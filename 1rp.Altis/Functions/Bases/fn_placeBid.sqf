/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_placeBid";

_this params [
	["_base", "", [""]]
];

if (!([player, ["Civilian"]] call ULP_fnc_isFaction) || { [] call ULP_fnc_isUndercover }) exitWith {
	["Только гражданские могут делать ставки на базы..."] call ULP_fnc_hint;
};

if !([] call ULP_fnc_isGroup) exitWith {
	["Вы должны быть в группе, чтобы сделать ставку на групповую базу..."] call ULP_fnc_hint;
};

private _obj = missionNamespace getVariable [format ["ULP_SRV_Base_%1", _base], objNull];
if (isNull _obj) exitWith {
	["Произошла ошибка при попытке сделать ставку..."] call ULP_fnc_hint;
};

private _bid = (_obj getVariable ["current_bid", getNumber (missionConfigFile >> "CfgBases" >> "StartingBid")]) + getNumber (missionConfigFile >> "CfgBases" >> "BidIncrement");

if (_bid > ([] call ULP_fnc_groupFunds)) exitWith {
	[format ["Следующая ставка составляет <t color='#B92DE0'>%1%2</t>, у вашей группы нет средств на это...", "$", [_bid] call ULP_fnc_numberText]] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Подтверждение", ["Подтвердить", "Отмена"],
	format ["Вы уверены, что хотите сделать ставку <t color='#B92DE0'>%1%2</t>...", "$", [_bid] call ULP_fnc_numberText], [_bid, _base],
	{	
		_this params [ "_bid", "_base" ];
		
		if (player getVariable ["bidding", false]) exitWith {
			["Вы уже делаете ставку!"] call ULP_fnc_hint;
		};

		player setVariable ["bidding", true];

		["BaseBid", {
			[_this param [0, "Вы успешно сделали ставку на эту базу..."]] call ULP_fnc_hint;
			player setVariable ["bidding", nil];
		}, true] call ULP_fnc_addEventHandler;

		["Совершение ставки..."] call ULP_fnc_hint;
		[player, _bid, _base] remoteExecCall ["ULP_SRV_fnc_addBaseBid", RSERV];
	}, {}, false
] call ULP_fnc_confirm;
