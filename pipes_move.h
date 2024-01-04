#pragma once

#include"pipes.h"
using namespace std;

class obstacle2 : public obstacle {

private:

	bool type = false;
public:

	void moveY(int add);
	void setType();
	bool getType();
};
