class CfgPlaceables {
	maxPlaceables = 20;

	class Objects {
		class SpikeStrip {
			displayName = "Звездный шип";
			className = "Land_Razorwire_F";
			positioning[] = { { 0, 5.5, 0 }, 90 };
			placementTime = 2;
			onPlaced = "(_this select 0) setDamage 1; _this remoteExecCall [""ULP_SRV_fnc_registerStinger"", 2];";
		};

		class RoadCone {
			displayName = "Дорожный конус";
			className = "RoadCone_F";
			positioning[] = { { 0, 3, 0.5 }, 0 };
			placementTime = 2;
			onPlaced = "";
		};

		class RoadConeWithLight : RoadCone {
			displayName = "Дорожный конус с фонарем";
			className = "RoadCone_L_F";
		};

		class SinglePortableLight : RoadCone {
			displayName = "Переносной фонарь (одиночный)";
			className = "Land_PortableLight_single_F";
		};

		class DoublePortableLight : RoadCone {
			displayName = "Переносной фонарь (двойной)";
			className = "Land_PortableLight_double_F";
		};

		class TapeSign : RoadCone {
			displayName = "Красно-белая лента";
			className = "TapeSign_F";
		};
	};
};
