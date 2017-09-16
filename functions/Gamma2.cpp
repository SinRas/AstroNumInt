// Done
double Gamma2(){
	// Function Form:
	// 	\Gamma^2 = \frac{ \gamma^2 }{ 1 - \gamma^2 }
	// 	= \frac{1}{ 1 - \gamma^2 } - 1
	tmp = gamma();
	return( sqrt( ( 1.0 / (1.0 - tmp*tmp) ) - 1.0 ) );
}
