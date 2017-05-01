#include <cmath>
#include "prototypes.h"

static int spin = 0;
//double t=0.0;
//double theta=M_PI/2.0;
//double omega=1.5;

// These two functions are the first and second derivative equations
// for the dynamical motion of the driven plane pendulum with damping

double thetadot(double t, double theta, double omega)
{
   return omega;
}

double omegadot(double t, double theta, double omega)
{
   //R = 1.00;  // Length of pendulum
   //g = 1.00;  // Normalized gravitational constant
   //b = 0.00;  // Frictional damping constant
   //m = 1.00;  // Mass in normalized gravitational units
   //A = 0.00;  // Amplitude of initial driving force
   //k = 0.00;  // Frequency parameter of initial driving force

   double damp, kick, denom;

   damp = -b*omega; 
   kick =  A*cos(k*t);
   //denom = m*pow(R,2.0);
   denom = 1.0;
   cout << "damp = " << damp << "speed = " << omega << endl;
   return -g/R*sin(theta)+damp/denom+kick/denom;
}


void step(double &t, double &theta, double &omega )
{
  // Time step variables
  double dt, h; 
  // variables for fourth-order Runge-Kutta method
  double k1, k2, k3, k4, j1, j2, j3, j4;
  int i; 

  h=100.0/Nstep;   // Try changing the value of Nstep above to see what happens 
  //cout << "Nstep = " << Nstep;

      // Fourth-Order Runge-Kutta propagation step for second order dynamical systems
        k1 = thetadot(t,theta, omega); 
        j1 = omegadot(t,theta, omega); 
        k2 = thetadot(t+h/2, theta+h/2*k1, omega+h/2*j1); 
        j2 = omegadot(t+h/2, theta+h/2*k1, omega+h/2*j1); 
        k3 = thetadot(t+h/2, theta+h/2*k2, omega+h/2*j2); 
        j3 = omegadot(t+h/2, theta+h/2*k2, omega+h/2*j2); 
        k4 = thetadot(t+h, theta+h*k3, omega+h*j3); 
        j4 = omegadot(t+h, theta+h*k3, omega+h*j3); 
        theta = theta + h/6*(k1+2*k2+2*k3+k4);
        omega = omega + h/6*(j1+2*j2+2*j3+j4);
        t = t + h;
}


void calculate(void)
{

   double t=0.0;
   double theta=M_PI/2.0;
   double omega=0.0;

   for (long i=0; i<2*Nstep; i++ ) {
    //printf("%i %f %f %f\n", i, t, theta, omega);
    cout << i << " " << t << " " << theta << " " << omega << endl;
    step( t, theta, omega);
   } 
}

