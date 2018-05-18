#ifndef circular_list_complex_hpp
#define circular_list_complex_hpp

#include "circular_list.hpp"
#include <iostream>
#include <string>
#include <cmath>

void complex_list_cli();

struct complex {
    int a;
    int b;
    
    complex() {};
    complex(int _a, int _b) {
        a = _a;
        b = _b;
    }
    
    double length() {
        return sqrt(a*a + b*b);
    }
};

#endif /* circular_list_complex_hpp */
