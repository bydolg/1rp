class CfgReputation {
	Lowest = -1000; // Наименьшая репутация
	Highest = 1000; // Наивысшая репутация

	class Types {
		// Высокая репутация
		class ReviveHighRep {
			reason = "Воскресил человека с высокой репутацией";
			change = 25; // Изменение репутации
		};

		class IncapHighRep {
			reason = "Обездвижил человека с высокой репутацией";
			change = -25;
		};

		class KilledHighRep {
			reason = "Убил человека с высокой репутацией";
			change = -50;
		};

		// Обычная репутация
		class ReviveNormal {
			reason = "Воскресил человека с нейтральной репутацией";
			change = 15;
		};

		class IncapNormal {
			reason = "Обездвижил человека с нейтральной репутацией";
			change = -15;
		};

		class KilledNormal : IncapNormal {
			reason = "Убил человека с нейтральной репутацией";
		};

		// Низкая репутация
		class IncapLowRep {
			reason = "Обездвижил человека с низкой репутацией";
			change = 25;
		};

		class KilledLowRep {
			reason = "Убил человека с низкой репутацией";
			change = 50;
		};
	};
};
