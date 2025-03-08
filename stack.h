#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
// private inheritance so that no one outside stack can access vector
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();

    bool empty() const {
        // return pointer to same function in vector class
        return this -> std::vector<T>::empty();
    }

    size_t size() const {
        // return pointer to same function in vector class
        return this -> std::vector<T>::size();
    }

    void push(const T& item) {
        // return pointer to function that adds to end 
        return this -> std::vector<T>::push_back(item);
    }

    // throws std::underflow_error if empty
    void pop() { 
        if(empty()){
            throw std::underflow_error("Can't remove back when list is empty");
        }
        // return pointer to the function that removes the last element
        return this -> std::vector<T>::pop_back();
    }  

    // throws std::underflow_error if empty
    const T& top() const {
        if(empty()){
            throw std::underflow_error("Can't access back when list is empty");
        }
        // return pointer to the function that returns the last element
        return this -> std::vector<T>::back();
    } 
    
    // Add other members only if necessary
};


#endif