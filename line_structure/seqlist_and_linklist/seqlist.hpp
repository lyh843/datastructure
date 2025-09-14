#include<iostream>

const int defaultSize = 100;
template <typename T>
class SeqList{
protected:
    T* data;
    int maxSize;
    int n;
    void reSize(int newSize);
public:
    SeqList(int sz = defaultSize){
        if(sz > 0){
            data = new T[sz];
            if (data == nullptr){
                std::cerr <<"存储分配错误！"<< std::endl;
                exit(1);
            }
            maxSize = sz;
            n = 0;
        }
    };  //构造函数
    SeqList(SeqList<T>& x){
        maxSize = x.maxSize;
        n = x.n;
        data = new T[maxSize];
        for(int i = 0; i < n; i++){
            data[i] = x.data[i];
        }
        return;
    };    //复制构造函数
    ~SeqList(){
        maxSize = 0;
        delete []data;
        n = 0;
    };//析构函数
    bool AddSize(){
        maxSize *= 2;
        T* newdata = new T[maxSize];
        for(int i = 0; i < n; i++){
            newdata[i] =data[i];
        }
        delete []data;
        data = newdata;
        return true;
    }; //扩容函数
    int Size()const{
        return this->maxSize;
    };//求表最大容量
    int Length()const{
        return this->n;
    };//计算表长度
    int Search(T x)const{
        for(int i = 0; i < n; i++){
            if(data[i] == x){
                return i;
            }
        }
        return -1;
    };//搜索x在表中位置，函数返回表项序号
    T Locate(int i)const{
        if(i < 0 || i >= n){
            std::cerr << "数组越界！" << std::endl;
            exit(1);
        }
        return data[i];
    };//定位第i个表项，函数返回表项序号
    bool Insert(int i, T x){
        if(i < 0 || i > n){
            std::cerr <<"访问越界！" << std::endl;
            exit(1);
            return false;
        }
        if(n + 1 > maxSize){ // 需要扩容
            this->AddSize();
        }
        for(int j = n; j > i; j--){
            data[j] = data[j - 1];
        }
        data[i] = x;
        n++;
        return true;
    };//插入
    bool Remove(int i){
        if(i < 0 || i >= n) return false;
        for(int j = i; j < n - 1; j++){
            data[j] = data[j + 1];
        }
        n--;
    return true;
    };//删除
    void print()const{
        std::cout << "===============\n"; 
        std::cout << "size = " << this->maxSize << std::endl;
        std::cout << "len = " << this->n << std::endl;
        for(int i = 0; i < n; i++){
            std::cout << this->data[i] << " ";
        }
        std::cout << "\n";
    }; //输出
};

