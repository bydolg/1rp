/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onRespawn";

_this params [
	["_unit", objNull, [objNull]],
	["_corpse", objNull, [objNull]]
];

// Corpse & Weapon Removal...
if !(isNull _corpse) then {
	{ deleteVehicle _x } forEach (nearestObjects [_corpse, ["WeaponHolderSimulated"], 5]);
	deleteVehicle _corpse;
};

_unit setUnconscious false;
unsetKiller(_unit);
unsetDowned(_unit);

// Handle creation of "new life"...
ULP_Respawned = true;

player playMove "AmovPercMstpSnonWnonDnon";

[] call ULP_fnc_setLoadout;
if ((count ULP_Gear_Safe)!= 0) then {[ULP_Gear_Safe] call ULP_fnc_loadGear;} else {[ULP_Gear] call ULP_fnc_loadGear;};     
diag_log format ["[RESPAWN LOAD_GEAR] Applying: %1", ULP_Gear];
[] call ULP_fnc_syncPlayerInfo;