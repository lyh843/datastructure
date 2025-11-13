#include "set.hpp"

const int DefaultSize = 50;
template <class T>
class bitSet:public Set<T>{
private:
    int setSize;
    int vectorSize;
    unsigned short *bitVector;
public:
    // 构造函数
    bitSet(int size = DefaultSize);
    // 复制构造函数
    bitSet(const bitSet<T>& R);
    // 析构函数
    ~bitSet(){
        delete []bitVector;
    }
    // 取集合元素x
    int getMenber(const T x);
    // 改集合元素x
    void putMenber(const T x, int v);
    // 置空集合
    void makeEmpty(){
        for(int i = 0; i < vectorSize; i++){
            bitVector[i] = 0;
        }
    }
    // 加入新成员x
    bool addMenber(const T x);
    // 删除老成员x
    bool delMenber(const T x);
    bitSet<T>& operator = (const bitSet<T>& R);
    bitSet<T> operator + (const bitSet<T>& R);
    bitSet<T> operator * (const bitSet<T>& R);
    bitSet<T> operator - (const bitSet<T>& R);
    // 判断x是否集合的成员
    bool Contains (const T x);
    // 判this是否R的子集
};