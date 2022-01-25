#include <iostream>
#include <stdexcept>
#include <string>

#include "Stack.h"
#include "StackLinked.h"

using namespace std;

float postfixEval(const string& expression);
float operate(const float operand1, const float operand2, const char operation);

int main()
{
    cout << "Exercise 1: Evaluation of postfix expressions" << endl;
    cout << "Test 1: (5 + 2) * 9  \t= Should equal 63; Postfix: 5 2 + 9 *  \t\t=  " << postfixEval("5 2 + 9 *") << endl;
    cout << "Test 2: (3^4(9-7)) / 3  = Should equal 54; Postfix: 3 4 ^ 9 7 - 3/  \t=  " << postfixEval("3 4 ^ 9 7 - * 3 /") << endl;
    cout << "Test 3: (5^0) * (9/3) \t= Should equal 3;  Postfix: 5 0 ^ 9 3 / *  \t=  " << postfixEval("5 0 ^ 9 3 / *") << endl;
    cout << "Test 4: (2*3*7)/2 \t= Should equal 21; Postfix: 2 3 * 7 * 2 /  \t=  " <<  postfixEval("2 3 * 7 * 2 /") << endl;
    cout << "Test 5: [(9-4)*9] - 7 \t= Should equal 38; Postfix: 9 4 - 9 * 7 -  \t=  " << postfixEval("9 4 - 9 * 7 -") << endl;
    return 0;
}

float postfixEval(const string& expression)
{
    float num;
    StackLinked<float> operandStack;
    int length = expression.length();
    float operand1, operand2;
    if(length == 0)
    {
        return 0;
    }
    for(int i = 0; i < length; i++)
    {
        if(isdigit(expression[i]))
        {
            operandStack.push(expression[i]-'0');
        }
        else if(expression[i] == ' ')
        {
            //Do nothing, ignore white space
        }
        else
        {
            operand2 = operandStack.pop();
            operand1 = operandStack.pop();

            operandStack.push(operate(operand1, operand2, expression[i]));
        }
    }
    return operandStack.pop();

}

float operate(const float operand1, const float operand2, const char operation)
{
    switch(operation)
    {
        case '+':
            return operand1 + operand2;
            break;
        case '-':
            return operand1 - operand2;
            break;
        case '*':
            return operand1 * operand2;
            break;
        case '/':
            return operand1 / operand2;
            break;
        case '^':
        {
            if(operand2 == 0)
            {
                return 1;
            }
            float total = 0;
            total = operand1 * operand1;
            for(int i = 1; i < (operand2 - 1); i++)
            {
                total = total * operand1;
            }
            return total;
            break;
        }
        default:  cout << "Invalid Operand" <<endl;
                    return 0;
    }
}