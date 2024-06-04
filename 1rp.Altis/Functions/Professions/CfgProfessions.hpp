class CfgProfessions {
	class Repairing {
		displayName = "Ремонт";
		icon = "\dataM\UI\Professions\repairing.paa";
		effectDescription = "Уменьшает время на ремонт на %1%2";
		effectCalculation = "5 * (_this select 0)"; // (_this select 0) относится к уровню этой профессии, а (_this select 1) - текущему опыту.
		xpLevel = 100;
		xpMultipler = 2; // ОПЫТ ДЛЯ УРОВНЯ = xpLevel * (xpMultipler * ТЕКУЩИЙ УРОВЕНЬ) (Если ТЕКУЩИЙ УРОВЕНЬ = 0, ТО xpMultipler не добавляется)
		maxLevel = 5;
	};

	class Fishing { // Рыболовство
		displayName = "Рыболовство";
		icon = "\dataM\UI\Professions\fishing.paa";
		effectDescription = "Уменьшает время на ловлю рыбы на %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Gathering { // Сбор ресурсов
		displayName = "Сбор ресурсов";
		icon = "\dataM\UI\Professions\gathering.paa";
		effectDescription = "Уменьшает время на сбор ресурсов на %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Mining { // Горное дело
		displayName = "Горное дело";
		icon = "\dataM\UI\Professions\mining.paa";
		effectDescription = "Уменьшает время на добычу полезных ископаемых на %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Processing { // Обработка
		displayName = "Обработка";
		icon = "\dataM\UI\Professions\processing.paa";
		effectDescription = "Уменьшает время на обработку на %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Cooking { // Кулинария
		displayName = "Кулинария";
		icon = "\dataM\UI\Professions\cooking.paa";
		effectDescription = "Уменьшает время на готовку на %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Smelting { // Плавление
		displayName = "Плавление";
		icon = "\dataM\UI\Professions\smelting.paa";
		effectDescription = "Уменьшает время на плавление на %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Archeology { // Археология
		displayName = "Археология";
		icon = "\dataM\UI\Professions\archeology.paa";
		effectDescription = "Уменьшает время на археологические исследования и раскопки на %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};
};
