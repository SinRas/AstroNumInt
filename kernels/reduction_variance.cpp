#include "../includes/all_includes.h"

// Done
void reduction_variance( double *h_input, double *h_output, double mean, int ARRAY_SIZE, int ARRAY_BYTES ){
    h_output[0] = 0.0;
	double tmp;
	for( int i = 0; i < ARRAY_SIZE; i++ ){
		tmp = h_input[i] - mean;
		h_output[0] += tmp*tmp;
	}
	return;
}
