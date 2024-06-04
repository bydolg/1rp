/*
	Area Defending System (ADS) - by Enigx
	
	ADS_OpenMe.sqf
	
	The system generates a cycle of random infantry attacks on an area positioned on map from editor.
	You can specify the number of attacks and the time between each one.
	It is sufficient to define two concentric areas from editor. The enemies will be created between the two areas in such way that the internal 
	one is free from enemies and used as defending zone from attacks.
	Enemy spawning position is random. They will attack the center of the internal area, with a range of 25m, following random directional waypoints.
	You can start, stop and restart the cycle at will. You can also start two at the same time.
	
	# Compatible with SP and MP.
	
	Steps needed for the system:
	1)
	******************************************************************************************************************
	Initiate the ADS system adding the following string in init.sqf file into the mission folder (create it if file not already present)
			
			null = [] execVM "ADS_system\functions\initADS.sqf"; // <- add in init.sqf
	
	******************************************************************************************************************
		
	2) Copy folder ADS_system\ into mission folder
	3) Define from editor TWO marker areas on map, more or less concentric. The internal one will be the zone to be defended from attacks, and where enemy will not be created.
		 The external one identifies the spawning limit edge. Enemies will be randomly spawned in the space between the two areas and will converge to the centre of the internal one
		 It is not necessary to hide the area with a transparent color. The areas will be hidden automatically when the mission starts
	4) Name the two areas in editor. Ex:
		- ADSi, ADSe
		- AreaInternal, AreaExternal
		- ......				
	5) Compile this file ADS_OpenMe.sqf to generate the cycle of attacks by the following two strings:
		*) Units array ** _arrayUnitsADS **
		 	Define the infantry units classname to be used. The script chooses random units from this array
		 	Ex:
		 	_arrayUnitsADS = ["I_C_Soldier_Bandit_8_F","I_C_Soldier_Bandit_5_F","I_C_Soldier_Bandit_4_F","I_C_Soldier_Bandit_1_F"];
		 	
		*) the string with the parameters of the cycle of attacks
	
				null = [FACTION,_arrayUnitsADS,[MAX_UNITS_PER_TEAM,RANDOM_NUM],["MARKER_AREA_EXT","MARKER_AREA_INT"],NUM_ATTACKS,TIME_PER_ATTACK] execVM "ADS_system\functions\launchADS.sqf";
	
			Arguments:
			0 - FACTION: Side faction to be used (east,independent,west)
			1 - _arrayUnitsADS: leave this array element name as it is !!! DON'T CHANGE THIS NAME !
			2 - MAX_UNITS_PER_TEAM: Max number of units per fire teams - <NUMBER>
			3 - RANDOM_NUM (true o false): use random number for units with MAX_UNITS_PER_TEAM (true), or create all fire teams having MAX_UNITS_PER_TEAM of units (false) - <BOLEAN>
			4 - "MARKER_AREA_EXT": Name of the external marker area in editor - <STRING>
			5 - "MARKER_AREA_INT": Name of internal marker area in editor - <STRING>
			6 - NUM_ATTACKS: Number of attacks to be generated in the cycle - <NUMBER>
			7 - TIME_PER_ATTACK: time in second between each attack - <NUMBER>
	
	6) Compile the file ADS_HideAreas.sqf inserting the names of the two areas (see file for details).
	
	Example 1
		- Cycle of attacks to internal area called "A_int" from external one called "A_ext", both defined in editor, using: 
			-) Units with classnames in _arrayUnitsADS
			-) Faction defined as EAST
			-) Random number of units per team with maximum 5 units
			-) 5 attacks timed of 1 minute each one 
			
		null = [east,_arrayUnitsADS,[5,true],["A_ext","A_int"],5,60] execVM "ADS_system\functions\launchADS.sqf";
	
	Example 2
		- Cycle of attacks to internal area called "ADSi" from external one called "ADSe", both defined in editor, using: 
			-) Units with classnames in _arrayUnitsADS
			-) Faction defined as INDEPENDENT
			-) Fixed number on units per team of 3 units
			-) 10 attacks timed of 80 seconds each one 
			
		null = [independent,_arrayUnitsADS,[3,false],["ADSe","ADSi"],10,80] execVM "ADS_system\functions\launchADS.sqf";
		
	
	HOW TO RUN THE SYSTEM
	-- By ACE self interaction menu.
		NOTE: OF COURSE YOU NEED THE ACE MOD LOADED IN YOUR MISSION TO USE THIS METHOD
		Initiate the commands for the execution of the ADS system from ACE self interaction menu.
		
		1) create initPlayerLocal.sqf in mission folder (if not already present)
		2) Add these strings in initPlayerLocal.sqf
			
				authPlayers = ["XXXXXXXXX"];	// <-- ADD HERE THE STEAM ID OF THE PLAYER/S ENABLED TO ACTIVATE THE CYCLE OF ATTACKS BY ACE COMMANDS
				_uidP = getPlayerUID player;
				if (_uidP in authPlayers) then {
				    _actionP = {execVM "ADS_system\ADS_OpenMe.sqf";};
						_EnemyADSAttacks = ['AreaDefendingSystem', 'Activate ADS', '', _actionP, {true}] call ace_interact_menu_fnc_createAction;
						[player, 1, ["ACE_SelfActions"], _EnemyADSAttacks] call ace_interact_menu_fnc_addActionToObject;
					
						_actionStop = {execVM "ADS_system\functions\Stop_ADS.sqf";};
						_StopADSAttacks = ['StopEnemyAttacksADS', 'Stop ADS', '', _actionStop, {true}] call ace_interact_menu_fnc_createAction;
						[player, 1, ["ACE_SelfActions"], _StopADSAttacks] call ace_interact_menu_fnc_addActionToObject;
				};
	
		NOTE: For obvious reasons not all players will be enabled to activate the cycle, but only the mission master with the specified ID
		Note: you have to run mission in MP also from editor to work with the Steam ID! 
	
	-- By Triggers in editor
		 Alternatively, the cycle can be activated or stopped using triggers with the following instructions into their OnActivation field:
	
				null = execVM "ADS_system\ADS_OpenMe.sqf"; 		// TO START THE CYCLE
				null = execVM "ADS_system\functions\Stop_ADS.sqf"; 	// TO STOP THE CYCLE

	-- By debug console
		 Digit one of the two strings in previous bullet from Arma debug console when in game

*/


// ***** MODIFY BELOW BY ENTERING THE ARRAY OF THE UNITS AND THE GENERATION CALL OF THE ATTACKS ON THE ADS ZONE TO BE DEFENDED


//# Array units to be used. Enter the list of classnames of the units the script will use
_arrayUnitsADS = ["O_SoldierU_SL_F","O_soldierU_repair_F","O_soldierU_medic_F","O_sniper_F","O_Soldier_A_F","O_Soldier_AA_F","O_Soldier_AAA_F","O_Soldier_AAR_F","O_Soldier_AAT_F","O_Soldier_AR_F","O_Soldier_AT_F","O_soldier_exp_F","O_Soldier_F","O_engineer_F","O_engineer_U_F","O_medic_F"];


//# Attack generation call. Edit with desired variables (NOTE: EXCEPT FOR THE _arrayUnitsADS ELEMENT, WHICH MUST BE KEPT AS IS)
null = [west,_arrayUnitsADS,[3,true],["MkAreaSpawn","MkAreaSafe"],5,10] execVM "ADS_system\functions\launchADS.sqf";


// ********** END

