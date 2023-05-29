#include "iostream"
#include "AQueue.h"
using namespace std;

int main(){
    AQueue<int> queue;
    for(int i=1;;i++){
        queue.push(i);
        if(queue.isFull()){
            while(!queue.isEmpty()){
                cout<<queue.pop()<<"#";
            }
            break;
        }else{
            queue.push(++i);
        }
        if(queue.isFull()){
            while(!queue.isEmpty()){
                cout<<queue.pop()<<"#";
            }
            break;
        }else{
            cout<<queue.pop()<<"*";
        }
    }
}