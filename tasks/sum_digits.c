#include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>

long long power(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
	
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int sum = 0;
    
    for (int k = 0; k < 5; k++){
        sum += (n / power(10, k)) % 10;
    }
    
    printf("%d\n", sum);
    return 0;
}
