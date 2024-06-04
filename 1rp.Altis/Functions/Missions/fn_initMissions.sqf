/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initMissions";

["Инициализация миссий"] call ULP_fnc_logIt;

["Смерть", {
    if ((count ULP_Missions) > 0) then {
        {
            _y params [
                "_task", "_reward", "_eachFrame"
            ];

			_task setTaskState "Failed";
            player removeSimpleTask _task;
        } forEach ULP_Missions;

        ULP_Missions = createHashMap;
    };

    // Обработка грузовых автомобилей
    private _vehicle = (missionNamespace getVariable ["ULP_FreightVehicle", [objNull, 0]]) param [0, objNull];

    if !(isNull _vehicle) then {
        private _countRemoved = [_vehicle, "FreightCargo"] call ULP_fnc_wipeItemFromCargo;

        if (_countRemoved > 0) exitWith {
            ["Вы умерли, и весь груз был потерян из вашего грузовика."] call ULP_fnc_hint;
        };
    };
}] call ULP_fnc_addEventHandler;
