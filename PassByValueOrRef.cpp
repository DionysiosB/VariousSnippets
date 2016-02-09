#include <cstdio>
#include <iostream>

void swapRef(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
    return; 
}

void swapValue(int x, int y){
    int temp = x;
    x = y;
    y = temp;
    return; 
}


int main(){

    int a(1), b(2);
    swapValue(a, b);
    std::cout << a << "\t" << b << std::endl;

    swapRef(a, b);
    std::cout << a << "\t" << b << std::endl;


    return 0;
}
