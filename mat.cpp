#include "mat.hpp"
#include <stdexcept>

matrix* createMat(int col, int row) {

    // invalid input
    if (row < 1 || col < 1) { throw std::invalid_argument("dont play with me this is invalid"); }
    if (row % 2 == 0 || col % 2 == 0) { throw std::invalid_argument("dont play with me this is invalid"); }

    if (row < 1 || col < 1) { return NULL; }

    matrix* mat = new matrix;
    if (mat == nullptr) { return NULL; }

    mat -> col = col;
    mat -> row = row;

    mat -> start = new char[col * row];
    if (mat -> start == nullptr) { return NULL; }

    return mat;
}

void releseMat(matrix* mat) {

    delete[](mat -> start);
    delete mat;
}


//troversing the matrix in spiral fassion and ading the data as should

void carpet(matrix* mat, char ch1, char ch2) {

    //setup
    int iter = 0;       //iterator
    int count = 0;      //counter
    int loop = 0;       //indication in to how 'deep' we are in the matrix
    int col = mat->col;
    int row = mat->row;
    char ch = ch1;      //wich charcter decorates current layer

    while (count < col * row) {

        for (int i = 0; (i < col - 2 * loop) && (count < col * row); i++) {        //right

            mat->start[iter] = ch;
            iter++;
            count++;
        }
        iter--;         //retret to the matrix'es bounds
        iter += col;    //get ready for next diraction

        for (int i = 0; i < (row - 1 - 2 * loop) && (count < col * row); i++) {    //down

            mat->start[iter] = ch;
            iter += col;
            count++;
        }
        iter -= col;
        iter--;

        for (int i = 0; i < (col - 1 - 2 * loop) && (count < col * row); i++) {   //left

            mat -> start[iter] = ch;
            iter--;
            count++;
        }
        iter++;
        iter -= col;

        for (int i = 0; i < (row - 2 - 2 * loop) && (count < col * row); i++) {    //up

            mat -> start[iter] = ch;
            iter -= col;
            count++;
        }
        iter += col;
        iter++;

        ch == ch1 ? ch = ch2 : ch = ch1;  //fliping charcter for new layer     
        loop++;
    }
}

string ariel::mat(int col, int row, char ch1, char ch2) {

    //invalid input, see mat.hpp
    if ((ch1 < low || ch1 > high) || (ch2 < low || ch2 > high)) { throw std::invalid_argument("invalid charcter"); }

    string ans;

    matrix* mat = createMat(col, row);  //alocating memory

    if (mat == nullptr) { return ans; } 

    carpet(mat, ch1, ch2);             //ading the data as required

    for (int i = 0; i < row; i++) {    //constructing answere line ny line
        for (int j = 0; j < col; j++) {

            ans += mat -> start[j + (i * col)];
        }
        ans += '\n';
    }

    releseMat(mat);

    return ans;
}