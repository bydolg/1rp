/*
	Area Defending System (ADS) - by Enigx
	
	Spawn_attacks_ADS.sqf
	
*/

_unitArray = _this select 0;
_MarkerPosArray = _this select 1;
_sideFactionUn = _this select 2;

private ["_grpAIads"];

_grpAIads = createGroup [_sideFactionUn, true];
_unitlArrayCount = (count _unitArray) - 1;
_markerArrayCount = (count _MarkerPosArray) - 1;
	
	for "_i" from 0 to _unitlArrayCount do
	{
		_ce = _grpAIads createUnit [_unitArray select _i, _MarkerPosArray select 0, [], 0, "FORM"];
		[_ce] join _grpAIads;
	};

for "_k" from 0 to _markerArrayCount do
{
	_wp = _grpAIads addWaypoint [(_MarkerPosArray select _k), 0];
	_wp setWaypointType "MOVE";
	_wp setWaypointBehaviour "AWARE";
	_wp setWaypointCombatMode "YELLOW";
	_wp setWaypointSpeed "NORMAL";
	_wp setWaypointFormation "WEDGE";
};