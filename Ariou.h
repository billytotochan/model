#ifndef ARIOU_H
#define ARIOU_H

#include "modelerview.h"
#include "modelerdraw.h"
#include "modelerglobals.h"
#include "modelerapp.h"
#include <cmath>

class Ariou : public ModelerView {

public:
	Ariou(int x, int y, int w, int h, char *label) : ModelerView(x, y, w, h, label) { }
	virtual void draw();
};

#endif