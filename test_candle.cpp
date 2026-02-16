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

// для метода full_size
TEST(CandleTests, FullSize) {
    Candle candle1(100, 90, 95, 98);
    EXPECT_DOUBLE_EQ(candle1.full_size(), 5.0); // |90 - 95| = 5

    Candle candle2(100, 100, 100, 100);
    EXPECT_DOUBLE_EQ(candle2.full_size(), 0.0); // |100 - 100| = 0

    Candle candle3(100, 95, 90, 98);
    EXPECT_DOUBLE_EQ(candle3.full_size(), 5.0); // |95 - 90| = 5 граничный случай
}