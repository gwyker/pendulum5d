#ifndef PROTOTYPES
#define PROTOTYPES

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <cmath>

extern double R, g, b, m, A, k;
extern double theta, omega, t;
extern double Nstep;
extern bool animate;

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

#endif
