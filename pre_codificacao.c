#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void preCodificar(char mensagem[], int  result[])
{
    int i=0;
    int h = strlen(mensagem);
    for (int i = 0 ; i < h;i++)
    {
        result[i] = mensagem[i];
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