#!/bin/bash

mkdir -p resultados
echo "algoritmo,tipo_entrada,tamanho,tempo,comparacoes" > resultados/resultados.csv
ulimit -s unlimited

algoritmos=("bubble" "insertion" "merge" "quick")
tipos=("sorted" "random" "desc")
tamanhos=("1000" "10000" "100000" "500000" "1000000")

for alg in "${algoritmos[@]}"; do
  for tipo in "${tipos[@]}"; do
    for tam in "${tamanhos[@]}"; do
      arquivo="entradas/entrada_${tam}_${tipo}.txt"
      if [ -f "$arquivo" ]; then
        echo "Executando: $alg - $arquivo"
        resultado=$(./medir "$alg" "$arquivo")
        
        tempo=$(echo "$resultado" | grep "Tempo" | awk '{print $3}')
        comp=$(echo "$resultado" | grep "Comparações" | awk '{print $2}')
        
        echo "$alg,$tipo,$tam,$tempo,$comp" >> resultados/resultados.csv
      else
        echo "Arquivo não encontrado: $arquivo"
      fi
    done
  done
done
