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
            "Land_d_House_Big_01_V1_F"
        };
    };

    class Altis {
        // Altis Police Service
        class KavalaStation : Police {
            displayName = "Штаб-квартира Кавалы";
            marker = "apc_spawn_kavala";
            icon = "\dataM\UI\Spawns\kavala.paa";
        };
        class KavalaStationNCA : Civilian {
            displayName = "Штаб-квартира НСА на передовой";
            marker = "apc_spawn_nca";
            icon = "\dataM\UI\Spawns\kavala.paa";
            radius = 1;
            conditions = "[] call ULP_fnc_isUndercover";
        };
        class AthiraStation : Police {
            displayName = "Пост Афиры";
            marker = "apc_spawn_athira";
            icon = "\dataM\UI\Spawns\athira.paa";
        };
        class PyrgosStation : Police {
            displayName = "Пост Пироса";
            marker = "apc_spawn_pyrgos";
            icon = "\dataM\UI\Spawns\pyrgos.paa";
        };
        class AgiosStation : Police {
            displayName = "Пост Агиоса";
            marker = "apc_spawn_agios";
            icon = "\dataM\UI\Spawns\agios.paa";
        };
        class UndercoverHeadquarters : BaseSpawn {
            displayName = "Скрытая штаб-квартира НСА";
            marker = "apc_spawn_uc";
            icon = "\dataM\UI\Spawns\neochori.paa";
            radius = 1;
            conditions = "[] call ULP_fnc_isUndercover";
        };

        // Altis Ambulance Service
        class KavalaHospital : Medic {
            displayName = "Госпиталь Кавалы";
            marker = "nhs_spawn_kavala";
            icon = "\dataM\UI\Spawns\kavala.paa";
        };
        class AthiraClinic : Medic {
            displayName = "Клиника Афиры";
            marker = "nhs_spawn_athira";
            icon = "\dataM\UI\Spawns\athira.paa";
        };
        class PyrgosClinic : Medic {
            displayName = "Клиника Пироса";
            marker = "nhs_spawn_pyrgos";
            icon = "\dataM\UI\Spawns\pyrgos.paa";
        };
        class AirAmbulance : Medic {
            displayName = "Станция Воздушной скорой помощи";
            marker = "nhs_spawn_aa";
            icon = "\dataM\UI\Spawns\idap.paa";
            conditions = "[""Medic_AA"", 1] call ULP_fnc_hasAccess";
        };

        // Altis Police Service / Altis Ambulance Service
        class MarineStation : Police {
            displayName = "Морская база";
            factions[] = { "Police", "Medic" };
            marker = "joint_spawn_marine";
            icon = "\dataM\UI\Spawns\marine.paa";
        };

        // HATO
        class HatoKavala : HATO {
            displayName = "Объект Кавалы";
            marker = "hato_spawn_kavala";
            icon = "\dataM\UI\Spawns\kavala.paa";
        };
        class HatoAgios : HATO {
            displayName = "Объект Агиоса";
            marker = "hato_spawn_agios";
            icon = "\dataM\UI\Spawns\agios.paa";
        };

        // Government
        class GovernorResidence : BaseSpawn {
            displayName = "10 улица Кавалы";
            marker = "civ_spawn_residence";
            icon = "\dataM\UI\Spawns\government.paa";
            conditions = "[] call ULP_fnc_isGovernor || { [] call ULP_fnc_isProtection }";
        };
        class GovernmentOffices : GovernorResidence {
            displayName = "Правительственные офисы";
            marker = "civ_spawn_government";
        };
        class KavalaSafehouse : GovernorResidence {
            displayName = "Тайник Кавалы";
            marker = "civ_spawn_kavSafehouse";
            conditions = "[] call ULP_fnc_isGovernor || { [] call ULP_fnc_isProtection && { [""GovernmentSafehouses""] call ULP_fnc_hasGroupPerk } }";
        };
        class PyrgosSafehouse : KavalaSafehouse {
            displayName = "Тайник Пироса";
            marker = "civ_spawn_pyrSafehouse";
        };
        
        // Civilian
        class Kavala : Civilian {
            displayName = "Кавала";
            marker = "civ_spawn_kavala";
            icon = "\dataM\UI\Spawns\kavala.paa";
        };
        class Athira : Civilian {
            displayName = "Афира";
            marker = "civ_spawn_athira";
            icon = "\dataM\UI\Spawns\athira.paa";
        };
        class Pyrgos : Civilian {
            displayName = "Пирогос";
            marker = "civ_spawn_pyrgos";
            icon = "\dataM\UI\Spawns\pyrgos.paa";
        };
        class Sofia : Civilian {
            displayName = "София";
            marker = "civ_spawn_sofia";
            icon = "\dataM\UI\Spawns\sofia.paa";
            conditions = "[""WideTraveller""] call ULP_fnc_hasPerk";
        };
        class Agios : Civilian {
            displayName = "Агиос";
            marker = "civ_spawn_agios";
            icon = "\dataM\UI\Spawns\agios.paa";
            conditions = "[""WideTraveller""] call ULP_fnc_hasPerk";
        };
        class Neochori : Civilian {
            displayName = "Неохори";
            marker = "civ_spawn_neochori";
            icon = "\dataM\UI\Spawns\neochori.paa";
            conditions = "[""WideTraveller""] call ULP_fnc_hasPerk";
        };

        class Taxi : BaseSpawn {
            displayName = "Такси на Алтисе";
            marker = "civ_spawn_taxi";
            icon = "\dataM\UI\Spawns\taxi.paa";
            conditions = "[""Taxi""] call ULP_fnc_hasLicense";
        };
        class Solicitor : BaseSpawn {
            displayName = "Адвокаты Алтиса";
            marker = "civ_spawn_solicitor";
            icon = "\dataM\UI\Spawns\solicitor.paa";
            conditions = "[""Solicitor""] call ULP_fnc_hasLicense";
        };
        class News : BaseSpawn {
            displayName = "AAN World News";
            marker = "civ_spawn_news";
            icon = "\dataM\UI\Spawns\news.paa";
            conditions = "[""News""] call ULP_fnc_hasLicense";
        };
        class Rebel : BaseSpawn {
            displayName = "Аутпост повстанцев";
            marker = "civ_spawn_rebel";
            icon = "\dataM\UI\Spawns\rebel.paa";
            conditions = "[""Rebel""] call ULP_fnc_hasLicense && { missionNamespace getVariable [""ULP_SRV_Setting_BaseBidsActive"", false] }";
        };
    };

    class Malden {
        class LaTriniteConstabulary : Police {
            displayName = "Констабулярия Ла Тринитэ";
            marker = "cop_spawn_1";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };

        class test : Police {
            displayName = "Другой вариант";
            marker = "cop_spawn_2";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };

        class LaTriniteHospital : Medic {
            displayName = "Главное управление Ла Тринитэ";
            marker = "medic_spawn";
            icon = "\a3\ui_f\data\map\VehicleIcons\pictureLogic_ca.paa";
        };

        class LaTrinite : BaseSpawn {
            displayName = "Ла Тринитэ";
            marker = "civ_spawn_1";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };
    };
};
