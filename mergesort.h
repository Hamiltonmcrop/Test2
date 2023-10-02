#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template <typename T>
void printVector(const std::vector<T>& data, int begin, int end);

template <typename T>
void merge(std::vector<T>& data, int begin, int middle, int end);

template <typename T>
void mergeSort(std::vector<T>& data, int begin, int end);

#endif

