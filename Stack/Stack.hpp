#if !defined(STACK_HPP)
#define STACK_HPP



#include <exception>
#include "../Node/Node.hpp"

using namespace std;


template <typename T> class Stack {

    public: class NoElementsException : public exception {
        private: const char* const EXCEPTION_MESSAGE = "Error: There are no elements in the stack!";
        public: const char* what() const noexcept override {
            return EXCEPTION_MESSAGE;
        }
    };

    private: Node<T>* firstNode;
    private: int length;

    public: Stack();
    public: ~Stack();
    public: int getLength() const;
    public: void push(T value);
    public: T pop();
    public: T top() const;
    public: void clear();
};


#include "Stack.tpp"



#endif
