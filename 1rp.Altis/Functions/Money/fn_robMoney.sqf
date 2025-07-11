/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_robMoney";

if (canSuspend) exitWith {
    [ULP_fnc_robMoney, _this] call ULP_fnc_directCall;
};

_this params [
    ["_mode", 0, [0]],
    ["_params", [], []]
];

switch (_mode) do {
    case 2: {
        _params params [
            ["_unit", objNull, [objNull]],
            ["_cash", 0, [0]]
        ];

        if (isNull _unit || { _unit isEqualTo player }) exitWith {};

		if (_cash > 0 && { [_cash, false, format ["%2 %1", name _unit, ["Robbed", "Seized"] select ([player, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_addMoney }) then {
			[format ["Вы %4 %1's <t color='#B92DE0'>%2%3</t>", [_unit, true] call ULP_fnc_getName, "$", [_cash] call ULP_fnc_numberText, ["robbed", "seized"] select ([player, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_hint;
			_unit setVariable ["robbing", nil];

			[getPlayerUID player, "Robbery", [name _unit, _cash]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
        } else {
            [format ["У %1 не было денег, чтобы %2...", [_unit, true] call ULP_fnc_getName, ["rob", "seize"] select ([player, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_hint;
        };
    };

    case 1: {
        _params params [
            ["_unit", objNull, [objNull]]
        ];

        if (isNull _unit || { _unit isEqualTo player }) exitWith {};

        private _cash = + CASH;
		if (_cash > 0 && { [_cash, false, format ["%2 By %1", name _unit, ["Robbed", "Seized"] select ([_unit, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_removeMoney }) then {
			[format ["%1 был %4 <t color='#B92DE0'>%2%3</t> с вас", [_unit, true] call ULP_fnc_getName, "$", [_cash] call ULP_fnc_numberText, ["robbed", "seized"] select ([_unit, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_hint;
        };

		_unit setVariable ["robbed_me", time];

        [2, [player, _cash]] remoteExecCall ["ULP_fnc_robMoney", _unit];
    };

    default {
        _params params [
            ["_unit", objNull, [objNull]]
        ];

        if (isNull _unit || { _unit isEqualTo player }) exitWith {};

		if (_unit getVariable ["robbing", false]) exitWith {
            [format ["Вы уже %1 наличные у этого человека...", ["robbing", "seizing"] select ([player, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_hint;
        };
		_unit setVariable ["robbing", true];
		_unit setVariable ["robbed_by_me", time];

        [1, [player]] remoteExecCall ["ULP_fnc_robMoney", _unit];
    };
};
