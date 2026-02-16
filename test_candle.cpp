#include "candle.h"
#include <gtest/gtest.h>

// для метода body_contains
TEST(CandleTests, BodyContains) {
    Candle candle(100, 90, 95, 98);
    // свеча красная, тело [98, 100]
    EXPECT_FALSE(candle.body_contains(92)); // 92 вне тела
    EXPECT_TRUE(candle.body_contains(98));  // 98 на границе тела
    EXPECT_FALSE(candle.body_contains(95)); // 95 вне тела
}

