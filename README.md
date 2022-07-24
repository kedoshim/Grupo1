# Trabalho de Teoria dos Grafos

## Integrantes do grupo

```
**********      Abraão                              ************@estudante.ufjf.br
202165077A      Jonatas Dias Machado Costa          jonatas.dias@estudante.ufjf.br
**********      Matheus                             ************@estudante.ufjf.br
**********      Pedro                               ************@estudante.ufjf.br
```

## Parte 1 - Funcionalidades

- Fecho Transitivo Direto
- Fecho Transitivo Indireto
- Coeficiente de agrupamento local de um vértice
- Coeficiente de agrupamento médio do grafo
- Caminho mínimo entre dois vértices, usando o algoritmo de Dijkstra
- Caminho mínimo entre dois vértices, usando o algoritmo de Floyd
- A árvore geradora mínima de um subgrafo vértice induzido por X, utilizando o algoritmo de Prim
- A árvore geradora mínima de um subgrafo vértice induzido por X, utilizando o algoritmo de Kruskal
- O caminho em profundidade dado a partir de um determinado nó do grafo, destacando as arestas de retorno

## Instruções para compilação

Utilizando o Makefile:

Criando o arquivo ./execGrupo1.exe e os arquivos .o

```
Make
```

Excluindo o arquivo ./execGrupo1.exe e os arquivos. o

```
Make clean
```

## Instruções para a execução

Para um grafo não direcionado, sem peso na aresta e nos vértices:
./execGrupo1.exe input.txt out.txt 0 0 0

Para um grafo direcionado:

```
./execGrupo1.exe input.txt out.txt 1 0 0
```

Para um grafo com peso nas arestas:

```
./execGrupo1.exe input.txt out.txt 0 1 0
```

Para um grafo com peso nos vértices:

```
./execGrupo1.exe input.txt out.txt 0 0 1
```

## Instruções para o arquivo dot

Instalar o programa em um sistema operacional Linux:

```
sudo apt install graphviz
```

Criar o gráfico utilizando o Graphviz:

```
dot -Tpng output.dot -o output.png
```
