#ifndef ALGORITMOS_H
#define ALGORITMOS_H

typedef struct dados{
    long long int trocas;
    long long int comp;
    double tempo;
}Dados;

typedef struct balde{
    int *balde;
    int topo;
}Balde;

Dados bolha(int *vet, int tam);

Dados bolhaParada(int *vet, int tam);

Dados insercaoDireta(int *vet, int tam);

Dados insercaoBin(int *vet, int tam);

Dados insercaoTern(int *vet, int tam);

Dados shellSort(int *vet, int tam);

Dados selectionSort(int *vet, int tam);

Dados heapSort(int *vet, int tam);

Dados quickSortCentro(int *vet, int esq, int dir);

Dados quickSortFim(int *vet, int esq, int dir);

Dados quickSortMediana(int *vet, int esq, int dir);

Dados mergeSort(int *vet, int inicio, int final);

Dados radixSort(int *vet, int tam);

Dados bucketSort(int *vet, int tam, int nBaldes);

#endif 