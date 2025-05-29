---

# 🧠 Análise e Comparação de Algoritmos de Ordenação em C

<p align="center">
  <img src="https://user-images.githubusercontent.com/49700354/114078715-a61b2f00-987f-11eb-8eef-6fd7cfc17d33.png" alt="UFRR Logo" width="80" height="80">
</p>

Projeto desenvolvido para a disciplina de **Análise de Algoritmos (UFRR - 2025)** com o objetivo de implementar e comparar diferentes algoritmos de ordenação utilizando a linguagem **C**.

---

## 📌 Objetivo

Implementar e comparar algoritmos de ordenação com base em:

* ⏱️ Tempo de execução
* 🔁 Número de comparações realizadas

A análise é feita para diferentes tipos e tamanhos de listas de entrada. Os resultados são exibidos através de gráficos para facilitar a visualização e comparação.

---

## 🔧 Algoritmos Implementados

* Bubble Sort
* Insertion Sort
* Merge Sort
* Quick Sort

Cada algoritmo conta o número de comparações realizadas durante a ordenação.

---

## 🧪 Tipos de Entrada

* **Ordenado**: `[1, 2, 3, ..., N]`
* **Aleatório**: números embaralhados entre `1` e `N`
* **Decrescente**: `[N, N-1, ..., 1]`

---

## 📦 Tamanhos de Entrada

* 1.000
* 10.000
* 100.000
* 500.000
* 1.000.000

---

## 📁 Estrutura do Projeto

```
ordenacao/
├── entradas/             # Arquivos de entrada
│   ├── entrada_1000_random.txt
│   ├── entrada_10000_sorted.txt
│   └── ...
│
├── algoritmos/           # Códigos de ordenação
│   ├── bubble_sort.c
│   ├── insertion_sort.c
│   └── ...
│
├── utils/                # Utilitários
│   ├── gerar_entradas.c
│   └── medir_performance.c
│
├── resultados/           # Resultados coletados
│   └── resultados.csv
│
└── graficos/             # Scripts Python para geração de gráficos
    └── graficos.py
```

---

## 🧰 Ferramentas Utilizadas

* Linguagem C (`<time.h>` para tempo, arquivos `.txt`)
* Python com `matplotlib` para visualização gráfica
* CSV para coleta e armazenamento de resultados

---

## 📈 Gráficos Gerados

Os seguintes gráficos são gerados com base nos testes:

1. Tempo de execução × Tamanho da entrada (Entradas Aleatórias)
2. Comparações × Tamanho da entrada (Entradas Aleatórias)
3. Tempo de execução × Tamanho da entrada (Entradas Ordenadas)
4. Comparações × Tamanho da entrada (Entradas Ordenadas)
5. Tempo de execução × Tamanho da entrada (Entradas Decrescentes)
6. Comparações × Tamanho da entrada (Entradas Decrescentes)

Obs: É gerado de forma iterativa, ou seja, é preciso interpretar o código .py

---

## ✅ Critérios de Avaliação

* Correta implementação dos algoritmos
* Contagem precisa das comparações
* Coleta adequada dos dados
* Clareza na apresentação dos gráficos
* Análise crítica dos resultados

---

## 👥 Autoria

Desenvolvido por:

* **Victor Hugo**
* **Sarah E.**

Disciplina de Análise de Algoritmos – UFRR – 2025

---
