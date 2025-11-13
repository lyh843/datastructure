const int maxWeight = 100;
const int DefaultVertices = 30;

template<class T, class E>
class Graph{
public:
    // 建立一个空的图
    Graph(int sz = DefaultVertices);
    // 析构函数
    ~Graph(){
        numVertices = 0;
        numEdges = 0;
    }
    // 判图空否
    bool graphEmpty() const{
        return numEdges == 0;
    }
    // 返回当前顶点数
    int numberOfVertices() const{
        return numVertices;
    }
    // 返回当前边数
    int numberOfEdges() const{
        return numEdges;
    }
    // 取顶点i的值
    virtual T getValue(int i);
    // 取边上的权值
    virtual E getWeight(int v1, int v2);
    // 给出顶点v第一个邻接顶点的位置
    virtual int getFirstNeighbor(int v) const;
    // 给出顶点v相对于w的下一个邻接顶点位置
    virtual int getNextNeighbor(int v, int w) const;
    // 插入一个顶点 vertex
    virtual void insertVertex(const T& vertex);
    // 在图中插入一条边
    virtual void insertEdge(int v1, int v2, int weight);
    // 在图中删除顶点v和所有关联到它的边
    virtual void removeVertex(int v);
    // 在图中删除边(v1,v2)
    virtual void removeEdge(int v1, int v2);
protected:
    int maxVertices;    // 最大顶点数
    int numVertices;    // 当前顶点数
    int numEdges;       // 当前边数
    int getVertexPos(const T& vertex);  // 获取顶点vertex的位置
};
