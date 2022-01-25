#include <iostream>
#include <stdexcept>

using namespace std;

#include "Stack.h"
#include "StackLinked.h"

template<typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
{
    top = NULL;
}

template<typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{/*
    if(other.top)
    {
        StackNode * temp = other.top;
        int size = 0;
        while(temp.next != NULL)
        {
            temp = temp.next;
            size++;
        }
        for (int i = size; size > 0; size --)
        
        
    }
    */
}
template<typename DataType>
StackLinked& StackLinked<DataType>::operator=(const StackLinked& other)
{

}

template<typename DataType>
StackLinked<DataType>::~StackLinked()
{

}
template<typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
    StackNode<DataType>* temp = top;
    top = new StackNode(newDataItem, temp);
}

template<typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
    StackNode<DataType>* temp = top;
    top = top.next;
    delete temp;
}

template<typename DataType>
void StackLinked<DataType>::clear()
{
    while (top != NULL)
    {
        pop();
    }
}

template<typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
    return (top = NULL);
}

template<typename DataType>
bool StackLinked<DataType>::isFull() const
{
    return 0;
}

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