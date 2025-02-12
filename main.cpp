#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>
#include <iostream>

using namespace std;

const float PI = 3.1416;
bool night = false;
bool light_on = false;
bool lightUp = true;

float waveMovement1 = 0.0f;
float waveMovement2 = 0.0f;
float waveMovement3 = 0.0f;
float sunMovement = 0.0f;
float cloudMovement1 = 0.0f;
float cloudMovement2 = 0.0f;
float shipMovement = 0.0f;
float smallShipMovement = 0.0f;
float truckMovement = 0.0f;
float moveLight = 200.0f;

float waveMovementSpeed1 = 0.3f;
float waveMovementSpeed2 = 0.3f;
float waveMovementSpeed3 = 0.3f;
float sunMovementSpeed = 0.5f;
float cloudMovement1Speed = 1.0f;
float cloudMovement2Speed = 1.0f;
float shipMovementSpeed = 2.2f;
float smallShipMovementSpeed = 1.4f;
float truckMovementSpeed = 2.0f;
float moveLightSpeed = 0.5f;

void update(int value) {

    waveMovement1 += waveMovementSpeed1;
    if (waveMovement1 > 400) {
        waveMovement1 = -1250.0f;
    }
    waveMovement2 += waveMovementSpeed2;
    if (waveMovement2 > 700) {
        waveMovement2 = -1300.0f;
    }
    waveMovement3 += waveMovementSpeed3;
    if (waveMovement3 > 1300) {
        waveMovement3 = -800.0f;
    }

    sunMovement += sunMovementSpeed;
    if (sunMovement > 1300) {
        sunMovement = -500.0f;
    }

    cloudMovement1 -= cloudMovement2Speed;
    cloudMovement2 -= cloudMovement2Speed;

    if (cloudMovement1 < -570) {
        cloudMovement1 = 1400.0f;
    }
    if (cloudMovement2 < -1350) {
        cloudMovement2 = 800.0f;
    }
    shipMovement += shipMovementSpeed;
    if (shipMovement > 1000) {
        shipMovement = -1300.0f;
    }
    smallShipMovement -= smallShipMovementSpeed;
    if (smallShipMovement <- 1000) {
        smallShipMovement = 850.0f;
    }
    truckMovement -= truckMovementSpeed;
    if (truckMovement <- 1000) {
        truckMovement = 1200.0f;
    }
    if (moveLight == 200){
        lightUp = true;
        moveLightSpeed = 0.5f;
    }

    else if (moveLight == 450){
        lightUp = false;
        moveLightSpeed = -0.5f;
    }
    moveLight += moveLightSpeed;


    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

void drawWater(){
	glBegin(GL_QUADS);
	if(night == false) glColor3f(0.149, 0.847, 0.866);
	else glColor3f(0.0f, 0.1f, 0.3f);
	glVertex2f(0, 200);
	glVertex2f(1400, 200);
	glVertex2f(1400, 607);
	glVertex2f(0, 607);
	glEnd();
}

void drawLand(){
    glBegin(GL_QUADS);
    if(night == false) glColor3f(0.547, 0.449, 0.461);
    else glColor3f(0.247, 0.176, 0.231);
    glVertex2f(0, 0);
    glVertex2f(1400, 0);

    if(night == false) glColor3f(0.647, 0.549, 0.561);
    else glColor3f(0.247, 0.176, 0.231);
    glVertex2f(1400, 200);
    glVertex2f(0, 200);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int numSegments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawContainer(float startX, float startY, string color){
	if(color == "p")
    {
        if(night == false) glColor3f(0.416, 0.204, 0.533);
        else glColor3f(0.325, 0.145, 0.423);
    }
	else if(color == "y")
    {
        if(night == false) glColor3f(0.902, 0.866, 0.149);
        else glColor3f(0.737, 0.702, 0);
    }
	else if(color == "b")
    {
        if(night == false)  glColor3f(0.145, 0.694, 0.855);
        else glColor3f(0.301, 0.525, 0.635);
    }
	else if(color == "r")
    {
        if(night == false) glColor3f(0.859, 0.196, 0.224);
        else glColor3f(0.556, 0.031, 0.054);
    }

	glBegin(GL_QUADS);
	glVertex2f(startX, startY);
	glVertex2f(startX + 100, startY);
	glVertex2f(startX + 100, startY + 50);
	glVertex2f(startX, startY + 50);
	glEnd();

	if(color == "p")
    {
        if(night == false) glColor3f(0.711, 0.176, 1);
        else glColor3f(0.416, 0.204, 0.533);
    }
	else if(color == "y")
	{
	    if(night == false) glColor3f(0.737, 0.702, 0);
	    else glColor3f(0.902, 0.866, 0.149);
	}
	else if(color == "b")
    {
        if(night == false) glColor3f(0.380, 0.796, 1);
        else glColor3f(0.145, 0.694, 0.855);
    }
	else if(color == "r")
    {
        if(night == false) glColor3f(1, 0.471, 0.494);
        else glColor3f(0.859, 0.196, 0.224);
    }
	glLineWidth(2);
	glBegin(GL_LINES);
	for(int i=10; i<100; i+=10)
	{
		glVertex2f(startX + i, startY + 5);
		glVertex2f(startX + i, startY + 45);
	}
	glEnd();
}

void drawBarrier(){
    glColor3f(0.3f, 0.3f, 0.3f);
    float barrierHeight = 50.0f;
    float barrierThickness = 19.0f;

    for (float x = 0; x < 1400; x += 60) {
        glBegin(GL_QUADS);

        // Vertical
        glVertex2f(x, 200);
        glVertex2f(x + barrierThickness, 200);
        glVertex2f(x + barrierThickness, 200 + barrierHeight);
        glVertex2f(x, 200 + barrierHeight);
        glEnd();

        // Horizontal rail
        if (x < 1400 - 60) {
            glBegin(GL_QUADS);
            glVertex2f(x, 200 + barrierHeight - 5);
            glVertex2f(x + 60, 200 + barrierHeight - 5);
            glVertex2f(x + 60, 200 + barrierHeight);
            glVertex2f(x, 200 + barrierHeight);
            glEnd();
        }
    }
}

void drawSun() {
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(450.0f, 690.0f, 40.0f, 100);
}

void drawMoon(){

        glColor3f(0.8f, 0.8f, 0.8f);
        drawCircle(450.0f, 690.0f, 40.0f, 100);
        glColor3f(0.0, 0.2, 0.4);
        drawCircle(470.0f, 695.0f, 33.0f, 100);

}

void drawCloud(float x, float y){
    if(night == false) glColor3f(1.0f, 1.0f, 1.0f);
    else glColor3f(0.498f, 0.549f, 0.553f);
    // Cloud
    float radius = 30.0f;
    int numSegments = 100;

    // Circle 1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();

    // Circle 2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x - 40, y + 10);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(x - 40 + radius * cos(angle), y + 10 + radius * sin(angle));
    }
    glEnd();

    // Circle 3
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x + 40, y + 10);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(x + 40 + radius * cos(angle), y + 10 + radius * sin(angle));
    }
    glEnd();

    // Circle 4
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x - 20, y - 20);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(x - 20 + radius * cos(angle), y - 20 + radius * sin(angle));
    }
    glEnd();

    // Circle 5
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x + 20, y - 20);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(x + 20 + radius * cos(angle), y - 20 + radius * sin(angle));
    }
    glEnd();
}

