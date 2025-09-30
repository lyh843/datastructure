#include <iostream>
using namespace std;

class bracket_list{
private:
    int pos;
    int size;
    int* data;
public:
    bracket_list(int _size, int _pos){
        size = _size;
        pos = _pos;
        data = new int[size];
    }
    void start_set(int pos, int _data){
        data[pos] = _data;
    }
    void left_pos(){
        while(pos - 1 >= 0 && data[pos - 1] == 0){
            pos--;
        }
        pos = pos - 1;
    }
    void right_pos(){
        while(pos + 1 < size && data[pos + 1] == 0){
            pos++;
        }
        pos = pos + 1;
    }
    void delelt(){
        int count = data[pos];
        if(count == 1){
            while(count != 0){
                data[pos] = 0;
                count += data[++pos];
            }
            data[pos] = 0;
            right_pos();
            if(pos == size){
                left_pos();
            }
        }
        else if(count == -1){
            while(count != 0){
                data[pos] = 0;
                count += data[--pos];
            }
            data[pos] = 0;
            right_pos();
            if(pos == size){
                left_pos();
            }
        }
        else{
            cout << "wrong pos!\n";
        }
    }
    void print(){
        for(int i = 0; i < size; i++){
            if(data[i] == 1) cout << "(";
            else if(data[i] == -1) cout <<")";
        }
        cout << "\n";
    }
};

int main(){
    int origin_size = 0, times = 0, pos= 0;
    cin >> origin_size >> times >> pos;
    bracket_list b_list(origin_size, pos - 1);
    for(int i = 0; i < origin_size; i++){
        char temp;
        cin >> temp;
        temp = (temp == '(') ? 1 : -1;
        b_list.start_set(i, temp);
    }
    for(int i = 0; i < times; i++){
        char optr;
        cin >> optr;
        if(optr== 'L'){
            b_list.left_pos();
        }
        else if(optr == 'R'){
            b_list.right_pos();
        }
        else if(optr == 'D'){
            b_list.delelt();
        }
        else{
            cout << "wrong oprt!\n";
        }
    }

    b_list.print();
    return 0;
}