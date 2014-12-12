#include <cstdio>
#include <iostream>
#include <vector>

//Input: First line - Capacity and number of items
//       Then the items follow, in the form of (weight, value);

int main(){

    long capacity, numItems; std::cin >> capacity >> numItems;
    std::vector<std::pair<long, long> > items(numItems);
    for(int p = 0; p < numItems; p++){
        long weight, value; std::cin >> weight >> value;
        items[p] = std::pair<long, long>(weight, value);
    }


    std::vector<std::pair<long, long> > optimal(capacity + 1, std::pair<long, long>(0,-1));


    for(long cap = 1; cap <= capacity; cap++){
        optimal[cap].first = optimal[cap - 1].first;
        for(long index = 0; index < items.size(); index++){
            long currentWeight = items[index].first;
            long currentValue  = items[index].second;

            if(currentWeight > cap){continue;}
            else if(optimal[cap - currentWeight].first + currentValue > optimal[cap].first){
                optimal[cap].first = optimal[cap - currentWeight].first + currentValue;
                optimal[cap].second = index;
            }
        }
    }

    std::vector<long> chosen;
    long cap = capacity;
    while(cap > 0){
        if(optimal[cap].second < 0){--cap;}
        else{
            long index = optimal[cap].second;
            chosen.push_back(index);
            cap -= items[index].first;
        }
    }

    std::cout << "Index\tWeight\tValue\n";
    for(int p = chosen.size() - 1; p >= 0; p--){
        long index = chosen[p];
        std::cout << index <<"\t"<< items[index].first <<"\t"<< items[index].second << "\n";
    }

    std::cout << "\nOptimal Value: " << optimal[capacity].first << std::endl;


    std::cout << "Optimal Value for different Capacities:\n" << std::endl;
    std::cout << "Cap\tValue\n";


    for(int p = 0; p < optimal.size(); p++){std::cout << p <<"\t"<< optimal[p].first << "\n";}

    return 0;
}
