class CfgNotificationStyles {
    class Info {
        color[] = {0.1, 0.1, 0.1, 0.8};
        icon = "\a3\ui_f\data\igui\cfg\simpleTasks\types\default_ca.paa";
    };
    class Warn : Info {
        color[] = {1, 0.5, 0, 0.8};
        icon = "\a3\ui_f\data\igui\cfg\simpleTasks\types\warning_ca.paa";
    };
    class Error : Info {
        color[] = {1, 0, 0, 0.8};
        icon = "\a3\ui_f\data\igui\cfg\simpleTasks\types\danger_ca.paa";
    };
};
