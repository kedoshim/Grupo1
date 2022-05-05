Grafo::Grafo(int nvert,int vPonderados,int aPonderadas)
{
    Vertice* first,vert1,vert2;
    int id;
    vert1=new Vertice(1);
    first=vert1;
    for(id=2;id<=nvert;id++){
        vert2=new Vertice(id);
        vert1.setProximo(vert2);
        vert2.setAnterior(vert1);
        vert1=vert2;
    }
}
