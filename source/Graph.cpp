#include <bits/stdc++.h>
#include "../headers/Graph.h"

Graph::Graph(char **argv)
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

Graph::~Graph()
{
}

void Graph::connectVertex(Vertex *a, Vertex *b)
{
    a->setNextEdge(b->getID());
    b->setNextEdge(a->getID());
}

void Graph::connectVertex(Vertex *a, Vertex *b, int weight)
{
    a->setNextEdge(b->getID(), weight);
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

void Graph::imprimeAdjacentes()
{
    for (Vertex *i = first; i != NULL; i = i->getNext())
    {
        std::cout << "Vertex " << i->getID() << ": ";

        for (Edge *j = i->getEdge(); j != NULL; j = j->getNext())
            std::cout << i->getID() << "<->" << j->getID() << ' ' << "(" << j->getWeight() << ") ";

        std::cout << std::endl;
    }
}