void drawStars(){
    glPointSize(3);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2f(100, 680);
    glVertex2f(200, 680);
    glVertex2f(300, 650);
    glVertex2f(400, 630);
    glVertex2f(500, 600);
    glVertex2f(600, 660);
    glVertex2f(700, 640);
    glVertex2f(850, 660);
    glVertex2f(950, 740);
    glVertex2f(800, 710);
    glVertex2f(1020, 700);
    glVertex2f(1140, 660);
    glVertex2f(1250, 700);
    glVertex2f(980, 690);
    glVertex2f(710, 670);
    glVertex2f(350, 700);
    glEnd();
}

void drawSky(){
    glBegin(GL_QUADS);
    if(night == false)glColor3f(0.553, 0.824, 0.957);
	else glColor3f(0.0, 0.2, 0.4);
    glVertex2f(0, 600);
    glVertex2f(1400, 600);
    glVertex2f(1400, 750);
    glVertex2f(0, 750);
    glEnd();

     if(night) drawStars();

    glPushMatrix();
    glTranslatef(sunMovement, 0.0f, 0.0f);
    if (night == false)drawSun();
    else drawMoon();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudMovement1, 0.0f, 0.0f);
    drawCloud(220, 690);
    drawCloud(500, 725);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudMovement2, 0.0f, 0.0f);
    drawCloud(910, 710);
    drawCloud(1210, 735);
    //drawCloud(1050, 750);
    glPopMatrix();
}

