/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_fuelCan";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "", "", "", "", "_fuel"
];

if !(isClass _missionCfg) exitWith {};

private _time = 40;
if (isNumber (_missionCfg >> "refuelTime")) then {
	_time = _time + getNumber (_missionCfg >> "refuelTime");
};

if !([format["Refueling %1", _name], _time, [_vehicle, _name, _fuel], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { ["FuelCan"] call ULP_fnc_hasItem > 0 } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name", "_fuel" ];

	if (isNull _vehicle || { !(alive _vehicle) } || { !(["FuelCan"] call ULP_fnc_hasItem > 0) }) exitWith {
		[format["Вы не смогли заправить <t color='#B92DE0'>%1</t>, так как он либо сильно поврежден, либо вы потеряли вашу канистру с топливом..."]] call ULP_fnc_hint;
	};

	if (["FuelCan", 1, true] call ULP_fnc_handleItem) then {
		_fuel = ((fuel _vehicle) + (_fuel * 0.2));
		
		if (local _vehicle) then {
			_vehicle setFuel _fuel;
		} else {
			[_vehicle, _fuel] remoteExecCall ["ULP_fnc_setFuel", _vehicle];
		};

		[format["Вы заправили <t color='#B92DE0'>%1</t> с помощью канистры с топливом...", _name]] call ULP_fnc_hint;
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["Вы не можете заправить транспортное средство, выполняя другое действие!"] call ULP_fnc_hint;
};

closeDialog 0;
