#include "e_lib.h"
#include <math.h>

volatile unsigned *max_prime = (unsigned*)0x7000;
volatile unsigned *cores = (unsigned*)0x7008;
volatile unsigned *row = (unsigned*)0x7010;
volatile unsigned *calc_end_flag = (unsigned*)0x7018;
volatile unsigned *primes = (unsigned*)0x7020;

int isprime(unsigned number){
    unsigned s = sqrt(number);
    for(unsigned i = 3; i <= s; i += 2){
        if(number % i == 0)return 0;
    }
    return 1;
}

int main(){
    (*calc_end_flag) = 0;
    e_coreid_t id = e_get_coreid();
    unsigned tmp_row, col;
    unsigned number;

    e_coords_from_coreid(id, &tmp_row, &col);

    number = (2 * (*row) * 4) + (2 * col + 1);

    (*primes) = 0;

    while(number < (*max_prime)){
        if(isprime(number)){
            (*primes)++;
        }
        number += (*cores) * 2;
    }
    (*calc_end_flag) = 1;
    return 0;
}
