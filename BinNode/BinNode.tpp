template<typename T> BinNode<T>::BinNode(T value) {
    left = nullptr;
    this->value = value;
    right = nullptr;
}

template<typename T> BinNode<T>::BinNode(BinNode<T>* left, T value, BinNode<T>* right) {
    this->left = left;
    this->value = value;
    this->right = right;
}

template<typename T> BinNode<T>* BinNode<T>::getLeft() const {
    return left;
}

template<typename T> void BinNode<T>::setLeft(BinNode<T>* left) {
    this->left = left;
}

template<typename T> T BinNode<T>::getValue() const {
    return value;
}

template<typename T> void BinNode<T>::setValue(T value) {
    this->value = value;
}

template<typename T> BinNode<T>* BinNode<T>::getRight() const {
    return right;
}

template<typename T> void BinNode<T>::setRight(BinNode<T>* right) {
    this->right = right;
}

template<typename T> bool BinNode<T>::hasLeft() const {
    return (left != nullptr);
}

template<typename T> bool BinNode<T>::hasRight() const {
    return (right != nullptr);
}
