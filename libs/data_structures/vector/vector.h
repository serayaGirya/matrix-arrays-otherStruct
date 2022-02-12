//
// Created by serge on 03.02.2022.
//

#ifndef A_1_VECTOR_H
#define A_1_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

//возвращает структуру - дескриптор вектор из n значений
vector createVector(size_t n);

//изменяет количество
//памяти, выделенное под хранение элементов вектора v размера newCapacity
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из контейнера, но не освобождает выделенную память вектора v
void clear(vector *v);

//освобождает память, выделенную под
//неиспользуемые элементы вектора v
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору v
void deleteVector(vector *v);

//возвращает значение ИСТИНА, если вектор v пуст, иначе ЛОЖЬ
bool isEmpty(vector *v);

//возвращает значение ИСТИНА, если вектор v полон, иначе ЛОЖЬ
bool isFull(vector *v);

//возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в конец вектора v
void pushBack(vector *v, int x);

//удаляет последний элемент из вектора v
void popBack(vector *v);

//возвращает указатель на index-ый элемент вектора v
int *atVector(vector *v, size_t index);

//возвращает указатель на последний элемент вектора v
int *back(vector *v);

//возвращает указатель на нулевой элемент вектора v
int *front(vector *v);

#endif //A_1_VECTOR_H



