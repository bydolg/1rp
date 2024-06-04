/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openHud";

if ([] call ULP_UI_fnc_isHudShown) exitWith {
	if (["EnableHUD", "HUD"] call ULP_fnc_getOption isEqualTo 0) then {
		[(["RscHUD"] call ULP_UI_fnc_getLayer)] call ULP_UI_fnc_closeHUD;
	};

	false
};

if (["RscHUD", "PLAIN", 3] call ULP_UI_fnc_createLayer) then {
	private _ui = ["RscHUD"] call ULP_UI_fnc_getLayer;
	if (isNull _ui) exitWith {}; // Shouldn't happen but we'll be safe...

	_ui setVariable ["food", -1];
	_ui setVariable ["water", -1];
	_ui setVariable ["health", -1];
	_ui setVariable ["icons", []];

	disableSerialization;

	private _foodText = _ui displayCtrl 501;
	private _foodBar = _ui displayCtrl 515;
	private _waterText = _ui displayCtrl 503;
	private _waterBar = _ui displayCtrl 514;
	private _healthText = _ui displayCtrl 505;
	private _healthBar = _ui displayCtrl 513;
	private _moneyText = _ui displayCtrl 512;
	_moneyText ctrlSetStructuredText parseText format["<t align='right'>$%1</t>", [CASH] call ULP_fnc_numberText];

	_ui setVariable ["eachframe", ([[_ui, [_foodText, _foodBar], [_waterText, _waterBar], [_healthText, _healthBar]], { _this call ULP_UI_fnc_eachFrameHUD }] call ULP_fnc_addEachFrame)];

	[] call ULP_UI_fnc_updateXpHud;
	_ui setVariable ["eventhandler", (["OnXPIncreased", { [] call ULP_UI_fnc_updateXpHud; }] call ULP_fnc_addEventHandler)];
	
	_ui setVariable ["money", (["MoneyChanged", {
		_this params [
			["_cash", 0, [0]],
			["_bank", 0, [0]]
		];

		private _ui = ["RscHUD"] call ULP_UI_fnc_getLayer;
		if (isNull _ui) exitWith {};

		(_ui displayCtrl 512) ctrlSetStructuredText parseText format["<t align='right'>$%1</t>", [_cash] call ULP_fnc_numberText];
	}] call ULP_fnc_addEventHandler)];
	
	true breakOut "fn_openHud";
};

false