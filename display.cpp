#include "prototypes.h"

/*
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
*/

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  moveCamera();

  glColor3f(0.5f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(-100.0f, 0.0f,  100.0f);
    glVertex3f( 100.0f, 0.0f,  100.0f);
    glVertex3f( 100.0f, 0.0f, -100.0f);
  glEnd();
  glColor3f(1.0f, 0.5f, 0.5f);
  glutSolidCube(2.0);
  glutSwapBuffers();
}

void moveCamera(void) {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  cout << angle << endl << "  " << vectorX << endl;;
    gluLookAt(posX, 1.0, posZ,  /* eye is at (0,0,5) */
    posX + vectorX, 1.0, posZ + vectorZ,      /* center is at (0,0,0) */
    0.0, 1.0, 0.0);      /* up is in positive Y direction */
}