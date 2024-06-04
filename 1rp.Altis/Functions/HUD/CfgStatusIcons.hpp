class CfgStatusIcons {
	class Base {
		factions[] = { "Civilian", "Police", "Medic", "Hato" };
		condition = "true";
	};

	class Seatbelt : Base {
		icon = "\dataM\UI\seatbelt.paa";
		condition = "!isNull (objectParent player) && { !(player getVariable[""seatBelt"", false]) } && { (vehicle player) isKindOf ""LandVehicle"" }";
	};

	class Overweight : Base {
		icon = "\dataM\UI\overweight.paa";
		condition = "isForcedWalk player";
	};


  class earplug : Base {
		icon = "\dataM\UI\earplug.paa";
		condition = "missionNamespace getVariable [""ULP_FadeSound"", false]";
	};

	
  class InRedzone : Base {
		icon = "\dataM\UI\redzone.paa";
		condition = "missionNamespace getVariable [""InRedzone"", false]";
	};
	       
  class InSafezoneIcon : Base {
		icon = "\dataM\UI\safezone.paa";
		condition = "missionNamespace getVariable [""InSafezone"", false]";
	};

	class RevivedRecently : Base {
		icon = "\dataM\UI\reviveCooldown.paa";
		condition = "missionNamespace getVariable [""ULP_LastRevived"", -300] > (time - 300)";
	};
  
	class NoCommunications : Base {
		icon = "\dataM\UI\noCommunications.paa";
		condition = "!([player] call ULP_fnc_hasComms)";
	};
};