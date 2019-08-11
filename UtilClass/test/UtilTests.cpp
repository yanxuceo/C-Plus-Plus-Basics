#include <gtest/gtest.h>
#include <iostream>
#include "Util.h"


TEST(UtilTests, GetLinesTest)
{
    Util util;

    std::vector<std::string> input;
    input = util.getLines("input.txt");

    EXPECT_EQ(input.at(0), "1,1,0,0,0,0,");
}


TEST(UtilTests, UtilitiesTest)
{
    Util util;
    Percent result = util.ConvertToPercent(0.25);

    EXPECT_EQ(result, 25);
}