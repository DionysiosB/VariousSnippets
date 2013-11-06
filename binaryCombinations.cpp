#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

std::vector<std::string> binaryCombinations(int n, std::vector<std::string> inputVector){

    if(n == 0){return inputVector;}
    else if(inputVector.size() == 0){
        std::vector<std::string> tempVector;
        tempVector.push_back("0");
        tempVector.push_back("1");
        std::vector<std::string> outputVector = binaryCombinations(n - 1, tempVector);
        return outputVector;
    }
    else{
        std::vector<std::string> newVector;
        for(int k = 0; k < inputVector.size(); k++){newVector.push_back("0" + inputVector[k]);}
        for(int k = 0; k < inputVector.size(); k++){newVector.push_back("1" + inputVector[k]);}
        std::vector<std::string> outputVector = binaryCombinations(n - 1, newVector);
        return outputVector;
    }
}


int main(){

    std::vector<std::string> testInput;
    std::vector<std::string> testString = binaryCombinations(3,testInput);
    for(int k = 0; k < testString.size(); k++){std::cout << testString[k] << std::endl;}

    return 0;
}
