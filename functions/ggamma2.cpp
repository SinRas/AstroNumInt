#include "../includes/all_includes.h"

// Done
double ggamma2(){
	// Function Form:
	// 	\Gamma^2 = \frac{ \gamma^2 }{ 1 - \gamma^2 }
	// 	= \frac{1}{ 1 - \gamma^2 } - 1
	return( sqrt( ( 1.0 / (1.0 - gamma2()) ) - 1.0 ) );
}
