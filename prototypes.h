#ifndef PROTOTYPES
#define PROTOTYPES

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include "SOIL.h"

extern GLuint textureID[9];
extern GLUquadric *bell;

extern GLfloat global_ambient[4];
extern GLfloat material_diffuse[4];
extern GLfloat material_ambient[4];
extern GLfloat material_emission[4];
extern GLfloat material_specular[4];

extern double R, g, b, m, A, k;
extern double theta, omega, t;
extern double Nstep;
extern bool animate;
extern double angleX, angleZ, vectorX, vectorY, vectorZ, posX, posY, posZ, moveSpeed;
extern double debugX, debugY, debugZ;

using namespace std;

typedef struct vertex {
    float x;
    float y;
    float z;
    float w;
} vertex;

void reshape (int w, int h);
void definePendulumArm (vertex *points);
void display (void);
void drawPendulum (vertex *points, int pointCount);
void initialize (void);
void step(double &t, double &theta, double &omega );
void moveCamera(void);
void mouseCamera(void);
void loadTextures(void);
void drawPendulum(void);
void drawCrib(void);
void drawRoom(void);
void draw(void);
void myinit(void);
void phaseinit(void);
void displayPhase(void);
#endif
