/*
** Автор: Льюис Маккиннон
** Описание: Удаляет средства связи у игрока и оповещает об этом обе стороны.
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_seizeComms";

_this params [
	["_unit", player, [objNull]]
];

if (isNull _unit) exitWith {};

{
	if (_x in getArray (missionConfigFile >> "CfgSettings" >> "communicationDevices")) then {
    	_unit unassignItem _x;
    	_unit removeItem _x;
  	};
} forEach (assignedItems _unit + items _unit);

if !(_unit isEqualTo player) then {
	["Вы уничтожили средства связи этого человека..."] call ULP_fnc_hint;
};

if (local _unit) then {
	["CommunicationsSeized", [player]] call ULP_fnc_invokeEvent;
} else {
	["CommunicationsSeized", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

[getPlayerUID player, "SeizedComms", [_unit]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
