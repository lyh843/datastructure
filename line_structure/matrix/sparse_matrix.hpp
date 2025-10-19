// 稀疏矩阵的实现
struct Triple{  // 三元组
    int row, col;
    int value;
    void operator=(Triple& R){
        row = R.row;
        col = R.col;
        value = R.value;
    }
};

class SparseMatirx{
public:
    SparseMatirx(int _rows = 0, int _cols = 0, int _size = 0){
        rows = _rows;
        cols = _cols;
        size = _size;
        smArray = new Triple[size];
    }
    void set_size(int _size){
        size = _size;
        smArray = new Triple[size];
    }
    void set(int _rol, int _col, int _value){
        
    }
    SparseMatirx transpose() const{    // 转置
        SparseMatirx new_matirx(cols, rows, size);
        if(size > 0){
            int num = 0;
            int i, k;
            for(k = 0; k < cols; k++){
                for(int i = 0; i < size; i++){
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
    void add (SparseMatirx& a, SparseMatirx& b);    // 矩阵加法
    void multiply(SparseMatirx& a, SparseMatirx& b);    // 矩阵乘法
private:
    int rows, cols, size;
    Triple* smArray;
};