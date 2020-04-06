#ifndef __PC_H
#define __PC_H

#define WHITE true
#define BLACK false

#include <iostream>
#include <string.h>

using namespace std;

class PC {
public:
	PC(bool color, int number);
	PC(const PC& other);
	~PC();

private:
	bool color;
	int number;
	
};
#endif