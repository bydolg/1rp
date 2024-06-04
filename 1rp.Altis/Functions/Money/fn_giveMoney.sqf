/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_giveMoney";

if (canSuspend) exitWith {
    [ULP_fnc_giveMoney, _this] call ULP_fnc_directCall;
};

_this params [
    ["_unit", objNull, [objNull]],
    ["_bank", false, [true]]
];

if (isNull _unit || { [] call ULP_fnc_isRestrained } || { [] call ULP_fnc_isSurrendered } || { isDowned(player) } || { isDowned(_unit) } || { !_bank && ((player distance _unit) > 3) }) exitWith {
    ["Для передачи денег вы должны быть рядом, находиться в свободном состоянии и не сдаваться..."] call ULP_fnc_hint;
    false
};

private _max = [CASH, BANK] select (_bank);

if (_max < 1) exitWith {
    ["У вас нет денег для передачи в данный момент..."] call ULP_fnc_hint;
    false
};

[
    (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _max], [_unit, _bank],
    {
        _this params [
            ["_unit", objNull, [objNull]],
            ["_bank", false, [true]],
            ["_display", displayNull, [displayNull]],
            ["_value", 1, [0]]
        ];

        [_unit, _value, _bank] call ULP_fnc_sendMoney;
    }, false
] call ULP_fnc_selectNumber;
true
