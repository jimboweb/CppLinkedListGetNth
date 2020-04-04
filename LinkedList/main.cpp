#include <iostream>
#include <cstdio>;
#include <cstdlib>;
using namespace std;

struct node{
    int data;
    struct node* next;

    explicit node(int x){
        data = x;
        next = nullptr;
    }
};

void push(struct node** head_ref, int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int GetNth(struct node* head_ref, int index);

int main() {
    int T,i,n,l,k;

    cin>>T;

    while (T--){
        struct node *head = NULL;

        cin>>n>>k;

        for(i=1;i<=n;i++){
            cin>>l;
            push(&head, l);
        }
        printf("%d\n",GetNth(head,n-k));
        getchar();
    }

    return 0;
}

int GetNth(struct node* head,int index){
    int current = 0;
    struct node* current_node = head;
    while(current<index){
        current_node = current_node->next;
        current++;
    }
    return current_node->data;
}