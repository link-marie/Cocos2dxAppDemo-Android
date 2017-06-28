
#include "Utl.h"

int Utl::screenType;

Utl::Utl() {
}

Utl::~Utl() {
}

bool Utl::isLandscape() {
    Size s = Director::getInstance()->getWinSize();
    if( s.width > s.height ) {
        return true;
    }
    return false;
}

/**
 * returns the design resolution,
 * but as you carefully noticed in the case of use FIXED_HEIGHT/FIXED_WIDTH,
 * the design resolution is recalculated so to have the same aspect ratio as the screen resolution
 */
Size Utl::getWinSize() {
    Size s = Director::getInstance()->getWinSize();
    return s;
}

/*
 * returns the part of the design resolution
 * which will be visible after the transformation
 * the Design resolution -> to the Screen resolution.
 */
Size Utl::getVisibleSize() {
    Size s = Director::getInstance()->getVisibleSize();
    return s;
}

/**
  returns the accessible part of your screen resolution
  (and always when mentioned the screen resolution,
  it is meant available screen resolution)
 */
Size Utl::getFrameSize() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    Size frameSize = glview->getFrameSize();
    return frameSize;
}

int Utl::getScreenType() {
    Size sSize = Director::getInstance()->getWinSize();

    if( isLandscape() == false ) {
        float h = sSize.height;
        float w = sSize.width;
        sSize = Size( h, w );
    }

    int type = DESIGN_RESOLUTION_SMALL;
    if( sSize.height >= largeResource.sizeBackground.height ) {
        type = DESIGN_RESOLUTION_LARGE;
    }
    else if( sSize.height >= mediumResource.sizeBackground.height ) {
        type = DESIGN_RESOLUTION_MID;
    }

    screenType = type;

    return type;
}

int Utl::getScreenTypeSaved() {
    return screenType;
}
