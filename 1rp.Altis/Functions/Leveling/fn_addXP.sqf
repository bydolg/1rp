/*
** Автор: Джек "Скарсо" Фархолл
** Описание:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addXP";

_this params [
	["_xp", 1, [0, []]],
	["_reason", "делать что-то...", [""]],
	["_chance", 100, [0]]
];

if (_xp isEqualType []) then {
	private _min = _xp # 0;
	private _max = _xp # 1;

	_xp = round (random [_min, ((_min + _max) / 2), _max]);
};

if ((random 100) > _chance || { _xp < 1 }) exitWith { false };
if (["ULP_SRV_Setting_DonationGoal"] call ULP_fnc_constant) then { _xp = _xp * getNumber(missionConfigFile >> "CfgSettings" >> "DonationRewards" >> "xpIncrease"); };

private _required = [ULP_Level] call ULP_fnc_getRequiredXP;
private _max = [] call ULP_fnc_getMaxLevel;

ULP_XP = round(ULP_XP + _xp);

private _previousLevel = ULP_Level;

for "_i" from 0 to 1 step 0 do {
	scopeName "fn_addXP_rankLoop";

	if (ULP_XP < _required) exitWith {};

	if (ULP_XP >= _required) then {
		if (ULP_Level isEqualTo _max) then {
			ULP_XP = _required;
			breakOut "fn_addXP_rankLoop";
		} else {
			ULP_XP = ULP_XP - _required;
			ULP_Level = ULP_Level + 1;
			_required = [ULP_Level] call ULP_fnc_getRequiredXP;
		};
	};
};

// Мы подняли уровень...
if !(ULP_Level isEqualTo _previousLevel) then {
	["Вы подняли уровень!"] call ULP_fnc_hint;
} else {
	[format["Вы получили <t color='#B92DE0'>%1</t> опыта за %2.", [_xp] call ULP_fnc_numberText, _reason]] call ULP_fnc_hint;
};

[player, 4, [ULP_Level, ULP_XP]] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
["OnXPIncreased"] call ULP_fnc_invokeEvent;
true
