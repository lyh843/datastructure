#include <istream>
#include <ostream>

#include "set.hpp"
#define DefaultSize 50

template <class T>
class bitSet : public Set<T> {
   public:
    // 构造函数
    bitSet(int sz = DefaultSize) {
        setSize = sz;
        vectorSize = sz / 16 + 1;
        bitVector = new unsigned short[vectorSize]();
    }
    // 复制构造函数
    bitSet(const bitSet<T> &R) {
        setSize = R.setSize;
        vectorSize = R.vectorSize;
        bitVector = new unsigned short[vectorSize];
        for (int i = 0; i < vectorSize; i++) {
            bitVector[i] = R.bitVector[i];
        }
    }
    ~bitSet() { delete[] bitVector; }
    // 取集合元素x，判断元素x是否在集合中，如果是返回1，否则返回0
    int getMember(const T x) const {
        if (x < 0 || x > setSize) return 0;
        int ad = x / 16;
        int id = x % 16;
        unsigned short elem = bitVector[ad];
        return ((elem >> id) % 2);
    }
    // 把值v送入集合元素x中
    void putMember(const T x, int v) {
        if (x < 0 || x > setSize) return;
        int ad = x / 16;
        int id = x % 16;
        if (v == 1) {
            bitVector[ad] |= (1 << id);
        } else {
            bitVector[ad] &= ~(1 << id);
        }
    }
    void makeEmpty() override {
        for (int i = 0; i < vectorSize; i++) {
            bitVector[i] = 0;
        }
    }
    // 加入新成员x
    bool addMember(const T x) override {
        if (x < 0 || x > setSize) return false;
        if (getMember(x) == 0) {
            putMember(x, 1);
        } else {
            return false;
        }
        return true;
    }
    // 删除老成员x
    bool delMember(const T x) override {
        if (x < 0 || x > setSize) return false;
        if (getMember(x) == 1) {
            putMember(x, 0);
        } else {
            return false;
        }
        return true;
    }
    bitSet<T> &operator=(const bitSet<T> &R) {
        if (*this == R) return *this;
        delete[] bitVector;
        bitVector = new unsigned short[R.vectorSize];
        for (int i = 0; i < R.vectorSize; i++) {
            bitVector[i] = R.bitVector[i];
        }
        vectorSize = R.vectorSize;
        setSize = R.setSize;
        return *this;
    }
    bitSet<T> unionWith(const bitSet<T> &R) const override {
        bitSet<T> result(setSize);
        for (int i = 0; i < vectorSize; i++) {
            result->bitVector[i] = bitVector[i] | R.bitVector[i];
        }
        return result;
    }
    bitSet<T> operator+(const bitSet<T> &R) const override { return unionWith(R); }
    bitSet<T> operator*(const bitSet<T> &R) const override {
        bitSet<T> result(setSize);
        for (int i = 0; i < vectorSize; i++) {
            result->bitVector[i] = bitVector[i] & R.bitVector[i];
        }
        return result;
    }
    bitSet<T> operator-(const bitSet<T> &R) const override {
        bitSet<T> result(setSize);
        for (int i = 0; i < vectorSize; i++) {
            result->bitVector[i] = bitVector[i] & ~R.bitVector[i];
        }
        return result;
    }
    bool Contains(const T x) const override { return getMember(x) == 1; }
    // 判断 this 是否R的子集
    bool subSet(const bitSet<T> &R) const override {
        for (int i = 0; i < vectorSize; i++) {
            if ((bitVector[i] & R.bitVector[i]) != bitVector[i]) {
                return false;
            }
        }
        return true;
    }
    // 判断集合 this 与 R 相等
    bool operator==(const bitSet<T> &R) {
        if (vectorSize != R.vectorSize) return false;
        for (int i = 0; i < vectorSize; i++) {
            if (bitVector[i] != R.bitVector[i]) {
                return false;
            }
        }
        return true;
    }
    // 输入
    friend std::istream &operator>>(std::istream &in, bitSet<T> &R) {
        for (int i = 0; i < R.vectorSize; i++) {
            in >> R.bitVector[i];
        }
        return in;
    }
    // 输出
    friend std::ostream &operator<<(std::ostream &out, bitSet<T> &R) {
        for (int i = 0; i < R.vectorSize; i++) {
            out << R.bitVector[i] << " ";
        }
        return out;
    }

   private:
    int setSize;
    int vectorSize;
    unsigned short *bitVector;
};