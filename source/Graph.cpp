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

void Graph::readArchives(char **argv)
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

void Graph::connectVertex(Vertex *a, Vertex *b)
{
    a->setNextEdge(b->getID());
    if (!isDirectioned)
        b->setNextEdge(a->getID());
}

void Graph::connectVertex(Vertex *a, Vertex *b, int weight)
{
    a->setNextEdge(b->getID(), weight);
    if (!isDirectioned)
        b->setNextEdge(a->getID(), weight);
}

void Graph::setVertex(int nVertex)
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

Vertex *Graph::getVertexByID(int id)
{
    for (Vertex *v = first; v != NULL; v = v->getNext())
    {
        if (v->getID() == id)
            return v;
    }

    return NULL;
}

void Graph::percorreVertices(Vertex *v)
{
    v->setVisited();

    for (Edge *e = v->getEdge(); e != NULL; e = e->getNext())
    {
        if (this->getVertexByID(e->getID())->getVisited() == false)
            percorreVertices(getVertexByID(e->getID()));
    }
}

void Graph::fechoTransitivoDireto()
{
    int id;
    std::string s = "";

    std::cout << "\n";
    std::cout << "Digite o ID do vertice: ";
    std::cin >> id;
    std::cout << std::endl;

    Vertex *i = this->getVertexByID(id);

    percorreVertices(i);

    std::cout << "Fecho transitivo direto do vertice " << i->getID() << ": ";

    std::cout << std::endl;

    std::cout << "{ ";

    for (i; i != NULL; i = i->getNext())
    {
        if (i->getVisited())
        {
            s += std::to_string(i->getID()) + ", ";
            /* std::cout << i->getID() << ": " << std::endl;

            for (Edge *e = i->getEdge(); e != NULL; e = e->getNext())
                std::cout << i->getID() << " -> " << e->getID() << std::endl;

            std::cout << "\n\n"; */
        }
    }

    s.pop_back();
    s.pop_back();

    s += " }\n";

    std::cout << s;
}