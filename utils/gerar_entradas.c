#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função para gerar vetor ordenado
void gerar_ordenado(int *vetor, int n) {
    for (int i = 0; i < n; i++)
        vetor[i] = i + 1;
}

// Função para gerar vetor decrescente
void gerar_decrescente(int *vetor, int n) {
    for (int i = 0; i < n; i++)
        vetor[i] = n - i;
}

// Função para embaralhar o vetor (aleatório)
void embaralhar(int *vetor, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

void salvar_em_arquivo(int *vetor, int n, const char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "w");
    if (!fp) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d\n", vetor[i]);
    fclose(fp);
}

int main() {
    int tamanhos[] = {1000, 10000, 100000, 500000, 1000000};
    const int qtd_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    srand(time(NULL));

    for (int i = 0; i < qtd_tamanhos; i++) {
        int n = tamanhos[i];
        int *vetor = malloc(sizeof(int) * n);
        if (!vetor) {
            fprintf(stderr, "Erro de memória para tamanho %d\n", n);
            exit(1);
        }

        char nome[100];

        gerar_ordenado(vetor, n);
        sprintf(nome, "entradas/entrada_%d_sorted.txt", n);
        salvar_em_arquivo(vetor, n, nome);

        gerar_decrescente(vetor, n);
        sprintf(nome, "entradas/entrada_%d_desc.txt", n);
        salvar_em_arquivo(vetor, n, nome);

        gerar_ordenado(vetor, n);
        embaralhar(vetor, n);
        sprintf(nome, "entradas/entrada_%d_random.txt", n);
        salvar_em_arquivo(vetor, n, nome);

        free(vetor);
        printf("Gerado: %d elementos\n", n);
    }

    printf("Todos os arquivos foram gerados com sucesso.\n");
    return 0;
}
