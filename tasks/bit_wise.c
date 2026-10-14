#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int i, j;
    int output[] = {0, 0, 0};
    for (i = 1; i < n; i++) {
        for (j = i + 1; j <= n; j++) {
            if ((i & j) < k && (i & j) > output[0]){
                output[0] = i & j;
            }
            if ((i | j) < k && (i | j) > output[1]) {
                output[1] = i | j;
            }
            if ((i ^ j) < k && (i ^ j) > output[2]) {
                output[2] = i ^ j;
            }
            
        }
    }
    
    for (int value = 0; value < 3; value++) {
        printf("%d\n", output[value]);
    }
}

int main() {
    
    int n, k;
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
    
 
    return 0;
}

/*
void calculate_the_maximum(int n, int k) {
    int max_and = 0, max_or = 0, max_xor = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int and_res = i & j;
            int or_res = i | j;
            int xor_res = i ^ j;
            
            if (and_res < k && and_res > max_and) max_and = and_res;
            if (or_res < k && or_res > max_or) max_or = or_res;
            if (xor_res < k && xor_res > max_xor) max_xor = xor_res;
        }
    }
    
    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
}
*/
