#include "Stack.hpp"

Stack::Stack()
{
    top = NULL;
}

char Stack::getTop()
{
    return top->getValue();
}

void Stack::pop()
{
    StackNode* nextOfTop = top->getNext();
    delete top;
    top = nextOfTop;
}

void Stack::insert(char value)
{
    StackNode* newNode = new StackNode();
    newNode->setValue(value);
    newNode->setNext(top);
    top = newNode;
}

bool Stack::isEmpty()
{
    return (top == NULL);
}

Stack::~Stack()
{
    StackNode* next = NULL;
    while(top != NULL)
    {
        next = top->getNext();
        delete top;
        top = next;     
    }
}
