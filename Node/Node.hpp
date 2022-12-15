#if !defined(NODE_HPP)
#define NODE_HPP



template <typename T> class Node {

    private: T value;
    private: Node<T>* next;

    public: Node(T value);
    public: Node(T value, Node<T>* next);
    public: T getValue() const;
    public: void setValue(T value);
    public: Node<T>* getNext() const;
    public: void setNext(Node<T>* next);
    public: bool hasNext() const;
};


#include "Node.tpp"



#endif
