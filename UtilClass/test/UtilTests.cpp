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

TEST(UtilTests, OSParseTest)
{
    Util util;
    
    std::string value = util.OperatingSystem(LinuxPath::kOSPath);
    EXPECT_EQ(value, "Ubuntu 16.04.3 LTS");
}