#include <bits/stdc++.h>
#include "../headers/Graph.h"
#include "../headers/Agm.h"
#include <string>
#include <vector>
using namespace std;

//**************************************************************************************************
//! * Definindo os métodos do grafo
//**************************************************************************************************/

//! Constructor
Graph::Graph(int order, bool directed, bool edgeWeighted, bool vertexWeighted)
{
    this->order = order;
    this->isDirected = directed;
    this->edgeIsWeighted = edgeWeighted;
    this->vertexIsWeighted = vertexWeighted;
    this->first = NULL;
    this->last = NULL;
}

Graph::~Graph()
{
}

void Graph::connectVertex(Vertex *a, Vertex *b) // Função para conectar dois vertices
{
    a->setNextEdge(b->getID(), &edgeNumber);
    if (!isDirected)
    {
        b->setNextEdge(a->getID(), &edgeNumber);
        edgeNumber -= 1;
    }
}

void Graph::connectVertex(Vertex *a, Vertex *b, int weight) // Função para conectar dois vertices com peso
{
    a->setNextEdge(b->getID(), weight, &edgeNumber);
    if (!isDirected)
    {
        b->setNextEdge(a->getID(), weight, &edgeNumber);
        edgeNumber -= 1;
    }
}

void Graph::setVertex(int nVertex) // Função para criar os vertices
{
    Vertex *v = NULL;
    first = new Vertex(1);
    first->setPrev(NULL);

    for (int i = 2; i <= nVertex; i++)
    {
        v = new Vertex(i);

        v->setPrev(getVertexByID(i - 1));
        v->getPrev()->setNext(v);
    }
}

Vertex *Graph::getVertexByID(int id) // Função para retornar o vertice pelo ID
{
    for (Vertex *v = first; v != NULL; v = v->getNext())
    {
        if (v->getID() == id)
            return v;
    }

    return NULL;
}

Vertex *Graph::getFirst() // Função para retornar o primeiro vertice
{
    return first;
}

void Graph::percorreVertices(Vertex *v) // Função para percorrer os vertices
{
    if (!v->getVisited())
        v->setVisited(true);

    for (Edge *e = v->getEdge(); e != NULL; e = e->getNext())
    {
        Vertex *w = getVertexByID(e->getID());
        if (!w->getVisited())
            percorreVertices(w);
        else
            continue;
    }
}

void Graph::clearVertex() // Função para limpar os vertices
{
    for (Vertex *v = first; v != NULL; v = v->getNext())
        v->setVisited(false);
}

/**
 * @brief          Função para calcular e exibir o fecho transitivo direto do grafo.
 * @param id       Variável que representa o id do vértice para qual será calculado o fecho transitivo direto.
 *
 */
void Graph::fechoTransitivoDireto(int id)
{
    ofstream outFile;
    outFile.open(outString);

    Vertex *i = this->getVertexByID(id);

    if (i == nullptr)
    {
        cout << "Nao existe nó com esse id";
        return;
    }

    int input;

    cout << "Deseja salvar o resultado em um arquivo de saída? " << endl;
    cout << "Digite: \n1 - Sim\n2 - Não" << endl;
    cout << "Entrada: ";
    cin >> input;

    if (input == 1)
        outFile << "Grafo: {\n";

    cout << "Fecho transitivo direto do vertice " << i->getID() << ": ";

    percorreVertices(i); // Percorre todos os vertices do grafo por um caminho em profundidade

    cout << "\n{\n";

    for (i; i != NULL; i = i->getNext())
    {
        if (i->getVisited())
        {
            cout << i->getID() << " | ";

            if (input == 1)
            {
                for (Edge *e = i->getEdge(); e != nullptr; e = e->getNext())
                    outFile << i->getID() << "->" << e->getID() << ";\n";
            }
        }
    }

    cout << "\n}\n";

    if (input == 1)
        outFile << "}\n";
}

/**
 * @brief          Função para calcular e exibir o fecho transitivo indireto do grafo.
 * @param id       Variável que representa o id do vértice para qual será calculado o fecho transitivo indireto.
 *
 */
