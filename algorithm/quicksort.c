#include <stdio.h>
#include <string.h>

/* L, R is 0-based index */
void quicksort(int* arr, int L, int R)
{
    int left, right;
    int pivot, temp;
    left = L;
    right = R;
    pivot = arr[(L+R)/2];
    do {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot)
            right--;
        if (left <= right) {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    } while (left <= right);
    if (L < right)
        quicksort(arr, L, right);
    if (left < R)
        quicksort(arr, left, R);
}

int main()
{
    return 0;
}