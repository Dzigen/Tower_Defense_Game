#ifndef TAKE_RUNE_TEST_H
#define TAKE_RUNE_TEST_H
#include "gtest/gtest.h"
#include "take_rune.h"

void take_rune(GameObject &object,ToolBar &toolbar,MenuBar &menubar);

TEST(PositiveTest_TakeRune,DeterminatedTypeRune){

    GameObject object;
    ToolBar toolbar;
    MenuBar menubar;

    object.rune.hp_base.sprite.setPosition(object.hero.sprite.getPosition().x+(object.hero.w*2),object.hero.sprite.getPosition().y);
    toolbar.typeRandomedRune=0;
    take_rune(object,toolbar,menubar);

    ASSERT_EQ(0,toolbar.typeRandomedRune);

    object.rune.hp_hero.sprite.setPosition(object.hero.sprite.getPosition().x+(object.hero.w*2),object.hero.sprite.getPosition().y);
    toolbar.typeRandomedRune=1;
    take_rune(object,toolbar,menubar);

    ASSERT_EQ(1,toolbar.typeRandomedRune);

    object.rune.plus_damage.sprite.setPosition(object.hero.sprite.getPosition().x+(object.hero.w*2),object.hero.sprite.getPosition().y);
    toolbar.typeRandomedRune=2;
    take_rune(object,toolbar,menubar);

    ASSERT_EQ(2,toolbar.typeRandomedRune);

    object.rune.coin.sprite.setPosition(object.hero.sprite.getPosition().x+(object.hero.w*2),object.hero.sprite.getPosition().y);
    toolbar.typeRandomedRune=3;
    take_rune(object,toolbar,menubar);

    ASSERT_EQ(3,toolbar.typeRandomedRune);
}

TEST(PositiveTest_TakeRune,EffectOfRune){

}

TEST(NegativeTest_TakeRune,UnititilizedTypeRune){

}

#endif // TAKE_RUNE_TEST_H
