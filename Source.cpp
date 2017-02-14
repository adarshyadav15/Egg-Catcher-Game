#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>


float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

float cloudspeed = 0.03;
bool cloudMoveRight = true;
float cloudX = -6.0;

float murgiSpeed = 0.03;
bool moveRight = true;
bool layEgg = true;
bool gameOver = false;
bool begin = true;

float murgiX = -0.55;
float murgiY = 0.0;
float murgiWidth = 1.10;
float murgiHeight = 0.66;
float mps = 0.11;

float dimX = murgiX + 0.55;
float dimWidth = 0.36;
float dimY = murgiY;
float dimHeight = 0.42;
float dimSpeed = 0.02;
float dps = 0.03;

float sunY = 1.0;
bool sunMoveup = true;

float baltiX = -0.35;
float baltiWidth = 0.70;
float baltiY = -3.00;
float baltiHeight = 0.70;

int count = 0;



void circle(float radius)
{
	glBegin(GL_POLYGON);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = radius;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();

}

void cloudOne()
{
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(cloudX, 2.2, 0.0); //Move to the center of the trapezoid
	glColor3f(1.0, 1.0, 1.0);
	circle(0.35);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(cloudX - 0.5, 2.2, 0.0); //Move to the center of the trapezoid
	glColor3f(1.0, 1.0, 1.0);
	circle(0.45);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(cloudX - 1.0, 2.2, 0.0); //Move to the center of the trapezoid
	glColor3f(1.0, 1.0, 1.0);
	circle(0.35);
	glPopMatrix();
}

void cloudTwo()
{

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(cloudX - 3.0, 2.2, 0.0); //Move to the center of the trapezoid
	glColor3f(1.0, 1.0, 1.0);
	circle(0.35);
	glPopMatrix();


	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(cloudX - 3.5, 2.2, 0.0); //Move to the center of the trapezoid
	glColor3f(1.0, 1.0, 1.0);
	circle(0.45);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(cloudX - 4.0, 2.2, 0.0); //Move to the center of the trapezoid
	glColor3f(1.0, 1.0, 1.0);
	circle(0.35);
	glPopMatrix();

}

void sun()
{
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(3.0, sunY, 0.0); //Move to the center of the trapezoid
	//glRotatef(-_cameraAngle, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	//glutSolidSphere(0.55, 30, 20);
	circle(0.55);
	glPopMatrix();
}

