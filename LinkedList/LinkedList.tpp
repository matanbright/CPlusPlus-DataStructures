template <typename T> LinkedList<T>::LinkedList() {
    firstBinNode = nullptr;
    lastBinNode = nullptr;
    length = 0;
}

template <typename T> LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T> BinNode<T>* LinkedList<T>::getBinNodeAt(int index) const {
    if (index < 0 || index >= length)
        throw IndexOutOfBoundariesException();
    BinNode<T>* currentBinNode;
    if (index < length / 2) {
        currentBinNode = firstBinNode;
        for (int i = 0; i < index; i++)
            currentBinNode = currentBinNode->getRight();
    } else {
        currentBinNode = lastBinNode;
        for (int i = length - 1; i > index; i--)
            currentBinNode = currentBinNode->getLeft();
    }
    return currentBinNode;
}

template <typename T> int LinkedList<T>::getLength() const {
    return length;
}

template <typename T> T LinkedList<T>::getAt(int index) const {
    return getBinNodeAt(index)->getValue();
}

template <typename T> void LinkedList<T>::setAt(int index, T value) {
    getBinNodeAt(index)->setValue(value);
}

template <typename T> void LinkedList<T>::add(T value) {
    addAt(length, value);
}

template <typename T> void LinkedList<T>::addAt(int index, T value) {
    if (index < 0 || index > length)
        throw IndexOutOfBoundariesException();
    BinNode<T>* newBinNode = new BinNode<T>(value);
    if (index == 0 || index == length) {
        if (index == 0) {
            if (length > 0) {
                firstBinNode->setLeft(newBinNode);
                newBinNode->setRight(firstBinNode);
            }
            firstBinNode = newBinNode;
        }
        if (index == length) {
            if (length > 0) {
                lastBinNode->setRight(newBinNode);
                newBinNode->setLeft(lastBinNode);
            }
            lastBinNode = newBinNode;
        }
    } else {
        BinNode<T>* currentBinNode = getBinNodeAt(index);
        currentBinNode->getLeft()->setRight(newBinNode);
        newBinNode->setLeft(currentBinNode->getLeft());
        currentBinNode->setLeft(newBinNode);
        newBinNode->setRight(currentBinNode);
    }
    length++;
}

template <typename T> T LinkedList<T>::remove() {
    return removeAt(length - 1);
}

template <typename T> T LinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= length)
        throw IndexOutOfBoundariesException();
    BinNode<T>* removedBinNode;
    if (index == 0 || index == length - 1) {
        if (index == 0) {
            removedBinNode = firstBinNode;
            firstBinNode = firstBinNode->getRight();
            if (length > 1)
                firstBinNode->setLeft(nullptr);
        }
        if (index == length - 1) {
            removedBinNode = lastBinNode;
            lastBinNode = lastBinNode->getLeft();
            if (length > 1)
                lastBinNode->setRight(nullptr);
        }
    } else {
        removedBinNode = getBinNodeAt(index);
        removedBinNode->getRight()->setLeft(removedBinNode->getLeft());
        removedBinNode->getLeft()->setRight(removedBinNode->getRight());
    }
    T value = removedBinNode->getValue();
    delete removedBinNode;
    length--;
    return value;
}

template <typename T> void LinkedList<T>::clear() {
    while (firstBinNode != nullptr) {
        BinNode<T>* removedBinNode = firstBinNode;
        firstBinNode = firstBinNode->getRight();
        delete removedBinNode;
    }
    lastBinNode = nullptr;
    length = 0;
}
