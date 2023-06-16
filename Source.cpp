#include <GL\glew.h>  // A cross-platform open-source C/C++ extension loading library
#include <GL\freeglut.h>   // handle the window-managing operations
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <mmsystem.h>
#define PI 3.14159265358978323846

using namespace std;
/*************************************************************************/
float _angle = 40.0f;
float transValueX, transValueY, transValueZ;
float posX = 0, posY = -0.7, posZ = 0;
float storyline1trany = -40, storyline2trany = -80, storyline3trany = -120, storyline4trany = -160, storyline5trany = -200;
float n, m,K;
float transvaluebuyerain;
float starscalex, starscaley;
float transvaluegirl = -0.6;
float scalevaluegirl = 0.3;
float name = -40, name1 = -80, name2 = -120, name3 = -160, name4 = -200;

/*************************************************************************/
GLint win_width = 950, win_hight = 950;
GLfloat rotation = 90.0;

/**************************************************************************/
GLuint myTexture1ro, myTexture2ro, myTexture3so, myTexture4so, myTexture5so, myTexture6so, myTexture7af, myTexture8af, myTexture9af, myTexture10af, myTexture11no, myTexture12no, myTexture13af, myTexture14af;
char image1Path[] = "C:/Users/omar/OneDrive/«·’Ê—/”·„.bmp";
char image2Path[] = "C:/Users/omar/OneDrive/«·’Ê—/”·„2.bmp";

char image3Path[] = "C:/Users/omar/OneDrive/«·’Ê—/kitch.bmp";
char image4Path[] = "C:/Users/omar/OneDrive/«·’Ê—/roomso.bmp";
char image5Path[] = "C:/Users/omar/OneDrive/«·’Ê—/»«» „ﬁ›·.bmp";
char image6Path[] = "C:/Users/omar/OneDrive/«·’Ê—/»«» „ﬁ›·.bmp";

char image7Path[] = "C:/Users/omar/OneDrive/«·’Ê—/room1.bmp";
char image8Path[] = "C:/Users/omar/OneDrive/«·’Ê—/room2_(3).bmp";
char image9Path[] = "C:/Users/omar/OneDrive/«·’Ê—/box4.bmp";
char image10Path[] = "C:/Users/omar/OneDrive/«·’Ê—/box3.bmp";

char image11Path[] = "C:/Users/omar/Downloads/PICROAA/wall.bmp";
char image12Path[] = "C:/Users/omar/Downloads/PICROAA/wall.bmp";

char image13Path[] = "C:/Users/omar/OneDrive/«·’Ê—/AF.bmp";
char image14Path[] = "C:/Users/omar/OneDrive/«·’Ê—/AF2.bmp";


GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat light_diffuse[] = { 0.95, 0.95, 0.95, 1.0 };
GLfloat light_specular[] = { 0.5, 0.0, 0.0, 1.0 };
GLfloat mat_specular[] = { 50, 1, 1, 1 };
GLfloat light_position[] = { -5.0, 1.0, -4.0, 1.0 };
GLfloat shininess[] = { 50 };
/**********************************************************************/
GLfloat light_ambient2[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat light_diffuse2[] = { 0.8, 0.8, 0.8,1.0 };
GLfloat light_specular2[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat mat_specular2[] = { 1, 1, 1, 1 };
GLfloat light_position2[] = { -1.0, 1.0, -4.0, 1.0 };
GLfloat shininess2[] = { 50 };
//------------------------------------------------------
GLuint LoadTexture(const char* filename, int width, int height) {
	GLuint texture;
	unsigned char* data;
	FILE* file;

	fopen_s(&file, filename, "r+");
	data = (unsigned char*)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i) {
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];
		data[index] = R;
		data[index + 2] = B;
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	free(data);

	return texture;
}//
void reshape(GLint new_width, GLint new_hight)
{
	glViewport(0, 0, new_width, new_hight);
	win_width = new_width;
	win_hight = new_hight;
}//
void print_text(const char* text, int len, int x, int y) {
	glMatrixMode(GL_PROJECTION);
	double* matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}
void Circle(float k, float h, float r)
{
	float x, y;

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 180; i++) {
		x = r * cos(i) - h;
		y = r * sin(i) + k;
		glVertex3f(x + k, y - h, 0);


		x = r * cos(i + 0.1) - h;
		y = r * sin(i + 0.1) + k;
		glVertex3f(x + k, y - h, 0);
	}
	glEnd();
}
void update(int value) {
	_angle += 2;
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}
void draw_circle()
{
	float theta;
	//glColor3f(1.0f, 1.0f, 0.48f); //smyrna purple MAIN color
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142f / 180;
		glVertex2f(0.0f + 0.2f * cos(theta), 0.0f + 0.2f * sin(theta));
	}
	glEnd();

}
void draw_halfcircle()
{
	float theta;
	// glColor3f(0.0f, 0.0f, 0.0f); //smyrna purple MAIN color
	glBegin(GL_POLYGON);
	for (int i = 0; i < 180; i++) {
		theta = i * 3.142f / 180;
		glVertex2f(0.147f + 0.1f * cos(theta), 0.0f + 0.2f * sin(theta));
	}
	glEnd();


}
void draw_rectangle()
{
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0);
	glVertex3f(0.0, 0.1, 0);
	glVertex3f(0.1, 0.1, 0);
	glVertex3f(0.1, 0.0, 0);
	glEnd();

}
void draw_triangle2()
{
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(0.2f, 0.0f);
	glEnd();
}
void gluter() {

	glColor3f(1.00000, 1.00000, 0.70196);
	glPushMatrix();
	glTranslatef(0.5, 0.5, 0);
	draw_triangle2();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.7, 0.5, 0);
	glRotatef(180, 0, 0, 0);
	draw_triangle2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, 0.4, 0);
	glRotatef(90, 0, 0, 1);
	draw_triangle2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, 0.6, 0);
	glRotatef(-90, 0, 0, 1);
	draw_triangle2();
	glPopMatrix();
}
void star() {

	glPointSize(2.0f);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 8);
	glVertex2f(-0.9, 0.9);
	glVertex2f(-0.9, -0.3);
	glVertex2f(-0.8, 0.6);
	glVertex2f(-0.7, -0.6);
	glVertex2f(-0.7, -0.7);
	glVertex2f(-0.5, 0.6);
	glVertex2f(-0.4, 0.6);
	glVertex2f(-0.2, 0.4);
	glVertex2f(-0.1, -0.6);
	glVertex2f(0.8, 0);
	glVertex2f(0.8, -0.8);
	glVertex2f(0.6, 0.6);
	glVertex2f(0.4, -0.5);
	glVertex2f(0.2, 0.3);
	glVertex2f(0.1, -0.6);
	glVertex2f(0.0, 0.8);
	glEnd();

	//star
	glPushMatrix();
	glTranslatef(0.3, 0.3, 0);
	glScalef(0.15, 0.15, 1);
	gluter();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, 0.3, 0);
	glScalef(0.1, 0.1, 1);
	gluter();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.7, 0.7, 0);
	glScalef(0.1, 0.1, 1);
	gluter();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.9, 0.7, 0);
	glScalef(0.05, 0.05, 1);
	gluter();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.7, 0.9, 0);
	glScalef(0.05, 0.05, 1);
	gluter();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.86, 0);
	glScalef(0.05, 0.05, 1);
	gluter();
	glPopMatrix();
}
void rain() {

	glColor4f(0.90196, 0.94902, 1.00000, 0.4);
	glLineWidth(0.2f);
	glLineStipple(3, 0x0c0F);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2f(-0.9, 3);
	glVertex2f(-0.9, -3);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}
