private _allChapelTerrainObjects = nearestTerrainObjects 
 [ 
  [worldSize / 2, worldSize / 2], ["CHAPEL"], worldSize * sqrt 2 / 2, false 
 ]; 
{
	_resp_markerName = format ["respawn_resistance_%1",_forEachIndex];
	_resp_TriggerName = format ["%1",_forEachIndex]; 
	_resp_marker = createMarker [_resp_markerName, position _x];
	_resp_marker setMarkerType "loc_Bush";
    _resp_marker setMarkerText _resp_TriggerName; 
	_resp_Trigger = createTrigger ["EmptyDetector", position _x, true];	
	_resp_Trigger setVariable [_resp_TriggerName, _x];
	_resp_Trigger setTriggerActivation ["ANYPLAYER", "PRESENT", true];
	_resp_Trigger setTriggerArea [2, 2, getDir _x, true]; 
	_resp_Trigger_Act = format ["ULP_Pos_Safe =""%1"";", _resp_markerName];
	
	_resp_Trigger setTriggerStatements
		[
		"this",
		_resp_Trigger_Act,
		""
		];

	//systemChat format ["%1", _resp_markerName];
} forEach _allChapelTerrainObjects;