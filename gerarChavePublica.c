#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int chavePublica(long long int p, long long int q)
{
    return p*q;
}


int main() {
    long long int result, valor1, valor2;
    scanf ("%lld %lld", &valor1, &valor2);
    result = chavePublica(valor1, valor2);
    printf ("%lld\n", result);

	return 0;
}