#ifndef MYINIT
#define MYINIT
#include "prototypes.h"

void myinit( void )
{
/* attributes */

/* set up viewing */
    glClearColor(0.0,0.0,0.0,0.0);

    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
  gluPerspective(    45.0,
    /* aspect ratio */ 1.0,
    /* Z near */ 0.1, /* Z far */ 5000.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0.0, 0.0, 25.0,  /* eye is at (0,0,5) */
    0.0, 0.0, 0.0,   //    center is at (0,0,0) 
    0.0, 1.0, 0.);      /* up is in positive Y direction */

      // gluLookAt(  20.0,   20.0,   20.0,  // Eye
      //           0.0,   0.0, 0.0,  // Center
      //           0.0,   0.0, 1.0); // Up

  bell = gluNewQuadric();
  gluQuadricTexture( bell, GL_TRUE);

  loadTextures();

/* set up initial values */

    theta = 0;
    R = 1;
    g = 1;
    b = 0;
    A = 0;
    k = 0;

      //initialize();

    // Now start working on lighting -- turn on some global settings
   global_ambient = { 0.5f, 0.5f, 0.5f, 1.0f };
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
   glShadeModel(GL_SMOOTH);

// these are material properties

   material_ambient  = { 0.5, 0.5, 0.5, 1.0 };
   material_diffuse  = { 0.2, 0.2, 0.2, 1.0 };
   material_specular = { 0.2, 0.2, 0.2, 1.0 };
   material_emission = { 0.2, 0.2, 0.2, 1.0 };

   glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
   glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
   glMaterialfv(GL_FRONT, GL_EMISSION, material_emission);
   glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
//   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 25.0);
}

#endif