/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_sellHouse";

_this params [
	["_building", objNull, [objNull]]
];

if ([player] call ULP_fnc_onDuty) exitWith {
	[["Вы не можете продавать дом, находясь на службе..."]] call ULP_fnc_hint;
};

private _cfg = [typeOf _building] call ULP_fnc_vehicleCfg;

if !(_cfg isEqualTo []) then {
	_cfg params [ "", "", "", "_name" ];

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Да", "Нет"],
		format ["Вы уверены, что хотите продать <t color='#B92DE0'>%1</t>, все сохраненные предметы будут утеряны...", _name], [_building],
		{	
			private _house = _this param [0, objNull];
			if (isNull _house) exitWith {};

			if (_house getVariable ["продается", false]) exitWith {
				[["Этот дом уже находится на продаже!"]] call ULP_fnc_hint;
			};

			_house setVariable ["selling", true];
			closeDialog 0;

		["HouseSold", {
				_this params [
					["_house", objNull, [objNull]],
					["_success", false, [true]],
					["_message", "", [""]],
					["_money", 0, [0]]
				];

				if (_success) then { [_money, true, "House Sold"] call ULP_fnc_addMoney; };
				[_message] call ULP_fnc_hint;

				_house setVariable ["selling", nil];
			}, true] call ULP_fnc_addEventHandler;

			["Продается дом..."] call ULP_fnc_hint;
			[getPlayerUID player, _house] remoteExecCall ["ULP_SRV_fnc_sellHouse", RSERV];
		}, {}, false
	] call ULP_fnc_confirm;
};
