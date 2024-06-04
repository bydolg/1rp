/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vehicleRegistration";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []];

if (_owner isEqualTo []) exitWith {
	deleteVehicle _vehicle;
	["Транспортное средство было удалено, так как, скорее всего, оно было заспавнено незаконно..."] call ULP_fnc_hint;
};

[format ["<t color='#FF0000'><t size='1.7'>Регистрация Транспортного Средства</t></t><br/><t color='#FFD700'><t size='1.5'>Владелец</t></t><br/> %1", _owner param [0, "Unknown"]]] call ULP_fnc_hint;
