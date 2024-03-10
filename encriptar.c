#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long int gerarChavePublica(long long int p, long long int q)
{
    return p*q;
}
void preCodificar(char mensagem[], int  result[])
{
    int i=0;
    int h = strlen(mensagem);
    for (int i = 0 ; i < h;i++)
    {
        result[i] = mensagem[i];
    }
}
unsigned long long int decimalParaBinario(unsigned long long int decimal, unsigned long long int result[])
{   
    unsigned long long int binario[32]; // array para armazenar os bits do número binário
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

unsigned long long int fastModuleExpo(unsigned long long int base, unsigned long long int expoente, unsigned long long int modN)
{   
    unsigned long long int expoBinario[32];
    unsigned long long int restos[32];
    restos[0] = base;

     unsigned long long int tamanho = decimalParaBinario(expoente, expoBinario);
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

        return ("%lld ", restos[tamanho-1]);
    
}


int main() {
    unsigned long long int result, valor1, valor2, base, expoente, chavePublica;
    char mensagem[255];
    printf ("Preciso de dois valores primos: ");
    scanf ("%lld %lld", &valor1, &valor2);
    getchar();
    printf ("Expoente 'e' relativamente primo:");
    scanf ("%lld", &expoente);
    getchar();
    chavePublica = gerarChavePublica(valor1, valor2);
    printf ("Digite uma mensagem para codificar\n");
    fgets(mensagem, sizeof(mensagem), stdin);
    fflush(stdin);
    int mensagemCifrada[strlen(mensagem)];//tamanho depende do tamanho da mensagem

    preCodificar(mensagem, mensagemCifrada);
      for (int i=0;i<strlen(mensagem);i++)
    {
        printf ("%d\n", mensagemCifrada[i]);
    }
    unsigned long long int valorEncriptado[strlen(mensagem)];

    for (int j=0; j<strlen(mensagem);j++)
    {
        valorEncriptado[j] =  fastModuleExpo(mensagemCifrada[j],expoente, chavePublica);
    }

    for (int k=0; k<strlen(mensagem);k++)
    {
        printf ("%lld\n", valorEncriptado[k]);
    }
     

	return 0;
}