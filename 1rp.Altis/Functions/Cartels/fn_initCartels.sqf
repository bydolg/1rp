/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initCartels";

["Initialising Cartels"] call ULP_fnc_logIt;

if !(hasInterface) exitWith {};

{
	private _object = missionNamespace getVariable [format["ULP_SRV_Cartel_%1", configName _x], objNull];
	if !(isNull _object) then {
		if ([player, getArray (_x >> "factions")] call ULP_fnc_isFaction) then {
			private _zoneRadius = getNumber (_x >> "zoneRadius");

			private _trigger = createTrigger ["EmptyDetector", getArray (_x >> "position"), false];
			
      private _markerName = format["MRK_Cartel_%1", configName _x];
			private _markerName_safe = format["MRK_Cartel_%1_safe", configName _x];
            
      _trigger setTriggerArea [_zoneRadius, _zoneRadius, 0, false];
      
      _marker = createMarker [_markerName, getArray (_x >> "position")];
      _marker setMarkerShape "ELLIPSE";
      _marker setMarkerSize [_zoneRadius + _zoneRadius, _zoneRadius + _zoneRadius];

      _marker_safe = createMarker [_markerName_safe, getArray (_x >> "position")];
      _marker_safe setMarkerShape "ELLIPSE";
      _marker_safe setMarkerSize [_zoneRadius, _zoneRadius];
			
      _trigger setTriggerActivation ["ANYPLAYER", "PRESENT", true];
			_trigger setTriggerStatements 
      [
      "this && { (vehicle player) in thisList }", 
      format ["[""%1"", ""create""] call ULP_fnc_cartelHud;
      _arrayUnitsADS = [""I_C_Soldier_Bandit_8_F"",""I_C_Soldier_Bandit_5_F"",""I_C_Soldier_Bandit_4_F"",""I_C_Soldier_Bandit_1_F""]; 
      null = [east,_arrayUnitsADS,[6,true],[""MRK_Cartel_%1"", ""MRK_Cartel_%1_safe""],3,120] execVM ""ADS_system\functions\launchADS.sqf"";", configName _x], 
      format ["[""%1"", ""remove""] call ULP_fnc_cartelHud; StopAttacksADS = 1; publicVariable ""StopAttacksADS""; { deleteVehicle _x } forEach allDeadMen;", configName _x]
      ];

			_object setVariable ["trigger", _trigger];
		};
	};
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgCartels" >> "Fixed"));

["CartelPayout", {
	_this params [
		["_cartel", "", [""]],
		["_personal", 0, [0]],
		["_group", 0, [0]]
	];

	if (_personal > 0) then {
		[_personal, true, format ["Cartel Payout"]] call ULP_fnc_addMoney;
	};

	[getNumber (missionConfigFile >> "CfgCartels" >> "Fixed" >> "rewardXp"), format["holding %1", _cartel]] call ULP_fnc_addXP;

	if ([["NotifyPayment", "Cartels"] call ULP_fnc_getOption] call ULP_fnc_bool) then {
		[format ["За удержание <t color='#B92DE0'>%1</t> вам заплатили <t color='#B92DE0'>%2%3</t> и ваша группа получила <t color='#B92DE0'>%2%4</t>", _cartel, "$", [_personal] call ULP_fnc_numberText, [_group] call ULP_fnc_numberText]] call ULP_fnc_hint;
	};

	["CartelLord"] call ULP_fnc_achieve;
}] call ULP_fnc_addEventHandler;