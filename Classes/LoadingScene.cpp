#include "AppMacros.h"
#include "AtlasLoader.h"
#include "LoadingScene.h"

LoadingScene::LoadingScene() {
}

LoadingScene::~LoadingScene() {
}

bool LoadingScene::init() {
    CCL( "LoadingScene::init start.." );
    if( Scene::init()) {
        return true;
    }
    else {
        return false;
    }
}

void LoadingScene::onEnter() {

    CCL( "LoadingScene::onEnter start.." );

    auto background = Sprite::create( "splash.png" );
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    background->setPosition( origin.x + visibleSize.width/2, origin.y + visibleSize.height/2 );
    this->addChild( background );

    // start ansyc method load the atlas
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    Size screenSize = glview->getFrameSize();

    director->getTextureCache()->addImageAsync( "atlas.png", CC_CALLBACK_1( LoadingScene::loadingCallBack, this ));

    CCL( "LoadingScene::onEnter done." );

}

void LoadingScene::loadingCallBack( Texture2D* texture ) {

    CCL( "LoadingScene::loadingCallBack start.." );

    AtlasLoader::getInstance()->loadAtlas( "atlas.txt", texture );

    // After load all the things, change the scene to new one
    auto scene = MainScene::create();
    float duration = 1.0f;
    TransitionScene* transition = TransitionFade::create( duration, scene );
    auto director = Director::getInstance();
    director->replaceScene( transition );

    CCL( "LoadingScene::loadingCallBack start.." );

}
