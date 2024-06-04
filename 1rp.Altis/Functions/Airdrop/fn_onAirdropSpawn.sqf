/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onAirdropSpawn";

_this params [
	["_airdrop", objNull, [objNull]],
	["_message", "", [""]]
];

if (isNull _airdrop) exitWith {};

[_message] call ULP_fnc_hint;

_airdrop addAction [
	"Забрать ящик с поставками", {
		_this params [ "_airdrop", "", "_actionId" ];

		if (_airdrop getVariable ["locked", false]) exitWith {
			["Ящик с поставками все еще заперт, вам нужно взломать его, прежде чем его можно будет забрать..."]  call ULP_fnc_hint;
		};

		["Забор ящика с поставками", 150, [_airdrop, _actionId], { true }, {
			_this params [ "_airdrop", "_actionId" ];

			_airdrop removeAction _actionId;
			["Забор ящика с поставками..."] call ULP_fnc_hint;

			[player, _airdrop] remoteExecCall ["ULP_SRV_fnc_claimAirdrop", RSERV];
		}, {}] call ULP_UI_fnc_startProgress;
	}, nil, 8, true, true, "", "(((getPos _target) select 2) <= 1)", 5
];
