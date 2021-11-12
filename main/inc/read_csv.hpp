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
    string delimiter;
    string file_path;
    uint32_t col;
    uint32_t row;
} csv_obj_t;

csv_obj_t *csv_read(csv_obj_t *csv_obj);

double csv_get_min_by_row(csv_obj_t *csv_obj, int row_no);
double csv_get_max_by_row(csv_obj_t *csv_obj, int row_no);
double csv_get_mean_by_row(csv_obj_t *csv_obj, int row_no);
double csv_get_median_by_row(csv_obj_t *csv_obj, int row_no);

double csv_get_min_by_col(csv_obj_t *csv_obj, int col_no);
double csv_get_max_by_col(csv_obj_t *csv_obj, int col_no);
double csv_get_mean_by_col(csv_obj_t *csv_obj, int col_no);
double csv_get_median_by_col(csv_obj_t *csv_obj, int col_no);

double csv_cat_to_num_map(string *cat);

unordered_map<double, uint32_t> csv_get_count_by_row(csv_obj_t *csv_obj, int row_no);
unordered_map<double, uint32_t> csv_get_count_by_col(csv_obj_t *csv_obj, int col_no);


void csv_write_has_to_file(void);

#endif
