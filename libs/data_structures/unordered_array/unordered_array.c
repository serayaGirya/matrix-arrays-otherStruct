//
// Created by serge on 25.12.2021.
//

#include "unordered_array.h"
#include <malloc.h>

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

// возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

// добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set, int value) {
    unordered_array_set_isAbleAppend(set);
    if (unordered_array_set_in(set, value) == set->size)
        append_(set->data, &set->size, value);
}

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; ++size) {
        unordered_array_set_insert(&set, a[i]);
    }
    return set;
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    return set1.size == set2.size && memcmp(set1.data, set2.data, set1.size) == 0;
}

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t positionDelElement = unordered_array_set_in(set, value);
    if (positionDelElement != set->size)
        deleteByPosUnsaveOrder_(set->data, &set->size, positionDelElement);
}

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set = unordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++)
        append_(set.data, &set.size, set1.data[i]);
    for (size_t i = 0; i < set2.size; i++)
        unordered_array_set_insert(&set, set2.data[i]);
    return set;
}

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    size_t capacity = set1.size + set2.size;
    unordered_array_set set3 = unordered_array_set_create(capacity);
    for (size_t i = 0; i < set1.size; i++)
        unordered_array_set_insert(&set3, set1.data[i]);
    for (size_t i = 0; i < set2.size; i++)
        if (unordered_array_set_in(&set3, set2.data[i]) != set3.size)
            unordered_array_set_deleteElement(&set3, set2.data[i]);
    return (unordered_array_set) set3;
}


// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set diffSet1 = unordered_array_set_difference(set1, set2);
    unordered_array_set diffSet2 = unordered_array_set_difference(set2, set1);
    unordered_array_set unitedSet = unordered_array_set_union(diffSet1, diffSet2);
    unordered_array_set_delete(diffSet1);
    unordered_array_set_delete(diffSet2);
    return unitedSet;
}

// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    return unordered_array_set_difference(universumSet, set);
}

// вывод множества set
void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    bool isEmpty = true;
    for (size_t i = 0; i < set.size; i++) {
        printf("%d ", set.data[i]);
        isEmpty = false;
    }
    if (isEmpty)
        printf("}");
    else
        printf("\b\b}\n");
}

// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}