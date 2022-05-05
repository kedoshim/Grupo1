Vertice::Vertice(int id,float p)
{
    ID=id;
    setPeso(p);
}
Vertice::Vertice(int id,float p, Vertice* anterior)
{
    ID=id;
    setPeso(p);
    setAnterior(anterior);

}
Vertice::setProximo(Vertice* p)
{
    vproximo=p;
}
Vertice::setAnterior(Vertice* a)
{
    vanterior=a;
    a.setProximo(this);//preciso do endereço do Vertice que estou trabalhando agora. n sei c ta certo
}
Vertice::setPeso(float p)
{
    peso=p;
}
