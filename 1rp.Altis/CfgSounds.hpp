class CfgSounds {
    sounds[] = {};
	
    class britishSiren {
        name = "britishSiren";
        sound[] = {"\DataM\Sounds\britishSiren.ogg", 1.0, 1};
        titles[] = {};
    };

    class Siren1 {
        name = "siren1";
        sound[] = {"\DataM\Sounds\Sirens\siren_1.ogg", 1.0, 1};
        titles[] = {};
    };

    class Siren2 : Siren1 {
        name = "siren1";
        sound[] = {"\DataM\Sounds\Sirens\siren_2.ogg", 1.0, 1};
    };

    class Siren3 : Siren1 {
        name = "siren1";
        sound[] = {"\DataM\Sounds\Sirens\siren_3.ogg", 1.0, 1};
    };

    class Siren4 : Siren1 {
        name = "siren1";
        sound[] = {"\DataM\Sounds\Sirens\siren_4.ogg", 1.0, 1};
    };

    class taserSound {
        name = "taserSound";
        sound[] = {"\DataM\Sounds\taser.ogg", 0.5, 1};
        titles[] = {};
    };

    class lockCarSound {
        name = "lockCarSound";
        sound[] = {"\DataM\Sounds\carLock.ogg", 1.0, 1};
        titles[] = {};
    };

    class unlockCarSound {
        name = "unlockCarSound";
        sound[] = {"\DataM\Sounds\carUnlock.ogg", 0.75, 1};
        titles[] = {};
    };

    class metalDetector {
        name = "metalDetector";
        sound[] = {"\DataM\Sounds\metalDetector.ogg", 0.75, 1}; 
        titles[] = {};
    };

    class panicButton {
        name = "panicButton";
        sound[] = {"\DataM\Sounds\panicButton.ogg", 1.0, 1};
        titles[] = {};
    };

    class messageNotification {
        name = "messageNotification";
        sound[] = {"\DataM\Sounds\messageNotification.ogg", 1.0, 1};
        titles[] = {};
    };
    	class geiger {
		name = "geiger"; // Name for mission editor
		sound[] = {\sounds\geiger.ogg, .7, 1.0};
		titles[] = {0, ""};
	};
	class breath {
		name = "breath";
		sound[] = {"\sounds\breath.ogg", 0.6, 1.0};
		titles[] = {0,""};
	};
	class cough {
		name = "cough";
		sound[] = {"\sounds\cough.ogg", db+1, 1.0};
		titles[] = {0,""};
	};
	class echipare {
		name = "echipare";
		sound[] = {"\sounds\echipare.ogg", 1, 1.0};
		titles[] = {0,""};
	};	
	class dezechipare {
		name = "dezechipare";
		sound[] = {"\sounds\dezechipare.ogg", 1, 1.0};
		titles[] = {0,""};
	};	
	class puls_1 {
		name = "puls_1";
		sound[] = {"\sounds\puls_1.ogg", db+1, 1};
		titles[] = {1, ""};
	};	
	class NoSound {
		name = "NoSound";
		sound[] = {"", 0, 1};
		titles[] = {0, ""};
	};
	class tuse_5 {
		name = "tuse_5";
		sound[] = {"\sounds\tuse_5.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class tuse_6 {
		name = "tuse_6";
		sound[] = {"\sounds\tuse_6.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class sandstorm {
		name = "sandstorm";
		sound[] = {"\sounds\sandstorm.ogg", 0.2, 1};
		titles[] = {1, ""};
	};
	class ambient_com {
		name = "ambient_com";
		sound[] = {"\sounds\ambient_com.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class ambient_fantoma {
		name = "ambient_fantoma";
		sound[] = {"\sounds\ambient_fantoma.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class ambient_fundal {
		name = "ambient_fundal";
		sound[] = {"\sounds\ambient_fundal.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class ambient_hall {
		name = "ambient_hall";
		sound[] = {"\sounds\ambient_hall.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class ambient_industrial {
		name = "ambient_industrial";
		sound[] = {"\sounds\ambient_industrial.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class ambient_jet {
		name = "ambient_jet";
		sound[] = {"\sounds\ambient_jet.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class ambient_spike {
		name = "ambient_spike";
		sound[] = {"\sounds\ambient_spike.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class ambient_steps {
		name = "ambient_steps";
		sound[] = {"\sounds\ambient_steps.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class ambient_tehnic {
		name = "ambient_tehnic";
		sound[] = {"\sounds\ambient_tehnic.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class ambient_vuumm {
		name = "ambient_vuumm";
		sound[] = {"\sounds\ambient_vuumm.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class ambient_wind {
		name = "ambient_wind";
		sound[] = {"\sounds\ambient_wind.ogg", 1, 1};
		titles[] = {1, ""};
	}; 
};