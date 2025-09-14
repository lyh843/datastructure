#include "seqlist.hpp"
#include <cstdio>
#include <iostream>
#include<stdlib.h>

template<typename T>
SeqList<T>::SeqList(int sz){
    if(sz > 0){
        data = new T[sz];
        if (data == nullptr){
            std::cerr <<"存储分配错误！"<< std::endl;
            exit(1);
        }
        maxSize = sz;
        n = 0;
    }
};

template<typename T>
SeqList<T>::SeqList(SeqList<T>& x){
    maxSize = x.maxSize;
    n = x.n;
    data = new T[maxSize];
    for(int i = 0; i < n; i++){
        data[i] = x.data[i];
    }
    return;
}

template<typename T>
SeqList<T>::~SeqList<T>(){
    maxSize = 0;
    delete []data;
    n = 0;
}

template<typename T>
bool SeqList<T>::AddSize(){
    maxSize *= 2;
    T* newdata = new T[maxSize];
    for(int i = 0; i < n; i++){
        newdata[i] =data[i];
    }
    delete []data;
    data = newdata;
    return true;
}

template<typename T>
bool SeqList<T>::Insert(int i, T x){
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
}

template<typename T>
int SeqList<T>::Length()const{
    return this->n;
}

template<typename T>
int SeqList<T>::Size()const{
    return this->maxSize;
}

template<typename T>
int SeqList<T>::Search(T x)const{
    for(int i = 0; i < n; i++){
        if(data[i] == x){
            return i;
        }
    }
    return -1;
}

template<typename T>
T SeqList<T>::Locate(int i)const{
    if(i < 0 || i >= n){
        std::cerr << "数组越界！" << std::endl;
        exit(1);
    }
    return data[i];
}

template<typename T>
bool SeqList<T>::Remove(int i){
    if(i < 0 || i >= n) return false;
    for(int j = i; j < n - 1; j++){
        data[j] = data[j + 1];
    }
    n--;
    return true;
}

template<typename T>
void SeqList<T>::print()const{
    std::cout << "===============\n"; 
    std::cout << "size = " << this->maxSize << std::endl;
    std::cout << "len = " << this->n << std::endl;
    for(int i = 0; i < n; i++){
        std::cout << this->data[i] << " ";
    }
    std::cout << "\n";
}