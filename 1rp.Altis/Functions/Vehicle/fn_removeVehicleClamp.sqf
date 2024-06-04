/*
** Автор: Джек "Scarso" Фархолл
** Описание: Позволяет снять замок с транспортного средства, если игрок является полицейским или ХАТО
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeVehicleClamp";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

private _clamp = _vehicle getVariable ["clamp_fine", []];

if (_clamp isEqualTo []) exitWith {
	["У этого транспортного средства нет замка..."] call ULP_fnc_hint;
	false
};

if !([player, ["Police", "Hato"]] call ULP_fnc_isFaction) exitWith {
	["Только полицейские или ХАТО могут снимать замки..."] call ULP_fnc_hint;
	false
};

private _profileName = _clamp param [0, "Неизвестно"];

closeDialog 0;

[format["Снятие замка с транспортного средства %1", _profileName, (_cfg param [3, "Vehicle"])], 30, [_vehicle, _cfg], { (player distance (_this select 0)) <= 5 }, {
	_this params [
		["_vehicle", objNull, [objNull]],
		["_cfg", configNull, [configNull]]
	];
	
	if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
		["Это транспортное средство слишком далеко..."] call ULP_fnc_hint;
	};

	_vehicle setVariable ["clamp_fine", nil, true];
	[format ["Вы сняли замок с <t color='#B92DE0'>%1</t>...", _cfg param [5, "Vehicle"]]] call ULP_fnc_hint;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;

true
