#include "../includes/all_includes.h"

double L_error;

// Done
double L( double s, double delta_c, double delta_cp ) {
    // Calculate and Return
    // \int^{s}_{0} R( s, sp ) * n1( sp ) * d(sp)

    // Calculate Values
    double V = s;
    double sp;
    double *values = new double[INT_SAMPLES];
    for(unsigned int i = 0; i < INT_SAMPLES; i++) {
        sp = ( (double) rand() / RAND_MAX ) * s;
        if( sp == 0.0 || sp == 1.0 ) {
            i--;
            continue;
        }
        values[i] = R( s, sp, delta_c, delta_cp ) * n1( sp, delta_c );
        // Debug - NEEDS CARE!
        if( isnan(values[i]) ){
            values[i] = 0.0;
        }

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
    double value_error = V * ( R( s, sp, delta_c, delta_cp ) * n1_error + n1( sp, delta_c ) * R_error + R_error * n1_error );
    L_error = std_err + value_error;


    return( result );
}
