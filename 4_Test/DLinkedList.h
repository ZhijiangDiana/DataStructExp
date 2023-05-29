#pragma once
#ifndef XIANBEI_DLINKEDLIST_H
#define XIANBEI_DLINKEDLIST_H
#include "iostream"
#include "exception"

template<typename T>
struct DNode{
    T data;
    DNode<T> *previous=NULL;
    DNode<T> *next=NULL;
};

template<typename T>
class DLinkedList {
public:
    int length;
    DLinkedList(){ //构造函数
        length=0;
        first=new DNode<T>;
    }
    ~DLinkedList(){ //析构函数
        clear();
        if(first!=NULL){
            delete first;
            first=NULL;
        }
    }
    void print(){  //打印链表数据
        DNode<T> *thisElem;
        thisElem=first->next;
        while(thisElem!=NULL){
            std::cout<<thisElem->data<<" ";
            thisElem=thisElem->next;
        }
        std::cout<<std::endl;
    }
    bool add(int position,T &insertData){  //后插操作
        if(position>length||position<=0){
            return false;
        }
        DNode<T> *thisElem=first;
        for(int i=0;i<position;i++){
            thisElem=thisElem->next;
        }
        DNode<T> *insertElem=new DNode<T>;
        insertElem->data=insertData;
        insertElem->previous=thisElem;
        insertElem->next=thisElem->next;
        thisElem->next=insertElem;
        if(position==length){
            thisElem->next->previous=insertElem;
        }
        length++;
        return true;
    }
    bool add(T insertData){  //尾插操作
        DNode<T> *thisElem=first;
        for(int i=0;i<length;i++){
            thisElem=thisElem->next;
        }
        DNode<T> *insertElem=new DNode<T>;
        insertElem->data=insertData;
        thisElem->next=insertElem;
        insertElem->previous=thisElem;
        length++;
        return true;
    }
    bool remove(int position){  //给定位置删除
        if(position>length||length==0||position<=0){
            return false;
        }
        DNode<T> *delElem=first;
        for(int i=0;i<position;i++){
            delElem=delElem->next;
        }
        if(position==length){
            DNode<T> *previousElem=delElem->previous;
            delete delElem;
            previousElem->next=NULL;
        }else{
            DNode<T> *nextElem=delElem->next;
            DNode<T> *previousElem=delElem->previous;
            delete delElem;
            previousElem->next=nextElem;
            nextElem->previous=previousElem;
        }
        length--;
        return true;
    }
    bool replace(int position,T &insertData){  //给定位置修改值
        if(position>length||length==0||position<=0){
            return false;
        }
        DNode<T> *replaceElem=first;
        for(int i=0;i<position;i++){
            replaceElem=replaceElem->next;
        }
        replaceElem->data=insertData;
        return true;
    }
    bool isEmpty(){  //判空
        if(length==0){
            return true;
        }else{
            return false;
        }
    }
    bool clear(){  //清空链表
        if(length==0){
            return false;
        }
        DNode<T> *delElem=first;
        while(delElem->next!=NULL){
            delElem=delElem->next;
        }
        while(delElem->previous!=NULL){
            delElem=delElem->previous;
            delete delElem->next;
        }
        delElem->next=NULL;
        length=0;
        return true;
    }
    T get(int position){
        DNode<T> *getElem=first;
        if(position>length||length==0||position<=0){
            throw std::runtime_error("IndexOutOfBounds");
        }
        for(int i=0;i<position;i++){
            getElem=getElem->next;
        }
        return getElem->data;
    }

private:
    DNode<T> *first;
};


#endif //XIANBEI_DLINKEDLIST_H
