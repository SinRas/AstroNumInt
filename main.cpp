#include <iostream>
#include <cstdlib>

#include "includes/all_includes.h"

using namespace std;

int main(){
    // Variables
//    const double D_IN = 0.7;
    srand(0);


    // Test Each Functions
    cout<<"f(s, delta_c, delta_cp):\t\t"<<f(120, 0.7, 0.8)<<endl;
    cout<<"f_error: "<<f_error<<endl;


    /*
    // Compilation Test
    cout<<"### Test Compiler"<<endl;
    cout<<"Hello World!\n"<<endl;
    */

    /*
    // Return Value
    cout<<"### Test Function Calls"<<endl;
    cout<<"f(s):\t\t\t\t"<<f(D_IN)<<endl;
    cout<<"psi_prime(t):\t\t"<<psi_prime(D_IN)<<endl;
    cout<<"psi(s):\t\t\t\t"<<psi(D_IN)<<endl;
    cout<<"n1(s, delta_c):\t\t"<<n1(D_IN, D_IN)<<endl;
    cout<<"L(s):\t\t\t\t"<<L(D_IN)<<endl;
    cout<<"R(s, sp, delta_c, delta_cp):\t"<<R(D_IN,D_IN,D_IN,D_IN)<<endl;
    cout<<"n2(s, sp, delta_c, delta_cp):\t"<<n2(D_IN,D_IN,D_IN,D_IN)<<endl;
    cout<<"gamma2():\t\t"<<gamma2()<<endl;
    cout<<"ggamma2():\t\t"<<ggamma2()<<endl;
    cout<<"mu1n2(s, sp, v, Gamma):\t"<<mu1n2(D_IN,D_IN,D_IN,D_IN)<<endl;
    cout<<"mu1n3(s, sp, v, vp, Gamma):\t"<<mu1n3(D_IN,D_IN,D_IN,D_IN, D_IN)<<endl;
    cout<<"p1(s, delta_c):\t\t"<<p1(D_IN,D_IN)<<endl;
    cout<<"p1n1(s, v, delta_c):\t"<<p1n1(D_IN,D_IN,D_IN)<<endl;
    cout<<"p1n2(s, sp, delta_c, delta_cp, v):\t"<<p1n2(D_IN,D_IN,D_IN,D_IN,D_IN)<<endl;
    cout<<"p1n3(s, sp, vp, delta_c, delta_cp, v):\t"<<p1n3(D_IN,D_IN,D_IN,D_IN,D_IN,D_IN)<<endl;
    cout<<"sigma1n2(s, sp, v, Gamma):\t\t"<<sigma1n2(D_IN,D_IN,D_IN,D_IN)<<endl;
    cout<<"sigma1n3(D_IN,D_IN,D_IN,D_IN,D_IN):\t"<< sigma1n3(D_IN,D_IN,D_IN,D_IN,D_IN)<<endl;
    */

    /*
    // Kernel Tests
    //  Variables
    const unsigned int ARRAY_SIZE = 512 * 512;
    double *h_input = new double[ARRAY_SIZE];
    double *h_output = new double[1];
    //  Initialize
    for(unsigned int i = 0; i < ARRAY_SIZE; i++){
        h_input[i] = (double) rand() / RAND_MAX;
    }
    // Sequential Sum
    h_output[0] = 0.0;
    for(unsigned int i = 0; i < ARRAY_SIZE; i++){
        h_output[0] += h_input[i];
    }
    cout<<"Sum Sequential: "<<h_output[0]<<endl;
    // Kernel Sum
    reduction_sum( h_input, h_output, ARRAY_SIZE, sizeof(double) * ARRAY_SIZE );
    cout<<"Sum Kernel: "<< h_output[0] <<endl;
    */



    return(0);
}
