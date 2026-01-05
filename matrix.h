#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

typedef struct {
        int rn;
        int cn;
        double* e;
} matrix_t;

matrix_t* make_matrix (int, int );

matrix_t* read_matrix (FILE* );

void write_matrix (matrix_t*, FILE* );

void put_entry_matrix (matrix_t*, int, int, double );

void add_to_entry_matrix (matrix_t*, int, int, double );

double get_entry_matrix (matrix_t*, int, int );

matrix_t* copy_matrix (matrix_t* );

matrix_t* transpose_matrix (matrix_t* );

void xchg_rows (matrix_t*, int, int );

void xchg_cols (matrix_t*, int i, int j );

matrix_t* mull_matrix (matrix_t*, matrix_t* );

matrix_t* ge_matrix (matrix_t* );

int bs_matrix (matrix_t* );

matrix_t* pivot_ge_matrix (matrix_t* , int* );

void pivot_ge_in_situ_matrix (matrix_t* );

matrix_t* symm_pivot_ge_matrix (matrix_t*, int* );

int* pivot_get_inv_per (matrix_t* , int* );

#endif
