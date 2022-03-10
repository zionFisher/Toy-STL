// O(n*n)

#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>

/*****
 * @brief insert sort. O(n*n)
 * @param arr array
 * @param left left boundary
 * @param right right boundary
 * @param lower_to_upper lower to upper
 *****/
template <typename T>
void insert_sort(std::vector<T> &arr, int left, int right, const bool &lower_to_upper = true)
{
    int size = arr.size(), outer, inner;
    if (size < 2 or left >= right or left < 0 or right > size - 1)
        return;

    for (outer = left + 1; outer < right + 1; ++outer)
    {
        T cur_val = arr[outer];
        for (inner = outer - 1; inner >= left; --inner)
            if (lower_to_upper and cur_val < arr[inner] or
               !lower_to_upper and cur_val > arr[inner])
                arr[inner + 1] = arr[inner];
            else
                break;

        arr[inner + 1] = cur_val;
    }

    return;
}

/*****
 * @brief insert sort. O(n*n)
 * @param arr array
 * @param left left boundary
 * @param right right boundary
 * @param lower_to_upper lower to upper
 *****/
template <typename T>
void insert_sort(std::vector<T> &arr, const bool &lower_to_upper = true)
{
    int size = arr.size(), outer, inner;
    if (size < 2)
        return;

    insertion_sort(arr, 0, size - 1, lower_to_upper);
    return;
}

#endif