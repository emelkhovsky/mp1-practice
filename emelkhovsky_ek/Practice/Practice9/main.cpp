#include <iostream>
#include "to_do_list.h"
#include "task.h"
#include "date.h"
#include "time.h"
#include <conio.h>
using namespace std;

int main(){
    todolist list;
    date dat;
    try {
        cin >> dat;
    }
    catch (errordate) {
        std::cout << "Not correct date!";
    }
    try {
        list.read("list_of_tasks.txt");
    }
    catch (notcorrecttype) {
        std::cout << "Not correct type!";
    }
    try{
        list.print(dat);
    }
    catch (noplans){
        std::cout << "Not any plans!";
    }
}