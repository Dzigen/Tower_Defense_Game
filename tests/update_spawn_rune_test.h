#ifndef UPDATE_SPAWN_RUNE_TEST_H
#define UPDATE_SPAWN_RUNE_TEST_H

#include"gtest/gtest.h"
#include "update_spawn_rune.h"
#include <random>

void update_spawn_rune(GameObject &object,ToolBar &toolbar,float &runeUPDATEtime,float &time,std::minstd_rand &simple_rand);

TEST(PositiveTest_UpdateSpawnRune,ChoosingCoordinatesRune){
    GameObject object;
    ToolBar toolbar;

    float runeUPDATEtime=0;
    float time=0;
    std::minstd_rand simple_rand;

    toolbar.randomizeCoordinates=true;
    update_spawn_rune(object,toolbar,runeUPDATEtime,time,simple_rand);

    ASSERT_FALSE(toolbar.randomizeCoordinates);

}


TEST(PositiveTest_UpdateSpawnRune,UpdateRuneFrame){
    GameObject object;
    ToolBar toolbar;

    std::minstd_rand simple_rand;
    toolbar.randomizeCoordinates=false;
    float runeUPDATEtime=0;
    float time=260;

    toolbar.typeRandomedRune=0;

    update_spawn_rune(object,toolbar,runeUPDATEtime,time,simple_rand);
    ASSERT_EQ(1,object.rune.hp_base.current_frame);

    toolbar.typeRandomedRune=1;

    update_spawn_rune(object,toolbar,runeUPDATEtime,time,simple_rand);
    ASSERT_EQ(1,object.rune.hp_base.current_frame);

    toolbar.typeRandomedRune=2;

    update_spawn_rune(object,toolbar,runeUPDATEtime,time,simple_rand);
    ASSERT_EQ(1,object.rune.hp_base.current_frame);

    toolbar.typeRandomedRune=3;

    update_spawn_rune(object,toolbar,runeUPDATEtime,time,simple_rand);
    ASSERT_EQ(1,object.rune.hp_base.current_frame);
}


TEST(NegativeTest_UpdateSpawnRune,UnititilizedTypeRune){
    GameObject object;
    ToolBar toolbar;

    std::minstd_rand simple_rand;
    toolbar.randomizeCoordinates=false;
    float runeUPDATEtime=0;
    float time=260;

    toolbar.typeRandomedRune=1234;

    update_spawn_rune(object,toolbar,runeUPDATEtime,time,simple_rand);
    ASSERT_EQ(-1,toolbar.typeRandomedRune);
}


#endif // UPDATE_SPAWN_RUNE_TEST_H
