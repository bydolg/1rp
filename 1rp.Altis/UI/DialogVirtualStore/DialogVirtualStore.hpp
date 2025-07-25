#define UI_X 0.29375
#define UI_WIDTH 0.4125
#define INNER_UI_WIDTH (UI_WIDTH - MARGIN_X)
#define BODY_HEIGHT 0.407

class DialogVirtualStore {
    idd = 3300;
    name = "DialogVirtualStore";
    movingEnable = 1;
    enableSimulation = 1;

    class ControlsBackground {
        class Header : Life_RscText {
            idc = 3301;
            colorBackground[] = HEADER_COLOUR;
            text = $STR_DIALOGVIRTUALSTORE_HEADER;
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.269);
            SAFEZONE_W(UI_WIDTH);
            SAFEZONE_H(0.022);
        };

        class Body : Life_RscText {
            idc = -1;
            colorBackground[] = BODY_COLOUR;
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.291);
            SAFEZONE_W(UI_WIDTH);
            SAFEZONE_H(BODY_HEIGHT);
        };

        class ItemBackground : Life_RscText {
            idc = -1;
            colorBackground[] = INNER_BODY_COLOUR;
            text = "";
            SAFEZONE_X(UI_X + MARGIN_X);
            SAFEZONE_Y(0.291 + MARGIN_Y);
            SAFEZONE_W(0.275);
            SAFEZONE_H(0.385);
        };

        class ItemHeader : Life_RscText {
            idc = -1;
            colorBackground[] = { 0, 0, 0, 1 };
            text = "";
            SAFEZONE_X(UI_X + MARGIN_X);
            SAFEZONE_Y(0.291 + MARGIN_Y);
            SAFEZONE_W(0.275);
            SAFEZONE_H(0.022);
			//0.385
        };

        class Footer : Life_RscText {
            idc = -1;
            colorBackground[] = FOOTER_COLOUR;
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.698);
            SAFEZONE_W(UI_WIDTH);
            SAFEZONE_H(0.033);
        };
    };

    class Controls {
        class ItemListHeader: Life_RscListNBox {
            idc = 3302;
            SAFEZONE_X(UI_X + MARGIN_X);
            SAFEZONE_Y(0.291 + MARGIN_Y);
            SAFEZONE_W(0.275);
            SAFEZONE_H(0.022);
            text = "";    
            rowHeight = 0.04;
            sizeEx = 0.038;
			columns[] = { 0, 0.5, 0.65, 0.8 };
            drawSideArrows = false;
            idcLeft = -1;
            idcRight = -1;
            disableOverflow = 1;

            class Items {
                class DisplayName {
                    text = $STR_DIALOGVIRTUALSTORE_ITEM;
                    value = 0;
                };
                class Buy {
                    text = $STR_DIALOGVIRTUALSTORE_BUY;
                };
                class Sell {
                    text = $STR_DIALOGVIRTUALSTORE_SELL;
                };
                class Amount {
                    text = $STR_DIALOGVIRTUALSTORE_AMOUNT;
                    value = -1;
                    data = "data";
                };
            };
        };

        class ItemListList : Life_RscListNBox {
            idc = 3303;
            SAFEZONE_X(UI_X + MARGIN_X);
            SAFEZONE_Y(0.324);
            SAFEZONE_W(0.275);
            SAFEZONE_H(0.363);
            text = "";    
            onLBSelChanged = "_this call ULP_fnc_vStoreChange;";
            rowHeight = 0.04;
            sizeEx = 0.038;
			columns[] = { 0, 0.5, 0.65, 0.8 };
            drawSideArrows = false;
            idcLeft = -1;
            idcRight = -1;
        };

        class ItemInformation : Life_RscStructuredText {
            idc = 3304;
            text = "";
            colorBackground[] = INNER_BODY_COLOUR;
            SAFEZONE_X(0.5790625);
            SAFEZONE_Y(0.291 + MARGIN_Y);
            SAFEZONE_W(0.12203125);
            SAFEZONE_H(0.385);
        };

        class BuyButton : Life_RscButtonCenter {
            idc = 3305;
            text = $STR_DIALOGVIRTUALSTORE_BUY_BTN;
            onButtonClick = "[_this] call ULP_fnc_handleVItems;";
            SAFEZONE_X(0.5790625);
            SAFEZONE_Y(0.698 + BUTTON_MARGIN_Y);
            SAFEZONE_W(0.0584375);
            SAFEZONE_H(BUTTON_H);
        };

        class SellButton : Life_RscButtonCenter {
            idc = 3306;
            text = $STR_DIALOGVIRTUALSTORE_SELL_BTN;
            onButtonClick = "[_this, true] call ULP_fnc_handleVItems;";
            SAFEZONE_X(0.64265625);
            SAFEZONE_Y(0.698 + BUTTON_MARGIN_Y);
            SAFEZONE_W(0.0584375);
            SAFEZONE_H(BUTTON_H);
        };
    };
};