void cloud() {
	glPushMatrix();
	glScalef(0.35, 0.35, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.25, 1.0);
	glTranslatef(0.3, -0.1, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.2, 1.0);
	glTranslatef(-0.3, -0.1, 0.0);
	draw_circle();
	glPopMatrix();
}
void transrain() {



	glPushMatrix();
	glTranslatef(-2.6, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.4, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.1, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.6, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.7, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.9, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.95, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.90, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.85, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.80, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.75, 0.0, 0.0);
	rain();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.70, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.65, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.59, 0.0, 0.0);
	rain();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.46, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.38, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.13, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.07, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.18, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.23, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.29, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.34, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.05, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.08, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.012, 0.07, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.16, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.20, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.23, 0.0, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.27, 0.066, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.32, 0.043, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.38, 0.02, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.44, 0.09, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.49, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.54, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.60, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.64, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.70, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.74, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.79, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.83, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.87, 0.04, 0.0);
	rain();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.92, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.96, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.04, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.09, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.13, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.19, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.23, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.30, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.45, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.50, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.64, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.69, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.75, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.81, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.89, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.94, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.02, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.09, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.13, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.19, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.24, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.31, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.40, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.56, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.62, 0.04, 0.0);
	rain();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.68, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.75, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.80, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.87, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.93, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.99, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.05, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.13, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.20, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.18, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.25, 0.04, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.32, 2, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.40, 2, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.45, 2, 0.0);
	rain();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.53, 2, 0.0);
	rain();
	glPopMatrix();


}
void shihab() {
	glColor3f(1.00000, 1.00000, 0.70196);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(2., 2.);
	glVertex2f(1.6, 1.6);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(1.98, 1.98);
	glVertex2f(1.62, 1.58);
	glEnd();

	glPushMatrix();
	glTranslatef(1.45, 1.45, 0);
	glScalef(0.28, 0.28, 1);
	gluter();
	glPopMatrix();


}
void gosh() {

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(0.69, -1);
	glVertex2f(0.69, -0.5);
	glVertex2f(0.92, -0.5);
	glVertex2f(0.92, -1);
	glEnd();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(0.58, 0.6, 1);
	glTranslatef(1.39, -0.8, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(0.1, 0.1, 1);
	glTranslatef(8.5, -4.8, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(0.1, 0.1, 1);
	glTranslatef(7.7, -4.8, 0.0);
	draw_circle();
	glPopMatrix();


}
void tree() {
	glPushMatrix();
	draw_triangle2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.05, 0);
	draw_triangle2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.1, 0);
	draw_triangle2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.15, 0);
	draw_triangle2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(0.2, 1.5, 1);
	glTranslatef(0.46, -0.2, 0);
	draw_rectangle();
	glPopMatrix();

}
void boma() {


	glPushMatrix();
	glColor3f(0, 0, 0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(20, 0, 0, 1);
	glTranslatef(-0.15, 0.05, 0);
	draw_triangle2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(-20, 0, 0, 1);
	glTranslatef(-0.05, 0.05, 0);
	draw_triangle2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.00000, 0.80000, 0.00000);
	glScalef(0.2, 0.2, 1);
	glTranslatef(-0.3, 0.2, 0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(0.08, 0.08, 1);
	glTranslatef(-0.75, 0.4, 0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.00000, 0.80000, 0.00000);
	glScalef(0.2, 0.2, 1);
	glTranslatef(0.4, 0.2, 0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(0.08, 0.08, 1);
	glTranslatef(0.95, 0.4, 0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.30196, 0.30196, 0.30196);
	glRotatef(180, 0, 0, 0);
	glScalef(0.8, 0.8, 1);
	glTranslatef(-0.11, -0.15, 0);
	draw_triangle2();
	glPopMatrix();

	///////////////////

	glPushMatrix();
	glColor3f(0.10196, 0.10196, 0.10196);
	glScalef(m, 0.2, 1);
	glTranslatef(0.4, 0.2, 0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.10196, 0.10196, 0.10196);
	glScalef(m, 0.2, 1);
	glTranslatef(-0.3, 0.2, 0);
	draw_circle();
	glPopMatrix();
}
void storylines() {

	//story
	std::string text;
	text = "Hello, I'm Sally, I was trapped in this terrifying haunted ";
	glColor3f(1.0, 1.0, 1.0);
	print_text(text.data(), text.size(), 70, storyline1trany);
	//260
	std::string text2;
	text2 = "house in the middle of the empty forest.It's dark, the lighting is ";

	glColor3f(1.0, 1.0, 1.0);
	print_text(text2.data(), text2.size(), 40, storyline2trany);
	//220

	std::string text3;
	text3 = "dim, the sound of thunderand rain is scary, and no one is here.";

	glColor3f(1.0, 1.0, 1.0);
	print_text(text3.data(), text3.size(), 40, storyline3trany);
	//180
	std::string text4;
	text4 = "I'm very scared, so help me to find the key to the  door ";

	glColor3f(1.0, 1.0, 1.0);
	print_text(text4.data(), text4.size(), 60, storyline4trany);
	//140
	std::string text5;
	text5 = "and get out of this terrifying place as soon as possible. ";

	glColor3f(1.0, 1.0, 1.0);
	print_text(text5.data(), text5.size(), 60, storyline5trany);
	//100
}
void Face()
{
	//gray 
	glColor4f(0., 0., 0., 0.0);
	glPushMatrix();
	glTranslatef(0, -0.50, 0);
	Circle(0, 0, 1.27);
	glPopMatrix();

	//big green circle
	glColor4f(0.10196, 0.10196, 0.00000, 1);
	glPushMatrix();
	glTranslatef(0, -0.50, 0);
	Circle(0, 0, 1.25);
	glPopMatrix();

	//small green eye circle
	glColor4f(0.10196, 0.10196, 0.00000, 1);
	glTranslatef(0, 0.20, 0);
	Circle(0, 0, 0.80);
}
void hand_and_leg()
{
	glColor4f(0.50, 0.50, 0.50, 0.80);
	glLineWidth(15);
	glBegin(GL_LINES);

	glVertex2f(1.1, -0.9);
	glVertex2f(1.1, -3.5);

	glVertex2f(-1.1, -0.9);
	glVertex2f(-1.1, -3.5);


	glVertex2f(0.3, -1.5);
	glVertex2f(0.3, -3.5);

	glVertex2f(-0.3, -1.5);
	glVertex2f(-0.3, -3.5);

	glEnd();

}
void eye()
{
	//gray circle
	glColor4f(0.50, 0.50, 0.50, 0.80);
	Circle(0, 0, 0.70);

	//green circle
	glColor4f(1, 1, 1, 1);
	Circle(0, 0, 0.68);

	//white circlr
	glColor4f(1, 1, 1, 1);
	Circle(0, 0, 0.66);

	//black circle
	glColor4f(0, 0.0, 0, 1);
	Circle(0, 0, 0.30);

	//dark green circle
	glColor4f(0.90196, 0.22353, 0.00000, 1);
	Circle(0, 0, 0.28);

	//small black circle
	glColor4f(0, 0.0, 0, 1);
	Circle(0, 0, 0.15);

	//small white circlr
	glColor4f(1, 1.0, 1, 0.80);
	glPushMatrix();
	glTranslatef(0.2, 0.2, 0);
	Circle(0, 0, 0.05);
	glPopMatrix();
}
void tiangle_ear()
{
	glBegin(GL_TRIANGLES);


	glColor4f(1, 1, 1, 0.5);
	glVertex2f(0.4, 0.4);
	glColor4f(1, 1, 1, 0.5);
	glVertex2f(0.2, 0.4);
	glColor4f(0.2, 0.2, 0, 1);
	glVertex2f(0.3, 0.7);


	glEnd();
}
void ear() {

	glPushMatrix();
	glTranslatef(0.1, 0.5, 0);
	glRotatef(-25, 0, 0, 1);
	tiangle_ear();
	glPopMatrix();

	glPushMatrix();
	glRotatef(25, 0, 0, 1);
	glTranslatef(-0.47, 0.5, 0);
	tiangle_ear();
	glPopMatrix();

}
void mouth()
{
	//black circle
	glColor4f(0, 0, 0, 1);
	glPushMatrix();
	glTranslatef(0, -0.85, 0);
	Circle(0, 0, 0.6);
	glPopMatrix();

	//green circle
	glColor4f(0.50, 1.0, 0.10, 0.80);
	glPushMatrix();
	glTranslatef(0, -0.4, 0);
	Circle(0, 0, 0.8);
	glPopMatrix();
}
void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);

	_angle += 0.8 * 3;
	if (_angle > 360.0);
	_angle = _angle - 360.0;
}
/*afrah*/

