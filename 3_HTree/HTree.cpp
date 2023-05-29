#include "iostream"
using namespace std;


struct Node{
    int id=-1;
    int weight;
    char ch;
    int parents=-1;
    int l=-1;
    int r=-1;
};
void dfs(Node NTree[],int thisNode,string code);

int main(){
    int n;
    cin>>n;
    Node NTree[2*n-1];
    for(int i=0;i<n;i++){
        char thisChar;
        int weight;
        cin>>thisChar>>weight;
        NTree[i].id=i;
        NTree[i].ch=thisChar;
        NTree[i].weight=weight;
    }
    for(int cnt=n;cnt<2*n-1;cnt++){
        int min1Position=114514;  //找到剩余根节点的两个最小的权重
        int min1Weight=114514;
        int min2Position=1145141919;
        int min2Weight=1145141919;
        for(int i=0;i<cnt;i++){
            if(NTree[i].parents==-1){
                int thisPosition=i;
                int thisWeight=NTree[i].weight;
                if(thisWeight<min1Weight){
                    min2Position=min1Position;
                    min2Weight=min1Weight;
                    min1Position=thisPosition;
                    min1Weight=thisWeight;
                }else if(thisWeight<min2Weight){
                    min2Position=thisPosition;
                    min2Weight=thisWeight;
                }
            }
        }

        //合并两个节点
        NTree[min1Position].parents=cnt;
        NTree[min2Position].parents=cnt;
        NTree[cnt].weight=min1Weight+min2Weight;
        NTree[cnt].l=min1Position;
        NTree[cnt].r=min2Position;

        cout<<"当前剩余根节点的权重：";
        for(int i=0;i<=cnt;i++){
            if(NTree[i].parents==-1){
                cout<<NTree[i].weight<<" ";
            }
        }
        cout<<endl;

    }

    cout<<endl;
    dfs(NTree,2*n-2,"");
}

void dfs(Node NTree[],int thisPosition,string code){
    Node thisNode=NTree[thisPosition];
    if(thisNode.l==-1&&thisNode.r==-1){
        cout<<thisNode.ch<<" -> "<<code<<endl;
        return;
    }
    dfs(NTree,thisNode.l,code+"1");
    dfs(NTree,thisNode.r,code+"0");
}