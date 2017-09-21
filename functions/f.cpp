#include "../includes/all_includes.h"

double f_error;

// Done
double f( double s, double delta_c, double delta_cp ){
	// Calculate and Return
	// psi_prime * exp( -psi )
	double result = psi_prime(s, delta_c, delta_cp) * exp( -psi(s, delta_c, delta_cp) );
	// This ERROR IS NOT ACCURATE!
	f_error = psi_prime_error * exp( -psi(s, delta_c, delta_cp) );

	return( result );
}
