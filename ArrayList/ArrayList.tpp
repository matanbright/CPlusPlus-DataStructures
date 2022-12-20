template <typename T> ArrayList<T>::ArrayList() {
    arr = nullptr;
    length = 0;
}

template <typename T> ArrayList<T>::~ArrayList() {
    clear();
}

template <typename T> int ArrayList<T>::getLength() const {
    return length;
}

template <typename T> T ArrayList<T>::getAt(int index) const {
    if (index < 0 || index >= length)
        throw IndexOutOfBoundariesException();
    return arr[index];
}

template <typename T> void ArrayList<T>::setAt(int index, T value) {
    if (index < 0 || index >= length)
        throw IndexOutOfBoundariesException();
    arr[index] = value;
}

template <typename T> void ArrayList<T>::add(T value) {
    addAt(length, value);
}

template <typename T> void ArrayList<T>::addAt(int index, T value) {
    if (index < 0 || index > length)
        throw IndexOutOfBoundariesException();
    T* previousArr = arr;
    arr = new T[length + 1];
    arr[index] = value;
    if (length > 0) {
        for (int i = 0; i < index; i++)
            arr[i] = previousArr[i];
        for (int i = index + 1; i < length + 1; i++)
            arr[i] = previousArr[i - 1];
        delete [] previousArr;
    }
    length++;
}

template <typename T> T ArrayList<T>::remove() {
    return removeAt(length - 1);
}

template <typename T> T ArrayList<T>::remove(T value) {
    int firstIndexOfValue = -1;
    for (int i = 0; i < length; i++) {
        if (arr[i] == value) {
            firstIndexOfValue = i;
            break;
        }
    }
    if (firstIndexOfValue < 0)
        throw ValueNotFoundException();
    return removeAt(firstIndexOfValue);
}

template <typename T> T ArrayList<T>::removeAt(int index) {
    if (index < 0 || index >= length)
        throw IndexOutOfBoundariesException();
    T* previousArr = arr;
    if (length == 1)
        arr = nullptr;
    else {
        arr = new T[length - 1];
        for (int i = 0; i < index; i++)
            arr[i] = previousArr[i];
        for (int i = index + 1; i < length; i++)
            arr[i - 1] = previousArr[i];
    }
    T value = previousArr[index];
    delete [] previousArr;
    length--;
    return value;
}

template <typename T> ArrayList<T>* ArrayList<T>::clone() {
    ArrayList<T>* clone = new ArrayList<T>();
    for (int i = 0; i < length; i++)
        clone->add(arr[i]);
    return clone;
}

template <typename T> void ArrayList<T>::clear() {
    if (arr != nullptr) {
        delete [] arr;
        arr = nullptr;
    }
    length = 0;
}
