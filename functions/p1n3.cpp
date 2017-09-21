#include "../includes/all_includes.h"

// Done
double p1n3( double s, double sp, double vp, double delta_c, double delta_cp, double v ){
	// Function Form:
	// 	p( vp | delta_c, delta_cp, v )
	// Calculate and Return
	// *Farnik: Gaussian( \mu = fp( s, sp, v, vp, \Gamma ), \sigma^2 = gp( s, sp, v, vp, \Gamma ) )*
	// exp( - \frac{ (\mu - vp)^2 }{ 2*\sigma^2 } ) / \sqrt{ 2*\pi*\sigma^2 }
    double Gamma = sqrt( ggamma2() );
    double mu = mu1n3(s, sp, v, vp, Gamma);
    double sigma2 = sigma1n3(s, sp, v, vp, Gamma);
    double tmp = mu - vp;

    return( exp( -tmp*tmp / (2.0 * sigma2) ) / sqrt( 2.0*MATH_PI*sigma2 ) );
}
