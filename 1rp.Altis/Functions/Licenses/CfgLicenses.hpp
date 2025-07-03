class CfgLicenses {
    class BaseLicense {
        factions[] = { "Civilian" };
        description = "Базовое требование для обработки товаров.";
        class Settings {
            isVisible = false;
            isRemovable = false;
        };
        conditions = "true";
    };

    class Driving : BaseLicense {
        displayName = "Водительское удостоверение";
        description = "Базовое требование для покупки автомобиля/фургона.";
        buyPrice = 1000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Trucking : Driving {
        displayName = "Удостоверение грузоперевозчика";
        description = "Базовое требование для покупки грузового транспортного средства.";
        buyPrice = 95000;
        class Settings : Settings {};
    };

    class Boating : Driving {
        displayName = "Удостоверение моряка";
        description = "Базовое требование для покупки лодки.";
        buyPrice = 6500;
        class Settings : Settings {};
    };

    class Piloting : Driving {
        displayName = "Удостоверение пилота";
        description = "Базовое требование для покупки вертолета/самолета.";
        buyPrice = 480000;
        class Settings : Settings {};
    };

    class Home : Driving {
        displayName = "Разрешение владельца недвижимости";
        description = "Базовое требование для покупки недвижимости.";
        buyPrice = 3000000;
        class Settings : Settings {};
    };

    class Taxi : Driving {
        displayName = "Водитель такси";
        description = "Одобрено для работы таксистом.";
        buyPrice = 35000;
        onBought = "[""Employment""] call ULP_fnc_achieve;";
        class Settings : Settings {};
        conditions = "[""CompletedCV""] call ULP_fnc_hasPerk";
    };

    class Solicitor : Taxi {
        displayName = "Адвокат";
        description = "Одобрено для работы адвокатом.";
        buyPrice = 1700000;
        class Settings : Settings {};
    };

    class News : Taxi {
        displayName = "Репортер мировых новостей AAN";
        description = "Одобрено для работы репортером новостей.";
        buyPrice = 700000;
        class Settings : Settings {};
    };

    class IDAP : Driving {
        displayName = "Доброволец IDAP";
        description = "Добровольно работаете на Международном проекте развития и помощи.";
        buyPrice = 0;
        class Settings : Settings {};
    };

    class Handgun : Driving {
        displayName = "Сертификат на пистолет";
        description = "Сертификация, позволяющая владеть пистолетом.";
        buyPrice = 65000;
        class Settings : Settings {};
    };

    class Hunting : Driving {
        displayName = "Сертификат на охоту";
        description = "Сертификация, позволяющая охотиться на диких животных.";
        buyPrice = 140000;
        class Settings : Settings {};
    };

    class Rebel : BaseLicense {
        displayName = "Доступ к повстанцам";
        description = "Приобретен доступ для использования ресурсов повстанцев на Алтисе.";
        buyPrice = 5000000;
        onBought = "[""JoinRebel""] call ULP_fnc_achieve;";
        class Settings {};
    };

    class Blackmarket : BaseLicense {
        displayName = "Доступ к чёрному рынку";
        description = "Приобретен доступ для использования ресурсов чёрного рынка на Алтисе.";
        buyPrice = 15000000;
        class Settings {};
        conditions = "[""Rebel""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk } && { [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
    };

    // Сайты обработки
    class Schnapps : BaseLicense {
        displayName = "Обработка шнапса";
        buyPrice = 15000;
        class Settings {};
    };

    class Tobacco : BaseLicense {
        displayName = "Обработка табака";
        buyPrice = 45000;
        class Settings {};
    };

    class Copper : BaseLicense {
        displayName = "Обработка меди";
        buyPrice = 30000;
        class Settings {};
    };

    class Silver : BaseLicense {
        displayName = "Обработка серебра";
        buyPrice = 35000;
        class Settings {};
    };

    class Iron : BaseLicense {
        displayName = "Обработка железа";
        buyPrice = 290000;
        class Settings {};
    };

    class Salt : BaseLicense {
        displayName = "Обработка соли";
        buyPrice = 140000;
        class Settings {};
    };

    class Sand : BaseLicense {
        displayName = "Обработка песка";
        buyPrice = 155000;
        class Settings {};
    };

    class Oil : BaseLicense {
        displayName = "Обработка нефти";
        buyPrice = 265000;
        class Settings {};
    };

    class Diamond : BaseLicense {
        displayName = "Обработка алмазов";
        buyPrice = 736500;
        class Settings {};
    };

    class Uranium : BaseLicense {
        displayName = "Обработка урана";
        buyPrice = 800000;
        class Settings {};
    };

    class Weed : BaseLicense {
        displayName = "Обработка марихуаны";
        buyPrice = 80000;
        class Settings {};
    };

    class Heroin : BaseLicense {
        displayName = "Обработка героина";
        buyPrice = 195000;
        class Settings {};
    };

    class Cocaine : BaseLicense {
        displayName = "Обработка кокаина";
        buyPrice = 710000;
        class Settings {};
    };

    class Meth : BaseLicense {
        displayName = "Обработка метамфетамина";
        buyPrice = 785000;
        class Settings {};
    };

    class Moonshine : BaseLicense {
        displayName = "Обработка мескита";
        buyPrice = 1050000;
        class Settings {};
    };
};
