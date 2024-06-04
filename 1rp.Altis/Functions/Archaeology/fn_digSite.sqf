/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_digSite";

_this params [
	["_rarity", "", [""]]
];

private _cfg = missionConfigFile >> "CfgArchaeology" >> _rarity;
if (!(isClass _cfg) || { !ULP_Archaeology_Digging }) exitWith { false };

private _type = format ["Archaeology%1", _rarity];

if !(_type in ULP_Missions) exitWith {
	["У вас в настоящее время нет назначенного археологического объекта..."] call ULP_fnc_hint;
};

(ULP_Missions get _type) params [
	"_task"
];

if ((player distance (taskDestination _task)) > 5) exitWith {
	["Вам нужно подойти ближе к месту раскопок."] call ULP_fnc_hint;
};

(getArray (_cfg >> "surveyTime")) params [ "_base", "_random" ];

private _time = ["RapidSurveyor", round (_base + (random _random))] call ULP_fnc_activatePerk;

if ([] call ULP_fnc_isGroup) then {
	private _buff = [group player, "Digging"] call ULP_fnc_groupBuff;
	if (_buff > 0) then { _time = _time - (_time * _buff); };
};

private _profCal = ["Archeology"] call ULP_fnc_getProfessionCalculation;
if (_profCal > 0) then { _time = _time - (_time * (_profCal / 100)); };

[format["Раскопки %1 археологического объекта", _rarity], _time, [_cfg, _task], { (player distance (taskDestination (_this select 1))) <= 5 }, {
	_this params [ "_cfg", "_task" ];

	private _amounts = getArray (_cfg >> "give");
	private _rewards = getArray (_cfg >> "rewards");
	private _given = createHashMap;
	_rewards sort false;
	
	for "_i" from 0 to ((_amounts select 0) max (round (random (_amounts select 1)))) do {
		private _chance = random 1;
		private _reward = _rewards param [_rewards findIf { (_x select 0) <= _chance }, []];

		if !(_reward isEqualTo []) then {
			_reward params [ "", "_item" ];
			_item params [ "_class", "_max" ];

			private _amount = (1 max (round (random _max)));

			if (_class in _given) then {
				_given set [_class, (_given get _class) + _amount];
			} else {
				_given set [_class, _amount];
			};
		};
	};

	{ [_x, _y, false, true] call ULP_fnc_handleItem; } forEach _given;
	[format["Archaeology%1", configName _cfg]] call ULP_fnc_finishMission;
	[format ["Вы закончили раскопки и нашли <t color='#B92DE0'>%1</t>", _given]] call ULP_fnc_hint;

	["Archeology", 1, 50] call ULP_fnc_increaseProfession;

	["Archaeologist"] call ULP_fnc_achieve;

	ULP_Archaeology = nil;
	ULP_Archaeology_Digging = false;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;

closeDialog 0;