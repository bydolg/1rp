class CfgSpawns {
    class BaseSpawn {
        factions[] = { "Civilian" };
        buildings[] = {};
        radius = 100;
        conditions = "true";
    };
    class Police : BaseSpawn { factions[] = { "Police" }; };
    class HATO : BaseSpawn { factions[] = { "Hato" }; };
    class Medic : BaseSpawn { factions[] = { "Medic" }; };
    class Civilian : BaseSpawn {
        buildings[] = {
            "Land_i_Shop_01_V1_F",
            "Land_i_Shop_02_V1_F",
            "Land_i_Shop_03_V1_F",
            "Land_i_Stone_HouseBig_V1_F",
            "Land_Chapel_V1_F",
            "Land_Chapel_V2_F",
            "Land_u_House_Big_02_V1_F",
            "Land_u_House_Big_01_V1_F",
            "Land_d_Stone_HouseBig_V1_F",
            "Land_d_Stone_HouseSmall_V1_F",
            "Land_d_House_Big_01_V1_F",
            "Land_Hotel_02_F"
        };
    };

    class Altis {
        // Altis Police Service
        class KavalaStation : Police {
            displayName = $STR_SPAWN_KAVALA_HQ;
            marker = "apc_spawn_kavala";
            icon = "\dataM\UI\Spawns\kavala.paa";
        };
        class KavalaStationNCA : Civilian {
            displayName = $STR_SPAWN_NCA_FRONTLINE;
            marker = "apc_spawn_nca";
            icon = "\dataM\UI\Spawns\kavala.paa";
            radius = 1;
            conditions = "[] call ULP_fnc_isUndercover";
        };
        class AthiraStation : Police {
            displayName = $STR_SPAWN_ATHIRA_POST;
            marker = "apc_spawn_athira";
            icon = "\dataM\UI\Spawns\athira.paa";
        };
        class PyrgosStation : Police {
            displayName = $STR_SPAWN_PYRGOS_POST;
            marker = "apc_spawn_pyrgos";
            icon = "\dataM\UI\Spawns\pyrgos.paa";
        };
        class AgiosStation : Police {
            displayName = $STR_SPAWN_AGIOS_POST;
            marker = "apc_spawn_agios";
            icon = "\dataM\UI\Spawns\agios.paa";
        };
        class UndercoverHeadquarters : BaseSpawn {
            displayName = $STR_SPAWN_UNDERCOVER_HQ;
            marker = "apc_spawn_uc";
            icon = "\dataM\UI\Spawns\neochori.paa";
            radius = 1;
            conditions = "[] call ULP_fnc_isUndercover";
        };

        // Altis Ambulance Service
        class KavalaHospital : Medic {
            displayName = $STR_SPAWN_KAVALA_HOSPITAL;
            marker = "nhs_spawn_kavala";
            icon = "\dataM\UI\Spawns\kavala.paa";
        };
        class AthiraClinic : Medic {
            displayName = $STR_SPAWN_ATHIRA_CLINIC;
            marker = "nhs_spawn_athira";
            icon = "\dataM\UI\Spawns\athira.paa";
        };
        class PyrgosClinic : Medic {
            displayName = $STR_SPAWN_PYRGOS_CLINIC;
            marker = "nhs_spawn_pyrgos";
            icon = "\dataM\UI\Spawns\pyrgos.paa";
        };
        class AirAmbulance : Medic {
            displayName = $STR_SPAWN_AIR_AMBULANCE;
            marker = "nhs_spawn_aa";
            icon = "\dataM\UI\Spawns\idap.paa";
            conditions = "[""Medic_AA"", 1] call ULP_fnc_hasAccess";
        };

        // Altis Police Service / Altis Ambulance Service
        class MarineStation : Police {
            displayName = $STR_SPAWN_MARINE_BASE;
            factions[] = { "Police", "Medic" };
            marker = "joint_spawn_marine";
            icon = "\dataM\UI\Spawns\marine.paa";
        };

        // HATO
        class HatoKavala : HATO {
            displayName = $STR_SPAWN_HATO_KAVALA;
            marker = "hato_spawn_kavala";
            icon = "\dataM\UI\Spawns\kavala.paa";
        };
        class HatoAgios : HATO {
            displayName = $STR_SPAWN_HATO_AGIOS;
            marker = "hato_spawn_agios";
            icon = "\dataM\UI\Spawns\agios.paa";
        };

        // Government
        class GovernorResidence : BaseSpawn {
            displayName = $STR_SPAWN_GOV_RESIDENCE;
            marker = "civ_spawn_residence";
            icon = "\dataM\UI\Spawns\government.paa";
            conditions = "[] call ULP_fnc_isGovernor || { [] call ULP_fnc_isProtection }";
        };
        class GovernmentOffices : GovernorResidence {
            displayName = $STR_SPAWN_GOV_OFFICES;
            marker = "civ_spawn_government";
        };
        class KavalaSafehouse : GovernorResidence {
            displayName = $STR_SPAWN_KAVALA_SAFEHOUSE;
            marker = "civ_spawn_kavSafehouse";
            conditions = "[] call ULP_fnc_isGovernor || { [] call ULP_fnc_isProtection && { [""GovernmentSafehouses""] call ULP_fnc_hasGroupPerk } }";
        };
        class PyrgosSafehouse : KavalaSafehouse {
            displayName = $STR_SPAWN_PYRGOS_SAFEHOUSE;
            marker = "civ_spawn_pyrSafehouse";
        };
        
        // Civilian
        class Kavala : Civilian {
            displayName = $STR_SPAWN_CIV_KAVALA;
            marker = "civ_spawn_kavala";
            icon = "\dataM\UI\Spawns\kavala.paa";
        };
        class Athira : Civilian {
            displayName = $STR_SPAWN_CIV_ATHIRA;
            marker = "civ_spawn_athira";
            icon = "\dataM\UI\Spawns\athira.paa";
        };
        class Pyrgos : Civilian {
            displayName = $STR_SPAWN_CIV_PYRGOS;
            marker = "civ_spawn_pyrgos";
            icon = "\dataM\UI\Spawns\pyrgos.paa";
        };
        class Sofia : Civilian {
            displayName = $STR_SPAWN_CIV_SOFIA;
            marker = "civ_spawn_sofia";
            icon = "\dataM\UI\Spawns\sofia.paa";
            conditions = "[""WideTraveller""] call ULP_fnc_hasPerk";
        };
        class Agios : Civilian {
            displayName = $STR_SPAWN_CIV_AGIOS;
            marker = "civ_spawn_agios";
            icon = "\dataM\UI\Spawns\agios.paa";
            conditions = "[""WideTraveller""] call ULP_fnc_hasPerk";
        };
        class Neochori : Civilian {
            displayName = $STR_SPAWN_CIV_NEOCHORI;
            marker = "civ_spawn_neochori";
            icon = "\dataM\UI\Spawns\neochori.paa";
            conditions = "[""WideTraveller""] call ULP_fnc_hasPerk";
        };

        class Taxi : BaseSpawn {
            displayName = $STR_SPAWN_TAXI;
            marker = "civ_spawn_taxi";
            icon = "\dataM\UI\Spawns\taxi.paa";
            conditions = "[""Taxi""] call ULP_fnc_hasLicense";
        };
        class Solicitor : BaseSpawn {
            displayName = $STR_SPAWN_SOLICITOR;
            marker = "civ_spawn_solicitor";
            icon = "\dataM\UI\Spawns\solicitor.paa";
            conditions = "[""Solicitor""] call ULP_fnc_hasLicense";
        };
        class News : BaseSpawn {
            displayName = $STR_SPAWN_NEWS;
            marker = "civ_spawn_news";
            icon = "\dataM\UI\Spawns\news.paa";
            conditions = "[""News""] call ULP_fnc_hasLicense";
        };
        class Rebel : BaseSpawn {
            displayName = $STR_SPAWN_REBEL_OUTPOST;
            marker = "civ_spawn_rebel";
            icon = "\dataM\UI\Spawns\rebel.paa";
            conditions = "[""Rebel""] call ULP_fnc_hasLicense && { missionNamespace getVariable [""ULP_SRV_Setting_BaseBidsActive"", false] }";
        };
    };

    class Malden {
        class LaTriniteConstabulary : Police {
            displayName = $STR_SPAWN_LA_TRINITE_CONSTAB;
            marker = "cop_spawn_1";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };

        class test : Police {
            displayName = $STR_SPAWN_LA_TRINITE_OTHER;
            marker = "cop_spawn_2";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };

        class LaTriniteHospital : Medic {
            displayName = $STR_SPAWN_LA_TRINITE_HOSPITAL;
            marker = "medic_spawn";
            icon = "\a3\ui_f\data\map\VehicleIcons\pictureLogic_ca.paa";
        };

        class LaTrinite : BaseSpawn {
            displayName = $STR_SPAWN_LA_TRINITE;
            marker = "civ_spawn_1";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };
    };
};
