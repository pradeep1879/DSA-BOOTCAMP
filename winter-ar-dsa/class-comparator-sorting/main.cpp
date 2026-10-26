#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool cmp(int a, int b){
  return b < a;
}

void sortInDescendingOrder(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(arr, arr + n, cmp);

  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }

}

bool cmp1(string a, string b){
  int lengthA = a.size();
  int lengthB = b.size();

  if(lengthA != lengthB){
    return lengthA < lengthB;
  }

  return a < b;
}

void sortByLength(){
    int n;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), cmp1);

    for (string s : arr) {
        cout << s << "\n";
    }
    cout << endl;
}


bool cmp2(int a, int b){
  int magnitudeA = abs(a);
  int magnitudeB = abs(b);

  if(magnitudeA != magnitudeB){
    return magnitudeA < magnitudeB;
  }

  return a < b;
}

void sortByMagnitude(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end(), cmp2); 

  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
}

bool cmp3(int a, int b){
  if(abs(a % 10) != abs(b % 10)){
    return abs(a % 10) < abs(b % 10);
  }

  return a < b;


}

void sortByLastDigit(){
  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end(), cmp3); 

    for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
}

struct Student{
  string name;
  int marks;
};

  bool cmp4(Student &a, Student &b){
    if(a.marks != b.marks){
      return a.marks > b.marks; // Higher marks first
    }

    return a.name < b.name;
  }

void sortStudents(){
  int n;
  cin >> n;

  Student arr[n];

  for(int i = 0; i < n; i++){
    cin >> arr[i].name >> arr[i].marks;
  }

  sort(arr, arr + n, cmp4);

  for(int i = 0; i < n; i++){
    cout << arr[i].name << " " << arr[i].marks << "\n";
  }

}



bool cmp5(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }

    return a.second < b.second;
}

void sortPoints() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++) {
      cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end(), cmp5);

    for (int i = 0; i < n; i++) {
      cout << points[i].first << " " << points[i].second << '\n';
    }
}

struct Flight {
  int flightNumber;
  int departureTime;
  string destination;
};

bool cmp6(Flight &a, Flight &b){
  if(a.departureTime != b.departureTime){
    return a.departureTime < b.departureTime;
  }
  
  return a.flightNumber < b.flightNumber;
}



void sortFlights(){
    int n;
    cin >> n;

    Flight arr[n];

    for (int i = 0; i < n; i++) {
      cin >> arr[i].flightNumber >> arr[i].departureTime >> arr[i].destination;
    } 

    sort(arr, arr + n, cmp6);

    for (int i = 0; i < n; i++) {
      cout << arr[i].flightNumber << " " << arr[i].departureTime << " "  << arr[i].destination << '\n';
    }
}




struct Stocks {
  string stockName;
  int price;
  int marketCap;
};

bool cmp7(Stocks &a, Stocks &b){
  if(a.price != b.price){
    return a.price < b.price;
  }
  if(a.marketCap != b.marketCap){
    return a.marketCap > b.marketCap;
  }
  
  return a.stockName < b.stockName;
}



void sortStocks(){
    int n;
    cin >> n;

    Stocks arr[n];

    for (int i = 0; i < n; i++) {
      cin >> arr[i].stockName >> arr[i].price >> arr[i].marketCap;
    } 

    sort(arr, arr + n, cmp7);

    for (int i = 0; i < n; i++) {
      cout << arr[i].stockName << " " << arr[i].price << " "  << arr[i].marketCap << '\n';
    }
}


struct Order {
  int orderId;
  int timestamp;
  int priority;
};

bool cmp8(Order &a, Order &b){
  if(a.priority != b.priority){
    return a.priority > b.priority;
  }
  if(a.timestamp != b.timestamp){
    return a.timestamp < b.timestamp;
  }
  
  return a.orderId < b.orderId;
}



void sortOrder(){
    int n;
    cin >> n;

    Order arr[n];

    for (int i = 0; i < n; i++) {
      cin >> arr[i].orderId >> arr[i].timestamp >> arr[i].priority;
    } 

    sort(arr, arr + n, cmp8);

    for (int i = 0; i < n; i++) {
      cout << arr[i].orderId << " " << arr[i].timestamp << " "  << arr[i].priority << '\n';
    }
}



int main(){
  // sortInDescendingOrder();
  // sortByLength();
  // sortByMagnitude();
  // sortByLastDigit();
  // sortStudents();
  // sortPoints();

  // sortFlights();
  // sortStocks();
  sortOrder();
}