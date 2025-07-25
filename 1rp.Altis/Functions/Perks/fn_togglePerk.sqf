/*
** Автор: Джек "Скарсо" Фархолл
** Описание:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_togglePerk";

_this params [
	["_perk", "", [""]]
];

private _cfg = missionConfigFile >> "CfgPerks" >> _perk;

if ([_perk] call ULP_fnc_hasPerk) then {
	private _name = getText (_cfg >> "displayName");
	private _cost = getNumber (missionConfigFile >> "CfgPerks" >> "removalCost");
	_cost = _cost * getNumber (_cfg >> "removalMultiplier");
	
	if (BANK < _cost) exitWith {
		[format ["Для отключения перка вам нужно %1%2!", "$", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
		false breakOut "fn_togglePerk";
	};

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
		format ["Вы уверены, что хотите потратить %1%2 на удаление %3...", "$", [_cost] call ULP_fnc_numberText, _name], [_perk, _name, _cost, _cfg],
		{	
			_this params [ "_perk", "_name", "_cost", "_cfg" ];

			if ([_cost, true, format ["Deativating %1", _name]] call ULP_fnc_removeMoney) then {
				ULP_Perks deleteAt _perk;
				[format ["<t color='#B92DE0'>%1</t> был деактивирован за <t color='#B92DE0'>%2%3</t>.", _name, "$", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
				
				false call compile getText (_cfg >> "onChanged");
				["PerksChanged", [_perk, ULP_Perks]] call ULP_fnc_invokeEvent;
			};
		}, {}, true
	] call ULP_fnc_confirm;
} else {
	if !(isClass _cfg) exitWith {
		["Этот перк больше не существует и был автоматически удален"] call ULP_fnc_hint;
		false breakOut "fn_togglePerk";
	};

	private _limit = [] call ULP_fnc_getPerkLimit;
	if ((count ULP_Perks) >= _limit) exitWith {
		[format ["У вас не может быть больше <t color='#B92DE0'>%1</t> активных перков!", _limit]] call ULP_fnc_hint;
		false breakOut "fn_togglePerk";
	};

	ULP_Perks set [_perk, [1, 0]];
	[format ["<t color='#B92DE0'>%1</t> был успешно активирован!", getText (_cfg >> "displayName")]] call ULP_fnc_hint;

	true call compile getText (_cfg >> "onChanged");
	["PerksChanged", [_perk, ULP_Perks]] call ULP_fnc_invokeEvent;
};

true
