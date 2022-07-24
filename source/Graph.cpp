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

int Graph::getnVertex(){return nVertex;}

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

int Graph::getVertexPower(Vertex *a){
    Edge *e;
    int i;
    for(e=a->getEdge();e!=nullptr;e=e->getNext())i++;

    return i;
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

void Graph::agrupamentoLocal(){
    int id;
    int grau;
    float coeficiente;

    std::cout << "\n";
    std::cout << "Digite o ID do vertice: ";
    std::cin >> id;
    std::cout << std::endl;

    Vertex *vertex=nullptr;

    vertex=getVertexByID(id);
    Vertex *v=nullptr;
    int size;
    Edge *e=nullptr;
    std::vector<int> adjacent(20);
    float pairs=0;
    for(e=vertex->getEdge();e!=nullptr;e=e->getNext()){
        grau++;
        adjacent.push_back(e->getID());
    }
    for(int i=0;i<static_cast<int>(adjacent.size());i++){
        v=getVertexByID(adjacent[i]);
        for(e=v->getEdge();e!=nullptr;e=e->getNext()){
            size=adjacent.size();
            for(int j=0;j<size;j++){
                if(e->getID()==adjacent[j])
                    pairs++;
            }
        }   
    }
    coeficiente=grau/pairs;

    std::cout << "O coeficiente de agrupamento local é: "<<coeficiente<<std::endl;


    


}

void Graph::agrupamentoGlobal(){}

/*void Graph::Djkstra(){

    std::string IDa,IDb;
    int ida,idb
    Vertex *a,*b;
    int aux;
    std::string s = "";

    std::cout << "\n";
    std::cout << "Digite o ID do vertice inicial: ";
    std::cin >> IDa;
    std::cout << "Digite o ID do vertice final: ";
    std::cin >> IDb;
    std::cout << std::endl;
    ida= stoi(IDa);
    idb= stoi(IDb);

    clearVertex();

    a=getVertexByID(ida);
    b=getVertexByID(idb);
    
    if (a!= nullptr && b!= nullptr)
    { 
        Edge* edge=nullptr;
        Vertex* vertex=a;
        int *distance = new int[nVertex];
        bool *visited= new bool[nVertex];
        int *antec = new int [nVertex];

        for(int i=0;i<nVertex;i++){
            distance[i]=INFINITY;
            visited[i]= false;
        }
        distance[a]=0;
        visited[a]=true;

        int v,c,id,peso;

        id=ida;

        for(int i=0;i<nVertex-1;i++){

            if (visited[id] == false)
            {
                visited[id] = true; //Marca o vertice como visitado
                node = getVertexByID(id);
                if (node != nullptr) //Busca o no pela posição
                    edge = vertex->getEdge();
                else
                    edge = nullptr; //Pega a primeira aresta do no

                while (edge != nullptr)
                { //Passa por todas as arestas do vertice u

                    if (!getEdgeIsWeighted())
                        peso = 1; //Para caso não haja pesso a distância será 1 por salto
                    else
                        peso = edge->getWeight();

                    v = edge->getID(); //Pega a posição do no Target dessa aresta

                    if (distance[v] > (distance[id] + peso))
                    {                                           //Verifica se a distância é menor
                        antec[v] = id;                         //Atualiza o antecessor
                        distance[v] = (distance[id] + peso); //Atualiza a distância
                        fp.push(make_pair(distance[v], v)); //Adiciona o vertice na fila de prioridade
                    }
                    edge = edge->getNext(); //Avança para o a proxima aresta do vertice

        /*for(edge=vertex->getEdge();edge != null; edge=edge->getNext){
            distance[vertex]=edge->getWeight;
        }
        int menor=INFINITY;
        for(int i=0; i<nVertex;i++){
            if(visited[i]==false&&distance[i]>menor){
                menor=distance[i];
                aux=i;
    
        }
    }
        }

    }
}*/