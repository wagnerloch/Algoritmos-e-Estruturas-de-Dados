# Algoritmos e Estruturas de Dados

Repositório dedicado a exercícios referentes a disciplina de Algoritmos e Estrutura de Dados. Além dos itens listados abaixo, neste repositório você também poderá encontrar trabalhos e provas que foram realizados no decorrer da disciplina. Convido você a explorá-lo e tentar resolver os desafios 😃

## [Agenda Simples](https://github.com/wagnerloch/Algoritmos-e-Estruturas-de-Dados/blob/master/Agenda%20Simples.c)

Este exercício foi solicitado por um aluno de uma instituição privada que estava com dificuldades em programação. Orientei e ajudei a desenvolver o seu código com diversos comentários e tentando deixá-lo o mais didático possível.

## [Agenda sem Variáveis](https://github.com/wagnerloch/Algoritmos-e-Estruturas-de-Dados/tree/master/Agenda%20sem%20Variaveis/Agenda)

Este exercício ~desafio~ foi proposto nas primeiras semanas de aula da disciplina de AED. O objetivo era criar uma agenda porém a restrição era de não utilizar variáveis, apenas ponteiros. O grande desafio deste exercício é lidar com a alocação de memória. Então, para ter uma representação visual de como a memória estava sendo alocada no decorrer da execução, criei um [arquivo no excel](https://github.com/wagnerloch/Algoritmos-e-Estruturas-de-Dados/blob/master/Agenda%20sem%20Variaveis/Agenda/Aloca%C3%A7%C3%A3o%20da%20Mem%C3%B3ria.xlsx) que exibe quantos bits cada variável ocupa.

Desafio você a praticar este exercício. Tente fazer algo semelhante e se tiver dúvidas confira o código 😊.

## [Ordenação por Inserção - Insertion Sort](https://github.com/wagnerloch/Algoritmos-e-Estruturas-de-Dados/blob/master/Insertion%20Sort%20Wagner/Insertion%20Sort/main.c)

Algoritmo de ordenação que, dado uma estrutura constrói uma matriz final com um elemento de cada vez, uma inserção por vez. Neste código você poderá ordenar de forma crescente ou decrescente números que podem ser gerados de forma automática. Veja no exemplo abaixo como funciona a execução do algoritmo para ordenação crescente.

![Insertion Sort Example](https://upload.wikimedia.org/wikipedia/commons/9/9c/Insertion-sort-example.gif)

## [Ordenação por Mistura - Merge Sort](https://github.com/wagnerloch/Algoritmos-e-Estruturas-de-Dados/blob/master/Merge%20Sort%20Wagner/Merge%20Sort/main.c)

Exemplo de algoritmo de ordenação por comparação que usa o conceito do tipo **dividir-para-conquistar**. Sua ideia básica consiste em Dividir o vetor inúmeras vezes, tornando a tarefa de ordenar tão simples quanto verificar dois números. Posteriormente vem a Conquista com a ordenação do vetor em sua totalidade. Veja no exemplo abaixo como ocorre a execução do algoritmo.

![Merge Sort Example](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)

## [Fila](https://github.com/wagnerloch/Algoritmos-e-Estruturas-de-Dados/tree/master/Fila/Fila)

Fila é um tipo de Estrutura de Dados FIFO (*First In First Out*), ou seja, o primeiro que chegar será o primeiro a sair, assim como o próprio nome sugere 😉. Veja na *gif* abaixo como ocorre a inserção e remoção de elementos.

![Exemplo Fila](https://i1.faceprep.in/Companies-1/queue-operations.gif)

## [Pilha](https://github.com/wagnerloch/Algoritmos-e-Estruturas-de-Dados/tree/master/Pilha/Pilha_Wagner_Loch)

Pilha é outro tipo de Estrutura de Dados, porém diferentemente de Fila ela é do tipo LIFO (*Last In First Out*), ou seja, o último a chegar é o primeiro a sair. Uma boa analogia é uma pilha de pratos sujos, você sempre insere novos pratos em cima e retira por cima já que retirar pelo meio ou final seria algo muito difícil. Vejja na *gif* abaixo como ocorre a inserção e remoção de elementos.

![Exemplo Pilha](https://i1.faceprep.in/Companies-1/stack-operations-in-c.gif)

## [Lista Encadeada](https://github.com/wagnerloch/Algoritmos-e-Estruturas-de-Dados/tree/master/Lista%20Encadeada/Lista%20Encadeada)

A Lista Encadeada é um tipo de Estrutura de Dados onde os elementos guardam referência para o próximo elemento da lista. O desafio de lidar com este tipo de estrutura é quando você decide inserir ou remover elementos no meio da lista, é necessário ter muito cuidado com as referências para não se perder. A imagem abaixo mostra como funciona uma lista encadeada, onde a estrutura armazena um ponteiro para o próximo elemento.

![Exemplo Lista Encadeada](https://www.codeproject.com/KB/cpp/linked_list/image001.gif)
