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
	["Только полиция и ХАТО могут изъять транспортные средства"] call ULP_fnc_hint;
};

if !((crew _vehicle) isEqualTo []) exitWith {
	["Никто не может находиться в транспортном средстве при его изъятии!"] call ULP_fnc_hint;
};

private _time = ["StreetCleaner", getNumber (missionConfigFile >> "CfgSettings" >> "Police" >> "impoundTime")] call ULP_fnc_activatePerk;
if (isNumber (_missionCfg >> "impoundTime")) then {
	_time = _time + getNumber (_missionCfg >> "impoundTime");
};

if ((_vehicle getVariable ["vehicle_id", -1]) < 0) exitWith {
	["Арендованные транспортные средства не могут быть изъяты!"] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), getArray (missionConfigFile >> "CfgSettings" >> "Police" >> "impoundFee"), [_vehicle, _name, _time],
	{
		_this params [ "_vehicle", "_name", "_time",
			["_display", displayNull, [displayNull]],
			["_fee", 1, [0]] 
		];

		if !([format["Изъятие %1", _name], _time, [_vehicle, _name, _fee], {
			!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 5 }
		}, {
			_this params [ "_vehicle", "_name", "_fee" ];

			if (isNull _vehicle || { !((crew _vehicle) isEqualTo []) }) exitWith {
				[format["Вы не смогли изъять это транспортное средство, так как в нем кто-то находился, или оно уже было удалено!"]] call ULP_fnc_hint;
			};

			private _id = _vehicle getVariable ["vehicle_id", -1];

			if (_id < 0) exitWith {
				["Арендованные транспортные средства не могут быть изъяты!"] call ULP_fnc_hint;
			};

			private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []];

			["Первое изъятие"] call ULP_fnc_achieve;

			[format["Вы запросили изъятие <t color='#B92DE0'>%1</t> за плату в <t color='#B92DE0'>%2%3</t>.", _name, "$", [_fee] call ULP_fnc_numberText]] call ULP_fnc_hint;
			["Транспортное средство изъято", { hint "Транспортное средство изъято."; }, true] call ULP_fnc_addEventHandler;
			[_vehicle, _fee] remoteExecCall ["ULP_SRV_fnc_storeVehicle", RSERV];

			["Изъято", [_owner param [0, "Кто-то"], _name, [player, true] call ULP_fnc_getName, format ["%1%2", "$", [_fee] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
		}, {}] call ULP_UI_fnc_startProgress) exitWith {
			["Вы не можете изъять транспортное средство, выполняя другое действие!"] call ULP_fnc_hint;
		};

		closeDialog 0;
	}, false
] call ULP_fnc_selectNumber;
