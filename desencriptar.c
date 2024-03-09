#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Escrever um programa para encontrar o inverso de a mod b.]
long long int gerarChavePublica(long long int p, long long int q)
{
    return p*q;
}

void preCodificar(char mensagem[], int  result[])
{
    int i=0;
    mensagem[strlen(mensagem) - 1] = '\0';//adiciona o \0 no final da string.
    while (mensagem[i] != '\0')
    {
        result[i] = mensagem[i];
        i++;
    }
}

unsigned long long int mdc(unsigned long long int a, unsigned long long int b){
    if(a%b==0){
        return b;
    }else{
        return mdc(b,a%b);
    }
}

unsigned long long int inverse( unsigned long long int a, unsigned long long int b){
    int   i = 1;
    while ((a * i ) % b != 1) i++;
    return i;
}

unsigned long long int retornaInverso(unsigned long long p, unsigned long long int q, unsigned long long int e)
{
    unsigned long long int z,d;
    
    z = (p-1)*(q-1);
    if (mdc(e, z)!= 1)
    {
        printf ("ERRO!, eles precisam ser primos entre si\n");
        return -5;
    }
    else
    {
        d = inverse(e, z);
        return d;
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
    unsigned long long int valor1, valor2, expoente, d,chavePublica;
    char mensagem[255];
    printf ("Preciso de dois valores primos: ");
    scanf ("%lld %lld", &valor1, &valor2);
    getchar();
    printf ("Expoente 'e' relativamente primo:");
    scanf ("%lld", &expoente);
    getchar();
    d = retornaInverso(valor1, valor2, expoente);
    chavePublica = gerarChavePublica(valor1, valor2);
    printf ("Digite uma mensagem para codificar\n");
    fgets(mensagem, sizeof(mensagem), stdin);
    fflush(stdin);
    int mensagemCifrada[strlen(mensagem)];//tamanho depende do tamanho da mensagem

    preCodificar(mensagem, mensagemCifrada);
/*       for (int i=0;i<strlen(mensagem);i++)
    {
        printf ("%d\n", mensagemCifrada[i]);
    } */
    int valorEncriptado[strlen(mensagem)];

    for (int j=0; j<strlen(mensagem);j++)
    {
        valorEncriptado[j] =  fastModuleExpo(mensagemCifrada[j],expoente, chavePublica);
    }
    printf ("Desencriptando....\n");

     int valorDesencriptado[strlen(mensagem)];
    for (int k=0; k<strlen(mensagem);k++)
    {
        valorDesencriptado[k] = fastModuleExpo(valorEncriptado[k], d, chavePublica);
    }
    for (int l=0; l<strlen(mensagem);l++)
    {
        printf ("%c", valorDesencriptado[l]);
    }
    
	return 0;
}