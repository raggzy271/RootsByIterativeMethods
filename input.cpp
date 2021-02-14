#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string eq;
    
    cout << "Enter an equation->\n";
    getline(cin, eq);
    
    ofstream out;
    out.open("equation.cpp");

    out << "inline double f(double x){\n\t"
        <<      "return " << eq << ";\n"
        << "}";

    out.close();
    return 0;
}