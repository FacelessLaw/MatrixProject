#include <iostream>
#include "matrix.h"

void matrix::print(char type)
{
    if (type == 'r')
        for (int i = 0; i < reverse_cell.size(); ++i)
        {
            for (int j = 0; j < reverse_cell[i].size(); ++j)
            {
                std::cout << reverse_cell[i][j] << ' ';
            }
            std::cout << '\n';
        }
    else if (type == 'a')
        for (int i = 0; i < cell.size(); ++i)
        {
            for (int j = 0; j < cell[i].size(); ++j)
            {
                std::cout << cell[i][j] << ' ';
            }
            std::cout << '\n';
        }
    else if (type == 'd')
        std::cout << det << '\n';
}

void matrix::set_size(int n)
{
    cell.resize(n, std::vector<double> (n));
}

void matrix::string_exchange(int k, int l, std::vector< std::vector<double> > &curr)
{
    for (int i = 0; i < curr[k].size(); ++i)
        std::swap(curr[k][i], curr[l][i]);
}

void matrix::column_exchange(int k, int l, std::vector< std::vector<double> > &curr)
{
    for (int i = 0; i < curr.size(); ++i)
        std::swap(curr[i][k], curr[i][l]);
}

void matrix::string_multiplex_on_number(int k, double x, std::vector< std::vector<double> > &curr)
{
    for (int i = 0; i < curr[k].size(); ++i)
        curr[k][i] *= x;
}

void matrix::column_multiplex_on_number(int k, double x, std::vector< std::vector<double> > &curr)
{
    for (int i = 0; i < curr.size(); ++i)
        curr[i][k] *= x;
}

void matrix::string_devide_on_number(int k, double x, std::vector< std::vector<double> > &curr)
{
    for (int i = 0; i < curr[k].size(); ++i)
        curr[k][i] /= x;
}

void matrix::column_devide_on_number(int k, double x, std::vector< std::vector<double> > &curr)
{
    for (int i = 0; i < curr.size(); ++i)
        curr[i][k] /= x;
}

void matrix::string_add_to(int k, int l, std::vector< std::vector<double> > &curr)
{
    for (int i = 0; i < curr[k].size(); ++i)
        curr[l][i] += curr[k][i];
}

void matrix::column_add_to(int k, int l, std::vector< std::vector<double> > &curr)
{
    for (int i = 0; i < curr.size(); ++i)
        curr[i][l] += curr[i][k];
}

void matrix::string_subtract_from(int k, int l, std::vector< std::vector<double> > &curr)
{
    for (int i = 0; i < curr[k].size(); ++i)
        curr[k][i] -= curr[l][i];
}
void matrix::column_subtract_from(int k, int l, std::vector< std::vector<double> > &curr)
{
    for (int i = 0; i < curr.size(); ++i)
        curr[i][k] -= curr[i][l];
}

void matrix::cast_equations()
{
    int its = 0;
    while (its < cell.size())
    {
        int it = its;
        while(it < cell.size() && cell[it][its] == 0)
            ++it;
        
        if (it != its)
        {
            det *= -1;
            string_exchange(it, its, cell);   
            string_exchange(it, its, reverse_cell);
            string_exchange(it, its, det_cell);
        }
        
        string_devide_on_number(its, cell[its][its], reverse_cell);
        string_devide_on_number(its, cell[its][its], cell);
        
        for (int i = 0; i < cell.size(); ++i)
        {
            if (i == its || cell[i][its] == 0)
                continue;

            double x = cell[i][its];
            string_multiplex_on_number(its, x, cell);
            string_subtract_from(i, its, cell);
            string_devide_on_number(its, x, cell);

            string_multiplex_on_number(its, x, reverse_cell);
            string_subtract_from(i, its, reverse_cell);
            string_devide_on_number(its, x, reverse_cell);
            
            x = det_cell[i][its];
            int backup = det_cell[its][its];
            string_devide_on_number(its, backup, det_cell);
            string_multiplex_on_number(its, x, det_cell);
            string_subtract_from(i, its, det_cell);
            string_devide_on_number(its, x, det_cell);
            string_multiplex_on_number(its, backup, det_cell);
            det *= det_cell[its][its];
        }
        ++its;
    }
}