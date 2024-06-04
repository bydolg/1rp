/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_serviceVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_serviceVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	["_location", objNull, [objNull]]
];

if (isNull _location) exitWith {};

private _near = _location nearEntities [["Air"], 15];
private _vehicle = _near param [(_near findIf { [player, _x] call ULP_fnc_isVehicleOwner }), objNull];

if (isNil "_vehicle" || { isNull _vehicle } || { !(alive _vehicle) }) exitWith {
	["Рядом нет воздушных транспортных средств для обслуживания!"] call ULP_fnc_hint;
};

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (_cfg isEqualTo []) exitWith {};

_cfg params [
	"", "_missionCfg", "", "_name", "", "", "", "", "_fuel"
];

private _time = 15;
if (isNumber (_missionCfg >> "serviceTime")) then {
	_time = _time + getNumber (_missionCfg >> "serviceTime");
};

private _cost = ["PartsCarrier", round ((["Service", 1000] call ULP_fnc_getLegislation) * (_fuel / 10))] call ULP_fnc_activatePerk;
if (isNumber (_missionCfg >> "serviceCost")) then {
	_cost = _cost + getNumber (_missionCfg >> "serviceCost");
};

if (CASH < _cost) exitWith {
	[format ["У вас недостаточно средств для оплаты <t color='#B92DE0'>%1%2</t> за обслуживание этого транспортного средства!", "$", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
};

if !([format["Servicing %1", _name], _time, [_location, _vehicle, _name, _cost], {
	!(isNull (_this select 0)) && { alive (_this select 1) } && { ((_this select 0) distance (_this select 1)) <= 15 }
}, {
	_this params [ "_location", "_vehicle", "_name", "_cost" ];

	if (isNull _vehicle || { !(alive _vehicle) } || { (_location distance _vehicle) > 15 }) exitWith {
		[format ["Вы не смогли обслужить %1, так как он находится в аварийном состоянии или находится далеко от стенда! ", _name]] call ULP_fnc_hint;
	};

	if ([_cost, false, format ["Serviced %1", _name]] call ULP_fnc_removeMoney) exitWith {
		[format ["У вас нет средств для оплаты %1%2 за обслуживание этого транспортного средства!", "$", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
	};

	[_vehicle, 1] remoteExecCall ["ULP_fnc_setFuel", _vehicle];
	_vehicle setDamage 0;

	[format ["Вы обслужили <t color='#B92DE0'>%1</t>.", _name]] call ULP_fnc_hint;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["Вы не можете обслуживать транспортное средство, выполняя другое действие!"] call ULP_fnc_hint;
};
