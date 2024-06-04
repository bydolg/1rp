/*
** Автор: Джек "Скарсо" Фархолл
** Описание: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vote";

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _pollingStation = _display getVariable ["pollingStation", objNull];
if (isNull _pollingStation) exitWith {};

private _list = _display displayCtrl 5202;

private _candidate = (_list lbData (lbCurSel _list));
if (_candidate isEqualTo "") exitWith {
	["Вы должны выбрать кандидата, за которого хотите проголосовать..."] call ULP_fnc_hint;
};

closeDialog 0;

if !(missionNamespace getVariable ["ULP_SRV_Setting_Election", false]) exitWith {
	["В настоящее время не проводятся выборы..."] call ULP_fnc_hint;
};

// Простой способ избежать спама, им придется перезагрузиться, чтобы пройти многократное голосование
if (player getVariable ["voted", false]) exitWith {
	["Вы уже проголосовали на этих выборах!"] call ULP_fnc_hint;
};

if (player getVariable ["voting", false]) exitWith {
	["Ваш голос уже обрабатывается!"] call ULP_fnc_hint;
};

player setVariable ["voting", true];

["ElectionVoteSubmitted", {
	private _message = _this param [0, "Вы успешно проголосовали на выборах..."];
	[_message] call ULP_fnc_hint;

	player setVariable ["voting", nil];

	if (_message isEqualTo "Вы успешно проголосовали на выборах...") then {
		player setVariable ["voted", true];
	};
}, true] call ULP_fnc_addEventHandler;

["Голосование..."] call ULP_fnc_hint;
[_pollingStation, player, _candidate] remoteExecCall ["ULP_SRV_fnc_submitVote", RSERV];
