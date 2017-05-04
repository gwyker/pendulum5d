#include "prototypes.h"

int WINDOW_MAX_X = 800;
int WINDOW_MAX_Y = 800;
double Nstep = 1000.0;
//float angle, length, gravity, damping, amplitude, freq;
double R, g, b, m, A, k;
bool animate = true;

double t=0.0;
double theta=M_PI/2.0;
//double theta=0.0;
double omega=1.5;

double angleX = 0.0;
double angleZ = 0.0;
double angleDeltaX = 0.0;
double angleDeltaY = 0.0;
double vectorX = 0.0;
double vectorY = 0.0;
double vectorZ = -1.0;
double posX = 0.0;
double posY = 0.0;
double posZ = 18.0;
double moveSpeed = 0.0;

int mousePrevX = 400;
int mousePrevY = 400;

void myinit( void )
{
/* attributes */

/* set up viewing */
    glClearColor(0.0,0.0,0.0,0.0);

    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
  gluPerspective( /* field of view in degree */ 45.0,
    /* aspect ratio */ 1.0,
    /* Z near */ 0.1, /* Z far */ 100.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0.0, 0.0, 15.0,  /* eye is at (0,0,5) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0.0, 1.0, 0.);      /* up is in positive Y direction */

  // loadTextures();

/* set up initial values */

    theta = 0;
    R = 1;
    g = 1;
    b = 0;
    A = 0;
    k = 0;

      //initialize();
}

void keyboardDown( unsigned char key, int x, int y ) {
    switch (key) {
        case 'q':
            exit(0);
            break;
        case 'w':
            moveSpeed = 0.5;
            break;
        case 's':
            moveSpeed = -0.5;
            break;
    }
}

void keyboardUp( unsigned char key, int x, int y ) {
    switch (key) {
        case 'q':
            exit(0);
            break;
        case 'w':
            moveSpeed = 0.0;
            break;
        case 's':
            moveSpeed = 0.0;
            break;
    }
}

void mouseMove(int x, int y) {
        y=WINDOW_MAX_Y-y;

        angleZ += (x-mousePrevX) / 100.0;
        angleX -= (y-mousePrevY) / 100.0;

        cout << "angleZ = " << angleZ << endl << "angleX = " << angleX << endl;

        if (angleX > (2*M_PI))
            angleX = 0.0;
        if (angleX < 0.0)
            angleX = (2*M_PI);
        if (angleZ > (2*M_PI))
            angleZ = 0.0;
        if (angleZ < 0.0)
            angleZ = (2*M_PI);

        // update x and z vectors
        vectorX = cos(angleX);
        vectorY = -sin(angleX);
        vectorZ = tan(angleZ);

        // glutWarpPointer(midX, WINDOW_MAX_Y-midY);

        mousePrevX = x;
        mousePrevY = y;
}

void reshape (int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode (GL_MODELVIEW);

    WINDOW_MAX_X = w;
    WINDOW_MAX_Y = h;
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
    glutInitWindowSize(WINDOW_MAX_X, WINDOW_MAX_Y); 
    glutInitWindowPosition(0,0); 
    glEnable(GL_DEPTH_TEST);
    glutCreateWindow("The Git and the Pendulum"); 
    myinit(); 
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutDisplayFunc(display); 
    glutIdleFunc(display); 
    glutMotionFunc(mouseMove);
    glClearColor(0.1,0.1,0.1,0.0);
    glutMainLoop();
}
