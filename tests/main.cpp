#include <gtest/gtest.h>

#include "effect_of_the_rune_test.h"
#include "game_process_test.h"
#include "move_hero_test.h"
#include "pause_menu_test.h"
#include "randomize_rune_coordinatest_test.h"
#include "take_rune_test.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
