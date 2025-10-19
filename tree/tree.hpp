class tree{
private:
public:
    tree();
    ~tree();
    void build_root(const int& value);
    int first_child(int p) const;
    int next_sibling(int p) const;
    int parent(int p) const;
    int get_data(int p) const;
    bool insert_child(int p, int& value);
    bool delete_child(int p, int i);
    void delete_sub_tree(int p);
    bool is_empty();
    void traversal(void(*visit)(int p));
};