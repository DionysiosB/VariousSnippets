#include <iostream>
#include <vector>

int main(){

    long M, n; std::cin >> M >> n;
    std::vector<long> words(n);
    for(long p = 0; p < n; p++){std::cin >> words[p];}

    std::vector<std::vector<long> > spaces(n, std::vector<long>(n, 0));
    for(int p = 0; p < n; p++){
        spaces[p][p] = M - words[p];
        for(int q = p + 1; q < n; q++){spaces[p][q] = spaces[p][q - 1] - words[q] - 1;}
    }

    std::vector<std::vector<long> > penalty(n, std::vector<long>(n, 0));
    for(int p = 0; p < n; p++){
        for(int q = p; q < n - 1; q++){
            penalty[p][q] = (spaces[p][q] < 0) ? (-1) : (spaces[p][q] * spaces[p][q]);
        }
    }

    std::vector<long> score(n, -1);
    std::vector<long> prev(n, 0);
    for(int p = 1; p < n; p++){
        for(int q = 1; q <= p; q++){
            if(penalty[q][p] < 0){continue;}
            long candidate = score[q - 1] + penalty[q][p];
            if(score[p] < 0 || candidate < score[p]){score[p] = candidate; prev[p] = q;}
        }
    }

    std::vector<std::pair<long, long> > lines;
    long ind(n - 1);
    while(ind >= 0){
        lines.push_back(std::make_pair(prev[ind], ind));
        ind = prev[ind] - 1;
    }

    for(long p = lines.size() - 1; p >= 0; p--){std::cout << lines[p].first << " " << lines[p].second << std::endl;}

    return 0;
}
