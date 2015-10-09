#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{ 
	XPOS, YPOS, ZPOS, HEIGHT, ROTATE, 
	XSCALE, YSCALE, ZSCALE,
	FLOOR_SIZE, FLOOR_DEPTH,

	HEAD_SIZE, HEAD_ROTATE,
	EAR_SIZE,

	UPPER_ARM_LENGTH, 
	LEFT_UPPER_ARM_ROTATE_X, LEFT_UPPER_ARM_ROTATE_Y,
	RIGHT_UPPER_ARM_ROTATE_X, RIGHT_UPPER_ARM_ROTATE_Y,
	LOWER_ARM_LENGTH, 
	LEFT_LOWER_ARM_ROTATE, RIGHT_LOWER_ARM_ROTATE,
	LEFT_HAND_ANGLE, RIGHT_HAND_ANGLE,
	
	LEG_LENGTH, 
	LEFT_LEG_ROTATE_X, LEFT_LEG_ROTATE_Y,
	RIGHT_LEG_ROTATE_X, RIGHT_LEG_ROTATE_Y,

	FEET_SIZE,

	TORUS_R, TORUS_r,

	DETAIL_LEVEL,
	NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_GRAY		0.8f, 0.8f, 0.8f
#define COLOR_BLACK		0.0f, 0.0f, 0.0f
#define COLOR_WHITE		1.0f, 1.0f, 1.0f
#define COLOR_ORANGE	1.0f, 0.73f, 0.0f
#define COLOR_YELLOW	1.0f, 1.0f, 0.0f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))
#define MAX(x) (ModelerApplication::Instance()->GetMaxControlValue(x))
#define MIN(x) (ModelerApplication::Instance()->GetMinControlValue(x))
#define SETVAL(x, v) (ModelerApplication::Instance()->SetControlValue(x, v))

#endif