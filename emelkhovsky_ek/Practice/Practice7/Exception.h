#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <iostream>
#include <string>
using namespace std;

struct error : std::exception {
    const char* what() const noexcept { return "Error!\n"; }
};
#endif