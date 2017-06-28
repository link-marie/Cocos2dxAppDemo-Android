#pragma once

#include "cocos2d.h"
#include "Common.h"
#include "AppMacros.h"

USING_NS_CC;


class Utl {
private:
    static int screenType;

public:
    Utl();

    virtual ~Utl();

    static Size getFrameSize();

    static Size getWinSize();

    static Size getVisibleSize();

    static int getScreenType();

    static int getScreenTypeSaved();

    static bool isLandscape();

};

