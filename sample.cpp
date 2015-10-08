// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
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
    return new SampleModel(x,y,w,h,label); 
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
	drawSierpinskiTriangle(0, 0, 1,
		0.86602540378443864676372317075293618347140262690519, 0, -0.5,
		-0.86602540378443864676372317075293618347140262690519, 0, -0.5,
		VAL(FLOOR_DEPTH)
	);

	glTranslated(0, -0.05, 0);
	setDiffuseColor(COLOR_BLUE);
	drawPolygon(18, 2);
	glPopMatrix();

	// draw the sample model
	/*GLfloat maambient[] = { 0.79225f, 0.79225f, 0.79225f, 1.0f };
	GLfloat madiffuse[] = { 0.50754f, 0.50754f, 0.50754f, 1.0f };
	GLfloat maspecular[] = { 0.508273f, 0.508273f, 0.508273f, 0.508273f };
	GLfloat mashiniess = 51.2f;
	GLfloat maemi[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, maambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, madiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, maspecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mashiniess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, maemi);*/

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

	controls[FLOOR_SIZE] = ModelerControl("Floor Size", 0, 10, 0.1f, 5.0f);
	controls[FLOOR_DEPTH] = ModelerControl("Floor Depth", 0, 10, 1, 4);

	controls[DETAIL_LEVEL] = ModelerControl("Detail Level", 1, 5, 1, 2);

    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}