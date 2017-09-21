#include "../includes/all_includes.h"

double psi_prime_error;

// Done
double psi_prime( double t, double delta_c, double delta_cp ) {
    // Calculate and Return
    // - n1(t) * \frac{ log{ 1 - L(t) } }{ L(t) }
    double L_value = L(t, delta_c, delta_cp);
    double n1_value = n1(t, delta_c);

	double value_up = ( n1_value +  n1_error ) * log( 1.0 - L_value + L_error ) / (L_value - L_error) ;
	double value_down = ( n1_value - n1_error) * log( 1.0 - L_value - L_error ) / (L_value + L_error) ;
	double value_error = fabs( value_up - value_down ) / 2.0;
	psi_prime_error = value_error;

	double result = 0.0;
	if( isinf(L_value) ){
        result = 0.0;
	}else{
        result = - n1_value * log(1.0 - L_value) / L_value;
	}

    return( result );
}
