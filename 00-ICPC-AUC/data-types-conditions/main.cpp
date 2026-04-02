#include <iostream>
using namespace std;
#include<iomanip>
#include <cmath>


int dataTypes(){
    int a;
    long long b;
    char c;
    float d;
    double e;

    cin >> a >> b >> c >> d >> e;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;

}

int printHello(){
    string s;
    cin>> s;
    
    cout << "Hello, " << s << endl;

}



void simpleCalculator(){
    long long x,y;
    cin >> x >> y;

    cout << x <<  " + " << y << " = " << x + y << endl;
    cout << x <<  " * " << y << " = " << x * y << endl;
    cout << x <<  " - " << y << " = " << x - y;
}

void difference(){
    int a, b, c, d;
    cin >> a>> b>> c>> d;

    cout << "Difference" << " = " << (a*b) - (c*d);
}





void areaOfCircle()
{   double R;
    cin>>R;
    const double PI = 3.141592653;
    double area = PI*R*R;
    cout << fixed << setprecision(9) << area << endl;

}

void digitsSummations(){
    long long a, b;
    cin >> a >> b;

    int digit1 = a % 10;
    int digit2 = b % 10;
    cout << digit1 + digit2;
}

void summationFrom1toN(){
    long long N;
    cin >> N;
    long long sum = 0;
    while(N>0){
        sum += N;
        N--;
    }
    cout << sum;
}

void twoNumbers(){
    long long A, B;
    cin >> A >> B;
    
    double result = (double)A/B;

    cout << "floor" << " "<< A << " / " << B << " = " << floor(result) << endl;
    cout << "ceil" << " "<< A << " / " << B << " = " << ceil(result) << endl;
    cout << "round" << " "<< A << " / " << B << " = " << round(result);
}

void welcomeToConditions(){
    int A,B;
    cin >> A >> B;

    if(A>=B){
        cout << "Yes";
    }else{
        cout << "No";
    }
}

void multiples(){
    long long  A,B;
    cin >> A >> B;
    if((A % B == 0) || (B % A == 0)){
        cout << "Multiples";
    }else{
        cout << "No Multiples";
    }
}

void maxMin(){
    int A,B,C;
    cin >> A >> B >> C;
    int Min = min(A, min(B,C));
    int Max = max(A, max(B,C));

    cout << Min << " " << Max;
}

void theBrothers(){
    string F1, S1;
    string F2, S2;
    cin >> F1 >> S1;
    cin >> F2 >> S2;

    if(S1 == S2){
        cout << "ARE Brothers";
    }else{
        cout << "NOT";
    }
}

void capitalOrSmallOrDigit(){
    char X;
    cin >> X;

    if(X >= '0' && X <= '9'){
        cout << "IS DIGIT";
    }else{
        cout << "ALPHA" << endl;
        if(X >= 'A' && X <= 'Z'){
            cout <<  "IS CAPITAL";
        }else{
            cout << "IS SMALL";
        }
    }
    

}

void Char(){
    char X;
    cin >> X;
    
    if(X >= 'A' && X <= 'Z'){
        cout << char(tolower(X));

    }else{
        cout << char((toupper(X)));
    }

}

void calculator(){
    int A;
    char S;
    int B;
    cin >> A >> S >> B;

    if(S == '+'){
        cout << A + B;
    }else if(S == '-'){
        cout << A - B;
    }else if(S == '*'){
        cout << A * B;
    }else{
        cout << A / B;
    }
}

void firstDigit(){
    int X;
    cin >> X;
    int firstDigit = 0;
    while (X != 0){
        firstDigit =  X % 10;
        X = X/10;
    }
    if(firstDigit % 2 == 0){
        cout << "EVEN";
    }else{
        cout << "ODD";
    }
}

void coordiatesOfaPoint(){
    double X, Y;
    cin >> X >> Y;

   if (X == 0 && Y == 0) {
        cout << "Origem";
    }
    else if (X == 0) {
        cout << "Eixo Y";
    }
    else if (Y == 0) {
        cout << "Eixo X";
    }
    else if (X > 0 && Y > 0) {
        cout << "Q1";
    }
    else if (X < 0 && Y > 0) {
        cout << "Q2";
    }
    else if (X < 0 && Y < 0) {
        cout << "Q3";
    }
    else { // X > 0 && Y < 0
        cout << "Q4";
    }

}

void ageInDays(){
    int x;
    cin >> x;

    int years = x / 365;
    int remainingDays = x % 365;
    int months = remainingDays / 30;
    int days = remainingDays % 30;

    cout << years << " years" << endl;
    cout << months <<  " months" << endl;
    cout << days << " days" <<  endl;
}

void interval(){
    double x;
    cin >> x;
    if(x >=0 && x<= 25){
        cout << "Interval" << " [0,25]";
    }else if(x>25 && x<=50){
        cout << "Interval" << " (25,50]";
    }else if(x>50 && x<=75){
        cout << "Interval" << " (50,75]";
    }else if(x>75 && x<=100){
        cout << "Interval" << " (75,100]";
    }else{
        cout << "Out of Intervals";
    }
}


#include <iostream>
#include <algorithm>
using namespace std;

void sortNumber() {
    int a, b, c;
    cin >> a >> b >> c;

    // store original order
    int original[3] = {a, b, c};

    // copy for sorting
    int sorted[3] = {a, b, c};

    sort(sorted, sorted + 3);

    // print ascending order
    for (int i = 0; i < 3; i++) {
        cout << sorted[i] << endl;
    }

    cout << endl; // blank line

    // print original order
    for (int i = 0; i < 3; i++) {
        cout << original[i] << endl;
    }

}



int main(){
    // printHello();
    // dataTypes();
    // simpleCalculator();
    // difference();
    // areaOfCircle();
    // digitsSummations();
    // summationFrom1toN();
    // twoNumbers();
    // welcomeToConditions();
    // multiples();
    // maxMin();
    // theBrothers();
    // capitalOrSmallOrDigit();
    // Char();
    // calculator();
    // firstDigit();
    // coordiatesOfaPoint();
    // ageInDays();
    // interval();
    sortNumber();

}