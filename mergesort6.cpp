#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T>& data, int begin, int end)
{
    for (int i = begin; i <= end; i++)
    {
        cout << data[i] << " ";
    }
    cout << "\n";
}

template <typename T>
void merge(vector<T>& data, int begin, int middle, int end)
{
    int left_size = middle - begin + 1;
    int right_size = end - middle;

    vector<T> left(left_size);
    vector<T> right(right_size);

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
void mergeSort(vector<T>& data, int begin, int end)
{
    if (begin < end)
    {
        int middle = begin + (end - begin) / 2;
        cout << "Merge Sorting: ";
        printVector(data, begin, end);

        cout << "MERGE!!!" << endl;

        mergeSort(data, begin, middle);
        mergeSort(data, middle + 1, end);
        merge(data, begin, middle, end);
    }
    else
    {
        cout << "One List! Do nothing" << endl;
    }
}

int main()
{
    vector<int> data = {7, 2, 1, 4, 3};
    cout << "Merge Sorting: ";
    printVector(data, 0, data.size() - 1);
    mergeSort(data, 0, data.size() - 1);

    return 0;
}

