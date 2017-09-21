#include "../includes/all_includes.h"

double R_error;

// Done
double R( double s, double sp, double delta_c, double delta_cp ){
	// Calculate and Return
	// 1.0 - ( n2( s, sp ) / ( n1(s) * n1(sp) ) )
	double result = 1.0 - ( n2( s, sp, delta_c, delta_cp ) / ( n1(s, delta_c) * n1(sp, delta_c) ) );
	// Error
	double value_up = (n2(s, sp, delta_c, delta_cp) + n2_error) / ( n1(s, delta_c) - n1_error ) * ( n1(sp, delta_c) - n1_error );
	double value_down = (n2(s, sp, delta_c, delta_cp) - n2_error) / ( n1(s, delta_c) + n1_error ) * ( n1(sp, delta_c) + n1_error );
	R_error = fabs( value_up - value_down ) / 2.0;

	return( result );
}
