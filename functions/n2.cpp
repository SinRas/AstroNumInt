#include "../includes/all_includes.h"

double n2_error;

// Done
double n2( double s, double sp, double delta_c, double delta_cp ) {
    // Calculate and Return
    // \int^{\infty}_{0} \int^{\infty}_{0} v*vp* p( \delta_c, \delta_cp, v, vp ) * dv * d(vp)
    // where
    // 	p( \delta_c, \delta_cp, v, vp ) := p4( \delta_c, \delta_cp, v, vp )
    // \int^{\infty}_{0} \int^{\infty}_{0} v*vp* p1(delta_c)*p1n1( v, delta_c )*p1n2(delta_cp, delta_c, v)*p1n3(vp, delta_cp, delta_c, v) * dv * d(vp)

    // Calculate Values
    const double V = 1.0 * 1.0;
    double v = 0.0, vp = 0.0, y = 0.0, yp = 0.0;
    double nominator = 0.0, denominator = 0.0;
    double *values = new double[INT_SAMPLES];
    for(unsigned int i = 0; i < INT_SAMPLES; i++) {
        v = (double) rand() /RAND_MAX;
        y = (1.0 / v) - 1.0;
        vp = (double) rand() / RAND_MAX;
        yp = (1.0 / vp) - 1.0;

        if( v == 0.0 || v == 1.0 || vp == 0.0 || vp == 1.0 ){
            i--;
            continue;
        }

        nominator = y * yp * p1(s, delta_c) * p1n1(s, y, delta_c) * p1n2(s, sp, delta_cp, delta_c, y) * p1n3(s, sp, yp, delta_c, delta_cp, y);
        denominator = v*v*vp*vp;
        values[i] = nominator / denominator;
    }
    // Get Mean and Variance
    //   Sum & Mean
    double *sum = new double[1];
    reduction_sum(values, sum, INT_SAMPLES, sizeof(double) * INT_SAMPLES);
    double mean = (double) sum[0] / INT_SAMPLES;
    //   Variance
    double *variance = new double[1];
    reduction_variance(values, variance, mean, INT_SAMPLES, sizeof(double) * INT_SAMPLES);
    // Results
    double result = V * mean;
    double std_err = (double) V * sqrt(variance[0]) / INT_SAMPLES;
    n2_error = std_err;

    return( result );
}
