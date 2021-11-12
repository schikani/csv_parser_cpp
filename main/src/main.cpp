
#include "read_csv.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    csv_obj_t csv_obj;

    csv_obj.file_path = "./big.csv";
    csv_obj.delimiter = ",";

    csv_read(&csv_obj);

    for (int i = 0; i < csv_obj.row; ++i)
    {
        for (int j = 0; j < csv_obj.col; ++j)
        {
            cout << csv_obj.data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Num of Rows: " << csv_obj.row << endl;
    cout << "Num of Cols: " << csv_obj.col << endl;

    cout << endl;

    int row_no = 0, col_no = 0;

    cout << "Enter row index: ";
    cin >> row_no;

    cout << endl;

    cout << "min: " << csv_get_min_by_row(&csv_obj, row_no) << endl;
    cout << "max: " << csv_get_max_by_row(&csv_obj, row_no) << endl;

    cout << "mean: " << csv_get_mean_by_row(&csv_obj, row_no) << endl;
    cout << "median: " << csv_get_median_by_row(&csv_obj, row_no) << endl;


    cout << endl;

    cout << "Enter col index: ";
    cin >> col_no;

    cout << "min: " << csv_get_min_by_col(&csv_obj, col_no) << endl;
    cout << "max: " << csv_get_max_by_col(&csv_obj, col_no) << endl;

    cout << "mean: " << csv_get_mean_by_col(&csv_obj, row_no) << endl;
    cout << "median: " << csv_get_median_by_col(&csv_obj, row_no) << endl;

    cout << endl;

    cout << "Count for row: " << row_no << endl;
    for (auto x: csv_get_count_by_row(&csv_obj, row_no))
    {
        cout << x.first << ": " << x.second << endl;
    }
    cout << endl;


    cout << "Count for col: " << col_no << endl;
    for (auto x: csv_get_count_by_col(&csv_obj, col_no))
    {
        cout << x.first << ": " << x.second << endl;
    }
    cout << endl;
    


    return 0;
}