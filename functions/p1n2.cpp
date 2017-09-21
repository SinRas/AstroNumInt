#include "../includes/all_includes.h"

// Done
double p1n2( double s, double sp, double delta_cp, double delta_c, double v ){
	// Function Form
	// 	p( \delta_cp | \delta_c, v )
	//
	// Calculate and Return
	// *Farnik: Gaussian( \mu = f(s, sp, v, \Gamma), \sigma^2 = g(s, sp, v, \Gamma) )*
       // exp( - \frac{ (\mu - \delta_cp)^2 }{ 2*\sigma^2 } ) / \sqrt{ 2*\pi*\sigma^2 }
       double Gamma = sqrt( ggamma2() );
       double mu = mu1n2(s, sp, v, Gamma);
       double sigma2 = sigma1n2(s, sp, v, Gamma);
       double tmp = mu - delta_cp;

       return( exp( -tmp*tmp / (2.0 * sigma2) ) / sqrt( 2.0*MATH_PI*sigma2 ) );
}
