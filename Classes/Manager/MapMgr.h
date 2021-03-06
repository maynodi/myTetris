//
//  MapMgr.h
//  myTetris
//
//  Created by CD-hj0949 on 2021/03/22.
//

#pragma once

#include "cocos2d.h"

#include "Define.h"

#include "Blocks.h"

class MapMgr
{
public:
    static MapMgr* pInstance_;
    
private:
    std::vector<bool> isExisting_[MAP_HEIGHT];
    std::vector<cocos2d::Sprite*>  gridMapBlocks_[MAP_HEIGHT];
    Blocks* pCurBlocks_;
    std::list<BLOCK*> newBlockList_;      // 맵의 블록과 부딪힐 가능성있는 블록 리스트
    GAMESTATE gameState_;
    std::list<int> nextBlockTypeList_;    // nextBlockLayer에 띄울 다음에 나올 블럭 정보를 담는 리스트
    
private:
    std::list<int> nextBlockRandomList_;  // 미리 랜덤으로 5종류의 블럭을 담아 놓는 리스트, 여기서 빼서 새로운 블럭 생성예정
    std::list<int> TrapRandomList_;
    
private:
    int twistTrapCnt_;
    bool isSmogTrap_;
    
public:
    static MapMgr* getInstance();
    static void destroyInstance();
    
public:
    void init();
    
public:
    void setIsDrop(bool isDrop);
    void setCurBlocksInfo(); // 블럭 사라지면서 값을 새로 세팅해주는 함수
    void setNullCurBlocks() { pCurBlocks_ = nullptr; }
    
public:
    GAMESTATE getGameState() { return gameState_; }
    int getNextBlockType() { return nextBlockTypeList_.front(); }
    Blocks* getCurBlocks() { return pCurBlocks_; }
    std::list<int> getNextBlockTypeList() { return nextBlockTypeList_; }
    
public:
    void update();
    void addLine();
    int getMaxRowOfExistingBlocksInMap();
    cocos2d::Sprite* createItem(int col, int row);
    
public:
    void makeNewBlocks();
    int getRandom(std::list<int> list, int condition);
    void createTrap(cocos2d::Sprite* sprite, int condition);
    void move(int dir);
    void rotate(int keyPressedCnt);
    void autoMoveDown();    
    
public:
    bool checkUnderSomething(std::vector<BLOCK*> blockVec);
    void getMaxRowOfUnderBlock(int* dist);
    bool checkCanChange(float x, float y);
    
public:
    void includeGridMapBlocks(cocos2d::Sprite*);
    void checkIsExisting(cocos2d::Sprite* sprite, bool isExist); // 맵배열 중 블럭의 유무를 bool로 결정하고 배열에 표시해주는 함수
    
public:
    void reset();
    void checkLineFull(std::list<int>* list);
    void deleteLine(int row);
    void lineGoDown(int row);
    void doByTwistTrap();  // 맵이 오른쪽으로 이동하는 함수
    void doBySmogTrap();   // 안개 생기는 함정함수
    
public:
    bool checkGameOver();
    
public:
    void swapHoldBlock(int type);
    
private:
    MapMgr();
    ~MapMgr();
};


