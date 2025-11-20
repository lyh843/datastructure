const int DefaultSize = 100;
class UFSets{
private:
    int *_parent;
    int _size;
public:
    // 构造函数  
	UFSets(int size = DefaultSize){
        _size = size;
        _parent = new int[_size];
        for(int i = 0; i < _size; i++)
            _parent[i] = -1;
    }
    // 析构函数
    ~UFSets(){
        delete [] _parent;
    }
    // 集合赋值
    UFSets& operator=(const UFSets& R){
        if(this != &R){
            delete [] _parent;
            _size = R._size;
            _parent = new int[_size];
            for(int i = 0; i < _size; i++)
                _parent[i] = R._parent[i];
        }
        return *this;
    }
    // 子集合并
    void Union(int root1, int root2){
        _parent[root1] += _parent[root2];
        _parent[root2] = root1;
    }
    // 查询元素所在集合的根
    int Find(int x){
        if(_parent[x] < 0) return x;
        else return Find(_parent[x]);
    }
    // 压缩高度的合并算法
    // void UnionByHeight(int root1, int root2);
    // 按元素个数进行合并
    void UnionByWeight(int root1, int root2){
        int temp = _parent[root1] + _parent[root2];
        if(_parent[root1] < _parent[root2]){
            _parent[root2] = root1;
            _parent[root1] = temp;
        }
        else{
            _parent[root1] = root2;
            _parent[root2] = temp;
        }
    }
};