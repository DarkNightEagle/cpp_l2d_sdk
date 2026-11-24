#pragma once
template <class T>
struct Range 
{
    T min;
    T max;
    T distance() {
        return max-min;
    }
}