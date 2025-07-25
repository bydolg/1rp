/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_transferGarage";

if (canSuspend) exitWith {
    [ULP_fnc_transferGarage, _this] call ULP_fnc_directCall;
};

_this params [
    "_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _vehInfo = _display getVariable ["selected", []];
if (_vehInfo isEqualTo []) exitWith {};

_vehInfo params [ "_id", "_classname", "", "", "", "_faction" ];

private _cfg = [_classname] call ULP_fnc_vehicleCfg;
if (_cfg isEqualTo []) exitWith {};

_cfg params [ "", "_missionCfg", "", "_name" ];

if !([getNumber (_missionCfg >> "canTransfer")] call ULP_fnc_bool) exitWith {
    ["Это транспортное средство нельзя передать"] call ULP_fnc_hint;
};

[ (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [_faction], [_display, _id, _name, _classname, _faction], {
    _this params [
        ["_display", displayNull, [displayNull]],
        ["_vehId", -1, [0]],
        ["_name", "", [""]],
        ["_classname", "", [""]],
        ["_faction", "", [""]],
        ["_selectDisplay", displayNull, [displayNull]]
    ];

    if (isNull _selectDisplay || { isNull _display } || { _vehId <= 0 }) exitWith {};

    private _list = _selectDisplay displayCtrl 3809;

    private _player = (_list tvData (tvCurSel _list)) call BIS_fnc_objectFromNetId;
    if (isNull _player) exitWith {
        ["Вы не выбрали никого!"] call ULP_fnc_hint;
    };

    if !(isNil { player getVariable "vehicle_transfer" }) exitWith {
        ["Вы уже ждете результатов другого трансфера. Пожалуйста, подождите завершения этого перед попыткой еще одного"] call ULP_fnc_hint;
    };
    player setVariable ["vehicle_transfer", _vehId];

    ["VehicleTransferred", {
        if (isNil { player getVariable "vehicle_transfer" }) exitWith {};
        player setVariable ["vehicle_transfer", nil];

        private _message = _this param [0, "Ваше транспортное средство успешно передано."];
        [_message] call ULP_fnc_hint;
    }, true] call ULP_fnc_addEventHandler;

    private _list = _display displayCtrl 3501;
    _list lbDelete (lbCurSel _list);

    _list lbSetCurSel 0;
    [_list, 0] call ULP_fnc_onGarageSwitch;

    [player, _player, _vehId, _classname, _faction] remoteExecCall ["ULP_SRV_fnc_transferVehicle", RSERV];
    [format ["Запрос на передачу вашего <t color='#B92DE0'>%1</t> <t color='#B92DE0'>%2</t>...", _name, name _player]] call ULP_fnc_hint;
}, false, false] call ULP_fnc_selectPlayer;
