#include "LS.h"


LS::LS(std::string i, int d, int a) :init(i), depth(d), angle(a)
{
}

void LS::expand(int d) {
	if (d > depth)
		return;

	for (int i = 0; i < init.length(); i++) {
		std::string ch = init.substr(i, 1);
		if (ch.compare("X") == 0) {
			init.replace(i, 1, "D[RX]D[LX]RX");
			i += 11;
		}
	}

	expand(++d);
}

LS::~LS()
{
}

void LS::rotate(bool left) {
	if (left) {
		glRotatef(angle, 1, 0, 0);
		glRotatef(angle * 4, 0, 1, 0);
		glRotatef(angle, 0, 0, 1);
	}
	else {
		glRotatef(-angle, 1, 0, 0);
		glRotatef(angle * 4, 0, 1, 0);
		glRotatef(-angle, 0, 0, 1);
	}
}

void LS::drawLine() {
	glLineWidth(3);

	glBegin(GL_LINES);

	glVertex3f(0, 0, 0);
	glVertex3f(0, 0.2, 0);
	glEnd();

	glTranslatef(0, 0.2, 0);
}

void LS::drawLS() {
	for (int i = 0; i < init.size(); i++) {
		std::string ch = init.substr(i, 1);
		if (ch.compare("D") == 0 || ch.compare("X") == 0) {
			drawLine();
		} else if (ch.compare("[") == 0){
			glPushMatrix();
		} else if (ch.compare("]") == 0){
			glPopMatrix();
		} else if (ch.compare("R") == 0){
			rotate(false);
		} else if (ch.compare("L") == 0){
			rotate(true);
		}

	}
}