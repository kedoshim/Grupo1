class Aresta
{
private:
    int IDtail;
    int IDhead;
    float peso=0;
    Aresta* Next=nullptr;

public:
    Aresta(int tail,int head);
    ~Aresta();
    setNext(Aresta* e);
    getNext();

};
