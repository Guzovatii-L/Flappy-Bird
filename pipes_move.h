#pragma once

#include"pipes.h"

class obstacle2 : public obstacle {

private:

	bool type = false;
public:

	void moveY(int add);
	void setType();
	bool getType();
};
