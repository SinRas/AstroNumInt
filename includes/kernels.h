// Done
#ifndef KERNELS_H
#define KERNELS_H
void reduction_sum(double *h_input, double *h_output, int ARRAY_SIZE, int ARRAY_BYTES);
void reduction_variance(double *h_input, double *h_output, double mean, int ARRAY_SIZE, int ARRAY_BYTES);
#endif // KERNELS_H
