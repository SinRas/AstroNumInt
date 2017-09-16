// Done
void reduction_variance( double *h_input, double *h_output, double mean, int ARRAY_SIZE, int ARRAY_BYTES ){
	double tmp;
	for( int i = 0; i < ARRAY_SIZE; i++ ){
		tmp = h_input - mean;
		h_output += tmp*tmp;
	}
	return;
}
