/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_shareHouse";

if (canSuspend) exitWith {
    [ULP_fnc_shareHouse, _this] call ULP_fnc_directCall;
};

_this params [
	["_house", objNull, [objNull]]
];

if (isNull _house) exitWith { false };

if !([_house, player, false] call ULP_fnc_isHouseOwner) exitWith {
	["Только владелец дома может изменять его статус доступности для группы!"] call ULP_fnc_hint;
	false
};

// Предотвращение спама...
if (time < (_house getVariable ["building_last_shared", 0])) exitWith {
	["Вы недавно меняли статус доступности этого дома, подождите, пожалуйста..."] call ULP_fnc_hint;
	false
};
_house setVariable ["building_last_shared", time + 5];

if (_house getVariable ["selling", false]) exitWith {
	["Этот дом продается!"] call ULP_fnc_hint;
	false
};

private _shared = !([_house] call ULP_fnc_isHouseShared);
_house setVariable ["building_shared", _shared, true];

private _event = ([
	"HouseRemoved",
	"HouseAdded"
] select (_shared));

{
	[_event, [_house]] remoteExecCall ["ULP_fnc_invokeEvent", _x];
} forEach ((units (group player)) select {
	!(_x isEqualTo player)
});

[_house getVariable ["building_id", -1], _shared] remoteExecCall ["ULP_SRV_fnc_setHouseShared", RSERV];
[format ["Этот дом теперь <t color='#B92DE0'>%1</t> доступен для вашей группы.", ["больше не", "теперь"] select (_shared)]] call ULP_fnc_hint;
true
