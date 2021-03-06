#include "prototypes.h"

void displayPhase(void) {
  glColor3f(1.0, 1.0, 1.0);
 
 //draw axes
  glBegin(GL_LINE);
    glVertex2f(200, 0);
    glVertex2f(200, 400);
  glEnd();
 
  glBegin(GL_LINE);
    glVertex2f(0, 200);
    glVertex2f(400, 200);
  glEnd();

  glutSwapBuffers();
}

void display(void)
{
  draw();
  moveCamera();

  step(t, theta, omega);

  glutSwapBuffers();
}

void draw(void) {
    //enable texturing and draw objects
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    drawRoom();
    drawCrib();
    drawPendulum();

    glFlush();

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
}

void moveCamera(void) {
  //move camera position based on movespeed
  posX += moveSpeed * vectorX * 1.5f;
  posY += moveSpeed * vectorY * 1.5f;
  posZ += moveSpeed * vectorZ * 1.5f;

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
    gluLookAt(posX, posY, posZ,
    posX + vectorX, posY + vectorY, posZ + vectorZ,
    0.0, 1.0, 0.0);
}

void drawPendulum(void) {
  
  //draw arm

  glPushMatrix();
  glTranslatef(7.5, 15.0, 15.0); //move up to draw arm
  glRotatef(theta*(180.0/M_PI), 0.0, 0.0, 1.0); //rotate arm to theta
  glRotatef(180.0, 0.0, 0.0, 1.0);
  glPushMatrix();
  glScalef(0.3, 1.0, 0.3);
  
    glBegin(GL_QUAD_STRIP);
    for (int k = 0; k <= 359; k++)
    {
        glNormal3d(cos(k), 10, sin(k));

        glTexCoord2f(0,0);    glVertex3f(cos(k), 0, sin(k));
        glTexCoord2f(0,1);    glVertex3f(cos(k), 5, sin(k));
        glTexCoord2f(1,1);    glVertex3f(cos(k + 1), 5, sin(k + 1));
        glTexCoord2f(1,0);    glVertex3f(cos(k + 1), 0, sin(k + 1));
    }
    glEnd();

    glPopMatrix();

  //draw bell

  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0);
  glBindTexture ( GL_TEXTURE_2D, textureID[4]);
  glTranslatef(0.0, 5.0, 0.0);
  glScalef(1.0,-1.0,1.0);
  gluSphere( bell, 0.9, 36, 72);
  //glutSolidSphere(1.0f,8,8); //radius, slices, stacks

  glPopMatrix();
}

void drawRoom(void) {
    //floor

    glBindTexture(GL_TEXTURE_2D, textureID[0]);
    glPushMatrix();
    glTranslatef(-100.0,-10,-100.0);
    glRotatef(90.0,1.0,0.0,0.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 8.0);   glVertex2d(  0.0, 200.0 );
      glTexCoord2d( 8.0, 8.0);   glVertex2d( 200.0, 200.0 );
      glTexCoord2d( 8.0, 0.0);   glVertex2d( 200.0,  0.0 );

    glEnd();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, textureID[5]);

    //ceiling

    glPushMatrix();
    //glLoadIdentity();
    glTranslatef(-100.0,40,-100.0);
    glRotatef(90.0,1.0,0.0,0.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 6.0);   glVertex2d(  0.0, 200.0 );
      glTexCoord2d( 6.0, 6.0);   glVertex2d( 200.0, 200.0 );
      glTexCoord2d( 6.0, 0.0);   glVertex2d( 200.0,  0.0 );

    glEnd();

    glPopMatrix();

    //back wall

    glBindTexture(GL_TEXTURE_2D, textureID[1]);

    glPushMatrix();
    glTranslatef(-100.0,40.0,-100.0);
    glScalef(1.0,-1.0,1.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 50.0 );
      glTexCoord2d( 4.0, 1.0);   glVertex2d( 200.0, 50.0 );
      glTexCoord2d( 4.0, 0.0);   glVertex2d( 200.0,  0.0 );

    glEnd();

    glPopMatrix();

    //front wall

    glPushMatrix();
    glTranslatef(-100.0,40.0,100.0);
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

  }

