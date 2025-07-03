/*
	@file_name: fn_protectiveGear.sqf
	@file_author: Dyzalonius
*/

_protectiveGear = missionNameSpace getVariable "protectiveGear";
_protectiveGear pushback _this;
missionNameSpace setVariable ["protectiveGear", _protectiveGear, true];

////////////////////////////////////////////////
/*                   USAGE                    //
////////////////////////////////////////////////

DESCRIPTION:
Spawns a radiation circle, with an OBJECT or a LOCATION at the center.

SYNTAX:
[a, b] spawn ZOR_fnc_protectiveGear;
a = classname of gear/item (any item or piece of apparel, not weaponry).
b = radiationProtection (protects the player from radiation (protection stacks).

EXAMPLE:
["H_PilotHelmetFighter_B", 3] spawn ZOR_fnc_protectiveGear;

*/