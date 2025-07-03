/*
** Author: Jack "Scarso" Farhall
** Description: Checks if we have the server side package available and calls to start initialisation
*/
#include "script_macros.hpp"

if (isClass (configFile >> "CfgPatches" >> "ULPServer")) then {
	[] call ULP_SRV_fnc_init;
};

  0 spawn {
  	private _DT_fnc_handleVehSafezone = {
		  params [
  			["_object",objNull,[objNull]]
		  ];
		  if (isNull _object) exitWith {};
		  [_object,["HandleDamage",{
  			params ["_vehicle","_part","_damage","_source","_projectile","_hitindex","_instigator","_hitpoint"];
			  if !(local _vehicle) exitWith {};

  			private _safezoneMarkers = allMapMarkers select {_x find "greenzone_" > -1};
			  private _inSafezone = false;
			  {
  			
      	  if (_vehicle inArea _x) exitWith {
  					_inSafezone = true;
				  };
  			
        } forEach _safezoneMarkers;
      
  			if (_inSafezone) then {_damage = false};

  			_damage	 
		  }]] remoteExec ["addEventHandler",0,_object];
	  };

	  while {true} do {
  		private _vehicles = vehicles select {(alive _x) AND ((_x isKindOf "LandVehicle") OR (_x isKindOf "Ship") OR (_x isKindOf "Air"))};
		  {
  			if !(_x getVariable ['SZHandled',false]) then {
				  _x setVariable ['SZHandled',true];
				  _x call _DT_fnc_handleVehSafezone;
			  };
		  } forEach _vehicles;
		  uiSleep 1;
	  };
  };

missionNameSpace setVariable ["protectiveGear", [], true];
missionNameSpace setVariable ["radiationZones", [], true];

////////////////////////////////////////////////
//             EDITABLE VARIABLES             //
////////////////////////////////////////////////

// RADIATION
_detector = "ItemWatch";
_gasmasks = ["G_RegulatorMask_F"];
_showGasmaskOnMap = false;
_useAceDamage = false;
_radiationDamagePerTick = 0.01;
["U_C_CBRN_Suit_01_White_F", 4] spawn ZOR_fnc_protectiveGear;
["U_C_CBRN_Suit_01_Blue_F", 4] spawn ZOR_fnc_protectiveGear;
["U_B_CBRN_Suit_01_MTP_F", 4] spawn ZOR_fnc_protectiveGear;
["U_B_CBRN_Suit_01_WDL_F", 4] spawn ZOR_fnc_protectiveGear;
["U_B_CBRN_Suit_01_Tropic_F", 4] spawn ZOR_fnc_protectiveGear; 
["U_I_CBRN_Suit_01_AAF_F", 4] spawn ZOR_fnc_protectiveGear;
["U_I_E_CBRN_Suit_01_EAF_F", 4] spawn ZOR_fnc_protectiveGear;

["G_RegulatorMask_F", 1] spawn ZOR_fnc_protectiveGear;
["B_SCBA_01_F", 3] spawn ZOR_fnc_protectiveGear;

[markerPos "rad_zone_01", 100, 3] spawn ZOR_fnc_spawnRadiation;
[markerPos "rad_zone_02", 150, 9] spawn ZOR_fnc_spawnRadiation;

////////////////////////////////////////////////
//        DO NOT EDIT BELOW THIS LINE         //
////////////////////////////////////////////////

// RADIATION
missionNameSpace setVariable ["radiationDetector", _detector, true];
missionNameSpace setVariable ["radiationDamage", _radiationDamagePerTick, true];
missionNameSpace setVariable ["radiationGasmasks", _gasmasks, true];
missionNameSpace setVariable ["radiationShowGasmaskOnMap", _showGasmaskOnMap, true];
missionNameSpace setVariable ["radiationAceDamage", _useAceDamage, true];
missionNameSpace setVariable ["radiationInitialized", true, true];
