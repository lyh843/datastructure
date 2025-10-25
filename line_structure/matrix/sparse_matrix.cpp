#include <iostream>
#include "sparse_matrix.hpp"  // 你的类头文件
using namespace std;

int main() {
    // 创建 3x3 稀疏矩阵 A
    SparseMatirx A(3, 3, 4);
    A.set(0, 0, 1);
    A.set(0, 2, 2);
    A.set(1, 1, 3);
    A.set(2, 0, 4);

    cout << "Matrix A:" << endl;
    A.print();

    // 创建 3x3 稀疏矩阵 B
    SparseMatirx B(3, 3, 3);
    B.set(0, 1, 5);
    B.set(1, 0, 6);
    B.set(2, 2, 7);

    cout << "\nMatrix B:" << endl;
    B.print();

    // 矩阵加法 C = A + B
    SparseMatirx C;
    C.add(A, B);
    cout << "\nMatrix C = A + B:" << endl;
    C.print();

    // 矩阵乘法 D = A * B
    SparseMatirx D;
    D.multiply(A, B);
    cout << "\nMatrix D = A * B:" << endl;
    D.print();

    // 测试快速转置
    SparseMatirx At = A.fast_transpose();
    cout << "\nMatrix At = transpose(A):" << endl;
    At.print();

    return 0;
}
