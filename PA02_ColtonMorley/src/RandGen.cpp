#include <fstream>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std; 

void fillRand(const string name, const int num);

//Generates, 1000, 10000, and 100000 integers between 0 and 1 million
//and outputs them to files listed in parameters
int main()
{
    fillRand("1Thousand.txt", 1000);
    fillRand("10Thousand.txt", 10000);
    fillRand("100Thousand.txt", 100000);
    return 0;
}

void fillRand(const string name, const int num)
{
    ofstream output;
    int array[num];
    //open file
    output.open(name);
    //seed random generator
    srand(time(0));
    //generate num random numbers
    for(int i = 0; i < num; i++)
    {
        array[i] = rand() % 1000000;
    }
    //output those random numbers to file
    for(int i = 0; i < num; i++)
    {
        output << array[i] << '\n';
    }
    output.close();
}