/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_forgeIdentity";

if !([player, ["Civilian"]] call ULP_fnc_isFaction || { ["IDForger"] call ULP_fnc_hasPerk }) exitWith {
    ["Только граждане могут подделывать удостоверения личности!"] call ULP_fnc_hint;
};

[
    (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Введите имя для удостоверения личности", ["Готово", "Отмена"], "Введите имя здесь...", [],
    {   
        _this params [
            ["_name", "", [""]]
        ];

        _name = [_name] call ULP_fnc_stripString;

        if ((count _name) > getNumber (missionConfigFile >> "CfgSettings" >> "Identity" >> "nameLength")) exitWith {
            ["Только граждане могут подделывать удостоверения личности!"] call ULP_fnc_hint;
        };

        private _cost = getNumber (missionConfigFile >> "CfgVirtualItems" >> "Identification" >> "buyPrice");
        if ([] call ULP_fnc_isUndercover) then { _cost = 0 };

        if (CASH < _cost) exitWith {
            [format ["Вам нужно <t color='#B92DE0'>%1%2</t> для подделки удостоверения личности!", "$", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
        };

		if ([_cost, true, "Forged ID"] call ULP_fnc_removeMoney) then {
            if (["Identification", _name] call ULP_fnc_handleItem) then {
                [format ["Вы получили удостоверение личности с именем <t color='#B92DE0'>%1</t>.", _name]] call ULP_fnc_hint;
            } else {
                [format ["Вы не смогли получить удостоверение личности с именем <t color='#B92DE0'>%1</t>.", _name]] call ULP_fnc_hint;
            };
        } else {
            [format ["У вас нет денег для подделки удостоверения личности в размере <t color='#B92DE0'>%1%2</t>.", "$", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
        };
    }, false
] call ULP_fnc_enterString;