void drawLighthouse(){
  glBegin(GL_POLYGON);
    if(night == false) glColor3f(0.547, 0.449, 0.461);
    else glColor3f(0.247, 0.176, 0.231);
    glVertex2f(1140, 370);
    glVertex2f(1160, 325);
    glVertex2f(1340, 325);
    glVertex2f(1350, 380);
    glVertex2f(1330, 390);
    glVertex2f(1170, 385);
    glEnd();

    float baseX = 1250.0f;
    float baseY = 350.0f;
    float bottomWidth = 130.0f;
    float topWidth = 58.0f;
    float height = 250.0f;

    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) glColor3f(0.9f, 0.0f, 0.0f);
        else glColor3f(0.92f, 0.94f, 0.91f);

        float currentBottomWidth = bottomWidth - (i * (bottomWidth - topWidth) / 5);
        float currentTopWidth = bottomWidth - ((i + 1) * (bottomWidth - topWidth) / 5);

        glBegin(GL_QUADS);
        glVertex2f(baseX - currentBottomWidth / 2, baseY + i * (height / 5));
        glVertex2f(baseX + currentBottomWidth / 2, baseY + i * (height / 5));
        glVertex2f(baseX + currentTopWidth / 2, baseY + (i + 1) * (height / 5));
        glVertex2f(baseX - currentTopWidth / 2, baseY + (i + 1) * (height / 5));
        glEnd();
    }

    float houseWidth = 50.0f;
    float houseHeight = 40.0f;
    float houseX = baseX - houseWidth / 2;
    float houseY = baseY + height;

    glColor3f(0.64f, 0.18f, 0.25f);
    glBegin(GL_QUADS);
    glVertex2f(houseX, houseY);
    glVertex2f(houseX + houseWidth, houseY);
    glVertex2f(houseX + houseWidth, houseY + houseHeight);
    glVertex2f(houseX, houseY + houseHeight);
    glEnd();


    glColor3f(0.88f, 0.92f, 0.95f);
    glBegin(GL_QUADS);
    glVertex2f(houseX + 5, houseY + 7);
    glVertex2f(houseX + 16, houseY + 7);
    glVertex2f(houseX + 16, houseY + 30);
    glVertex2f(houseX + 5, houseY + 30);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(houseX + 34, houseY + 7);
    glVertex2f(houseX + 45, houseY + 7);
    glVertex2f(houseX + 45, houseY + 30);
    glVertex2f(houseX + 34, houseY + 30);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(1250 , 630, 8, 100);
    glEnd();

    if (night && light_on) {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(1245, 630);
    glVertex2f(1255, 630);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(850, moveLight);
    glVertex2f(1000, moveLight);
    glEnd();
    }

    float roofHeight = 20.0f;
    glColor3f(0.5f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(houseX - 5, houseY + houseHeight);
    glVertex2f(houseX + houseWidth + 5, houseY + houseHeight);
    glVertex2f(baseX, houseY + houseHeight + roofHeight);
    glEnd();
}

