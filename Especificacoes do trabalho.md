ESPECIFICA��ES DO TRABALHO

Objeto: desenvolver um Tipo Abstrato de Dados - TAD ou uma Classe que represente grafos simples, orientados e n�o
orientados, ponderados e n�o ponderados (nos v�rtices e arestas) e implemente o conjunto de funcionalidades
apresentadas a seguir, detalhadas em sala de aula. O desenvolvimento dos algoritmos aqui requeridos contribui como
base para a resolu��o das quest�es das avalia��es te�ricas.


Orienta��es:
� seu TAD ou Classe deve ser capaz de representar grafos utilizando lista de adjac�ncia;
� o c�digo deve ser desenvolvido em linguagem C ou C++ (padr�o ANSI);
� Al�m do atendimento �s funcionalidades, alguns dos elementos avaliados s�o a clareza e a organiza��o do
c�digo (nomes de fun��es e vari�veis, coment�rios que indiquem o prop�sito das principais fun��es e
procedimentos, inclusive explicando o que s�o os par�metros e o retorno, em caso de fun��o);
� o programa principal que usar� o TAD ou a Classe Grafo deve ler os dados do grafo de entrada (direcionados
ou n�o direcionados, ponderados ou n�o ponderados) a partir de arquivo texto. O formato do arquivo
depender� da origem dos dados de entrada. Assim, cabe ao grupo ler o arquivo README que explica a sem�ntica
do arquivo de entrada ou, caso n�o haja este arquivo, o grupo deve ler o detalhamento do mesmo na fonte de
dados, implementando conforme o caso. Entenda-se por formato do arquivo a estrutura em que os dados do grafo
aparecem no texto do mesmo. Por exemplo, para algumas inst�ncias teste, o arquivo pode ser apresentado como
segue no exemplo, onde se tem um grafo simples, n�o ponderado nos v�rtices e ponderado nas arestas, n�o
direcionado. Neste exemplo, a primeira linha indica o n�mero de v�rtices e as demais linhas indicam cada aresta
e seu peso.
� a informa��o sobre o tipo de grafo, se direcionado ou n�o direcionado, deve ser passada ao programa por
par�metro via linha de comando (par�metros da fun��o main), sendo 0 (zero) para n�o direcionado e 1 (um) para
grafos direcionados. Note que o TAD ou Classe deve prever a exist�ncia de duas formas de inclus�o das
adjac�ncias, conforme cada caso.



Especifica��o do trabalho pr�tico 1 da disciplina DCC059 � Teoria dos Grafos � Semestre 2022-1 Turma A 2
� a informa��o sobre arestas ponderadas ou n�o deve ser passada ao programa por par�metro via linha de
comando, sendo 0 (zero) para n�o ponderado nas arestas e 1 (um) para grafos com peso nas arestas.
� a informa��o sobre a exist�ncia de pesos nos v�rtices deve ser passada ao programa por par�metro via linha de
comando, sendo 0 (zero) quando o grafo n�o � ponderado nos v�rtices e 1 (um) para grafos com pesos nos
v�rtices.
� o nome do arquivo a ser lido deve ser informado ao programa via teclado para a fun��o main (utilizar int main
(int argc, char ** argv) para passar ao programa todas as informa��es necess�rias ao seu funcionamento;
� cada grupo enviar� um unico e-mail contendo APENAS os arquivos fonte (extens�o c, cc, cpp e h) e os arquivos
de entrada utilizados (quando o professor n�o os tiver encaminhado antes);
� o padr�o para compila��o a ser utilizado (ambiente Linux ou IOS) ser� g++ *.c* - o execGrupoX. Onde �GrupoX�
indica a qual grupo o trabalho se refere;
� o padr�o para a execu��o a ser utilizado pelo professor ser� a linha abaixo, executada em ambiente Linux ou
IOS:
�./execGrupoX <arquivo_entrada> <arquivo_saida> <Opc_Direc> <Opc_Peso_Aresta> <Opc_Peso_Nos>, onde
< arquivo_entrada> � o nome do arquivo que cont�m as informa��es do grafo, < arquivo_saida> � o arquivo onde
ser� gravado o grafo armazenado na mem�ria ao t�rmino do;
� o grupo deve enviar um �NICO arquivo compactado de nome Trabalho_GrupoX.zip para o e-mail indicado em
sala de aula, cujo assunto da mensagem seja �Trabalho Grafos Grupo X � 2020-3�, onde X indica o n�mero do
grupo.
Nota: no arquivo zip deve ter incluso APENAS os arquivos com extens�o c, cc, cpp ou h e os arquivos das
inst�ncias usadas no experimento.
Funcionalidades:
� O programa deve apresentar em tela a sa�da para as seguintes funcionalidades definidas nas sa�das
conforme os par�metros:

a) Par�metro: um ID de um v�rtice de um grafo direcionado; (0,5 pontos)
Sa�da: o fecho transitivo direto deste v�rtice. //todos os vertices alcan�ados a partir desse vertice

