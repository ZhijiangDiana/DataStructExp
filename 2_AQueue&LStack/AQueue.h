#ifndef XIANBEI_AQUEUE_H
#define XIANBEI_AQUEUE_H

#include "iostream"
#include "exception"

template <typename T>
class AQueue{  //都什么年代了，还用传统顺序队列
private:
    const static int maxLength=20;
    T elem[maxLength];
    int front;
    int rear;

public:
    int length;
    AQueue(){
        front=0;
        rear=0;
        length=0;
    }
    bool push(T insertElem){
        if(isFull()){
            return false;
        }
        elem[rear]=insertElem;
        rear=(rear+1)%maxLength;
        length++;
        return true;
    }
    T pop(){
        T popElem=peek();
        front=(front+1)%maxLength;
        length--;
        return popElem;
    }
    T peek(){
        if(isEmpty()){
            throw std::runtime_error("IndexOutOfBounds");
        }
        return elem[front];
    }
    bool isEmpty(){
        if(length==0){
            return true;
        }else{
            return false;
        }
    }
    bool isFull(){
        if(length==maxLength){
            return true;
        }else{
            return false;
        }
    }
};

#endif //XIANBEI_AQUEUE_H
