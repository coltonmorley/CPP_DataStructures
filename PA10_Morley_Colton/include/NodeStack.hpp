#include <iostream>
#include "Node.hpp"

using std::cout;
using std::endl;


template <typename T>
    std::ostream & operator << (std::ostream & os, const NodeStack<T> & nodeStack);

template <typename T>
class NodeStack{

        friend std::ostream & operator<<(std::ostream & os,const NodeStack<T> & nodeStack)
        {
            nodeStack.serialize(os);
            return os;

        }

    public:
    /* Default ctor, sets m_top to nullptr to signify empty stack */
        NodeStack()
        {
            m_top = nullptr;
        }
    /* Parameterized ctor, creates stack of size count and fills all elemnts with value passe */
        NodeStack(size_t count, const T & value)
        {
            for(int i = 0; i < count; i++)
            {
                push(value);
            }
        }
    /* Copy ctor, creates a copy of another NodeStack object */
        NodeStack(const NodeStack & other)
        {
            Node<T> * temp = other.m_top;
            size_t size = other.size();
            for(int i = size; size != 0; size--)
            {
                temp = other.m_top;
                for(int j = 0; j < size - 1; j++)
                {
                    temp = temp->m_next;
                }
                push(temp->data());
            }
            
        }
    /* Deallocates all Data */
        ~NodeStack()
        {
            clear();
            cout << "NodeStack dtor" << endl;
        }
    /* Assign new value to calling nodestack of rhs nodestack */
        NodeStack & operator= (const NodeStack & rhs)
        {
            clear();
            Node<T> * temp = rhs.m_top;
            size_t size = rhs.size();
            for(int i = size; size != 0; size--)
            {
                temp = rhs.m_top;
                for(int j = 0; j < size - 1; j++)
                {
                    temp = temp->m_next;
                }
                push(temp->data());
            }
            return *this;
        }
    /* Assumes stack not empty and returns reference to m_top */
        T & top()
        {
            return m_top;
        }
    /* Assumes stack not empty and returns const reference to m_top */
        const T & top() const
        {
            return m_top;
        }
    /*Allocates and addes new Node to top of stack */
        void push(const T & value)
        {
            if(empty())
            {
                m_top = new Node<T>(value, nullptr);
            }
            else
            {
                Node<T> * temp = m_top;
                m_top = new Node<T>(value, temp);
            }
        }
    /* Deallocates and removes top Node of stack */
        void pop()
        {
            if(!empty())
            {
            Node<T> * temp = m_top;
            m_top = m_top->m_next;
            delete temp;
            cout << "Node Deallocated" << endl;
            }
            else
            {
                cout << "Warning: attempting to pop empty stack" << endl;
            }
            
        }
    /* Returns size of NodeStack*/
        size_t size() const
        {
            int count = 0;
            Node<T> * curr = m_top;
            while (curr)
            {
                count ++;
                curr = curr->m_next;
            }
            return count;
        }
    /* Returns one if empty stack and 0 if stack is not empty */
        bool empty() const
        {
            if(m_top == nullptr)
            {
                return 1;
            }
            return 0;
        }
    /* Returns false */
        bool full() const
        {
            return 0;
        }
    /* Deallocates all Nodes */
        void clear()
        {
            while (m_top != nullptr)
            {
                pop();
            }
        }
        void serialize(std::ostream & os) const
        {
            if(m_top == nullptr)
            {
                os << "Empty list" << endl;
                return;
            }
            Node<T> * curr = m_top;
            while (curr != nullptr)
            {
                os << curr->data() << endl;
                curr = curr->m_next;
            }
        }

    private:
    Node<T> * m_top;
};
