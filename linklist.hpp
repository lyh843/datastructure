template<class T>
class List;

template<class T>
class ListNode{
friend List<T>;
private:
    T data;
    ListNode<T>* link;
public:
    ListNode();
    ListNode<T>* operator++(){return this->link;};
};

template <class T>
class List{
private:
    ListNode<T>* fake_head;
    int len;
public:
    List();
    bool insert(int loc, T data);    //插入（表头、中间、结尾）
    bool remove(int loc);
    int search(T data);
    void sort();
};




template <class T>
List<T>::List(){
    fake_head = new ListNode<T>();
    len = 0;
}

template <class T>
bool List<T>::insert(int loc, T data){
    if(loc > len + 1) return false; //loc 为从1开始计数
    ListNode<T>* newnode = new ListNode<T>();
    newnode->data = data;
    ListNode<T>* curr = fake_head;
    for(int i = 0; i < loc; i++){
        
    }
};

template <class T>
ListNode<T>::ListNode(){
    link = nullptr;
}