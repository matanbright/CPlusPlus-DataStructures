template <typename T> Stack<T>::Stack() {
    firstNode = nullptr;
    length = 0;
}

template <typename T> Stack<T>::~Stack() {
    clear();
}

template <typename T> int Stack<T>::getLength() const {
    return length;
}

template <typename T> void Stack<T>::push(T value) {
    firstNode = new Node<T>(value, firstNode);
    length++;
}

template <typename T> T Stack<T>::pop() {
    if (length == 0)
        throw NoElementsException();
    Node<T>* removedNode = firstNode;
    firstNode = firstNode->getNext();
    T value = removedNode->getValue();
    delete removedNode;
    length--;
    return value;
}

template <typename T> T Stack<T>::top() const {
    if (length == 0)
        throw NoElementsException();
    return firstNode->getValue();
}

template <typename T> void Stack<T>::clear() {
    while (firstNode != nullptr) {
        Node<T>* removedNode = firstNode;
        firstNode = firstNode->getNext();
        delete removedNode;
    }
    length = 0;
}
