#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

#include "StackNode.hpp"

class Stack
{

public:
    Stack(); // Stack Constructoru
    char getTop(); // Stack'in tepesindeki elemani doner. 
    void pop(); // Stackten eleman cikarir. 
    void insert(char value);  // Stacke eleman ekler. 
    bool isEmpty(); // Stack bos ise true bos degil ise false doner. 
    ~Stack(); // Stack Destructoru 
    
private:
    StackNode* top;
};

#endif