b) Par�metro: um ID de um v�rtice de um grafo direcionado; (0,5 pontos)
Sa�da: o fecho transitivo indireto deste v�rtice. //todos os vertices que alcan�am esse vertice

c) Par�metro: o ID de v�rtices do grafo (1,0 pontos)
Sa�da: o coeficiente de agrupamento local do v�rtice

d) Par�metro: um grafo; (3 pontos)
Sa�da: o coeficiente de agrupamento m�dio do grafo;
e) Par�metro: dois IDs de v�rtices do grafo; (1 ponto)
Sa�da: o caminho m�nimo entre estes dois v�rtices usando algoritmo de Djkstra;

f) Par�metro: dois IDs de v�rtices do grafo; (1 ponto)
Sa�da: o caminho m�nimo entre estes dois v�rtices usando algoritmo de Floyd;

g) Par�metro: um subconjunto X de v�rtices de um grafo; (1 ponto)
Sa�da: uma �rvore Geradora M�nima sobre o subgrafo v�rtice-induzido por X usando o algoritmo de Prim;

h) Par�metro: um subconjunto X de v�rtices do grafo; (1 ponto)
Sa�da: uma �rvore Geradora M�nima sobre o subgrafo v�rtice-induzido por X usando o algoritmo de
Kruskal;

i) Par�metro: um ID de v�rtice; (1 ponto)
Sa�da: a �rvore dada pela ordem de caminhamento em profundidade a partir de n� dado par�metro,
destacando as arestas de retorno;


� Todas as sa�das das funcionalidades acima devem ser apresentadas na tela. Ao final da execu��o;
� Com exce��o do item h, todas as sa�das devem ser dadas na linguagem �dot� para gera��o de grafos para
no software Graphviz (vide http://www.inf.ufes.br/~pdcosta/ensino/2018-2-estruturas-de-
dados/material/Tutorial%20Graphviz.pdf).



Perguntas Frequentes
1. Quantos membros um grupo pode ter?
O trabalho pode ter no m�ximo 4 pessoas. Mas, caso haja interesse de fazer o trabalho individualmente,
voc� deve estar ciente de que, uma vez informado ao professor, n�o poder� integrar um outro grupo depois.
2. Se eu fizer alguma parte do trabalho individualmente ou em grupo, terei que fazer o trabalho 2 correspondente
ao assunto da Unidade 6 da mesma forma (mesmo grupo)?
Sim, pois a avalia��o do trabalho considera a composi��o de todas as funcionalidades requeridas.
3. O projeto poder� ter mais de um arquivo fonte (c, cc, cpp e h)?
Pode (e, para boa organiza��o do c�digo, deve). Como usual, a especifica��o do trabalho descreve somente
a interface a ser implementada. A organiza��o do projeto � livre.
4. O que ser� levado em conta na corre��o?
Na corre��o ser�o levados em conta (entre outros) os seguintes elementos.
1. Intera��o com o professor;
2. Conformidade com a especifica��o.
3. Corre��o da implementa��o.
4. Efici�ncia da implementa��o.
5. Organiza��o e clareza do c�digo (nomes de fun��es e vari�veis, coment�rios etc).
5. Por que a especifica��o de como o programa ser� executado � importante?
Porque o trabalho entregue poder� ser pr�-processado por um script que depende de a especifica��o de
entrega ser corretamente observada.
6. O que acontece se a especifica��o de execu��o do programa n�o for corretamente observada?
Seu trabalho s� ser� corrigido quando houver tempo de fazer manualmente o pr�-processamento. Por isso,
haver� desconto na sua nota, proporcional ao trabalho de pr�-processamento que tenha que ser feito
manualmente.
7. Meu trabalho tem um bug. O que vai acontecer com minha nota?
Haver� algum desconto, dependendo da gravidade do bug. Se o problema afetar alguma das funcionalidades
requeridas, o desconto ser� proporcional ao que estiver faltando.
8. Meu c�digo n�o compila. Posso enviar assim mesmo?
N�o ser�o avaliados trabalhos com erros de compila��o. Por isso a import�ncia de se usar apenas fun��es
do padr�o Ansi.
9. Tenho outra pergunta/d�vida a respeito do trabalho.
Procure os professores ou os tutores para tirar suas d�vidas no hor�rio de atendimento ou durante as aulas.
