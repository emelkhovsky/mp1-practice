#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_
#include "iostream"
#include "string"
using namespace std;
class exceptions {
private:
	string e;
public:
	exceptions(string e1) :e(e1) {};
	void print() {
		cout << "Error!" << e << endl;
	}
};
#endif;