/*
	@file_name: fn_handleGasmasks.sqf
	@file_author: Dyzalonius
*/

////////////////////////////////////////////////
//               SUB-FUNCTIONS                //
////////////////////////////////////////////////

fn_gasMaskEH = {
	while {!isNull player} do {
		_gasmasks = missionNameSpace getVariable "radiationGasmasks";
		_hasGasmask = missionNameSpace getVariable "hasGasmask";
		_hasGasmaskNew = false;
		{
			if (_x call fn_hasItemM) then {
				_hasGasmaskNew = true;
			};
		} foreach _gasmasks;

		if (!(_hasGasmask isEqualTo _hasGasmaskNew)) then {
			missionNameSpace setVariable ["hasGasmask", _hasGasmaskNew, false];
			if (_hasGasmaskNew) then {
				// Put on gasmask
				playsound "echipare";
				onEachFrame {overlayeffects = 0 spawn { 0 cutRsc ["equipment_prot","PLAIN", 1, missionNameSpace getVariable "radiationShowGasmaskOnMap"];};};
				sleep 2.6;
				[] spawn {
					_hasGasmask = missionNameSpace getVariable "hasGasmask";
					while {_hasGasmask} do {
						_int_b = linearConversion [0, 1,(getFatigue player), 8, 1.8, true];
						playsound "breath";
						sleep _int_b;
						_hasGasmask = missionNameSpace getVariable "hasGasmask";
					};
				};
			} else {
				// Take off gasmask
				onEachFrame {0 cutText ["","PLAIN"];};
				playsound "dezechipare";
				terminate overlayeffects;
			};
		};
		sleep 0.5;
	};
};

fn_hasItemM = {
    // return if gasmask is in inventory of player
    (
        (_this == goggles player)
    );
};

////////////////////////////////////////////////
//               FUNCTION LOOP                //
////////////////////////////////////////////////

missionNameSpace setVariable ["hasGasmask", false, false];
[] spawn fn_gasMaskEH;