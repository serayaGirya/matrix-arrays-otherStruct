//
// Created by serge on 12.02.2022.
//

#ifndef A_1_MATRIX_H
typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;


#define A_1_MATRIX_H

#endif //A_1_MATRIX_H
