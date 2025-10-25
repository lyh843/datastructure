// 稀疏矩阵的实现
#include <iostream>
#include <vector>
using namespace std;

struct Triple{  // 三元组
    int row, col;
    int value;
    void operator=(const Triple& R){  // 修改为 const 引用
        row = R.row;
        col = R.col;
        value = R.value;
    }
    Triple(){}
     Triple(int r, int c, int v) : row(r), col(c), value(v) {}  // 三参数构造
};

class SparseMatirx{
public:
    SparseMatirx(int _rows = 0, int _cols = 0, int _size = 0){
        rows = _rows;
        cols = _cols;
        size = _size;
        smArray = new Triple[size];
    }
    ~SparseMatirx(){
        delete [] smArray;
    }
    void set_size(int _size){
        delete [] smArray;   // 释放旧内存
        size = _size;
        smArray = new Triple[size];
    }

    // 设置矩阵元素
    void set(int r, int c, int value){
        for(int i = 0; i < size; i++){
            if(smArray[i].row == r && smArray[i].col == c){
                smArray[i].value = value;  // 已有元素覆盖
                return;
            }
        }
        for(int i = 0; i < size; i++){
            if(smArray[i].value == 0){  // 空位置插入
                smArray[i].row = r;
                smArray[i].col = c;
                smArray[i].value = value;
                return;
            }
        }
        cout << "No space to insert new element!" << endl;
    }

    SparseMatirx transpose() const{    // 转置
        SparseMatirx new_matirx(cols, rows, size);
        if(size > 0){
            int num = 0;
            int i, k;
            for(k = 0; k < cols; k++){
                for(i = 0; i < size; i++){
                    if(smArray[i].col == k){
                        new_matirx.smArray[num].row = smArray[i].col;
                        new_matirx.smArray[num].col = smArray[i].row;
                        new_matirx.smArray[num].value = smArray[i].value;
                        num++;
                    }
                }
            }
        }
        return new_matirx; 
    }

    SparseMatirx fast_transpose() const{   //快速转置
        int* row_size = new int[cols];
        int *row_start = new int[cols];
        SparseMatirx new_matirx(cols, rows, size);
        if(size > 0){
            for(int i = 0; i < cols; i++) row_size[i] = 0;
            for(int i = 0; i < size; i++) row_size[smArray[i].col]++;
            row_start[0] = 0;
            for(int i = 1; i < cols; i++){
                row_start[i] = row_start[i - 1] + row_size[i - 1];
            }
            for(int i = 0; i < size; i++){
                int j = row_start[smArray[i].col];
                new_matirx.smArray[j].row = smArray[i].col;
                new_matirx.smArray[j].col = smArray[i].row;
                new_matirx.smArray[j].value = smArray[i].value;
                row_start[smArray[i].col]++;
            }
        }
        delete []row_size;
        delete []row_start;
        return new_matirx;
    }

    void add(SparseMatirx& a, SparseMatirx& b){    // 矩阵加法
        if(a.rows != b.rows || a.cols != b.cols){
            cout << "Matrix dimensions do not match!" << endl;
            return;
        }

        int maxSize = a.size + b.size;
        set_size(maxSize);
        int i = 0, j = 0, k = 0;

        while(i < a.size && j < b.size){
            int a_pos = a.smArray[i].row * a.cols + a.smArray[i].col;
            int b_pos = b.smArray[j].row * b.cols + b.smArray[j].col;

            if(a_pos < b_pos) smArray[k++] = a.smArray[i++];
            else if(a_pos > b_pos) smArray[k++] = b.smArray[j++];
            else { // 同位置元素相加
                int sum = a.smArray[i].value + b.smArray[j].value;
                if(sum != 0) smArray[k++] = Triple(a.smArray[i].row, a.smArray[i].col, sum);
                i++; j++;
            }
        }
        while(i < a.size) smArray[k++] = a.smArray[i++];
        while(j < b.size) smArray[k++] = b.smArray[j++];

        size = k;
        rows = a.rows;
        cols = a.cols;
    }

    void multiply(SparseMatirx& a, SparseMatirx& b){    // 矩阵乘法
        if(a.cols != b.rows){
            cout << "Matrix dimensions do not allow multiplication!" << endl;
            return;
        }

        std::vector<Triple> temp;
        for(int i = 0; i < a.size; i++){
            for(int j = 0; j < b.size; j++){
                if(a.smArray[i].col == b.smArray[j].row){
                    int r = a.smArray[i].row;
                    int c = b.smArray[j].col;
                    int val = a.smArray[i].value * b.smArray[j].value;

                    bool found = false;
                    for(auto &t : temp){
                        if(t.row == r && t.col == c){
                            t.value += val;
                            found = true;
                            break;
                        }
                    }
                    if(!found) temp.push_back(Triple(r, c, val));
                }
            }
        }

        set_size(temp.size());
        for(size_t i = 0; i < temp.size(); i++)
            smArray[i] = temp[i];
        rows = a.rows;
        cols = b.cols;
        size = temp.size();
    }

        // 在 SparseMatirx 类里增加
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int val = 0;
                for (int k = 0; k < size; k++) {
                    if (smArray[k].row == i && smArray[k].col == j) {
                        val = smArray[k].value;
                        break;
                    }
                }
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }


private:
    int rows, cols, size;
    Triple* smArray;
};
