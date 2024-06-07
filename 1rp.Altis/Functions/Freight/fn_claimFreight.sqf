/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#define FREIGHT_ITEM_CFG missionConfigFile >> "CfgVirtualItems" >> "FreightCargo"
#include "..\..\script_macros.hpp"
scopeName "fn_claimFreight";

if (canSuspend) exitWith {
    [ULP_fnc_claimFreight, _this] call ULP_fnc_directCall;
};

_this params [
    ["_trader", objNull, [objNull]]
];

if (isNull _trader) exitWith {};

if !(["Freight"] call ULP_fnc_hasGroupPerk) exitWith {
    ["Ваша группа не имеет доступа к этой миссии"] call ULP_fnc_hint;
};

private _near = ((_trader nearEntities [["Car"], 10]) select {
    !([_x] call ULP_fnc_getVehicleOwner isEqualTo "" &&
    { [player, _x] call ULP_fnc_isVehicleOwner })
});

if (_near isEqualTo []) exitWith {
    ["Поблизости нет грузовиков"] call ULP_fnc_hint;
};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (_near apply { 
    ([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "", "_picture", "_name" ]; 
    [_picture, _name, _x call BIS_fnc_netId, 0];
}), ["Готов", "Отмена"], [_trader], {
    _this params [
        ["_trader", objNull, [objNull]],
        ["_display", displayNull, [displayNull]]
    ];

    if ((player distance _trader) > 5) exitWith {
        ["Вы отошли слишком далеко"] call ULP_fnc_hint;
    };

    if (isNull _display) exitWith {};
    private _list = _display displayCtrl 4509;

    private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
    if (isNull _vehicle) exitWith { ["Вы не выбрали транспорт для заполнения грузом!"] call ULP_fnc_hint; };

    if !([_vehicle, getPos _trader] call ULP_fnc_isVehicleStationary) exitWith { ["Двигатель транспорта должен быть выключен и находиться рядом со знаком!"] call ULP_fnc_hint; };

    private _currentVehicleLoad = [_vehicle] call ULP_fnc_currentLoad;
    private _maxVehicleLoad = [_vehicle] call ULP_fnc_maxLoad;

    private _freightItemWeight = getNumber (FREIGHT_ITEM_CFG >> "weight");

    private _maxQuantity = ( floor ((_maxVehicleLoad - _currentVehicleLoad) / _freightItemWeight) max 0 );

    if (_maxQuantity <= 0) exitWith { ["У этого транспорта нет места, чтобы хранить хотя бы одну единицу груза!"] call ULP_fnc_hint; };

    private _time = (_freightItemWeight * _maxQuantity) / 8; // Делим на 8, иначе процесс может занять несколько минут

    private _vehicleCfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;

    private _item = configName (FREIGHT_ITEM_CFG);

    if (_item in getArray ((_vehicleCfg select 1) >> "blacklistedItems")) exitWith {
        ["Грузовик должен использоваться для грузовых миссий"] call ULP_fnc_hint;
    };

    [format["Заполнение %1 грузом", _vehicleCfg param [3, "транспорт"]], _time, [_trader, _vehicle, _maxQuantity, _item], 
        { (player distance (_this select 0)) <= 5 && { [(_this select 1), getPos (_this select 0)] call ULP_fnc_isVehicleStationary } }, 
        {
            _this params [ "_trader", "_vehicle", "_maxQuantity", "_item" ];

            if (isNull _vehicle) exitWith {};

            if ("CorporateFreight" in ULP_Missions) exitWith {
                [getText (missionConfigFile >> "CfgMissions" >> "CorporateFreight" >> "Messages" >> "onAlreadyHas")] call ULP_fnc_hint;
            };

            private _cargoParams = [_vehicle, _item, _maxQuantity];

            if !(_cargoParams call ULP_fnc_addToCargo) exitWith {
                ["Этот транспорт не может вместить ожидаемое количество грузов, убедитесь, что ничего не добавляется во время этого процесса!"] call ULP_fnc_hint;
            };

            missionNamespace setVariable ["ULP_FreightVehicle", [_vehicle, _maxQuantity]];

            if !(["CorporateFreight", (str _trader)] call ULP_fnc_claimMission) exitWith {
                _cargoParams call ULP_fnc_removeFromCargo;
            };
        }, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
    }, false] call ULP_fnc_selectObject;