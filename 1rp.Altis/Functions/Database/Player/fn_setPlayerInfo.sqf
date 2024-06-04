/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_setPlayerInfo";

if (ULP_Loaded) exitWith {};

if (canSuspend) exitWith {
    [ULP_fnc_setPlayerInfo, _this] call ULP_fnc_directCall;
};

_this params [
	["_playerData", false, [[], false]]
];

["Установка информации об игроке"] call ULP_fnc_logIt;

if (_playerData isEqualType false) exitWith {}; // Ошибка

_playerData params ["_uid", "_steamid", "_groupid", "_cash", "_bank", "", "", "_adminlevel", "_eventslevel", "_donorlevel", "_licenses", "_gear", "_stats", "_professions", "_prestige", "_level", "_xp", "_achievements", "_daily", "_weekly", "_textures", "_titles", "_perks", "_reputation", "_blueprints", "_bool"];
private _count = count _playerData;

if !(_steamid isEqualTo (getPlayerUID player)) exitWith {}; // Ошибка

private _factionCfg = missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction; // Получаем конфигурацию нашей текущей фракции...

ULP_ID = _uid;

// Деньги...
CASH = _cash;
BANK = _bank;

// Система белого списка...
CONST(ULP_Staff, _adminlevel);
CONST(ULP_Event, _eventslevel);
CONST(ULP_Donator, _donorlevel);

ULP_Licenses = (_licenses select {
	isClass (missionConfigFile >> "CfgLicenses" >> _x)
});

ULP_Professions = _professions;
ULP_Achievements = _achievements;

private _max = [] call ULP_fnc_getMaxLevel;
if (_level > _max) then { _level = _max; };

private _required = [_level] call ULP_fnc_getRequiredXP;
for "_i" from 0 to 1 step 0 do {
	scopeName "fn_setPlayerInfo_rankLoop";

	if (_xp < _required) exitWith {};

	if (_xp >= _required) then {
		if (_level isEqualTo _max) then {
			_xp = _required;
			breakOut "fn_setPlayerInfo_rankLoop";
		} else {
			_xp = _xp - _required;
			_level = _level + 1;
			_required = [_level] call ULP_fnc_getRequiredXP;
		};
	};
};

ULP_Prestige = _prestige;
ULP_Level = _level;
ULP_XP = _xp;

// Устанавливаем сохраненную статистику выживания....
ULP_Survival_Hunger = (_stats select 0);
ULP_Survival_Thirst = (_stats select 1);
player setDamage (_stats select 2);

// TODO : Обработать Черный список...

switch (configName _factionCfg) do {
	case "Civilian": {
		ULP_Imprisioned = _bool;
		ULP_Prison_Time = _playerData select 26;

		// Обработка под прикрытием...
		private _copLevel = _playerData select 27;
		private _ucLevel = _playerData select 28;
		if (_copLevel > 0 && { _ucLevel > 0 }) then {
			ULP_UCLevels = [_copLevel, _ucLevel];
		};
	};
};

// Устанавливаем любые значения белого списка, которые может иметь наша фракция...
if (isClass (_factionCfg >> "Whitelisting")) then {
	{
		missionNamespace setVariable [format["%1_%2", configName _factionCfg, configName _x], compileFinal str(_playerData select (getNumber(_x >> "queryIndex")))];
	} forEach ("isNumber(_x >> 'queryIndex')" configClasses (_factionCfg >> "Whitelisting"));
};

// Добавляем себя в группу, если мы в ней...
private _group = _playerData select (_count - 5);
if (_group isEqualType 0) then {
	if !(_groupid isEqualTo _group) exitWith {
		[format["Сервер не заметил несоответствие идентификатора группы (%1, %2)", _groupid, _group]] call ULP_fnc_logIt;
	};

	InitGroupId = _groupid;
	[format["Присоединились к группе (%1)", _group]] call ULP_fnc_logIt;
};

// Получаем любые дома, возвращенные нам сервером, и настраиваем их...
private _houses = _playerData select (_count - 4);
if (_houses isEqualType []) then {
	[_houses] call ULP_fnc_setupHouses;
};

// Получаем ключи от транспортных средств, которые у нас были на этом рестарте...
{
	ULP_Keys pushBack _x
} forEach (_playerData select (_count - 3));

[_daily, _weekly] call ULP_fnc_initPersonalGoals;

ULP_New = (_playerData select (_count - 2)); // Говорит нам, является ли это новым вставкой в базу данных...
ULP_Date = (_playerData select (_count - 1)); // Содержит Год, Месяц и День в этом порядке...

// Применяем наш сохраненный инвентарь...
ULP_Gear = _gear;
[ULP_Gear] call ULP_fnc_loadGear;

ULP_UnlockedTextures = _textures;
ULP_Titles = _titles;
ULP_Perks = _perks;
ULP_Reputation = _reputation;
ULP_Blueprints = _blueprints;

ULP_Loaded = true; // Говорит сценарию инициализации, что мы можем продолжить...
InitGroupId = nil; // Используется только во время инициализации для "fn_setupHouses", так как в Arma кажется, что мы не добавляемся в группу вовремя...
