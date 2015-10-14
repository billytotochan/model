// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include "Ariou.h"
#include <FL/gl.h>
#include <complex>
#include <cmath>

#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }

    virtual void draw();
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{
	//return new SampleModel(x, y, w, h, label);
	return new Ariou(x, y, w, h, label);
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
    ModelerView::draw();

	// draw the floor
	setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	glScaled(VAL(FLOOR_SIZE), VAL(FLOOR_SIZE), VAL(FLOOR_SIZE));
	glTranslated(0, -0.05, 0);
	setDiffuseColor(COLOR_BLUE);
	drawPolygon(18, 2);
	glPopMatrix();

	setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();

	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
	glScaled(VAL(XSCALE), VAL(YSCALE), VAL(ZSCALE));

		glPushMatrix();
		glTranslated(-1.5, 0, -2);
		glScaled(3, 1, 4);
		drawBox(1,1,1);
		glPopMatrix();

		// draw cannon
		glPushMatrix();
		glRotated(VAL(ROTATE), 0.0, 1.0, 0.0);
		glRotated(-90, 1.0, 0.0, 0.0);
		drawCylinder(VAL(HEIGHT), 0.1, 0.1);

		glTranslated(0.0, 0.0, VAL(HEIGHT));
		drawCylinder(1, 1.0, 0.9);

		glTranslated(0.0, 0.0, 0.5);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(4, 0.1, 0.2);
		glPopMatrix();

	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
	controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);

	controls[XSCALE] = ModelerControl("X Scale", 0, 3, 0.1f, 1.0f);
	controls[YSCALE] = ModelerControl("Y Scale", 0, 3, 0.1f, 1.0f);
	controls[ZSCALE] = ModelerControl("Z Scale", 0, 3, 0.1f, 1.0f);

    controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);

	controls[HEAD_SIZE] = ModelerControl("Head Size", 0.8, 2, 0.1f, 1);
	controls[HEAD_ROTATE] = ModelerControl("Head Rotate", -135, 135, 1, 0);
	controls[EAR_SIZE] = ModelerControl("Ear Size", 0, 2, 0.1f, 1);

	controls[UPPER_ARM_LENGTH] = ModelerControl("Upper Arm Length", 1, 5, 0.1f, 0.8);
	controls[LEFT_UPPER_ARM_ROTATE_X] = ModelerControl("Left Upper Arm Rotate X", -90, 100, 1.0f, 80);
	controls[LEFT_UPPER_ARM_ROTATE_Y] = ModelerControl("Left Upper Arm Rotate Y", -30, 90, 1.0f, 0);
	controls[RIGHT_UPPER_ARM_ROTATE_X] = ModelerControl("Right Upper Arm Rotate X", -90, 100, 1.0f, -40);
	controls[RIGHT_UPPER_ARM_ROTATE_Y] = ModelerControl("Right Upper Arm Rotate Y", -90, 30, 1.0f, 0);

	controls[LOWER_ARM_LENGTH] = ModelerControl("Lower Arm Length", 1, 5, 0.1f, 0.8);
	controls[LEFT_LOWER_ARM_ROTATE] = ModelerControl("Left Lower Arm Rotate", 20, 180, 1.0f, 80);
	controls[RIGHT_LOWER_ARM_ROTATE] = ModelerControl("Right Lower Arm Rotate", 20, 180, 1.0f, 180);
	controls[RIGHT_HAND_ANGLE] = ModelerControl("Right Hand Angle", 0, 70, 1, 0);
	controls[LEFT_HAND_ANGLE] = ModelerControl("Left Hand Angle", 0, 70, 1, 0);

	controls[LEG_LENGTH] = ModelerControl("Leg Length", 1, 5, 0.1f, 2);
	controls[LEFT_LEG_ROTATE_X] = ModelerControl("Left Leg Rotate X", 30, 150, 1.0f, 40);
	controls[LEFT_LEG_ROTATE_Y] = ModelerControl("Left Leg Rotate Y", -80, 90, 1.0f, 0);
	controls[RIGHT_LEG_ROTATE_X] = ModelerControl("Right Leg Rotate X", 30, 150, 1.0f, 140);
	controls[RIGHT_LEG_ROTATE_Y] = ModelerControl("Right Leg Rotate Y", -90, 80, 1.0f, 0);

	controls[FLOOR_SIZE] = ModelerControl("Floor Size", 0, 10, 0.1f, 5.0f);
	controls[FLOOR_DEPTH] = ModelerControl("Floor Depth", 0, 10, 1, 4);

	controls[DETAIL_LEVEL] = ModelerControl("Detail Level", 1, 5, 1, 3);

    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}
