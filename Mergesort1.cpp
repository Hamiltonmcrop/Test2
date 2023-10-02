#include <iostream>
#include "mergesort.h"

template <typename T>
void printVector(const std::vector<T>& data, int begin, int end)
{
    for (int i = begin; i <= end; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
void merge(std::vector<T>& data, int begin, int middle, int end)
{
    int left_size = middle - begin + 1;
    int right_size = end - middle;

    std::vector<T> left(left_size);
    std::vector<T> right(right_size);

    for (int i = 0; i < left_size; i++)
    {
        left[i] = data[begin + i];
    }

    for (int i = 0; i < right_size; i++)
    {
        right[i] = data[middle + 1 + i];
    }

    int i = 0, j = 0, k = begin;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            data[k] = left[i];
            i++;
        }
        else
        {
            data[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        data[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        data[k] = right[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(std::vector<T>& data, int begin, int end)
{
    if (begin < end)
    {
        int middle = begin + (end - begin) / 2;
        std::cout << "Merge Sorting: ";
        printVector(data, begin, end);

        std::cout << "MERGE!!!" << std::endl;

        mergeSort(data, begin, middle);
        mergeSort(data, middle + 1, end);
        merge(data, begin, middle, end);
    }
    else
    {
        std::cout << "One List! Do nothing" << std::endl;
    }
}

int main()
{
    std::vector<int> data = {7, 2, 1, 4, 3};
    std::cout << "Merge Sorting: ";
    printVector(data, 0, data.size() - 1);
    mergeSort(data, 0, data.size() - 1);

    return 0;
}

