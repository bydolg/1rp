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