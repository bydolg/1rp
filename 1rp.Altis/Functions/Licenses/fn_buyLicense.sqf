/*
** Автор: Джек "Scarso" Фархолл
** Описание:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyLicense";

if (canSuspend) exitWith {
    [ULP_fnc_buyLicense, _this] call ULP_fnc_directCall;
};

_this params [
	"_button"
];

if ([player] call ULP_fnc_onDuty) exitWith {
	["Вы не можете покупать лицензии находясь на службе..."] call ULP_fnc_hint;
};

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _list = _display displayCtrl 3903;
private _curSel = lbCurSel _list;

private _license = _list lbData _curSel;

if ([_license, (_list lbValue _curSel)] call ULP_fnc_addLicense) then {
	private _cfg = missionConfigFile >> "CfgLicenses" >> _license;
	if (isText (_cfg >> "onBought")) then {
		call compile getText (_cfg >> "onBought");
	};

	["Вы приобрели эту лицензию."] call ULP_fnc_hint;
	[] call ULP_fnc_listLicenses;
};
