/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_impoundVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

if !(isClass _missionCfg) exitWith {};
if !([player, ["Police", "Hato"]] call ULP_fnc_isFaction) exitWith {
        [LSTRING(IMPOUND_ONLY_POLICE)] call ULP_fnc_hint;
};

if !((crew _vehicle) isEqualTo []) exitWith {
        [LSTRING(IMPOUND_NOBODY)] call ULP_fnc_hint;
};

private _time = ["StreetCleaner", getNumber (missionConfigFile >> "CfgSettings" >> "Police" >> "impoundTime")] call ULP_fnc_activatePerk;
if (isNumber (_missionCfg >> "impoundTime")) then {
	_time = _time + getNumber (_missionCfg >> "impoundTime");
};

if ((_vehicle getVariable ["vehicle_id", -1]) < 0) exitWith {
        [LSTRING(IMPOUND_RENTAL)] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), getArray (missionConfigFile >> "CfgSettings" >> "Police" >> "impoundFee"), [_vehicle, _name, _time],
	{
		_this params [ "_vehicle", "_name", "_time",
			["_display", displayNull, [displayNull]],
			["_fee", 1, [0]] 
		];

		if !([format[LSTRING(IMPOUND_PROGRESS), _name], _time, [_vehicle, _name, _fee], {
			!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 5 }
		}, {
			_this params [ "_vehicle", "_name", "_fee" ];

			if (isNull _vehicle || { !((crew _vehicle) isEqualTo []) }) exitWith {
                                [LSTRING(IMPOUND_FAILED)] call ULP_fnc_hint;
			};

			private _id = _vehicle getVariable ["vehicle_id", -1];

			if (_id < 0) exitWith {
                                [LSTRING(IMPOUND_RENTAL)] call ULP_fnc_hint;
			};

			private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []];

			["Первое изъятие"] call ULP_fnc_achieve;

                        [format[LSTRING(IMPOUND_REQUEST), _name, "$", [_fee] call ULP_fnc_numberText]] call ULP_fnc_hint;
                        [LSTRING(IMPOUND_DONE_TITLE), { hint LSTRING(IMPOUND_DONE_HINT); }, true] call ULP_fnc_addEventHandler;
			[_vehicle, _fee] remoteExecCall ["ULP_SRV_fnc_storeVehicle", RSERV];

                        [LSTRING(CHAT_IMPOUNDED_NOTIFY), [_owner param [0, "Кто-то"], _name, [player,true] call ULP_fnc_getName, format ["%1%2", "$", [_fee] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
		}, {}] call ULP_UI_fnc_startProgress) exitWith {
                        [LSTRING(IMPOUND_BUSY)] call ULP_fnc_hint;
		};

		closeDialog 0;
	}, false
] call ULP_fnc_selectNumber;
