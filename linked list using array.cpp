#include<bits/stdc++.h>
using namespace std;
#define Max 100
struct Element{
int num;
string data;
};
struct List{
    Element arr[Max];
     int size;
};
void create(List*l){
    l->size=0;
}
void Add(int index, Element e,List* l){
    if(index<0 || index>Max-1){
        cout<<"In valid index";
        return;
    }
    else if(index>l->size){
        cout<<"List is Full";
        return ;
    }
    else{
        for(int i=l->size-1;i>=index;i--){
            l->arr[i+1]=l->arr[i];
        }
        l->arr[index]=e;
        l->size++;
    }
}
void remove(List* l,int index){
    if(index<0 || index>Max-1){
        cout<<"In valid index";
        return;
    }
    else if(l->size==0){
        cout<<"List is empty";
        return ;
    }
    else{
        for(int i=index;i<l->size-1;i++){
            l->arr[i]=l->arr[i+1];
        }
        l->size--;
    }
}
int wasize(List* l){
    return l->size;
}
bool isEmpty(List* l){
    return l->size==0;
}
Element Get(List* l,int index){
    if(index<0 || index>Max-1){
        cout<<"In valid index";
        return {0,"NULL"};
    }
    else{
       return l->arr[index];
    }
}
Element  End(List* l){
    if(isEmpty(l)){
        cout<<"List is empty";
        return {0,"NULL"};
    }
    return l->arr[l->size-1];
}
Element  Start(List* l){
     if(isEmpty(l)){
        cout<<"List is empty";
        return {0,"NULL"};
    }
    return l->arr[0];
}
int main(){
    List l;
    create(&l);
    Add(0,{1,"Afzaal"},&l);
    Add(1,{2,"UBAIDULLAH"},&l);
    Add(2,{1,"SIKANDAR"},&l);
    Add(3,{1,"HAROON"},&l);
    Element e=Get(&l,2);
    cout<<e.data<<endl;
    cout<<e.num<<endl;
    remove(&l,2);
   cout<<wasize(&l)<<endl;
   cout<<isEmpty(&l);
   Element e1=End(&l);
   cout<<e1.data<<endl;
   cout<<e1.num<<endl;
   Element e2=Start(&l);
 cout<<e2.data<<endl;
 cout<<e2.num<<endl;
}
