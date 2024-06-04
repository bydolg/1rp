/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_craft";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
private _tree = _display displayCtrl 23077;
if (isNull _display || { isNull _tree }) exitWith {};

if !(isNull (objectParent player)) exitWith {
	["Вы не можете создавать предметы, находясь в транспортном средстве..."] call ULP_fnc_hint;
	false;
};

private _cfg = _display getVariable ["craft_cfg", configNull];
if !(isClass _cfg) exitWith {
	["Сначала вы должны выбрать чертеж..."] call ULP_fnc_hint;
	false
};

if ([getNumber (_cfg >> "workbench")] call ULP_fnc_bool && { !([] call ULP_fnc_nearWorkbench) }) exitWith {
	["Для создания этого чертежа требуется верстак..."] call ULP_fnc_hint;
	false
};

private _total = selectMin (getArray (_cfg >> "materials") apply {
	floor (([_x select 0] call ULP_fnc_hasItem) / (_x select 1))
});

if (_total < 1) exitWith {
	["У вас нет всех необходимых материалов для создания этого чертежа..."] call ULP_fnc_hint;
	false
};

private _name = getText (_cfg >> "displayName");

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _total], [_cfg, _name],
	{
		_this params [
			["_cfg", configNull, [configNull]],
			["_name", "", [""]],
			["_display", displayNull, [displayNull]],
			["_amount", 1, [0]]
		];

		if (_amount < 0) exitWith {};
		closeDialog 0;

		[format["Создание %1(ых)", _name], getNumber (_cfg >> "time") * _amount, [_cfg, _name, _amount], { true }, {
			_this params [ "_cfg", "_name", "_amount" ];

			private _item = getText (_cfg >> "item");

			if ([_item, _amount, false, true] call ULP_fnc_handleItem) then {
				{ [_x select 0, (_x select 1) * _amount, true] call ULP_fnc_handleItem; } forEach getArray (_cfg >> "materials");

				[format ["Вы создали %2 %1(ых)...", _name, [_amount] call ULP_fnc_numberText]] call ULP_fnc_hint;

				[true] call ULP_fnc_saveGear;
				[getPlayerUID player, "Craft", [_name, _amount]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
			};
		}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, true
] call ULP_fnc_selectNumber;
