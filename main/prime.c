#include <stdio.h>
#include <math.h>
#include <sys/time.h>

int isprime(unsigned number){
    unsigned s = sqrt(number);
    for(unsigned i = 3; i <= s; i += 2){
        if(number % i == 0)return 0;
    }
    return 1;
}

int main(int argc, char const *argv[]){
	unsigned primes = 0;
	unsigned max_prime;
	scanf("%u", &max_prime);
	struct timeval start, end;
	gettimeofday(&start, NULL);
	unsigned n = 1;
	while(n < max_prime){
		if(isprime(n)){
			primes++;
		}
		n += 2;
	}
	gettimeofday(&end, NULL);
	double calc_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) * 1.0e-6;
    printf("primes: %u, time : %lf\n", primes, calc_time);
	return 0;
}