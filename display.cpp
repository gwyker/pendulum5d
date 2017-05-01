#include "prototypes.h"

void display(void)
{
    if (animate) {
      glClear(GL_COLOR_BUFFER_BIT);
      glColor3f(1.0, 0.0, 0.8);

      glPushMatrix();
      step(t, theta, omega);
      glTranslatef(400.0, 400.0, 0.0);
      glRotatef(theta*(180.0/M_PI), 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      	for(double i = 0; i < 2 * M_PI; i += M_PI / 8)
 		glVertex3f(cos(i) * 40, (sin(i) * 40) - (R*200), 0.0);
      glEnd();
      glTranslatef(-400.0, -400.0, 0.0);
      glRecti(380, 400, 420, 400 - (R*200));
      
      //cout << "t = " << t << " theta = " << theta << " omega = " << omega << endl;
      //cout << "loop\n";
      glutSwapBuffers();
      glPopMatrix();
    }
      glutPostRedisplay();
}
