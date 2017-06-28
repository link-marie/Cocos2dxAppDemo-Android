/*
 * MainScene.cpp
 *
 */

#include "MainScene.h"
#include "MainLayer.h"

bool MainScene::init() {

    if( Scene::initWithPhysics()) {

        MainLayer* mainLayer = MainLayer::create();
        if( mainLayer ) {
            this->addChild( mainLayer );
            //		CCLOG( "%s::%s %d", this->__CLASS__, __FUNCTION__, mainLayer->getID());
        }
        else {
            return false;
        }
        return true;
    }
    else {
        return false;
    }
}
