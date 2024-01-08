#pragma once
#include"pipes.h"
using namespace std;

class MovePipe : public Pipe {
private:
	bool moveType = false;
public:
	void moveY(int add);
	void setType();
	bool getType();
};
