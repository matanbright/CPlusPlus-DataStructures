template <typename T> Queue<T>::Queue() {
    firstBinNode = nullptr;
    lastBinNode = nullptr;
    length = 0;
}

template <typename T> Queue<T>::~Queue() {
    clear();
}

template <typename T> int Queue<T>::getLength() const {
    return length;
}

template <typename T> void Queue<T>::insert(T value) {
    BinNode<T>* newBinNode = new BinNode<T>(value);
    if (length > 0) {
        firstBinNode->setLeft(newBinNode);
        newBinNode->setRight(firstBinNode);
    }
    firstBinNode = newBinNode;
    if (length == 0)
        lastBinNode = newBinNode;
    length++;
}

template <typename T> T Queue<T>::remove() {
    if (length == 0)
        throw NoElementsException();
    BinNode<T>* removedBinNode = lastBinNode;
    lastBinNode = lastBinNode->getLeft();
    if (length > 1)
        lastBinNode->setRight(nullptr);
    else if (length == 1)
        firstBinNode = nullptr;
    T value = removedBinNode->getValue();
    delete removedBinNode;
    length--;
    return value;
}

template <typename T> T Queue<T>::head() const {
    if (length == 0)
        throw NoElementsException();
    return lastBinNode->getValue();
}

template <typename T> void Queue<T>::clear() {
    while (firstBinNode != nullptr) {
        BinNode<T>* removedBinNode = firstBinNode;
        firstBinNode = firstBinNode->getRight();
        delete removedBinNode;
    }
    lastBinNode = nullptr;
    length = 0;
}
