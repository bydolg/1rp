/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onKilled";

_this params [
    ["_unit", objNull, [objNull]],
    ["_killer", objNull, [objNull]]
];

if (isNull _unit || { !(isPlayer _unit) }) exitWith {}; // Проверки...

if !(isNull objectParent _unit) then { moveOut _unit }; // Вынимаем из транспорта...

[] spawn ULP_UI_fnc_closeDialogs; // Убеждаемся, что все диалоги закрыты...

if ([] call ULP_UI_fnc_isProgress) then {
    [(["RscProgress"] call ULP_UI_fnc_getLayer), false] call ULP_UI_endProgress;
};

if ([] call ULP_fnc_isEscorting) then {
    detach ULP_Escort;
    ULP_Escort = nil;
};


ULP_Gear_Safe = [
    (getUnitLoadout _unit),
    [],
    [
        [ULP_UniformTexture, ""] select ((uniform _unit) isEqualTo ""),
        [ULP_BackpackTexture, ""] select ((backpack _unit) isEqualTo "")
    ]
]; 

// Удаление оружия...
_unit removeWeapon (primaryWeapon _unit);
_unit removeWeapon (handgunWeapon _unit);
_unit removeWeapon (secondaryWeapon _unit);
{ deleteVehicle _x; } forEach (nearestObjects [_unit, ["WeaponHolderSimulated"], 5]);

//[getPos _unit, getDir _unit] call ULP_fnc_createBodyBag;
//[_unit getPos [3,getDir _unit]] call ULP_fnc_dropMoney;
_mpos = (getPosATL _unit); 
[_mpos, getDir _unit] call ULP_fnc_createBodyBag;
_mpos set [2,_mpos#2+0.3]; 
[_mpos] call ULP_fnc_dropMoney;


ULP_Inventory = createHashMap; // Очистка инвентаря...
ULP_CarryInfo set [0, 0];
[] call ULP_fnc_saveGear;

// Закрытие скрипта отбирания...
if !(isNil { uiNamespace getVariable "_fnc_bleedout" }) then {
    [uiNamespace getVariable "_fnc_bleedout"] call ULP_fnc_removeEachFrame;
    uiNamespace setVariable ["_fnc_bleedout", nil];
};

// Экран смерти...
["RscIncapacitated"] call ULP_UI_fnc_destroyLayer;
"WaitToRespawn" cutText ["<t color='#ffffff' font='PuristaLight' size='2px'>ВЫ ПОГИБЛИ</t>", "BLACK", -1, false, true];

[getPos _unit] call ULP_fnc_addNLR;

ULP_Respawned = false;
ULP_CanRespawn = nil;

player setVariable ["IncapacitatedWounds", nil, true];

["Died", [_unit, _killer]] call ULP_fnc_invokeEvent;

[ { ULP_Respawned }, [], {
    uiNamespace setVariable ["IncapacitatedEffect", nil];
    [] call ULP_fnc_wipeEffects;

    "WaitToRespawn" cutText ["", "PLAIN"];
    [] call ULP_fnc_resetSurvival;
    [] call ULP_fnc_spawnMenu;
} ] call ULP_fnc_waitUntilExecute;