void Ultachicken(float murgiX, float murgiY)
{


	glBegin(GL_POINTS);
	glColor3f(0.1, 0.1, 0.1);
	glPointSize(5.5);
	glVertex2f(murgiX + mps * (1.5), murgiY + mps * 8);
	glEnd();
	glFlush();
	//--thang--
	glColor3f(1.0, 0.8, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(murgiX + mps * 4, murgiY + mps * 0, 0.0);
	glVertex3f(murgiX + mps * 4, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*3.35, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*3.35, murgiY + mps * 0, 0.0);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);

	glVertex3f(murgiX + mps * 5, murgiY + mps * 0, 0.0);
	glVertex3f(murgiX + mps*5.65, murgiY + mps * 0, 0.0);
	glVertex3f(murgiX + mps*5.65, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps * 5, murgiY + mps*(-2), 0.0);
	glEnd();
	glFlush();


	glColor3f(1.0, 0.8, 0.5);
	//body
	glBegin(GL_POLYGON);
	glVertex3f(murgiX + mps*0.3, murgiY + mps * 6, 0.0);
	glVertex3f(murgiX + mps * 0, murgiY + mps * 4, 0.0);
	glVertex3f(murgiX + mps * 0, murgiY + mps * 2, 0.0);
	glVertex3f(murgiX + mps * 1, murgiY + mps * 1, 0.0);
	glVertex3f(murgiX + mps * 3, murgiY + mps * 0, 0.0);
	glColor3f(1.0, 1.0, 0.8);
	glVertex3f(murgiX + mps * 6, murgiY + mps * 0, 0.0);
	glVertex3f(murgiX + mps * 8, murgiY + mps * 1, 0.0);
	glVertex3f(murgiX + mps * 10, murgiY + mps * 3, 0.0);
	glVertex3f(murgiX + mps * 11, murgiY + mps * 6, 0.0);
	glEnd();
	glFlush();

	//matha
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.8, 0.5);
	glVertex3f(murgiX + mps*0.3, murgiY + mps * 6, 0.0);
	glVertex3f(murgiX + mps * 0, murgiY + mps * 7, 0.0);
	glVertex3f(murgiX + mps * 0, murgiY + mps * 8, 0.0);
	glVertex3f(murgiX + mps * 1, murgiY + mps * 9, 0.0);
	glColor3f(1.0, 1.0, 0.8);
	glVertex3f(murgiX + mps * 3, murgiY + mps * 9, 0.0);
	glVertex3f(murgiX + mps * 4, murgiY + mps * 8, 0.0);
	glVertex3f(murgiX + mps*4.8, murgiY + mps * 6, 0.0);
	glVertex3f(murgiX + mps*5.5, murgiY + mps * 6, 0.0);
	glEnd();
	glFlush();

	//jhuti
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.3, 0.3);

	glVertex3f(murgiX + mps*0.7, murgiY + mps*7.5, 0.0);
	glVertex3f(murgiX + mps*0.4, murgiY + mps*9.8, 0.0);
	glVertex3f(murgiX + mps*1.4, murgiY + mps*9.3, 0.0);
	glVertex3f(murgiX + mps*1.8, murgiY + mps * 10, 0.0);
	glVertex3f(murgiX + mps*2.5, murgiY + mps*9.2, 0.0);
	glVertex3f(murgiX + mps*3.2, murgiY + mps*9.8, 0.0);
	glVertex3f(murgiX + mps*3.8, murgiY + mps*8.8, 0.0);
	glVertex3f(murgiX + mps*4.4, murgiY + mps*9.5, 0.0);
	glVertex3f(murgiX + mps * 3, murgiY + mps * 7, 0.0);
	glEnd();
	glFlush();


	//bick
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.1, 0.1);

	glVertex3f(murgiX + mps * 0, murgiY + mps * 7, 0.0);
	glVertex3f(murgiX + mps*(-1), murgiY + mps*7.5, 0.0);
	glVertex3f(murgiX + mps * 0, murgiY + mps * 8, 0.0);

	glEnd();
	glFlush();

	//fingers
	glColor3f(1.0, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(murgiX + mps * 3.8, murgiY + mps * -2.7, 0.0);
	glVertex3f(murgiX + mps * 3.8, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*3.6, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*3.6, murgiY + mps * -2.7, 0.0);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex3f(murgiX + mps * 3, murgiY + mps * -2.7, 0.0);
	glVertex3f(murgiX + mps * 3.4, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*3.7, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*3.2, murgiY + mps * -2.7, 0.0);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex3f(murgiX + mps * 4.2, murgiY + mps * -2.7, 0.0);
	glVertex3f(murgiX + mps * 3.6, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*3.9, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*4.4, murgiY + mps * -2.7, 0.0);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);

	//fingers
	glColor3f(1.0, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(murgiX + mps * 5.5, murgiY + mps * -2.7, 0.0);
	glVertex3f(murgiX + mps * 5.5, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*5.3, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*5.3, murgiY + mps * -2.7, 0.0);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex3f(murgiX + mps * 4.7, murgiY + mps * -2.7, 0.0);
	glVertex3f(murgiX + mps * 5.1, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*5.4, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*4.9, murgiY + mps * -2.7, 0.0);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex3f(murgiX + mps * 5.9, murgiY + mps * -2.7, 0.0);
	glVertex3f(murgiX + mps * 5.3, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*5.6, murgiY + mps*(-2), 0.0);
	glVertex3f(murgiX + mps*6.1, murgiY + mps * -2.7, 0.0);
	glEnd();
	glFlush();

	glColor3f(0.1, 0.1, 0.1);

	glPointSize(5.5);
	glBegin(GL_POINTS);
	glVertex3f(murgiX - mps*-1, murgiY + mps * 8, 0.0);


	glEnd();
	glFlush();
}

