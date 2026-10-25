#include <iostream>
using namespace std;

/** Given an array of N integers and Q queries, 
 *  find the sum of elements from index L to R (inclusive) for each query.
 *  Use 0-based indexing.
 * 
 */

 /**
  * Given an array of integers, find the maximum sum of any non-empty contiguous subarray.
  */

  void questionII(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    int max = arr[0];
    for(int i = 0; i < n; i++){
      int sum = 0;
      for(int j = i; j < n; j++){
        sum += arr[j];
        if(sum > max){
          max = sum;
        }
      }
    }
    cout << max << endl;
  }

  /**
   * Ques3. Given an array and an integer K, find the sum of every contiguous
   *        subarray of size K.
   */

   void questionIII(){
       int n, k;
      cin >> n >> k;

      int arr[n];
      for(int i = 0; i < n; i++){
        cin >> arr[i];
      }

      int sum = 0;
      for(int j = 0; j < k; j++){
        sum += arr[j];
      }
      cout << sum << endl;

      for(int i=k;i<n;i++){
        sum -= arr[i-k];
        sum += arr[i];
        cout << sum << endl;
      }
   }


   /**
    *Ques4. Find an index where the sum of all elements to its left
    * equals the sum of all elements to its right. If no such index exists, print -1.
    */


    void questionIV(){
      int n;
      cin >> n;

      int arr[n];
      for(int i = 0; i < n; i++){
        cin >> arr[i];
      } 

      int rightSum = 0;
      for(int i = 0; i < n; i++){
        rightSum += arr[i];
      }

      int leftSum = 0;
      bool found = false;
      for(int i = 0; i < n; i++){
        rightSum -= arr[i];
        if(rightSum == leftSum){
            cout << i;
            found = true;
            break;
        }
        leftSum += arr[i];
      }
      if(!found){
        cout << -1 << "\n";
      }

    }

int main(){
  // questionII();
  // questionIII();
  // questionIV();
}