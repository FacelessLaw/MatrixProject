#include <vector>

class matrix
{
    std::vector< std::vector<double> > cell;
    matrix(std::vector< std::vector<double> > _cell) : cell(_cell) {};
    
    void set_size(int);
    void print();
};