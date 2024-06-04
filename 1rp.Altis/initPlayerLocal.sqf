/*
** Author: 
** Description: Starts the initialization of the player.
*/
#include "script_macros.hpp"

CONST(BIS_fnc_endMission,BIS_fnc_endMission);

enableRadio false;
enableSentences false;
enableEnvironment false;
showHud false;
showChat false;

[] spawn ULP_fnc_initialisation;

0 spawn {   
  private _safezoneMarkers = allMapMarkers select {_x find "greenzone_" > -1};       
  {                                           
    _safeMark = _x;  
    private _isRec = false; if (markerShape _x == "RECTANGLE") then {_isRec = true};  
    private _markSize = markerSize _x #0;        
    if (markerSize _x #0 < markerSize _x #1) then { _markSize = markerSize _x #1 };  
 
    private _allObj = nearestTerrainObjects  [getMarkerPos _x, [], _markSize, false]; 
    private _safeObj = _allObj inAreaArray [getMarkerPos _x, (markerSize _x #0), (markerSize _x #1), markerDir _x, _isRec, -1];       
    {_x allowdamage false} forEach _safeObj; 
 
    private _allObj = -1 allObjects 0; 
    private _safeObj = _allObj inAreaArray [getMarkerPos _x, (markerSize _x #0), (markerSize _x #1), markerDir _x, _isRec, -1];       
    {_x allowdamage false} forEach _safeObj; 
       
   
  } forEach _safezoneMarkers;   
};