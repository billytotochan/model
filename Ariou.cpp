#include "Ariou.h"
#include "modelerapp.h"

void Ariou::draw() {
	ModelerView::draw();

	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_BLUE);
	glPushMatrix();
	glScaled(VAL(FLOOR_SIZE), VAL(FLOOR_SIZE), VAL(FLOOR_SIZE));
	drawSierpinskiTriangle(0, 0, 1,
		0.86602540378443864676372317075293618347140262690519, 0, -0.5,
		-0.86602540378443864676372317075293618347140262690519, 0, -0.5,
		VAL(FLOOR_DEPTH));

	glTranslated(0, -0.05, 0);
	setDiffuseColor(COLOR_RED);
	drawPolygon(7, 2);
	glPopMatrix();


	glPushMatrix();
		/*
		GLfloat maambient[] = { 0.79225f, 0.79225f, 0.79225f, 1.0f };
		GLfloat madiffuse[] = { 0.50754f, 0.50754f, 0.50754f, 1.0f };
		GLfloat maspecular[] = { 0.508273f, 0.508273f, 0.508273f, 0.508273f };
		GLfloat shininess = 51.2f;
		GLfloat maemi[] = { 0.0f, 0.0f, 0.0f, 1.0f };

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, maambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, madiffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, maspecular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, maemi);*/

		glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
		glScaled(VAL(XSCALE), VAL(YSCALE), VAL(ZSCALE));

		// Torus
		if (VAL(DETAIL_LEVEL) > 1) {
			glPushMatrix();
				glTranslated(.0f, 6, .0f);
				drawTorus(VAL(TORUS_R), VAL(TORUS_r));
			glPopMatrix();
		}
		
		//head
		glPushMatrix();
			glTranslated(0, VAL(LEG_LENGTH) + 0.05 + VAL(HEIGHT) + 0.05 + VAL(HEAD_SIZE), 0);
			glRotated(VAL(HEAD_ROTATE), 0.0, 1.0, 0.0);
			drawSphere(VAL(HEAD_SIZE));
			if (VAL(DETAIL_LEVEL) > 2) {
				drawRoundCylinder(VAL(HEAD_SIZE) * 1.1, 0.2, 0.2);
				glPushMatrix();
					glTranslated(-0.5, 0.5, 0);
					drawRoundCylinder(VAL(HEAD_SIZE) * 0.9, 0.2, 0.2);
				glPopMatrix();
				glPushMatrix();
					glTranslated(0.5, 0.5, 0);
					drawRoundCylinder(VAL(HEAD_SIZE) * 0.9, 0.2, 0.2);
				glPopMatrix();
			}
		glPopMatrix();

		//body
		// a.k.a. torso/trunk
		glPushMatrix();
			glTranslated(0, 0.05 + VAL(LEG_LENGTH), 0);
			glRotated(-90, 1.0, 0.0, 0.0);
			drawRoundCylinder(VAL(HEIGHT), 0.7, 0.6);
			glPushMatrix();
				glTranslated(-0.8, 0, VAL(HEIGHT) - 0.4);
				glRotated(90, 0, 1, 0);
				// the shoulder
				if (VAL(DETAIL_LEVEL) > 1) {
					drawRoundCylinder(1.6, 0.2, 0.2);
			}
			glPopMatrix();

			// the waist
			if (VAL(DETAIL_LEVEL) > 2) {
				glPushMatrix();
					glTranslated(0, 0, 0.5);
					glRotated(90, 1, 0, 0);
					drawTorus(0.7, 0.08);
				glPopMatrix();
			}

		glPopMatrix();

		//right arm
		glPushMatrix();
			glTranslated(-0.7 - 0.20, VAL(LEG_LENGTH) + 0.05 + VAL(HEIGHT) * 0.9f, 0);
			glTranslated(0.15, 0, 0);
			glRotated(VAL(RIGHT_UPPER_ARM_ROTATE_X), 1.0, 0.0, 0.0);
			glRotated(VAL(RIGHT_UPPER_ARM_ROTATE_Y), 0.0, 1.0, 0.0);
			glTranslated(-0.15, 0, 0);
			drawRoundCylinder(VAL(UPPER_ARM_LENGTH), 0.22, 0.15);

			// lower arm
			glTranslated(0, 0, VAL(UPPER_ARM_LENGTH) - 0.1);
			glRotated(VAL(RIGHT_LOWER_ARM_ROTATE) - 180, 1, 0, 0);
			drawRoundCylinder(VAL(LOWER_ARM_LENGTH), 0.15, 0.20);

			// hand
			glPushMatrix();
				glTranslated(-0.03, -0.15, VAL(LOWER_ARM_LENGTH) - 0.1);
				glRotated(VAL(RIGHT_HAND_ANGLE), 0, 1, 0);
				drawBox(0.03, 0.25, 0.5);
			glPopMatrix();

			glPushMatrix();
				glTranslated(0.03, -0.15, VAL(LOWER_ARM_LENGTH) - 0.1);
				glRotated(-VAL(RIGHT_HAND_ANGLE), 0, 1, 0);
				drawBox(0.03, 0.25, 0.5);
			glPopMatrix();

		glPopMatrix();

		//left arm
		glPushMatrix();
			glTranslated(0.7 + 0.20, VAL(LEG_LENGTH) + 0.05 + VAL(HEIGHT) * 0.9f, 0);
			glTranslated(-0.15, 0, 0);
			glRotated(VAL(LEFT_UPPER_ARM_ROTATE_X), 1.0, 0.0, 0.0);
			glRotated(VAL(LEFT_UPPER_ARM_ROTATE_Y), 0.0, 1.0, 0.0);
			glTranslated(0.15, 0, 0);
			drawRoundCylinder(VAL(UPPER_ARM_LENGTH), 0.22, 0.15);

			glTranslated(0, 0, VAL(UPPER_ARM_LENGTH) - 0.1);
			glRotated(VAL(LEFT_LOWER_ARM_ROTATE) - 180, 1, 0, 0);
			drawRoundCylinder(VAL(LOWER_ARM_LENGTH), 0.15, 0.20);

			// hand
			glPushMatrix();
				glTranslated(-0.03, 0, VAL(LOWER_ARM_LENGTH) - 0.1);
				glRotated(VAL(LEFT_HAND_ANGLE), 0, 1, 0);
				drawCylinder(0.8, 0.15, 0.0001);
			glPopMatrix();

			glPushMatrix();
				glTranslated(0.03, 0, VAL(LOWER_ARM_LENGTH) - 0.1);
				glRotated(-VAL(LEFT_HAND_ANGLE), 0, 1, 0);
				drawCylinder(0.8, 0.15, 0.0001);
			glPopMatrix();

		glPopMatrix();

		//right leg
		glPushMatrix();
			glTranslated(-0.5, VAL(LEG_LENGTH), 0);
			glRotated(VAL(RIGHT_LEG_ROTATE_X), 1.0, 0.0, 0.0);
			glRotated(VAL(RIGHT_LEG_ROTATE_Y), 0.0, 1.0, 0.0);
			drawRoundCylinder(VAL(LEG_LENGTH) - 0.15, 0.3, 0.4);
			glTranslated(0, 0, VAL(LEG_LENGTH) * 0.85f);
			glRotated(90, 1, 0, 0);
			drawTorus(VAL(FEET_SIZE), VAL(FEET_SIZE) / 4);

		glPopMatrix();

		//left leg
		glPushMatrix();
			glTranslated(0.5, VAL(LEG_LENGTH), 0);
			glRotated(VAL(LEFT_LEG_ROTATE_X), 1.0, 0.0, 0.0);
			glRotated(VAL(LEFT_LEG_ROTATE_Y), 0.0, 1.0, 0.0);
			drawRoundCylinder(VAL(LEG_LENGTH) - 0.15, 0.3, 0.4);
			glTranslated(0, 0, VAL(LEG_LENGTH) * 0.85f);
			glRotated(90, 1, 0, 0);
			drawTorus(VAL(FEET_SIZE), VAL(FEET_SIZE) / 4);

		glPopMatrix();

	glPopMatrix();
}