#include <iostream>

using std::cout;
using std::endl;


template <typename T, size_t ARRAY_CAPACITY = 1000>
class ArrayStack;

template <typename T, size_t ARRAY_CAPACITY>
    std::ostream & operator << (std::ostream & os, const ArrayStack<T, ARRAY_CAPACITY> & arrayStack);

template <typename T, size_t ARRAY_CAPACITY>
class ArrayStack{
      friend std::ostream & operator<<(std::ostream & os, const ArrayStack<T, ARRAY_CAPACITY> & arrayStack)
      {
          arrayStack.serialize(os);
          return os;
      }
    public:
    /*Default ctor: Setting m_top to 0 so that we can easily see no elements havae been added */
        ArrayStack()
        {
            m_top = 0;
        }
    /* Parameterized ctor: creates an objet filled with count number of values */
        ArrayStack(size_t count, const T & value)
        {
            m_top = 0;
            for (int i = 0; i < count; i++)
            {
                push(value);
            }
        }
    /*No pointers means no need for special implementation of copy ctor */
    /* No dynamic memory means no need for a custom dtor */
    /*No pointers means no need for assignment operator implementation either */
    /* Returns the last inserted element of the stack, both const and non const qualified */
        T & top()
        {
            return m_container[m_top - 1];
        }
        const T & top() const
        {
            return m_container[m_top - 1];
        }
    /* Adds element to top of stack */
        void push(const T & value)
        {
        if(!full())
        {
            m_container[m_top] = value;
            m_top++;
        }
        else
        {
            cout << "Warning: Attempting to push element into full array" << endl;
        }
        }
        void pop()
        {
        if(!empty())
        {
            m_top --;
        }
        else
        {
            cout << "Warning:Attempting to pop empty array" <<endl;
        }
        }
        size_t size() const
        {
            return m_top;
        }
        bool empty() const
        {
            if(m_top == 0)
            {
                return 1;
            }
            return 0;
        }
        bool full() const
        {
            if(m_top == ARRAY_CAPACITY)
            {
                return 1;
            }
            return 0;
        }
        void clear()
        {
            m_top = 0;
        }
        void serialize(std::ostream & os) const
        {
            if(m_top == 0)
            {
                cout << "Empty Array Stack" << endl;
                return;
            }
            for(int i = 0; i < m_top; i++)
            {
              os << m_container[i] << endl;
            }
        }
    private:
        T m_container[ARRAY_CAPACITY];
        size_t m_top;
};