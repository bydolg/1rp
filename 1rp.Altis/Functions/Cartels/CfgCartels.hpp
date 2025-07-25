class CfgCartels {
	class Popup {
		duration = 30 * 60;
		captureTime = 5 * 60;
		reward[] = { 100000, 300000 };
	};

	class Fixed {
		cartelTick = 1 * 60;
		rewardTicks = 15;
		rewardXp = 100;
		rewardAmounts[] = { 150, 350 }; // При 25 игроках и менее, выше 25

		class Northern {
			name = "Северный наркокартель";
			factions[] = { "Police", "Civilian" };
			position[] = {14295, 13029, 0};
			zoneRadius = 50;
			kosRadius = 300;
			class Drug {
				extraPay = 1.05;
				saleTax = 0.05;
			};
		};

		class Southern {
			name = "Южный наркокартель";
			factions[] = { "Police", "Civilian" };
			position[] = {11194, 8717, 0};
			zoneRadius = 75;
			kosRadius = 0;
			class Drug {
				extraPay = 1.025;
				saleTax = 0.1;
			};
		};

		class Church {
			name = "Церковный оружейный картель";
			factions[] = { "Police", "Civilian" };
			position[] = {8926, 7493, 0};
			zoneRadius = 50;
			kosRadius = 0;
			class Arms {
				primaryDiscount = 0.25;
				secondaryDiscount = 0.25;
			};
		};

		class Zaros {
			name = "Картель Зарос Бэй";
			factions[] = { "Police", "Civilian" };
			position[] = {10037, 10130, 0};
			zoneRadius = 40;
			kosRadius = 0;
			class Drug {
				extraPay = 1.025;
				saleTax = 0.05;
			};
			class Arms {
				primaryDiscount = 0.05;
				secondaryDiscount = 0.1;
			};
		};

		class Pefkas {
			name = "Картель бухты Пефкас";
			factions[] = { "Police", "Civilian" };
			position[] = {20600, 20116, 0};
			zoneRadius = 50;
			kosRadius = 300;
			class Drug {
				extraPay = 1.015;
				saleTax = 0.025;
			};
			class Arms {
				primaryDiscount = 0.025;
				secondaryDiscount = 0.05;
			};
		};
	};
};
