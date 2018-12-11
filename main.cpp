#include <iostream>
#include "matrix.h"

int main()
{
    char type_of_input;
    std::cout << "Enter preferable type of input: file or terminal (F/T)\n";
    std::cin >> type_of_input;
    if (type_of_input == 'F')
        freopen("input.txt", "r", stdin);

    std::cout << "Enter the size of matrix\n";
    int n;
    std::cin >> n;
    std::vector< std::vector<double> > curr(n, std::vector<double> (n));
    matrix m(curr);

    std::cout << "Hello, world\n";
}