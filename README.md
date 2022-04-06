<h1 align="center">Contando Instruções</h1>

<p align="center">
  <a href="#problema">Problema</a> -
  <a href="#desenvolvimento">Desenvolvimento</a> -
  <a href="#executar">Executar</a>
</p>
 

# Problema
### Elaboração de um pequeno programa que utiliza uma matriz N x N, com o valor de N fornecido como entrada do programa, para executar a seguinte operação:
+ Preenche a matriz N x N com números inteiros aleatórios de 0 a 99;
+ Considerando a posição Linha 0 e Coluna 0 (0,0) como início;
+ Considerando a posição (N, N) como posição final;
+ Percorre a matriz a partir do início, somando a cada passo, o próximo maior valor encontrado;
+ O próximo valor pode ser o que está na mesma linha e imediatamente à direita, imediatamente à esquerda, bem como, o que está na coluna abaixo do numero corrente;
+ Há apenas uma exceção de percurso. Ao chegar na última linha deve-se percorre-la até o fim sem realizar mais migrações para colunas acima. 
+ Andando na matriz conforme as regras acima, qual o maior caminho do início até o final, sabendo-se que a soma das posições representa o tamanho do caminho.
### Exemplo:
Uma matriz com N=7
![image](https://user-images.githubusercontent.com/55333375/162018606-f6fa17f2-0ad1-4c70-9160-2a11e45c9526.png)

# Desenvolvimento
O problema foi desenvolvido da seguinte maneira:

* É definido pelo usuario o numero de **N** na função **define**
![image](https://user-images.githubusercontent.com/55333375/162021906-b4d24be0-d70f-4c20-8564-914ad161f200.png)
* Informado o **N**, o programa inicia a matriz e logo após printa o estado atual da matriz
* Depois é executado a função PercorrerM(), onde será feita as comparações de acordo com as regras do jogo e será feito um caminho onde cada elemento será substituido por **"-1"** e agregado a soma final
* Por fim é executado a função Caminho() que faz a transformação da matriz int em string e ao mesmo tempo substitui o "-1" por flags, finalizando com o print da matriz com o caminho percorrido e o print da soma total
![image](https://user-images.githubusercontent.com/55333375/162034066-bc368463-46e3-4e05-91bb-cde8ffc27a74.png)


# Executar
* Como executar:

```
  make
  make run
```
