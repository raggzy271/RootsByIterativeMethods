#include <cstdlib>
int main(){
    system("g++ input.cpp -o input");
    system("input.exe");
    system("del input.exe");
    system("g++ methods.cpp -o methods");
    system("methods.exe");
    system("del methods.exe");
    system("del equation.cpp");
    return 0;
}
