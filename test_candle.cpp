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

// для метода contains
TEST(CandleTests, Contains) {
    Candle candle(100, 95, 90, 98);
    EXPECT_TRUE(candle.contains(92)); // внутри свечи
    EXPECT_FALSE(candle.contains(85)); // вне свечи
    EXPECT_TRUE(candle.contains(90)); // граничный случай
}