void Graph::fechoTransitivoIndireto(int id) // Função para calcular o fecho transitivo indireto
{
    ofstream outFile;
    outFile.open(outString);

    Vertex *i = this->getFirst(), *v = this->getVertexByID(id);

    if (v == nullptr)
    {
        cout << "Nao existe nó com esse id";
        return;
    }

    int input;

    cout << "Deseja salvar o resultado em um arquivo de saída? " << endl;
    cout << "Digite: \n1 - Sim\n2 - Não" << endl;
    cout << "Entrada: ";
    cin >> input;

    if (input == 1)
        outFile << "Grafo: {\n";

    cout << "Fecho transitivo indireto do vertice " << v->getID() << ": ";
    cout << "\n{\n";

    for (i; i != nullptr; i = i->getNext())
    {
        clearVertex();
        percorreVertices(i);

        if (v->getVisited())
        {
            cout << i->getID() << " | ";

            if (input == 1)
                outFile << i->getID() << ";\n";
        }
    }

    if (input == 1)
        outFile << "\n}\n";
    cout << "\n}\n";
}

/**
 * @brief Realiza o caminhamento em profundidade, destacando as arestas de retorno.
 */
void Graph::arvoreCaminhamento() // Função para calcular e imprimir a arvore de caminhamento
{
    vector<int> returnE;
    vector<int> vec;
    vector<string> grafoS;
    int id;

    cout << "\n";
    cout << "Digite o ID do vertice: ";
    cin >> id;

    while (getVertexByID(id) == nullptr)
    {
        cout << "Nao existe nó com esse id" << endl;
        cout << "Digite o ID do vertice: ";
        cin >> id;
    }

    Vertex *v = this->getVertexByID(id);

    clearVertex();
    auxArvCam(v, &vec, &returnE, &grafoS);

    char r;

    cout << "\nArvore de caminhamento do vertice " << v->getID() << ": \n{\n";
    for (int i = 0; i < grafoS.size(); i++)
        cout << grafoS[i] << " | ";
    cout << "\n}\n";

    cout << "Arestas de retorno: \n{\n";
    for (int i = 0; i < returnE.size(); i++)
        cout << returnE[i] << " | ";
    cout << "\n}\n";

    do
    {
        cout << "Gerar  arquivo de saída(s/n)?\n";
        cin >> r;
    } while (r != 's' && r != 'S' && r != 'n' && r != 'n');

    if (r == 's' || r == 'S')
        outFileArvCam(&grafoS);

    returnE.clear();
    vec.clear();
    grafoS.clear();
}

void Graph::auxArvCam(Vertex *v, vector<int> *vec, vector<int> *returnE, vector<string> *grafoS)
{
    vec->push_back(v->getID());
    v->setVisited(true);

    for (Edge *e = v->getEdge(); e != nullptr; e = e->getNext())
    {
        if (!getVertexByID(e->getID())->getVisited())
        {
            grafoS->push_back(to_string(v->getID()) + "->" + to_string(e->getID()) + ";");
            auxArvCam(getVertexByID(e->getID()), vec, returnE, grafoS);
        }
    }
    returnE->push_back(v->getID());
}

void Graph::outFileArvCam(vector<string> *grafoS)
{
    ofstream outDot;
    ofstream outFile;
    outFile.open(outString);

    outDot.open("arvCam.dot", ios::out | ios::trunc);

    outDot << "digraph{\n";
    outFile << "digraph{\n";
    for (int i = 0; i < grafoS->size(); i++)
    {
        outDot << grafoS->at(i) << endl;
        outFile << grafoS->at(i) << endl;
    }
    outDot << "}\n";
    outFile << "}\n";

    outDot.close();
    system("dot -Tpng output.dot -o output.png");
}

