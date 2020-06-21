#ifndef RANDOMIZE_RUNE_COORDINATEST_TEST_H
#define RANDOMIZE_RUNE_COORDINATEST_TEST_H

#include"gtest/gtest.h"

#include "tool_bar.h"
#include "game_objects.h"

void randomize_rune_coordinates(GameObject &object,ToolBar &toolbar,std::minstd_rand &simple_rand);


TEST(PositiveTest_RandomizeRuneCoordinates,DeterminatedTypeRune){

    GameObject object;
    ToolBar toolbar;
    std::minstd_rand simple_rand;

    toolbar.randomizeCoordinates=true;


    toolbar.typeRandomedRune=0;
    randomize_rune_coordinates(object,toolbar,simple_rand);

    ASSERT_EQ(0,toolbar.typeRandomedRune);

    toolbar.typeRandomedRune=1;
    randomize_rune_coordinates(object,toolbar,simple_rand);

    ASSERT_EQ(1,toolbar.typeRandomedRune);

    toolbar.typeRandomedRune=2;
    randomize_rune_coordinates(object,toolbar,simple_rand);

    ASSERT_EQ(2,toolbar.typeRandomedRune);

    toolbar.typeRandomedRune=3;
    randomize_rune_coordinates(object,toolbar,simple_rand);

    ASSERT_EQ(3,toolbar.typeRandomedRune);

}

TEST(NegativeTest_RandomizeRuneCoordinates,UninitializedTypeRune){

    GameObject object;
    ToolBar toolbar;
    std::minstd_rand simple_rand;

    toolbar.randomizeCoordinates=true;

    toolbar.typeRandomedRune=1234;
    randomize_rune_coordinates(object,toolbar,simple_rand);

    ASSERT_EQ(-1,toolbar.typeRandomedRune);
}

#endif // RANDOMIZE_RUNE_COORDINATEST_TEST_H
