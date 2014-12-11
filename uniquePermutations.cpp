#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

int main(){

    std::string input = "aac";
    int length = input.size();
    char * array = new char[length];
    for(int k = 0; k < length; k++){array[k] = input[k];}


    std::sort(array, array + length);
    do{
        for(int k = 0; k < length; k++){printf("%c", array[k]);}
        puts("");
    } while(std::next_permutation(array, array + length));

    return 0;
}
