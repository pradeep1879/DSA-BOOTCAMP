/* sorting and binary-search */ 

int main(){
  int n;
  int l = 0;
  int arr[n];
  int r = n-1;
  int target = arr[0];
  bool flag = false;
  
  while (l <= r){
    int mid = (l + r)/2;
    if(arr[mid] == target){
      flag = true;
      break;
    }else if(arr[mid] > target){
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  
}