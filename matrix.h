#include <vector>

class matrix
{
    std::vector< std::vector<double> > cell;
    
    public:
        void set_size(int);
        void print();
        void cast_dioganal_form();
        matrix(std::vector< std::vector<double> > _cell)
        {
            cell = _cell;
        };

    private:
        void string_multiplex_on_number(int, double);
        void column_multiplex_on_number(int, double);
        void string_devide_on_number(int, double);
        void column_devide_on_number(int, double);
        void string_add_to(int, int);
        void column_add_to(int, int);
        void string_subtract_from(int, int);
        void column_subtract_from(int, int);
        void string_exchange(int, int);
        void column_exchange(int, int);
};