#include <iostream>
#include "matrix.h"

void matrix::print()
{
    for (int i = 0; i < cell.size(); ++i)
    {
        for (int j = 0; j < cell[i].size(); ++j)
        {
            std::cout << cell[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void matrix::set_size(int n)
{
    cell.resize(n, std::vector<double> (n));
}