#include <cstdio>
#include <iostream>
#include <vector>

int main(){

    //Input
    //First Line: capacity, and number of items
    //Subsequent n lines: weight(w) and value (v) of each item

    long capacity, numItems; std::cin >> capacity >> numItems;
    std::vector<std::pair<long, long> > itemVec(numItems);
    for(int p = 0; p < numItems; p++){
        long weight, value; std::cin >> weight >> value;
        itemVec[p] = std::pair<long, long>(weight, value);
    }

    std::vector<std::vector<std::pair<long, long> > > matrix(numItems, std::vector<std::pair<long, long> >(capacity + 1, std::pair<long, long>(0, -1)));

    //Row 0, corresponding to item 0 - no previous item;
    for(long cap = 1; cap <= capacity; cap++){
        matrix[0][cap] = std::pair<long, long>(0, 0);
        if(itemVec[0].first <= cap){matrix[0][cap] = std::pair<long, long>(itemVec[0].second, 1);}
    }

    for(long cap = 1; cap <= capacity; cap++){
        for(long i = 1; i < numItems; i++){

            long weight = itemVec[i].first;
            long value  = itemVec[i].second;

            if(i == 0 && weight <= cap){matrix[0][cap] = std::pair<long, long>(value, 1);}
            else if(i > 0){
                matrix[i][cap] = std::pair<long, long>(matrix[i - 1][cap].first, 0);
                if(weight <= cap && matrix[i - 1][cap - weight].first + value > matrix[i][cap].first){matrix[i][cap] = std::pair<long, long>(matrix[i - 1][cap - weight].first + value, 1);}
            }
        }
    }

    std::cout << "\nMaximum Value: " << matrix[numItems - 1][capacity].first << std::endl << std::endl;

    //Rows correspond to items, and columns to capacity;
    for(long i = 0; i < numItems; i++){
        std::cout << i << "**\t";
        for(long cap = 0; cap <= capacity; cap++){std::cout << matrix[i][cap].first << "\t";}
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;


    long remCap = capacity;
    std::vector<long> includedItems;
    for(long p = numItems - 1; p >= 0; p--){
        if(matrix[p][remCap].second > 0){
            includedItems.push_back(p);
            remCap -= itemVec[p].first;
        }
    }
    for(long p = includedItems.size() - 1; p >= 0; p--){std::cout << includedItems[p] << "\t";}; puts("");

    return 0;
}
