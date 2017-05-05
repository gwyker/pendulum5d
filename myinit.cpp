#ifndef MYINIT
#define MYINIT
#include "prototypes.h"

  GLfloat global_ambient[4];

  GLfloat material_diffuse[4];
  GLfloat material_ambient[4];
  GLfloat material_emission[4];
  GLfloat material_specular[4];

  GLfloat light_0_position[4];
  GLfloat light_0_ambient[4];
  GLfloat light_0_diffuse[4];
  GLfloat light_0_specular[4];
  GLfloat light_0_spot_direction[3];
  GLfloat light_0_spot_cutoff;
  GLfloat light_0_spot_exponent;
  GLfloat light_0_gl_constant_attenuation;
  GLfloat light_0_gl_linear_attenuation;
  GLfloat light_0_gl_quadratic_attenuation;

  GLfloat light_1_position[4];
  GLfloat light_1_ambient[4];
  GLfloat light_1_diffuse[4];
  GLfloat light_1_specular[4];
  GLfloat light_1_spot_direction[3];
  GLfloat light_1_spot_cutoff;
  GLfloat light_1_spot_exponent;
  GLfloat light_1_gl_constant_attenuation;
  GLfloat light_1_gl_linear_attenuation;
  GLfloat light_1_gl_quadratic_attenuation;

  GLfloat light_2_position[4];
  GLfloat light_2_ambient[4];
  GLfloat light_2_diffuse[4];
  GLfloat light_2_specular[4];
  GLfloat light_2_spot_direction[3];
  GLfloat light_2_spot_cutoff;
  GLfloat light_2_spot_exponent;
  GLfloat light_2_gl_constant_attenuation;
  GLfloat light_2_gl_linear_attenuation;
  GLfloat light_2_gl_quadratic_attenuation;

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

   // These are light properties -- notice, specified for EACH light

   light_0_position =  {  5.0,  5.0,  0.0, 1.0 };
   light_0_ambient  =  {  1.0,  0.0,  0.0, 1.0 };
   light_0_diffuse  =  {  1.0,  0.0,  0.0, 1.0 };
   light_0_specular =  {  1.0,  0.0,  0.0, 1.0 };
   glLightfv(GL_LIGHT0, GL_POSITION, light_0_position);
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_0_ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_0_diffuse);
   glLightfv(GL_LIGHT0, GL_SPECULAR, light_0_specular);

// Lets set up a second light

   light_1_position =  {  5.0,  10.0,  5.0, 1.0 };
   light_1_ambient  =  {  0.0,  0.0,  1.0, 1.0 };
   light_1_diffuse  =  {  0.0,  0.0,  1.0, 1.0 };
   light_1_specular =  {  0.0,  0.0,  1.0, 1.0 };
   glLightfv(GL_LIGHT1, GL_POSITION, light_1_position);
   glLightfv(GL_LIGHT1, GL_AMBIENT, light_1_ambient);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, light_1_diffuse);
   glLightfv(GL_LIGHT1, GL_SPECULAR, light_1_specular);

// And now its time for a spotlight

   light_2_position =  {  5.0,  3.0,  5.0, 1.0 };
   light_2_ambient  =  {  1.0,  1.0,  1.0, 1.0 };
   light_2_diffuse  =  {  1.0,  1.0,  1.0, 1.0 };
   light_2_specular =  {  1.0,  1.0,  1.0, 1.0 };
   light_2_spot_direction = { 0.0, 1.0, 0.0 };
   light_2_spot_cutoff = 10.0;
   light_2_spot_exponent = 64;
   light_2_gl_linear_attenuation = .3;

   glLightfv(GL_LIGHT2, GL_POSITION, light_2_position);
   glLightfv(GL_LIGHT2, GL_AMBIENT, light_2_ambient);
   glLightfv(GL_LIGHT2, GL_DIFFUSE, light_2_diffuse);
   glLightfv(GL_LIGHT2, GL_SPECULAR, light_2_specular);
   glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_2_spot_direction);
   glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, &light_2_spot_cutoff);
   glLightfv(GL_LIGHT2, GL_SPOT_EXPONENT, &light_2_spot_exponent);
   glLightfv(GL_LIGHT2, GL_LINEAR_ATTENUATION, &light_2_gl_linear_attenuation);
 

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_LIGHT1);
   glEnable(GL_LIGHT2);
}

#endif