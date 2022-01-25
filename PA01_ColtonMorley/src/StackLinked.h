//--------------------------------------------------------------------
//
//  StackArray.h
// 
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType> {

  public:

    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackLinked(const StackLinked& other);
    StackLinked& operator=(const StackLinked& other);
    ~StackLinked();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

  private:

    class StackNode {
      public:
	      StackNode(const DataType& nodeData, StackNode* nextPtr);

	      DataType dataItem;
      	StackNode* next;
    };

    StackNode* top;
};

//Sets top to nullptr to indicate stack is empty
template<typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
{
    top = nullptr;
}

template<typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
    StackNode* temp = top;
    StackNode* temp2 = other.top;
    while(temp != nullptr)
    {
      temp = new StackNode(temp2->dataItem, temp2->next);
      if(top == nullptr)
      {
        top = temp;
      }
      temp = temp->next;
      temp2 = temp2->next;
    }
    
}
template<typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
  if(this == other)
  {
    return *this;
  }
  clear();
  StackNode* temp = top;
    StackNode* temp2 = other.top;
    while(temp != nullptr)
    {
      temp = new StackNode(temp2->dataItem, temp2->next);
      if(top == nullptr)
      {
        top = temp;
      }
      temp = temp->next;
      temp2 = temp2->next;
    }
    return *this;
}

//Deletes memory allocated for the stack using clear
template<typename DataType>
StackLinked<DataType>::~StackLinked()
{
  clear();
  top = nullptr;
}

//Pushes newly allocated StackNode onto the top of stack
template<typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
    top = new StackNode(newDataItem, top);
}

//Pushes top off of stack and deallocates the memory that was being used to store it
//Returns the value that was popped.
template<typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
  if(!isEmpty())
  {
    StackNode* temp = top;
    top = top->next;
    DataType val = temp->dataItem;
    delete temp;
    return val;
  }
  else
  {
    //Edited out logic throw so that delimiters.cpp can work more easily
    return 0;
  }
  
}

//Pops everything in stack until top ends up as nullptr
template<typename DataType>
void StackLinked<DataType>::clear()
{
    while (top != nullptr)
    {
        pop();
    }
}

//If top is a nullptr, it assumes that the stack is empty
template<typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
    return (top == nullptr);
}

//Returns 0 as LinkedList nodes are dynamically allocated
template<typename DataType>
bool StackLinked<DataType>::isFull() const
{
    return 0;
}

//Pritns out the content of the stack
template<typename DataType>
void StackLinked<DataType>::showStructure() const
{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}

template<typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr)
{
  dataItem = nodeData;
  next = nextPtr;
}

#endif		//#ifndef STACKARRAY_H

