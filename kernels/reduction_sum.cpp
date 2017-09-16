// Done
void reduction_sum( double *h_input, double *h_output, int ARRAY_SIZE, int ARRAY_BYTES ){
	for( int i = 0; i < ARRAY_SIZE; i++ ){
		h_output[0] += h_input[i];
	}
	return;
}
