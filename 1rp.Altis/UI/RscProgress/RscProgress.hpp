class RscProgress {
    name = "RscProgress";
    idd = 38200;
    fadein=0;
    duration = 10e10;
    fadeout=0;
    movingEnable = 0;
    onLoad="uiNamespace setVariable ['RscProgress', _this select 0]";
	onUnload="";
    objects[]={};

    class controlsBackground {
        class Background: Life_RscText {
            idc = -1;
            colorBackground[] = {0.1,0.1,0.1,0.85};
			x = 0.386562 * safezoneW + safezoneX;
            y = 0.87 * safezoneH + safezoneY;
            w = 0.226875 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class ProgressBar: Life_RscProgress {
            idc = 38201;
            x = 0.386562 * safezoneW + safezoneX;
            y = 0.87 * safezoneH + safezoneY;
            w = 0.226875 * safezoneW;
            h = 0.022 * safezoneH;
        };

		class ProgressText: Life_RscStructuredText {
            idc = 38202;
            text = "Пожалуйста, подождите";
            x = 0.386562 * safezoneW + safezoneX;
            y = 0.845 * safezoneH + safezoneY;
            w = 0.226875 * safezoneW;
            h = 0.022 * safezoneH;
			class Attributes
			{
				align = "center";
			};
        };

		class PercentageText: Life_RscStructuredText {
            idc = 38203;
            text = "69%";
            x = 0.386562 * safezoneW + safezoneX;
            y = 0.87 * safezoneH + safezoneY;
            w = 0.226875 * safezoneW;
            h = 0.022 * safezoneH;
			class Attributes
			{
				align = "center";
			};
        };

        class CancelText: Life_RscStructuredText {
            idc = 38204;
            text = "Нажмите <t color = '#8A2BE2'>[ESCAPE]</t> для отмены";
            x = 0.386562 * safezoneW + safezoneX;
            y = 0.895 * safezoneH + safezoneY;
            w = 0.226875 * safezoneW;
            h = 0.022 * safezoneH;
			class Attributes
			{
				align = "center";
			};
        };
    };
};