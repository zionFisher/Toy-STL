// O(nlogn)

#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <vector>
#include <stack>

/*****
 * @brief quick sort base on iterative implementation. O(nlogn)
 * @param arr array
 * @param left left boundary
 * @param right right boundary
 * @param lower_to_upper lower to upper
 *****/
template <typename T>
void quick_sort_iterative(std::vector<T> &arr, int left, int right, const bool &lower_to_upper = true)
{
    int size = arr.size();
    if (size < 2 or left >= right or left < 0 or right > size - 1)
        return;

    std::stack<std::pair<int, int>> range;
    range.push({left, right});
    std::pair<int, int> cur_range;

    while (range.empty() == false)
    {
        cur_range = range.top();
        range.pop();

        if(cur_range.first >= cur_range.second)
            continue;

        int cur_left = cur_range.first, cur_right = cur_range.second, origin_pos = cur_range.first;
        T pivot_val = arr[origin_pos];

        while (cur_left < cur_right)
        {
            while (lower_to_upper and arr[cur_right] >= pivot_val and cur_left < cur_right or
                  !lower_to_upper and arr[cur_right] <= pivot_val and cur_left < cur_right)
                cur_right--;
            while (lower_to_upper and arr[cur_left] <= pivot_val and cur_left < cur_right or
                  !lower_to_upper and arr[cur_left] >= pivot_val and cur_left < cur_right)
                cur_left++;

            if (cur_left < cur_right)
                std::swap(arr[cur_left], arr[cur_right]);
        }
        std::swap(arr[origin_pos], arr[cur_left]);

        int pivot = cur_left;
        range.push( { cur_range.first, pivot - 1 } );
        range.push( { pivot + 1, cur_range.second } );
    }
}

/*****
 * @brief quick sort base on recursive implementation. O(nlogn)
 * @param arr array
 * @param left left boundary
 * @param right right boundary
 * @param lower_to_upper lower to upper
 *****/
template <typename T>
void quick_sort_recursive(std::vector<T> &arr, int left, int right, bool lower_to_upper = true)
{
    int size = arr.size();
    if (size < 2 or left >= right or left < 0 or right > size - 1)
        return;

    int origin_left = left, origin_right = right, origin_pos = left;
    T pivot_val = arr[origin_pos];
    while (left < right)
    {
        while (lower_to_upper and arr[right] >= pivot_val and left < right or
              !lower_to_upper and arr[right] <= pivot_val and left < right)
            right--;
        while (lower_to_upper and arr[left] <= pivot_val and left < right or
              !lower_to_upper and arr[left] >= pivot_val and left < right)
            left++;

        if (left < right)
            std::swap(arr[left], arr[right]);
    }
    std::swap(arr[origin_pos], arr[left]);

    int pivot = left;
    quick_sort_recursive(arr, origin_left, pivot - 1, lower_to_upper);
    quick_sort_recursive(arr, pivot + 1, origin_right, lower_to_upper);
}

/*****
 * @brief quick sort. O(nlogn)
 * @param arr array
 * @param lower_to_upper lower to upper
 *****/
template <typename T>
void quick_sort(std::vector<T> &arr, const bool &lower_to_upper = true)
{
    int size = arr.size();
    if (size < 2)
        return;

    quick_sort_iterative(arr, 0, size - 1, lower_to_upper);
    return;
}

#endif