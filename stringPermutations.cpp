#include <cstdio>
#include <iostream>
#include <string>


void printPerms(std::string input, std::string remainder){

    if(input.size() == 0){std::cout << remainder << std::endl;}
    else{
        for(int k = 0; k < input.size(); k++){
            std::string newRemainder = remainder + input[k];
            std::string newInput = input.substr(0,k) + input.substr(k + 1);
            printPerms(newInput,newRemainder);
        }
    }
}


int main(){

    std::string testString = "abcd";
    printPerms(testString, "");

    return 0;
}




