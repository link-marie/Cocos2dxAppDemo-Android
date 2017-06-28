#pragma once
#include "cocos2d.h"


/* Kind of resolutions */
#define DESIGN_RESOLUTION_SMALL	0
#define DESIGN_RESOLUTION_MID	1
#define DESIGN_RESOLUTION_LARGE	2

/*
 * Choose a design resolution
 */
#define TARGET_DESIGN_RESOLUTION_SIZE  DESIGN_RESOLUTION_MID

typedef struct tagResource {
	cocos2d::Size sizeBackground;	// ResourceBackground
	char directory[100];
} Resource;

/*
 * Example background images for each resolution
 */
#define kBackgroundImageSmall	"bg480x320.png"
#define kBackgroundImageSmallPort	"bg320x480.png"
#define kBackgroundImageMid	"bg960x640.png"
#define kBackgroundImageMidPort	"bg640x960.png"
#define kBackgroundImageLarge	"bg1024x768.png"
#define kBackgroundImageLargePort	"bg768x1024.png"

/**
 * Resolution resources
 */
static Resource smallResource = { cocos2d::Size( 480, 320), "sd"};
static Resource mediumResource = { cocos2d::Size( 960, 640), "hd"};
static Resource largeResource = { cocos2d::Size( 1024, 768), "hd"};

/**
 * Specified screen resolution
 */
#if (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_SMALL)
	static cocos2d::Size designResolutionSize = cocos2d::Size( 480, 320);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_MID)
	static cocos2d::Size designResolutionSize = cocos2d::Size( 960, 640);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_LARGE)
	static cocos2d::Size designResolutionSize = cocos2d::Size( 1024, 768);
#else
	#error unknown target design resolution!
#endif

// The font size 24 is designed for small resolution, so we should change it to fit for current design resolution
#define TITLE_FONT_SIZE  (cocos2d::EGLView::sharedOpenGLView()->getDesignResolutionSize().width / smallResource.size.width * 24)

/**
 * Logging utility for easily log a calling method and message
 */
#define CCL(arg, ...) \
		CCLOG(\
        "%s.%d: %s", \
        __PRETTY_FUNCTION__, \
        __LINE__, \
        cocos2d::StringUtils::format(arg, ##__VA_ARGS__).c_str()\
    )
