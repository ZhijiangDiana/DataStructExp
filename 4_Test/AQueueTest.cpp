#include "AQueue.h"
#include "iostream"
using namespace std;

int main(){
    int n;
    cin>>n;
    AQueue<int> queue;
    for(int i=0;i<n;i++){
        int thisData;
        cin>>thisData;
        queue.enqueue(thisData);
    }
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    //找到front指针：
    cout<<queue.getFront()<<endl;
    //队空条件：length==0
    cout<<queue.isEmpty()<<endl;
    //队满条件：length==maxLength
    cout<<queue.isFull()<<endl;
}