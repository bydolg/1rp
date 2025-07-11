/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_revived";

if (canSuspend) exitWith {
    [ULP_fnc_revived, _this] call ULP_fnc_directCall;
};

if !(_this params [
	["_medic", objNull, [objNull]]
]) exitWith {};

if ([_medic] call ULP_fnc_onDuty) then {
	["Вас оживил администратор..."] call ULP_fnc_hint;
} else {
	[format ["Вас оживил <t color='#B92DE0'>%1</t>", [_medic, true] call ULP_fnc_getName]] call ULP_fnc_hint;
};

if !(player isEqualTo _medic) then {
        ["Revived", [name player, [[_medic, true] call ULP_fnc_getName, "администратор"] select ([_medic] call ULP_fnc_onDuty)]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];

	// У нас высокая репутация, поэтому человек, который вас оживил, получит репутацию в ответ
	if (ULP_Reputation >= 500) then {
		[_medic, "ReviveHighRep"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];
	};
};

player setVariable ["IncapacitatedWounds", nil, true];

player setUnconscious false;
unsetKiller(player);
unsetDowned(player);

player playMoveNow "amovppnemstpsraswrfldnon";

["RscIncapacitated"] call ULP_UI_fnc_destroyLayer;
uiNamespace setVariable ["IncapacitatedEffect", nil];
[] call ULP_fnc_wipeEffects;

if (["EnableHUD", "HUD"] call ULP_fnc_getOption isEqualTo 1) then {
	[] call ULP_UI_fnc_openHUD;
};

ULP_Respawned = false;
ULP_CanRespawn = nil;

ULP_LastRevived = time;

[] call ULP_fnc_syncPlayerInfo;
