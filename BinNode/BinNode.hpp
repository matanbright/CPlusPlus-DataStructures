#if !defined(BIN_NODE_HPP)
#define BIN_NODE_HPP



template <typename T> class BinNode {

    private: BinNode<T>* left;
    private: T value;
    private: BinNode<T>* right;

    public: BinNode(T value);
    public: BinNode(BinNode<T>* left, T value, BinNode<T>* right);
    public: BinNode<T>* getLeft() const;
    public: void setLeft(BinNode<T>* left);
    public: T getValue() const;
    public: void setValue(T value);
    public: BinNode<T>* getRight() const;
    public: void setRight(BinNode<T>* right);
    public: bool hasLeft() const;
    public: bool hasRight() const;
};


#include "BinNode.tpp"



#endif
