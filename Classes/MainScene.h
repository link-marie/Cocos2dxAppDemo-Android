#pragma once

#include "cocos2d.h"

using namespace cocos2d;

class MainScene : public Scene {
private:
    const char* __CLASS__ = "MainScene";

public:
    bool virtual init();

    CREATE_FUNC( MainScene );
};
