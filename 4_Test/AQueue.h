#ifndef XIANBEI_AQUEUE_H
#define XIANBEI_AQUEUE_H

#include "iostream"
#include "exception"

template <typename T>
class AQueue{  //都什么年代了，还用传统顺序队列
private:
    const static int maxLength=5;
    T elem[maxLength];
    int rear;

public:
    int length;
    AQueue(){
        rear=0;
        length=0;
    }
    int getFront(){
        return (rear-length+maxLength)%maxLength;
    }
    bool enqueue(T insertElem){
        if(isFull()){
            return false;
        }
        elem[rear]=insertElem;
        rear=(rear+1)%maxLength;
        length++;
        return true;
    }
    T dequeue(){
        T popElem=peek();
        length--;
        int front=getFront();
        return popElem;
    }
    T peek(){
        if(isEmpty()){
            throw std::runtime_error("IndexOutOfBounds");
        }
        return elem[getFront()];
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
