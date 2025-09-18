#include <vector>
#include <stdexcept>
#include <optional>

template<typename T>
class DualStack {
public:
    explicit DualStack(size_t capacity)
        : data_(capacity), cap_(capacity), top1_(-1), top2_(static_cast<int>(capacity)) {
        if (capacity == 0) throw std::invalid_argument("capacity must be > 0");
    }
    // push 到栈1（左侧）
    void push1(const T& value) {
        ensure_space();
        data_[++top1_] = value;
    }
    // push 到栈2（右侧）
    void push2(const T& value) {
        ensure_space();
        data_[--top2_] = value;
    }
    // pop 栈1，返回弹出的值（异常若为空）
    T pop1() {
        if (empty1()) throw std::underflow_error("pop1 from empty stack");
        T v = std::move(data_[top1_]);
        --top1_;
        return v;
    }
    // pop 栈2
    T pop2() {
        if (empty2()) throw std::underflow_error("pop2 from empty stack");
        T v = std::move(data_[top2_]);
        ++top2_;
        return v;
    }
    // 访问栈顶（不弹出），返回 optional（避免异常）
    std::optional<T> top1() const {
        if (empty1()) return std::nullopt;
        return data_[top1_];
    }
    std::optional<T> top2() const {
        if (empty2()) return std::nullopt;
        return data_[top2_];
    }

    bool empty1() const { return top1_ == -1; }
    bool empty2() const { return top2_ == static_cast<int>(cap_); }

    size_t size1() const { return static_cast<size_t>(top1_ + 1); }
    size_t size2() const { return static_cast<size_t>(cap_ - top2_); }
    size_t capacity() const { return cap_; }

    // 清空
    void clear1() { top1_ = -1; }
    void clear2() { top2_ = static_cast<int>(cap_); }
    void clear_all() { clear1(); clear2(); }

private:
    void ensure_space() {
        if (top1_ + 1 == top2_) throw std::overflow_error("DualStack overflow: no space left");
    }

    std::vector<T> data_;
    size_t cap_;
    int top1_; // -1 表示空
    int top2_; // cap 表示空
};