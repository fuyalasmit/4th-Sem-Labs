#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearchIterative(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] < key) return binarySearchRecursive(arr, mid + 1, right, key);
    return binarySearchRecursive(arr, left, mid - 1, key);
}

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 25;

    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int linResult = linearSearch(arr, n, key);
    cout << "Linear Search: " << (linResult != -1 ? "Found at index " + to_string(linResult) : "Not found") << endl;

    int binIterResult = binarySearchIterative(arr, n, key);
    cout << "Binary Search (Iterative): " << (binIterResult != -1 ? "Found at index " + to_string(binIterResult) : "Not found") << endl;

    int binRecResult = binarySearchRecursive(arr, 0, n - 1, key);
    cout << "Binary Search (Recursive): " << (binRecResult != -1 ? "Found at index " + to_string(binRecResult) : "Not found") << endl;

    return 0;
}
