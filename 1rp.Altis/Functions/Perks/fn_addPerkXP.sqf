/*
** Автор: Джек "Скарсо" Фархолл
** Описание:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addPerkXP";

_this params [
	["_perk", "", [""]],
	["_amount", 1, [0]]
];

if !([_perk] call ULP_fnc_hasPerk) exitWith { false };

private _cfg = missionConfigFile >> "CfgPerks" >> _perk >> "Leveling";
if !(isClass _cfg) exitWith { false };

// Остановка простого спама уровневыми повышениями путем добавления мини-перерыва...
private _recentIncreases = + (missionNamespace getVariable ["ULP_PerksXP", createHashMap]);
if (time < (_recentIncreases getOrDefault [_perk, time])) exitWith { false };
_recentIncreases set [_perk, time + (random 8)];
missionNamespace setVariable ["ULP_PerksXP", _recentIncreases];

private _requirement = getNumber (_cfg >> "xpLevel");
private _max = getNumber (_cfg >> "maxLevel");

([_perk] call ULP_fnc_getPerkLevel) params [
	"_level", "_xp"
];

if (_level > 1) then {
	_requirement = _requirement * (getNumber (_cfg >> "xpMultipler") * _level);
};

private _previousLevel = _level;
_xp = _xp + _amount;

for "_i" from 0 to 1 step 0 do {
	if (_xp < _requirement || { _level isEqualTo _max }) exitWith {};
	_xp = _xp - _requirement;
	_level = _level + 1;
};

// "Ограничьте" их...
_level = (_level max 0) min _max;
_xp = (_xp max 0) min _requirement;

if (_previousLevel < _level) then {
	["Вы повысили уровень способностей!"] call ULP_fnc_hint;
};

ULP_Perks set [_perk, [_level, _xp]];
[player, 11, ULP_Perks] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
true
