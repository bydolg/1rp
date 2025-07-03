class CfgRobberies {
	personalTimeout = 3 * 60;

	class FuelStation {
		name = "Заправка";
		time = 5 * 60;
		timeout = 3 * 60;
		factions[] = { "Civilian" };
		reward[] = { 30000, 65000 };
		leveling[] = { { 5, 15 }, "Ограбление Заправки", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 1";
		onFail = "[""Для ограбления этой локации должно быть онлайн как минимум <t color='#B92DE0'>1 офицер</t>!"" ] call ULP_fnc_hint;";
	};

	class Supermarket {
		name = "Супермаркет";
		time = 7 * 60;
		timeout = 5 * 60;
		factions[] = { "Civilian" };
		reward[] = { 50000, 95000 };
		leveling[] = { { 5, 15 }, "Ограбление Супермаркета", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 2";
		onFail = "[""Для ограбления этой локации должно быть онлайн как минимум <t color='#B92DE0'>2 офицера</t>!"" ] call ULP_fnc_hint;";
	};

	class Jewellery {
		name = "Ювелирный магазин";
		time = 8 * 60;
		timeout = 15 * 60;
		factions[] = { "Civilian" };
		reward[] = { 95000, 220000 };
		leveling[] = { { 5, 15 }, "Ограбление Ювелирного магазина", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 3";
		onFail = "[""Для ограбления этой локации должно быть онлайн как минимум <t color='#B92DE0'>3 офицера</t>!"" ] call ULP_fnc_hint;";
	};

	class RegionalBank {
		name = "Региональный банк";
		time = 10 * 60;
		timeout = 30 * 60;
		factions[] = { "Civilian" };
		reward[] = { 140000, 460000 };
		leveling[] = { { 5, 15 }, "Ограбление Регионального банка", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction >= 4";
		onFail = "[""Для ограбления этой локации должно быть онлайн как минимум <t color='#B92DE0'>5 офицеров</t>!"" ] call ULP_fnc_hint;";
	};
};