void drawWave(float startX, float startY, float length, string color){
	if(color == "dark")
    {
        if(night == false) glColor3f(0.145, 0.694, 0.855);
        else glColor3f(0.0, 0.184, 0.294);
    }
	else
    {
        if(night == false) glColor3f(0.161, 0.996, 0.847);
        else glColor3f(0.0039, 0.309, 0.525);
    }

	float waveRadius = 3.3f;
    int numSegments = 30;

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 1.0f * M_PI * i / numSegments;
        glVertex2f(startX + waveRadius * cos(angle + M_PI * 0.5), startY + waveRadius * sin(angle + M_PI * 0.5));
    }
    glEnd();

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= numSegments; i++) {
        float angle = 1.0f * M_PI * i / numSegments;
        glVertex2f(startX + length + waveRadius * cos(angle - M_PI * 0.5), startY + waveRadius * sin(angle - M_PI * 0.5));
    }
    glEnd();

	glBegin(GL_QUADS);
	glVertex2f(startX, startY - waveRadius);
	glVertex2f(length + startX, startY - waveRadius);
	glVertex2f(length + startX, startY - waveRadius + 2 * waveRadius);
	glVertex2f(startX, startY - waveRadius + 2 * waveRadius);
	glEnd();
}

void drawSmallShip(){
    float y = 465;

    // Body
    glBegin(GL_QUADS);
    if(night == false) glColor3f(0.1f, 0.1f, 0.1f);
    else glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(750, 55 + y);
    glVertex2f(950, 55 + y);
    glVertex2f(970, 90 + y);
    glVertex2f(730, 90 + y);
    glEnd();

    // containers
    drawContainer(785, 148 + y, "y");
    drawContainer(735, 102 + y, "p");
    drawContainer(810, 102 + y, "b");
    drawContainer(865, 102 + y, "r");

    // Railing part
    glBegin(GL_QUADS);
    if(night == false) glColor3f(0.3f, 0.22f, 0.23f);
    else glColor3f(0.28f, 0.22f, 0.23f);
    glVertex2f(730, 90 + y);
    glVertex2f(970, 90 + y);
    glVertex2f(970, 110 + y);
    glVertex2f(730, 110 + y);
    glEnd();

    // windows
    if(night == false) glColor3f(0.88f, 0.92f, 0.95f);
    else glColor3f(1.0f, 1.0f, 0.0f);
    for (int i = 0; i <= 190; i += 30)
        drawCircle(755 + i, 90 + y, 5, 100);
}

void drawShip(){
    float shipYOffset = 115;

    // Body
    glBegin(GL_QUADS);
    if(night == false) glColor3f(0.1f, 0.1f, 0.1f);
    else glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(700, 90 + shipYOffset);
    glVertex2f(1100, 90 + shipYOffset);
    glVertex2f(1140, 150 + shipYOffset);
    glVertex2f(660, 150 + shipYOffset);
    glEnd();

    // Railing part
    glBegin(GL_QUADS);
    if(night == false) glColor3f(0.3f, 0.22f, 0.23f);
    else glColor3f(0.28f, 0.22f, 0.23f);
    glVertex2f(660, 150 + shipYOffset);
    glVertex2f(1140, 150 + shipYOffset);
    glVertex2f(1140, 170 + shipYOffset);
    glVertex2f(660, 170 + shipYOffset);
    glEnd();

    // windows
 	if(night == false) glColor3f(0.88f, 0.92f, 0.95f);
	else  glColor3f(1.0f, 1.0f, 0.0f);
    for (int i = 0; i <= 390; i += 35) {
        drawCircle(710 + i, 150 + shipYOffset, 7, 100);
    }

    // containers
    drawContainer(680, 170 + shipYOffset, "p");
    drawContainer(780, 170 + shipYOffset, "b");
    drawContainer(880, 170 + shipYOffset, "r");
    drawContainer(980, 170 + shipYOffset, "y");
    drawContainer(785, 220 + shipYOffset, "y");
    drawContainer(885, 220 + shipYOffset, "p");
}

