class CfgPerks {
	baseLimit = 3;
	maxLimit = 15;
	removalCost = 100000;

	class SecondNature {
		icon = "\dataM\UI\Perks\secondNature.paa";
		displayName = "Вторая природа";
		description = "Автоматически пристегивает ремень безопасности.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 1;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params setVariable [""seatbelt"", true]; _params";
	};

	class ImprovedMetabolism {
		icon = "\dataM\UI\Perks\improvedMetabolism.paa";
		displayName = "Улучшенный метаболизм";
		description = "Замедляет прирост голода и обезвоживания на 50%.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 2;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class GovernmentBonus {
		icon = "\dataM\UI\Perks\governmentBonus.paa";
		displayName = "Государственная выплата";
		description = "Увеличивает вашу базовую зарплату на 5%.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Hato" };
			level = 3;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class Muscleman {
		icon = "\dataM\UI\Perks\muscleman.paa";
		displayName = "Мускулист";
		description = "Увеличивает ваш предел по весу предметов на 25%.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 4;
			prestige = 0;
			profession[] = {};
		};
		onSelected = "[] call ULP_fnc_maxCarry;";
		onActivated = "";
	};

	class GeneralMechanic {
		icon = "\dataM\UI\Perks\generalMechanic.paa";
		displayName = "Универсальный механик";
		description = "Уменьшает вероятность поломки вашего инструмента на %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic" };
			level = 5;
			prestige = 0;
			profession[] = { "Repairing", 1 };
		};
		onChanged = "";
		onActivated = "_params + (_bonus / 100)";
	};

	class MindfulPlanner {
		icon = "\dataM\UI\Perks\mindfulPlanner.paa";
		displayName = "Внимательный планировщик";
		description = "Вы будете появляться с картой, радио и GPS.";
		removalMultiplier = 2;
		class Requirements {
			factions[] = { "Civilian" };
			level = 6;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class StreetCleaner {
		icon = "\dataM\UI\Perks\vehicleCollector.paa";
		displayName = "Уборщик улиц";
		description = "Увеличивает скорость изъятия и уничтожения автомобилей на %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "10 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Police" };
			level = 6;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class SpeedyLocksmith {
		icon = "\dataM\UI\Perks\speedyLocksmith.paa";
		displayName = "Скоростной слесарь";
		description = "Увеличивает скорость вскрытия замков на %1%2.";
		removalMultiplier = 1.3;
		class Leveling {
			maxLevel = 3;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "20 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 7;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class WideTraveller {
		icon = "\dataM\UI\Perks\wideTraveller.paa";
		displayName = "Широкий путешественник";
		description = "Позволяет вам появляться в Софии, Агиосе и Неохори.";
		removalMultiplier = 5;
		class Requirements {
			factions[] = { "Civilian" };
			level = 8;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class CompletedCV {
		icon = "\dataM\UI\Perks\completedCV.paa";
		displayName = "Завершенное резюме";
		description = "Позволяет вам устроиться на различные рабочие места.";
		removalMultiplier = 3;
		class Requirements {
			factions[] = { "Civilian" };
			level = 9;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class LegalTrader {
		icon = "\dataM\UI\Perks\legalTrader.paa";
		displayName = "Законный торговец";
		description = "Увеличивает цену продажи легальных товаров на %1%2.";
		removalMultiplier = 3;
		class Leveling {
			maxLevel = 3;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "5 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 10;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class RapidSurveyor {
		icon = "\dataM\UI\Perks\rapidSurveyor.paa";
		displayName = "Быстрый обследователь";
		description = "Увеличивает скорость обследования месторождений при раскопках на %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "15 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian" };
			level = 11;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class BoltCutter {
		icon = "\dataM\UI\Perks\boltCutter.paa";
		displayName = "Откусыватель болтов";
		description = "Увеличивает скорость откусывания болтов на %1%2.";
		removalMultiplier = 1.3;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 12;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class ShadyTrader {
		icon = "\dataM\UI\Perks\shadyTrader.paa";
		displayName = "Теневой торговец";
		description = "Увеличивает цену продажи нелегальных товаров на %1%2.";
		removalMultiplier = 3;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "5 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 13;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class cuffCourier {
		icon = "\dataM\UI\Perks\cuffCourier.paa";
		displayName = "Перчаточный курьер";
		description = "Получите возможность заключать в наручники без стяжек.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian" };
			level = 14;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class IDForger {
		icon = "\dataM\UI\Perks\idForger.paa";
		displayName = "Фальсификатор ID";
		description = "Позволяет вам подделывать фальшивые удостоверения личности.";
		removalMultiplier = 3;
		class Requirements {
			factions[] = { "Civilian" };
			level = 15;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class EcoDriver { // TODO
		icon = "\dataM\UI\Perks\ecoDriver.paa";
		displayName = "Экологичный водитель";
		description = "Уменьшает стоимость топлива за литр на %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 16;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class MatesRates {
		icon = "\dataM\UI\Perks\matesRates.paa";
		displayName = "Льготные цены";
		description = "Уменьшает плату за доставку в гараж на 50%.";
		removalMultiplier = 6;
		class Requirements {
			factions[] = { "Civilian" };
			level = 17;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class PartsCarrier {
		icon = "\dataM\UI\Perks\partsCarrier.paa";
		displayName = "Перевозчик запчастей";
		description = "Уменьшает стоимость обслуживания воздушного судна на %1%2.";
		removalMultiplier = 2;
		class Leveling {
			maxLevel = 3;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian" };
			level = 18;
			prestige = 0;
			profession[] = { "Repairing", 3 };
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class ScrapDealer {
		icon = "\dataM\UI\Perks\scrapDealer.paa";
		displayName = "Дилер по металлолому";
		description = "Увеличивает сумму денег, получаемую за разборку автомобиля на металлолом на %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 5;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "3 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian" };
			level = 19;
			prestige = 0;
			profession[] = { "Repairing", 3 };
		};
		onChanged = "";
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class SlightofHand { // TODO
		icon = "\dataM\UI\Perks\slightOfHand.paa";
		displayName = "Ловкость рук";
		description = "Увеличивает скорость перезарядки ваших магазинов на %1%2.";
		removalMultiplier = 1.5;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "15 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police" };
			level = 20;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

	class VehicleCollector {
		icon = "\dataM\UI\Perks\vehicleCollector.paa";
		displayName = "Собиратель транспорта";
		description = "Увеличивает лимит гаража для каждого типа транспортных средств на 1.";
		removalMultiplier = 10;
		class Requirements {
			factions[] = { "Civilian" };
			level = 21;
			prestige = 0;
			profession[] = {};
		};
		onChanged = "";
		onActivated = "";
	};

class BloodCarrier {
    icon = "\dataM\UI\Perks\bloodCarrier.paa";
    displayName = "Переливатель крови";
    description = "Увеличивает эффективность переливания крови на %1%2.";
    removalMultiplier = 1.2;
    class Leveling {
        maxLevel = 4;
        xpLevel = 100;
        xpMultipler = 2;
        levelCalculation = "25 * (_this select 0)";
    };
    class Requirements {
        factions[] = { "Civilian", "Police", "Medic", "Hato" };
        level = 22;
        prestige = 0;
        profession[] = {};
    };
    onChanged = "";
    onActivated = "_params + (_params * (_bonus / 100))";
};

class IntelligentBanker { // TODONOW
    icon = "\dataM\UI\Perks\intelligentBanker.paa";
    displayName = "Интеллектуальный банкир";
    description = "Уменьшает комиссию за банковские переводы на %1%2.";
    removalMultiplier = 1;
    class Leveling {
        maxLevel = 4;
        xpLevel = 100;
        xpMultipler = 2;
        levelCalculation = "25 * (_this select 0)";
    };
    class Requirements {
        factions[] = { "Civilian", "Police", "Medic", "Hato" };
        level = 23;
        prestige = 0;
        profession[] = {};
    };
    onChanged = "";
    onActivated = "";
};

class FirstAider {
    icon = "\dataM\UI\Perks\firstAider.paa";
    displayName = "Первый помощник";
    description = "Увеличивает эффективность аптечек на %1%2.";
    removalMultiplier = 1.2;
    class Leveling {
        maxLevel = 5;
        xpLevel = 100;
        xpMultipler = 2;
        levelCalculation = "5 * (_this select 0)";
    };
    class Requirements {
        factions[] = { "Civilian", "Police", "Medic", "Hato" };
        level = 24;
        prestige = 0;
        profession[] = {};
    };
    onChanged = "";
    onActivated = "_params + (_params * (_bonus / 100))";
};

class SilentLocksmith { // TODO : Add to vehicle lockpicking...
    icon = "\dataM\UI\Perks\silentLocksmith.paa";
    displayName = "Бесшумный слесарь";
    description = "Уменьшает вероятность срабатывания сигнализации на %1%2.";
    removalMultiplier = 1.3;
    class Leveling {
        maxLevel = 4;
        xpLevel = 100;
        xpMultipler = 2;
        levelCalculation = "25 * (_this select 0)";
    };
    class Requirements {
        factions[] = { "Civilian", "Police", "Medic", "Hato" };
        level = 25;
        prestige = 0;
        profession[] = {};
    };
    onChanged = "";
    onActivated = "_params - (_params * (_bonus / 100))";
};

class Blackmarketer {
    icon = "\dataM\UI\Perks\blackmarketer.paa";
    displayName = "Черный рынок";
    description = "Позволяет получить доступ к Черному рынку.";
    removalMultiplier = 10;
    class Requirements {
        factions[] = { "Civilian" };
        level = 26;
        prestige = 0;
        profession[] = {};
    };
    onChanged = "";
    onActivated = "";
};

class QuickLearner {
    icon = "\dataM\UI\Perks\quickLearner.paa";
    displayName = "Быстро обучаемый";
    description = "Увеличивает количество получаемого опыта профессии на 10%.";
    removalMultiplier = 1.5;
    class Requirements {
        factions[] = { "Civilian", "Police", "Medic", "Hato" };
        level = 27;
        prestige = 0;
        profession[] = {};
    };
    onChanged = "";
    onActivated = "_params + (_params * (_bonus / 100))";
};

class LandLord {
    icon = "\dataM\UI\Perks\landLord.paa";
    displayName = "Владелец недвижимости";
    description = "Позволяет вам приобрести дополнительное имущество.";
    removalMultiplier = 4;
    class Requirements {
        factions[] = { "Civilian" };
        level = 28;
        prestige = 0;
        profession[] = {};
    };
    onChanged = "";
    onActivated = "";
};

class LifeSaver {
    icon = "\A3\ui_f\data\GUI\Cfg\Hints\Injury_ca.paa";
    displayName = "Спаситель жизни";
    description = "Увеличивает скорость оживления на %1%2.";
    removalMultiplier = 1;
    class Leveling {
        maxLevel = 5;
        xpLevel = 100;
        xpMultipler = 2;
        levelCalculation = "10 * (_this select 0)";
    };
    class Requirements {
        factions[] = { "Civilian", "Police", "Medic", "Hato" };
        level = 24;
        prestige = 0;
        profession[] = {};
    };
    onChanged = "";
    onActivated = "_params + (_params * (_bonus / 100))";
};


class rapidStorer {
    icon = "\dataM\UI\Perks\rapidStorer.paa";
    displayName = "Быстрый складыватель";
    description = "Уменьшает время, необходимое для уборки транспорта в гараж на %1%2.";
    removalMultiplier = 1;
    class Leveling {
        maxLevel = 3;
        xpLevel = 100;
        xpMultipler = 2;
        levelCalculation = "10 * (_this select 0)";
    };
    class Requirements {
        factions[] = { "Civilian", "Police", "Hato" };
        level = 29;
        prestige = 0;
        profession[] = {};
    };
    onChanged = "";
    onActivated = "_params - (_params * (_bonus / 100))";
};

class UncertainMind {
    icon = "\dataM\UI\Perks\uncertainPerson.paa";
    displayName = "Неуверенный человек";
    description = "Получите шанс сохранить транспорт при его разборке.";
    removalMultiplier = 2;
    class Requirements {
        factions[] = { "Civilian" };
        level = 30;
        prestige = 0;
        profession[] = {};
    };
    onChanged = "";
    onActivated = "((random 100) max 1)";
};
};
