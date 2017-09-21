#include "../includes/all_includes.h"

double psi_error;

// Done
double psi( double s, double delta_c, double delta_cp ) {
    // Calculate and Return
    // \int^{s}_{0} psi_prime(t) dt

    // Calculate Values
    double V = s;
    double t;
    double *values = new double[INT_SAMPLES];
    for(unsigned int i = 0; i < INT_SAMPLES; i++) {
        t = ( (double) rand() / RAND_MAX ) * s;
        if( t == 0.0 ){
            i--;
            continue;
        }
        values[i] = psi_prime(t, delta_c, delta_cp);
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
    double value_error = V * psi_prime_error;
    psi_error = value_error + std_err;

    return( result );
}
