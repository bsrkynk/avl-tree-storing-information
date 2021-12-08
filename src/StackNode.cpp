#include "StackNode.hpp"

StackNode::StackNode()
{
    value = 0;
    next = NULL;
}

void StackNode::setValue(char value)
{
    this->value = value;
}

char StackNode::getValue()
{
    return value;
}

void StackNode::setNext(StackNode* next)
{
    this->next = next;
}

StackNode* StackNode::getNext()
{
    return next;
}
