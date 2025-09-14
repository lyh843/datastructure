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
    SeqList(int sz = defaultSize);  //构造函数
    SeqList(SeqList<T>& L);    //复制构造函数
    ~SeqList();//析构函数
    bool AddSize(); //扩容函数
    int Size()const;//求表最大容量
    int Length()const;//计算表长度
    int Search(T x)const;//搜索x在表中位置，函数返回表项序号
    T Locate(int i)const;//定位第i个表项，函数返回表项序号
    bool Insert(int i, T x);//插入
    bool Remove(int i);//删除
    void print()const; //输出
};

