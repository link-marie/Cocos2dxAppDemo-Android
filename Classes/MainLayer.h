#pragma once

#include "cocos2d.h"
#include "Common.h"

USING_NS_CC;

class MainLayer : public cocos2d::LayerColor {

private:
    const char* __CLASS__ = "MainLayer";
    Size _screenSize;
    Label* label1;
    Label* labelS;

    void onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCord, cocos2d::Event* event );

    void initScoreDisplay();
    void initEvents();
    void initCloseButton();
    void initBackground();

    void testJni();

    void createLabel( const char* );
    void setLabelText( const char* format, ... );
    void createLabelSys( const char* );
    void update( float dt );

    Sprite* getBackground();

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // a selector callback
    void menuCloseCallback( cocos2d::Ref* pSender );

    bool onTouchBegan( cocos2d::Touch* touch, cocos2d::Event* event );

    void onTouchMoved( cocos2d::Touch* touch, cocos2d::Event* event );

    void onTouchEnded( cocos2d::Touch* touch, cocos2d::Event* event );

    void onTouchCancelled( cocos2d::Touch* touch, cocos2d::Event* event );

    // implement the "static create()" method manually
    CREATE_FUNC( MainLayer );
};

