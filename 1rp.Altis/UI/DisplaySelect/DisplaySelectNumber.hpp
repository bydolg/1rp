#define UI_WIDTH 0.175
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.1
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DisplaySelectNumber {
    idd = 3200;
    movingEnable = 0;
    enableSimulation = 0;
	onunload = "_this call { private _params = ((_this select 0) getVariable ""params""); _params append [(_this select 0), (sliderPosition ((_this select 0) displayCtrl 3205))]; if ((_this select 1) isEqualTo 1) then { ((_this select 0) getVariable ""params"") call ((_this select 0) getVariable ""onSelect""); }; };";

    class ControlsBackground {
		class TabletBackground : Life_RscBackground {
			idc = 3207;
			colorBackground[] = { 0, 0, 0, 0.6 };
			SAFEZONE_X(0.29375);
			SAFEZONE_Y(0.243);
			SAFEZONE_W(0.4150);
			SAFEZONE_H(0.505);
		};

		class FullBackground : Life_RscBackground {
			idc = 3208;
			colorBackground[] = { 0, 0, 0, 0.6 };
			SAFEZONE_X(0);
			SAFEZONE_Y(0);
			SAFEZONE_W(1);
			SAFEZONE_H(1);
		};

		class Header : Life_RscText {
			idc = 3201;
			colorBackground[] = HEADER_COLOUR;
                        text = $STR_DISPLAYSELECTNUMBER_HEADER;
			SAFEZONE_X(UI_X);
			SAFEZONE_Y(BODY_Y - 0.022);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.022);
		};

		class Body : Life_RscText {
			idc = -1;
			colorBackground[] = BODY_COLOUR;
			SAFEZONE_X(UI_X);
			SAFEZONE_Y(BODY_Y);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BODY_HEIGHT);
		};

		class Footer : Life_RscText {
			idc = -1;
			colorBackground[] = FOOTER_COLOUR;
			SAFEZONE_X(UI_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT));
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.033);
		};
	};

	class Controls {

		#define ITEM_HEIGHTS VERTICAL_GRID_H((BODY_HEIGHT - (MARGIN_Y * 2)), 3, (MARGIN_Y / 2))

		class MinMaxText : Life_RscStructuredText {
			idc = 3204;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 0, (MARGIN_Y / 2)));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(ITEM_HEIGHTS);
		};

		class ValueInput : life_RscEdit {
			idc = 3209;
			text = "";
			colorDisabled[] = {0.95, 0.95, 0.95, 1};
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 1, (MARGIN_Y / 2)));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(ITEM_HEIGHTS);
		};

		class Slider : life_RscXSliderH {
			idc = 3205;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 2, (MARGIN_Y / 2)));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(ITEM_HEIGHTS);
		};

		class Select : Life_RscButtonCenter {
			idc = 3206;
                        text = $STR_DISPLAYSELECTNUMBER_SELECT;
			onButtonClick = "(ctrlParent (_this select 0)) closeDisplay 1;";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};