void drawTruck(){
    glBegin(GL_QUADS);
    if(night == false) glColor3f(0.2f, 0.2f, 0.2f);
    else glColor3f(0.2f, 0.1f, 0.1f);
    glVertex2f(300, 120);
    glVertex2f(500, 120);
    glVertex2f(500, 135);
    glVertex2f(300, 135);
    glEnd();

    if(night == false) glColor3f(0.88f, 0.92f, 0.95f);
    else glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(299, 159, 5, 100);
    if(night) {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(301, 160);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(223, 120);
    glVertex2f(220, 166);
    glEnd();
 }

    glBegin(GL_QUADS);
    if(night == false) glColor3f(0.859, 0.196, 0.224);
    else glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(302, 135);
    glVertex2f(362, 135);
    glVertex2f(362, 185);
    glVertex2f(302, 185);
    glEnd();

    glBegin(GL_QUADS);
    if(night == false) glColor3f(0.6f, 0.8f, 1.0f);
    else glColor3f(0.3f, 0.5f, 0.8f);
    glVertex2f(302, 157);
    glVertex2f(332, 157);
    glVertex2f(332, 185);
    glVertex2f(302, 185);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(340, 110, 15, 100);
    drawCircle(460, 110, 15, 100);

    glColor3f(0.7f, 0.7f, 0.7f);
    drawCircle(340, 110, 5, 100);
    drawCircle(460, 110, 5, 100);

    drawContainer(375, 135, "p");
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

	drawSky();
	drawWater();

    //Wave
    glPushMatrix();
    glTranslatef(waveMovement1, 0.0f, 0.0f);
	//drawWave(1100, 380, 200, "dark");
	//drawWave(1200, 255, 150, "dark");
    drawWave(1100, 265, 150, "dark");
    drawWave(1350, 265, 170, "dark");
    drawWave(1110, 340, 160, "dark");
    drawWave(1100, 415, 130, "light");
    drawWave(1290, 415, 150, "dark");
    drawWave(1250, 490, 100, "dark");
    drawWave(1150, 490, 210, "dark");
    drawWave(1150, 565, 200, "dark");
    glPopMatrix();

	glPushMatrix();
    glTranslatef(waveMovement2, 0.0f, 0.0f);
	//drawWave(900, 285, 250, "light");
	//drawWave(900, 480, 150, "light");
    drawWave(500, 265, 150, "dark");
    drawWave(750, 265, 170, "dark");
    drawWave(490, 340, 160, "dark");
    drawWave(500, 415, 130, "light");
    drawWave(760, 415, 150, "dark");
    drawWave(400, 490, 100, "dark");
    drawWave(640, 490, 210, "light");
    drawWave(670, 565, 300, "dark");
	drawWave(200, 565, 50, "dark");
    glPopMatrix();

    glPushMatrix();
    glTranslatef(waveMovement3, 0.0f, 0.0f);
    drawWave(-160, 265, 150, "dark");
    drawWave(180, 265, 170, "dark");
    drawWave(40, 340, 160, "light");
    drawWave(-120, 415, 150, "dark");
    drawWave(180, 415, 150, "dark");
    drawWave(50, 490, 100, "light");
    drawWave(90, 565, 300, "dark");
	drawWave(-130, 565, 120, "dark");
	glPopMatrix();

	drawLand();

    glPushMatrix();
    if (night == false)glTranslatef(smallShipMovement, 0.0f, 0.0f);
	else glTranslatef(800.0f, 0.0f, 0.0f);
    drawSmallShip();
    glPopMatrix();

	drawLighthouse();

    glPushMatrix();
    if(night == false) glTranslatef(shipMovement, 0.0f, 0.0f);
    else glTranslatef(-300.0f, 0.0f, 0.0f);
	drawShip();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(truckMovement, 0.0f, 0.0f);
    drawTruck();
    glPopMatrix();
    drawBarrier();

	//Container
	drawContainer(0, 0, "p");
	drawContainer(100, 0, "y");
	drawContainer(200, 0, "r");
	drawContainer(300, 0, "b");
	drawContainer(400, 0, "y");
	drawContainer(575, 0, "r");
	drawContainer(900, 0, "p");
	drawContainer(1000, 0, "b");
	drawContainer(1100, 0, "y");
	drawContainer(1200, 0, "r");
	drawContainer(1300, 0, "b");
	drawContainer(20, 50, "r");
	drawContainer(138, 50, "b");
	drawContainer(240, 50, "y");
	drawContainer(342, 50, "p");
	drawContainer(940, 50, "y");
	drawContainer(1050, 50, "p");
	drawContainer(1150, 50, "b");
	drawContainer(1270, 50, "p");
	drawContainer(270, 100, "r");
	drawContainer(1090, 100, "r");

	//glutSwapBuffers();
	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'N':
        case 'n':
            night = true;
            break;
        case 'D':
        case 'd':
            night = false;
            break;
        case ' ':
            waveMovementSpeed1 = 0.0f;
            waveMovementSpeed2 = 0.0f;
            waveMovementSpeed3 = 0.0f;
            sunMovementSpeed = 0.0f;
            cloudMovement1Speed = 0.0f;
            cloudMovement2Speed = 0.0f;
            shipMovementSpeed = 0.0f;
            smallShipMovementSpeed = 0.0f;
            truckMovementSpeed = 0.0f;
            moveLightSpeed = 0.0f;
            break;
        case 's':
        case 'S':
            waveMovementSpeed1 = 0.5f;
            waveMovementSpeed2 = 0.5f;
            waveMovementSpeed3 = 0.5f;
            sunMovementSpeed = 0.5f;
            cloudMovement1Speed = 1.0f;
            cloudMovement2Speed = 1.0f;
            shipMovementSpeed = 2.2f;
            smallShipMovementSpeed = 1.4f;
            truckMovementSpeed = 2.0f;
            if (lightUp)moveLightSpeed = 0.5f;
            else moveLightSpeed = -0.5f;
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void mouseCallback(int button, int state, int x, int y)
{

        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            light_on = !light_on;
        }
}