void rec1()
{
	glBegin(GL_QUADS);
	glVertex2f(0.39, -0.38);
	glVertex2f(0.39, -0.36);
	glVertex2f(0.27, -0.39);
	glVertex2f(0.27, -0.42);
	glEnd();


}
void rec2()
{
	glBegin(GL_QUADS);
	glVertex2f(0.38, -0.38);
	glVertex2f(0.365, -0.39);
	glVertex2f(0.365, -0.43);
	glVertex2f(0.38, -0.43);
	glEnd();

}
void draw_circle(float x, float y, float n1, float n2)
{
	glBegin(GL_POLYGON);

	GLfloat angle;
	for (int i = 0; i <= 360; i++) {
		angle = i * 3.14 * 2 / 180;
		glVertex2f(x + cos(angle) * n1, y + sin(angle) * n2);
	}

	glEnd();
}
void box()
{


	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture9af);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(0.39, -0.45);
	glTexCoord2f(1, 0); glVertex2f(0.39, -0.35);
	glTexCoord2f(1, 1); glVertex2f(0.23, -0.35);
	glTexCoord2f(0, 1); glVertex2f(0.23, -0.45);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glFlush();

}
void box2()
{/*
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture10af);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(0.39, -0.45);
	glTexCoord2f(1, 0); glVertex2f(0.39, -0.35);
	glTexCoord2f(1, 1); glVertex2f(0.23, -0.35);
	glTexCoord2f(0, 1); glVertex2f(0.23, -0.45);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glFlush();

}
void closet()
{/*
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture13af);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(-0.6, -0.32);
	glTexCoord2f(1, 0); glVertex2f(-0.6, 0.05);
	glTexCoord2f(1, 1); glVertex2f(-0.4, 0.05);
	glTexCoord2f(0, 1); glVertex2f(-0.4, -0.32);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glFlush();

}
void closet1()
{/*
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture14af);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(-0.6, -0.32);
	glTexCoord2f(1, 0); glVertex2f(-0.6, 0.05);
	glTexCoord2f(1, 1); glVertex2f(-0.4, 0.05);
	glTexCoord2f(0, 1); glVertex2f(-0.4, -0.32);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glFlush();

}
void spider() {
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	draw_circle(-0.6, -0.2, 0.03, 0.03);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	draw_circle(-0.62, -0.2, 0.005, 0.005);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	draw_circle(-0.59, -0.2, 0.005, 0.005);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.3, 0.1, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	draw_circle(0.7, -0.23, 0.05, 0.05);
	glPopMatrix();

	glLineWidth(3.0f);
	glLineStipple(2, 0x00FF);
	glBegin(GL_LINES);
	glVertex2f(-0.6, -0.2);
	glVertex2f(-0.55, -0.28);

	glLineWidth(3.0f);
	glLineStipple(2, 0x00FF);
	glBegin(GL_LINES);
	glVertex2f(-0.61, -0.2);
	glVertex2f(-0.66, -0.28);

	glLineWidth(3.0f);
	glLineStipple(2, 0x00FF);
	glBegin(GL_LINES);
	glVertex2f(-0.61, -0.16);
	glVertex2f(-0.67, -0.26);

	glLineWidth(3.0f);
	glLineStipple(2, 0x00FF);
	glBegin(GL_LINES);
	glVertex2f(-0.6, -0.16);
	glVertex2f(-0.54, -0.26);

	glLineWidth(3.0f);
	glLineStipple(2, 0x00FF);
	glBegin(GL_LINES);
	glVertex2f(-0.61, -0.18);
	glVertex2f(-0.69, -0.09);

	glLineWidth(3.0f);
	glLineStipple(2, 0x00FF);
	glBegin(GL_LINES);
	glVertex2f(-0.62, -0.2);
	glVertex2f(-0.69, -0.13);

	glLineWidth(3.0f);
	glLineStipple(2, 0x00FF);
	glBegin(GL_LINES);
	glVertex2f(-0.58, -0.18);
	glVertex2f(-0.5, -0.09);

	glLineWidth(3.0f);
	glLineStipple(2, 0x00FF);
	glBegin(GL_LINES);
	glVertex2f(-0.58, -0.2);
	glVertex2f(-0.5, -0.13);

	glEnd();

	/*glLineWidth(1.5f);
	glLineStipple(2, 0x00FF);
	glBegin(GL_LINES);
	glVertex2f(-0.6, 0.09);
	glVertex2f(-0.6, -0.1);
	glEnd();*/
}
void key1() {

	glPushMatrix();
	glColor3f(0.90196, 0.72157, 0.00000);
	draw_circle(0.26, -0.41, 0.03, 0.03);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.18, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	draw_circle(0.25, -0.23, 0.01, 0.01);
	glPopMatrix();


	glColor3f(0.90196, 0.72157, 0.00000);
	rec1();

	glColor3f(0.90196, 0.72157, 0.00000);
	rec2();

	glPushMatrix();
	glTranslatef(-0.03, 0.01, 0.0);
	glColor3f(0.90196, 0.72157, 0.00000);
	rec2();
	glPopMatrix();
}
void girl() {


	//back hair
	glPushMatrix();
	glColor3f(0.30196, 0.20000, 0.09804);
	glScalef(4.45, 5, 1);
	glTranslatef(-0.049, -0.09, 0.0);
	draw_rectangle();
	glPopMatrix();

	//neck
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 3, 1);
	glTranslatef(-0.049, -0.144, 0.0);
	draw_rectangle();
	glPopMatrix();

	//face
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	draw_circle();
	glPopMatrix();

	//hair
	glPushMatrix();
	glColor3f(0.30196, 0.20000, 0.09804);
	glScalef(2.25, 1.5, 1);
	glTranslatef(-0.145, 0.0, 0.0);
	draw_halfcircle();
	glPopMatrix();

	//face
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(.9, .15, 1);
	draw_circle();
	glPopMatrix();

	/*************************************/
   //eye
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glScalef(.08, .12, 1);
	glTranslatef(1, 0.1, 0.0);
	draw_circle();
	glPopMatrix();

	//left eye
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glScalef(.08, .12, 1);
	glTranslatef(-1, 0.1, 0.0);
	draw_circle();
	glPopMatrix();


	//white eye
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glScalef(.027, .065, 1);
	glTranslatef(-2.9, 0.24, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glScalef(.027, .065, 1);
	glTranslatef(2.9, 0.2, 0.0);
	draw_circle();
	glPopMatrix();

	//eyebrwo
	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(.2, .2, 1);
	glTranslatef(0.4, 0.6, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(.2, .2, 1);
	glTranslatef(-0.4, 0.6, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.30196, 0.20000, 0.09804);
	glScalef(.38, .3, 1);
	glTranslatef(0.28, 0.48, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.30196, 0.20000, 0.09804);
	glScalef(.38, .3, 1);
	glTranslatef(-0.28, 0.48, 0.0);
	draw_circle();
	glPopMatrix();

	//mouth
	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(0.36, .07, 1);
	glTranslatef(0, -1.6, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(.13, .1, 1);
	glTranslatef(0.4, -1.25, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(.13, .1, 1);
	glTranslatef(-0.4, -1.25, 0.0);
	draw_circle();
	glPopMatrix();

	//mouth toon
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(.23, .2, 1);
	glTranslatef(0.0, -0.78, 0.0);
	draw_circle();
	glPopMatrix();

	glEnd();

	//backhand
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(0.18, -0.2, 0.0);
	draw_rectangle();
	glPopMatrix();

	//left leg 
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(-0.16, -0.34, 0.0);
	draw_rectangle();
	glPopMatrix();


	//rightleg
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(0.08, -0.34, 0.0);
	draw_rectangle();
	glPopMatrix();
	//leftfeet
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(.23, .2, 1);
	glTranslatef(-0.35, -4.3, 0.0);
	draw_circle();
	glPopMatrix();


	//rightfeet
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(.23, .2, 1);
	glTranslatef(0.37, -4.3, 0.0);
	draw_circle();
	glPopMatrix();

	//dress
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(3, 5, 1);
	glTranslatef(-0.049, -0.144, 0.0);
	draw_rectangle();
	glPopMatrix();


	//middress
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0, -2.4, 0.0);
	draw_circle();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(-0.3, -2.4, 0.0);
	draw_circle();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0.31, -2.4, 0.0);
	draw_circle();
	glPopMatrix();


	//ﬂ„ Ì„Ì‰
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0.5, -0.9, 0.0);
	draw_circle();
	glPopMatrix();
	//left hand
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(-0.25, -0.2, 0.0);
	draw_rectangle();
	glPopMatrix();

	//ﬂ„ Ì”«—
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(-0.5, -0.9, 0.0);
	draw_circle();
	glPopMatrix();
	////

	//backhand
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(0.18, -0.2, 0.0);
	draw_rectangle();
	glPopMatrix();

	//left leg 
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(-0.16, -0.34, 0.0);
	draw_rectangle();
	glPopMatrix();


	//rightleg
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(0.08, -0.34, 0.0);
	draw_rectangle();
	glPopMatrix();
	//leftfeet
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(.23, .2, 1);
	glTranslatef(-0.35, -4.3, 0.0);
	draw_circle();
	glPopMatrix();


	//rightfeet
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(.23, .2, 1);
	glTranslatef(0.37, -4.3, 0.0);
	draw_circle();
	glPopMatrix();

	//dress
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(3, 5, 1);
	glTranslatef(-0.049, -0.144, 0.0);
	draw_rectangle();
	glPopMatrix();


	//middress
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0, -2.4, 0.0);
	draw_circle();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(-0.3, -2.4, 0.0);
	draw_circle();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0.31, -2.4, 0.0);
	draw_circle();
	glPopMatrix();


	//ﬂ„ Ì„Ì‰
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0.5, -0.9, 0.0);
	draw_circle();
	glPopMatrix();
	//left hand
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(-0.25, -0.2, 0.0);
	draw_rectangle();
	glPopMatrix();

	//ﬂ„ Ì”«—
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(-0.5, -0.9, 0.0);
	draw_circle();
	glPopMatrix();
	//
	glPushMatrix();
	glColor3f(0.22745, 0.14902, 0.07451);
	glScalef(0.6, 0.6, 1);
	glTranslatef(-0.5, -0.95, 0.0);
	draw_circle();
	glPopMatrix();
	glEnd();

	glPushMatrix();
	glColor3f(0.45098, 0.30196, 0.14902);
	glScalef(0.58, 0.58, 1);
	glTranslatef(-0.5, -0.98, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.45098, 0.30196, 0.14902);
	glScalef(0.2, 0.4, 1);
	glTranslatef(-1.8, -1.6, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.22745, 0.14902, 0.07451);
	glScalef(0.53, 0.53, 1);
	glTranslatef(-0.69, -0.95, 0.0);
	draw_circle();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.45098, 0.30196, 0.14902);
	glScalef(0.5, 0.5, 1);
	glTranslatef(-0.73, -1., 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.45098, 0.30196, 0.14902);
	glScalef(0.3, 0.3, 1);
	glTranslatef(-1.2, -1.35, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.45098, 0.30196, 0.14902);
	glScalef(0.3, 0.3, 1);
	glTranslatef(-1.55, -1.7, 0.0);
	draw_circle();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.22745, 0.14902, 0.07451);
	glScalef(0.3, 0.3, 1);
	glTranslatef(-0.56, -1.9, 0.0);
	draw_circle();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.22745, 0.14902, 0.07451);
	glScalef(0.3, 0.3, 1);
	glTranslatef(-0.8, -2.25, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.45098, 0.30196, 0.14902);
	glScalef(0.29, 0.29, 1);
	glTranslatef(-0.56, -1.98, 0.0);
	draw_circle();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.45098, 0.30196, 0.14902);
	glScalef(0.29, 0.29, 1);
	glTranslatef(-0.81, -2.35, 0.0);
	draw_circle();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.45098, 0.30196, 0.14902);
	glScalef(0.4, 0.15, 1);
	glTranslatef(-0.48, -3.15, 0.0);
	draw_circle();
	glPopMatrix();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.3, -0.5);
	glVertex2f(-0.4, -0.53);
	glEnd();


	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.35, -0.47);
	glVertex2f(-0.35, -0.57);
	glEnd();

	glPushMatrix();
	glScalef(K, 1, 1);
	key1();
	glPopMatrix();
}
/*end afrah methds*/