void drawCrib(void) {
    //crib legs

    glBindTexture(GL_TEXTURE_2D, textureID[2]);
    for (int i = 0; i < 2;i++) {
      for (int j = 0; j < 2;j++) {

        glPushMatrix();

        glTranslatef(j * 15.0,-10.0,i * 30.0);
        glScalef(0.5,1.0,0.5);

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

  //crib bed top
    glBindTexture(GL_TEXTURE_2D, textureID[6]);
    glPushMatrix();
    glTranslatef(0.0,0,0.0);
    glRotatef(90.0,1.0,0.0,0.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 2.0);   glVertex2d(  0.0, 30.0 );
      glTexCoord2d( 1.0, 2.0);   glVertex2d( 15.0, 30.0 );
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 15.0,  0.0 );

    glEnd();
    glPopMatrix();

  //crib bed bottom
    glBindTexture(GL_TEXTURE_2D, textureID[8]);
    glPushMatrix();
    //glTranslatef(debugX,debugY,debugZ);
    glTranslatef(0.0,-3.0,0.0);
    glRotatef(90.0,1.0,0.0,0.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 30.0 );
      glTexCoord2d( 1.0, 1.0);   glVertex2d( 15.0, 30.0 );
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 15.0,  0.0 );

    glEnd();
    glPopMatrix();

  //crib bed left & right
    for (int i = 0;i < 2;i++) {
      glBindTexture(GL_TEXTURE_2D, textureID[6]);
      glPushMatrix();
      glTranslatef(i * 15.0,-3.0,0.0);
      glRotatef(90.0,1.0,0.0,0.0);
      glRotatef(90.0,0.0,1.0,0.0);
      glBegin(GL_POLYGON);

        glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
        glTexCoord2d( 0.0, 10.0);   glVertex2d(  0.0, 30.0 );
        glTexCoord2d( 1.0, 10.0);   glVertex2d( 3.0, 30.0 );
        glTexCoord2d( 1.0, 0.0);   glVertex2d( 3.0,  0.0 );

      glEnd();
      glPopMatrix();
    }

  //crib bed back & front
    for (int i = 0;i < 2;i++) {
      glBindTexture(GL_TEXTURE_2D, textureID[6]);
      glPushMatrix();
      glTranslatef(0.0,0.0,i * 30.0);
      glRotatef(-90.0,0.0,0.0,1.0);
      glBegin(GL_POLYGON);

        glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
        glTexCoord2d( 0.0, 5.0);   glVertex2d(  0.0, 15.0 );
        glTexCoord2d( 1.0, 5.0);   glVertex2d( 3.0, 15.0 );
        glTexCoord2d( 1.0, 0.0);   glVertex2d( 3.0,  0.0 );

      glEnd();
      glPopMatrix();
    }



    //crib railing pillars

    glBindTexture(GL_TEXTURE_2D, textureID[2]);
    for (int i = 0; i < 7;i++) {
      for (int j = 0; j < 2;j++) {

        glPushMatrix();

        glTranslatef(j * 15.0,0.0,i * 5.0);
        glScalef(0.5,1.0,0.5);

        glBegin(GL_QUAD_STRIP);
        for (int k = 0; k <= 359; k++)
        {
            glNormal3d(cos(k), 1, sin(k));

            glTexCoord2f(0,0);    glVertex3f(cos(k), 0, sin(k));
            glTexCoord2f(0,1);    glVertex3f(cos(k), 8, sin(k));
            glTexCoord2f(1,1);    glVertex3f(cos(k + 1), 8, sin(k + 1));
            glTexCoord2f(1,0);    glVertex3f(cos(k + 1), 0, sin(k + 1));
        }
        glEnd();

        glPopMatrix();
    }
  }

    //crib rails
    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    for (int i = 0; i < 2;i++) {

        glPushMatrix();

        glTranslatef(i * 15.0,8.0,0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
    

        glBegin(GL_QUAD_STRIP);
        for (int k = 0; k <= 359; k++)
        {
            glNormal3d(cos(k), 10, sin(k));

            glTexCoord2f(0,0);    glVertex3f(cos(k), 0, sin(k));
            glTexCoord2f(0,1);    glVertex3f(cos(k), 30, sin(k));
            glTexCoord2f(1,1);    glVertex3f(cos(k + 1), 30, sin(k + 1));
            glTexCoord2f(1,0);    glVertex3f(cos(k + 1), 0, sin(k + 1));
        }
        glEnd();

        glPopMatrix();
  }

    //crib wall rails
    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    for (int i = 0; i < 2;i++) {

        glPushMatrix();

        glTranslatef(0.0,10.0,i * 30.0);
        glRotatef(-90.0, 0.0, 0.0, 1.0);
    

        glBegin(GL_QUAD_STRIP);
        for (int k = 0; k <= 359; k++)
        {
            glNormal3d(cos(k), 10, sin(k));

            glTexCoord2f(0,0);    glVertex3f(cos(k), 0, sin(k));
            glTexCoord2f(0,1);    glVertex3f(cos(k), 15, sin(k));
            glTexCoord2f(1,1);    glVertex3f(cos(k + 1), 15, sin(k + 1));
            glTexCoord2f(1,0);    glVertex3f(cos(k + 1), 0, sin(k + 1));
        }
        glEnd();

        glPopMatrix();
  }

    //pendulum supports
        glBindTexture(GL_TEXTURE_2D, textureID[3]);
        glPushMatrix();

        glTranslatef(0.0,8.0,15.0);
        glScalef(0.5,1.0,0.5);
    

        glBegin(GL_QUAD_STRIP);
        for (int k = 0; k <= 359; k++)
        {
            glNormal3d(cos(k), 10, sin(k));

            glTexCoord2f(0,0);    glVertex3f(cos(k), 0, sin(k));
            glTexCoord2f(0,1);    glVertex3f(cos(k), 10, sin(k));
            glTexCoord2f(1,1);    glVertex3f(cos(k + 1), 10, sin(k + 1));
            glTexCoord2f(1,0);    glVertex3f(cos(k + 1), 0, sin(k + 1));
        }
        glEnd();

        glPopMatrix();

        glPushMatrix();

        glTranslatef(-0.5,17.5,15.0);
        glRotatef(-90.0, 0.0, 0.0, 1.0);
        glScalef(0.5,1.0,0.5);
    

        glBegin(GL_QUAD_STRIP);
        for (int k = 0; k <= 359; k++)
        {
            glNormal3d(cos(k), 10, sin(k));

            glTexCoord2f(0,0);    glVertex3f(cos(k), 0, sin(k));
            glTexCoord2f(0,1);    glVertex3f(cos(k), 8.5, sin(k));
            glTexCoord2f(1,1);    glVertex3f(cos(k + 1), 8.5, sin(k + 1));
            glTexCoord2f(1,0);    glVertex3f(cos(k + 1), 0, sin(k + 1));
        }
        glEnd();

        glPopMatrix();

        glPushMatrix();

        glTranslatef(7.5,18.0,15.0);
        glRotatef(-180.0, 0.0, 0.0, 1.0);
        glScalef(0.5,1.0,0.5);
    

        glBegin(GL_QUAD_STRIP);
        for (int k = 0; k <= 359; k++)
        {
            glNormal3d(cos(k), 10, sin(k));

            glTexCoord2f(0,0);    glVertex3f(cos(k), 0, sin(k));
            glTexCoord2f(0,1);    glVertex3f(cos(k), 3, sin(k));
            glTexCoord2f(1,1);    glVertex3f(cos(k + 1), 3, sin(k + 1));
            glTexCoord2f(1,0);    glVertex3f(cos(k + 1), 0, sin(k + 1));
        }
        glEnd();

        glPopMatrix();


    //crib back wall
    glBindTexture(GL_TEXTURE_2D, textureID[7]);
    glPushMatrix();
    glTranslatef(0.0,10.0,0.0);
    glScalef(1.0,-1.0,1.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 10.0 );
      glTexCoord2d( 1.0, 1.0);   glVertex2d( 15.0, 10.0 );
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 15.0,  0.0 );

    glEnd();

    glPopMatrix();

    //crib front wall

    glPushMatrix();
    glTranslatef(0.0,10.0,30.0);
    glScalef(1.0,-1.0,1.0);
    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 1.0);   glVertex2d(  0.0, 10.0 );
      glTexCoord2d( 1.0, 1.0);   glVertex2d( 15.0, 10.0 );
      glTexCoord2d( 1.0, 0.0);   glVertex2d( 15.0,  0.0 );

    glEnd();

    glPopMatrix();
 } 