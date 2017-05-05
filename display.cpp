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
  displayTextures();

  moveCamera();
  step(t, theta, omega);

  displayPendulum();
  glutSolidSphere(1.0f,8,8);
  // cout << "please show a sphere\n";

  glutSwapBuffers();
}

void moveCamera(void) {
  //move camera position based on movespeed
  posX += moveSpeed * vectorX * 1.3f;
  posY += moveSpeed * vectorY * 1.3f;
  posZ += moveSpeed * vectorZ * 1.3f;
  // cout << "moveSpeed = " << moveSpeed << endl;

  //mouse movement


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // cout << "angleX = " << angleX << endl << "angleZ = " << angleZ << endl;
    gluLookAt(posX, posY, posZ,  /* eye is at (0,0,5) */
    posX + vectorX, posY + vectorY, posZ + vectorZ,      /* center is at (0,0,0) */
    0.0, 1.0, 0.0);      /* up is in positive Y direction */

    // cout << "X = " << vectorX << "   ";
    // cout << "Y = " << vectorY << "   ";
    // cout << "Z = " << vectorZ << "   " << endl;
}

void displayTexturesTest(void) {
    // Enable Texturing and the Depth Buffer
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


    // Bind the texture you want to use and draw the first polygon

    // cout << "displaying texture" << endl;

    glBindTexture(GL_TEXTURE_2D, textureID[0]);
    glPushMatrix();
    glLoadIdentity();
    glRotatef(90.0,0.0,1.0,0.0);
    glTranslatef(0.0,-10.0,0.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 10.0 );
      glTexCoord2d( 1.0, 1.0);   glVertex2d( 10.0, 10.0 );
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 10.0,  0.0 );

    glEnd();
    glPopMatrix();
    
    // Flush the buffer
    glFlush();

    // For completeness turn off these options
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
}

void displayTextures(void) {
      // Enable Texturing and the Depth Buffer
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    //glColor3ub(0,255,255);

    glutSolidSphere(1.0f,8,8);


    //floor

    glBindTexture(GL_TEXTURE_2D, textureID[0]);
    glPushMatrix();
    glTranslatef(debugX,debugY,debugZ);
    glTranslatef(-100.0,-10,-100.0);
    glRotatef(90.0,1.0,0.0,0.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 200.0 );
      glTexCoord2d( 1.0, 1.0);   glVertex2d( 200.0, 200.0 );
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 200.0,  0.0 );

    glEnd();
    glPopMatrix();

    // Bind the second you want to use and draw the first polygon

    glBindTexture(GL_TEXTURE_2D, textureID[1]);

    //ceiling

    glPushMatrix();
    //glLoadIdentity();
    glTranslatef(-100.0,40,-100.0);
    glRotatef(90.0,1.0,0.0,0.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 200.0 );
      glTexCoord2d( 1.0, 1.0);   glVertex2d( 200.0, 200.0 );
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 200.0,  0.0 );

    glEnd();

    glPopMatrix();

    //back wall

    glPushMatrix();
    //glLoadIdentity();
    glTranslatef(-100.0,40.0,-100.0);
    glScalef(1.0,-1.0,1.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 50.0 );
      glTexCoord2d( 4.0, 1.0);   glVertex2d( 200.0, 50.0 );
      glTexCoord2d( 4.0, 0.0);   glVertex2d( 200.0,  0.0 );

    glEnd();

    glPopMatrix();

    //left wall

    glPushMatrix();
    //glLoadIdentity();
    glTranslatef(-100.0,40.0,100.0);
    glRotatef(90.0,0.0,1.0,0.0);
    glScalef(1.0,-1.0,1.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 50.0 );
      glTexCoord2d( 4.0, 1.0);   glVertex2d( 200.0, 50.0 );
      glTexCoord2d( 4.0, 0.0);   glVertex2d( 200.0,  0.0 );

    glEnd();

    glPopMatrix();

    //right wall

    glPushMatrix();
    //glLoadIdentity();
    glTranslatef(100.0,40.0,-100.0);
    glRotatef(-90.0,0.0,1.0,0.0);
    glScalef(1.0,-1.0,1.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 50.0 );
      glTexCoord2d( 4.0, 1.0);   glVertex2d( 200.0, 50.0 );
      glTexCoord2d( 4.0, 0.0);   glVertex2d( 200.0,  0.0 );

    glEnd();

    glPopMatrix();
///////////////////objects/////////////////////////
    //crib leg

    glBindTexture(GL_TEXTURE_2D, textureID[0]);
    for (int i = 0; i < 2;i++) {
      for (int j = 0; j < 2;j++) {

        glPushMatrix();

        glTranslatef(j * 15.0,-10.0,i * 30.0);
        //glScalef(1.0,-1.0,1.0);

        glBegin(GL_QUAD_STRIP);
        for (int k = 0; k <= 359; k++)
        {
            glNormal3d(cos(k), 1, sin(k));

            glTexCoord2f(0,0);    glVertex3f(cos(k), 0, sin(k));
            glTexCoord2f(0,1);    glVertex3f(cos(k), 10, sin(k));
            glTexCoord2f(1,1);    glVertex3f(cos(k + 1), 10, sin(k + 1));
            glTexCoord2f(1,0);    glVertex3f(cos(k + 1), 0, sin(k + 1));
        }
        glEnd();

        glPopMatrix();
    }
  }


  //crib bed

    glPushMatrix();
    glTranslatef(debugX,debugY,debugZ);
    glTranslatef(-100.0,0,-100.0);
    glRotatef(90.0,1.0,0.0,0.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 200.0 );
      glTexCoord2d( 1.0, 1.0);   glVertex2d( 100.0, 200.0 );
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 100.0,  0.0 );

    glEnd();
    glPopMatrix();


    // Flush the buffer
    glFlush();

    // For completeness turn off these options
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
}

void displayPendulum(void) {
  glPushMatrix();
  // // Draw ground

  // glColor3f(0.0f, 0.9f, 0.9f);
  // glBegin(GL_QUADS);
  //   glVertex3f(-10.0f, 0.0f, -10.0f);
  //   glVertex3f(-10.0f, 0.0f,  10.0f);
  //   glVertex3f( 10.0f, 0.0f,  10.0f);
  //   glVertex3f( 10.0f, 0.0f, -10.0f);
  // glEnd();

  //draw arm
  glRotatef(90.0, 1.0, 0.0, 0.0);
  glTranslatef(0.0f, 0.0f, 1.0f); //move up to draw arm
  glRotatef(theta*(180.0/M_PI), 0.0, 1.0, 0.0); //rotate arm to theta
  GLUquadricObj *qobj;
  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj, GLU_FILL);
  glColor3f(0.5f, 0.8f, 0.0f);
  gluCylinder(qobj, 0.5f, 0.5f, 5.0f, 8, 8);
  //draw bell
  glTranslatef(0.0, 0.0, 5.0);
  glColor3f(0.5f, 0.5f, 1.0f);
  glutSolidSphere(1.0f,8,8); //radius, slices, stacks
  // glColor3f(1.0f, 0.5f, 0.5f);
  // glutSolidCube(2.0);
  glPopMatrix();
}