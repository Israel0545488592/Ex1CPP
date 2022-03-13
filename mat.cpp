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

            while (iter % col < col - loop || iter == 0) {

                mat->start[iter] = ch;
                iter++;
                count++;
            }
            iter--;
            iter += row;
            dir = 'd';

        case 'd':

            while (iter < (col - loop) * (row - loop)) {

                mat->start[iter] = ch;
                iter += row;
                count++;
            }
            iter -= row;
            iter--;
            dir = 'l';

        case 'l':

            while (iter % col < col - loop || iter == (col * row) - 1) {

                mat->start[iter] = ch;
                iter--;
                count++;
            }
            iter++;
            iter -= row;
            dir = 'u';

        case 'u':

            while (iter > loop + row * loop) {

                mat->start[iter] = ch;
                iter -= row;
                count++;
            }
            iter += row;
            iter++;
            dir = 'r';

        default:
            break;
        }

        ch == ch1 ? ch = ch2 : ch = ch1;  //fliping charcter for new layer     
        loop++;
    }
}