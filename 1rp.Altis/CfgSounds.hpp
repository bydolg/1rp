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
};