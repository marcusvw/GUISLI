#pragma once
#include "../PAG/PAG.h"
#include "../../version.h"
#ifdef HW_M5PAPER
#include <M5EPD.h>
#endif
#ifdef HW_M5CORE2
#include <M5Core2.h>
#endif
#include "../../rpc/RPC.h"
#include <ArduinoJson.h>
#include <FS.h>
#include <SPIFFS.h>
#include <SD.h>
/**
 * Slider Page implementation
 ***/
class SliderPage : public Page
{
private:
    String image1;
    String image2;
    String itemId;
    String header;
    float factor;
    uint32_t state = 0;
    uint32_t sliderLastSendValue;
#ifdef HW_M5PAPER
    M5EPD_Canvas canvas = (&M5.EPD);
#endif
#ifdef HW_M5CORE2
    #define canvas  M5.Lcd
#endif
    JsonRPC rpc;
    FS *fsHandler;
    bool sliderActive = false;
    const uint16_t SLIDER_X = 160;
    const uint16_t SLIDER_HEIGHT = 200;
    const uint16_t SLIDER_Y = 25;
    const uint16_t SLIDER_WIDTH = 150;
    const uint16_t IMG_POS1_X = 32;
    const uint16_t IMG_POS1_Y = 32;
    const uint16_t IMG_POS2_X = 32;
    const uint16_t IMG_POS2_Y = 128;
    uint32_t lastUpdate = 0;
    int32_t getSliderPos(PAG_pos_t pos);
    void renderHeader(const char *string);

public:
    SliderPage(JsonObject obj, PAG_pos_t cp, bool useSDCard);
    void activate();
    void deActivate();
    void draw();
    void handleInput(PAG_pos_t pos);
    void middleButtonPushed();
    String getHeader();
};