class CfgGovernment {
	electionInternal = 14;

	class Rigging {
		timeToRig = 30;
		alreadyRiggedMultiplier = 1.5;
	};
	
	class Legislation {
		class Tax {
			displayName = "Ставка налога на острове";
			tooltip = "Это изменяет ставку налога, применяемую к определенным ценам на острове.";
			type = "NUMBER";
			format = "format [""%2%1"", ""%"", [_this] call ULP_fnc_numberText]";
			values[] = { { 1, 10 }, 5 };
		};
		class Paychecks {
			displayName = "Субсидии к зарплатам";
			tooltip = "Это изменяет сумму денег, добавляемую к зарплатам граждан Алтиса.";
			type = "NUMBER";
			format = "format [""%1%2"", ""$"", [_this] call ULP_fnc_numberText]";
			values[] = { { 2500, 7500 }, 5000 };
		};
		class Mission {
			displayName = "Оплата за выполнение заданий";
			tooltip = "Это изменяет сумму дополнительных денег, которые правительство дает за выполнение заданий.";
			type = "NUMBER";
			format = "format [""%1%2"", ""$"", [_this] call ULP_fnc_numberText]";
			values[] = { { 0, 5 }, 0 };
		};
		class Service {
			displayName = "Ценообразование на авиационных услугах";
			tooltip = "Это изменяет цену за единицу топлива на авиационной заправке.";
			type = "NUMBER";
			format = "format [""%1%2"", ""$"", [_this] call ULP_fnc_numberText]";
			values[] = { { 500, 1500 }, 1000 };
		};
		class Revival {
			displayName = "Сбор за воскрешение";
			tooltip = "Это изменяет сумму денег, выплачиваемую медикам за воскрешение.";
			type = "NUMBER";
			format = "format [""%1%2"", ""$"", [_this] call ULP_fnc_numberText]";
			values[] = { { 10000, 25000 }, 17500 };
		};
	};
};