Graph *Graph::getVerticeInduzido()
{
    cout << "\nVocê deseja rodar para o Grafo inteiro ou para um subgrafo?" << endl;
    cout << "1 - Grafo inteiro\n2 - Subgrafo\nSua opção: ";
    int opcao;
    cin >> opcao;

    if (opcao == 2)
    {
        cout << "\nDigite os IDs dos vértices  no formato (1;2;3;4):" << endl;

        string aux;
        cout << "Vértices: ";
        cin >> aux;

        // Vector para armazenar os ids dos vértices do subgrafo
        vector<int> idV;
        idV.clear();

        // Separando a string
        stringstream ss(aux);
        while (getline(ss, aux, ';'))
        {
            if (this->getVertexByID(stoi(aux)))
                idV.push_back(stoi(aux));
            else
                cout << "O vértice " << aux << " não está no Grafo" << endl;
        }

        // Criar o subgrafo vértice induzido
        Graph *subgrafo = new Graph(idV.size(), this->getDirected(), this->getWeightedEdge(), this->getWeightedVertex());

        // Inserindo as arestas correspondentes no subgrafo
        this->clearVertex();
        for (int i = 0; i < idV.size(); i++)
        {
            for (int j = i + 1; j < idV.size(); j++)

                // Verificar se a aresta realmente existe no grafo original
                if ((!this->getVertexByID(idV[j])->getVisited()) && this->getVertexByID(idV[i])->searchEdge(idV[j]))
                {
                    Edge *aux = this->getVertexByID(idV[i])->getEdgeByID(idV[j]);
                    subgrafo->connectVertex(getVertexByID(idV[i]), getVertexByID(idV[j]), aux->getWeight());
                }
                else
                    subgrafo->insertVertex(idV[j]);

            this->getVertexByID(idV[i])->setVisited(true);
        }

        cout << "\nO Subgrafo X foi gerado com sucesso! ";
        cout << "(Ordem = " << subgrafo->getOrder() << " e Num de Arestas = " << subgrafo->getEdgeNumber() << ")" << endl;

        return subgrafo;
    }
    else
        return this;
}

/* float Graph::camMinD()
{
    ofstream outFile;
    outFile.open(outString);

    int idSource, idTarget;
    Vertex *vSource, *vTarget;
    string idS, idT;
    try
    {
        cout << "Digite o vertice Source" << endl;
        cin >> idS;
        cout << "Digite o vertice Target" << endl;
        cin >> idT;
        idSource = stoi(idS);
        idTarget = stoi(idT);
    }
    catch (const exception &e)
    {
        cout << "Parâmetros inválidos." << endl;
        return 0;
    }

    if (idSource == idTarget)
    {
        cout << "\n\nA distância é: " << 0 << endl;
        return 0;
    } // Encerra caso seja o mesmo vertice

    vSource = getVertexByID(idSource); // Busca o vertice
    vTarget = getVertexByID(idTarget); // Busca o vertice

    if (vSource != nullptr && vTarget != nullptr)
    {

        int pSource = vSource->getPosition(), pTarget = vTarget->getPosition(), distancia = INF, V = getOrder();
        int ver = 0, c_edge = 0, u;

        int *distance = new int[V];  // Vetor para os distâncias entre a posição do noSorce e os demais
        int *antec = new int[V];     // Vetor para os antecessores
        bool *visited = new bool[V]; // Vetor para as posições já visitadas
        for (int i = 0; i < V; i++)
        {
            distance[i] = INF;
            visited[i] = false;
        }                      // Inicializador dos vetores visitados e distância
        distance[pSource] = 0; // Distância do vertice para ele mesmo

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fp; // Fila de prioridade para os pares distancia e vertice

        fp.push(make_pair(distance[pSource], pSource)); // Adiciona o par vetor distância e

        pair<int, int> p = fp.top(); // Adiciona o p na fila de prioridade

        Node *node = nullptr;
        Edge *edge = nullptr;

        while (!fp.empty())
        {

            pair<int, int> p = fp.top(); // Pega o do topo
            u = p.second;                // Obtem o vértice
            fp.pop();                    // Remove da lista de prioridade
            if (visited[u] == false)
            {
                visited[u] = true; // Marca o vertice como visitado
                node = getNodePosition(u);
                if (node != nullptr) // Busca o no pela posição
                    edge = node->getFirstEdge();
                else
                    edge = nullptr; // Pega a primeira aresta do no

                while (edge != nullptr)
                { // Passa por todas as arestas do vertice u

                    if (!getWeightedEdge())
                        c_edge = 1; // Para caso não haja pesso a distância será 1 por salto
                    else
                        c_edge = edge->getWeight();

                    ver = edge->getTargetPosition(); // Pega a posição do no Target dessa aresta

                    if (distance[ver] > (distance[u] + c_edge))
                    {                                           // Verifica se a distância é menor
                        antec[ver] = u;                         // Atualiza o antecessor
                        distance[ver] = (distance[u] + c_edge); // Atualiza a distância
                        fp.push(make_pair(distance[ver], ver)); // Adiciona o vertice na fila de prioridade
                    }
                    edge = edge->getNextEdge(); // Avança para o a proxima aresta do vertice
                }
            }
        }

        distancia = distance[pTarget];

        delete[] distance; // Desalocando o vetore usado
        delete[] visited;  // Desalocando o vetore usado

        if (distancia < INF)
            saidaDijkstra(antec, pSource, pTarget, outFile); // Imprime todo a lista na ordem de acesso

        delete[] antec;
        cout << "\n\nA distância é: " << distancia << endl;
        return distancia;
    }
    else
    {

        if (vertexSource == nullptr)
            cout << "Source node não existe nesse grafo" << endl;
        if (noTarget == nullptr)
            cout << "Target node não existe nesse grafo" << endl;
        return -1;
    }
} */

