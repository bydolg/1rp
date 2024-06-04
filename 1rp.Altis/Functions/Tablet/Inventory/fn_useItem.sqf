/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_useItem";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
private _list = _display displayCtrl 23016;
if (isNull _display || { isNull _list }) exitWith {};

private _list = _display displayCtrl 23016;
private _curSel = missionConfigFile >> "CfgVirtualItems" >> (_list lbData (lbCurSel _list));
if !(isClass _curSel) exitWith { ["Сначала вам нужно выбрать предмет!"] call ULP_fnc_hint; };

private _amount = [configName _curSel] call ULP_fnc_hasItem;
if (_amount isEqualTo -1) exitWith {
	["У вас нет таких предметов для использования!"] call ULP_fnc_hint;
};

if !(isText (_curSel >> "Events" >> "onUse")) exitWith { ["Этот предмет нельзя использовать для выполнения действий!"] call ULP_fnc_hint; };

private _item = 1;
if !(_amount isEqualType 0) then {
	_item = (_amount select (_list lbValue (lbCurSel _list)));
};

[configName _curSel, _item] call compile getText (_curSel >> "Events" >> "onUse");
_display call ULP_fnc_inventory;
