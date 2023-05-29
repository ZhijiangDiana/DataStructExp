#pragma once
#ifndef XIANBEI_LSTACK_H
#define XIANBEI_LSTACK_H
#include "iostream"
#include "exception"

template <typename T>
struct SNode{
    T data;
    SNode<T> *next;
    SNode<T> *previous;
};

template <typename T>
class LStack{
public:
    int length;
    LStack(){
        length=0;
        first=new SNode<T>;
        first->next=first;
        first->previous=first;
        rear=first;
    }
    ~LStack(){
        clear();
        if(first!=NULL){
            delete first;
            first=NULL;
        }
    }
    bool isEmpty(){
        if(length==0){
            return true;
        }else{
            return false;
        }
    }
    void push(T insertData){
        SNode<T> *thisElem=new SNode<T>;
        thisElem->data=insertData;
        thisElem->previous=rear;
        thisElem->next=first;
        rear->next=thisElem;
        first->previous=thisElem;
        rear=thisElem;
        length++;
    }
    T peek(){
        if(length==0){
            throw std::runtime_error("IndexOutOfBounds");
        }
        return rear->data;
    }
    T pop(){
        if(length==0){
            throw std::runtime_error("IndexOutOfBounds");
        }
        SNode<T> *popElem=rear;
        T popData=rear->data;
        rear=popElem->previous;
        rear->next=first;
        first->previous=rear;
        delete popElem;
        length--;
        return popData;
    }
    bool clear(){
        if(length==0){
            return false;
        }
        for(int i=0;i<length;i++){
            rear=rear->previous;
            delete rear->next;
        }
        first->next=first;
        first->previous=first;
        length=0;
        return true;
    }

private:
    SNode<T> *first;
    SNode<T> *rear;
};

#endif //XIANBEI_LSTACK_H
