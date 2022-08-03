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

    for (; i != NULL; i = i->getNext())
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

    for (; i != NULL; i = i->getNext())
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

float Graph::agrupamentoLocal(int id, bool print){
    //int id=0;
    int grau=0;
    float coeficiente;
    if(print){
    std::cout << "\n";
    std::cout << "Digite o ID do vertice: ";
    std::cin >> id;
    std::cout << std::endl;
    }
    if(getVertexByID(id)==NULL){
        std::cout<<"Id nao existe!"<< std::endl;
        return agrupamentoLocal(id,true);
    }
    Vertex *vertex=nullptr;

    vertex=getVertexByID(id);
    Vertex *v=nullptr;
    int size=0;
    Edge *e=nullptr;
    std::vector<int> adjacent;
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
    int arestasCompleto = (grau*(grau-1))/2;

    if(!getIsDirectioned()){pairs=pairs/2;}
    if(getIsDirectioned()){arestasCompleto=arestasCompleto*2;}
    coeficiente=pairs/arestasCompleto;
//    std::cout<<"pares:"<<pairs<<std::endl;
    if(pairs==0){coeficiente=0;}
    if(print){
    std::cout << "O coeficiente de agrupamento local : "<<coeficiente<<std::endl;}
    return coeficiente;

    


}

void Graph::agrupamentoGlobal(){

    float coefGlobal;
    float somaLocal;
    Vertex *v=nullptr;

    for(v=getFirst();v!=nullptr;v=v->getNext()){
        somaLocal+=agrupamentoLocal(v->getID(),false);  
    }    

    coefGlobal =  somaLocal/nVertex;
    std::cout << "O coeficiente de agrupamento medio do grafo : "<<coefGlobal<<std::endl;
    




}

void Graph::Djkstra(){

    int INF=2147483647;

    int ida,idb;
    int id;
    int menor=0;
    int peso;
    Vertex *v;
    Edge *e;

    std::cout<<"Digite o ID inicial:"<<std::endl;
    std::cin>>ida;
    
    std::cout<<"Digite o ID final:"<<std::endl;
    std::cin>>idb;

    ida=ida-1;
    idb=idb-1;

    std::vector<int> inside;
    std::vector<int> outside;
    std::vector<int> distancia;
    std::stack<int> antecessores;

    inside.reserve(nVertex);
    outside.reserve(nVertex);
    distancia.reserve(nVertex);

    if(!getEdgeIsWeighted()){peso=1;}

    antecessores.push(ida);
    //std::cout<<"nVertex: "<<nVertex;  
    
    for(int i=0;i<nVertex;i++){
        inside[i]=INF;
        outside[i]=i;
        distancia[i]=INF;
    }
    inside[ida]=ida;
    outside[ida]=INF;
    distancia[ida]=0;

     /*std::cout<<std::endl<<"Distancias:[";
        for(int j=0;j<nVertex;j++){
            std::cout<<distancia[j]<<", ";
        }
        std::cout<<"]"<<std::endl;*/



    //std::cout<<std::endl<<"escolhidos: ";

    for(int i=0;i<nVertex;i++){
        //std::cout<<std::endl<<"Antecessores:"<<std::endl;
        //for(j=0;j<antecessores.size();j++){
            //std::cout<<antecessores.top();
        //}

        id=antecessores.top();

        //std::cout<<"id:"<<id<<std::endl;

        v=getVertexByID(id+1);
        for(e=v->getEdge();e!=NULL;e=e->getNext()){

            //std::cout<<e->getID()<<" ";
            peso=1;
            if(getEdgeIsWeighted()){peso=e->getWeight();}
            if(distancia[id]+peso < distancia[e->getID()-1]){
                //std::cout<<std::endl<<distancia[id]+peso<<"<"<<distancia[e->getID()-1]<<std::endl;
                distancia[e->getID()-1]=distancia[id]+peso;
        }
        }
        menor=INF;
        for(int j=1; j<=nVertex;j++){
            if(outside[j-1]!=INF&&distancia[j-1]<menor){
                menor=j;
            }
        }
        inside[menor-1]=menor-1;
        outside[menor-1]=INF;
        antecessores.push(menor-1);
        //std::cout<< "menor: "<< menor;

        /*std::cout<<std::endl<<"Distancias:[";
        for(int j=0;j<nVertex;j++){
            std::cout<<distancia[j];
        }
        std::cout<<"]"<<std::endl;*/
            if(menor==idb){
                break;
            }
        
    }
    
    std::cout<<"antecessores "<<std::endl;
    for(int i=0;i<nVertex;i++){
        std::cout<<antecessores.top()+1<<" ";
        antecessores.pop();
    }


    return;

    
}