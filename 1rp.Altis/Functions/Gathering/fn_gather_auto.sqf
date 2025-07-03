#include "..\..\script_macros.hpp"
scopeName "fn_gather_auto";

if !(["JoinRebel"] call ULP_fnc_hasAchieved) exitWith { ["Невышло! Нужно найти тех кто научит!"] call ULP_fnc_hint;};
private _near = ((player nearEntities [["Car"], 10]) select {        
    !([_x] call ULP_fnc_getVehicleOwner isEqualTo "" &&        
    { [player, _x] call ULP_fnc_isVehicleOwner })        
});        
private _list = (_near apply {       
    ([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "", "_picture", "_name" ];       
    [_picture, _name, _x call BIS_fnc_netId, 0]; }); private _zone = [] call ULP_fnc_getGatherZone;        
  
private _resources = getArray (_zone >> "items");       
private _items = _resources apply { _x select 0 };        
private _weights = _resources apply { (_x select 1) / 100 };     
private _weights1 = getNumber (missionConfigFile >> "CfgVirtualItems" >> _items#0 >> "weight");       
private _veh = _list#0#2 call BIS_fnc_objectFromNetId;     
private _currentVehicleLoad = [_veh] call ULP_fnc_currentLoad;      
private _maxVehicleLoad = [_veh] call ULP_fnc_maxLoad;     
private _maxQuantity = ( floor ((_maxVehicleLoad - _currentVehicleLoad) / _weights1) max 0 );     
private _time = (_weights1 * _maxQuantity) / 8;  private _vehicleCfg = [typeOf _veh] call ULP_fnc_vehicleCfg;     
if (_maxQuantity <= 0) exitWith { ["У Вашего транспорта нет места, чтобы хранить хотя бы одну единицу груза!"] call ULP_fnc_hint; };    
if (_items isEqualTo []) exitWith { ["Вы не в зоне погрузки!"] call ULP_fnc_hint;};     
[format["Загрузка %1 грузом", _vehicleCfg param [3, "транспорт"]], _time, [_veh, _maxQuantity, _items#0],      
        {true},      
        {     
            _this params [ "_veh", "_maxQuantity", "_item" ];     
            if (isNull _veh) exitWith {};     
            private _cargoParams = [_veh, _item, _maxQuantity];     
     
            if !(_cargoParams call ULP_fnc_addToCargo) exitWith     
            {     
                ["Ваш транспорт не может вместить ожидаемое количество груза, убедитесь, что ничего не добавляется во время погрузки!"] call ULP_fnc_hint;     
            };     
        }, {}, ["", ""]] call ULP_UI_fnc_startProgress; 