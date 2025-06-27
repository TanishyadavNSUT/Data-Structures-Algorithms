#include <iostream>
using namespace std;

int nth_term(int n)
{
    int term = (3 * n) + 7;
    return term;
}

int main()
{

    int n;
    cout << "enter the term you want: ";
    cin >> n;

    int value = nth_term(n);
    cout << n << "th term is: " << value;
}