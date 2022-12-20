#if !defined(LINKED_LIST_HPP)
#define LINKED_LIST_HPP



#include <exception>
#include "../BinNode/BinNode.hpp"

using namespace std;


template <typename T> class LinkedList {

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

    private: BinNode<T>* firstBinNode;
    private: BinNode<T>* lastBinNode;
    private: int length;
    
    public: LinkedList();
    public: ~LinkedList();
    private: BinNode<T>* getBinNodeAt(int index) const;
    public: int getLength() const;
    public: T getAt(int index) const;
    public: void setAt(int index, T value);
    public: void add(T value);
    public: void addAt(int index, T value);
    public: T remove();
    public: T remove(T value);
    public: T removeAt(int index);
    public: LinkedList<T>* clone();
    public: void clear();
};


#include "LinkedList.tpp"



#endif
