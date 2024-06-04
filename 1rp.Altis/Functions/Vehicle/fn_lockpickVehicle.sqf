/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_lockpickVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] } || { ((["Lockpick"] call ULP_fnc_hasItem) < 1) }) exitWith { if (dialog) then { closeDialog 0; }; };

closeDialog 0;

if (_vehicle in ULP_Keys) exitWith {
	["У вас уже есть ключи от этого транспортного средства"] call ULP_fnc_hint;
};

private _time = ["SpeedyLocksmith", round (40 + (random 25))] call ULP_fnc_activatePerk;

if ([] call ULP_fnc_isGroup) then {
	private _buff = [group player, "Отмычка"] call ULP_fnc_groupBuff;
	if (_buff > 0) then { _time = _time - (_time * _buff); };
};

[format["Взламываем %1", (_cfg param [3, "Транспортное средство"])], _time, [_vehicle, _cfg], { (player distance (_this select 0)) <= 5 }, {
	_this params [
		["_vehicle", objNull, [objNull]],
		["_cfg", configNull, [configNull]]
	];
	
	if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
		["Это транспортное средство слишком повреждено для взламывания..."] call ULP_fnc_hint;
	};

	if (_vehicle in ULP_Keys) exitWith {
		["У вас уже есть ключи от этого транспортного средства"] call ULP_fnc_hint;
	};

	if (["Отмычка", 1, true] call ULP_fnc_handleItem) then {
		if (0.7 <= (random 1)) then {
			[getPlayerUID player, "Theft", "Section12", 
				format [
					"Транспортное средство: %1 (%2)", 
					([typeOf _vehicle] call ULP_fnc_vehicleCfg) param [3, "Unknown"], 
					getText (missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle) >> "Textures" >> (_vehicle getVariable ["texture", ""]) >> "displayName")
				]
			] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];

			[format ["Вы успешно взломали замок <t color='#B92DE0'>%1</t> и получили поддельные ключи...", _cfg param [3, "vehicle"]]] call ULP_fnc_hint;
			ULP_Keys pushBackUnique _vehicle;
		} else {
			[getPlayerUID player, "CriminalAttempts", "Section1", 
				format [
					"Попытка взлома транспортного средства: %1 (%2)", 
					([typeOf _vehicle] call ULP_fnc_vehicleCfg) param [3, "Unknown"], 
					getText (missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle) >> "Textures" >> (_vehicle getVariable ["texture", ""]) >> "displayName")
				]
			] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];

			["Отмычка сломалась во время попытки взлома замка..."] call ULP_fnc_numberText;
		};
	} else {
		["Вы потеряли отмычку, пока пытались взломать транспортное средство и не смогли завершить процесс..."] call ULP_fnc_numberText;
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
