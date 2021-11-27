#include "read_csv.hpp"

using namespace std;

unordered_map<string, uint32_t> u_map;

const string WHITESPACE = " \n\r\t\f\v";
 
string ltrim(const string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}
 
string rtrim(const string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}
 
string trim(const string &s) {
    return rtrim(ltrim(s));
}

vector <double>get_row_by_index(csv_obj_t *csv_obj, int row_no)
{
    vector <double> vect;
    for (int i = 0; i < csv_obj->col; ++i)
    {
        vect.push_back(csv_obj->data[row_no][i]);
    }

    return vect;
}

vector <double>get_col_by_index(csv_obj_t *csv_obj, int col_no)
{
    vector <double> vect;
    for (int i = 0; i < csv_obj->row; ++i)
    {
        vect.push_back(csv_obj->data[i][col_no]);
    }

    return vect;
}

// Initialize csv_obj
void csv_init(csv_obj_t *csv_obj)
{
    csv_obj->col = 0;
    csv_obj->row = 0;
    csv_obj->map_path = csv_obj->file_path + ".map";
}

string csv_get_cat_from_num(uint32_t cat_num)
{
    for (auto x: u_map)
    {
        if (x.second == cat_num) return x.first;
    }
    return "";
}


double csv_get_min_by_row(csv_obj_t *csv_obj, int row_no)
{
    double min = 0;
    min = csv_obj->data[row_no][0];

    for (int i = 0; i < csv_obj->col; ++i)
    {
        if (min > csv_obj->data[row_no][i])
        {
            min = csv_obj->data[row_no][i];
        }
    }

    return min;
}

double csv_get_max_by_row(csv_obj_t *csv_obj, int row_no)
{
    double max = 0;
    max = csv_obj->data[row_no][0];

    for (int i = 0; i < csv_obj->col; ++i)
    {
        if (max < csv_obj->data[row_no][i])
        {
            max = csv_obj->data[row_no][i];
        }
    }

    return max;
}

double csv_get_mean_by_row(csv_obj_t *csv_obj, int row_no)
{
    double mean = 0.0;

    for (int i = 0; i < csv_obj->col; ++i)
    {
        mean = mean + csv_obj->data[row_no][i];
    }

    mean /= csv_obj->col;

    return mean;
}

double csv_get_median_by_row(csv_obj_t *csv_obj, int row_no)
{
    double median = 0.0;
    vector<double> values;

    values.reserve(csv_obj->col);

    for (int i = 0; i < csv_obj->col; ++i)
    {
        values.push_back(csv_obj->data[row_no][i]);
    }

    sort(values.begin(), values.end());
    if (csv_obj->col % 2 != 0)
    {
        median = values[csv_obj->col / 2];
    }
    else
    {
        median = (values[(csv_obj->col - 1) / 2] + values[csv_obj->col / 2]) / 2.0;
    }

    return median;
}

double csv_get_min_by_col(csv_obj_t *csv_obj, int col_no)
{
    double min = 0.0;
    min = csv_obj->data[0][col_no];

    for (int i = 0; i < csv_obj->row; ++i)
    {
        if (min > csv_obj->data[i][col_no])
        {
            min = csv_obj->data[i][col_no];
        }
    }

    return min;
}

double csv_get_max_by_col(csv_obj_t *csv_obj, int col_no)
{
    double max = 0.0;
    max = csv_obj->data[0][col_no];

    for (int i = 0; i < csv_obj->row; ++i)
    {
        if (max < csv_obj->data[i][col_no])
        {
            max = csv_obj->data[i][col_no];
        }
    }

    return max;
}

double csv_get_mean_by_col(csv_obj_t *csv_obj, int col_no)
{
    double mean = 0.0;

    for (int i = 0; i < csv_obj->row; ++i)
    {
        mean = mean + csv_obj->data[i][col_no];
    }

    mean /= csv_obj->row;

    return mean;
}

double csv_get_median_by_col(csv_obj_t *csv_obj, int col_no)
{
    double median = 0.0;
    vector<double> values;

    values.reserve(csv_obj->row);

    for (int i = 0; i < csv_obj->row; ++i)
    {
        values.push_back(csv_obj->data[i][col_no]);
    }

    sort(values.begin(), values.end());
    if (csv_obj->row % 2 != 0)
    {
        median = values[csv_obj->row / 2];
    }
    else
    {
        median = (values[(csv_obj->row - 1) / 2] + values[csv_obj->row / 2]) / 2.0;
    }
    return median;
}

