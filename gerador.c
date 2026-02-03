#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador.h"

void gerar(int *vet, int tam){
    int op;
    printf("------ GERADOR DE NUMEROS-----\n");
    printf("DESEJA GERAR SEUS NÚMEROS DE QUE FORMA:\n");
    printf("1- ALEATORIO\t2- CRESCENTE\t3-DECRESCENTE\n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        geraAleatorio(vet, tam);
        break;
    case 2:
        geraCrescente(vet, tam);
        break;
    case 3:
        geraDecrescente(vet, tam);
        break;
    default:
        printf("OPCAO INVALIDA\n");
        break;
    }
}

void geraAleatorio(int *vet, int tam){
    srand(time(NULL));

    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 100001;
        //printf("%d\n", vet[i]);
    }
}

void geraCrescente(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        vet[i] = i;
        //printf("%d\n", vet[i]);
    }
}

void geraDecrescente(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
        //printf("%d\n", vet[i]);
    }
} 

void imprimeVetor(int *vet, int tam){
    for(int i = 0; i< tam; i++){
        printf("%d\n", vet[i]);
    }
}