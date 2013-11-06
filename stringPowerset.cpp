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
    std::string combinationsInput = "abcde";
    std::vector<std::string> binaryVector = binaryCombinations(combinationsInput.size(),testInput);
    for(int k = 0; k < binaryVector.size(); k++){std::cout << binaryVector[k] << std::endl;}


    for(int k = 0; k < binaryVector.size(); k++){
        std::string currentString = binaryVector[k];
        for(int m = 0; m < combinationsInput.size(); m++){if(currentString[m] == '1'){std::cout << combinationsInput[m];}}
        std::cout << std::endl;
    }

    return 0;
}
