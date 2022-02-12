//
// Created by serge on 25.12.2021.
//

#include "algorithm.h"
#include <stdio.h>
void swap(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (int i = 0; i < size ; ++i) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}