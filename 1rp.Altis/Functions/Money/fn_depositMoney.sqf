/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_depositMoney";

if (canSuspend) exitWith {
    [ULP_fnc_depositMoney, _this] call ULP_fnc_directCall;
};

_this params [
    "_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = _display getVariable ["group", false];

if (_group && { !([0] call ULP_fnc_canGroupRank) }) exitWith {
    ["У вас нет разрешения на внесение денег в групповой счет!"] call ULP_fnc_hint;
};

private _amount = CASH;
if (_amount <= 0) exitWith {
    ["У вас нет средств для депозита!"] call ULP_fnc_hint;
};

[
    (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_group],
    {
        _this params [
            ["_group", false, [true]],
            ["_display", displayNull, [displayNull]],
            ["_value", 1, [0]]
        ];

        if (_value > CASH) exitWith {
            [format["У вас нет <t color='#B92DE0'>%1%2</t> для депозита!", "$", [_value] call ULP_fnc_numberText]] call ULP_fnc_hint;
        };

		if ([_value, false, "Bank Deposit"] call ULP_fnc_removeMoney) then {
            if (_group) then {
                [player, _value, true] remoteExecCall ["ULP_SRV_fnc_handleGroupFunds", RSERV];
            } else {
				[_value, true, "Bank Deposit"] call ULP_fnc_addMoney;
            };

            [format["Вы внесли <t color='#B92DE0'>%1%2</t>.", "$", [_value] call ULP_fnc_numberText]] call ULP_fnc_hint;
        };
    }, false
] call ULP_fnc_selectNumber;
