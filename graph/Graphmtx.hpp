#include "Graph.hpp"
#include <cstddef>
#include <istream>

template<class T, class E>
class Graphmtx: public Graph<T,E>{
    friend std::istream& operator>>(std::istream& in, Graphmtx<T, E>& G);
    friend std::ostream& operator<<(std::ostream& out, Graphmtx<T, E>& G); 
private:
    T *VerticesList;    // 顶点列表
    E **Edge;   // 邻接矩阵
    // 给出顶点vertex在图中的位置
    int getVertexPos(T vertex) const{
        for(int i = 0; i < this->numVertices; i++){
            if(VerticesList[i] == vertex)
                return i;
        }
        return -1;
    }
public:
    // 构造函数
    Graphmtx(int sz = DefaultVertices){
        this->maxVertices = sz;
        this->numVertices = 0;
        this->numEdges = 0;
        VerticesList = new T[this->maxVertices];
        Edge = (int**) new int *[this->maxVertices];
        for(int i = 0; i < this->maxVertices; i++){
            Edge[i] = new int[this->maxVertices];
        }
        for(int i = 0; i < this->maxVertices; i++){
            for(int j = 0; j < this->maxVertices; j++){
                Edge[i][j] = (i == j) ? 0 : maxWeight;
            }
        }
    }
    ~Graphmtx(){
        delete [] VerticesList;
        delete [] Edge;
    }
    // 取顶点i的值，i不合理返回0
    // 取顶点i的值
    T getValue(int i){
        if(i >= 0 && i < this->numVertices){
            return VerticesList[i];
        }
        return NULL;
    }
    // 取边上的权值
    E getWeight(int v1, int v2){
        if (v1 >= 0 && v1 < this->numVertices && v2 >= 0 && v2 < this->numVertices){
            return Edge[v1][v2];
        }
        return NULL;
    }
    // 给出顶点v第一个邻接顶点的位置
    int getFirstNeighbor(int v) const{

    }
    // 给出顶点v相对于w的下一个邻接顶点位置
    int getNextNeighbor(int v, int w) const;
    // 插入一个顶点 vertex
    void insertVertex(const T& vertex);
    // 在图中插入一条边
    void insertEdge(int v1, int v2, int weight);
    // 在图中删除顶点v和所有关联到它的边
    void removeVertex(int v);
    // 在图中删除边(v1,v2)
    void removeEdge(int v1, int v2);
};
