#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> countMap;

void mergeAndCount(int left, int mid, int right, vector<int>& arr) {
    int leftIdx = left, rightIdx = mid + 1;
    vector<int> merged;

    while (leftIdx <= mid && rightIdx <= right) {
        if (arr[leftIdx] <= arr[rightIdx]) {
            merged.push_back(arr[leftIdx]);
            leftIdx++;
        } else {
            merged.push_back(arr[rightIdx]);
            countMap[arr[rightIdx]]++;
            rightIdx++;
        }
    }

    while (leftIdx <= mid) {
        merged.push_back(arr[leftIdx]);
        leftIdx++;
    }
    while (rightIdx <= right) {
        merged.push_back(arr[rightIdx]);
        rightIdx++;
    }

    for (int i = left; i <= right; i++) {
        arr[i] = merged[i - left];
    }
}

void performMergeSort(int left, int right, vector<int>& arr) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    performMergeSort(left, mid, arr);
    performMergeSort(mid + 1, right, arr);
    mergeAndCount(left, mid, right, arr);
}

int computeLargestCountValue(vector<int>& arr) {
    int n = arr.size();
    performMergeSort(0, n - 1, arr);
    int maxCount = 0;

    for (const auto& entry : countMap) {
        maxCount = max(maxCount, entry.second);
    }

    return maxCount;
}

