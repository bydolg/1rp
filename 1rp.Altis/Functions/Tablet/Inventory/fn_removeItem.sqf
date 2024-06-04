/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_removeItem";

_this params [
	"_ctrl"
];

disableSerialization;

private _display = ctrlParent _ctrl;
private _list = _display displayCtrl 23016;
if (isNull _display || { isNull _list }) exitWith {};

private _list = _display displayCtrl 23016;
private _curSel = missionConfigFile >> "CfgVirtualItems" >> (_list lbData (lbCurSel _list));
if !(isClass _curSel) exitWith { ["Сначала вам нужно выбрать предмет!"] call ULP_fnc_hint; };

private _amount = [configName _curSel] call ULP_fnc_hasItem;
if (_amount isEqualTo -1) exitWith {
	["У вас нет таких предметов для удаления!"] call ULP_fnc_hint;
};

if ([getNumber (_curSel >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
	private _itemData = (([configName _curSel] call ULP_fnc_hasItem) select (_list lbValue (lbCurSel _list)));
	private _name = format [getText(_curSel >> "displayName"), _itemData];

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
		format ["Вы уверены, что хотите удалить %1...", _name], [_curSel, _itemData, _name],
		{	
			_this params [ "_cfg", "_data", "_name" ];

			_display = findDisplay 23000; // Нам не нужно выбирать, поэтому мы переключаем это на планшет...
			if (isNull _display || { isNull _cfg }) exitWith {};

			if ([configName _cfg, _data, true] call ULP_fnc_handleItem) then {
				[format["Вы удалили %1 из вашего инвентаря!", _name]] call ULP_fnc_hint;
				_display call ULP_fnc_inventory;
			} else {
				["У вас нет этого предмета для удаления!"] call ULP_fnc_hint;
			};
		}, {}, false
	] call ULP_fnc_confirm;
} else {
	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_curSel],
		{
			_this params [
				["_cfg", configNull, [configNull]],
				["_display", displayNull, [displayNull]],
				["_value", 1, [0]]
			];

			_display = findDisplay 23000; // Нам не нужно выбирать, поэтому мы переключаем это на планшет...
			if (isNull _display || { isNull _cfg }) exitWith {};

			if ([configName _cfg, _value, true] call ULP_fnc_handleItem) then {
				[format["Вы удалили <t color='#B92DE0'>%1 %2(ов)</t> из вашего инвентаря.", _value, getText(_cfg >> "displayName")]] call ULP_fnc_hint;
				_display call ULP_fnc_inventory;
			} else {
				["У вас нет столько этого предмета!"] call ULP_fnc_hint;
			};
		}
	] call ULP_fnc_selectNumber;
};
