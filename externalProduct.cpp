#include <cstdio>
#include <vector>
#include <iostream>
#include <string>


std::vector<std::string> generateCombinations(std::vector<std::string> inputVector){
    
    if(inputVector.size() == 0){
        std::vector<std::string> output;
        output.push_back("");
        return output;
    }
    else if (inputVector.size() == 1){
        std::vector<std::string> output;
        std::string currentString = inputVector[0];
        for(int n = 0; n < currentString.size(); n++){output.push_back(currentString.substr(n,1));}
        return output;
    }
    else if(inputVector.size() > 1){

        std::vector<std::string> output;
        std::string currentString = inputVector.back();
        inputVector.pop_back();
        std::vector<std::string> previousOutput = generateCombinations(inputVector);

        for(int k = 0; k < currentString.size(); k++){
            for(int m = 0; m < previousOutput.size(); m++){
                output.push_back(previousOutput[m] + currentString[k]);
            }
        }
        return output;
    }

    std::vector<std::string> dummy; return dummy;
}



int main(){

    std::string A = "abc"; 
    std::string B = "d";
    std::string C = "gh";
    std::string D = "xyz";

    std::vector<std::string> testInput; testInput.push_back(A); testInput.push_back(B); testInput.push_back(C); testInput.push_back(D);

    std::vector<std::string> testOutput = generateCombinations(testInput);
    for(int k = 0; k < testOutput.size(); k++){std::cout << testOutput[k] << std::endl;}

    return 0;
}
