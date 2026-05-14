#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *next;
};
Node *createNode(int value){
    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
Node *getNode(Node* head,int index){
    while(head && index--){
        head=head->next;
    }
    return head;

}
void insert(Node **head,int value,int pos){
    if (pos==0){
        Node* newNode=createNode(value);
        newNode->next=*head;
        *head=newNode;
    }
    else{
        Node* newNode=createNode(value);
        Node* prev=getNode(*head,pos-1);
        newNode->next=prev->next;
        prev->next=newNode;
    }
    cout<<"Added"<<endl;
}
void delete_at(Node**head,int pos){
    if(!*head){
        cout<<"list is empty";
        return;
    }
    if(pos==0){
        Node*temp=*head;
        *head=(*head)->next;//*head=temp->next;
        delete temp;
    }
    else{
        Node*prev=getNode(*head,pos-1);
        Node* temp=prev->next;
        prev->next=temp->next;
        delete temp;
    }
    cout<<"Deleted";
}
void search(Node*head,int key)
{
int index=0;
while(head){
    if(key==head->data){
        cout<<"Key found at index"<<endl;
        return;
    }
    index++;
    head=head->next;
}
cout<<"Key not found"<<endl;

}
int size(Node* head){
    int count=0;
    while(head){
        head=head->next;
        count++;
    }
return count;
}
void emptylist(Node** head){
    while(*head){
        Node* temp=*head;
        *head=(*head)->next;
        delete temp;
    }
    cout<<"List Deleted";
}
void print(Node *head){
    if(!head){
        cout<<"empty"<<endl;
        return;
    }
    int nodecount=0;
    while(head){
        cout<<"data in Node"<<nodecount<<" is"<<head->data;
        cout<<endl;
        head=head->next;
        nodecount++;
    }
    cout<<"Null"<<endl;
}
int main(){
	int n=1;
	Node* head=NULL;
	insert(&head,3,0);
		insert(&head,3,1);
    insert(&head,4,size(head));
    insert(&head,5,n);
    delete_at(&head,0);
    delete_at(&head,size(head)-1);
      delete_at(&head,n);
      search(head,4);
      emptylist(&head);
      cout<<size(head);
		
}
