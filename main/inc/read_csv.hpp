#ifndef _READ_CSV_HPP_
#define _READ_CSV_HPP_

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct 
{
    vector<vector<double>> data;
    string file_path;
    string delimiter;
    string map_path;
    uint32_t col;
    uint32_t row;
} csv_obj_t;

string ltrim(const string &s);
string rtrim(const string &s);
string trim(const string &s);

void csv_init(csv_obj_t *csv_obj);
vector <double>get_row_by_index(csv_obj_t *csv_obj, int row_no);
vector <double>get_col_by_index(csv_obj_t *csv_obj, int col_no);
csv_obj_t *csv_read(csv_obj_t *csv_obj);

double csv_get_min_by_row(csv_obj_t *csv_obj, int row_no);
double csv_get_max_by_row(csv_obj_t *csv_obj, int row_no);
double csv_get_mean_by_row(csv_obj_t *csv_obj, int row_no);
double csv_get_median_by_row(csv_obj_t *csv_obj, int row_no);

double csv_get_min_by_col(csv_obj_t *csv_obj, int col_no);
double csv_get_max_by_col(csv_obj_t *csv_obj, int col_no);
double csv_get_mean_by_col(csv_obj_t *csv_obj, int col_no);
double csv_get_median_by_col(csv_obj_t *csv_obj, int col_no);

string csv_get_cat_from_num(uint32_t cat_num);

unordered_map<double, uint32_t> csv_get_count_by_row(csv_obj_t *csv_obj, int row_no);
unordered_map<double, uint32_t> csv_get_count_by_col(csv_obj_t *csv_obj, int col_no);

// Private Methods
bool csv_cat_to_num_map(string *cat, double *cat_num);
int csv_save_cat_to_num_map(string file_name);
int csv_read_cat_to_num_map(string file_name);

#endif