void myInit(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(0,1400,0,750);
}

int main(int argc, char** argv) {

    cout << ".----------------------------------------." << endl;
    cout << "|                                        |" << endl;
    cout << "|             SEA PORT PROJECT           |" << endl;
    cout << "|                                        |" << endl;
    cout << ".----------------------------------------|" << endl;
    cout << "|      Faculty: UMME SADIA SALSABIL      |" << endl;
    cout << "|            2024-2025, FALL             |" << endl;
    cout << "|       Submission Date: 4/2/2025        |" << endl;
    cout << ".----------------------------------------." << endl;
    cout << ".------------------------.---------------." << endl;
    cout << "|   NAME                 |   ID          |" << endl;
    cout << "-------------------------|---------------." << endl;
    cout << "|   SYED AL SADMAN DIP   |   22-47884-2  |" << endl;
    cout << "`------------------------.---------------`" << endl;

    cout << endl << endl;
    cout << ".-------------------------------------------------------------.\n";
    cout << "| KEY / MOUSE INPUT        | ACTION                           |\n";
    cout << ".-------------------------------------------------------------.\n";
    cout << "| 'N' or 'n'               | Transition to night              |\n";
    cout << "| 'D' or 'd'               | Transition to day                |\n";
    cout << "| Space                    | Stop scenery                     |\n";
    cout << "| 'S' or 's'               | Start scenery                    |\n";
    cout << "| 'M' or 'm'               | Start/stop sound                 |\n";
    cout << "| Hold 'LEFT' Mouse        | Toggle lighthouse light on/off   |\n";
    cout << "| Esc                      | Exit App                         |\n";
    cout << "| Link : https://github.com/22-47884-2/Sea_Port-_Freeglut.git |\n";
    cout << ".-------------------------------------------------------------.\n";

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400, 750);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Sea port");

    myInit();

    glutDisplayFunc(display);
    glutTimerFunc(20, update, 0);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseCallback);

    glutMainLoop();

    return 0;
}
