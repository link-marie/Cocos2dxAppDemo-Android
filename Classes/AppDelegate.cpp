#include "AppMacros.h"
#include "Utl.h"
#include "AppDelegate.h"
#include "LoadingScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {
}

AppDelegate::~AppDelegate() {
}

void AppDelegate::initGLContextAttrs() {
    // OpenGL context attributes
    int redBits = 8;
    int greenBits = 8;
    int blueBits = 8;
    int alphaBits = 8;
    int depthBits = 24;
    int stencilBits = 8;
    GLContextAttrs glContextAttrs = {redBits, greenBits, blueBits, alphaBits, depthBits, stencilBits};
    GLView::setGLContextAttrs( glContextAttrs );
}

/**
 * package manager to install more packages
 */
static int register_all_packages() {
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {

    CCL( "start.." );

    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if( !glview ) {
        glview = GLViewImpl::create( "CocosApp" );
        director->setOpenGLView( glview );
    }

    // turn on display FPS
    director->setDisplayStats( true );
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval( 1.0f/60 );

    initObj();

    register_all_packages();

    // create a scene. it's an autorelease object
    auto scene = LoadingScene::create();
    /* Enable following scene and disable above scene
     * if you want to execute much simpler demo
     */
//    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene( scene );

    CCL( "done." );

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}


void AppDelegate::initObj() {

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    Size frameSize = glview->getFrameSize();
    bool land = Utl::isLandscape();

    float dw = designResolutionSize.width;
    float dh = designResolutionSize.height;
    if( land == false ) {
        dw = designResolutionSize.height;
        dh = designResolutionSize.width;
    }

    /*
     * Choose resolution policy suitable for your app
     */
//    ResolutionPolicy poliicy = ResolutionPolicy::EXACT_FIT;
//    ResolutionPolicy poliicy = ResolutionPolicy::NO_BORDER;
//    ResolutionPolicy poliicy = ResolutionPolicy::SHOW_ALL;
//    ResolutionPolicy poliicy = ResolutionPolicy::FIXED_HEIGHT;
//    ResolutionPolicy poliicy = ResolutionPolicy::FIXED_WIDTH;
//    ResolutionPolicy poliicy = ResolutionPolicy::UNKNOWN;
    ResolutionPolicy poliicy = ResolutionPolicy::SHOW_ALL;
    glview->setDesignResolutionSize( dw, dh, poliicy );

    Size designResolution = glview->getDesignResolutionSize();
    ResolutionPolicy resolutionPolicy = glview->getResolutionPolicy();

    int sType = Utl::getScreenType();
    Resource res;
    if( sType == DESIGN_RESOLUTION_LARGE ) {
        res = largeResource;
    }
    else if( sType == DESIGN_RESOLUTION_MID ) {
        res = mediumResource;
    }
    else {
        res = smallResource;
    }
    const char*resDir = res.directory;

    float scaleFactor = 1.0f;
    float scaleh = res.sizeBackground.height/designResolutionSize.height;
    float scalew = res.sizeBackground.width/designResolutionSize.width;
    scaleFactor = MIN( scaleh, scalew );
    director->setContentScaleFactor( scaleFactor );

    std::vector<std::string> searchPath;
    searchPath.push_back( resDir );
    searchPath.push_back( "images" );
    searchPath.push_back( "fonts" );
//    FileUtils::getInstance()->setSearchResolutionsOrder( searchPath);
    FileUtils::getInstance()->setSearchPaths( searchPath );


    CCL( "Res=%d land=%d dir=%s frame=%.1f,%.1f scaleFactor=%.3f designResolution=%.1f,%.1f resolutionPolicy=%d"
         , TARGET_DESIGN_RESOLUTION_SIZE
         , (land ? 1 : 0)
         , resDir
         , frameSize.width
         , frameSize.height
         , scaleFactor
         , designResolution.width
         , designResolution.height
         , (int)resolutionPolicy );
}
