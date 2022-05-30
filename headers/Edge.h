class Edge
{
private:
    int vertexID;
    Edge *nextEdge = nullptr;
    int weight;
public:
    Edge(int id);
    ~Edge();
    void setNextEdge(int edgeID);
};