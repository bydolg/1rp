
/*
 * Безопасное применение экипировки после полной инициализации игрока
 */
params ["_loadout"];

if (_loadout isEqualTo [] || isNil "_loadout") exitWith {
    diag_log "[SAFELOADOUT] Пустой лоадаут, пропуск.";
};

private _frameHandle = addMissionEventHandler ["EachFrame", {
    if (!isNull player && local player && alive player && !(uniform player isEqualTo "")) then {
        diag_log format ["[SAFE LOAD_GEAR] Applying: %1", _loadout];
        diag_log format ["[SAFE LOAD] local: %1, player: %2, alive: %3", local player, player, alive player];
        player setUnitLoadout _loadout;
        diag_log format ["[SAFE LOADOUT] Применили экипировку: %1", _loadout];
        removeMissionEventHandler ["EachFrame", _thisEventHandler];
    };
}];
