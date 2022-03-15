#ifndef _MAT_HPP_
#define _MAT_HPP_

#include <string>

using namespace std;

typedef struct matrix {

    //size
    int row;
    int col;

    char* start; //the actuall data
}matrix;

matrix* createMat(int, int);

void carpet(matrix*, char, char); //to ad the info as required 

void releseMat(matrix*); //free memory

namespace ariel { string mat(int, int, char, char); } //output function

//the ASCII interval of ligall input
#define low 33
#define high 126

#endif
