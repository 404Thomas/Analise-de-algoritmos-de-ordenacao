#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos.h"

Dados bolha(int *vet, int tam){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    for(int i = tam - 1; i > 1; i--){
        for(int j = 0; j < i; j++){
            resul.comp++;
            if(vet[j] > vet[j+1]){
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                resul.trocas++;
            }
        }
    }
    
    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}


Dados bolhaParada(int *vet, int tam){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    int mudou  = 1;
    int i = tam - 1;

    while(mudou){
        int j = 1;
        mudou = 0;
        while(j < tam){
            resul.comp++;
            if(vet[j-1] > vet[j]){
                int aux = vet[j-1];
                vet[j-1] = vet[j];
                vet[j] = aux;
                mudou = 1;
                resul.trocas++;
            }
            i = j;
            j++;
        }
        tam = i;
    }

    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}


Dados insercaoDireta(int *vet, int tam){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    for(int i = 1; i < tam; i++){
        int aux = vet[i];
        int j = i-1;
        while((j>=0) && (aux < vet[j])){
            resul.comp++;
            vet[j+1] = vet[j];
            resul.trocas++;
            j--;
        }

        if(j>=0){
            resul.comp++;    
        }

        if(j != (i-1)){
            vet[j+1] = aux;
            resul.trocas++;
        }
    }

    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}


Dados insercaoBin(int *vet, int tam){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    for(int i = 1; i < tam; i++){
        int aux  = vet[i];
        int esq = 0;
        int dir = i;

        while(esq < dir){
            int meio = (esq + dir)/2;
            resul.comp++;

            if(vet[meio] <= aux){
                esq = meio + 1;
            }
            else{
                dir = meio;
            }
        }
        for(int j = i; j > esq; j--){
            vet[j] = vet[j-1];
            resul.trocas++;
        }
        if(dir != i){
            vet[dir] = aux;
            resul.trocas++;
        }
    }

    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}


Dados insercaoTern(int *vet, int tam){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    for (int i = 1; i < tam; i++) {
        int aux = vet[i];
        int esq = 0;
        int dir = i - 1;

        // Busca ternária para encontrar posição de inserção
        while (esq <= dir) {

            int terco = (dir - esq) / 3;
            int m1 = esq + terco;
            int m2 = dir - terco;

            resul.comp++;
            if (aux < vet[m1]) {
                dir = m1 - 1;
            } 
            else {
                resul.comp++;
                if (aux > vet[m2]) {
                    esq = m2 + 1;
                } 
                else {
                    // aux está entre m1 e m2
                    esq = m1 + 1;
                    dir = m2 - 1;
                }
            }
        }

        // desloca os elementos
        for (int j = i; j > esq; j--) {
            vet[j] = vet[j - 1];
            resul.trocas++;
        }

        vet[esq] = aux;
        if (esq != i) {
            resul.trocas++;
        }
    }

    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}


Dados shellSort(int *vet, int tam){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    int h = 1;
    while(h < tam){
        h = 3*h+1;
    }
    while(h > 0){
        for(int i = h; i< tam; i++){
            int aux  = vet[i];
            int j = i-h;
            int moveu = 0;

            while((j>=0) && (aux < vet[j])){
                resul.comp++;
                vet[j+h] = vet[j];
                resul.trocas++;
                j = j-h;
                moveu = 1;
            }

            if(j>=0){
                resul.comp++;
            }

            vet[j+h] = aux;
            if(moveu){
                resul.trocas++;
            }
        }
        h = h/3;
    }

    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}


Dados selectionSort(int *vet, int tam){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    for(int i = 0; i < tam; i++){
        int menor = i;
        for(int j = i +1; j < tam; j++){
            resul.comp++;
            if(vet[j] < vet[menor]){
                menor = j;
            }
        }
        if(i != menor){
            int aux  = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux;
            resul.trocas++;
        }
    }

    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}

void criarHeap(int *vet, int inicio, int final, Dados *resul){
    int aux = vet[inicio];
    int j = inicio * 2 + 1;
    while (j <= final){
        if(j < final){
            resul->comp++;
            if(vet[j] < vet[j+1]){
                j++;
            }
        }
        resul->comp++;
        if(aux < vet[j]){
            vet[inicio] = vet[j];
            resul->trocas++;
            inicio = j;
            j = 2 * inicio + 1;
        }
        else{
            j = final + 1;
        }
    }
    vet[inicio] = aux;
    resul->trocas++;
}

