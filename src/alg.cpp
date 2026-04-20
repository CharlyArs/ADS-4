// Copyright 2026 NNTU-CS
#include <cstdint>
#include <iostream>

int countPairs1(int *arr, int len, int value)
{
    size_t count = 0;
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = i+1; j < len; j++)
        {
            if (arr[i]+arr[j]==value)
            {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0;          
    int right = len - 1;   
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            else {
                int leftVal = arr[left];
                int leftCount = 0;
                while (left < right && arr[left] == leftVal) {
                    leftCount++;
                    left++;
                }
                int rightVal = arr[right];
                int rightCount = 0;
                while (right >= left && arr[right] == rightVal) {
                    rightCount++;
                    right--;
                }
                count += leftCount * rightCount;
            }
        }
        else if (currentSum < value) {
            left++;
        }
        else {
            right--;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        int start = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                start = mid;
                right = mid - 1;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (start != -1) {
            left = start;
            right = len - 1;
            int end = start;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) {
                    end = mid;
                    left = mid + 1; 
                }
                else if (arr[mid] < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            count += (end - start + 1);
        }
    }
    return count;
}
