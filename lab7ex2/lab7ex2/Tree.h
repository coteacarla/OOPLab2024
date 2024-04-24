template <typename T>
class Node {

public:
    T info;
    Node<T>* children[10];
    int index = 0;
    Node(T i)
    {
        this->info = i;
    }

};

template <typename T>
class Tree {
private:
    Node<T>* start;
public:
    Tree() {
        start = nullptr;
    }

    Node<T>* add_node(T elem, Node<T>* parent) {
        if (!start) {
            start = new Node<T>(elem);
            return start;
        }
        if (parent==nullptr) 
            parent = start;
        if (parent->index < 10)
        {
            parent->children[parent->index++] = new Node<T>(elem);
            return parent->children[parent->index - 1];
        }
        return nullptr;
    }


    Node<T>* get_node(Node<T>* parent) 
    {
        if (parent==nullptr) 
            return start;
        if (parent->index > 0)
        {
            return parent->children[0];
        }
        return nullptr;
    }

 

    void delete_node(Node<T>* node) {
        if (node==nullptr)
            return;
        for (int i = 0; i < node->index; ++i)
        {
            delete_node(node->children[i]);
        }
        delete node;
    }

    Node<T>* find(const T& elem, Node<T>* node) {
        if (node==nullptr) 
            node = start;
        if (node->info == elem)
            return node;
        for (int i = 0; i < node->index; ++i) 
        {
            Node<T>* found = find(elem, node->children[i]);
            if (found) 
                return found;
        }
        return nullptr;
    }


    bool insert(int ind, T elem, Node<T>* parent) {
        if (ind >= 10) 
            return false;
        if (parent==nullptr) 
            parent = start;
        if (parent->children[ind]!=nullptr)
            return false;
        parent->children[ind] = new Node<T>(elem);
        if(ind>this->index)
        this->index=ind;
        return true;
    }


    int count(Node<T>* node) {
        if (node==nullptr)
            node = start;
        return node->index;
    }

    void sort(Node<T>* node, bool (*compare)(const T&, const T&)) {
        if (compare==nullptr) 
            return;
        if (node == nullptr)
            node = start;

        for (int i = 1; i <=node->index - 1; ++i) {
            for (int j = i; j <=node->index; ++j) {
                if (compare(node->children[i]->info, node->children[j]->info)) {
                    std::swap(node->children[i], node->children[j]);
                }
            }
        }
    }

};
