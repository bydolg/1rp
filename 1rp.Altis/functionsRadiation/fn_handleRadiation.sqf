/*
	@file_name: fn_handleRadiation.sqf
	@file_author: Dyzalonius
*/

////////////////////////////////////////////////
//               SUB-FUNCTIONS                //
////////////////////////////////////////////////

fn_handleDamageEffects = {
    [] spawn {
        _blur = ppEffectCreate ["DynamicBlur", 401];
        _blur ppEffectEnable true;
        _blur ppEffectAdjust [1];
        _blur ppEffectCommit 1;
        uiSleep 2;
        _blur ppEffectAdjust [0];
        _blur ppEffectCommit 1;
        uiSleep 2;
        ppEffectDestroy _blur;
    };

    addCamShake [linearConversion [0.1, 1, _this, 0.1, 1, true], 3, 17];
    enableCamShake true;

    _randomSound = selectRandom ["NoSound","NoSound","NoSound","cough","NoSound","NoSound","NoSound","NoSound","tuse_5","NoSound","NoSound","NoSound","NoSound","tuse_6","NoSound","NoSound","NoSound","NoSound"];
    playsound _randomSound;
    playsound "puls_1";
    
    sleep linearConversion [0, 1, _this, 2, 0.1, true];
};

fn_handleDetection = {
    _detector = missionNameSpace getVariable "radiationDetector";
    if (_this > 0 && _detector call fn_hasItem) then {
        playsound "geiger";
    };
};

fn_handleRadiation = {
    // Check if deltaRadiation is below 0
    if (_this < 0) then {
        _damagePerTick = missionNameSpace getVariable "radiationDamage";

        if (missionNameSpace getVariable "radiationAceDamage") then {
            _bodypartIndex = floor (random 6);
            _bodypart = ["head", "body", "hand_l", "hand_r", "leg_r", "leg_l"] select _bodypartIndex;
            _bodypartDamage = (player getvariable "ace_medical_bodyPartStatus") select _bodypartIndex;
            [player, (_bodypartDamage + _damagePerTick/10), _bodypart, "unknown"] call ace_medical_fnc_addDamageToUnit;
        } else {                                      
        
            player setDamage ((damage player) - _this * _damagePerTick);
        };

        (damage player) spawn fn_handleDamageEffects;
    };
};

fn_hasItem = {
    // return if protective gear is in inventory of player
    (
        (_this == headgear player) ||
        (_this == goggles player) ||
        (_this == uniform player) ||
        (_this == vest player) ||
        (_this == Backpack player) ||
        (_this in (assigneditems player + items player))
    );
};

fn_getRadiationProtection = {
    _radiationProtection = 0;
    _protectiveGear = missionNameSpace getVariable "protectiveGear";

    // If player has protective gear, give protection value
    {
        if ((_x select 0) call fn_hasItem) then {
            _radiationProtection = _radiationProtection + (_x select 1);
        };
    } foreach _protectiveGear;

    _radiationProtection;
};

fn_getRadiationStrength = {
    _radiationStrength = 0;
    _radiationAreas = missionNameSpace getVariable "radiationZones";
    {
        if (((_this) distance (_x select 0)) < (_x select 1) && _radiationStrength < (_x select 2)) then {
_radiationStrength = ((_x select 1) - ((_this) distance (_x select 0)))/(_x select 1)*(_x select 2);
        };
    } foreach _radiationAreas;
    _radiationStrength;
};

////////////////////////////////////////////////
//               FUNCTION LOOP                //
////////////////////////////////////////////////

waitUntil {missionNameSpace getVariable ["radiationInitialized", false]};

while {true} do {
    _radiationStrength = (position player) call fn_getRadiationStrength;
    
    _radiationProtection = [] call fn_getRadiationProtection;
    
    (_radiationProtection - _radiationStrength) call fn_handleRadiation;
    _radiationStrength spawn fn_handleDetection;

    sleep (1.2 + random 1);
};