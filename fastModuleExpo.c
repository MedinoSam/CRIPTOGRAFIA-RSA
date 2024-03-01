#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>





// divida por 10 at� que o quociente seja menor que 10, ap�s empilhar esses resultados, printe os restos.
//caso base = a <= 10
int decimalParaBinario(int decimal, int result[])
{   
    int binario[32]; // array para armazenar os bits do número binário
    int i = 0; // contador para o índice do array

    // converte decimal para binário
    while (decimal > 0)
    {
        binario[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    // imprime o número binário na ordem reversa
    int k=0;
    for (int j = i - 1; j >= 0; j--)
    {
        result[k++] = binario[j];
        
    }
    return i;
}

long long int fastModuleExpo(long long int base, long long int expoente, int modN)
{   
    int expoBinario[32];
    int restos[32];
    restos[0] = base;

     int tamanho = decimalParaBinario(expoente, expoBinario);
     int j=0;
    for (int i=1;i <tamanho;i++)
    {
        if (expoBinario[j+1] == 0)
        {
            restos[i] = (restos[i-1]*restos[i-1])%modN;
            j++;
        }
        else if (expoBinario[j+1] == 1)
        {
            restos[i] = ((restos[i-1]*restos[i-1])*base)%modN;
            j++;
        }
    }

        return ("%d ", restos[tamanho-1]);
    
}




int main() {
    long long int base, expoente, modulo;
    printf ("Digite a base, o expoente e o modulo: ");
    scanf("%lld %lld %lld", &base, &expoente, &modulo);
    long long int result = fastModuleExpo(base,expoente, modulo);
    printf ("Resultado com algortimo exponenciacao modular rapida: %lld\n", result);    
    int result2 = pow(base,expoente);
    printf ("Resultado usando funcao pow: %d\n", result2);

}