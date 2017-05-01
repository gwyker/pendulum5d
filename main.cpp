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

void myinit( void )
{
/* attributes */

      glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
      glPointSize(1.0);

/* set up viewing */

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, (float) WINDOW_MAX, 
                 0.0, (float) WINDOW_MAX);
      glMatrixMode(GL_MODELVIEW);

/* set up initial values */

      initialize();
}

void keyboard( unsigned char key, int x, int y ) {
    if ( key == 'q' || key == 'Q') //exit program
    	exit(0);
    if (key == 's' || key == 'S') {
        if (animate)
            animate = false;
        else
            animate = true;
    } //stop animation

    if (key == 'r' || key == 'R') {
        theta = M_PI/2;
        t = 0;
        omega = 1.5;
    }   //reset pendulum to the initial position AND restart motion

}

void arrowkeys ( int key, int x, int y)
{
    if ( key == GLUT_KEY_RIGHT) {
        Nstep *= 0.8; // increase pendulum speed
        cout << "speed up: " << Nstep << "\n";
    }
    if ( key == GLUT_KEY_LEFT) {
        Nstep *= 1.2; // decrease pendulum speed
        cout << "slow down: " << Nstep << "\n";
    }
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
    glutInitDisplayMode (/*GLUT_DOUBLE | */GLUT_RGB); 
    glutInitWindowSize(WINDOW_MAX, WINDOW_MAX); 
    glutInitWindowPosition(0,0); 
    glutCreateWindow("The Git and the Pendulum"); 
    myinit(); 
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrowkeys);
    glutDisplayFunc(display); 
    glutMainLoop();
}
