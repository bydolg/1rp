class CfgNotifications {
    class AchievementUnlocked {
        title = "ДОСТИЖЕНИЕ РАЗБЛОКИРОВАНО";
        iconPicture = "\a3\ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
        description = "%1";
        priority = 0;
    };

    class GoalReward : AchievementUnlocked {
        title = "ЛИЧНАЯ ЦЕЛЬ";
    };

    class TitleUnlocked : AchievementUnlocked {
        title = "ЗАГОЛОВОК РАЗБЛОКИРОВАН";
    };
};
