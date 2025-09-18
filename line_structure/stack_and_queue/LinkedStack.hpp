
#include <cstddef>
#include <ostream>
template <typename T>
class StackNode{
private:
    T data;
    StackNode<T>* next;
public:
    StackNode(T data = NULL, StackNode<T>* next = nullptr):data(data), next(next){}
};

static int k = 1;

template<typename T>
class linkedstack :public StackNode<T>{
private:
    StackNode<T>* top;
    static void output(std::ostream& os, StackNode<T> *ptr, int& i){
        if(ptr != NULL){
            if(ptr->next != NULL){
                output(os, ptr->next, i++);
            }
            os << i << ":" << ptr->data << std::endl;
        }
    }
public:
    linkedstack():top(nullptr){}
    ~linkedstack(){
        makeEmpty();
    }
    void push(T x){
        top = new StackNode<T>(x, top);
    }
    bool pop(T& x){
        if(isEmpty()) return false;
        x = top->data;
        StackNode<T>* denode = top;
        top = top->next;
        delete denode;
        return true;
    }
    bool getTop(T& x)const{
        if(isEmpty()) return false;
        x = top->data;
        return true;
    }
    bool isEmpty()const{
        return top == nullptr;
    }
    void makeEmpty(){
        StackNode<T>* denode;
        while(!isEmpty()){
            denode = top;
            top = top->next;
            delete denode;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, linkedstack<T>& s){
        output(os, s.top, k);
    }
};