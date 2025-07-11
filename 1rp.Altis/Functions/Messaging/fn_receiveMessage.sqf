/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_recieveMessage";

_this params [
	["_type", configNull, [configNull]],
	["_message", "", [""]],
	["_sender", [], [[]]]
];

if (isNull _type || { _message isEqualTo "" } || { _sender isEqualTo [] } || { (count _message) > getNumber (missionConfigFile >> "CfgMessages" >> "length") }) exitWith {};

if (!([getNumber (_type >> "ignoreComms")] call ULP_fnc_bool) && { !([] call ULP_fnc_hasComms) }) exitWith {
	["Вы получили сообщение, но поскольку у вас нет связи, вы не смогли его принять..."] call ULP_fnc_hint;
};

private _messages = + (profileNamespace getVariable ["ULP_Messages", []]);
_messages pushBack [configName _type, _sender, _message, false];

private _count = count _messages;
if (_count > 25) then {
	_messages = _messages select [_count - 25, 25];
};

profileNamespace setVariable ["ULP_Messages", _messages];
saveProfileNamespace;

if ([["EnableMessageAlert", "Audio"] call ULP_fnc_getOption] call ULP_fnc_bool && { [getNumber (_type >> "alertSound")] call ULP_fnc_bool }) then {
	playSound "messageNotification";
};

if ([["EnableStreamerMode"] call ULP_fnc_getOption] call ULP_fnc_bool && { !([getNumber (_type >> "ignoreStreamer")] call ULP_fnc_bool) }) then {
	["Вы получили сообщение, и его содержание было скрыто."] call ULP_fnc_hint;
} else {
	_sender params [
		["_name", "", [""]]
	];

	[format ["Вы получили сообщение от <t color='#B92DE0'>%1</t>: %2", _name, _message]] call ULP_fnc_hint;
};

if (isText (_type >> "onRecieved")) then {
	[[_sender select 1] call ULP_fnc_playerByUID, _message] call compile getText (_type >> "onRecieved");
};

["MessageReceived", _messages] call ULP_fnc_invokeEvent;
