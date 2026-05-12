#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
===============================================================================
                         SLIDING WINDOW + TWO POINTERS
===============================================================================

Sliding Window is one of the most important techniques in DSA.

It is mainly used for:

1. Subarrays
2. Substrings
3. Contiguous segments
4. Fixed size windows
5. Variable size windows

-------------------------------------------------------------------------------
WHY DO WE NEED SLIDING WINDOW?
-------------------------------------------------------------------------------

Suppose we want:

-> Sum of every subarray of size K
-> Longest substring without repeating characters
-> Number of distinct elements in every window
-> Longest subarray with sum < K

Using brute force:

For every window:
    Recalculate everything again

Time Complexity:
    O(n²) or O(n³)

This is inefficient.

Sliding Window helps us:
    Reuse previous computation

and reduce complexity to:
    O(n)

===============================================================================
TYPES OF SLIDING WINDOW
===============================================================================

1. FIXED SIZE WINDOW
--------------------------------
Window size always remains constant.

Example:
    -> Maximum sum subarray of size K
    -> Distinct elements in every window of size K

Pattern:
    Remove left element
    Add right element

===============================================================================

2. VARIABLE SIZE WINDOW
--------------------------------
Window size changes dynamically.

Example:
    -> Longest substring without repeating characters
    -> Longest subarray with sum < K
    -> At most K distinct characters

Pattern:
    Expand right pointer
    Shrink left pointer when invalid

===============================================================================
HOW TWO POINTERS WORK
===============================================================================

We maintain:

l -> Left pointer
r -> Right pointer

Window:
    [l ........ r]

Initially:
    l = 0
    r = 0

Expand:
    r++

Shrink:
    l++

===============================================================================
GENERAL TEMPLATE (VARIABLE WINDOW)
===============================================================================

PSEUDOCODE:

Initialize:
    l = 0

For every r:

    Add current element

    While window becomes invalid:
        Remove left element
        l++

    Update answer

===============================================================================
GENERAL TEMPLATE (FIXED WINDOW)
===============================================================================

PSEUDOCODE:

1. Build first window of size K

2. Slide window:
        Remove left element
        Add new right element

===============================================================================
EXAMPLE 1:
SUM OF ALL SUBARRAYS (BRUTE FORCE)
===============================================================================

TIME COMPLEXITY:
    O(n³)

WHY?
    Three nested loops

-------------------------------------------------------------------------------
APPROACH
-------------------------------------------------------------------------------

Loop over all starting indices
Loop over all ending indices
Calculate sum manually

*/

void sumOfSubArrayBruteForce() {

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int l = 0; l < n; l++) {

        for(int r = l; r < n; r++) {

            int sum = 0;

            for(int i = l; i <= r; i++) {
                sum += arr[i];
            }

            cout << sum << " ";
        }

        cout << endl;
    }
}

/*
===============================================================================
EXAMPLE 2:
SUM OF ALL SUBARRAYS USING PREFIX SUM
===============================================================================

TIME COMPLEXITY:
    O(n²)

-------------------------------------------------------------------------------
PREFIX SUM CONCEPT
-------------------------------------------------------------------------------

prefix[i] =
    Sum from index 0 to i

Example:
    arr = [1 2 3 4]

prefix:
    [1 3 6 10]

-------------------------------------------------------------------------------
FORMULA
-------------------------------------------------------------------------------

Sum from l to r:

If l == 0:
    prefix[r]

Else:
    prefix[r] - prefix[l-1]

-------------------------------------------------------------------------------
WHY PREFIX SUM IS BETTER?
-------------------------------------------------------------------------------

Instead of recalculating sum again and again,
we answer every query in O(1).

*/

