class CfgDebriefing {
    class Abort {
        title = "Покинул игру";
        subtitle = "Спасибо за игру!";
        description = "Ваши данные синхронизированы, и вы вернулись в лобби.";
        pictureBackground = "";
        picture = "\A3\ui_f\data\GUI\Cfg\Hints\Doors_ca.paa";
        pictureColor[] = {1,1,1,1};
    };
    class NotWhitelisted : Abort {
        title = "Невозможно присоединиться";
        subtitle = "У вас нет белого списка";
        description = "Пожалуйста, свяжитесь с членом команды данной фракции для получения дополнительной информации.";
    };
    class Blacklisted : Abort {
        title = "Невозможно присоединиться";
        subtitle = "Вы находитесь в черном списке";
        description = "Пожалуйста, свяжитесь с членом команды данной фракции для получения дополнительной информации.";
    };
};
