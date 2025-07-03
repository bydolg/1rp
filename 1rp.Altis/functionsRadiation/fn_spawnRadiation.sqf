/*
	@file_name: fn_spawnRadiation.sqf
	@file_author: Dyzalonius
*/

////////////////////////////////////////////////
//               SUB-FUNCTIONS                //
////////////////////////////////////////////////

fn_spawnRadiation = {
    _radiationZones = missionNameSpace getVariable "radiationZones";
    _radiationZones pushback _this;
    missionNameSpace setVariable ["radiationZones", _radiationZones, true];
};

////////////////////////////////////////////////
//               FUNCTION LOOP                //
////////////////////////////////////////////////

switch (typeName (_this select 0)) do {
    // object
    case "OBJECT": {
		if (isMultiplayer && !isServer) exitWith {};
        waitUntil {missionNameSpace getVariable ["radiationInitialized", false]};

        _this set [0, position (_this select 0)];
        _this spawn fn_spawnRadiation;
    };

    // position
    case "ARRAY": {
        waitUntil {missionNameSpace getVariable ["radiationInitialized", false]};
        _this spawn fn_spawnRadiation;
    };
};

////////////////////////////////////////////////
/*                   USAGE                    //
////////////////////////////////////////////////

DESCRIPTION:
Spawns a radiation circle, with an OBJECT or a LOCATION at the center.

SYNTAX:
[a, b, c] spawn ZOR_fnc_spawnRadiation;
a = center (OBJECT or LOCATION).
b = radius (in meters).
c = radiationStrength (radiation present in the whole circle, affecting players (doesn't stack, highest applies)).

EXAMPLES:

Example 1 - In the init field of an OBJECT:
[this, 500, 3] spawn ZOR_fnc_spawnRadiation;

Example 2 - Anywhere, spawning at a LOCATION:
[[8000, 7000], 3000, 8] spawn ZOR_fnc_spawnRadiation;

Example 3 - Anywhere, spawning on an OBJECT with variable name 'myObject':
[myObject, 500, 3] spawn ZOR_fnc_spawnRadiation;

*/