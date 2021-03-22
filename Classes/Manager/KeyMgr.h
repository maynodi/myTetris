//
//  KeyMgr.h
//  myTetris
//
//  Created by CD-hj0949 on 2021/03/22.
//

#pragma once

#include "cocos2d.h"

#include "Define.h"

class KeyMgr : public cocos2d::Node
{
public:
    static KeyMgr* pInstance_;

private:
    cocos2d::EventListenerKeyboard* pListner_;
    std::map<KEY, bool> keyMap_;
    
public:
    static KeyMgr* getInstance();
    static void destroyInstance();
    
public:
    virtual bool init() override;
    
public:
    bool getIsPressed(KEY keyCode) { return keyMap_[keyCode]; }
    
public:
    void onKeyPressed(KEY keyCode, cocos2d::Event* event);
    void onKeyReleased(KEY keyCode, cocos2d::Event* event);
    
private:
    KeyMgr();
    ~KeyMgr();
};


