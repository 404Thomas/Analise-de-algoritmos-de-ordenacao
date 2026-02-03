#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gerador.h"
#include "algoritmos.h"

int main() {

    int qtdElementos[] = {10000, 100000, 500000}; //valores para fins de testes. o: 10000, 100000, 500000

    FILE *arq = fopen("resultados.csv", "w"); //cria ou abre o arquivo para escrever os resultados
    FILE *arqVetores = fopen("vetores.txt", "w"); // arquivo txt para guardar os vetores gerados

    if (arq == NULL || arqVetores == NULL) {
        printf("\nNão foi possivel criar/abrir o arquivo!");
        return 1;
    }
    fprintf(arq,"Algoritmo;Tamanho;Cenario;Tempo;troca;Comparações\n"); //formato do arquvio

    for (int i=0; i<3; i++) { //inicio do teste
        int qtdAtual = qtdElementos[i]; //define a quantidade de elementos para rodar o teste.

        int *vetOriginal = (int*) malloc(qtdAtual * sizeof(int));
        int *vetCopia = (int*) malloc(qtdAtual * sizeof(int));

        for (int j=0; j<3; j++) {
            if (j==0) {
                geraAleatorio(vetOriginal, qtdAtual); //gera o vetor de elementos a serem ordenados

                // SALVAR NO ARQUIVO
                fprintf(arqVetores, "--- Vetor Aleatorio: %d Elementos ---\n", qtdAtual);
                for(int k = 0; k < qtdAtual; k++){
                    // Salva o numero. O espaço ou \n separa os valores
                    fprintf(arqVetores, "%d\n", vetOriginal[k]);
                }
                fprintf(arqVetores, "\n"); // Pula uma linha no final do bloco
                printf("\nVetor aleatorio de tamanho %d salvo em arquivo.\n", qtdAtual); // Feedback visual
                // -------------------------------------
            }
            else if (j==1) geraCrescente(vetOriginal, qtdAtual);
            else geraDecrescente(vetOriginal, qtdAtual);

            //inicio das comparações

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int)); //joga no vetor de copia os dados do original
            printf("\nrodando BOLHA, %d elementos - %d", qtdElementos[i], j); //feedback visual no terminal
            fflush(stdout);
            Dados d = bolha(vetCopia,qtdAtual); //executa o codigo com o vetor e qnt de elementos corretos
            fprintf(arq,"Bolha;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp); //grava os resultados no arquivo

            //basicamente repetir para todos os algoritmos

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando BOLHA PARADA, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = bolhaParada(vetCopia,qtdAtual);
            fprintf(arq,"BolhaParada;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando insDIR, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = insercaoDireta(vetCopia, qtdAtual);
            fprintf(arq,"Inserção Direta;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando insBIN, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = insercaoBin(vetCopia,qtdAtual);
            fprintf(arq,"Inserção Binaria;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando insTER, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = insercaoTern(vetCopia,qtdAtual);
            fprintf(arq,"Inserção Ternaria;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando SHELLSORT, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = shellSort(vetCopia,qtdAtual);
            fprintf(arq,"ShellSort;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando selection, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = selectionSort(vetCopia,qtdAtual);
            fprintf(arq,"SelectionSort;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando HEAP, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = heapSort(vetCopia,qtdAtual);
            fprintf(arq,"HeapSort;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando quickCENTRO, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = quickSortCentro(vetCopia,0,qtdAtual -1);
            fprintf(arq,"QuickSortCentro;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando quickFIM, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = quickSortFim(vetCopia,0,qtdAtual -1);
            fprintf(arq,"QuickSortFim;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando quickMEDIANA, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = quickSortMediana(vetCopia,0,qtdAtual -1);
            fprintf(arq,"QuickSortMediana;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando MERGE, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = mergeSort(vetCopia,0, qtdAtual -1);
            fprintf(arq,"MergeSort;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando RADIX, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = radixSort(vetCopia,qtdAtual);
            fprintf(arq,"RadixSort;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);

            memcpy(vetCopia, vetOriginal, qtdAtual * sizeof(int));
            printf("\nrodando BUCKET, %d elementos - %d", qtdElementos[i], j);
            fflush(stdout);
            d = bucketSort(vetCopia,qtdAtual, qtdAtual/10);
            fprintf(arq,"BucketSort;%d;%d;%f;%lld;%lld\n", qtdAtual, j, d.tempo, d.trocas, d.comp);
        }

        free(vetOriginal);
        free(vetCopia);
    }

    fclose(arq);
    fclose(arqVetores);

    printf("\nResultados salvos com sucesso.");
    return 0;
}