#include <iostream>
#define DefaultSize 20

template <class T, class E>
class MinPQ{
public:
    virtual bool insert(E& d) = 0;
    virtual bool remove(E& d) = 0;
};

template<class T, class E>
class MinHeap:public MinPQ<T, E>{
private:
    E *heap;    // 最小堆元素存储数组
    int currentSize;    // 最小堆当前元素个数
    int maxHeapSize;    // 最小堆最大容量
    void siftDown(int start, int m){    // 调整算法
        int i = start, j = 2 * i + 1;   // j 是 i 的左子女位置
        E temp = heap[i];
        while(j <= m){
            if(j < m && heap[j] > heap[j + 1]) j++; // 让 j 指向两子女中的小者
            if(temp <= heap[j]) break;  // 小则退出
            else{
                heap[i] = heap[j];
                i = j;
                j = 2 * j + 1;
            } 
        }
        heap[i] = temp;
    }    
    void siftUp(int start){     // 调整算法
        int j = start, i = (j - 1) / 2;
        E temp = heap[j];
        while(j > 0){
            if(heap[i] <= temp) break;
            else{
                heap[j] = heap[i];
                j = i;
                i = (i - 1) / 2;
            }
        }
        heap[j] = temp;
    }
public:
    MinHeap(int sz = DefaultSize){  // 构造函数
        maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
        heap = new E[maxHeapSize];
        currentSize = 0;
    }
    MinHeap(E arr[], int n){
        maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
        heap = new E[maxHeapSize];
        for(int i = 0; i < n; i++) heap[i] = arr[i];
        currentSize = n;
        int currentPos = (currentSize - 2) / 2;     // 最后的分支结点
        while(currentPos >= 0){
            siftDown(currentPos, currentSize - 1);
            currentPos--;
        }
    }
    ~MinHeap(){delete []heap;}  // 析构函数
    bool insert(E& d){  // 插入
        if(currentSize == maxHeapSize){
            std::cerr << "Heap Full" << std::endl;
            return false;
        }
        heap[currentSize] = d;
        siftUp(currentSize);
        currentSize++;
        return true;
    }
    bool remove(E& x){  // 删除
        x = heap[0];
        heap[0] = heap[currentSize - 1];
        currentSize--;
        siftDown(0, currentSize - 1);   // 自上向下调整堆
        return true;
    }
    bool isEmpty()const{
        return currentSize == 0;
    }
    bool isFull()const{
        return currentSize == maxHeapSize;
    }
    void makeEmpty(){
        currentSize = 0;
    }
};