#include "../includes/all_includes.h"

double n1_error;

// Done
double n1( double s, double delta_c ) {
    // Calculate and Return
    // 1)
    // \int^{\infty}_{0} v p( \delta_c, v ) dv
    // where
    // 	p( \delta_c, v ) := p2( \delta_c, v )
    // 2)
    // p( \delta_c ) * \int^{\infty}_{0} v * p( v | \delta_c ) * dv
    // where
    // 	p( v | \delta_c ) := p1n1( v, \delta_c )

    // Calculate Values
    double V = 1.0;
    double v, y;
    double *values = new double[INT_SAMPLES];
    for(unsigned int i = 0; i < INT_SAMPLES; i++) {
        v = (double) rand() / RAND_MAX;
        y = (1.0 / v) - 1.0;

        if( v == 0.0 || v == 1.0 ){
            i--;
            continue;
        }

        values[i] = p1(s, delta_c) * y * p1n1(s, y, delta_c) / (v * v);
    }
    // Get Mean and Variance
    //   Sum & Mean
    double *sum = new double[1];
    reduction_sum(values, sum, INT_SAMPLES, sizeof(double) * INT_SAMPLES);
    double mean = sum[0] / INT_SAMPLES;
    //   Variance
    double *variance = new double[1];
    reduction_variance(values, variance, mean, INT_SAMPLES, sizeof(double) * INT_SAMPLES);
    // Results
    double result = V * mean;
    double std_err = V * sqrt(variance[0]) / INT_SAMPLES;
    n1_error = std_err;

    return( result );
}