void sumOfSubArrayPrefix() {

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int prefix[n];

    prefix[0] = arr[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    for(int l = 0; l < n; l++) {

        for(int r = l; r < n; r++) {

            int sum;

            if(l == 0) {
                sum = prefix[r];
            }
            else {
                sum = prefix[r] - prefix[l - 1];
            }

            cout << sum << " ";
        }

        cout << endl;
    }
}

/*
===============================================================================
EXAMPLE 3:
SUM OF ALL SUBARRAYS USING CARRY FORWARD
===============================================================================

TIME COMPLEXITY:
    O(n²)

-------------------------------------------------------------------------------
CARRY FORWARD IDEA
-------------------------------------------------------------------------------

Instead of recalculating:

    1 + 2 + 3

again and again,

we keep extending previous sum.

Example:

sum = 1
sum = 1 + 2
sum = 1 + 2 + 3

-------------------------------------------------------------------------------
WHY THIS WORKS?
-------------------------------------------------------------------------------

Previous subarray sum already contains most work.

We only add one new element.

*/

void sumOfSubArrayCarryForward() {

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int l = 0; l < n; l++) {

        int sum = 0;

        for(int r = l; r < n; r++) {

            sum += arr[r];

            cout << sum << " ";
        }

        cout << endl;
    }
}

/*
===============================================================================
EXAMPLE 4:
MAXIMUM SUM SUBARRAY OF SIZE K
===============================================================================

TYPE:
    Fixed Size Sliding Window

-------------------------------------------------------------------------------
BRUTE FORCE
-------------------------------------------------------------------------------

Generate all subarrays of size K
Calculate sum

Complexity:
    O(n²)

-------------------------------------------------------------------------------
OPTIMAL APPROACH
-------------------------------------------------------------------------------

1. Calculate first window sum
2. Slide window

Remove:
    Left element

Add:
    New right element

-------------------------------------------------------------------------------
PSEUDOCODE
-------------------------------------------------------------------------------

Take first K elements sum

For remaining elements:

    Add new element
    Remove old element

    Update answer

TIME:
    O(n)

*/

void maximumSumSubarrayOfSizeK() {

    int n, k;
    cin >> n >> k;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;

    for(int i = 0; i < k; i++) {
        sum += arr[i];
    }

    int ans = sum;

    for(int i = k; i < n; i++) {

        sum += arr[i];
        sum -= arr[i - k];

        ans = max(ans, sum);
    }

    cout << ans;
}

/*
===============================================================================
EXAMPLE 5:
DISTINCT ELEMENTS IN EVERY WINDOW OF SIZE K
===============================================================================

TYPE:
    Fixed Size Sliding Window

-------------------------------------------------------------------------------
IDEA
-------------------------------------------------------------------------------

Use Hash Map for frequency.

Map stores:
    element -> frequency

Distinct elements:
    freq.size()

-------------------------------------------------------------------------------
WHEN MOVING WINDOW
-------------------------------------------------------------------------------

1. Remove left element
2. If frequency becomes 0:
        erase it
3. Add new right element

TIME:
    O(n)

*/

void distinctElementsInWindow() {

    int n, k;
    cin >> n >> k;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;

    for(int i = 0; i < k; i++) {
        freq[arr[i]]++;
    }

    cout << freq.size() << " ";

    for(int i = k; i < n; i++) {

        freq[arr[i - k]]--;

        if(freq[arr[i - k]] == 0) {
            freq.erase(arr[i - k]);
        }

        freq[arr[i]]++;

        cout << freq.size() << " ";
    }
}

/*
===============================================================================
EXAMPLE 6:
LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
===============================================================================

TYPE:
    Variable Size Sliding Window

-------------------------------------------------------------------------------
IDEA
-------------------------------------------------------------------------------

Expand right pointer.

If duplicate character appears:
    Shrink window from left

Maintain:
    All characters unique

-------------------------------------------------------------------------------
CONDITION
-------------------------------------------------------------------------------

freq[s[r]] > 1

means duplicate exists.

-------------------------------------------------------------------------------
TIME:
    O(n)

*/

void longestSubstringWithoutRepeatingCharacters() {

    string s;
    cin >> s;

    unordered_map<char, int> freq;

    int l = 0;

    int maxLength = 0;

    for(int r = 0; r < s.length(); r++) {

        freq[s[r]]++;

        while(freq[s[r]] > 1) {

            freq[s[l]]--;

            l++;
        }

        maxLength = max(maxLength, r - l + 1);
    }

    cout << maxLength;
}

/*
===============================================================================
EXAMPLE 7:
LONGEST SUBSTRING WITH ATMOST K DISTINCT CHARACTERS
===============================================================================

TYPE:
    Variable Size Sliding Window

-------------------------------------------------------------------------------
IDEA
-------------------------------------------------------------------------------

Maintain window with:
    At most K distinct characters

If distinct characters exceed K:
    Shrink from left

-------------------------------------------------------------------------------
IMPORTANT
-------------------------------------------------------------------------------

Number of distinct characters:
    freq.size()

NOT:
    freq[s[r]]

*/

