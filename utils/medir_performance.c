#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Declaração externa da variável de comparações dos algoritmos
long long comparacoes = 0;

// Declaração dos algoritmos
void bubble_sort(int *arr, int n);
void insertion_sort(int *arr, int n);
void merge_sort(int *arr, int l, int r);
void quick_sort(int *arr, int low, int high);

// Função para ler vetor de um arquivo
int* ler_arquivo(const char *nome_arquivo, int *tamanho) {
    FILE *fp = fopen(nome_arquivo, "r");
    if (!fp) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    int capacidade = 1000;
    int *vetor = malloc(sizeof(int) * capacidade);
    int valor, count = 0;

    while (fscanf(fp, "%d", &valor) == 1) {
        if (count >= capacidade) {
            capacidade *= 2;
            vetor = realloc(vetor, sizeof(int) * capacidade);
        }
        vetor[count++] = valor;
    }

    fclose(fp);
    *tamanho = count;
    return vetor;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <algoritmo> <arquivo_entrada.txt>\n", argv[0]);
        printf("Algoritmos: bubble, insertion, merge, quick\n");
        return 1;
    }

    const char *algoritmo = argv[1];
    const char *arquivo = argv[2];

    int n;
    int *arr = ler_arquivo(arquivo, &n);

    clock_t inicio = clock();
    comparacoes = 0;

    if (strcmp(algoritmo, "bubble") == 0) {
        bubble_sort(arr, n);
    } else if (strcmp(algoritmo, "insertion") == 0) {
        insertion_sort(arr, n);
    } else if (strcmp(algoritmo, "merge") == 0) {
        merge_sort(arr, 0, n - 1);
    } else if (strcmp(algoritmo, "quick") == 0) {
        quick_sort(arr, 0, n - 1);
    } else {
        printf("Algoritmo inválido.\n");
        free(arr);
        return 1;
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Arquivo: %s\n", arquivo);
    printf("Algoritmo: %s\n", algoritmo);
    printf("Tamanho: %d\n", n);
    printf("Comparações: %lld\n", comparacoes);
    printf("Tempo (s): %f\n", tempo);

    free(arr);
    return 0;
}