Dados heapSort(int *vet, int tam){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    for(int i = ((tam-1)/2); i >= 0; i--){
        criarHeap(vet, i, tam-1, &resul);
    }
    for(int i = tam-1; i>=1; i--){
        int aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        resul.trocas++;
        criarHeap(vet, 0, i-1, &resul);
    }

    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}


void particaoCentro(int *vet, int esq, int dir, int *i, int *j, Dados *resul){
    *i = esq;
    *j = dir;
    int pivo = vet[(*i + *j)/2];
    while(*i <= *j){
        while((vet[*i] < pivo) && (*i < dir)){
            resul->comp++;
            (*i)++;
        }
        resul->comp++;
        while((vet[*j] > pivo) && (*j > esq)){
            (*j)--;
            resul->comp++;
        }
        if(*i <= *j){
            int aux = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = aux;
            resul->trocas++;
            (*i)++;
            (*j)--;
        }
    }
}

void quickSortRecursivoCentro(int *vet, int esq, int dir, Dados *resul) {
    int i, j;
    particaoCentro(vet, esq, dir, &i, &j, resul);

    if (j > esq) quickSortRecursivoCentro(vet, esq, j, resul);
    if (i < dir) quickSortRecursivoCentro(vet, i, dir, resul);
}

Dados quickSortCentro(int *vet, int esq, int dir){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    quickSortRecursivoCentro(vet, esq, dir, &resul);

    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    return resul;
}

void particaoFim(int *vet, int esq, int dir, int *i, int *j, Dados *resul){
    *i = esq;
    *j = dir;
    int pivo = vet[dir];
    while(*i <= *j){
        while((vet[*i] < pivo) && (*i < dir)){
            (*i)++;
            resul->comp++;
        }
        resul->comp++;
        while((vet[*j] > pivo) && (*j > esq)){
            (*j)--;
            resul->comp++;
        }
        if(*i <= *j){
            int aux = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = aux;
            resul->trocas++;
            (*i)++;
            (*j)--;
        }
    }
}

void quickSortRecursivoFim(int *vet, int esq, int dir, Dados *resul) {
    int i, j;
    particaoFim(vet, esq, dir, &i, &j, resul);

    if (j > esq) quickSortRecursivoFim(vet, esq, j, resul);
    if (i < dir) quickSortRecursivoFim(vet, i, dir, resul);
}

Dados quickSortFim(int *vet, int esq, int dir){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    quickSortRecursivoFim(vet, esq, dir, &resul);

    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}

void particaoMediana(int *vet, int esq, int dir, int *i, int *j, Dados *resul){
    *i = esq;
    *j = dir;

    int pivo;
    if((vet[esq] <= vet[(*i + *j)/2] && vet[(*i + *j)/2] <= vet[dir]) || (vet[dir] <= vet[(*i + *j)/2] && vet[(*i + *j)/2] <= vet[esq])){
        pivo = vet[(*i + *j)/2];
    }
    else if((vet[(*i + *j)/2] <= vet[esq] && vet[esq] <= vet[dir]) || (vet[dir] <= vet[esq] && vet[esq] <= vet[(*i + *j)/2])){
        pivo = vet[esq];
    }
    else{
        pivo = vet[dir];
    }


    while(*i <= *j){
        while((vet[*i] < pivo) && (*i < dir)){
            (*i)++;
            resul->comp++;
        }
        resul->comp++;
        while((vet[*j] > pivo) && (*j > esq)){
            (*j)--;
            resul->comp++;
        }
        if(*i <= *j){
            int aux = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = aux;
            resul->trocas++;
            (*i)++;
            (*j)--;
        }
    }
}

void quickSortRecursivoMediana(int *vet, int esq, int dir, Dados *resul) {
    int i, j;
    particaoMediana(vet, esq, dir, &i, &j, resul);

    if (j > esq) quickSortRecursivoMediana(vet, esq, j, resul);
    if (i < dir) quickSortRecursivoMediana(vet, i, dir, resul);
}

Dados quickSortMediana(int *vet, int esq, int dir){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    quickSortRecursivoMediana(vet, esq, dir, &resul);

    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}


