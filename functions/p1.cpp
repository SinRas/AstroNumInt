#include "../includes/all_includes.h"

// Done
double p1( double s, double delta_c ){
	// Calculate and Return
	// p( \delta_c ) = \frac{1}{ \sqrt{ 2*\pi*s } } * exp( - \frac{ \delta^2_c}{ 2*s } )
	return( exp( - delta_c * delta_c / (2.0 * s) ) / sqrt( 2.0 * MATH_PI * s ) );
}
