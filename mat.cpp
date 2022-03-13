#include "mat.h"

matrix* createMat(int col, int row) {

    if (row < 1 || col < 1) { return NULL; }

    matrix* mat = new matrix;
    if (!mat) { return NULL; }

    mat->col = col;
    mat->row = row;
    mat->start = new char[col * row];
    if (!mat->start) { return NULL; }

    return mat;
}

void releseMat(matrix* mat) {

    delete[](mat->start);
    delete mat;
}


//troversing the matrix in spiral fassion and ading the data as should

void carpet(matrix* mat, char ch1, char ch2) {

    int iter = 0, count = 0, loop = 0;  //iterator, counter, indication to which layer we'r in
    int col = mat->col;
    int row = mat->row;
    char ch = ch1, dir = 'r';   // r - right, l - left ext...

    while (count < col * row) {

        switch (dir) {

        case 'r':

            for (int i = 0; (i < col - 2*loop) && count < col * row; i++) {

                mat->start[iter] = ch;
                iter++;
                count++;
            }
            iter--;         //retret to the matrix'es bounds
            iter += col;    //preper for next
            dir = 'd';      //diraction

        case 'd':

            for (int i = 0; (i < row - 1 - 2*loop) && count < col * row; i++) {

                mat->start[iter] = ch;
                iter += col;
                count++;
            }
            iter -= col;
            iter--;
            dir = 'l';

        case 'l':

            for (int i = 0; (i < col - 1 - 2*loop) && count < row * col; i++) {

                mat->start[iter] = ch;
                iter--;
                count++;
            }
            iter++;
            iter -= col;
            dir = 'u';

        case 'u':

            for (int i = 0; (i < row -2 - 2*loop) && count < col * row; i++) {

                mat->start[iter] = ch;
                iter -= col;
                count++;
            }
            iter += col;
            iter++;
            dir = 'r';

        default:
            break;
        }

        ch == ch1 ? ch = ch2 : ch = ch1;  //fliping charcter for new layer     
        loop++;
    }
}