void intercalar(int *vet, int inicio, int meio, int final, Dados *resul){
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    int tamanho  = final - inicio + 1;
    int *temp = (int*) malloc(tamanho * sizeof(int));

    if (temp == NULL){exit(1);}

    while((i <= meio)||(j<=final)){
        resul->comp++;
        if((i == meio+1) || (vet[j] < vet[i]) && (j != final + 1)){
            temp[k] = vet[j];
            resul->trocas++;
            j++;
            k++;
        }
        else{
            temp[k] = vet[i];
            resul->trocas++;
            i++;
            k++;
        }
    }

    for(int i = inicio; i <= final; i++){
        vet[i] = temp[i - inicio];
        resul->trocas++;
    }

    free(temp);
}

Dados mergeSort(int *vet, int inicio, int final){
    clock_t ini, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    ini = clock();

    if(inicio < final){
        int meio = (inicio + final)/2;
        
        Dados d1 = mergeSort(vet, inicio, meio);
        resul.comp += d1.comp;
        resul.trocas += d1.trocas;
        
        Dados d2 = mergeSort(vet, meio + 1, final);
        resul.comp += d2.comp;
        resul.trocas += d2.trocas;
        
        intercalar(vet, inicio, meio, final, &resul);
    }

    fim = clock();

    resul.tempo = ((double) (fim - ini)) / CLOCKS_PER_SEC;

    return resul;
}


Dados radixSort(int *vet, int tam) {
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    // 1. Encontrar o maior número para determinar a quantidade de dígitos
    int maior = vet[0];
    for (int i = 1; i < tam; i++) {
        resul.comp++;
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }

    // Alocação de vetor auxiliar, similar ao estilo usado no bucketSort
    int *saida = (int *)malloc(tam * sizeof(int));

    // 2. Executar o Counting Sort para cada dígito (unidades, dezenas, centenas...)
    // exp é 10^i, onde i é o dígito atual
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        int baldes[10] = {0};

        // Conta a frequência de cada dígito na posição 'exp'
        for (int i = 0; i < tam; i++) {
            baldes[(vet[i] / exp) % 10]++;
        }

        // Ajusta as posições acumuladas para garantir a ordenação estável
        for (int i = 1; i < 10; i++) {
            baldes[i] += baldes[i - 1];
        }

        // Constrói o vetor auxiliar (de trás para frente para manter a estabilidade)
        for (int i = tam - 1; i >= 0; i--) {
            int digito = (vet[i] / exp) % 10;
            saida[baldes[digito] - 1] = vet[i];
            baldes[digito]--;
            resul.trocas++; // Contabiliza a movimentação para o vetor auxiliar
        }

        // Copia de volta para o vetor original para o próximo dígito
        for (int i = 0; i < tam; i++) {
            vet[i] = saida[i];
            resul.trocas++; // Contabiliza a movimentação de volta ao vetor original
        }
    }

    free(saida);

    fim = clock();
    resul.tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}


Dados bucketSort(int *vet, int tam, int nBaldes){
    clock_t inicio, fim;
    Dados resul;
    resul.comp = 0;
    resul.trocas = 0;
    resul.tempo = 0.0;

    inicio = clock();

    Balde *baldes = (Balde*)malloc(nBaldes * sizeof(Balde));

    for(int i = 0; i< nBaldes; i++){
        baldes[i].topo = 0;
        baldes[i].balde = (int*) malloc(tam * sizeof(int));
    }

    for(int i = 0; i < tam; i++){
        int j = nBaldes - 1;
        while(j>=0){
            resul.comp++;
            if(vet[i] >= j*10){
                baldes[j].balde[baldes[j].topo] = vet[i];
                resul.trocas++;
                baldes[j].topo++;
                break;
            }
            j--;
        }
    }

    for(int i = 0; i < nBaldes; i++){
        if(baldes[i].topo > 0){
            Dados d = bolha(baldes[i].balde, baldes[i].topo);
            resul.comp += d.comp;
            resul.trocas += d.trocas;
        }
    }

    int i = 0;

    for(int j = 0; j < nBaldes; j++){
        for(int k = 0; k < baldes[j].topo; k++){
            vet[i] = baldes[j].balde[k];
            resul.trocas++;
            i++;
        }
    }

    for(int i = 0; i < nBaldes; i++){
        free(baldes[i].balde);
    }
    free(baldes);
    
    fim = clock();

    resul.tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    return resul;
}