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

void matrix::string_exchange(int k, int l)
{
    for (int i = 0; i < cell.size() + 1; ++i)
        std::swap(cell[k][i], cell[l][i]);
}

void matrix::column_exchange(int k, int l)
{
    for (int i = 0; i < cell.size(); ++i)
        std::swap(cell[i][k], cell[i][l]);
}

void matrix::string_multiplex_on_number(int k, double x)
{
    for (int i = 0; i < cell.size() + 1; ++i)
        cell[k][i] *= x;
}

void matrix::column_multiplex_on_number(int k, double x)
{
    for (int i = 0; i < cell.size(); ++i)
        cell[i][k] *= x;
}

void matrix::string_devide_on_number(int k, double x)
{
    for (int i = 0; i < cell.size() + 1; ++i)
        cell[k][i] /= x;
}

void matrix::column_devide_on_number(int k, double x)
{
    for (int i = 0; i < cell.size(); ++i)
        cell[i][k] /= x;
}

void matrix::string_devide_on_number(int k, double x)
{
    string_multiplex_on_number(k, 1.0/x);
}

void matrix::column_devide_on_number(int k, double x)
{
    column_multiplex_on_number(k, 1.0/x);
}

void matrix::string_add_to(int k, int l)
{
    for (int i = 0; i < cell.size() + 1; ++i)
        cell[l][i] += cell[k][i];
}

void matrix::column_add_to(int k, int l)
{
    for (int i = 0; i < cell.size(); ++i)
        cell[i][l] += cell[i][k];
}

void matrix::string_subtract_from(int k, int l)
{
    for (int i = 0; i < cell.size() + 1; ++i)
        cell[l][i] -= cell[k][i];
}
void matrix::column_subtract_from(int k, int l)
{
    for (int i = 0; i < cell.size(); ++i)
        cell[i][l] -= cell[i][k];
}

void matrix::cast_dioganal_form()
{
    int its = 0;

    while (its < cell.size())
    {
        int it = 0;
        while(its < cell.size() && cell[it][its] == 0)
            ++it;
        
        if (it != its)
            string_exchange(it, its);
        
        string_devide_on_number(its, cell[its][its]);

        for (int i = 0; i < cell.size(); ++i)
        {
            if (i == its || cell[i][its] == 0)
                continue;
            
            double x = cell[i][its];
            string_multiplex_on_number(its, x);
            string_subtract_from(i, its);
            string_devide_on_number(its, x);
        }
        
        ++its;
    }
}