#include <cstddef>
template<typename T>
class Stack{
private:
    int maxsize;
    int top;
    T* data;
    void overflowProcess(){
        T* newdata = new T[2 * maxsize];
        for(int i = 0; i < maxsize; i++){
            newdata[i] = data[i];
        }
        maxsize *= 2;
        delete []data;
        data = newdata;
    }
public:
    Stack(int input_Size = 10){
        maxsize = input_Size;
        data =  new T[maxsize];
        top = -1;
    }
    void push(const T& item){
        if(isFull()) overflowProcess();
        data[++top] = item;
    }
    T pop(){
        if(!isEmpty()){
            return data[top--];
        }
        return NULL;
    }
    T gettop()const{
        if(!isEmpty()){
            return data[top];
        }
        return NULL;
    }
    void clear(){
        top = -1;
    }
    bool isEmpty()const{
        return top == -1;
    }
    bool isFull()const{
        return top == maxsize - 1;
    }
};