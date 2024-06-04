class CfgCapture {
	class Altis {
		class WestHideout {
			displayName = "Западное убежище преступников";
			time = 180;
			condition = "[""Hideout""] call ULP_fnc_hasGroupPerk";
		};
		class EastHideout : WestHideout { displayName = "Восточное убежище преступников"; };
	};
};
