/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_increaseProfession";

_this params [
	["_profession", "", [""]],
	["_amount", 1, [0]],
	["_chance", 5, [0]]
];

if (["ULP_SRV_Setting_DonationGoal"] call ULP_fnc_constant) then { _chance = (_chance * getNumber(missionConfigFile >> "CfgSettings" >> "DonationRewards" >> "profChanceIncrease")) min 100; };

if ((random 100) > _chance) exitWith { false };

private _cfg = missionConfigFile >> "CfgProgression" >> "CfgProfessions" >> _profession;
if (!(isClass _cfg) || { _amount < 1 }) exitWith { false };

private _requirement = getNumber (_cfg >> "xpLevel");
private _max = getNumber (_cfg >> "maxLevel");

([_profession] call ULP_fnc_getProfessionLevel) params [
	"_level", "_points"
];

if (_level > 0) then {
	_requirement = _requirement * (getNumber (_cfg >> "xpMultipler") * _level);
};

_amount = round (["QuickLearner", _amount] call ULP_fnc_activatePerk);

private _previousLevel = _level;
_points = _points + _amount;

for "_i" from 0 to 1 step 0 do {
	if (_points < _requirement || { _level isEqualTo _max }) exitWith {};
	_points = _points - _requirement;
	_level = _level + 1;
};

// "Clamp" them...
_level = (_level max 0) min _max;
_points = (_points max 0) min _requirement;

if (_previousLevel < _level) then {
	["Вы <t color='#B92DE0'>повысили</t> уровень профессии!"] call ULP_fnc_hint;
} else {
	["Вы <t color='#B92DE0'>улучшили</t> профессию!"] call ULP_fnc_hint;
};

ULP_Professions set [_profession, [_level, _points]];
[player, 3, ULP_Professions] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];

true
