/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_giveVehicleKeys";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit || { !(isPlayer _unit) } || { (player distance _unit) > 5 }) exitWith {};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (ULP_Keys apply { 
	([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "_missionCfg", "", "_name" ]; 
	[_picture, _name, _x call BIS_fnc_netId, 0];
}), ["Give", "Cancel"], [_unit], {
	_this params [
		["_unit", objNull, [objNull]],
		["_display", displayNull, [displayNull]]
	];

	if ((player distance _unit) > 5) exitWith {
		["Вы слишком далеко, чтобы дать этому человеку ключи!"] call ULP_fnc_hint;
	};

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _vehicle) exitWith { ["Вы не выбрали транспортное средство для передачи ключей!"] call ULP_fnc_hint; };

	private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
	if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith {};

	_cfg params [
		"", "_missionCfg", "", "_name"
	];

	if !(isClass _missionCfg) exitWith {};

	["KeysGiven", [_vehicle, player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	[format ["Вы передали <t color='#B92DE0'>%1</t> ключи <t color='#B92DE0'>%2</t>.", name _unit, _name]] call ULP_fnc_hint;
}, false] call ULP_fnc_selectObject;
