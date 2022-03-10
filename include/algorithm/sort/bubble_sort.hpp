// O(n*n)

#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <vector>

/*****
 * @brief bubble sort. O(n*n)
 * @param arr array
 * @param left left boundary
 * @param right right boundary
 * @param lower_to_upper lower to upper
 *****/
template <typename T>
void bubble_sort(std::vector<T> &arr, int left, int right, const bool &lower_to_upper = true)
{
    int size = arr.size();
    if (size < 2 or left >= right or left < 0 or right > size - 1)
        return;

    for (int outer = left; outer < right; ++outer)
        for (int inner = left; inner + 1 < size - outer; ++inner)
            if (lower_to_upper and arr[inner] > arr[inner + 1] or
               !lower_to_upper and arr[inner] < arr[inner + 1])
                std::swap(arr[inner], arr[inner + 1]);

    return;
}

/*****
 * @brief bubble sort. O(n*n)
 * @param arr array
 * @param lower_to_upper lower to upper
 *****/
template <typename T>
void bubble_sort(std::vector<T> &arr, const bool &lower_to_upper = true)
{
    int size = arr.size();
    if (size < 2)
        return;

    bubble_sort(arr, 0, size - 1, lower_to_upper);
    return;
}

#endif