class Vertice
{
private:
    int ID;
    float peso=0;
    Vertice* vanterior=nullptr;
    Vertice* vproximo=nullptr;
    Aresta* aresta;
public:
    Vertice(int id, Vertice* anterior);
    ~Vertice();
    setAresta(Aresta* endereco);

};
