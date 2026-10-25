
#include <cassert>

#include <iostream>

#include <vector>

#include <string>

using namespace std;

//first real example of a template function I made
template <typename T>
//notes for tutor (maybe go over with professor) remember that size_t just means a kind of intiger in this case you can replace 
T fold(T (*f)(T, T), const vector<T>& v, size_t indx = 0) //this takes in a function pointer that allows 2 inputs of type T 
{


    if (indx == v.size() - 1) 
    {
        return v[indx];
    }

    return f(v[indx], fold(f, v, indx + 1));
}

//simple add fucntion
int add(int a, int b) 
{
    return a + b;
}

//simple multiply 2 arguments function
int multiply(int a, int b) 
{
    return a * b;
}





int main() {
    // Integers

    assert(fold(add, vector<int>{1, 2, 3, 4}) == 10);

    assert(fold(multiply, vector<int>{1, 2, 3, 4}) == 24);

    //testing the implimentaion of doubles while also trying lambda functions
    auto add_doubles = [](double a, double b) {return a + b;};

    assert(fold<double>(add_doubles, vector<double>{1.5, 2.5, 3.0}) == 7.0);


    cout << "All tests passed!" << endl;

}
