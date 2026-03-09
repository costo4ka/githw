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

// для метода body_size
TEST(CandleTests, BodySize) {
    Candle candle1(100, 95, 90, 98);
    EXPECT_DOUBLE_EQ(candle1.body_size(), 2.0); // |100 - 98| = 2

    Candle candle2(100, 100, 100, 100); // свеча без тела
    EXPECT_DOUBLE_EQ(candle2.body_size(), 0.0); // |100 - 100| = 0

    Candle candle3(90, 95, 85, 100);
    EXPECT_DOUBLE_EQ(candle3.body_size(), 10.0); // |100 - 90| = 10
}

// для метода is_green
TEST(CandleTests, IsGreen) {
    Candle candle1(100, 95, 90, 98);
    EXPECT_FALSE(candle1.is_green()); // close < open

    Candle candle2(90, 95, 85, 100);
    EXPECT_TRUE(candle2.is_green()); // close > open

    Candle candle3(100, 100, 100, 100); // свеча без изменения цены
    EXPECT_FALSE(candle3.is_green()); // close == open
}

// для метода is_red
TEST(CandleTests, IsRed) {
    Candle candle1(100, 95, 90, 98);
    EXPECT_TRUE(candle1.is_red()); // close < open

    Candle candle2(90, 95, 85, 100);
    EXPECT_FALSE(candle2.is_red()); // close > open

    Candle candle3(100, 100, 100, 100); // свеча без изменения цены
    EXPECT_FALSE(candle3.is_red()); // close == open
}

// для метода upper_shadow_size
TEST(CandleTests, UpperShadowSize) {
    // зелёная свеча: open=90, high=110, low=85, close=105
    // верхняя тень = high - max(open, close) = 110 - 105 = 5
    Candle candle1(90, 110, 85, 105);
    EXPECT_DOUBLE_EQ(candle1.upper_shadow_size(), 5.0);

    // красная свеча: open=105, high=110, low=85, close=90
    // верхняя тень = 110 - 105 = 5
    Candle candle2(105, 110, 85, 90);
    EXPECT_DOUBLE_EQ(candle2.upper_shadow_size(), 5.0);

    // свеча без верхней тени
    Candle candle3(90, 100, 85, 100);
    EXPECT_DOUBLE_EQ(candle3.upper_shadow_size(), 0.0);
}

// для метода lower_shadow_size
TEST(CandleTests, LowerShadowSize) {
    // зелёная свеча: open=90, high=110, low=85, close=105
    // нижняя тень = min(open, close) - low = 90 - 85 = 5
    Candle candle1(90, 110, 85, 105);
    EXPECT_DOUBLE_EQ(candle1.lower_shadow_size(), 5.0);

    // красная свеча: open=105, high=110, low=85, close=90
    // нижняя тень = 90 - 85 = 5
    Candle candle2(105, 110, 85, 90);
    EXPECT_DOUBLE_EQ(candle2.lower_shadow_size(), 5.0);

    // свеча без нижней тени
    Candle candle3(85, 110, 85, 100);
    EXPECT_DOUBLE_EQ(candle3.lower_shadow_size(), 0.0);
}