void Graph::insertVertex(int id)
{
    // confere se o grafo tem vertices
    if (this->first != nullptr)
    {
        Vertex *newVertex = new Vertex(id);
        newVertex->setPosition(this->position);
        this->last->setNextVertex(newVertex);
        this->last = newVertex;
    }
    else
    {
        Vertex *newVertex = new Vertex(id);
        newVertex->setPosition(this->position);
        this->first = newVertex;
        this->last = newVertex;
    }
    this->position = this->position + 1;
}

void Graph::agmKruskal(Graph *g)
{
    Agm *agm = new Agm();      // Criando o conjunto solucao das arestas com menor peso
    vector<Edge *> arestasAux; // Criando vetor que guarda as arestas
    int *ciclo;
    ciclo = new int[arestasGrafo.size()];

    // Atribuindo as arestas do grafo no vetor que sera ordenado
    for (auto i = arestasGrafo.begin(); i != arestasGrafo.end(); i++)
    {
        Edge *auxs = *i;
        arestasAux.push_back(auxs);
    }

    Edge *aux = NULL;

    // Ordenar as arestas conforme o peso
    for (int i = arestasAux.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arestasAux[j]->getWeight() > arestasAux[j + 1]->getWeight())
            {
                aux = arestasAux[j];
                arestasAux[j] = arestasAux[j + 1];
                arestasAux[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < arestasAux.size(); i++)
    {
        ciclo[i] = i;
    }

    for (auto i = arestasAux.begin(); i != arestasAux.end(); i++)
    {
        Edge *j = *i;
        // Detectando se com esta aresta forma ciclo:
        if (pai(j->getID(), ciclo) != pai(j->getNext(), ciclo))
        {
            unir(j->getID(), j->getNext(), ciclo);

            agm->insereAresta(j); // Insere aresta na arvore agm
        }
    }
    delete[] ciclo;
    return agm;
}
// Funcao que uni o pai de dois vertices no ciclo para descobrir se forma ciclo
void Graph::unir(int v1, int v2, int *ciclo)
{
    ciclo[pai(v1, ciclo)] = pai(v2, ciclo);
}

int Graph::pai(int v, int *ciclo)
{
    if (ciclo[v] == v)
    {
        return v;
    }

    ciclo[v] = pai(ciclo[v], ciclo);

    return ciclo[v];
}
