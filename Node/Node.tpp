template <typename T> Node<T>::Node(T value) {
    this->value = value;
    next = nullptr;
}

template <typename T> Node<T>::Node(T value, Node<T>* next) {
    this->value = value;
    this->next = next;
}

template <typename T> T Node<T>::getValue() const {
    return value;
}

template <typename T> void Node<T>::setValue(T value) {
    this->value = value;
}

template <typename T> Node<T>* Node<T>::getNext() const {
    return next;
}

template <typename T> void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template <typename T> bool Node<T>::hasNext() const {
    return (next != nullptr);
}
