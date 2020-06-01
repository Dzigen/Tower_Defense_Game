#ifndef MOVE_HERO_TEST_H
#define MOVE_HERO_TEST_H

#include "gtest/gtest.h"
#include "game_objects.h"
#include "tool_bar.h"


void move_hero(GameObject &object ,float time,int flag);

TEST(PositiveTest_MoveHero,CheckMoving){
    GameObject object;
    float time=45;
    int flag;

    flag=0;
    move_hero(object,time,flag);
    ASSERT_EQ(200,object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ(191,object.hero.sprite.getPosition().y);

    flag=1;
    move_hero(object,time,flag);
    ASSERT_EQ(209,object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ(191,object.hero.sprite.getPosition().y);

    flag=2;
    move_hero(object,time,flag);
    ASSERT_EQ(209,object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ(200,object.hero.sprite.getPosition().y);

    flag=3;
    move_hero(object,time,flag);
    ASSERT_EQ(200,object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ(200,object.hero.sprite.getPosition().y);
}

TEST(NegetiveTest_MoveHero,TryCrossMapBorder){
    GameObject object;
    float time=45;
    int flag;

    flag=0;
    object.hero.sprite.setPosition(100,(55+5));
    move_hero(object,time,flag);
    ASSERT_EQ(100,object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ(55,object.hero.sprite.getPosition().y);

    flag=1;
    object.hero.sprite.setPosition(((1200-object.hero.w)-5),100);
    move_hero(object,time,flag);
    ASSERT_EQ((1200-object.hero.w),object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ(100,object.hero.sprite.getPosition().y);

    flag=2;
    object.hero.sprite.setPosition(100,(((object.map.h+55)-object.hero.h)-5));
    move_hero(object,time,flag);
    ASSERT_EQ(100,object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ(((object.map.h+55)-object.hero.h),object.hero.sprite.getPosition().y);

    flag=3;
    object.hero.sprite.setPosition(3,100);
    move_hero(object,time,flag);
    ASSERT_EQ(0,object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ(100,object.hero.sprite.getPosition().y);


}

TEST(NegativeTest_MoveHero,TryMoveAcrossBase){
    ToolBar toolbar;
    GameObject object;
    float time=45;
    int flag;

    flag=0;
    object.hero.sprite.setPosition((object.base.box_x+(object.base.w/2)),((object.base.box_y+object.base.h)+5));
    move_hero(object,time,flag);
    ASSERT_EQ((object.base.box_x+(object.base.w/2)),object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ((object.base.box_y+object.base.h),object.hero.sprite.getPosition().y);

    flag=1;
    object.hero.sprite.setPosition(((object.base.box_x-object.hero.w)-5),(object.base.box_y+(object.base.h/2)));
    move_hero(object,time,flag);
    ASSERT_EQ((object.base.box_x-object.hero.w),object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ((object.base.box_y+(object.base.h/2)),object.hero.sprite.getPosition().y);

    flag=2;
    object.hero.sprite.setPosition((object.base.box_x+(object.base.w/2)),((object.base.box_y-object.hero.h)-5));
    move_hero(object,time,flag);
    ASSERT_EQ((object.base.box_x+(object.base.w/2)),object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ((object.base.box_y-object.hero.h),object.hero.sprite.getPosition().y);

    flag=3;
    object.hero.sprite.setPosition(((object.base.box_x+object.base.w)+5),(object.base.box_y+(object.base.h/2)));
    move_hero(object,time,flag);
    ASSERT_EQ((object.base.box_x+object.base.w),object.hero.sprite.getPosition().x);
    ASSERT_FLOAT_EQ((object.base.box_y+(object.base.h/2)),object.hero.sprite.getPosition().y);
}


#endif // MOVE_HERO_TEST_H
