/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_withdrawMoney";

if (canSuspend) exitWith {
    [ULP_fnc_withdrawMoney, _this] call ULP_fnc_directCall;
};

_this params [
    "_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = _display getVariable ["group", false];

if (_group && { !([1] call ULP_fnc_canGroupRank) }) exitWith {
    ["У вас нет прав на снятие средств со счета группы!"] call ULP_fnc_hint;
};

private _amount = ([BANK, [] call ULP_fnc_groupFunds] select (_group));
if (_amount <= 0) exitWith {
    ["У вас нет средств для снятия!"] call ULP_fnc_hint;
};

[
    (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_group],
    {
        _this params [
            ["_group", false, [true]],
            ["_display", displayNull, [displayNull]],
            ["_value", 1, [0]]
        ];

        if (_group) then {
            [format ["Попытка снять %1%2...", "$", [_value] call ULP_fnc_numberText]] call ULP_fnc_hint;
            [player, _value] remoteExecCall ["ULP_SRV_fnc_handleGroupFunds", RSERV];
        } else {
            if (_value > BANK) exitWith {
                [format["У вас нет <t color='#B92DE0'>%1%2</t> для снятия!", "$", [_value] call ULP_fnc_numberText]] call ULP_fnc_hint;
            };

            if ([_value, true, "Bank Withdrawal"] call ULP_fnc_removeMoney) then {
                [_value, false, "Bank Withdrawal"] call ULP_fnc_addMoney;
                [format["Вы сняли <t color='#B92DE0'>%1%2</t>.", "$", [_value] call ULP_fnc_numberText]] call ULP_fnc_hint;
            };
        };
    }, false
] call ULP_fnc_selectNumber;
