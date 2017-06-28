#include "MainLayer.h"
#include "Utl.h"
#include "AtlasLoader.h"
#include "Number.h"
#include "JniIf.h"

Scene* MainLayer::createScene() {
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = MainLayer::create();
    // add layer as a child to scene
    scene->addChild( layer );
    // return the scene
    return scene;
}

bool MainLayer::init() {
    if( !Layer::init()) {
        return false;
    }

    /*
     * Set layer background color
     */
    if( !LayerColor::initWithColor( Color4B( 168, 168, 168, 255 ))) {
        return false;
    }

/*
	this->setIgnoreAnchorPointForPosition( false);
	this->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	this->setPosition(Vec2::ZERO);
*/
    _screenSize = Director::getInstance()->getWinSize();

    initCloseButton();

    createLabel( this->__CLASS__ );
    createLabelSys( "日本語も" );

    Sprite* sprite = Sprite::createWithSpriteFrame( AtlasLoader::getInstance()->getSpriteFrameByName( "CocosTitle1" ));
    sprite->setPosition( Vec2( _screenSize.width*0.6f, _screenSize.height*0.3f ));
    this->addChild( sprite, kZOrder::zMid );

    initScoreDisplay();

    initBackground();

    initEvents();

    testJni();

    //create main loop
    this->schedule( schedule_selector( MainLayer::update ));

    Size sFrame = Utl::getFrameSize();
    Size sVisible = Director::getInstance()->getVisibleSize();
    setLabelText( "type=%d sWin=%.0f,%.0f\nsFrame=%.0f,%.0f\nsVisible=%.0f,%.0f"
                  , Utl::getScreenTypeSaved()
                  , _screenSize.width
                  , _screenSize.height
                  , sFrame.width
                  , sFrame.height
                  , sVisible.width
                  , sVisible.height );

    return true;
}

void MainLayer::initBackground() {
    Sprite* background = getBackground();
    background->setPosition( _screenSize.width*0.5f, _screenSize.height*0.5f );
    this->addChild( background, kZOrder::zBackground );
}

void MainLayer::createLabel( const char* msg ) {
    // create and initialize a label
    int sizeFont = 30;
    TTFConfig ttfConfig( "Arial.ttf", sizeFont, GlyphCollection::DYNAMIC );
    label1 = Label::createWithTTF( ttfConfig, msg );
//    label1->setPosition(Vec2( _screenSize.width/2, _screenSize.height - label->getContentSize().height));
    label1->setPosition( _screenSize.width*0.5f, _screenSize.height*0.5f );
//    label1->setPosition(Vec2( 0, 0));
    this->addChild( label1, kZOrder::zTest );
}

void MainLayer::setLabelText( const char* format, ... ) {

    int maxLen = 1024;
    std::string str;

    va_list ap;
    va_start( ap, format );

    char* buf = (char*)malloc( maxLen );
    if( buf != nullptr ) {
        vsnprintf( buf, maxLen, format, ap );
        str = buf;
        free( buf );
    }
    va_end( ap );

    label1->setString( str.c_str());
}

void MainLayer::createLabelSys( const char* msg ) {
    auto labelA = Label::createWithSystemFont( msg, "Arial.ttf", 24 );
    auto size = labelA->getContentSize();
    labelA->setDimensions( size.width, size.height );
    labelA->setPosition( _screenSize.width*0.5f, _screenSize.height*0.8f );
    addChild( labelA, kZOrder::zTest );
}

void MainLayer::initCloseButton() {
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create( "CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1( MainLayer::menuCloseCallback, this ));

    float x = _screenSize.width - closeItem->getContentSize().width/2;
    float y = closeItem->getContentSize().height/2;
    closeItem->setPosition( Vec2( x, y ));

    // create menu, it's an autorelease object
    auto menu = Menu::create( closeItem, nullptr );
    menu->setPosition( Vec2::ZERO );
    this->addChild( menu, kZOrder::zMenu );
}


void MainLayer::initEvents() {
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2( MainLayer::onTouchBegan, this );
    listener->onTouchMoved = CC_CALLBACK_2( MainLayer::onTouchMoved, this );
    listener->onTouchEnded = CC_CALLBACK_2( MainLayer::onTouchEnded, this );
    listener->onTouchCancelled = CC_CALLBACK_2( MainLayer::onTouchCancelled, this );
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
//    this->setSwallowsTouches( true);
//    Layer::setKeypadEnabled( true);


    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyReleased = CC_CALLBACK_2( MainLayer::onKeyReleased, this );
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( keyboardListener, this );

}

void MainLayer::initScoreDisplay() {
    Number::getInstance()->loadNumber( NUMBER_SCORE.c_str(), "num_%02d" );
    Sprite* scoreDisp = Sprite::createWithSpriteFrame( AtlasLoader::getInstance()->getSpriteFrameByName( "blank" ));
    Node* val = (Node*)Number::getInstance()->convert( NUMBER_SCORE.c_str(), 1234, Gravity::GRAVITY_CENTER );
    scoreDisp->addChild( val );
    scoreDisp->setPosition( Vec2( _screenSize.width*0.5f, _screenSize.height*0.5f ));
    this->addChild( scoreDisp, kZOrder::zBackground );
}

void MainLayer::testJni() {
    CCL( "JNI testString=%s", testString());
    CCL( "JNI testInt1=%d", testInt1());
    CCL( "JNI testInt2=%d", testInt2( 5));
    CCL( "JNI testFloat1=%f", testFloat1());
    CCL( "JNI testFloat2=%f", testFloat2( 5));
    CCL( "JNI testDouble2=%f", testDouble2( 5));
}

bool MainLayer::onTouchBegan( cocos2d::Touch* touch, cocos2d::Event* event ) {
    return true;
}

void MainLayer::onTouchMoved( cocos2d::Touch* touch, cocos2d::Event* event ) {

}

void MainLayer::onTouchEnded( cocos2d::Touch* touch, cocos2d::Event* event ) {

}

void MainLayer::onTouchCancelled( cocos2d::Touch* touch, cocos2d::Event* event ) {

}

void MainLayer::update( float dt ) {

}

void MainLayer::menuCloseCallback( Ref* pSender ) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MainLayer::onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event ) {
    if( keyCode == EventKeyboard::KeyCode::KEY_ESCAPE ) {
        Director::getInstance()->end();
    }
}

/**
 * Get background imange depends on specifid screen resolution
 * @return
 */
Sprite* MainLayer::getBackground() {
    int sType = TARGET_DESIGN_RESOLUTION_SIZE;
    bool land = Utl::isLandscape();
    const char* img;
    if( sType == DESIGN_RESOLUTION_LARGE ) {
        if( land ) {
            img = kBackgroundImageLarge;
        }
        else {
            img = kBackgroundImageLargePort;
        }
    }
    else if( sType == DESIGN_RESOLUTION_MID ) {
        if( land ) {
            img = kBackgroundImageMid;
        }
        else {
            img = kBackgroundImageMidPort;
        }
    }
    else {
        if( land ) {
            img = kBackgroundImageSmall;
        }
        else {
            img = kBackgroundImageSmallPort;
        }
    }
    Sprite* background = Sprite::create( std::string( img ));
    return background;
}
