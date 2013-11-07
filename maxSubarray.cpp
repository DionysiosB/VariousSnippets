#include <iostream>
#include <cstdio>
#include <vector>

int maxSum(std::vector<int> const & input){
        
        int maxSoFar(input[0]), maxEndingHere(input[0]);
        size_t tempStart(0),candidateBegin(0),candidateEnd(0);

        for(size_t i = 1; i < input.size(); i++){
                if(maxEndingHere < 0){maxEndingHere = input[i]; tempStart = i;}
                else{maxEndingHere += input[i];}
                if(maxEndingHere >= maxSoFar){maxSoFar  = maxEndingHere; candidateBegin = tempStart; candidateEnd = i;}
        }
        std::cout << candidateBegin << "   " << candidateEnd << std::endl; 
        return maxSoFar ;
}


int main(){
    std::vector<int> test({1,2,3,-10,7,8,9,-11});
    std::cout << maxSum(test) << std::endl;
    return 0;
}
