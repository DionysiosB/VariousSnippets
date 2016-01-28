#include <cstdio>
#include <cstdlib>

class Stack{

    struct node{
        int data;
        node *next;
    };


    public:
        Stack(){
            head = NULL;
        }

        ~Stack(){};

    void push(int x){
        node *p = new node;
        p->data = x;
        p->next = head;
        head = p;
        printf("Added a new node with value %d\n", x);
    }

    int pop(){
        if(head == NULL){puts("Empty list!"); return -1;}
        int res = head->data;
        printf("Removing element with value %d\n", res);
        node *rem = head;
        head = head->next;
        free(rem);
        return res;
    }

    void print(){
        if(head == NULL){puts("Empty Stack!"); return;}
        node *index = head;
        while(index != NULL){
            printf("%d\t", index->data);
            index = index->next;
        }
        puts("");
    }

    void addToEnd(int x){
        if(head == NULL){
            node *p = new node;
            p->data = x; p->next = NULL; head = p;
            printf("Added a new head with value %d\n", x);
            return;
        }

        node *index = head;
        while(index->next != NULL){index = index->next;}
        node *p = new node; 
        p->data = x; 
        p->next = NULL; 
        index->next = p;
        printf("Added a new node at the tail of the stack with value %d\n", x);
        return;
    }

    void removeElement(int x){

        if(head == NULL){puts("Empty stack, cannot remove element!"); return;}
        
        if(head->data == x){
            node *p = head;
            head = head->next;
            free(p);
            printf("Removed element with value %d, which happened to be the head\n", x);
            return;
        }

        node *p = head;
        while(p != NULL && p->next != NULL && p->next->data != x){p = p->next;}
        if(p == NULL || p->next == NULL){printf("Did not find element with value %d in the list, doing nothing\n", x); return;}

        node *toRemove = p->next;
        p->next = toRemove->next;
        free(toRemove);
        printf("Removed the first element with value %d from the list\n", x);
        return;
    }

    void erase(){
        while(head != NULL){this->pop();}
        puts("Removed all elements from the stack;");
    }




    private:
    node *head = NULL;

};

int main(){

    Stack *stack = new Stack();
    int n = 11;
    for(int p = 0; p < n; p++){stack->push(p);}


    return 0;
}
