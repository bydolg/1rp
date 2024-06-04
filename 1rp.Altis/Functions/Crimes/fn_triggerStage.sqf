/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_triggerStage";

_this params [
	["_location", objNull, [objNull]],
	["_crime", "", [""]],
	["_stage", "", [""]]
];

if (isNull _location) exitWith { false };

private _cfg = missionConfigFile >> "CfgCrimes" >> worldName >> _crime;
private _stageCfg = _cfg >> "Stages" >> _stage;
if !(isClass _cfg || { isClass _stageCfg }) exitWith { false };

if !([player, getArray (_cfg >> "factions")] call ULP_fnc_isFaction) exitWith {
	["Your faction can't do this crime..."] call ULP_fnc_hint;
	false
};

if !(call compile getText (_stageCfg >> "condition")) exitWith {
	call compile getText (_stageCfg >> "onFail");
	false
};

private _onStart = getText (_stageCfg >> "onStarted");
private _eachFrame = getText (_stageCfg >> "onEachFrame");

private _time = getNumber (_stageCfg >> "time");

if ([] call ULP_fnc_isGroup) then {
	private _buff = [group player, "Hacking"] call ULP_fnc_groupBuff;
	if (_buff > 0) then { _time = _time - (_time * _buff); };
};

if ([getText (_stageCfg >> "displayName"), _time, [_stageCfg, _location], { (player distance (_this select 1)) <= 5 }, {
	_this params [ "_stageCfg" ];

	// Recheck condition...
	if !(call compile getText (_stageCfg >> "condition")) exitWith {
		call compile getText (_stageCfg >> "onFail");
	};

	call compile getText (_stageCfg >> "onCompleted");
}, (compile getText (_stageCfg >> "onProgressStop")), ["GRAB", "CROUCH"], (compile _eachFrame)] call ULP_UI_fnc_startProgress) then  {
	call compile _onStart;
};