unordered_map<double, uint32_t> csv_get_count_by_row(csv_obj_t *csv_obj, int row_no)
{
    unordered_map<double, uint32_t> count_map;

    for (int i = 0; i < csv_obj->col; ++i)
    {
        if (count_map.find(csv_obj->data[row_no][i]) == count_map.end())
        {
            count_map[csv_obj->data[row_no][i]] = 1;
        }
        else
        {
            count_map[csv_obj->data[row_no][i]]++;
        }
    }

    return count_map;
}

unordered_map<double, uint32_t> csv_get_count_by_col(csv_obj_t *csv_obj, int col_no)
{
    unordered_map<double, uint32_t> count_map;

    for (int i = 0; i < csv_obj->row; ++i)
    {
        if (count_map.find(csv_obj->data[i][col_no]) == count_map.end())
        {
            count_map[csv_obj->data[i][col_no]] = 1;
        }
        else
        {
            count_map[csv_obj->data[i][col_no]]++;
        }
    }

    return count_map;
}

bool csv_cat_to_num_map(string *cat, double *cat_num)
{
    const char *str = cat->c_str();
    char *end = nullptr;
    double value = strtod(str, &end);
    bool result = false;

    if (strcmp(end, str) == 0)
    {
        // String not found in map.
        if (u_map.find((string)str) == u_map.end())
        {
            u_map[(string)str] = u_map.size();
            value = u_map[(string)str];
            result = true;
        }
        // String found map.
        else
        {
            value = u_map[(string)str];
        }
    }

    *cat_num = value;

    return result;
}

int csv_save_cat_to_num_map(string file_name)
{
    ofstream file;
    file.open(file_name);

    for (auto x : u_map)
    {
        size_t size = x.first.length() + sizeof(int32_t) + 2;
        char *line = (char *)malloc(size);
        sprintf(line, "%s,%d\n", x.first.c_str(), x.second);
        file.write(line, strlen(line));
        free(line);
    }

    file.close();

    return 0;
}

int csv_read_cat_to_num_map(string file_name)
{
    ifstream file;
    file.open(file_name);

    if (file.is_open())
    {
        size_t pos = 0;
        while (file)
        {
            string line, cat;
            uint32_t cat_num;
            getline(file, line);

            if ((pos = line.find("->")) != string::npos)
            {
                cat = line.substr(0, pos);
                cat_num = atoi(line.substr(pos + 1, line.length() - pos - 1).c_str());

                u_map[cat] = cat_num;
            }
        }

        file.close();
    }

    return 0;
}

csv_obj_t *csv_read(csv_obj_t *csv_obj)
{
    
    bool new_cat_found = false;

    ifstream file, map_file;
    file.open(csv_obj->file_path);
    map_file.open(csv_obj->map_path);

    if(map_file.good())
    {
        map_file.close();
        csv_read_cat_to_num_map(csv_obj->map_path);
    }
    else
    {
        new_cat_found = true;
    }

    if (file.is_open())
    {
        size_t pos = 0;
        string token;

        while (file)
        {
            vector<double> row;
            string line;
            getline(file, line);

            while ((pos = line.find(csv_obj->delimiter)) != string::npos)
            {
                token = line.substr(0, pos);
                token = trim(token);
                double value;

                if (csv_cat_to_num_map(&token, &value))
                {
                    new_cat_found = true;
                }

                row.push_back(value);

                line.erase(0, pos + csv_obj->delimiter.length());
            }

            // Last Column
            if (line.length())
            {
                double value;
                line = trim(line);

                if (csv_cat_to_num_map(&line, &value))
                {
                    new_cat_found = true;
                }

                row.push_back(value);
            }

            if (!row.empty())
            {
                if (csv_obj->col == 0)
                {
                    csv_obj->col = row.size();
                }

                csv_obj->data.push_back(row);
                csv_obj->row++;
            }
        }

        file.close();
    }

    if (new_cat_found)
    {
        csv_save_cat_to_num_map(csv_obj->map_path);
    }

    return csv_obj;
}
