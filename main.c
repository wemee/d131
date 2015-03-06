#include "stdio.h"
#include "stdlib.h"

int main(){
    int n, idx, i, check_for, printf_count;
    int primes[25]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int *primes_count;
    while (scanf("%d", &n) != EOF) {
        if (n==0) break;

        primes_count = calloc(100, sizeof(int));
        
        for (i=2; i<=n; i++) {
            idx = 0;
            check_for = i;
            while (primes[idx]<=check_for && idx<=25) {
                if (check_for%primes[idx] == 0) {
                    primes_count[primes[idx]]++;
                    check_for /= primes[idx];
                    continue;
                }
                idx++;
            }
        }
        
        printf("%3d! =", n);
        printf_count = 0;
        for (i=0; i<25; i++) {
            if (primes[i] > n) break;
            if (printf_count >= 15) {
                printf("\n      ");
                printf_count = 0;
            }
            printf("%3d", primes_count[primes[i]]);
            printf_count++;
        }
        printf("\n");
        free(primes_count);
    }
    return 0;
}
