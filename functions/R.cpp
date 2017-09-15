// Done
double R( double s, double sp, double delta_c, double delta_cp ){
	// Calculate and Return
	// 1.0 - ( n2( s, sp ) / ( n1(s) * n1(sp) ) )
	return( 1.0 - ( n2( s, sp, delta_c, delta_cp ) / ( n1(s, delta_c) * n1(sp, delta_c) ) ) );
}
