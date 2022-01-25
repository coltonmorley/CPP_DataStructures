//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------
#include <iostream>

using namespace std;

#include "config.h"
#include "Stack.h"
#if !LAB6_TEST1
#  include "StackArray.h"
#else
#  include "StackLinked.h"
#endif

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;
    
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below


bool delimitersOk ( const string &expression )
{
    StackLinked<char> stack1;
    int length = expression.length();
    char temp;
    for (int i = 0; i < length; i++)
    {
        if(!isdigit(expression[i]))
        {
            switch(expression[i])
            {
                case '(':
                    stack1.push(expression[i]);
                    break;
                case ')':
                    temp = stack1.pop();
                        if(temp != '(')
                        {
                            return 0;
                        }
                    break;
                case '[': 
                    stack1.push(expression[i]);
                    break;
                case ']':
                    temp = stack1.pop();
                        if(temp != '[')
                        {
                            return 0;
                        }
                    break;
                //Disregarding defualt case so operators are ignored as well as digits 
            }
        }
    }
    return stack1.isEmpty();
}

