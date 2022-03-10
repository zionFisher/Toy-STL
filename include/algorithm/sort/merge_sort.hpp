// O(nlogn) stable sort

#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>

/*****
 * @brief merge sort base on iterative implementation. O(nlogn)
 * @param arr array
 * @param left left boundary
 * @param right right boundary
 * @param lower_to_upper lower to upper
 *****/
template <typename T>
void merge_sort_iterative(std::vector<T> &arr, int left, int right, const bool &lower_to_upper = true)
{
    int size = arr.size();
    if (size < 2 or left >= right or left < 0 or right > size - 1)
        return;

    std::vector<T> buffer(size);
    int l_left, l_right, r_left, r_right;

    for (int step = 1; step < size; step *= 2)
        for (l_left = left; l_left <= right; l_left = r_right + 1)
        {
            l_right = right < l_left + step - 1 ? right : l_left + step - 1;
            r_left  = right < l_right + 1       ? right : l_right + 1;
            r_right = right < r_left + step - 1 ? right : r_left + step - 1;

            int counter = 0, origin = l_left;

            if (lower_to_upper)
                while (l_left <= l_right and r_left <= r_right)
                    buffer[counter++] = arr[l_left] < arr[r_left] ? arr[l_left++] : arr[r_left++];
            else
                while (l_left <= l_right and r_left <= r_right)
                    buffer[counter++] = arr[l_left] > arr[r_left] ? arr[l_left++] : arr[r_left++];

            while (l_left <= l_right)
                buffer[counter++] = arr[l_left++];
            while (r_left <= r_right)
                buffer[counter++] = arr[r_left++];

            for (int outer = origin, counter = 0; outer <= r_right; ++outer)
                arr[outer] = buffer[counter++];
        }

    return;
}

/*****
 * @brief merge sort base on recursive implementation. O(nlogn)
 * @param arr array
 * @param left left boundary
 * @param right right boundary
 * @param lower_to_upper lower to upper
 *****/
template <typename T>
void merge_sort_recursive(std::vector<T> &arr, int left, int right, const bool &lower_to_upper = true)
{
    int size = arr.size();
    if (size < 2 or left >= right or left < 0 or right > size - 1)
        return;

    int mid = left + (right - left) * 0.5;
    int l_left = left, l_right = mid, r_left = mid + 1, r_right = right;

    merge_sort_recursive(arr, l_left, l_right, lower_to_upper);
    merge_sort_recursive(arr, r_left, r_right, lower_to_upper);

    std::vector<T> buffer;
    int counter = 0;

    if (lower_to_upper)
        while (l_left <= l_right and r_left <= r_right)
            buffer.emplace_back(arr[l_left] < arr[r_left] ? arr[l_left++] : arr[r_left++]);
    else
        while (l_left <= l_right and r_left <= r_right)
            buffer.emplace_back(arr[l_left] > arr[r_left] ? arr[l_left++] : arr[r_left++]);

    while (l_left <= l_right)
        buffer.emplace_back(arr[l_left++]);
    while (r_left <= r_right)
        buffer.emplace_back(arr[r_left++]);

    for (int outer = left; outer <= right; ++outer)
        arr[outer] = buffer[counter++];

    return;
}

/*****
 * @brief merge sort. O(nlogn)
 * @param arr array
 * @param lower_to_upper lower to upper
 *****/
template <typename T>
void merge_sort(std::vector<T> &arr, const bool &lower_to_upper = true)
{
    int size = arr.size();
    if (size < 2)
        return;

    merge_sort_iterative(arr, 0, size - 1, lower_to_upper);
    return;
}

#endif