#include <iostream>

using namespace std;

typedef struct node{
  int data;
  node *next;
}node;

 node *createnode(){
 node *temp=(node *)malloc(sizeof(node));
return temp;
};

void freenode(node *node){
   free(node);
}

void printlist(node *head){
    node *temp;
    temp=head;
    while(temp!=NULL){
        cout<< temp->data << "";
        temp=temp->next;
    }

}

void Search(node *head,int req){
    node *temp;
    temp=head;
    while(temp!=NULL){
        if(temp->data==req)break;
        else temp=temp->next;
    }
    if(temp==NULL)cout << "not found" << '\n';
    else cout << "found"<< '\n';

}

void addstart(node **head,int data){
  node *temp;
  temp=createnode();
  if(temp==NULL)return;
  temp->data=data;
  temp->next=*head;
  *head=temp;
}

void deletestart(node **head){
    node *temp;
    if(*head==NULL)return;
    else{
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}

void deleteend(node **head){
    node *temp,*prev;
    temp=*head;prev=NULL;
    if(temp==NULL) return;
    while(temp->next!=NULL){
        prev=temp;temp=temp->next;
    }
    free(temp);
    if(prev!=NULL)prev->next=NULL;
    else *head=NULL;
}

int length(node **head) {
    int count = 0;
    node *temp = *head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}



int main(){

    node *head=NULL;
    int choice=1,x;
    while(choice){
        cout << "1. Insert at head\n";
        cout << "2. Delete at head\n";
        cout << "3. Delete at tail\n";
        cout << "4. Length of Linked List\n";
        cout << "5. Print Linked List\n";
        cout << "6. Search for a value in linked list\n";
        cout << "0.Exit\n";
        cout << "enter your choice\n";
        cin >> choice;

        switch(choice){
        case 0:
            break;
        case 1:
            cout << "enter a value to insert";
            cin >> x;
            addstart(&head,x);
            break;
        case 2:
            deletestart(&head);
        
        case 3:
            deleteend(&head);
            break;
        case 4:
            cout << length(&head) << '\n';
            break;
        case 5:
            printlist(head);
            break;
        case 6:
            cout << "enter a value to search\n";
            cin >> x;
            Search(head,x);
            break;
        default:
            cout << "enter a valid choice\n";

        }
        cout << '\n';

    }

return 0;

}
