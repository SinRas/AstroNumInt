#include "../includes/all_includes.h"

// Done
double p1n1( double s, double v, double delta_c ){
	// Calculate and Return
	// *Farnik: Gaussian( \mu = \frac{ \delta_c }{ 2*s }, \sigma^2 = \frac{1}{ 4 * s * \Gamma^2 )*
	// exp( - \frac{ (\mu - v)^2 }{ 2*\sigma^2 } ) / \sqrt{ 2*\pi*\sigma^2 }
	double mu = delta_c / ( 2.0 * s );
	double sigma2 = 1.0 / ( 4.0 * s * ggamma2() );
	double tmp = mu - v;

	return( exp( - tmp*tmp / ( 2.0 * sigma2 ) ) / sqrt( 2.0*MATH_PI*sigma2 ) );
}
