#include "prototypes.h"

int WINDOW_MAX = 800;
double Nstep = 1000.0;
//float angle, length, gravity, damping, amplitude, freq;
double R, g, b, m, A, k;
bool animate = true;

double t=0.0;
double theta=M_PI/2.0;
//double theta=0.0;
double omega=1.5;

double angle = 0.0;
double vectorX = 0.0;
double vectorZ = -1.0;
double posX = 0.0;
double posZ = 5.0;

void myinit( void )
{
/* attributes */

/* set up viewing */
    glClearColor(0.0,0.0,0.0,0.0);

    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
  gluPerspective( /* field of view in degree */ 40.0,
    /* aspect ratio */ 1.0,
    /* Z near */ 1.0, /* Z far */ 10.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(8.0, 3.0, 5.0,  /* eye is at (0,0,5) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0.0, 1.0, 0.);      /* up is in positive Y direction */

/* set up initial values */

    theta = 0;
    R = 1;
    g = 1;
    b = 0;
    A = 0;
    k = 0;

      //initialize();
}

void keyboard( unsigned char key, int x, int y ) {
    if ( key == 'q' || key == 'Q') //exit program
        exit(0);
    if ( key == 'a' || key == 'A') { //exit program
        angle -= 0.01;
        cout << "test\n";
        vectorX = sin(angle);
        vectorZ = -cos(angle);
    }
    if ( key == 'd' || key == 'D') { //exit program
    	angle += 0.01;
        cout << "test\n";
        vectorX = sin(angle);
        vectorZ = -cos(angle);
    }
    if ( key == 'w' || key == 'W') {
        posX += vectorX * 0.2;
        posZ += vectorZ * 0.2;
    }
    if ( key == 's' || key == 'S') {
        posX -= vectorX * 0.2;
        posZ -= vectorZ * 0.2;
    }
}

void arrowkeys ( int key, int x, int y)
{
    
}

void reshape (int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode (GL_MODELVIEW);
}

void initialize(void) {
    cout << "Please enter the initial values for this simulation.\n\n";
    cout << "Initial angle (degrees): ";
        cin >> theta;
        theta *= (M_PI/180);
    cout << "Pendulum length: ";
        cin >> R;
    cout << "Gravitational constant: ";
        cin >> g;
    cout << "Damping constant: ";
        cin >> b;
    cout << "Amplitude of the impulse: ";
        cin >> A;
    cout << "Frequency of the impulse: ";
        cin >> k;                    
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(WINDOW_MAX, WINDOW_MAX); 
    glutInitWindowPosition(0,0); 
    glEnable(GL_DEPTH_TEST);
    glutCreateWindow("The Git and the Pendulum"); 
    myinit(); 
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrowkeys);
    glutDisplayFunc(display); 
    glutIdleFunc(display); 
    glClearColor(0.1,0.1,0.1,0.0);
    glutMainLoop();
}
