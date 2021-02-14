#include <iostream>
#include <cmath>
using namespace std;
#include "equation.cpp" //where f(x) will be defined

double fd(double x){
    //calculating derative using fundamental principle
    return (f(x+1e-10) - f(x))*1e10;
}

inline bool isNotDefined(double x){
    //if x is infinity or NotANumber...
    return isinf(x) || isnan(x);
}

inline double bisection(double i, double j){
    return 0.5*(i+j);
}

inline double regular_falsi(double i, double j){
    return i - f(i)*(j-i)/(f(j)-f(i));
}

inline double newton_raphson(double i, double j){
    //only requires one variable
    return j - f(j)/fd(j);
}

double solve(double fptr(double, double)){ //a function pointer will be passed
    const int MAX_ITERATIONS = 10000;
    double i = INT8_MIN, j = -i, m;
    
    while(isNotDefined(f(i)) && i<j) i++;
    while(isNotDefined(f(j)) && j>i) j--;
    while(f(i)*f(j)>0 && i<j) j--;
    
    if(i==j) return INT16_MIN; //Error
    if(!f(i)) return i;
    if(!f(j)) return j;

    for(int it=1; it<=MAX_ITERATIONS; it++) {
        m = fptr(i, j);
        if(isNotDefined(f(m))) return INT16_MIN; //Error
        if(!f(m)) return m;
        if(f(i)*f(m)<0.0) j = m;
        else i = m;
    }

    return m;
}

int main(){
    int choice;
    cout << "1. Bisection Method" << endl;   
    cout << "2. Regular-Falsi Method" << endl;   
    cout << "3. Newton-Raphson Method" << endl;
    cin >> choice;

    double root;
    switch(choice){
        case 1: root = solve(bisection); break;
        case 2: root = solve(regular_falsi); break;
        case 3: root = solve(newton_raphson); break;
        default: cout << "Error!";
    }

    if(root==INT16_MIN) cout << "Error!";
    else cout << root;

    return 0;
}