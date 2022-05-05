class Aresta
{
private:
    int idA;
    int idB;
    float peso=0;
    Aresta* nextA=nullptr;  //A ideia é que como cada aresta liga dois vertices, voce consiga dar procedimento à lista de aresta de ambos os grupos
    Aresta* nextB=nullptr;  //Por isso tem o endereço da proxima aresta de A e B

public:
    Aresta(int tail,int head);
    ~Aresta();
    setNextAB(int id,Aresta* e);
    getNextAB(int id);

};
