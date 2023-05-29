#include "iostream"
#define MAXN 114514
#define MINN -114514
using namespace std;

class Node{
public:
    int id;
    int data;
    int l=-1;
    int r=-1;
    Node(int id,int data,int l,int r){
        this->data=data;
        this->id=id;
        this->l=l;
        this->r=r;
    }
    Node(){}
};
int mid[MAXN];
bool isFill[MAXN];
int cnt=0;
Node sTree[MAXN];

void dfs(int thisPosition){
    Node thisNode=sTree[thisPosition];
    if(thisNode.l!=-1){
        dfs(thisNode.l);
    }
    mid[cnt]=thisNode.data;
    isFill[cnt]=true;
    cnt++;
    if(thisNode.r!=-1){
        dfs(thisNode.r);
    }
}

int main(){
    for(int i=0;i<MAXN;i++){
        isFill[i]=false;
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int data,l,r;
        cin>>data>>l>>r;
        sTree[i]=Node(i,data,l,r);
    }
    dfs(1);
    bool isSearchTree=true;
    for(int i=1;i<MAXN;i++){
        if(isFill[i]){
            if(mid[i]<=mid[i-1]){
                isSearchTree=false;
                break;
            }
        }
    }
    if(isSearchTree){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }

}

/*
8
53 2 3
17 4 5
78 6 7
9 -1 -1
45 8 -1
65 -1 -1
87 -1 -1
23 -1 -1
 */