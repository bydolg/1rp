/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_surveySite";

_this params [
	["_rarity", "", [""]]
];

private _cfg = missionConfigFile >> "CfgArchaeology" >> _rarity;
if (!(isClass _cfg) || { ULP_Archaeology_Digging }) exitWith { false };

private _type = format ["Archaeology%1", _rarity];

if !(_type in ULP_Missions) exitWith {
	["Для начала исследования необходимо заявить права на археологический участок."] call ULP_fnc_hint;
};

(ULP_Missions get _type) params [
	"_task"
];

if ((player distance (taskDestination _task)) > 5) exitWith {
	["Для начала исследования вам нужно находиться внутри вашего назначенного археологического участка."] call ULP_fnc_hint;
};

(getArray (_cfg >> "surveyTime")) params [ "_base", "_random" ];

private _time = ["RapidSurveyor", round (_base + (random _random))] call ULP_fnc_activatePerk;

if ([] call ULP_fnc_isGroup) then {
	private _buff = [group player, "Surveying"] call ULP_fnc_groupBuff;
	if (_buff > 0) then { _time = _time - (_time * _buff); };
};

private _profCal = ["Archeology"] call ULP_fnc_getProfessionCalculation;
if (_profCal > 0) then { _time = _time - (_time * (_profCal / 100)); };

[format["Исследование археологического участка %1", _rarity], _time, [_cfg, _task], { (player distance (taskDestination (_this select 1))) <= 5 }, {
	_this params [ "_cfg", "_task" ];
	
	ULP_SurveyTotal = ULP_SurveyTotal + 1;

	private _pos = [(taskDestination _task), 0, 50] call BIS_fnc_findSafePos;
	if (_pos isEqualTo []) then { _pos = taskDestination _task; };

	if (ULP_SurveyTotal >= getNumber (_cfg >> "surveyTimes")) then {
		_task setSimpleTaskDescription [
			"Вы нашли хорошее место для раскопок, теперь вам нужно использовать своё археологическое оборудование, чтобы увидеть, что вы там найдете.", "Начать раскопки на археологическом участке", ""
		];

		[format ["Вы провели исследование <t color='#B92DE0'>%1 археологического участка</t> и нашли <t color='#B92DE0'>место раскопок</t>.", configName _cfg]] call ULP_fnc_hint;
		ULP_Archaeology_Digging = true;
	} else {
		[format ["Вы провели исследование <t color='#B92DE0'>%1 археологического участка</t> и нашли лучшую область для поисков...", configName _cfg]] call ULP_fnc_hint;
	};

	["Archeology", 1, 50] call ULP_fnc_increaseProfession;
	
	_task setSimpleTaskDestination _pos;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;

closeDialog 0;
