#if !defined(QUEUE_HPP)
#define QUEUE_HPP



#include <exception>
#include "../BinNode/BinNode.hpp"

using namespace std;


template <typename T> class Queue {

    public: class NoElementsException : public exception {
        private: const char* const EXCEPTION_MESSAGE = "Error: There are no elements in the queue!";
        public: const char* what() const noexcept override {
            return EXCEPTION_MESSAGE;
        }
    };

    private: BinNode<T>* firstBinNode;
    private: BinNode<T>* lastBinNode;
    private: int length;

    public: Queue();
    public: ~Queue();
    public: int getLength() const;
    public: void insert(T value);
    public: T remove();
    public: T head() const;
    public: Queue<T>* clone();
    public: void clear();
};


#include "Queue.tpp"



#endif
