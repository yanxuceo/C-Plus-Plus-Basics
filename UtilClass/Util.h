#ifndef _UTIL_H_
#define _UTIL_H_

#include <string>
#include <fstream>

const float kPi = 3.14159265358979323846F;
typedef unsigned int Percent;

// helper functions
class Util {
    public:
        static std::string convertToTime ( long int input_seconds );
        static std::string getProgressBar(std::string percent);
        static std::ifstream getStream(std::string path);

        static float ConvertToRadian(float value);
        static Percent ConvertToPercent(float probability);
        static float ConvertFromPercent(Percent percent);
};

std::string Util::convertToTime (long int input_seconds)
{
    long minutes = input_seconds / 60;
    long hours = minutes / 60;
    long seconds = int(input_seconds%60);
    minutes = int(minutes%60);
    std::string result = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
    return result;
}

// constructing string for given percentage
// 50 bars is uniformly streched 0 - 100 %
// meaning: every 2% is one bar(|)
std::string Util::getProgressBar(std::string percent)
{
    std::string result = "0% ";
    int _size = 50;
    int  boundaries = (stof(percent)/100)*_size;

    for (int i = 0;i < _size;i++) {
        if (i <= boundaries) {
            result +="|";
        }
        else {
            result += " ";
        }
    }

    result += " " + percent.substr(0,5) + " /100%";
    return result;
}

// wrapper for creating streams
std::ifstream Util::getStream(std::string path)
{
    std::ifstream stream(path);
    if(!stream) {
        throw std::runtime_error("Non - existing PID");
    }
    return stream;
}

 /// Converts a given value of from degree into radian
float Util::ConvertToRadian(float value)
{
    return(kPi * value / 180.0F);
}

/// Converts [0..1] float value into [0..100]% 
Percent Util::ConvertToPercent(float probability)
{
    Percent result = 0U;
    bool is_in_range = ((probability >= 0.0F) && (probability <= 1.0F));
    if(is_in_range) {
        result = static_cast<Percent>(probability * 100.0F);
    }
    return result;
}

/// Converts [0..100]% integer value into float [0..1]
float Util::ConvertFromPercent(Percent percent)
{
    float result = 0.0F;
    bool is_in_range = (percent <= 100U);
    if (is_in_range) {
        result = static_cast<float>(percent) / 100.0F;
    }
    return result;
}


#endif
