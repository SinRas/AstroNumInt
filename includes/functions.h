// Done

// Mathematical Functions
#include <math.h>
// Random Numbers
#include <cstdlib>

// Fixed Integration Samples
#ifndef INT_SAMPLES
#define INT_SAMPLES 100
#endif // INT_SAMPLES

// Constant for Stupid Windows
#ifndef MATH_PI
#define MATH_PI 3.1415
#endif // MATH_PI

// Function Prototypes
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
extern double f_error; // Not defined accurately at the moment!
extern double L_error;
extern double n1_error;
extern double n2_error;
extern double psi_error;
extern double psi_prime_error;
extern double R_error;

double f( double s, double delta_c, double delta_cp );
double gamma2();
double ggamma2();
double L( double s, double delta_c, double delta_cp );
double mu1n2( double s, double sp, double v, double Gamma );
double mu1n3( double s, double sp, double v, double vp, double Gamma );
double n1( double s, double delta_c );
double n2( double s, double sp, double delta_c, double delta_cp );
double p1( double s, double delta_c );
double p1n1( double s, double v, double delta_c );
double p1n2( double s, double sp, double delta_cp, double delta_c, double v );
double p1n3( double s, double sp, double vp, double delta_c, double delta_cp, double v );
double psi( double s, double delta_c, double delta_cp );
double psi_prime( double t, double delta_c, double delta_cp );
double R( double s, double sp, double delta_c, double delta_cp );
double sigma1n2( double s, double sp, double v, double Gamma );
double sigma1n3( double s, double sp, double v, double vp, double Gamma );
#endif // FUNCTIONS_H
