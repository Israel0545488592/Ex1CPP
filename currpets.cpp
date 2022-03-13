#include "mat.h"


string ariel::mat(int col, int row, char ch1, char ch2) {

    string ans = "";

    matrix* mat = createMat(col, row);

    if (!mat) { return ans; }//change to exptions

    carpet(mat, ch1, ch2);

    for (int i = 0; i < mat->col; i++) {
        for (int j = 0; j < mat->row; j++) {

            ans += mat->start[i + (j * mat->col)];
        }
        ans += '\n';
    }

    return ans;
}