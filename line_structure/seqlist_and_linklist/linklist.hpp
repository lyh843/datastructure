template<class T>
class List;

template<class T>
class ListNode{
friend List<T>;
private:
    T data;
    ListNode<T>* link;
public:
    ListNode(){
        link = nullptr;
    };
    ListNode(const T& item, ListNode<T> *ptr = nullptr){
        data = item;
        link = ptr;
    }
    ListNode<T>* operator++(){return this->link;};
};

template <class T>
class List{
private:
    ListNode<T>* fake_head;
    int len;
public:
    List(){
        fake_head = new ListNode<T>();
        len = 0;
    };
    List(const T& x){
        fake_head = new ListNode<T>();
        ListNode<T>* newnode = new ListNode<T>(x);
        fake_head->link = newnode;
        len = 1;
    }
    ~List(){
        makeEmpty();
    }
    void makeEmpty(){
        ListNode<T>* curr = fake_head->link;
        ListNode<T>* next = curr->link;
        while(curr != nullptr){
            delete curr;
            curr = next;
            next = next->link;
        }
        fake_head->link = nullptr;
        len = 0;
    }
    int length()const{
        return len;
    }
    bool insert(int loc, T data){ //追加至后面
        ListNode<T>* curr = locate(loc);
        if(curr == nullptr) return false;
        ListNode<T>* newnode = new ListNode<T>(data);
        newnode->link = curr->link;
        curr->link = newnode;
        len++;
        return true;
    }
    bool remove(int loc){
        ListNode<T>* curr = locate(loc - 1);
        if(curr == nullptr || curr->link == nullptr){
            return false;
        }
        ListNode<T>* denode = curr->link;
        curr->link = curr->link->link;
        delete denode;
        len--;
        return true;
    }
    ListNode<T>* search(T data){
        ListNode<T>* curr = fake_head;
        while(curr != nullptr){
            if(curr->data == data){
                break;
            }
            curr = curr->link;
        }
        return curr;
    }
    ListNode<T>* locate(int x){
        ListNode<T>* curr = fake_head;
        for(int i = 0; i < x; i++){
            if(curr->link == nullptr) break;
            curr = curr->link;
        }
        return curr;
    }
    T& getData(int i){
        ListNode<T>* curr = locate(i);
        return curr->data;
    }
    void setData(int i, T &x){
        ListNode<T>* curr = locate(i);
        curr->data = x;
    }
    bool isEmpty(){
        return len == 0;
    }
    ListNode<T>* gethead()const{
        return fake_head->link;
    }
    ListNode<T>* merge(ListNode<T>* l1, ListNode<T>* l2){
        ListNode<T> dummy;
        ListNode<T>* tail = &dummy;
        while(l1 && l2){
            if(l1->data <= l2->data){
                tail->link = l1;
                l1 = l1->link;
            }else{
                tail->link = l2;
                l2 = l2->link;
            }
            tail = tail->link;
        }
        tail->link = (l1 ? l1 : l2);
        return dummy.link;
    }
    ListNode<T>* mergesort(ListNode<T>* head){
        if(!head || !head->link) return head;
        ListNode<T>* slow = head;
        ListNode<T>* fast = head->link;
        while(fast && fast->link){
            slow = slow->link;
            fast = fast->link->link;
        }
        ListNode<T>* mid = slow->link;
        slow->link = nullptr;
        ListNode<T>* left = mergesort(head);
        ListNode<T>* right = mergesort(mid);
        return merge(left, right);
    }
    void sort();
};