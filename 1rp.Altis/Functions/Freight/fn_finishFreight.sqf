/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_finishFreight";

if (canSuspend) exitWith {
    [ULP_fnc_finishFreight, _this] call ULP_fnc_directCall;
};

if !("CorporateFreight" in ULP_Missions) exitWith {
    [getText (missionConfigFile >> "CfgMissions" >> "CorporateFreight" >> "Messages" >> "onFinishWithoutMission")] call ULP_fnc_hint;
    false
};

(missionNamespace getVariable ["ULP_FreightVehicle", [objNull, 0]]) params [
    "_vehicle",
    "_expectedQuantity"
];

if (isNull _vehicle || { !(alive _vehicle) } || { (player distance _vehicle) > 15 }) exitWith {
    ["Ваш оригинальный транспорт был уничтожен или вы слишком далеко от него"] call ULP_fnc_hint;
    false
};

private _countRemoved = [_vehicle, "FreightCargo"] call ULP_fnc_wipeItemFromCargo;

if !(_countRemoved isEqualTo _expectedQuantity) exitWith {
    ["В вашем транспорте не было ожидаемого количества груза, награда не будет выдана."] call ULP_fnc_hint;
    false
};

private _secondaryReward = getNumber (missionConfigFile >> "CfgVirtualItems" >> "FreightCargo" >> "sellPrice") * _countRemoved;

[_secondaryReward, false, "Freight Mission Cut"] call ULP_fnc_addMoney;
[(group player), "Freight"] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];

[format ["Вам начислено %1%2 за груз и вы заработали немного опыта группы", "$", [_secondaryReward] call ULP_fnc_numberText]] call ULP_fnc_hint;

true
