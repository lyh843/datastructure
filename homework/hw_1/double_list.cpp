#include <iostream>
using namespace std;
class Double_List{
private:
    class List_Node{
    public:
        int data;
        int insert_num;
        List_Node* next;
        List_Node* prev;
        List_Node(int _data = 0, int _insert_num = 0, List_Node* _next = nullptr, List_Node* _prev = nullptr)
            :data(_data), insert_num(_insert_num), next(_next), prev(_prev){}
        
    };
    List_Node* head;
    List_Node* tail;
    int count;
public:
    Double_List(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    };
    void left_insert(int _insert_data){
        if(head == nullptr){
            head = new List_Node(_insert_data, count++);
            tail = head;
            return;
        }
        List_Node* new_node = new List_Node(_insert_data, count++, head);
        head = new_node;
    };
    void right_insert(int _insert_data){
        if(head == nullptr){
            head = new List_Node(_insert_data, count++);
            tail = head;
            return;
        }
        List_Node* new_node = new List_Node(_insert_data, count++, nullptr, tail);
        tail = new_node;
    }
    void k_left_insert(int _insert_num, int _insert_data){
        List_Node* target = search(_insert_num);
        List_Node* prev = target->prev;
        List_Node* newnode = new List_Node(_insert_data, count++, target, prev);
        if(prev) prev->next = newnode;
        else head = newnode;
        target->prev = newnode;
    }
    void k_right_insert(int _insert_num, int _insert_data){
        List_Node* target = search(_insert_num);
        List_Node* next = target->next;
        List_Node* newnode = new List_Node(_insert_data, count++, next, target);
        if(next) next->prev = newnode;
        else tail = newnode;
        target->next = newnode;
    }
    void delete_k(int _insert_num){
        List_Node* target = search(_insert_num);
        List_Node* prev = target->prev;
        List_Node* next = target->next;
        if(target == head){
            head = head->next;
            head->prev = nullptr;
            delete target;
            if(head == nullptr) tail = nullptr;
        }
        else if(target == tail){
            tail = tail->prev;
            tail->next = nullptr;
            delete target;
            if(tail == nullptr) tail = nullptr;
        }
        else{
            prev->next = next;
            next->prev = prev;
            delete target;
        }
        return;
    };
    List_Node* search(int insert_num){
        List_Node* curr = head;
        while(curr != head){
            if(curr->insert_num == insert_num){
                return curr;
            }
            curr = curr->next;
        }
        cout << "not find\n";
        return nullptr;
    };
    void print(){
        List_Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout <<"\n";
    }
};

int main(){
    int times = 0;
    cin >> times;
    Double_List dl;
    while(times--){
        string order;
        cin >> order;
        if(order == "L"){
            int insert_data;
            cin >> insert_data;
            dl.left_insert(insert_data);
        }
        else if(order == "R"){
            int insert_data;
            cin >> insert_data;
            dl.right_insert(insert_data);
        }
        else if(order == "D"){
            int delete_num;
            cin >> delete_num;
            dl.delete_k(delete_num);
        }
        else if(order == "IL"){
            int insert_num;
            int insert_data;
            cin >> insert_num >> insert_data;
            dl.k_left_insert(insert_num, insert_data);
        }
        else if(order == "IR"){
            int insert_num;
            int insert_data;
            cin >> insert_num >> insert_data;
            dl.k_right_insert(insert_num, insert_data);
        }
        else{
            cout << "wrong insert!\n";
        }
    }
}