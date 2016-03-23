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


long getMaxRectangleArea(std::vector<std::vector<int> > box){

    std::vector<long> hist(box[0].size(), 0);
    long maxBoxArea(0);
    for(int row = 0; row < box.size(); row++){
        for(int col = 0; col < box[row].size(); col++){
            if(box[row][col]){++hist[col];}
            else{hist[col] = 0;}
        }

        long subArea = getHistMaxArea(hist);
        if(subArea > maxBoxArea){maxBoxArea = subArea;}
    }

    return maxBoxArea;
}


int main(){

    int R, C; std::cin >> R >> C;
    std::vector<std::vector<int> > matrix(R, std::vector<int>(C, 0));
    for(int row = 0; row < R; row++){for(int col = 0; col < C; col++){std::cin >> matrix[row][col];}}
    std::cout << getMaxRectangleArea(matrix) << std::endl;

    return 0;
}


/* Example input
4 6
1 0 0 1 1 1
1 0 1 1 0 1
0 1 1 1 1 1
0 0 1 1 1 1
*/
