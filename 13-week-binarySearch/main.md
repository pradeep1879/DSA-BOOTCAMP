content = r'''/*
===========================================================
        BINARY SEARCH NOTES (BEGINNER TO ADVANCED)
===========================================================

Binary Search is one of the most important algorithms.

It works on:
-> SORTED ARRAYS

Time Complexity:
-> O(log n)

===========================================================
1. WHAT IS BINARY SEARCH?
===========================================================

Binary Search divides the search space into HALF every step.

Example:

Array:
1 3 5 7 9 11 15

Target:
9

Steps:
1. Find middle element
2. Compare with target
3. Move LEFT or RIGHT
4. Repeat

===========================================================
2. IMPORTANT CONDITION
===========================================================

Binary Search ONLY works on sorted arrays.

Correct:
1 3 5 7 9

Wrong:
7 1 9 3 5

===========================================================
3. TIME COMPLEXITY
===========================================================

Linear Search:
O(n)

Binary Search:
O(log n)

Example:
1,000,000 elements
Only around 20 operations.

===========================================================
4. ITERATIVE BINARY SEARCH (PSEUDO CODE)
===========================================================

function binarySearch(arr, target):

    start = 0
    end = n - 1

    while(start <= end):

        mid = start + (end - start) / 2

        if(arr[mid] == target):
            return mid

        else if(arr[mid] < target):
            start = mid + 1

        else:
            end = mid - 1

    return -1

===========================================================
5. SAFE MID FORMULA
===========================================================

Use:

mid = start + (end - start) / 2

Avoid:

(start + end) / 2

Reason:
Can cause integer overflow.

===========================================================
6. ITERATIVE BINARY SEARCH CODE
===========================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int target) {

    int start = 0;
    int end = n - 1;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] == target) {
            return mid;
        }

        else if(arr[mid] < target) {
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }
    }

    return -1;
}

/*
===========================================================
7. RECURSIVE BINARY SEARCH
===========================================================

Function calls itself again and again.

PSEUDO CODE:

function binarySearch(arr, start, end, target):

    if(start > end):
        return -1

    mid = start + (end - start) / 2

    if(arr[mid] == target):
        return mid

    else if(arr[mid] < target):
        search right half

    else:
        search left half
===========================================================
*/

int recursiveBinarySearch(int arr[], int start, int end, int target) {

    if(start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if(arr[mid] == target) {
        return mid;
    }

    else if(arr[mid] < target) {
        return recursiveBinarySearch(arr, mid + 1, end, target);
    }

    else {
        return recursiveBinarySearch(arr, start, mid - 1, target);
    }
}

/*
===========================================================
8. LOWER BOUND
===========================================================

Definition:
First index where:

arr[i] >= target

Example:
1 2 4 4 4 6

target = 4

Answer:
index = 2

===========================================================
*/

int lowerBound(int arr[], int n, int target) {

    int start = 0;
    int end = n - 1;

    int ans = n;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] >= target) {
            ans = mid;
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }
    }

    return ans;
}

/*
===========================================================
9. UPPER BOUND
===========================================================

Definition:
First index where:

arr[i] > target

===========================================================
*/

int upperBound(int arr[], int n, int target) {

    int start = 0;
    int end = n - 1;

    int ans = n;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] > target) {
            ans = mid;
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }
    }

    return ans;
}

/*
===========================================================
10. FIRST OCCURRENCE
===========================================================

If target found:
-> Store answer
-> Continue searching LEFT

===========================================================
*/

int firstOccurrence(int arr[], int n, int target) {

    int start = 0;
    int end = n - 1;

    int ans = -1;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] == target) {
            ans = mid;
            end = mid - 1;
        }

        else if(arr[mid] < target) {
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }
    }

    return ans;
}

/*
===========================================================
11. LAST OCCURRENCE
===========================================================

If target found:
-> Store answer
-> Continue searching RIGHT

===========================================================
*/

int lastOccurrence(int arr[], int n, int target) {

    int start = 0;
    int end = n - 1;

    int ans = -1;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] == target) {
            ans = mid;
            start = mid + 1;
        }

        else if(arr[mid] < target) {
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }
    }

    return ans;
}

/*
===========================================================
12. COUNT OCCURRENCES
===========================================================

count =
lastOccurrence - firstOccurrence + 1

===========================================================
*/

/*
===========================================================
13. BINARY SEARCH ON ANSWER
===========================================================

Used in:
-> Aggressive Cows
-> Allocate Books
-> Painter Partition
-> Koko Eating Bananas

Pattern:

while(low <= high):

    mid = possible answer

    if(valid):
        store answer
        move LEFT

    else:
        move RIGHT

===========================================================
*/

/*
===========================================================
14. SQUARE ROOT USING BINARY SEARCH
===========================================================
*/

int sqrtBinary(int n) {

    int start = 0;
    int end = n;

    int ans = 0;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        long long square = 1LL * mid * mid;

        if(square == n) {
            return mid;
        }

        else if(square < n) {
            ans = mid;
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }
    }

    return ans;
}

/*
===========================================================
15. ROTATED SORTED ARRAY
===========================================================

Example:

4 5 6 7 0 1 2

Observation:
At least one half is always sorted.

===========================================================
*/

/*
===========================================================
16. PEAK ELEMENT
===========================================================

One side always contains peak.

===========================================================
*/

/*
===========================================================
17. INFINITE SORTED ARRAY
===========================================================

Expand range exponentially:

end = end * 2

Then apply binary search.

===========================================================
*/

/*
===========================================================
18. BINARY SEARCH IN 2D MATRIX
===========================================================

Approach:
Treat matrix as sorted array.

row = mid / columns
col = mid % columns

===========================================================
*/

/*
===========================================================
19. COMMON MISTAKES
===========================================================

1. Using on unsorted array
2. Infinite loop
3. Wrong mid formula
4. Incorrect updates

Wrong:
start = mid

Correct:
start = mid + 1

===========================================================
*/

/*
===========================================================
20. STL FUNCTIONS
===========================================================

binary_search(arr, arr + n, x)

lower_bound(arr, arr + n, x)

upper_bound(arr, arr + n, x)

===========================================================
*/

/*
===========================================================
21. IMPORTANT INTERVIEW PATTERNS
===========================================================

-> Exact Search
-> Lower Bound
-> Upper Bound
-> First/Last Occurrence
-> Binary Search on Answer
-> Monotonic Functions

===========================================================
*/

/*
===========================================================
22. RECOGNIZING BINARY SEARCH PROBLEMS
===========================================================

Use Binary Search when you see:

-> Sorted array
-> Minimum possible
-> Maximum possible
-> First TRUE
-> Last FALSE
-> Monotonic property

===========================================================
*/

int main() {

    int arr[] = {1, 3, 5, 7, 9, 11, 15};
    int n = 7;

    int target = 11;

    cout << "Binary Search Index: "
         << binarySearch(arr, n, target) << endl;

    cout << "Lower Bound of 9: "
         << lowerBound(arr, n, 9) << endl;

    cout << "Upper Bound of 9: "
         << upperBound(arr, n, 9) << endl;

    cout << "Square Root of 25: "
         << sqrtBinary(25) << endl;

    return 0;
}

/*
===========================================================
                    GOLDEN RULE
===========================================================

Whenever you see:

-> Sorted
-> Minimum possible
-> Maximum possible
-> First TRUE
-> Last FALSE

Think:

Can Binary Search be applied here?

===========================================================
*/
'''

path = "/mnt/data/Binary_Search_Notes.cpp"

with open(path, "w") as file:
    file.write(content)

print(f"C++ notes file created at: {path}")
