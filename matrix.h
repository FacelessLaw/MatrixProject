#include <vector>

class matrix
{
    long double det = 1;
    std::vector< std::vector<double> > cell;
    std::vector< std::vector<double> > source_cell;
    std::vector< std::vector<double> > reverse_cell;
    std::vector< std::vector<double> > det_cell;

    public:
        void set_size(int);
        void print(char);
        void cast_equations();
        matrix(std::vector< std::vector<double> > _cell)
        {
            source_cell = _cell;
            cell = _cell;
            det_cell = _cell;
            reverse_cell.resize(_cell.size(), std::vector<double> (_cell.size(), 0));
            for (int i = 0; i < reverse_cell.size(); ++i)
                reverse_cell[i][i] = 1;
        };

    private:
        void string_multiplex_on_number(int, double, std::vector< std::vector<double> > &);
        void column_multiplex_on_number(int, double, std::vector< std::vector<double> > &);
        void string_devide_on_number(int, double, std::vector< std::vector<double> > &);
        void column_devide_on_number(int, double, std::vector< std::vector<double> > &);
        void string_add_to(int, int, std::vector< std::vector<double> > &);
        void column_add_to(int, int, std::vector< std::vector<double> > &);
        void string_subtract_from(int, int, std::vector< std::vector<double> > &);
        void column_subtract_from(int, int, std::vector< std::vector<double> > &);
        void string_exchange(int, int, std::vector< std::vector<double> > &);
        void column_exchange(int, int, std::vector< std::vector<double> > &);
};