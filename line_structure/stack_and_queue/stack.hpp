template<typename T>
class Stack{
private:
    int maxsize;
public:
    Stack(int maxSize = 10);
    void push(const T& item);
    T pop();
    T gettop()const;
    void clear();
    bool isEmpty()const;
    bool isFull()const;

};