void longestSubstringWithAtMostKDistinctCharacters() {

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    unordered_map<char, int> freq;

    int l = 0;

    int maxLength = 0;

    for(int r = 0; r < n; r++) {

        freq[s[r]]++;

        while(freq.size() > k) {

            freq[s[l]]--;

            if(freq[s[l]] == 0) {
                freq.erase(s[l]);
            }

            l++;
        }

        maxLength = max(maxLength, r - l + 1);
    }

    cout << maxLength;
}

/*
===============================================================================
EXAMPLE 8:
LONGEST SUBARRAY WITH SUM < K
===============================================================================

TYPE:
    Variable Size Sliding Window

-------------------------------------------------------------------------------
IMPORTANT CONDITION
-------------------------------------------------------------------------------

This works ONLY when all elements are positive.

-------------------------------------------------------------------------------
WHY?
-------------------------------------------------------------------------------

Removing elements from left always decreases sum.

This property fails for negative numbers.

-------------------------------------------------------------------------------
IDEA
-------------------------------------------------------------------------------

Expand window by moving r.

If sum becomes invalid:
    Shrink from left

Maintain:
    sum < k

TIME:
    O(n)

*/

void longestSubArrayWithSumLessThanK() {

    int n, k;
    cin >> n >> k;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long sum = 0;

    int l = 0;

    int maxLength = 0;

    for(int r = 0; r < n; r++) {

        sum += arr[r];

        while(sum >= k) {

            sum -= arr[l];

            l++;
        }

        maxLength = max(maxLength, r - l + 1);
    }

    cout << maxLength;
}

/*
===============================================================================
EXAMPLE 9:
COUNT SUBARRAYS WITH SUM < K
===============================================================================

TYPE:
    Variable Size Sliding Window

-------------------------------------------------------------------------------
IMPORTANT OBSERVATION
-------------------------------------------------------------------------------

If current valid window is:

    [l .... r]

Then ALL subarrays ending at r are valid.

Count:
    (r - l + 1)

-------------------------------------------------------------------------------
WHY?
-------------------------------------------------------------------------------

Because:
    [r]
    [r-1 ... r]
    [r-2 ... r]
    ...
    [l ... r]

all satisfy condition.

TIME:
    O(n)

*/

void countSubarraysWithSumLessThanK() {

    int n, k;
    cin >> n >> k;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long sum = 0;

    long long count = 0;

    int l = 0;

    for(int r = 0; r < n; r++) {

        sum += arr[r];

        while(sum >= k) {

            sum -= arr[l];

            l++;
        }

        count += (r - l + 1);
    }

    cout << count;
}

/*
===============================================================================
IMPORTANT SLIDING WINDOW PATTERN RECOGNITION
===============================================================================

Use FIXED SIZE WINDOW when:
--------------------------------
-> Window size K is fixed
-> Example:
        "subarray of size K"

Use VARIABLE SIZE WINDOW when:
--------------------------------
-> Need longest/shortest window
-> Conditions:
        sum < k
        distinct <= k
        unique characters
        etc.

===============================================================================
COMMON MISTAKES
===============================================================================

1. Forgetting to remove old element
2. Using wrong window size formula

Correct:
    r - l + 1

3. Forgetting erase() when frequency becomes 0

4. Sliding window with negative numbers
    (may fail)

5. Confusing substring vs subsequence

Substring:
    Contiguous

Subsequence:
    Not necessarily contiguous

===============================================================================
TIME COMPLEXITY SUMMARY
===============================================================================

Brute Force:
    O(n²) or O(n³)

Sliding Window:
    O(n)

Why?
    Each element enters and leaves window at most once.

===============================================================================
*/

int main() {

    // sumOfSubArrayBruteForce();

    // sumOfSubArrayPrefix();

    // sumOfSubArrayCarryForward();

    // maximumSumSubarrayOfSizeK();

    // distinctElementsInWindow();

    // longestSubstringWithoutRepeatingCharacters();

    // longestSubstringWithAtMostKDistinctCharacters();

    // longestSubArrayWithSumLessThanK();

    // countSubarraysWithSumLessThanK();

}