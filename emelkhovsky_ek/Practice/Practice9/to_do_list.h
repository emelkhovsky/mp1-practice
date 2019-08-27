#ifndef _TO_DO_LIST_H_
#define _TO_DO_LIST_H_
#include <string>
#include "date.h"
#include "task.h"

using namespace std;

class todolist
{
    task **tasks;
    int count;
public:
    todolist();
    ~todolist();
    void read(const string namefile);
    void print(date dat);
};
class notopenfile : std::exception {
    const std::string what_str = "File is not open!";
public:
    const char* what() const;
};
class notcorrecttype : std::exception {
    const std::string what_str = "Not correct type!";
public:
    const char* what() const;
};
class noplans : std::exception {
    const std::string what_str = "Not any plans!";
public:
    const char* what() const;
};
#endif