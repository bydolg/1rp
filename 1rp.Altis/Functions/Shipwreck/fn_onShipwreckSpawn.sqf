/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onShipwreckSpawn";

_this params [
	["_shipwreck", objNull, [objNull]],
	["_message", "", [""]]
];

if (isNull _shipwreck) exitWith {};

[_message] call ULP_fnc_hint;

_shipwreck addAction [
	"Забрать обломки корабля", {
		_this params [ "_shipwreck", "", "_actionId" ];

		["Забираю обломки корабля", 200, [_shipwreck, _actionId], { true }, {
			_this params [ "_shipwreck", "_actionId" ];

			_shipwreck removeAction _actionId;
			["Забираю обломки корабля..."] call ULP_fnc_hint;

			[player, _shipwreck] remoteExecCall ["ULP_SRV_fnc_claimShipwreck", RSERV];
		}, {}] call ULP_UI_fnc_startProgress;
	}, nil, 8, true, true, "", "true", 20
];
