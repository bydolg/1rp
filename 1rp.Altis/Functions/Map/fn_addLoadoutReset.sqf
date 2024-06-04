/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
** Использование:
** 	[this, "<t color='#073763'>[АПЦ]</t>", "Полиция"] call ULP_fnc_addLoadoutReset;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addLoadoutReset";

_this params [
	["_trader", objNull, [objNull]],
	["_title", "", [""]],
	["_faction", "", [""]]
];

private _cfg = missionConfigFile >> "CfgFactions" >> _faction >> "Loadout";
if !(isClass _cfg) exitWith {};

_trader addAction [format["Сбросить снаряжение %1", _title], { [(_this select 3)] call ULP_fnc_setCfgLoadout }, _cfg, 1, true, true, "", format["[_this, [""%1""]] call ULP_fnc_isFaction", _faction], 3];
