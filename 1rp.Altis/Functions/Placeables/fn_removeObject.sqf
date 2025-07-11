/*
** Автор: Джек "Скарсо" Фархолл
** Описание:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeObject";

if (canSuspend) exitWith {
    [ULP_fnc_removeObject, _this] call ULP_fnc_directCall;
};

_this params [
	["_object", objNull, [objNull]]
];

if !([_object] call ULP_fnc_isPlaceable) exitWith { false };

private _item = (_object getVariable "object_owner") param [2, "", [""]];

if !([_item, 1] call ULP_fnc_handleItem) then {
	["Вы не смогли унести предмет, поэтому он был уничтожен"] call ULP_fnc_hint;
};

deleteVehicle _object;
true
