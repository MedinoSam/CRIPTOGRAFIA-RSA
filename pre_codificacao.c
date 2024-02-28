#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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


int main() {
    char mensagem[255];
    printf ("Digite uma mensagem\n");
    fgets(mensagem, sizeof(mensagem), stdin);
    fflush(stdin);
    int mensagemCifrada[strlen(mensagem)];//tamanho depende do tamanho da mensagem

    preCodificar(mensagem, mensagemCifrada);
      for (int i=0;i<strlen(mensagem);i++)
    {
        printf ("%d\n", mensagemCifrada[i]);
    }
   

	return 0;
}