void sojachicken(float murgiX)
{

	glBegin(GL_POINTS);
	glColor3f(0.1, 0.1, 0.1);
	glPointSize(5.5);
	glVertex2f(murgiX + mps * (-1.5), murgiY + mps * 8);
	glEnd();
	glFlush();

	//--thang--
	glColor3f(1.0, 0.8, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(murgiX - mps * 4, murgiY + mps * 0);
	glVertex2f(murgiX - mps * 4, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*3.35, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*3.35, murgiY + mps * 0);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);

	glVertex2f(murgiX - mps * 5, murgiY + mps * 0);
	glVertex2f(murgiX - mps*5.65, murgiY + mps * 0);
	glVertex2f(murgiX - mps*5.65, murgiY + mps*(-2));
	glVertex2f(murgiX - mps * 5, murgiY + mps*(-2));
	glEnd();
	glFlush();


	glColor3f(1.0, 0.8, 0.5);
	//body
	glBegin(GL_POLYGON);
	glVertex2f(murgiX - mps*0.3, murgiY + mps * 6);
	glVertex2f(murgiX - mps * 0, murgiY + mps * 4);
	glVertex2f(murgiX - mps * 0, murgiY + mps * 2);
	glVertex2f(murgiX - mps * 1, murgiY + mps * 1);
	glVertex2f(murgiX - mps * 3, murgiY + mps * 0);
	glColor3f(1.0, 1.0, 0.8);
	glVertex2f(murgiX - mps * 6, murgiY + mps * 0);
	glVertex2f(murgiX - mps * 8, murgiY + mps * 1);
	glVertex2f(murgiX - mps * 10, murgiY + mps * 3);
	glVertex2f(murgiX - mps * 11, murgiY + mps * 6);
	glEnd();
	glFlush();
	//glVertex2f(murgiX+mps*5,murgiY+mps*5.5);


	//matha
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.8, 0.5);
	glVertex2f(murgiX - mps*0.3, murgiY + mps * 6);
	glVertex2f(murgiX - mps * 0, murgiY + mps * 7);
	glVertex2f(murgiX - mps * 0, murgiY + mps * 8);
	glVertex2f(murgiX - mps * 1, murgiY + mps * 9);
	glColor3f(1.0, 1.0, 0.8);
	glVertex2f(murgiX - mps * 3, murgiY + mps * 9);
	glVertex2f(murgiX - mps * 4, murgiY + mps * 8);
	glVertex2f(murgiX - mps*4.8, murgiY + mps * 6);
	glVertex2f(murgiX - mps*5.5, murgiY + mps * 6);
	glEnd();
	glFlush();

	//jhuti
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.3, 0.3);

	glVertex2f(murgiX - mps*0.7, murgiY + mps*7.5);
	glVertex2f(murgiX - mps*0.4, murgiY + mps*9.8);
	glVertex2f(murgiX - mps*1.4, murgiY + mps*9.3);
	glVertex2f(murgiX - mps*1.8, murgiY + mps * 10);
	glVertex2f(murgiX - mps*2.5, murgiY + mps*9.2);
	glVertex2f(murgiX - mps*3.2, murgiY + mps*9.8);
	glVertex2f(murgiX - mps*3.8, murgiY + mps*8.8);
	glVertex2f(murgiX - mps*4.4, murgiY + mps*9.5);
	glVertex2f(murgiX - mps * 3, murgiY + mps * 7);
	glEnd();
	glFlush();


	//lips
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.1, 0.1);

	glVertex2f(murgiX - mps * 0, murgiY + mps * 7);
	glVertex2f(murgiX - mps*(-1), murgiY + mps*7.5);
	glVertex2f(murgiX - mps * 0, murgiY + mps * 8);

	glEnd();
	glFlush();


	//fingers
	glColor3f(1.0, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(murgiX - mps * 3.8, murgiY + mps * -2.7);
	glVertex2f(murgiX - mps * 3.8, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*3.6, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*3.6, murgiY + mps * -2.7);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex2f(murgiX - mps * 3, murgiY + mps * -2.7);
	glVertex2f(murgiX - mps * 3.4, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*3.7, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*3.2, murgiY + mps * -2.7);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex2f(murgiX - mps * 4.2, murgiY + mps * -2.7);
	glVertex2f(murgiX - mps * 3.6, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*3.9, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*4.4, murgiY + mps * -2.7);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);

	//fingers
	glColor3f(1.0, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(murgiX - mps * 5.5, murgiY + mps * -2.7);
	glVertex2f(murgiX - mps * 5.5, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*5.3, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*5.3, murgiY + mps * -2.7);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex2f(murgiX - mps * 4.7, murgiY + mps * -2.7);
	glVertex2f(murgiX - mps * 5.1, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*5.4, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*4.9, murgiY + mps * -2.7);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex2f(murgiX - mps * 5.9, murgiY + mps * -2.7);
	glVertex2f(murgiX - mps * 5.3, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*5.6, murgiY + mps*(-2));
	glVertex2f(murgiX - mps*6.1, murgiY + mps * -2.7);
	glEnd();
	glFlush();

}

