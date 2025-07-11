/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initPolice";

["Initialising Police Related Events"] call ULP_fnc_logIt;

["TicketPaid", {
	_this params [
		["_name", "", [""]],
		["_amount", 0, [0]],
		["_paid", false, [true]]
	];

	if (_name isEqualTo "" || { _amount < 0 }) exitWith {};

	if (_paid) then {
		[format ["%1 оплатил свое уведомление о штрафе в размере %2%3", _name, "$", [_amount] call ULP_fnc_numberText]] call ULP_fnc_hint;
		[round (_amount / 2), true, format ["Штраф для %1", _name]] call ULP_fnc_addMoney;
	} else {
		[format ["<t color='#B92DE0'>%1</t> отказался или не смог оплатить свое уведомление о штрафе..."]] call ULP_fnc_hint;
	};
}] call ULP_fnc_addEventHandler;

["TicketRecieved", {
	_this params [
		["_unit", objNull, [objNull]],
		["_amount", 0, [0]]
	];

	if (isNull _unit || { _amount < 0 }) exitWith {};

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Penalty Notice", ["Pay", "Refuse"],
		format ["%1 выписал вам уведомление о штрафе в размере %2%3", [_unit, true] call ULP_fnc_getName, "$", [_amount] call ULP_fnc_numberText], [_unit, _amount],
		{	
			_this params [ "_unit", "_amount" ];

			if (isNull _unit) exitWith {};

			private _name = [player, true] call ULP_fnc_getName;

			if ([_amount, true, "Penalty Notice"] call ULP_fnc_removeMoney) then {
				[format ["Вы оплатили фиксированный штраф в размере <t color='#B92DE0'>%1%2</t>", "$", [_amount] call ULP_fnc_numberText]] call ULP_fnc_hint;
				["TicketPaid", [_name, _amount, true]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
				["FinePaid", [_name, format ["%1%2", "$", [_amount] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
			} else {
				["У вас недостаточно денег для оплаты этого уведомления о штрафе..."] call ULP_fnc_hint;
				["TicketPaid", [_name, _amount, false]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
				["FinePoor", [_name, format ["%1%2", "$", [_amount] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
			};
		}, {
			_this params [ "_unit", "_amount" ];

			if (isNull _unit) exitWith {};
			
			private _name = [player, true] call ULP_fnc_getName;

			["TicketPaid", [_name, _amount, false]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			["FineRefused", [_name, format ["%1%2", "$", [_amount] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
		}, false
	] call ULP_fnc_confirm;
}] call ULP_fnc_addEventHandler;

["LicensesShown", {
	_this params [
		["_unit", objNull, [objNull]],
		["_licenses", [], [[]]],
		["_shown", false, [true]],
		["_refused", false, [true]]
	];

	if (isNull _unit) exitWith {};

	_unit setVariable ["licenses_requested", nil];

	private _name = [_unit, true] call ULP_fnc_getName;

	if (_licenses isEqualTo []) exitWith {
		[format ["%1 не имеет лицензий...", _name]] call ULP_fnc_hint;
	};

	if (_shown) then {
		if (_refused) exitWith {
			[format ["%1 отказался вам показать свои лицензии...", _name]] call ULP_fnc_hint;
		};

		[format ["<t color='#FF0000'><t size='1.7' align='center'>%1</t></t><br/><t color='#FFD700'><t size='1.5' align='center'>Лицензии</t></t><br/><t align='center'>%2</t>", _name, (_licenses apply {
			if (isClass (missionConfigFile >> "CfgLicenses" >> _x >> "displayName"))  exitWith {
				getText (missionConfigFile >> "CfgLicenses" >> _x >> "displayName")
			};

			_x
		}) joinString "<br/>"]] call ULP_fnc_hint;
	} else {
		if (createDialog "DialogSeizeLicenses") then {
			private _display = findDisplay 5100;
			if (isNull _display) exitWith {};

			_display setVariable ["unit", _unit];
			
			(_display displayCtrl 5101) ctrlSetText format ["Лицензии %1", _name];

			private _list = _display displayCtrl 5102;
			lbClear _list;

			{
				private _license = missionConfigFile >> "CfgLicenses" >> _x;

				if (isClass _license) then {
					private _item = _list lbAdd getText (_license >> "displayName");
					_list lbSetData [_item, _x];
				};
			} forEach _licenses;
		} else {
			[format ["Что-то пошло не так при попытке отобразить лицензии %1...", _name]] call ULP_fnc_hint;
		};
	};
}] call ULP_fnc_addEventHandler;

["RequestLicenses", {
	_this params [
		["_unit", objNull, [objNull]]
	];

	if (isNull _unit) exitWith {};

	if ([player] call ULP_fnc_isRestrained) then {
		["LicensesShown", [player, ULP_Licenses, false]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	} else {
		[
			(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Accept", "Decline"],
			format ["%1 запросил у вас лицензии, вы соглашаетесь?", [_unit, true] call ULP_fnc_getName], [_unit],
			{
				private _unit = _this param [0, objNull];
				if (isNull _unit) exitWith {};
				["LicensesShown", [player, ULP_Licenses, true]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			}, {
				private _unit = _this param [0, objNull];
				if (isNull _unit) exitWith {};
				["LicensesShown", [player, ULP_Licenses, true, true]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			}, false
		] call ULP_fnc_confirm;
	};
}] call ULP_fnc_addEventHandler;

["LicenseSeized", {
	_this params [
		["_unit", objNull, [objNull]],
		["_license", "", [""]]
	];

	if (isNull _unit || { !([_license] call ULP_fnc_hasLicense) }) exitWith {};
	
	ULP_Licenses deleteAt (ULP_Licenses find _license);

	[format ["%1 изъял ваш %2", [_unit, true] call ULP_fnc_getName, getText (missionConfigFile >> "CfgLicenses" >> _license >> "displayName")]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;
