/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#define RIG_CFG missionConfigFile >> "CfgGovernment" >> "Rigging" 
#include "..\..\script_macros.hpp"
scopeName "fn_rigPollingStation";

_this params [
	["_pollingStation", objNull, [objNull]]
];

if (isNull _pollingStation || { !(isNil { player getVariable "rigging" }) }) exitWith {};

private _group = group player;
private _groupId = [_group] call ULP_fnc_groupId;

if (_groupId isEqualTo -1 || { !(["PollRigging", _group] call ULP_fnc_hasGroupPerk) }) exitWith {
	["Вы должны быть в группе с возможностью взламывать избирательные участки"] call ULP_fnc_hint;
};

private _riggedGroup = _pollingStation getVariable ["rigged_group", grpNull];
private _riggedGroupId = [_riggedGroup] call ULP_fnc_groupId;

private _isRigged = !(isNull _riggedGroup && { _riggedGroupId isEqualTo -1 });

if (_isRigged && { _riggedGroupId isEqualTo _groupId }) exitWith {
	["Этот избирательный участок уже был взломан вашей группой"] call ULP_fnc_hint;
};

player setVariable ["rigging", true];

private _time = getNumber (RIG_CFG >> "timeToRig");

if (_isRigged) then {
	_time = _time * getNumber (RIG_CFG >> "alreadyRiggedMultiplier");
};

["Взлом избирательного участка", _time, [_pollingStation, _group, _groupId], 
	{ !(((_this select 0) getVariable ["rigged_group", grpNull]) isEqualTo (_this select 1)) && { (player distance (_this select 0)) <= 5 } }, 
	{
		_this params [ "_pollingStation", "_group", "_groupId" ];

		["PollingStationRigged", {
			_this params [
				["_message", "Избирательный участок успешно взломан", [""]]
			];

			player setVariable ["rigging", nil];

			[_message] call ULP_fnc_hint;
		}, true] call ULP_fnc_addEventHandler;

		[_pollingStation, player] remoteExecCall ["ULP_SRV_fnc_rigPollingStation", RSERV];
	}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