void egg(float ex, float ey) {
	glColor3f(1.0, 0.8, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(dimX + dps * 5, dimY - dps * 0);
	glVertex2f(dimX + dps * 3.5, dimY - dps * 1);
	glVertex2f(dimX + dps * 2, dimY - dps * 2);
	glVertex2f(dimX + dps * 1, dimY - dps * 4);
	glVertex2f(dimX + dps * 0, dimY - dps * 7);
	glVertex2f(dimX + dps * 0, dimY - dps * 9);
	glVertex2f(dimX + dps * 1, dimY - dps *11.5);
	glVertex2f(dimX + dps * 2, dimY - dps * 13);
	glVertex2f(dimX + dps * 4, dimY - dps * 14);
	glColor3f(0.95, 0.77, 0.38);
	glVertex2f(dimX + dps * 8, dimY - dps * 14);

	glVertex2f(dimX + dps * 10, dimY - dps * 13);
	glVertex2f(dimX + dps * 11, dimY - dps *11.5);
	glVertex2f(dimX + dps * 12, dimY - dps * 9);
	glVertex2f(dimX + dps * 12, dimY - dps * 7);
	glVertex2f(dimX + dps * 11, dimY - dps * 4);
	glColor3f(1.0, 0.8, 0.5);
	glVertex2f(dimX + dps * 10, dimY - dps * 2);
	glVertex2f(dimX + dps * 8.5, dimY - dps * 1);
	glVertex2f(dimX + dps * 7, dimY - dps * 0);

	glEnd();
	glFlush();

}

void balti()
{
	glPushMatrix();
	glColor3f(0.94, 0.4, 0.2);
	glBegin(GL_QUADS);
	glVertex3f(baltiX - 0.10, baltiY + baltiHeight, 0.0);
	glVertex3f(baltiX, baltiY, 0.0);
	glColor3f(0.8, 0.3, 0.1);
	glVertex3f(baltiX + baltiWidth, baltiY, 0.0);
	glVertex3f(baltiX + baltiWidth + 0.10, baltiY + baltiHeight, 0.0);
	glEnd();
	glPopMatrix();
	glFlush();
}

void tree()
{
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-5.02, 0.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 51.0, 0.0);
	circle(0.65);   
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-4.02, 0.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 51.0, 0.0);
	circle(0.65);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-4.6, 0.9, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 51.0, 0.0);
	circle(0.65);
	glPopMatrix();

	glColor3f(0.61, 0.3, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(-4.4, -2.0, 0.0);
	glVertex3f(-4.7, -2.0, 0.0);
	glVertex3f(-4.6, 0.0, 0.0);
	glVertex3f(-4.5, 0.0, 0.0);
	glEnd();
	


	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(4.6, 0.9, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 51.0, 0.0);
	circle(0.55);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(3.8, 0.9, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 51.0, 0.0);
	circle(0.55);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(4.2, 1.5, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0,51.0, 0.0);
	circle(0.55);
	glPopMatrix();

	glColor3f(0.61, 0.3, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(4.0, -1.0, 0.0);
	glVertex3f(4.3, -1.0, 0.0);
	glVertex3f(4.2, 1.0, 0.0);
	glVertex3f(4.1, 1.0, 0.0);
	glEnd();

}

void stickAndRope()
{
	glColor3f(0.61, 0.3, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(1.5, -3.0, 0.0);
	glVertex3f(1.4, -3.0, 0.0);
	glVertex3f(1.4, -0.3, 0.0);
	glVertex3f(1.5, -0.3, 0.0);
	glEnd();

	glColor3f(0.61, 0.3, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(-5.5, -3.0, 0.0);
	glVertex3f(-5.4, -3.0, 0.0);
	glVertex3f(-5.4, -0.3, 0.0);
	glVertex3f(-5.5, -0.3, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex3f(1.5, -0.3, 0.0);
	glVertex3f(-5.5, -0.3, 0.0);
	glEnd();
}

void surface()
{
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-7.0, 1.0, 0.0);
	glVertex3f(7.0, 1.0, 0.0);
	glVertex3f(7.0, -3.0, 0.0);
	glVertex3f(-7.0, -3.0, 0.0);
	glEnd();
}

void peaks()
{
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(5.07, 1.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 1.0, 0.0);
	circle(0.57);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(4.05, 1.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 1.0, 0.0);
	circle(0.55);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(3.05, 1.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 1.0, 0.0);
	circle(0.55);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(2.05, 1.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 1.0, 0.0);
	circle(0.55);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(1.05, 1.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 1.0, 0.0);
	circle(0.55);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.01, 1.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 1.0, 0.0);
	circle(0.57);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.01, 1.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 1.0, 0.0);
	circle(0.57);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-2.05, 1.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 1.0, 0.0);
	circle(0.55);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-3.05, 1.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 1.0, 0.0);
	circle(0.56);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-4.09, 1.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 1.0, 0.0);
	circle(0.57);
	glPopMatrix();

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-5.15, 1.0, 0.0); //Move to the center of the trapezoid
	glColor3f(0.0, 1.0, 0.0);
	circle(0.57);
	glPopMatrix();
}

