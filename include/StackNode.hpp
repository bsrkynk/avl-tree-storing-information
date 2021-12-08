#ifndef STACKNODE_HPP
#define STACKNODE_HPP

#include <iostream>

class StackNode
{
public:
    StackNode();
    void setValue(char value);
    char getValue();
    void setNext(StackNode* next);
    StackNode* getNext();
    
private:
    char value;
    StackNode* next;
};

#endif