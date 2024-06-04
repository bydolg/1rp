/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
scopeName "fn_sync";

if ([player] call ULP_fnc_onDuty) exitWith {
	["Вы не можете синхронизировать данные, находясь на службе администратора!"] call ULP_fnc_hint;
};

if (time <= (ULP_Last_Sync + getNumber(missionConfigFile >> "CfgSettings" >> "sync_delay"))) exitWith {
	["Ваши данные были синхронизированы недавно. Пожалуйста, подождите между автоматическими и ручными синхронизациями..."] call ULP_fnc_hint;
};

[] call ULP_fnc_syncPlayerInfo;
ULP_Last_Sync = time;

["Синхронизация информации игрока на сервер. Пожалуйста, подождите до <t color='#B92DE0'>20 секунд</t>, прежде чем уходить..."] call ULP_fnc_hint;
