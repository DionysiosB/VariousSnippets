#include <iostream>
#include <vector>


long getHistMaxArea(std::vector<long> h){

    long maxArea;
    size_t n = h.size();
    std::vector<long> stack;
    size_t k(0);

    while(k < n){
        if(stack.empty() || h[stack.back()] <= h[k]){stack.push_back(k++);}
        else{
            long top = stack.back(); stack.pop_back(); 
            long area = h[top] * (stack.empty() ? k : (k - stack.back() - 1));
            if(area > maxArea){maxArea = area;}
        }
    }

    while(!stack.empty()){
        long top = stack.back(); stack.pop_back(); 
        long area = h[top] * (stack.empty() ? n : (n - stack.back() - 1));
        if(area > maxArea){maxArea = area;}
    }

    return maxArea;
}




int main(){

    int n; std::cin >> n;
    std::vector<long> hist(n, 0);
    for(int p = 0; p < n; p++){std::cin >> hist[p];}
    long area = getHistMaxArea(hist);
    std::cout << area << std::endl;

    return 0;
}
