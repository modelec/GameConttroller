#pragma once
#include <string>
#include <vector>

#define PI 3.14159265358979323846

namespace Utils {
    inline bool startWith(const std::string& str, const std::string& start)
    {
        return str.rfind(start, 0) == 0;
    }

    inline bool endsWith(const std::string& str, const std::string& end)
    {
        if (str.length() >= end.length())
        {
            return (0 == str.compare(str.length() - end.length(), end.length(), end));
        }
        return false;
    }

    inline bool contains(const std::string& str, const std::string& sub)
    {
        return str.find(sub) != std::string::npos;
    }

    inline std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
        std::vector<std::string> tokens;
        size_t prev = 0, pos = 0;
        do
        {
            pos = str.find(delimiter, prev);
            if (pos == std::string::npos) pos = str.length();
            std::string token = str.substr(prev, pos - prev);
            if (!token.empty()) tokens.push_back(token);
            prev = pos + delimiter.length();
        } while (pos < str.length() && prev < str.length());
        return tokens;
    }

    template<typename T>
    T mapValue(T v, T v_min, T v_max, T v_min_prime, T v_max_prime) {
        return v_min_prime + (((v - v_min) * (v_max_prime - v_min_prime)) / (v_max - v_min));
    }
}