#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <FL/gl.h>
#include "modelerglobals.h"

class LS
{
private:
	float angle;

	std::string init;
	int depth;
public:
	LS(std::string i, int d, int a);
	void expand(int depth);

	void rotate(bool left);
	void drawLine();
	void drawLS();
	~LS();
};
