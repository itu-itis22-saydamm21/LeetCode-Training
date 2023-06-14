#include <string.h>
int countPrimes(int n){
    if(n < 2)
    {
        return 0;
    }

 
    int* primes = (int*)calloc(n+1, sizeof(int)); 
    int count = 0;
    for(int i = 2; i < n; i++) {
        if (!primes[i]) {
            count++;
            for(int j = 2*i; j < n; j += i)
                primes[j] = 1; 
        }
    }

    



    free(primes);
    return(count);
}