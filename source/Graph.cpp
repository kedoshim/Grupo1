#include <bits/stdc++.h>
#include "../headers/Graph.h"

Graph::Graph(char **argv)
{
    isDirectioned = std::stoi(argv[3]);
    edgeIsWeighted = std::stoi(argv[4]);
    vertexIsWeighted = std::stoi(argv[5]);

    readArchives(argv);
}

Graph::~Graph()
{
}

void Graph::readArchives(char **argv) // Função para ler o arquivo de entrada e criar o grafo
{

    std::ifstream archive;
    std::string line, stringVertex = "", temp = "";
    int nVertex;

    archive.open(argv[1]);

    if (archive.is_open())
    {

        getline(archive, stringVertex);
        nVertex = std::stoi(stringVertex);

        setVertex(nVertex);

        std::vector<int> test;

        while (getline(archive, temp))
        {
            std::stringstream sTeste(temp);

            while (getline(sTeste, line, ' '))
                test.push_back(stoi(line));

            if (std::stoi(argv[4]) == 1)
                this->connectVertex(getVertexByID(test.at(0)), getVertexByID(test.at(1)), test.at(2));
            else
                this->connectVertex(getVertexByID(test.at(0)), getVertexByID(test.at(1)));

            test.clear();
        }
    }
    else
        std::cout << "Nao foi possivel abrir o arquivo." << std::endl;
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

void Graph::percorreVertices(Vertex *v, bool arestasRetorno) // Função para percorrer os vertices destacando as arestas de retorno
{
    if (!v->getVisited())
    {
        v->setVisited(true);
    }

    if (arestasRetorno)
        arvoreC += std::to_string(v->getID()) + " ";

    for (Edge *e = v->getEdge(); e != NULL; e = e->getNext())
    {
        Vertex *w = getVertexByID(e->getID());

        // if a vertex was already visited, add it to the "arestasR" string
        if (w->getVisited())
        {
            if ((arestasRetorno && w->getID() > v->getID()) && w->getID() != v->getVisitedBefore())
                arestasR += std::to_string(w->getID()) + " -> " + std::to_string(v->getID()) + "\n";
        }
        else
        {
            w->setVisitedBefore(v->getID());
            percorreVertices(w, arestasRetorno);
        }
    }
}

void Graph::percorreVertices(Vertex *v) // Função para percorrer os vertices
{
    if (!v->getVisited())
        v->setVisited(true);

    for (Edge *e = v->getEdge(); e != NULL; e = e->getNext())
    {
        Vertex *w = getVertexByID(e->getID());
        percorreVertices(w);
    }
}

void Graph::clearVertex() // Função para limpar os vertices
{
    for (Vertex *v = first; v != NULL; v = v->getNext())
        v->setVisited(false);
}

void Graph::fechoTransitivoDireto() // Função para calcular o fecho transitivo direto
{
    int id;
    std::string s = "";

    std::cout << "\n";
    std::cout << "Digite o ID do vertice: ";
    std::cin >> id;
    std::cout << std::endl;

    clearVertex();
    Vertex *i = this->getVertexByID(id);

    percorreVertices(i);

    std::cout << "Fecho transitivo direto do vertice " << i->getID() << ": ";

    std::cout << std::endl;

    std::cout << "{ ";

    for (i; i != NULL; i = i->getNext())
    {
        if (i->getVisited())
            s += std::to_string(i->getID()) + " ";
    }

    s += "}\n";

    std::cout << s << "\n\n";
}

void Graph::fechoTransitivoIndireto() // Função para calcular o fecho transitivo indireto
{
    int id;
    std::string s = "";

    std::cout << "\n";
    std::cout << "Digite o ID do vertice: ";
    std::cin >> id;
    std::cout << std::endl;

    clearVertex();
    Vertex *i = this->getFirst(), *v = this->getVertexByID(id);

    std::cout << "Fecho transitivo indireto do vertice " << v->getID() << ": ";

    std::cout << std::endl;

    std::cout << "{ ";

    for (i; i != NULL; i = i->getNext())
    {
        for (Edge *j = i->getEdge(); j != NULL; j = j->getNext())
        {
            if (j->getID() == v->getID())
            {
                s += std::to_string(i->getID()) + " ";
                break;
            }
        }
    }

    s += "}\n";

    std::cout << s << "\n\n";
}

void Graph::arvoreCaminhamento() // Função para calcular e imprimir a arvore de caminhamento 
{
    int id;
    std::string s = "";

    std::cout << "\n";
    std::cout << "Digite o ID do vertice: ";
    std::cin >> id;

    Vertex *v = this->getVertexByID(id);

    clearVertex();
    percorreVertices(v, true);

    std::cout << "\nArvore de caminhamento do vertice " << v->getID() << ": ";
    std::cout << std::endl;
    std::cout << "{ " << arvoreC << "}\n\n";

    std::cout << "Arestas de retorno: \n{\n"
              << arestasR << "}\n\n";
}