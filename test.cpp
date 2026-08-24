#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted halves
void merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st;
    int j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }
}

// Manual Merge Sort function (Divide and Conquer)
void mergeSort(vector<int>& arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, st, mid, end);
    }
}

int binary_search(const vector<int>& arr, int target) {
    int st = 0;
    int end = arr.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] > target) {
            end = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the target: ";
    cin >> target;

    // Sort the array using Merge Sort before running Binary Search
    if (n > 0) {
        mergeSort(arr, 0, n - 1);
    }

    cout << "Sorted Array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    int binaryResult = binary_search(arr, target);

    cout << "Binary Search Result Index: " << binaryResult << endl;

    return 0;
}

