//
// Created by serge on 25.12.2021.
//

#include <stdio.h>

// добавляет в конец массива a размера n значение value
void append_(int *a, size_t *n, const int value) {
    (*n)++;
    a[*n - 1] = value;
}

// возвращает индекс первого элемента в массиве a размера n,
// равного x, иначе размер массива
int linearSearch_(const int *a, const size_t n, const int x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return n;
}
// удаляет элемент массива а размера n с позиции index
// без сохранения порядка элементов
void deleteByPosUnsaveOrder_(int *a, size_t *n, const size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}




