/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyHouse";

if (canSuspend) exitWith {
    [ULP_fnc_buyHouse, _this] call ULP_fnc_directCall;
};

_this params [
    ["_house", objNull, [objNull]]
];

if ([player] call ULP_fnc_onDuty) exitWith {
    ["Вы не можете купить дом, находясь на службе..."] call ULP_fnc_hint;
};

private _objectCfg = [typeOf _house] call ULP_fnc_vehicleCfg;

if !([_house] call ULP_fnc_isHouse || 
    { isClass (missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction >> "Housing") } || 
    { [_house] call ULP_fnc_isHouseOwned } ||
    { (count _objectCfg) > 0 }
) exitWith {
    ["Этот дом нельзя купить!"] call ULP_fnc_hint;
};

if !(["Home"] call ULP_fnc_hasLicense) exitWith {
    ["Вам нужно разрешение владельца дома, чтобы купить дом."] call ULP_fnc_hint;
};

if (_house getVariable ["blacklisted", false]) exitWith {
    ["Этот дом находится в черном списке."] call ULP_fnc_hint;
};

if !(call compile getText (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house) >> "condition")) exitWith {
    ["Вы не можете купить этот дом в данный момент..."] call ULP_fnc_hint;
};

private _limit = getNumber (missionConfigFile >> "CfgHousing" >> "houseLimit");
if (["LandLord"] call ULP_fnc_hasPerk) then { _limit = _limit + 1 };
if ((count ([_house] call ULP_fnc_ownedHouses)) >= _limit) exitWith {
    [format ["Вы уже достигли лимита в <t color='#B92DE0'>%1</t> для собственности.", _limit]] call ULP_fnc_hint;
};

private _money = getNumber (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house) >> "price");

_objectCfg params [ "", "", "", "_name" ];

[
    (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
    format ["Вы уверены, что хотите потратить <t color='#B92DE0'>%1%2</t> на <t color='#B92DE0'>%3</t>...", "$", [_money] call ULP_fnc_numberText, _name], [_house, _money],
    {   
        _this params [
            ["_house", objNull, [objNull]],
            ["_money", 0, [0]]
        ];

        if (isNull _house) exitWith {};

        if (_house getVariable ["buying", false]) exitWith {
            ["Этот дом уже покупается!"] call ULP_fnc_hint;
        };

        _house setVariable ["buying", true];
        closeDialog 0;

        ["HouseBought", {
            _this params [
                ["_house", objNull, [objNull]],
                ["_success", false, [true]],
                ["_message", "", [""]],
                ["_money", 0, [0]]
            ];

            if (_success) then {
                [[_house]] call ULP_fnc_setupHouses;
                ["BuyHouse"] call ULP_fnc_achieve;
                
                private _cfg = missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house);
                if (isText (_cfg >> "onBought")) then {
                    call compile getText (_cfg >> "onBought");
                };
            } else {
                [_money, true, "Покупка дома не удалась"] call ULP_fnc_addMoney;
            };

            [_message] call ULP_fnc_hint;

            _house setVariable ["buying", nil];
        }, true] call ULP_fnc_addEventHandler;

		if ([_money, true, "Bought House"] call ULP_fnc_removeMoney) then {
            ["Покупка дома..."] call ULP_fnc_hint;
            [player, _house, _money] remoteExecCall ["ULP_SRV_fnc_buyHouse", RSERV];
        } else {
            [format ["У вас нет достаточно средств <t color='#B92DE0'>%1%2</t> для покупки этой собственности!", "$", [_money] call ULP_fnc_numberText]] call ULP_fnc_hint;
        };
    }, {}, false
] call ULP_fnc_confirm;
