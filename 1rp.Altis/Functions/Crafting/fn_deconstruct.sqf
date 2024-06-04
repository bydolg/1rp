/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_deconstruct";

_this params [
	["_item", "", [""]]
];

if !(isNull (objectParent player)) exitWith {
	["Вы не можете разбирать предметы, находясь в транспортном средстве..."] call ULP_fnc_hint;
	false;
};

private _cfg =  missionConfigFile >> "CfgVirtualItems" >> _item;
if !(isClass (_cfg >> "Deconstruction")) exitWith {
	["Этот предмет нельзя разобрать"] call ULP_fnc_hint;
	false
};

if (["Toolbox"] call ULP_fnc_hasItem < 1) exitWith {
	["Для разборки предметов вам нужен ящик с инструментами..."] call ULP_fnc_hint;
	false
};

if ([getNumber (_cfg >> "Deconstruction" >> "workbench")] call ULP_fnc_bool && { !([] call ULP_fnc_nearWorkbench) }) exitWith {
	["Для разборки этого предмета вы должны находиться рядом с <t color='#B92DE0'>верстаком</t>"] call ULP_fnc_hint;
	false
};

private _name = getText (_cfg >> "displayName");

private _total = [_item] call ULP_fnc_hasItem;
if (_total < 1) exitWith {
	[format ["У вас нет <t color='#B92DE0'>%1</t> для разборки", _name]] call ULP_fnc_hint;
	false
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _total], [_cfg, _name],
	{
		_this params [
			["_cfg", configNull, [configNull]],
			["_name", "", [""]],
			["_display", displayNull, [displayNull]],
			["_amount", 1, [0]]
		];

		if (_amount < 0 || { _amount > ([configName _cfg] call ULP_fnc_hasItem) }) exitWith {};
		closeDialog 0;

		[format["Разбор %1(ов)", _name], getNumber (_cfg >> "Deconstruction" >> "time") * _amount, [_cfg, _name, _amount], { true }, {
			_this params [ "_cfg", "_name", "_amount" ];

			if ([configName _cfg, _amount, true] call ULP_fnc_handleItem) then {
				{ [_x select 0, (_x select 1) * _amount, false, true] call ULP_fnc_handleItem; } forEach getArray (_cfg >> "Deconstruction" >> "materials");
				{ _x call ULP_fnc_unlockBlueprint; } forEach getArray (_cfg >> "Deconstruction" >> "blueprints");

				[format ["Вы разобрали <t color='#B92DE0'>%2 %1(ов)</t>...", _name, [_amount] call ULP_fnc_numberText]] call ULP_fnc_hint;

				[true] call ULP_fnc_saveGear;
			} else {
				[format ["У вас нет <t color='#B92DE0'>%2</t> x <t color='#B92DE0'>%1</t> для разборки...", _name, [_amount] call ULP_fnc_numberText]] call ULP_fnc_hint;
			};
		}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, true
] call ULP_fnc_selectNumber;
true
