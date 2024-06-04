/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getRequiredXP";

_this params [
	["_level", 0, [0]],
	["_lvlCfg", missionConfigFile >> "CfgProgression" >> "Leveling", [configNull]]
];

if !(isClass _lvlCfg) exitWith { 0 };

(round(getNumber (_lvlCfg >> "baseXp") * (getNumber (_lvlCfg >> "xpMultiplier") * _level)))