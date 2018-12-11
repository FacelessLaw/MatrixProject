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
    std::vector< std::vector<double> > curr(n, std::vector<double> (n + 1));
    std::cout << "Enter the values\n";

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n + 1; ++j)
            std::cin >> curr[i][j];

    matrix m(curr);
    m.cast_dioganal_form();
    m.print();

    return 0;
}