#include <cstdio>
#include <iostream>

int64_t factorial(int x){
    if(x <= 1){return 1;}
    return x * factorial(x - 1);
}

int main(){

    for(int p = 0; p < 15; p++){
        printf("%lld\n", factorial(p));
    }

    return 0;
}
