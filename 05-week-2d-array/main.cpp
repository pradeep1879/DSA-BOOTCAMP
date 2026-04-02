#include <iostream>
using namespace std;


void rowWise2DArr(){
  int n, m;
  cin >> n>> m;
  int arr[n][m];

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

}

void colWise2DArr(){
  int n, m;
  cin >> n>> m;
  int arr[n][m];

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }

  for(int j=0; j<n; j++){
    for(int i=0; i<m; i++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  
}

void waveColWise(){
  int n, m;
  cin >> n>> m;
  int arr[n][m];

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }

  for(int i=0; i<n; i++){
  if(i % 2 == 0){
    for(int j=0; j<m; j++){
        cout << arr[i][j] << " ";  
      }
    }else{
      for(int j=m-1; j>=0; j--){
        cout << arr[i][j] << " ";
      }
    }

  }

}


int main(){
  // rowWise2DArr();
  // colWise2DArr();
  // waveColWise();
}

