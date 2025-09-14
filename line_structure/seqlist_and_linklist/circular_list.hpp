template <typename T>
class List_node{
private:
    T data;
    List_node<T>* next;
public:
    List_node<T>(T input_data = T(), List_node<T>* input_next = nullptr){
        data = input_data;
        next = input_next;
    }
    ~List_node<T>(){
        data = T();
        next = nullptr;
    }
    T getdata()const{return data;}
    List_node<T>* getnext()const{return next;}
    bool editdata(T new_data = T()){
        data = new_data;
        return true;
    }
    bool editnext(List_node<T>* next_node = nullptr){
        if(next_node == nullptr)return false;
        next = next_node;
        return true;
    }
};

template<typename T>
class Circular_list{
private:
    List_node<T>* head;
    int num;
public:
    Circular_list<T>(){
        head = new List_node<T>;
        head->editnext(head);
        num = 0;
    }
    ~Circular_list<T>(){
        List_node<T>* curr = head->getnext();
        while(curr != head){
            List_node<T>* denode = curr;
            curr = curr->getnext();
            delete denode;
        }
        head->editnext(head);
    }
    //复制构造函数
    Circular_list<T>(const Circular_list<T>& x){
        head = new List_node<T>;
        num = x.num;
        List_node<T>* curr = x.head->getnext();
        List_node<T>* prev = head;
        while(curr != x.head){
            List_node<T>* newnode = new List_node<T>(curr->getdata());
            prev->editnext(newnode);
            prev = prev->getnext();
            curr = curr->getnext();
        }
        prev->editnext(head);
    }
    //将链表定义为空表
    bool clear(){
       List_node<T>* curr = head->getnext();
       while(curr != head){
            curr->editdata();
            curr = curr->getnext();
       }
       return true;
    }
    //计算链表的长度
    int getlength()const{return num;}
    //搜索含x的元素
    List_node<T>* search(T& x){
        List_node<T>* curr = head->getnext();
        while(curr != head){
            if(curr->getdata() == x){
                return curr;
            }
            curr = curr->getnext();
        }
        return nullptr;
    }
    //定位第i个元素
    List_node<T>* located(int ip){
        if (ip > num) return nullptr;
        List_node<T>* curr = head;
        for(int i = 0; i < ip; i++){
            curr = curr->getnext();
        }
        return curr;

    }
    //取出第i个元素
    T getdata(int ip){
        if(ip > num) return T();
        List_node<T>* curr = head->getnext();
        for(int i = 1; i < ip; i++){
            curr = curr->getnext();
        }
        return curr->getdata();
    }
    //更新第i个元素
    bool update(T new_data, int ip){
        if(ip > num) return false;
        List_node<T>* curr = head->getnext();
        for(int i = 1; i < ip; i++){
            curr = curr->getnext();
        }
        curr->editdata(new_data);
        return true;
    }
    //在第i元素后插入
    bool insert(T newdata, int ip){
        if(ip > num)return false;
        List_node<T>* curr = located(ip);
        List_node<T>* newnode = new List_node<T>(newdata, curr->getnext());
        curr->editnext(newnode);
        num++;
        return true;
    }
    //删除第i个元素
    bool remove(int ip){
        if(ip > num) return false;
        List_node<T>* prev = located(ip - 1);
        List_node<T>* denode = prev->getnext();
        prev->editnext(denode->getnext());
        delete denode;
        num--;
        return true;
    }
    //判断表空否
    bool isEmpty()const{return num == 0;}
};