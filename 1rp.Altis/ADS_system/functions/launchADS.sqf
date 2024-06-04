/*
	Area Defending System (ADS) - by Enigx
	
	launchADS.sqf

*/

StopAttacksADS = 0;
publicVariable "StopAttacksADS";

_sidefact = _this select 0;
_unitsADS = _this select 1;
_teamComp = _this select 2; _maxUnXteam = _teamComp select 0; _RandomUnit = _teamComp select 1;
_AreaMk = _this select 3; _ADS_Area = _AreaMk select 0; _ADS_Area2 = _AreaMk select 1;
_nAttacks = _this select 4;
_TimeAttack = _this select 5;

private ["_ADSPos","_EnemyFireTeamADS","_pSpawn","_nFTD"];

hint "Активирована защита области, высланы отряды!";

_ADSPos = getMarkerPos _ADS_Area2;

// ciclo "for" per lo spawn dei nemici dell'attacco
for "_i" from 1 to _nAttacks do 
{
	if (StopAttacksADS == 1) exitWith {};
	_EnemyFireTeamADS = [];
	_pSpawn = [_ADS_Area,0,_ADS_Area2] call SHK_posADS;
	if (_RandomUnit) then {	_nFTD = floor(random _maxUnXteam);} else {_nFTD = _maxUnXteam - 1;};
	for "_k" from 0 to _nFTD do {
			_EnemyFireTeamADS pushBack (selectRandom _unitsADS);
	};
	// waypoint 1
	_grDir = _ADSPos getDir _pSpawn;
	_alpha = [-45,45] call BIS_fnc_randomNum;
	_gamma = 90 - _grDir - _alpha;
	_dist = _pSpawn distance _ADSPos;
	_rand = [0.2,0.5] call BIS_fnc_randomNum;
	_a = _rand * _dist;
	_L = _a / (cos _alpha);
	_wpRand1 = [(_pSpawn select 0) - _L * cos(_gamma), (_pSpawn select 1) - _L * sin(_gamma),_pSpawn select 2];
	// waypoint 2
	_grDir = _ADSPos getDir _wpRand1;
	_alpha = [-45,45] call BIS_fnc_randomNum;
	_gamma = 90 - _grDir - _alpha;
	_dist = _wpRand1 distance _ADSPos;
	_rand = [0.2,0.5] call BIS_fnc_randomNum;
	_a = _rand * _dist;
	_L = _a / (cos _alpha);
	_wpRand2 = [(_wpRand1 select 0) - _L * cos(_gamma), (_wpRand1 select 1) - _L * sin(_gamma),_wpRand1 select 2];
	// waypoint ADS random nell'intorno di 25m dal centro area	
	_ADSPosRand = [(_ADSPos select 0) + ([-25,25] call BIS_fnc_randomNum), (_ADSPos select 1) + ([-25,25] call BIS_fnc_randomNum),_ADSPos select 2];
	
	null = [_EnemyFireTeamADS,[_pSpawn,_wpRand1,_wpRand2,_ADSPosRand],_sidefact] execVM "ADS_system\functions\Spawn_attacks_ADS.sqf";	
	if (_TimeAttack == 0) then {_TimeAttack = 1};
	sleep _TimeAttack;
};

hint "Атака окончена!";
if (StopAttacksADS == 1) then {hint "Атака отрятов прервана!";};