#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *circle_create(int n);
void count_off(Node *head, int n, int k, int m);

int main() 
{
    int n, k, m;
    
    scanf("%d%d%d", &n, &k, &m);
    Node *head = circle_create(n);
    count_off(head, n, k, m);
    
    return 0;
}

Node *circle_create(int n) 
{
    Node *temp, *new_node, *head;
    int i;

    temp = (Node *) malloc(sizeof(Node));
    head = temp;
    head->data = 1;

    for(i = 2; i <= n; i++) {
        new_node = (Node *) malloc(sizeof(Node));
        new_node->data = i;
        temp->next = new_node;
        temp = new_node;
    }

    temp->next = head;

    return head;
}

void count_off(Node *head, int n, int k, int m) 
{
    Node *temp, *pre, *free1;
    int i = 1;
    int times;
    times = 1;
    temp = head;
    pre = head;
    
    if (k == 1) {
        for (i = 1; i < n; i++) {
            pre = pre->next;
        }
            pre =head;
     
    } else {
        for (i = 1; i < k - 1; i++) {
            pre = pre->next;
        }
    }
    
    temp = pre->next;
    i = 1;
    
    while(times <= n) {
        if (m == 1) {
            if (times == n ) {
                printf("%d", pre -> data);
            } else {
                printf("%d ", pre -> data);
            }
            pre = pre -> next;
           // free(pre);
            times++;
        } else if(i == m) {
            printf("%d", temp->data);
            times++;
            pre->next = temp->next;
            free1  =temp;
            temp = temp->next;
            free(free1);
            if(times != 1 + n) {
                printf(" ");
            }
            i=1;
        }
        pre = temp;
        temp = temp->next;
        i++;
    }

    return;
}