/*Noura*/
void drawCircle(GLfloat x0, GLfloat y0, GLfloat r, int a, int b, int c)
{
	GLfloat x = x0;
	GLfloat y = y0;
	GLfloat radius = r;
	float theta;

	glBegin(GL_POLYGON);
	glColor3ub(a, b, c);
	glVertex2f(x, y);
	for (int i = 0; i <= 360; i++) {
		theta = i * PI / 180;
		glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
	}
	glEnd();
	

}
void drawHalfCircle(GLfloat x0, GLfloat y0, GLfloat r, int a, int b, int c)
{
	GLfloat x = x0;
	GLfloat y = y0;
	GLfloat radius = r;
	float theta;

	glBegin(GL_POLYGON);
	glColor3ub(a, b, c);
	glVertex2f(x, y);
	for (int i = 0; i <= 180; i++) {
		theta = i * PI / 180;
		glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
	}
	glEnd();
	
}
void upRoom(){

	glColor4f(0.27451, 0.34510, 0.38431, 1);

	glBegin(GL_QUADS);
	glVertex2f(-0.78, 0.12);
	glVertex2f(-0.78, 0.53);
	glVertex2f(0.34, 0.53);
	glVertex2f(0.34, 0.12);
	glEnd();

	glColor3ub(59, 59, 59);
	glBegin(GL_POLYGON);
	glVertex2f(-0.48, 0.12);
	glVertex2f(-0.48, 0.7);
	glVertex2f(-0.37, 0.7);
	glVertex2f(-0.37, 0.12);
	glEnd();

	//floor
	glColor3ub(101, 65, 36);
	glBegin(GL_QUADS);
	glVertex2f(-0.78, 0.12);
	glVertex2f(-0.78, 0.25);
	glVertex2f(0.34, 0.25);
	glVertex2f(0.34, 0.12);
	glEnd();
	//

	glColor3ub(83, 52, 28);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.78f, 0.14f);
	glVertex2f(0.34f, 0.14f);
	glEnd();

	glColor3ub(83, 52, 28);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.78f, 0.16f);
	glVertex2f(0.34f, 0.16f);
	glEnd();

	glColor3ub(83, 52, 28);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.78f, 0.18f);
	glVertex2f(0.34f, 0.18f);
	glEnd();

	glColor3ub(83, 52, 28);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.78f, 0.20f);
	glVertex2f(0.34f, 0.20f);
	glEnd();

	glColor3ub(83, 52, 28);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.78f, 0.22f);
	glVertex2f(0.34f, 0.22f);
	glEnd();

	glColor3ub(83, 52, 28);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.78f, 0.24f);
	glVertex2f(0.34f, 0.24f);
	glEnd();

	//wall
	glColor3ub(59, 59, 59);
	glBegin(GL_QUADS);
	glVertex2f(-0.78, 0.25);
	glVertex2f(-0.78, 0.53);
	glVertex2f(0.34, 0.53);
	glVertex2f(0.34, 0.25);
	glEnd();

	//œÊ·«»
	glColor3ub(135, 108, 72);
	glBegin(GL_QUADS);
	glVertex2f(-0.23, 0.25);
	glVertex2f(-0.23, 0.47);
	glVertex2f(-0.06, 0.47);
	glVertex2f(-0.06, 0.25);
	glEnd();

	glColor3ub(113, 90, 60); //ÕœÊœ
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.23, 0.25);
	glVertex2f(-0.23, 0.47);
	glVertex2f(-0.06, 0.47);
	glVertex2f(-0.06, 0.25);
	glEnd();

	glColor3ub(113, 90, 60); //ÕœÊœ
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.22, 0.263);
	glVertex2f(-0.22, 0.46);
	glVertex2f(-0.07, 0.46);
	glVertex2f(-0.07, 0.263);
	glEnd();

	glColor3ub(113, 90, 60); //ÕœÊœ
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.145, 0.47);
	glVertex2f(-0.145, 0.25);
	glEnd();

	glPointSize(5.0f); //„”ﬂÂ
	glBegin(GL_POINTS);
	glColor3ub(113, 90, 60);
	glVertex2f(-.165, .36);

	glPointSize(5.0f); // „”ﬂÂ
	glBegin(GL_POINTS);
	glColor3ub(113, 90, 60);
	glVertex2f(-.13, .36);

	glEnd();

	//„œ›∆Â
	glColor3ub(135, 108, 72);
	glBegin(GL_QUADS);
	glVertex2f(-0.5, 0.25);
	glVertex2f(-0.5, 0.37);
	glVertex2f(-0.35, 0.37);
	glVertex2f(-0.35, 0.25);
	glEnd();

	glColor3ub(113, 90, 60); //ÕœÊœ
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5, 0.25);
	glVertex2f(-0.5, 0.37);
	glVertex2f(-0.35, 0.37);
	glVertex2f(-0.35, 0.25);
	glEnd();

	drawHalfCircle(-.426f, .26f, .05f, 59, 59, 59); // › Õ… «·„œ›∆Â

	glColor3ub(135, 108, 72); //—› «·„œ›∆Â
	glBegin(GL_QUADS);
	glVertex2f(-0.51, 0.33);
	glVertex2f(-0.51, 0.355);
	glVertex2f(-0.34, 0.355);
	glVertex2f(-0.34, 0.33);
	glEnd();

	glColor3ub(113, 90, 60); //ÕœÊœ
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.51, 0.33);
	glVertex2f(-0.51, 0.355);
	glVertex2f(-0.34, 0.355);
	glVertex2f(-0.34, 0.33);
	glEnd();

	// ﬂ‰»Â
	glColor3ub(132, 40, 31);
	glBegin(GL_QUADS);
	glVertex2f(0.04, 0.25);
	glVertex2f(0.04, 0.37);
	glVertex2f(0.27, 0.37);
	glVertex2f(0.27, 0.25);
	glEnd();

	glColor3ub(120, 40, 31); //ÕœÊœ
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.155, 0.37);
	glVertex2f(0.155, 0.25);
	glEnd();

	glColor3ub(120, 40, 31); //ÕœÊœ
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.04, 0.25);
	glVertex2f(0.04, 0.37);
	glVertex2f(0.27, 0.37);
	glVertex2f(0.27, 0.25);
	glEnd();

	glColor3ub(123, 36, 28);
	glBegin(GL_QUADS);
	glVertex2f(0.04, 0.25);
	glVertex2f(0.04, 0.3);
	glVertex2f(0.27, 0.3);
	glVertex2f(0.27, 0.25);
	glEnd();

	glColor3ub(120, 40, 31); //ÕœÊœ
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.04, 0.25);
	glVertex2f(0.04, 0.3);
	glVertex2f(0.27, 0.3);
	glVertex2f(0.27, 0.25);
	glEnd();

	glColor3ub(123, 36, 28); // „”‰œ «·Ì„Ì‰
	glBegin(GL_QUADS);
	glVertex2f(0.25, 0.25);
	glVertex2f(0.25, 0.34);
	glVertex2f(0.29, 0.34);
	glVertex2f(0.29, 0.25);
	glEnd();

	glColor3ub(123, 36, 28); // „”‰œ «·Ì”«—
	glBegin(GL_QUADS);
	glVertex2f(0.02, 0.25);
	glVertex2f(0.02, 0.34);
	glVertex2f(0.06, 0.34);
	glVertex2f(0.06, 0.25);
	glEnd();

	// œ„ «·«—÷
	drawCircle(-0.06, 0.19, 0.03, 100, 30, 22);
	drawCircle(-0.08, 0.17, 0.02, 100, 30, 22);
	drawCircle(-0.09, 0.20, 0.02, 100, 30, 22);
	drawCircle(-0.12, 0.165, 0.013, 100, 30, 22);
	drawCircle(-0.14, 0.2, 0.008, 100, 30, 22);

}

