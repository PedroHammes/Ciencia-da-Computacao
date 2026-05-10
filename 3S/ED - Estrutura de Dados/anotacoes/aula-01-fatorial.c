#include <stdio.h>

long fatorial(long n) {
    if(n==0) return 1;
    return n * fatorial(n-1);
}

int main() {
    printf("%ld\n", fatorial(5));    
}