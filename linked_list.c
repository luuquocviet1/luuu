#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct slinklist {
    int data;
    struct slinklist *next;
};
typedef struct slinklist node;

node *start = NULL;

int menu() {
    int ch;
    printf("\n 1.Create a list.");
    printf("\n ----------------------------");
    printf("\n 2.Insert a node at beginning.");
    printf("\n 3.Insert a node at end.");
    printf("\n 4.Insert a node at middle.");
    printf("\n ----------------------------");
    printf("\n 5.Delete a node at beginning.");
    printf("\n 6.Delete a node a end.");
    printf("\n 7.Delete a node at middle.");
    printf("\n ----------------------------");
    printf("\n 8.Traverse the list (L -> R): ");
    printf("\n 9.Traverse the list (R -> L): ");
    printf("\n ----------------------------");
    printf("\n 10.Count node.");
    printf("\n 11.Exit");
    printf("\n\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

node* getnode() {
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter yout data: "); scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

int countnode(node *ptr) {
    int count = 0;
    while(ptr != 0) {
        count ++;
        ptr = ptr->next;
    }
    return count;
}

void createlist(int n) {
    int i;
    node *newnode;
    node *temp;
    for(i = 0 ; i < n ; i++) {
        newnode = getnode();
        if(start == NULL) {
            start = newnode;
        } else {
            temp = start;
            while(temp -> next != NULL) 
                temp = temp ->next;
            temp -> next = newnode;
            
        }
    }
}

void insert_at_beg() {
    node *newnode;
    newnode = getnode();
    if(start == NULL) {
        start = newnode;
    } else {
        newnode->next = start;
        start = newnode;
    }
}

void insert_at_mid() {
    node *newnode,*temp,*prev;
    int pos, nodectr, ctr = 1;
    newnode = getnode();
    printf("Enter your position: "); scanf("%d", &pos);
    nodectr = countnode(start);
    if (pos > 1 && pos < nodectr) {
        temp = prev = start;
        while(ctr < pos) {
            prev = temp;
            temp = temp ->next;
            ctr++;
        }
        prev->next = newnode;
        newnode->next = temp;
    } else {
        printf("position %d is not exist.", pos);
    }
}

void insert_at_end() {
    node *newnode,*temp;
    newnode = getnode();
    if(start == NULL) {
        start = newnode;
    } else {
        temp = start;
    while( temp->next != NULL) {
            temp = temp->next;
        }
    temp ->next = newnode;
    }
}

void delete_at_beg() {
    node *temp;
    if(start ==NULL) {
        printf("\n No exist.");
        return;
    } else {
        temp = start;
        start = temp ->next;
        free(temp);
        printf("/n Node deleted.");
    }
}

void delete_at_end() {
    node *temp,*prev;
    if(start == NULL) {
        printf("\n No exist.");
        return;
    } else {
        temp = prev = start;
        while(temp ->next != NULL) {
            prev = temp;
            temp = temp -> next;
        }
        free(temp);
        prev->next = NULL;
        printf("\n Node deleted.");
    }
}

void delete_at_mid() {
    node *temp, *prev;
    int pos, nodectr, ctr = 1;
    if(start == NULL) {
        printf("No exist.");
        return;
    } else {
        printf("Enter your position: ");scanf("%d", &pos);
        nodectr = countnode(start); 
        if(pos > nodectr) {
            printf("\n This node not exist.");
        }
        if (pos > 1 && pos < nodectr) {
            temp = prev = start;
            while(ctr < pos) {
                ctr++;
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            free(temp);
            printf("Node deleted.");
        } else {
        printf("\n Invalid position..");
        getch();
    }
    }
}

void traverse() {
    node *temp;
    temp = start;
    printf("\n The contents of List (L->R)\n");
    if(start == NULL) {
        printf("Empty.");
        return;
    } else {
        while(temp != NULL) {
            printf("%d-->", temp->data);
            temp = temp-> next;
        }
    }
    printf("X");
}

void rev_traverse(node *start) {
    if(start == NULL) {
        return;
    } else {
        rev_traverse(start->next);
        printf("%d->",start->data);
    }
}

int main() {
    int ch,n;
    while(1) {
        ch = menu();
        switch(ch) {
            case 1:
                if(start == NULL) {
                    printf("\nEnter n:"); scanf("%d", &n);
                    createlist(n);
                    printf("\n List created..");
                }
                else
                    printf("\n List is already created..");
                    break;
            case 2:
                insert_at_beg();
                break;
            case 3:
                insert_at_mid();
                break;
            case 4:
                insert_at_end();
                break;
            case 5:
                delete_at_beg();
                break;
            case 6:
                delete_at_end();
                break;
            case 7:
                delete_at_mid();
                break;
            case 8:
                traverse();
                break;
            case 9:
                printf("\n The contents of List (R-> L): \n");
                rev_traverse(start);
                printf("X");
                break;
            case 10:
                printf("\n No of nodes : %d ", countnode(start));
                break;
            case 11 :
                exit(0);
        }
        getch();
}
}