void ghost() {

	// body
	glBegin(GL_TRIANGLES);
	glColor3ub(208, 211, 212);
	glVertex2f(-0.65f, 0.355f);
	glVertex2f(-0.585f, 0.27f);
	glVertex2f(-0.715f, 0.27f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(208, 211, 212);
	glVertex2f(-0.65f, 0.38f);
	glVertex2f(-0.59f, 0.3f);
	glVertex2f(-0.71f, 0.3f);
	glEnd();

	// head
	drawCircle(-0.65, 0.35, 0.04, 208, 211, 212);
	// eyes
	drawCircle(-0.635, 0.36, 0.013, 23, 32, 42);
	drawCircle(-0.665, 0.36, 0.013, 23, 32, 42);
	// red eyes
	drawCircle(-0.635, 0.36, 0.0065, 146, 43, 33);
	drawCircle(-0.665, 0.36, 0.0065, 146, 43, 33);
	// mouth
	drawCircle(-0.654, 0.33, 0.01, 23, 32, 42);
	drawCircle(-0.646, 0.33, 0.01, 23, 32, 42);
}
/////////////////////

void drawrectangle()
{
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0);
	glVertex3f(0.0, 0.1, 0);
	glVertex3f(0.1, 0.1, 0);
	glVertex3f(0.1, 0.0, 0);
	glEnd();

}
void drawtriangle2()
{
	glBegin(GL_TRIANGLES);
	glColor3ub(34, 153, 84);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.2f, 0.0f);
	glColor3ub(25, 111, 61);
	glVertex2f(0.1f, 0.2f);
	glEnd();
}
void tree2() {

	glPushMatrix();
	glColor3ub(120, 66, 18);
	glScalef(0.2, 1.5, 1);
	glTranslatef(0.46, -0.2, 0);
	drawrectangle();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.15, 0);
	drawtriangle2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.1, 0);
	drawtriangle2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.05, 0);
	drawtriangle2();
	glPopMatrix();

	glPushMatrix();
	drawtriangle2();
	glPopMatrix();

}
void cloud2() {
	glColor3f(1, 1, 1);
	glPushMatrix();
	glScalef(0.35, 0.35, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.25, 1.0);
	glTranslatef(0.3, -0.1, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.2, 1.0);
	glTranslatef(-0.3, -0.1, 0.0);
	draw_circle();
	glPopMatrix();
}
void girl2() {

	//face
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	draw_circle();
	glPopMatrix();

	//face
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(.9, .15, 1);
	draw_circle();
	glPopMatrix();

	/*************************************/

	//backhand
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(0.18, -0.2, 0.0);
	draw_rectangle();
	glPopMatrix();

	//left leg 
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(-0.16, -0.34, 0.0);
	draw_rectangle();
	glPopMatrix();

	//rightleg
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(0.08, -0.34, 0.0);
	draw_rectangle();
	glPopMatrix();

	//leftfeet
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(.23, .2, 1);
	glTranslatef(-0.35, -4.3, 0.0);
	draw_circle();
	glPopMatrix();

	//rightfeet
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(.23, .2, 1);
	glTranslatef(0.37, -4.3, 0.0);
	draw_circle();
	glPopMatrix();

	//ﬂ„ Ì„Ì‰
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0.5, -0.9, 0.0);
	draw_circle();
	glPopMatrix();

	//left hand
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(-0.25, -0.2, 0.0);
	draw_rectangle();
	glPopMatrix();

	//ﬂ„ Ì”«—
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(-0.5, -0.9, 0.0);
	draw_circle();
	glPopMatrix();
	////

	//backhand
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(0.18, -0.2, 0.0);
	draw_rectangle();
	glPopMatrix();

	//left leg 
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(-0.16, -0.34, 0.0);
	draw_rectangle();
	glPopMatrix();

	//rightleg
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(0.08, -0.34, 0.0);
	draw_rectangle();
	glPopMatrix();

	//leftfeet
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(.23, .2, 1);
	glTranslatef(-0.35, -4.3, 0.0);
	draw_circle();
	glPopMatrix();

	//rightfeet
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(.23, .2, 1);
	glTranslatef(0.37, -4.3, 0.0);
	draw_circle();
	glPopMatrix();

	//dress
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(3, 5, 1);
	glTranslatef(-0.049, -0.144, 0.0);
	draw_rectangle();
	glPopMatrix();

	//middress
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0, -2.4, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(-0.3, -2.4, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0.31, -2.4, 0.0);
	draw_circle();
	glPopMatrix();

	//ﬂ„ Ì„Ì‰
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0.5, -0.9, 0.0);
	draw_circle();
	glPopMatrix();

	//left hand
	glPushMatrix();
	glColor3f(0.92941, 0.84314, 0.77255);
	glScalef(0.7, 2.5, 1);
	glTranslatef(-0.25, -0.2, 0.0);
	draw_rectangle();
	glPopMatrix();

	//ﬂ„ Ì”«—
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(-0.5, -0.9, 0.0);
	draw_circle();
	glPopMatrix();

	//œ»œÊ»

	glPushMatrix();
	glColor3ub(147, 81, 22);
	glScalef(0.6, 0.6, 1);
	glTranslatef(-0.5, -0.95, 0.0);
	draw_circle();
	glPopMatrix();
	glEnd();

	glPushMatrix();
	glColor3ub(147, 81, 22);
	glScalef(0.58, 0.58, 1);
	glTranslatef(-0.5, -0.98, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(147, 81, 22);
	glScalef(0.2, 0.4, 1);
	glTranslatef(-1.8, -1.6, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(147, 81, 22);
	glScalef(0.53, 0.53, 1);
	glTranslatef(-0.69, -0.95, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(147, 81, 22);
	glScalef(0.5, 0.5, 1);
	glTranslatef(-0.73, -1., 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(147, 81, 22);
	glScalef(0.3, 0.3, 1);
	glTranslatef(-1.2, -1.35, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(147, 81, 22);
	glScalef(0.3, 0.3, 1);
	glTranslatef(-1.55, -1.7, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(147, 81, 22);
	glScalef(0.29, 0.29, 1);
	glTranslatef(-0.56, -1.98, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix(); //d leg
	glColor3ub(147, 81, 22);
	glScalef(0.29, 0.29, 1);
	glTranslatef(-0.81, -2.35, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix(); //d hand
	glColor3ub(147, 81, 22);
	glScalef(0.4, 0.15, 1);
	glTranslatef(-0.48, -3.15, 0.0);
	draw_circle();
	glPopMatrix();


	//dress
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(3, 5, 1);
	glTranslatef(-0.049, -0.144, 0.0);
	draw_rectangle();
	glPopMatrix();

	//middress
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0, -2.4, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(-0.3, -2.4, 0.0);
	draw_circle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(.3, .3, 1);
	glTranslatef(0.31, -2.4, 0.0);
	draw_circle();
	glPopMatrix();

	//hair
	glPushMatrix();
	glColor3f(0.30196, 0.20000, 0.09804);
	glScalef(2.25, 1.5, 1);
	glTranslatef(-0.145, 0.0, 0.0);
	draw_halfcircle();
	glPopMatrix();

	//back hair
	glPushMatrix();
	glColor3f(0.30196, 0.20000, 0.09804);
	glScalef(4.45, 5, 1);
	glTranslatef(-0.049, -0.09, 0.0);
	draw_rectangle();
	glPopMatrix();
}
void grass() {

	glBegin(GL_TRIANGLES);
	glColor3ub(39, 174, 96);
	glVertex2f(0.0f, 0.0f);
	glColor3ub(25, 111, 61);
	glVertex2f(-0.02f, -0.2f);
	glVertex2f(0.02f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(39, 174, 96);
	glVertex2f(0.03f, -0.02f);
	glColor3ub(25, 111, 61);
	glVertex2f(-0.02f, -0.2f);
	glVertex2f(0.01f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(39, 174, 96);
	glVertex2f(-0.03f, -0.02f);
	glColor3ub(25, 111, 61);
	glVertex2f(-0.02f, -0.2f);
	glVertex2f(0.02f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(39, 174, 96);
	glVertex2f(0.06f, -0.05f);
	glColor3ub(25, 111, 61);
	glVertex2f(-0.02f, -0.2f);
	glVertex2f(0.02f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(39, 174, 96);
	glVertex2f(-0.06f, -0.05f);
	glColor3ub(25, 111, 61);
	glVertex2f(-0.02f, -0.2f);
	glVertex2f(0.01f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(39, 174, 96);
	glVertex2f(0.09f, -0.09f);
	glColor3ub(25, 111, 61);
	glVertex2f(-0.02f, -0.2f);
	glVertex2f(0.02f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(39, 174, 96);
	glVertex2f(-0.09f, -0.09f);
	glColor3ub(25, 111, 61);
	glVertex2f(-0.02f, -0.2f);
	glVertex2f(0.01f, -0.2f);
	glEnd();
}
void lines() {

	//story
	std::string text;
	text = "By : ";
	glColor3f(0.0, 0.0, 0.0);
	print_text(text.data(), text.size(), 390, name);
	//260
	std::string text2;
	text2 = "Roaa Fatani";

	glColor3f(0.0, 0.0, 0.0);
	print_text(text2.data(), text2.size(), 350, name1);
	//220

	std::string text3;
	text3 = "Noura Alhassani";

	glColor3f(0.0, 0.0, 0.0);
	print_text(text3.data(), text3.size(), 330, name2);
	//180
	std::string text4;
	text4 = "Afrah Almalki";

	glColor3f(0.0, 0.0, 0.0);
	print_text(text4.data(), text4.size(), 340, name3);
	//140
	std::string text5;
	text5 = "Somayah Ahmed ";

	glColor3f(0.0, 0.0, 0.0);
	print_text(text5.data(), text5.size(), 330, name4);
	//100
}

/*end Noura's methds*/
/*somaya*/
//method wrapp texture in the door <somaya ahmed >
void opendoor(){

	glColor4f(0, 0, 0, 1);
	
	glBegin(GL_QUADS);
	glVertex2f(0.44, -0.90);
	glVertex2f(0.44, -0.60);
	glVertex2f(0.48, -0.69);
	glVertex2f(0.48, -1);
	glEnd();

	glColor4f(1, 1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture6so);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);  glVertex2f(0.25, -0.9);
	glTexCoord2f(1, 0);  glVertex2f(0.25, -0.6);
	glTexCoord2f(1, 1);  glVertex2f(0.44, -0.6);
	glTexCoord2f(0, 1);  glVertex2f(0.44, -0.9);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glFlush();
}
void closedoor() {
	
	glColor4f(1, 1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture6so);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);   glVertex2f(0.44, -0.90);
	glTexCoord2f(1, 0); glVertex2f(0.44, -0.60);
	glTexCoord2f(1, 1);  glVertex2f(0.48, -0.69);
	glTexCoord2f(0, 1);  glVertex2f(0.48, -1);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glFlush();
	
}
/*end somaya methods*/
void warning() {

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-600, -600);
	glVertex2f(-600, 600);
	glVertex2f(600, 600);
	glVertex2f(600, -600);
	glEnd();

	std::string text3;
	text3 = "Warning ";

	glColor3f(1.0, 0.0, 0.0);
	print_text(text3.data(), text3.size(), 350, 300);
	
	std::string text;
	text = "Warning this game may contain scary images and effects   ";
	glColor3f(1.0, 1.0, 1.0);
	print_text(text.data(), text.size(), 150, 260);
	std::string text2;
	text2 = "that may not suit to some people , not allowed for those under 18  ";
	glColor3f(1.0, 1.0, 1.0);
	print_text(text2.data(), text2.size(), 110, 220);

	glBegin(GL_QUADS);
	glColor3f(0.20000, 0.20000, 0.20000);
	glVertex2f(-0.18,-0.6);
	glVertex2f(-0.18,-0.45);
	glVertex2f(0.1,-0.45);
	glVertex2f(0.1,-0.6);
	glEnd();
	std::string text4;
	text4 = "START ";
	glColor3f(1.0, 1.0, 1.0);
	print_text(text4.data(), text4.size(), 350, 135);
	glFlush();
}
void home() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3f(0.04314, 0.12157, 0.14902);
	glVertex2f(-600, -600);
	glVertex2f(-600, 600);
	glVertex2f(600, 600);
	glVertex2f(600, -600);
	glEnd();

	glPushMatrix();
	glTranslatef(transvaluebuyerain, transvaluebuyerain, 0.0);
	shihab();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.40000, 0.40000, 0.40000);
	glScalef(2, 2, 2);
	glTranslatef(-transvaluebuyerain - 0.2, 1, 0.0);
	cloud();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.40000, 0.40000, 0.40000);
	glScalef(2, 2, 2);
	glTranslatef(-transvaluebuyerain - 0.6, 1, 0.0);
	cloud();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.40000, 0.40000, 0.40000);
	glScalef(2, 2, 2);
	glTranslatef(-transvaluebuyerain - 0.8, 1, 0.0);
	cloud();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.40000, 0.40000, 0.40000);
	glScalef(2, 2, 2);
	glTranslatef(-transvaluebuyerain - 0.6, 0.85, 0.0);
	cloud();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.40000, 0.40000, 0.40000);
	glScalef(2, 2, 2);
	glTranslatef(-transvaluebuyerain, 0.9, 0.0);
	cloud();
	glPopMatrix();

	glPushMatrix();
	glRotatef(20.0, 0.0, 0.0, 1.0);
	glTranslatef(0, transvaluebuyerain, 0.0);
	transrain();
	glPopMatrix();

	star();


	glBegin(GL_POLYGON);
	glColor4f(0.10196, 0.09804, 0.09804, 1);
	glVertex2f(-5, -5);
	glVertex2f(-5, -0.8);
	glVertex2f(5, -0.8);
	glVertex2f(5, -5);
	glEnd();

	glColor4f(0.12549, 0.16471, 0.16471, 1);

	glBegin(GL_POLYGON);
	glVertex2f(-0.95, -1);
	glVertex2f(-0.95, 0.1);
	glVertex2f(0.5, 0.1);
	glVertex2f(0.5, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.95, 0.1);
	glVertex2f(-0.8, 0.55);
	glVertex2f(0.35, 0.55);
	glVertex2f(0.5, 0.1);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 0.55);
	glVertex2f(-0.5, 0.7);
	glVertex2f(-0.35, 0.7);
	glVertex2f(-0.35, 0.55);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(-0.53, 0.7);
	glVertex2f(-0.47, 0.9);
	glVertex2f(-0.38, 0.9);
	glVertex2f(-0.329, 0.7);
	glEnd();


	//outhome

	glColor3f(0.18431, 0.23137, 0.25882);
	glBegin(GL_POLYGON);
	glVertex2f(-0.93, -1);
	glVertex2f(-0.93, 0.08);
	glVertex2f(0.48, 0.08);
	glVertex2f(0.48, -1);
	glEnd();

	//«ÿ«— «·‰Ê«›–
	glColor3f(0.14902, 0.14902, 0.14902);
	glBegin(GL_POLYGON);
	glVertex2f(-0.80, -0.35);
	glVertex2f(-0.80, 0.02);
	glVertex2f(-0.50, 0.02);
	glVertex2f(-0.50, -0.35);
	glEnd();

	glColor3f(0.14902, 0.14902, 0.14902);
	glBegin(GL_POLYGON);
	glVertex2f(-0.40, -0.35);
	glVertex2f(-0.40, 0.02);
	glVertex2f(-0.10, 0.02);
	glVertex2f(-0.10, -0.35);
	glEnd();

	glColor3f(0.14902, 0.14902, 0.14902);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, -0.35);
	glVertex2f(0.0, 0.02);
	glVertex2f(0.30, 0.02);
	glVertex2f(0.30, -0.35);
	glEnd();
	//«·‰Ê«›– «··Ì  Õ 
	glColor3f(0.14902, 0.14902, 0.14902);
	glBegin(GL_POLYGON);
	glVertex2f(-0.80, -0.85);
	glVertex2f(-0.80, -0.5);
	glVertex2f(-0.50, -0.5);
	glVertex2f(-0.50, -0.85);
	glEnd();

	glColor3f(0.14902, 0.14902, 0.14902);
	glBegin(GL_POLYGON);
	glVertex2f(-0.40, -0.85);
	glVertex2f(-0.40, -0.5);
	glVertex2f(-0.10, -0.5);
	glVertex2f(-0.10, -0.85);
	glEnd();

	glColor3f(0.14902, 0.14902, 0.14902);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, -0.85);
	glVertex2f(0.0, -0.5);
	glVertex2f(0.30, -0.5);
	glVertex2f(0.30, -0.85);
	glEnd();

	//black
	//«ÿ«— «·‰Ê«›–
	glColor3f(0.05490, 0.04706, 0.04706);
	glBegin(GL_POLYGON);
	glVertex2f(-0.78, -0.33);
	glVertex2f(-0.78, 0.0);
	glVertex2f(-0.52, 0.0);
	glVertex2f(-0.52, -0.33);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.38, -0.33);
	glVertex2f(-0.38, 0.0);
	glVertex2f(-0.12, 0.0);
	glVertex2f(-0.12, -0.33);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.02, -0.33);
	glVertex2f(0.02, 0.0);
	glVertex2f(0.28, 0.0);
	glVertex2f(0.28, -0.33);
	glEnd();
	//«·‰Ê«›– «··Ì  Õ 

	glBegin(GL_POLYGON);
	glVertex2f(-0.78, -0.83);
	glVertex2f(-0.78, -0.52);
	glVertex2f(-0.52, -0.52);
	glVertex2f(-0.52, -0.83);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.38, -0.83);
	glVertex2f(-0.38, -0.52);
	glVertex2f(-0.12, -0.52);
	glVertex2f(-0.12, -0.83);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.02, -0.83);
	glVertex2f(0.02, -0.52);
	glVertex2f(0.28, -0.52);
	glVertex2f(0.28, -0.83);
	glEnd();

	//«ÿ«—
	glColor3f(0.25882, 0.24314, 0.24314);
	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(-0.65, -0.35);
	glVertex2f(-0.65, 0.02);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(-0.25, -0.35);
	glVertex2f(-0.25, 0.02);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(0.15, -0.35);
	glVertex2f(0.15, 0.02);
	glEnd();

	//
	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(-0.65, -0.85);
	glVertex2f(-0.65, -0.5);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(-0.25, -0.85);
	glVertex2f(-0.25, -0.5);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(0.15, -0.85);
	glVertex2f(0.15, -0.5);
	glEnd();

	//«ÿ«— ⁄—÷
	glColor3f(0.25882, 0.24314, 0.24314);
	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(-0.80, -0.175);
	glVertex2f(-0.50, -0.175);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(-0.38, -0.175);
	glVertex2f(-0.12, -0.175);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(0.02, -0.175);
	glVertex2f(0.28, -0.175);
	glEnd();

	//
	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(-0.78, -0.68);
	glVertex2f(-0.52, -0.68);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(-0.38, -0.68);
	glVertex2f(-0.12, -0.68);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(0.02, -0.68);
	glVertex2f(0.28, -0.68);
	glEnd();
	//«·”ﬁ›
	//
	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(1.1, 0.5, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.95, 0.95, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.85, 1.4, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(1.1, 0.54, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.95, 0.99, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.85, 1.44, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	//
	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.7, 0.5, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.55, 0.95, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.45, 1.4, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.7, 0.54, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.55, 0.99, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.45, 1.44, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	//
	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.3, 0.5, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.15, 0.95, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.05, 1.4, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.3, 0.54, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.15, 0.99, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(0.05, 1.44, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	//
	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.1, 0.5, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.25, 0.95, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.39, 1.4, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.1, 0.54, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.25, 0.99, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.39, 1.44, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	//
	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.50, 0.5, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.65, 0.95, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.79, 1.4, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.50, 0.54, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.65, 0.99, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.79, 1.44, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();


	//
	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.90, 0.5, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.05, 0.95, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.19, 1.4, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-0.90, 0.54, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.05, 0.99, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.19, 1.44, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	//
	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.30, 0.5, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.45, 0.95, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.59, 1.4, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.30, 0.54, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.45, 0.99, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.59, 1.44, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();


	//
	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.70, 0.5, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.85, 0.95, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.99, 1.4, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.70, 0.54, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.85, 0.99, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-1.99, 1.44, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	//
	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-2.10, 0.5, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-2.50, 0.5, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-2.25, 0.95, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27451, 0.34510, 0.38431);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-2.30, 1.4, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-2.10, 0.54, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-2.50, 0.54, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-2.25, 0.99, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12549, 0.16471, 0.16471);
	glScalef(0.33, 0.33, 1);
	glTranslatef(-2.30, 1.44, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

}
void home1() {
	//glClear(GL_COLOR_BUFFER_BIT);

	/*****************************************************************/
	//home with scale
	glPushMatrix();
	glScalef(0.5, 0.5, 1);
	home();
	glPopMatrix();
	/*****************************************************************/
	//trees
	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(1.35, 1.3, 0);
	glTranslatef(0.6, -0.4, 0);
	tree();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.6, -0.4, 0);
	tree();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.3, -0.2, 0);
	tree();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.5, -0.1, 0);
	tree();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.7, -0.15, 0);
	tree();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-1, -0.2, 0);
	tree();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-0.7, -0.1, 0);
	tree();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-0.9, -0.15, 0);
	tree();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-0.9, -0.5, 0);
	tree();
	glPopMatrix();
	/***************************************************************/
	//moon
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glPushMatrix();
	glTranslatef(0.85, 0.85, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();
	glDisable(GL_LIGHTING);

	/*********************************************************************/

	 //ground
	glBegin(GL_POLYGON);
	glColor3f(0.23137, 0.21961, 0.21961);
	glVertex2f(-1, -1);
	glVertex2f(-0.48, -0.5);
	glVertex2f(0.25, -0.5);
	glVertex2f(1, -1);
	glEnd();


	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0.6, -0.98);
	glVertex2f(0.6, -0.96);
	glVertex2f(1, -0.96);
	glVertex2f(1, -0.98);
	glEnd();
	
	/******************************************************************/
   //spider
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glRotatef(90, 0, 0, 1);
	glTranslatef(-0.7, transvaluebuyerain -0.3, 0);
	spider();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glRotatef(90, 0, 0, 1);
	glTranslatef(-0.9, transvaluebuyerain+0.5, 0);
	spider();
	glPopMatrix();

	//left spider
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glRotatef(90, 0, 0, 1);
	glTranslatef(-0.8, transvaluebuyerain+1.3, 0);
	spider();
	glPopMatrix();

	
	/*******************************************************************/
	//boma
	glPushMatrix();
	glScalef(0.75, 0.75, 1);
	glTranslatef(0.9, -1.09, 0);
	boma();
	glPopMatrix();
	
	/****************************************************************/

	glutSwapBuffers();
	glFlush();
}
void home2() {

	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	home();
	glPopMatrix();
	/*************************************************/
	//trees
	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(2.5, 2.5, 1);
	glTranslatef(0.27, -0.05, 0);
	tree();
	glPopMatrix();
	/****************************************************/
	glPushMatrix();
	glScalef(0.05, 0.05, 1);
	glTranslatef(1.9, -2.5, 0);
	eye();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.05, 0.05, 1);
	glTranslatef(4, -2.5, 0);
	eye();
	glPopMatrix();

	/***************************************************/
	//moon
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glPushMatrix();
	glTranslatef(0.85, 0.85, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	/*****************************************************/
	//story
	glPushMatrix();
	glTranslatef(0, 0, 0);
	storylines();
	glPopMatrix();

	/******************************************************************/
   // monster
	glPushMatrix();
	glScalef(n, 1, 1);
	ear();
	Face();
	eye();
	glPopMatrix();

	/******************************************************************/

	glutSwapBuffers();
	glFlush();
}
float transvaluespider;
float S;
float scalekey;
float scalebox;
float scalecloset;
float scaledoor = 0;
void home3() {

	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	///*****************************************************************/
	glBegin(GL_POLYGON);
	glColor3f(0.04314, 0.12157, 0.14902);
	glVertex2f(-600, -600);
	glVertex2f(-600, 600);
	glVertex2f(600, 600);
	glVertex2f(600, -600);
	glEnd();

	//trees
	glPushMatrix();
	glColor3f(0, 0, 0);
	glScalef(2.5, 2.5, 1);
	glTranslatef(0.27, -0.05, 0);
	tree();
	glPopMatrix();

	/***************************************/
	//moon
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glPushMatrix();
	glTranslatef(0.85, 0.85, 0.5);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	/*********************************************/

	//gosh
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glRotatef(_angle, 0, 1, 0);
	gosh();
	glPopMatrix();

	//star
	
	star();
	

	glPushMatrix();
	glTranslatef(0.3, 0, 0);
	glRotatef(0, 0, _angle, 0);
	star();
	glPopMatrix();

	//ground
	glBegin(GL_POLYGON);
	glColor4f(0.10196, 0.09804, 0.09804, 1);
	glVertex2f(-5, -5);
	glVertex2f(-5, -0.8);
	glVertex2f(5, -0.8);
	glVertex2f(5, -5);
	glEnd();
	/*********************************************************/
	//home
	glColor4f(0.12549, 0.16471, 0.16471, 1);

	glBegin(GL_POLYGON);
	glVertex2f(-0.95, -1);
	glVertex2f(-0.95, 0.1);
	glVertex2f(0.5, 0.1);
	glVertex2f(0.5, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.95, 0.1);
	glVertex2f(-0.8, 0.55);
	glVertex2f(0.35, 0.55);
	glVertex2f(0.5, 0.1);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 0.55);
	glVertex2f(-0.5, 0.7);
	glVertex2f(-0.35, 0.7);
	glVertex2f(-0.35, 0.55);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.53, 0.7);
	glVertex2f(-0.47, 0.9);
	glVertex2f(-0.38, 0.9);
	glVertex2f(-0.329, 0.7);
	glEnd();

	/*************************here rooms ***********************************/

	/**********************norah****************************/

	upRoom();

	glPushMatrix();
	glTranslatef(-0.24, 0.0, 0.0);
	glRotatef(_angle, 0, 1, 0);
	ghost();
	glPopMatrix();
	/*************************roaa********************************/

	//strinr
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture1ro);
	
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	
	glTexCoord2f(0, 0);
	glVertex3f(-0.93, -0.46, 0);

	glTexCoord2f(1, 0);
	glVertex3f(-0.93, 0.1, 0);

	glTexCoord2f(1, 1);
	glVertex3f(-0.75, 0.1, 0);

	glTexCoord2f(0, 1);
	glVertex3f(-0.75, -0.46, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	
	/************************afrah***********************************/
	glColor4f(1, 1, 1, 1);
	// «·€—›… «··Ì Ì„Ì‰
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture8af);

	glBegin(GL_QUADS);

	glTexCoord2f(0, 1); glVertex2f(-0.73, -0.46);
	glTexCoord2f(1, 1); glVertex2f(-0.73, 0.1);
	glTexCoord2f(1, 0); glVertex2f(-0.3, 0.1);
	glTexCoord2f(0, 0);	glVertex2f(-0.3, -0.46);
	glEnd();


	glDisable(GL_TEXTURE_2D);
	//«·€—›… «··Ì ⁄ Ì”«—
	glColor4f(1, 1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture7af);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(-0.28, -0.46);
	glTexCoord2f(1, 0); glVertex2f(-0.28, 0.1);
	glTexCoord2f(1, 1); glVertex2f(0.48, 0.1);
	glTexCoord2f(0, 1); glVertex2f(0.48, -0.46);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	////////
	box();

	glPushMatrix();
	glScalef(scalebox, 1, 1);
	box2();
	glPopMatrix();

	glPushMatrix();
	glScalef(scalekey, 1, 1);
	key1();
	glPopMatrix();

	glPushMatrix();
	glScalef(scalekey, 1, 1);
	key1();
	glPopMatrix();

	closet();
	glPushMatrix();
	glScalef(scalecloset, 1, 1);
	closet1();
	glPopMatrix();


	glPushMatrix();
	glScalef(S, 1, 1);
	glTranslatef(-0.05, transvaluespider, 0.0);
	spider();
	glPopMatrix();
	/******************************roaa********************************/
	//strainer
	glColor3f(1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture2ro);

	
	glBegin(GL_QUADS);

	glNormal3f(0, 0, 1);

	glTexCoord2f(0, 0);
	glVertex2f(-0.93, -1);

	glTexCoord2f(0, 1);
	glVertex2f(-0.93, -0.48);

	glTexCoord2f(1, 1);
	glVertex2f(-0.75, -0.48);

	glTexCoord2f(1, 0);
	glVertex2f(-0.75, -1);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	/************************somaya**************************/

	glColor4f(1, 1, 1, 1);
	// «·€—›… «··Ì ⁄ Ì”«—
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture3so);
	
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(-0.73, -1);
	glTexCoord2f(0, 1);
	glVertex2f(-0.73, -0.48);
	glTexCoord2f(1, 1);
	glVertex2f(-0.3, -0.48);
	glTexCoord2f(1, 0);
	glVertex2f(-0.3, -1);
	glEnd();

	//under room left
	glColor4f(1, 1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture4so);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(-0.28, -1);
	glTexCoord2f(0, 1);
	glVertex2f(-0.28, -0.48);
	glTexCoord2f(1, 1);
	glVertex2f(0.48, -0.48);
	glTexCoord2f(1, 0);
	glVertex2f(0.48, -1);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	closedoor();

	glPushMatrix();
	glScalef(scaledoor, 1, 1);
	opendoor();
	glPopMatrix();
	/************************girl******************************/

	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	glScalef(0.3, 0.3, 1);
	girl();
	glPopMatrix();

	/**************************************************************/

	glutSwapBuffers();
	glFlush();


}
void home4() {
	glClear(GL_COLOR_BUFFER_BIT);

	//glBegin(GL_POLYGON);
	//glColor3f(0.90196, 0.94902, 1.00000);
	//glVertex2f(-600, -600);
	//glVertex2f(-600, 600);
	//glVertex2f(600, 600);
	//glVertex2f(600, -600);
	//glEnd();
	///******************************************************************/
	////moon
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular2);
	//glLightfv(GL_LIGHT0, GL_POSITION, light_position2);

	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	//glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);

	//glPushMatrix();
	//glTranslatef(0.85, 0.85, 0.5);
	//glutSolidSphere(0.2, 50, 50);
	//glPopMatrix();
	/*glDisable(GL_LIGHTING);*/
	/************************************************************/
	//////////////////////////////////////////////////////////////last 
	glBegin(GL_POLYGON);
	glColor3ub(252, 243, 207);
	glVertex2f(-600, -600);
	glColor3ub(174, 214, 241);
	glVertex2f(-600, 600);
	glVertex2f(600, 600);
	glColor3ub(252, 243, 207);
	glVertex2f(600, -600);
	glEnd();

	
	/************************************************************/
	//ground

	drawCircle(0.0, -0.8, 0.6, 25, 111, 61);
	drawCircle(-0.6, -1.0, 0.8, 25, 111, 61);
	drawCircle(0.7, -0.9, 0.7, 25, 111, 61);

	/************************************************************/
	//tree

	//tree();

	glPushMatrix();
	glScalef(1, 1, 1);
	glTranslatef(0.1, 0.0, 0);
	tree2();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.3, 1.3, 1);
	glTranslatef(0.3, 0.0, 0);
	tree2();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.7, 1.7, 1);
	glTranslatef(0.47, 0.04, 0);
	tree2();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.3, 1.3, 1);
	glTranslatef(-0.4, 0.0, 0);
	tree2();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.7, 1.7, 1);
	glTranslatef(-0.65, 0.04, 0);
	tree2();
	glPopMatrix();

	/************************************************************/
	//cloud

	glPushMatrix();
	glScalef(1.4, 1.4, 1.0);
	glTranslatef(0.0, 0.4, 0.0);
	cloud2();
	glPopMatrix();

	glPushMatrix();
	glScalef(2, 2, 1.0);
	glTranslatef(0.34, 0.35, 0.0);
	cloud2();
	glPopMatrix();

	glPushMatrix();
	glScalef(2.4, 2.4, 1.0);
	glTranslatef(-0.3, 0.34, 0.0);
	cloud2();
	glPopMatrix();

	/************************************************************/
	//grass

	glPushMatrix();
	glScalef(1.0, 1.0, 1);
	glTranslatef(0.46, -0.23, 0);
	grass();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.0, 1.0, 1);
	glTranslatef(-0.46, -0.23, 0);
	grass();
	glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3ub(245, 203, 167);
	glVertex2f(-0.02, -0.2);
	glVertex2f(0.02, -0.2);
	glVertex2f(0.3, -1.0);
	glVertex2f(-0.3, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(237, 187, 153);
	glVertex2f(-0.01, -0.2);
	glVertex2f(0.01, -0.2);
	glVertex2f(0.2, -1.0);
	glVertex2f(-0.2, -1.0);
	glEnd();

	/************************************************************/
	//girl

	glPushMatrix();
	glTranslatef(0.0, transvaluegirl, 0.0);
	glScalef(scalevaluegirl, scalevaluegirl, 1);
	girl2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0);
	lines();
	glPopMatrix();


	glutSwapBuffers();
	glFlush();

}
void background(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3f(0.04314, 0.12157, 0.14902);
	glVertex2f(-600, -600);
	glVertex2f(-600, 600);
	glVertex2f(600, 600);
	glVertex2f(600, -600);
	glEnd();
	/***********************************************************/
	 //stars
	glPushMatrix();
	star();
	glPopMatrix();
	/*******************************************************/
	//moon
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glPushMatrix();
	glTranslatef(-0.3, 0, 0.5);
	glRotatef(_angle, 0, 1, 0);
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	/***************************************************/

	glutSwapBuffers();
	glFlush();
}
void display(void)
{
	glClearColor(1., 1., 1., 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	warning();
	//PlaySound(TEXT("mixkit-wolf-howling.wav"), NULL, SND_ASYNC);

	glutSwapBuffers();
	glFlush();
}
void keyboard(unsigned char keyPressed, int x, int y) // key handling
{
	switch (keyPressed) {

	case GLUT_KEY_RIGHT://f
	{
		if (posX <= 0.7) {
			posX += 0.1;
		}
		else {
			posX -= 0.1;
		}
		cout << "translate " << posX << endl;
		glutPostRedisplay();
		break;
	}

	case GLUT_KEY_LEFT://d
	{
		if (posX >= -0.8) {
			posX -= 0.1;
		}
		else {
			posX += 0.1;
		}
		cout << "translate  " << posX << endl;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_UP://e
	{
		if (posY <= 0.1) {
			posY += 0.1;
		}
		else {
			posY -= 0.1;
		}
		cout << "translate  " << posY << endl;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_DOWN://g
	{
		if (posY >= -0.7) {
			posY -= 0.1;
		}
		else {
			posY += 0.1;
		}
		cout << "translate  " << posY << endl;
		glutPostRedisplay();
		break;
	}
	
	case '1':
	{
		PlaySound(NULL, 0, 0);

		glutDisplayFunc(background);
		PlaySound(TEXT("mixkit-wolf-howling.wav"), NULL, SND_ASYNC);
		
		glutMainLoop();

		break;
	}
	case '2':
	{
		PlaySound(NULL, 0, 0);
		
		glutDisplayFunc(home1);
		PlaySound(TEXT("thunder-with-rain.wav"), NULL, SND_ASYNC);
		glutMainLoop();
		break;
	}
	case '3':
	{
		PlaySound(NULL, 0, 0);
		glutDisplayFunc(home2);
		PlaySound(TEXT("mixkit-scary-graveyard-wind-1157"), NULL, SND_ASYNC);
		glutMainLoop();
		break;
	}
	case '4':
	{
		PlaySound(NULL, 0, 0);
		glutDisplayFunc(home3);
		PlaySound(TEXT("ScaryMusic2018-10-12_-_It_Is_Coming_-_David_Fesliyan.wav"), NULL, SND_ASYNC);
		glutMainLoop();
		break;
	}

	case '5':
	{
		PlaySound(NULL, 0, 0);
		glutDisplayFunc(home4);
		PlaySound(TEXT("mixkit-walking-in-the-forest-1214.wav"), NULL, SND_ASYNC);
		glutMainLoop();
		break;
	}
	case 'l':
		if (storyline1trany < 220) {
			storyline1trany = storyline1trany + 40;
			break;
		}

		if (storyline2trany < 180) {
			storyline2trany = storyline2trany + 40;

			break;
		}

		if (storyline3trany < 140) {
			storyline3trany = storyline3trany + 40;
			break;
		}

		if (storyline4trany < 100) {
			storyline4trany = storyline4trany + 40;
			break;
		}
		if (storyline5trany < 60) {

			storyline5trany = storyline5trany + 40;
			break;
		}

	case 'n':
		PlaySound(TEXT("surprise"), NULL, SND_ASYNC);
		n = +1;
		
		break;
	
	case 't'://
		/*scalebox = 1.0;
		break;*/
		
		scalebox = 1.0;
		//PlaySound(TEXT("box open.wav"),  NULL, SND_ASYNC);
		glutMainLoop();

		break;
	case 'k'://kEY appears
		scalekey = 1.0;

		break;
	case 'j'://kEY 
		scalekey = scalekey - 1.0;
		K = 1;
		break;
	case 'm'://Move spider
		transvaluespider = transvaluespider - 0.01;

		break;
	case 'c'://closet appears
		scalecloset = 1;
		S = S + 1.0;

		break;
	case 'G'://Move girl

		transvaluegirl = transvaluegirl + 0.01;

		if (scalevaluegirl >= 0.00600004) {
			scalevaluegirl -= 0.007;
		}

		cout << "scalevaluegir  " << scalevaluegirl << endl;
		break;
	case 'r':
		scaledoor = 1;
		K = 0;
		break;

	case 'L':
		if (name < 780) {
			name = name + 40;
			name1 = name1 + 40;
			name2 = name2 + 40;
			name3 = name3 + 40;
			name4 = name4 + 40;
			break;
		}
	case 's'://Move girl

		
		break;
	default:
		exit(0);
		break;

	}
}
static void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_UP) {
			transvaluebuyerain = transvaluebuyerain - 0.1;
			m = 0;

		}
	}
	if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_UP) {
			m = 0.2;

		}
	}
	glutPostRedisplay();
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1, 1, -1, 1, -1, 1);
	myTexture1ro = LoadTexture(image1Path, 512, 512);
	myTexture2ro = LoadTexture(image2Path, 512, 512);
	myTexture3so = LoadTexture(image3Path, 512, 512);
	myTexture4so = LoadTexture(image4Path, 512, 512);
	myTexture5so = LoadTexture(image5Path, 512, 512);
	myTexture6so = LoadTexture(image6Path, 512, 512);
	myTexture7af = LoadTexture(image7Path, 512, 512);
	myTexture8af = LoadTexture(image8Path, 512, 512);
	myTexture9af = LoadTexture(image9Path, 512, 512);
	myTexture10af = LoadTexture(image10Path, 512, 512);
	myTexture11no = LoadTexture(image11Path, 512, 512);
	myTexture12no = LoadTexture(image12Path, 512, 512);
	myTexture13af = LoadTexture(image13Path, 512, 512);
	myTexture14af = LoadTexture(image14Path, 512, 512);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(65, (win_width / win_hight), 0.01, 50);

	glMatrixMode(GL_MODELVIEW);
	
}

int main(int argc, char** argv)
{
	
	glutInit(&argc, argv);
	glutInitWindowSize(900, 750);
	glutInitWindowPosition(100, 10);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("project");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glClearColor(1, 1, 1, 1);

    init();
	m = 0;

	glutDisplayFunc(display); PlaySound(TEXT("start.wav"), NULL, SND_ASYNC);

	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	glutReshapeFunc(reshape);
	glutTimerFunc(25, update, 0);
	glutMainLoop();

	return 0;
}