void sky()
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-7.0, 0.55, 0.0);
	glVertex3f(7.0, 0.55, 0.0);
	glVertex3f(7.0, 3.0, 0.0);
	glVertex3f(-7.0, 3.0, 0.0);
	glEnd();
}

void cloths()
{
	//clip
	glColor3f(0.9, 0.2, 0.2);
	glBegin(GL_QUADS);
	glVertex3f(-4.23, -0.3, 0.0);
	glVertex3f(-4.23, -0.16, 0.0);
	glVertex3f(-4.17, -0.16, 0.0);
	glVertex3f(-4.17, -0.3, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glVertex3f(-3.43, -0.3, 0.0);
	glVertex3f(-3.43, -0.16, 0.0);
	glVertex3f(-3.37, -0.16, 0.0);
	glVertex3f(-3.37, -0.3, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glVertex3f(-0.27, -0.3, 0.0);
	glVertex3f(-0.27, -0.16, 0.0);
	glVertex3f(-0.33, -0.16, 0.0);
	glVertex3f(-0.33, -0.3, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glVertex3f(-1.17, -0.3, 0.0);
	glVertex3f(-1.17, -0.16, 0.0);
	glVertex3f(-1.23, -0.16, 0.0);
	glVertex3f(-1.23, -0.3, 0.0);
	glEnd();
	glFlush();

	//pant
	glColor3f(0.16, 0.26, 0.4);
	glBegin(GL_POLYGON);
	glVertex3f(-4.20, -0.30, 0.0);
	glVertex3f(-4.40, -1.50, 0.0);
	glVertex3f(-4.00, -1.50, 0.0);
	glVertex3f(-3.80, -0.80, 0.0);
	glVertex3f(-3.80, -0.35, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glVertex3f(-3.40, -0.30, 0.0);
	glVertex3f(-3.20, -1.50, 0.0);
	glVertex3f(-3.60, -1.50, 0.0);
	glVertex3f(-3.80, -0.80, 0.0);
	glVertex3f(-3.80, -0.35, 0.0);
	glEnd();
	glFlush();

	//shirt
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
	glVertex3f(-0.30, -0.30, 0.0);
	glVertex3f(-0.00, -0.70, 0.0);
	glVertex3f(-0.25, -0.70, 0.0);
	glVertex3f(-0.55, -0.40, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glVertex3f(-1.20, -0.30, 0.0);
	glVertex3f(-1.50, -0.70, 0.0);
	glVertex3f(-1.25, -0.70, 0.0);
	glVertex3f(-0.95, -0.40, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glVertex3f(-0.40, -0.40, 0.0);
	glVertex3f(-0.40, -1.40, 0.0);
	glVertex3f(-1.10, -1.40, 0.0);
	glVertex3f(-1.10, -0.40, 0.0);
	glEnd();
	glFlush();

}

void house()
{

	glBegin(GL_LINE_LOOP);//for win01
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(2.40, -0.63, 0.0);
	glVertex3f(2.40, -0.20, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);//for win02
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(3.15, -0.68, 0.0);
	glVertex3f(3.15, -0.20, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);//for win01
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(2.15, -0.40, 0.0);
	glVertex3f(2.60, -0.40, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);//for win02
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(2.90, -0.40, 0.0);
	glVertex3f(3.35, -0.40, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.50, 1.0); //window
	glVertex3f(2.15, -0.60, 0.0);
	glVertex3f(2.15, -0.20, 0.0);
	glVertex3f(2.60, -0.20, 0.0);
	glVertex3f(2.60, -0.65, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.50, 1.0); //window2
	glVertex3f(2.90, -0.65, 0.0);
	glVertex3f(2.90, -0.20, 0.0);
	glVertex3f(3.35, -0.20, 0.0);
	glVertex3f(3.35, -0.70, 0.0);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.0, 0.50, 1.0); //door
	glVertex3f(3.80, -0.97, 0.0);
	glVertex3f(3.80, -0.20, 0.0);
	glVertex3f(4.20, -0.20, 0.0);
	glVertex3f(4.20, -0.93, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0); //ber
	glVertex3f(1.95, -0.95, 0.0);
	glVertex3f(1.95, -0.85, 0.0);
	glVertex3f(3.55, -1.00, 0.0);
	glVertex3f(3.55, -1.10, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0); //ber2
	glVertex3f(3.55, -1.00, 0.0);
	glVertex3f(3.55, -1.10, 0.0);
	glVertex3f(4.55, -0.95, 0.0);
	glVertex3f(4.55, -0.85, 0.0);
	glEnd();



	//HOUSE...........
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.7, 0.0); //1
	glVertex3f(3.50, -1.00, 0.0);
	glVertex3f(4.50, -0.90, 0.0);
	glVertex3f(4.50, -0.10, 0.0);
	glVertex3f(3.50, -0.10, 0.0);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0); //2
	glVertex3f(2.65, 0.80, 0.0);
	glVertex3f(3.80, 0.75, 0.0);
	glVertex3f(4.65, -0.10, 0.0);
	glVertex3f(3.55, -0.10, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.5, 0.0); //3
	glVertex3f(2.00, -0.05, 0.0);
	glVertex3f(3.55, -0.10, 0.0);
	glVertex3f(3.55, -1.00, 0.0);
	glVertex3f(2.00, -0.85, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.5, 0.0); //4
	glVertex3f(2.00, -0.05, 0.0);
	glVertex3f(2.75, 0.70, 0.0);
	glVertex3f(3.55, -0.10, 0.0);
	glVertex3f(2.00, -0.05, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.50, 1.0); //5
	glVertex3f(2.75, 0.70, 0.0);
	glVertex3f(2.65, 0.80, 0.0);
	glVertex3f(1.90, -0.15, 0.0);
	glVertex3f(2.00, -0.15, 0.0);
	glEnd();

}

void road()
{
	glBegin(GL_QUADS);
	glColor3f(0.55f, 0.5f, 0.1f); //5
	glVertex3f(3.70, -1.00, 0.0);
	glVertex3f(4.30, -1.00, 0.0);
	glVertex3f(4.70, -1.80, 0.0);
	glVertex3f(4.30, -1.80, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.55f, 0.5f, 0.1f); //5
	glVertex3f(4.30, -0.80, 0.0);
	glVertex3f(4.80, -1.80, 0.0);
	glVertex3f(2.00, -3.00, 0.0);
	glVertex3f(2.60, -2.40, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.55f, 0.5f, 0.1f);//5
	glVertex3f(2.00, -3.00, 0.0);
	glVertex3f(2.60, -2.40, 0.0);
	glVertex3f(-0.60, -2.00, 0.0);
	glVertex3f(-0.40, -2.80, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glColor3f(0.55f, 0.5f, 0.1f);//5
	glVertex3f(-6.00, -2.40, 0.0);
	glVertex3f(-6.00, -3.40, 0.0);
	glVertex3f(-0.60, -2.00, 0.0);
	glVertex3f(-0.40, -2.80, 0.0);
	glEnd();
	glFlush();

}

void gameover(char *string, float x, float y, float z)
{
	//glColor3f(1.0, 1.0, 1.0);
	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}

}

void drawBitmapText(char *string, float x, float y, float z)
{
	glColor3f(1.0, 1.0, 1.0);

	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}


//Initializes 3D rendering
void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


//Draws the 3D scene
void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

								  //initialize();
	

	if (gameOver)
	{
		glColor3f(1.0, 1.0, 1.0);
		gameover("GAME OVER", -0.30, 0.10, 0.0);
		//gameover();
		char score[4];
		char scr[] = { "FINAL SCORE:   " };
		sprintf_s(score, "%d", count);
		drawBitmapText(score, 0.90, -0.20, 0.0);
		drawBitmapText(scr, -0.40, -0.20, 0);
		glColor3f(0.0, 0.0, 0.0);
		gameover("Press'R' to replay", -0.47, -0.60, 0.0);
	}

	else
	{
		char score[4];
		char scr[] = { "SCORE:   " };
		sprintf_s(score, "%d", count);
		drawBitmapText(score, 4.75, 3.00, 0.0);
		drawBitmapText(scr, 4.00, 3.00, 0.0);

		balti();
		egg(dimX, dimY);

		if (layEgg)
		{
			dimX = murgiX + 0.37;
			dimY = murgiY;
			layEgg = false;
		}
		if (moveRight)
		{
			sojachicken(murgiX + murgiWidth);
		}
		else
		{
			Ultachicken(murgiX, murgiY);
		}

	}



	if (murgiX + murgiWidth >= 1.50)
		moveRight = false;
	else if (murgiX <= -5.50)
		moveRight = true;

	if (moveRight)
		murgiX += murgiSpeed;
	else
		murgiX -= murgiSpeed;




	stickAndRope();
	house();
	cloths();
	road();
	tree();
	surface();
	peaks();
	cloudOne();
	sun();
	cloudTwo();
	sky();

	if (sunY <= 2.2)
	{
		sunMoveup = true;
	}
	else
		sunY = 2.2;

	if (sunMoveup)
	{
		sunY += cloudspeed;
	}


	if (cloudX >= 11)
	{
		cloudMoveRight = false;
	}
	else if (cloudX <= -7)
	{
		cloudMoveRight = true;
	}


	if (cloudMoveRight)
	{
		cloudX += cloudspeed;
	}
	else
	{
		cloudX -= cloudspeed;
	}


	if (dimX >= baltiX && dimX + dimWidth <= baltiX + baltiWidth && dimY<baltiY + baltiHeight && dimY>baltiY + baltiHeight - 5)
	{
		layEgg = true;
		murgiSpeed += 0.003f;
		dimSpeed += 0.002f;
		count++;
	}
	else if (dimY - dimHeight <= -3.40)
	{
		gameOver = true;
		layEgg = false;

	}
	else {
		dimY -= dimSpeed;
	}

	glutSwapBuffers();

}

void SpecialKeys(int key, int x, int y) {
	if (gameOver) {

	}
	else {
		switch (key) {
		case GLUT_KEY_LEFT:
			if (baltiX <= -5.50)
				break;
			else
				baltiX -= 0.20f;

			break;
		case GLUT_KEY_RIGHT:
			if (baltiX + baltiWidth >= 1.50)
				break;
			else
				baltiX += 0.20f;

			break;

		}

		balti();
	}
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'r':

		gameOver = false;
		count = 0;
		murgiX = 0;
		baltiX = 0;
		dimX = 0;
		cloudX = 0;
		dimSpeed = 0.02;
		murgiSpeed = 0.03;
		glutPostRedisplay();
		break;
	}
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

						 //Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1500, 700);
	glutInitWindowPosition(0, 0);
	//Create the window
	glutCreateWindow("Transformations");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);
	glutKeyboardFunc(handleKeypress);

	glutTimerFunc(25, update, 0); //Add a timer
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();
	return 0;
}
