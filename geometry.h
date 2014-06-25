/*
 * geometry.h
 * Andy Sayler
 * CSCI 3308
 * Summer 2014
 *
 * Description:
 * This file contains a simple geomtery functions.
 *
 */

#include <stdbool.h>

typedef struct coord_2d {
    double x;
    double y;
} coord_2d_t;

double coord_2d_dist(const coord_2d_t* a, const coord_2d_t* b);
bool coord_2d_eq(const coord_2d_t* a, const coord_2d_t* b);
void coord_2d_midpoint(coord_2d_t* mid, const coord_2d_t* a, const coord_2d_t* b);
