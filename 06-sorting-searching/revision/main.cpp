#include <iostream>
using namespace std;


//Insertion Sort
void insertionSort( ){
  int arr[] = {5, 3, 4, 1, 2};
  int n = 5;

  for(int i = 1; i < n; i++){
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }

  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

}

// merge twoArray

void mergeTwoArray(){
  int arrA[] = {1, 7, 8, 150, 160};
  int A = 5;
  int arrB[] = {2, 5, 6, 9, 18, 19, 59};
  int B = 7;

  int arrC[A + B];

  int i = 0, j = 0, k = 0;

  while(i < A && j < B){
    if(arrA[i] < arrB[j]){
      arrC[k] = arrA[i];
      i++;
    }else{
      arrC[k] = arrB[j];
      j++;
    }
    k++;
  }

  while(i < A){
    arrC[k] = arrA[i];
    i++;
    k++;
  }

  while(j < B){
    arrC[k] = arrB[j];
    j++;
    k++;
  }
  for(int i = 0; i < (A+B); i++){
    cout << arrC[i] << " ";
  }
}


// Selection Sort
/**
 * 1)Select the min in the unsorted region.
 * 2)Bring to the front by swapping it with the first element of unsorted region.
 */

 void selectionSort(){
  int arr[] = {5, 3, 4, 1, 2};
  int n = 5;

  for(int i = 0;  i < n;  i++){
    int min = arr[i];
    int loc = i;
    for(int j = i + 1; j < n; j++){
      if(arr[j] < min){
        min = arr[j];
        loc = j;
      }
    }
    swap(arr[i], arr[loc]);
  }
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
 }

 // Bubble Sort
 /**
  * If two neighbours/adjacent element are in wrong order => swap them.
  */

  void bubbleSort(){
    int arr[] = {5, 3, 4, 1, 2};
    int n = 5;

    for(int i = n - 1; i >= 1; i--){
      for(int j = 0; j < i; j++){
        if(arr[j] > arr[j+1]){
          swap(arr[j], arr[j+1]);
        }
      }
    }

    for(int i = 0; i < n; i++){
      cout << arr[i] << " ";
    }
  }

int main(){
  // insertionSort();
  // mergeTwoArray();
  // selectionSort();
  bubbleSort();
}