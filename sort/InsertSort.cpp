#include<iostream>

#define NUM 6

struct Node{
    int id;
    int key;
    Node(int id = 0, int key = 0):id(id), key(key){}
};

Node arr[NUM];

void set(){
    arr[0] = Node(0, 21);
    arr[1] = Node(0, 25);
    arr[2] = Node(0, 49);
    arr[3] = Node(1, 25);
    arr[4] = Node(0, 16);
    arr[5] = Node(0, 8);
}

void print(){
    std::cout << "============ Sort ==========\n";
    for(int i = 0; i < NUM; i++){
        std::cout << i << " id: " << arr[i].id << "\tkey: " << arr[i].key << "\n";
    }
}

void printStep(int step){
    std::cout << "============ Step "<< step <<" ===========\n";
    for(int i = 0; i < NUM; i++){
        std::cout << i << "id: " << arr[i].id << "\t key: " << arr[i].key << "\n";
    }
}

void InsertSort(int begin = 0, int end = NUM,  int gap = 1, bool stepPrint = false){
    int step = 0;
    for(int i = begin + gap; i < end; i++){
        int insertPos = i;
        Node temp = arr[i];
        int j = i - gap;
        while(j >= begin && arr[j].key > temp.key){
            arr[j + gap] = arr[j];
            j -= gap;
        }
        arr[j + gap] = temp;
        if(stepPrint){
            printStep(++step);
        }
    }
}

void midInsertSort(int begin = 0, int end = NUM, bool stepPrint = false){
    int step = 0;
    for(int i = begin + 1; i < end; i++){
        int left = begin, right = i - 1;
        int insertPos = i;
        Node temp = arr[i];

        while(left <= right){
            int mid = (left + right) / 2;
            if(arr[mid].key <= temp.key){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        insertPos = left;
        for(int j = i; j > insertPos; j--){
            arr[j] = arr[j - 1];
        }
        arr[insertPos] = temp;
        if(stepPrint) printStep(++step);
    }
}

void shellSort(int begin = 0, int end = NUM, int gap = 3, bool stepPrint = false){
    int step = 0;
    while(gap >= 1){
        InsertSort(begin, end, gap);
        if(stepPrint) printStep(++step);
        if(gap == 1) break;
        gap = (gap + 1) / 2;
    }
}

void bubbleSort(int begin = 0, int end = NUM, bool stepPrint = false){
    bool exchange = false;
    int step = 0;
    for(int i = begin; i < end - 1; i++){
        for(int j = begin; j < end - i - 1; j++){
            if(arr[j].key > arr[j + 1].key){
                exchange = true;
                Node temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if(stepPrint) printStep(++step);
    }
}

int main(){
    set();
    InsertSort();
    print();

    set();
    InsertSort(0, NUM, 1, true);

    set();
    midInsertSort();
    print();

    set();
    midInsertSort(0, NUM, true);

    set();
    shellSort();
    print();

    set();
    shellSort(0, NUM, 3, true);
    
    set();
    bubbleSort();
    print();
    
    set();
    bubbleSort(0, NUM, true);
}