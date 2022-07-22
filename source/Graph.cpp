#include <bits/stdc++.h>
#include "../headers/Graph.h"
using namespace std;

//**************************************************************************************************
//! * Definindo os métodos do grafo
//**************************************************************************************************/

//! Constructor
Graph::Graph(char **argv)
{
    outString = argv[2];
    isDirectioned = stoi(argv[3]);
    edgeIsWeighted = stoi(argv[4]);
    vertexIsWeighted = stoi(argv[5]);

    readArchives(argv);
}

Graph::~Graph()
{
}

void Graph::readArchives(char **argv) // Função para ler o arquivo de entrada e criar o grafo
{

    ifstream archive;
    string line, stringVertex = "", temp = "";
    int nVertex;

    archive.open(argv[1]);

    if (archive.is_open())
    {

        getline(archive, stringVertex);
        nVertex = stoi(stringVertex);

        setVertex(nVertex);

        vector<int> test;

        while (getline(archive, temp))
        {
            stringstream sTeste(temp);

            while (getline(sTeste, line, ' '))
                test.push_back(stoi(line));

            if (stoi(argv[4]) == 1)
                this->connectVertex(getVertexByID(test.at(0)), getVertexByID(test.at(1)), test.at(2));
            else
                this->connectVertex(getVertexByID(test.at(0)), getVertexByID(test.at(1)));

            test.clear();
        }
    }
    else
        cout << "Nao foi possivel abrir o arquivo." << endl;

    order = nVertex;
}

void Graph::connectVertex(Vertex *a, Vertex *b) // Função para conectar dois vertices
{
    a->setNextEdge(b->getID());
    if (!isDirectioned)
        b->setNextEdge(a->getID());
}

void Graph::connectVertex(Vertex *a, Vertex *b, int weight) // Função para conectar dois vertices com peso
{
    a->setNextEdge(b->getID(), weight);
    if (!isDirectioned)
        b->setNextEdge(a->getID(), weight);
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
    system("dot -Tpng arvCam.dot -o arvCam.png");
}