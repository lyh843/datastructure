struct Triple{
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
    SparseMatirx(int _rows = 0, int _cols = 0){
        rows = _rows;
        cols = _cols;
    }
    void set_size(int _size){
        size = _size;
        smArray = new Triple[size];
    }
    void set(int _rol, int _col, int _value){
        
    }
    void transpose(SparseMatirx& b);
    void add (SparseMatirx& a, SparseMatirx& b);
    void multiply(SparseMatirx& a, SparseMatirx& b);
private:
    int rows, cols, size;
    Triple* smArray;
};