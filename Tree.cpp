#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>

struct node{
    int data;
    node *left;
    node *right;
};

std::vector<int> rearrange(std::vector<int> v){

    if(v.size() <= 1){return v;}
    sort(v.begin(), v.end());
    std::vector<int> res; 
    int m = (v.size() - 1)/ 2;
    res.push_back(v[m]);
    std::vector<int> vleft(v.begin(), v.begin() + m); vleft = rearrange(vleft);
    std::vector<int> vright(v.begin() + m + 1, v.end()); vright = rearrange(vright);
    res.insert(res.end(), vleft.begin(), vleft.end());
    res.insert(res.end(), vright.begin(), vright.end());
    return res;
}



class Tree{

    public:
        Tree(){root = NULL;}
        ~Tree();

        void addData(int x){addData(root, x);}
        void addData(node * start, int x){
            if(start == NULL){
                node *p = new node; 
                p->data = x; 
                p->left = p->right = NULL; 
                root = p;
            }

            else if(x < start->data){
                if(start->left == NULL){node *p = new node; p->data = x; p->left = p->right = NULL; start->left = p;}
                else{addData(start->left, x);}
            }
            else if(x > start->data){
                if(start->right == NULL){node *p = new node; p->data = x; p->left = p->right = NULL; start->right = p;}
                else{addData(start->right, x);}
            }
        }


        void printDFS(){printDFS(root);}
        void printDFS(node * start){
            if(start == NULL){return;}
            printf("%d _ ", start->data);
            printDFS(start->left);
            printDFS(start->right);
        }


        void printBFS(){
            if(root == NULL){puts("Empty Stack using BFS");}
            std::deque<node> q;
            q.push_front(*root);
            while(!q.empty()){
                node current = q.back(); q.pop_back();
                printf("%d = ", current.data);
                if(current.left != NULL){q.push_front(*(current.left));}
                if(current.right != NULL){q.push_front(*(current.right));}
            }
        }


        int depth(){return depth(root);}
        int depth(node *start){
            if(start == NULL){return 0;}
            return 1 + std::max(depth(start->left), depth(start->right));
        }


        int minDepth(){return minDepth(root);}
        int minDepth(node *start){
            if(start == NULL){return 0;}
            return 1 + std::min(minDepth(start->left), minDepth(start->right));
        }

        int maxDepth(){return maxDepth(root);}
        int maxDepth(node *start){
            if(start == NULL){return 0;}
            return 1 + std::max(maxDepth(start->left), maxDepth(start->right));
        }

        bool isBalanced(){
            bool res = (this->maxDepth() - this->minDepth() <= 1) ? true : false;
            puts(res ? "Balanced Tree" : "Not balanced tree");
            return res;
        }

    private: 
        node *root;

};


int main(){

    std::vector<int> v; 
    v.push_back(5); v.push_back(3); v.push_back(1); v.push_back(7); v.push_back(9); v.push_back(4); v.push_back(2); v.push_back(8); v.push_back(0); v.push_back(11); v.push_back(6); v.push_back(10); v.push_back(12);

    Tree *tree = new Tree();
    for(size_t p = 0; p < v.size(); p++){tree->addData(v[p]);}
    tree->printDFS(); puts("");
    tree->printBFS(); puts("");
    printf("Depth of tree is: %d\n", tree->depth());
    tree->isBalanced();

    std::vector<int> test; int A = 15;
    for(int p = 0; p < A; p++){test.push_back(A - p);}
    test = rearrange(test);
    for(int p = 0; p < A; p++){printf("%d  ! ", test[p]);}; puts(""); 



}
