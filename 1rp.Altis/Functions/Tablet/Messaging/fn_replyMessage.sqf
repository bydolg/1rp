/*
** Автор: Джек "Scarso" Фархолл
** Описание: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_replyMessage";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _inbox = _display displayCtrl 23048;
private _row = lnbCurSelRow _inbox;

private _forIndex = _inbox lnbValue [_row, 0];
private _messages = + (profileNamespace getVariable ["ULP_Messages", []]);
private _message = _messages param [_forIndex, []];

if (_message isEqualTo []) exitWith {
	["Для ответа на сообщение выберите сообщение!"] call ULP_fnc_hint;
};

_message params [
	"_type", "_sender"
];

private _cfg = missionConfigFile >> "CfgMessages" >> _type;
if !(isClass _cfg) exitWith {};

if !([getNumber (_cfg >> "canReply")] call ULP_fnc_bool) exitWith {
	["На это сообщение нельзя ответить!"] call ULP_fnc_hint;
};

_sender params [ "_name", "_steamid" ];

private _unit = [_steamid] call ULP_fnc_playerByUID;
if (isNull _unit) exitWith {
	["Вы не можете ответить на это сообщение, так как отправитель больше не в сети!"] call ULP_fnc_hint;
};

private _msgCtrl = _display displayCtrl 23041;
private _message = [ctrlText _msgCtrl] call ULP_fnc_stripString;

if (_message isEqualTo "" || { (count _message) > getNumber (missionConfigFile >> "CfgMessages" >> "length") }) exitWith {
	["Введите сообщение, которое вы хотите отправить!"] call ULP_fnc_hint;
};

[missionConfigFile >> "CfgMessages" >> "Reply", _message, _unit] call ULP_fnc_sendMessage;
_msgCtrl ctrlSetText "";
