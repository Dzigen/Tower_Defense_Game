#include <gtest/gtest.h>

#include "update_spawn_rune_test.h"
#include "move_hero_test.h"
#include "randomize_rune_coordinates_test.h"
#include "take_rune_test.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
