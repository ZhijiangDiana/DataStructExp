#include "iostream"
using namespace std;

template<typename T>
struct DNode {
    T data;
    DNode<T> *previous = NULL;
    DNode<T> *next = NULL;
};
template<typename T>
bool add(T insertData,DNode<T> *first){  //尾插操作
    DNode<T> *thisElem=first->previous;
    DNode<T> *insertElem=new DNode<T>;
    insertElem->data=insertData;
    insertElem->previous=thisElem;
    insertElem->next=first;
    thisElem->next=insertElem;
    first->previous=insertElem;
    return true;
}
template<typename T>
T pop(DNode<T> *first){
    T getData=first->previous->data;
    DNode<T> *lastElem=first->previous->previous;
    delete lastElem->next;
    lastElem->next=first;
    first->previous=lastElem;
    return getData;
}

int main(){
    int n;
    cin>>n;
    DNode<int> head1;
    head1.next=&head1;
    head1.previous=&head1;
    for(int i=0;i<n;i++){
        int thisData;
        cin>>thisData;
        add(thisData,&head1);
    }
    DNode<int> head2;
    head2.next=&head2;
    head2.previous=&head2;
    for(int i=0;i<n;i++){
        int data=pop(&head1);
        add(data,&head2);
    }
    DNode<int> *thisElem=head2.next;
    for(int i=0;i<n;i++){
        cout<<thisElem->data<<" ";
        thisElem=thisElem->next;
    }
}