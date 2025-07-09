/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_crushVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

if !(isClass _missionCfg) exitWith {};
if !([player, ["Police"]] call ULP_fnc_isFaction) exitWith {
	["Только полиция может уничтожать транспортные средства!"] call ULP_fnc_hint;
};

if !((crew _vehicle) isEqualTo []) exitWith {
	["Никто не должен находиться в транспортном средстве, которое вы уничтожаете!"] call ULP_fnc_hint;
};

private _time = ["StreetCleaner", getNumber (missionConfigFile >> "CfgSettings" >> "Police" >> "crushTime")] call ULP_fnc_activatePerk;
if (isNumber (_missionCfg >> "crushTime")) then {
	_time = _time + getNumber (_missionCfg >> "crushTime");
};

if !([format["Уничтожение %1", _name], _time, [_vehicle, _name, _fee], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name", "_fee" ];

	if (isNull _vehicle || { !((crew _vehicle) isEqualTo []) }) exitWith {
		[format["Вы не смогли уничтожить это транспортное средство, так как в нем находился кто-то или оно уже было удалено!"]] call ULP_fnc_hint;
	};

	private _id = _vehicle getVariable ["vehicle_id", -1];
	if (_id >= 0) then {
		[_id] remoteExecCall ["ULP_SRV_fnc_destroyVehicle", RSERV];
	};

	private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []];

	deleteVehicle _vehicle;
	["FirstCrush"] call ULP_fnc_achieve;

	["Транспортное средство было уничтожено!"] call ULP_fnc_hint;
        ["Crushed", [_owner param [0, "Кто-то"], _name, [player, true] call ULP_fnc_getName]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
}, {}] call ULP_UI_fnc_startProgress) exitWith {
	["Вы не можете уничтожать транспортное средство, выполняя другое действие!"] call ULP_fnc_hint;
};

closeDialog 0;
