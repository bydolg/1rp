class CfgOptions {
	class General {
		title = "Общие";

		class EnableWelcome {
			name = "Включить приветственное сообщение";
			tooltip = "При включении будет отображаться текст с информацией о сервере при первом появлении.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
			condition = "true";
		};

		class EnableStreamerMode : EnableWelcome {
			name = "Включить режим стримера";
			tooltip = "При включении некоторые аспекты вашей игры могут быть скрыты или заменены для обеспечения конфиденциальности.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 0 };
		};

		class EnableAutoDecline : EnableWelcome {
			name = "Включить отклонение приглашений в группу";
			tooltip = "При включении приглашения в группу будут автоматически отклонены.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 0 };
		};

		class NightLight : EnableWelcome {
			name = "Освещение ночью";
			tooltip = "Это уровень освещения, который будет использоваться на карте ночью.";
			type = "SLIDER";
			values[] = { { 0, 0.5 }, 0.5, { 0.1, 0.1 } };
		};
	};

	class Audio {
		title = "Звук";

		class EffectsFade {
			name = "Громкость звуковых эффектов";
			tooltip = "Это уровень громкости звуковых эффектов, который будет использоваться при использовании наушников.";
			type = "SLIDER";
			values[] = { { 0, 1 }, 0.25, { 0.1, 0.1 } };
			condition = "true";
		};
		
		class MusicFade : EffectsFade {
			name = "Громкость музыки";
			tooltip = "Это уровень громкости музыки, который будет использоваться при использовании наушников.";
			type = "SLIDER";
			values[] = { { 0, 1 }, 0.25, { 0.1, 0.1 } };
		};

		class EnableMessageAlert : EffectsFade {
			name = "Включить оповещение о сообщениях";
			tooltip = "При включении вы будете получать звуковое оповещение о поступлении сообщения.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
		};

		class EnableAmbientSounds : EffectsFade {
			name = "Включить звуки окружения";
			tooltip = "При включении вы сможете слышать звуки окружения в ArmA.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
		};
	};

	class HUD {
		title = "Пользовательский интерфейс";

		class EnableHUD {
			name = "Включить HUD";
			tooltip = "При включении на экране отображается информация, такая как здоровье, вода и т. д.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
			condition = "true";
		};

		class EnableXPBar : EnableHUD {
			name = "Включить панель опыта";
			tooltip = "Если HUD включен, а также это, ваш опыт будет отображаться на экране.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
		};

		class EnablePlayerTags : EnableHUD  {
			name = "Включить теги игроков";
			tooltip = "При включении будет отображаться информация о игроке над его головой.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
		};

		class ShowOwnTags : EnableHUD  {
			name = "Показывать собственные теги игрока";
			tooltip = "Если теги игроков включены, а также это, вы увидите свой собственный тег игрока.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
		};

		class SideChat : EnableHUD  {
			name = "Показывать чат";
			tooltip = "При включении будут отображаться сообщения в чате.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
		};
	};

	class Indicators {
		title = "Индикаторы группы";

		class EnableIndicators {
			name = "Включить индикаторы";
			tooltip = "При включении будут отображаться шестиугольники, показывающие местоположение членов группы.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
			condition = "true";
		};

		class EnableFactionColouring {
			name = "Включить цветовую разметку по фракциям";
			tooltip = "При включении индикаторы будут окрашены в соответствии с их формой.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
			condition = "[player, [""Police"", ""Medic""]] call ULP_fnc_isFaction";
		};

		class EnableNamesOnIndicators : EnableIndicators {
			name = "Включить отображение имен на индикаторах";
			tooltip = "При включении имена членов группы будут отображаться под их шестиугольниками.";
		};

		class IndicatorDistance : EnableIndicators {
			name = "Дистанция индикаторов";
			tooltip = "Это расстояние, на котором будут видны индикаторы группы. (20 - 2000 м)";
			type = "SLIDER";
			values[] = { { 20, 2000 }, 2000, { 1, 1, 1 } };
		};
	};

	class Cartels {
		title = "Картелы";

		class NotifyPayment {
			name = "Отображать выплаты от картелей";
			tooltip = "При включении вы узнаете точную сумму, которую вы и ваша группа получили от картелей.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
			condition = "true";
		};
	};

	class Chat {
		title = "Чат";

		class EnableMessagesIncapacitated {
			name = "Включить сообщения о бессознательности";
			tooltip = "При включении сообщения о бессознательности и ранениях будут отображаться в чате.";
			type = "DROPDOWN";
			values[] = { { {"Включено", 1}, {"Отключено", 0} }, 1 };
			condition = "true";
		};

		class EnableMessagesBleedout : EnableMessagesIncapacitated {
			name = "Включить сообщения о кровотечении";
			tooltip = "При включении сообщения о кровотечении и казнях будут отображаться в чате.";
		};

		class EnableMessagesTicket : EnableMessagesIncapacitated {
			name = "Включить сообщения о штрафах";
			tooltip = "При включении будут отображаться сообщения о штрафах в чате.";
		};

		class EnableMessagesRevived : EnableMessagesIncapacitated {
			name = "Включить сообщения о воскрешении";
			tooltip = "При включении будут отображаться сообщения о воскрешении в чате.";
		};

		class EnableMessagesPrisoned : EnableMessagesIncapacitated {
			name = "Включить сообщения о заключении";
			tooltip = "При включении будут отображаться сообщения о заключении в чате.";
		};

		class EnableMessagesVehicle : EnableMessagesIncapacitated {
			name = "Включить сообщения о транспорте";
			tooltip = "При включении будут отображаться сообщения о гараже, конфискации и уничтожении транспорта в чате.";
		};
	};
};
