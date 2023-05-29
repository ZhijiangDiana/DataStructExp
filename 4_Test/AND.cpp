#include "iostream"
#include "DLinkedList.h"
using namespace std;

int main(){
    int n,m;
    DLinkedList<int> l1;
    DLinkedList<int> l2;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int thisData;
        cin>>thisData;
        l1.add(thisData);
    }
    for(int i=0;i<m;i++){
        int thisData;
        cin>>thisData;
        l2.add(thisData);
    }
    DLinkedList<int> AND;
    for(int i=1,j=1;i<=n&&j<=m;){
        int thisData1=l1.get(i);
        int thisData2=l2.get(j);
        if(thisData1<thisData2){
            i++;
        }else if(thisData1>thisData2){
            j++;
        }else{
            int equalsData=thisData1;
            AND.add(equalsData);
            while(thisData1==equalsData&&i<=n){
                i++;
                try{
                    thisData1=l1.get(i);
                }catch(runtime_error){
                    break;
                }
            }
            while(thisData2==equalsData&&j<=m){
                j++;
                try{
                    thisData2=l2.get(j);
                }catch(runtime_error){
                    break;
                }
            }
        }
    }
    AND.print();
}
