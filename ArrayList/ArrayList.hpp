#if !defined(ARRAY_LIST_HPP)
#define ARRAY_LIST_HPP



#include <exception>

using namespace std;


template <typename T> class ArrayList {

    public: class IndexOutOfBoundariesException : public exception {
        private: const char* const EXCEPTION_MESSAGE = "Error: Index is outside the boundaries of the list!";
        public: const char* what() const noexcept override {
            return EXCEPTION_MESSAGE;
        }
    };

    public: class ValueNotFoundException : public exception {
        private: const char* const EXCEPTION_MESSAGE = "Error: Value is not found in the list!";
        public: const char* what() const noexcept override {
            return EXCEPTION_MESSAGE;
        }
    };

    private: T* arr;
    private: int length;
    
    public: ArrayList();
    public: ~ArrayList();
    public: int getLength() const;
    public: T getAt(int index) const;
    public: void setAt(int index, T value);
    public: void add(T value);
    public: void addAt(int index, T value);
    public: T remove();
    public: T remove(T value);
    public: T removeAt(int index);
    public: ArrayList<T>* clone();
    public: void clear();
};


#include "ArrayList.tpp"



#endif
