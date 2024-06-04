/*
  SHK_pos
  
  Version 0.24
  Author: Shuko (shuko@quakenet, miika@miikajarvinen.fi)
  Contributors: Cool=Azroul13, Hatifnat

  Forum: http://forums.bistudio.com/showthread.php?162695-SHK_pos

  Marker Based Selection
    Required Parameters:
      0 String   Area marker's name.
      
    Optional Parameters:
      1 Number            Water position. Default is only land positions allowed.
                            0   Find closest land. Search outwards 360 degrees (20 degree steps) and 20m steps.
                            1   Allow water positions.
                            2   Find only water positions.
      2 Array or String   One or multiple blacklist area markers which are excluded from the main marker area.
      3 Array, Number, Object or Vehicle Type         Force finding large enough empty position.
                            0   Max range from the selection position to look for empty space. Default is 200.
                            1   Vehicle or vehicle type to fit into an empty space.
                            
                            Examples:
                              [...,[300,heli]]       Array with distance and vehicle object.
                              [...,350]              Only distance given
                              [...,(typeof heli)]    Only vehicle type given
                              [...,heli]             Only vehicle object given

  Position Based Selection
    Required Parameters:
      0 Object or Position  Anchor point from where the relative position is calculated from.
      1 Array or Number     Distance from anchor.
      
    Optional Parameters:
      2 Array of Number     Direction from anchor. Default is random between 0 and 360.
      3 Number              Water position. Default is only land positions allowed.
                              0   Find closest land. Search outwards 360 degrees (20 degree steps) and 20m steps.
                              1   Allow water positions.
                              2   Find only water positions.
      4 Array               Road positions.
                              0  Number  Road position forcing. Default is 0.
                                   0    Do not search for road positions.
                                   1    Find closest road position. Return the generated random position if none found.
                                   2    Find closest road position. Return empty array if none found.
                              1  Number   Road search range. Default is 200m.
      5 Array, Number, Object or Vehicle Type         Force finding large enough empty position.
                              0   Max range from the selection position to look for empty space. Default is 200.
                              1   Vehicle or vehicle type to fit into an empty space.
                            
                            Examples:
                              [...,[300,heli]]       Array with distance and vehicle object.
                              [...,350]              Only distance given
                              [...,(typeof heli)]    Only vehicle type given
                              [...,heli]             Only vehicle object given                              
    
  Usage:
    Preprocess the file in init.sqf:
      call compile preprocessfile "ADS_system\functions\shk\shk_pos_initADS.sqf";
    
    Actually getting the position:
      pos = [parameters] call SHK_posADS;
*/
// Functions
SHK_pos_getPosADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_getposADS.sqf";
SHK_pos_getPosMarkerADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_getposmarkerADS.sqf";

// Sub functions
SHK_pos_fnc_findClosestPositionADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_findclosestpositionADS.sqf";
SHK_pos_fnc_getMarkerCornersADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_getmarkercornersADS.sqf";
SHK_pos_fnc_getMarkerShapeADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_getmarkershapeADS.sqf";
SHK_pos_fnc_getPosADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_getposADS.sqf";
SHK_pos_fnc_getPosFromCircleADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_getposfromcircleADS.sqf";
SHK_pos_fnc_getPosFromEllipseADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_getposfromellipseADS.sqf";
SHK_pos_fnc_getPosFromRectangleADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_getposfromrectangleADS.sqf";
SHK_pos_fnc_getPosFromSquareADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_getposfromsquareADS.sqf";
SHK_pos_fnc_isBlacklistedADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_isblacklistedADS.sqf";
SHK_pos_fnc_isInCircleADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_isincircleADS.sqf";
SHK_pos_fnc_isInEllipseADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_isinellipseADS.sqf";
SHK_pos_fnc_isInRectangleADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_isinrectangleADS.sqf";
SHK_pos_fnc_isSamePositionADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_issamepositionADS.sqf";
SHK_pos_fnc_rotatePositionADS = compile preprocessfilelinenumbers "ADS_system\functions\shk\shk_pos_fnc_rotatepositionADS.sqf";

// Wrapper function
// Decide which function to call based on parameters.
SHK_posADS = {
  private ["_posADS"];
  _posADS = [];

  // Only marker is given as parameter
  if (typename _this == "STRING") then {
    _posADS = [_this] call SHK_pos_getPosMarkerADS;

  // Parameter array
  } else {
    if (typename (_this select 0) == "STRING") then {
      _posADS = _this call SHK_pos_getPosMarkerADS;
    } else {
      _posADS = _this call SHK_pos_getPosADS;
    };
  };

  // Return position
  _posADS
};