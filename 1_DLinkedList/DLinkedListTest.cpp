#include "iostream"
#include "string"
#include "DLinkedList.h"
#include "windows.h"
#include "fstream"
using namespace std;

class Person{
public:
    string name;
    string road;
    string city;
    string nation;
    string phone;
    Person(){};
    Person(string name,string road,string city,string nation,string phone){
        this->name=name;
        this->road=road;
        this->city=city;
        this->nation=nation;
        this->phone=phone;
    }
};

DLinkedList<Person> d;

void Menu(){
    cout<<"____________________________________________________________"<<endl;
    cout<<"欢迎进入通讯录管理系统！"<<endl;
    cout<<"1、输入信息"<<endl;
    cout<<"2、显示信息"<<endl;
    cout<<"3、按姓名查找人"<<endl;
    cout<<"4、删除信息"<<endl;
    cout<<"5、信息存储到磁盘"<<endl;
    cout<<"6、信息从文件导入"<<endl;
    cout<<"7、退出系统"<<endl;
    cout<<"8、清空所有数据"<<endl;
    cout<<"____________________________________________________________"<<endl;
}
void Input(){
    cout<<"____________________________________________________________"<<endl;
    cout<<"请输入姓名，街道，城市，国家，电话号码，用空格键分隔"<<endl;
    cout<<"请输入信息："<<endl;
    string name,road,city,nation,phone;
    cin>>name>>road>>city>>nation>>phone;
    Person p=*new Person(name,road,city,nation,phone);
    bool isRepeat=false;
    for(int i=1;i<=d.length;i++){
        Person p1=d.get(i);
        if(p1.name==p.name){
            isRepeat=true;
            break;
        }
    }
    if(isRepeat){
        cout<<"同名记录已存在"<<endl;
    }else{
        d.add(p);
        cout<<"添加成功！"<<endl;
    }
    cout<<"____________________________________________________________"<<endl;
    Sleep(1000);
    system("cls");
    Sleep(300);
}
void PrintAll(){
    cout<<"____________________________________________________________"<<endl;
    cout<<"姓名          街道          城市          国家          手机号          "<<endl;
    for(int i=1;i<=d.length;i++){
        Person p=d.get(i);
        printf("%-14s%-14s%-14s%-14s%-14s\n",p.name.c_str(),p.road.c_str(),p.city.c_str(),p.nation.c_str(),p.phone.c_str());
    }
    cout<<"____________________________________________________________"<<endl;
    system("pause");
}
void Search(){
    cout<<"____________________________________________________________"<<endl;
    cout<<"请输入要查询的姓名"<<endl;
    string name;
    cin>>name;
    bool find=false;
    Person p;
    for(int i=1;i<=d.length;i++){
        p=d.get(i);
        if(name==p.name){
            find=true;
            break;
        }
    }
    if(find){
        cout<<"您是不是要找："<<endl;
        cout<<"姓名："<<p.name<<endl;
        cout<<"街道："<<p.road<<endl;
        cout<<"城市："<<p.city<<endl;
        cout<<"国家："<<p.nation<<endl;
        cout<<"手机号："<<p.phone<<endl;
        cout<<"____________________________________________________________"<<endl;
        system("pause");
    }else{
        cout<<"您要找的人不存在"<<endl;
        Sleep(3000);
    }
}
void Delete(){
    cout<<"____________________________________________________________"<<endl;
    cout<<"请输入要删除的姓名"<<endl;
    string name;
    cin>>name;
    bool find=false;
    Person p;
    int position=0;
    for(int i=1;i<=d.length;i++){
        p=d.get(i);
        if(name==p.name){
            find=true;
            position=i;
            break;
        }
    }
    if(find){
        cout<<"您是不是要删除："<<endl;
        cout<<"姓名："<<p.name<<endl;
        cout<<"街道："<<p.road<<endl;
        cout<<"城市："<<p.city<<endl;
        cout<<"国家："<<p.nation<<endl;
        cout<<"手机号："<<p.phone<<endl;
        cout<<"请再次确认是否删除y(Yes)  其他(No)"<<endl;
        char option;
        cin>>option;
        if(option=='y'){
            d.remove(position);
            cout<<"删除成功！"<<endl;
        }else{
            cout<<"您取消了操作"<<endl;
        }
    }else{
        cout<<"您要删除的人不存在"<<endl;
    }
    cout<<"____________________________________________________________"<<endl;
    system("pause");
}
void Save(){
    cout<<"____________________________________________________________"<<endl;
    ofstream wFile("SavedFile.txt",ios::out);
    if(!wFile){
        cerr<<"文件写入失败，请检查程序写入权限或磁盘坏道!"<<endl;
    }else{
        for(int i=1;i<=d.length;i++){
            Person p=d.get(i);
            wFile<<p.name<<" "<<p.road<<" "<<p.city<<" "<<p.nation<<" "<<p.phone<<endl;
        }
        cout<<"已保存"<<d.length<<"条数据"<<endl;
    }
    system("pause");
}
void InputFromFile(){
    cout<<"____________________________________________________________"<<endl;
    ifstream rFile("SavedFile.txt",ios::in);
    if(!rFile){
        cerr<<"文件读取失败，请检查程序读取权限或磁盘坏道!"<<endl;
    }else{
        int i=0;
        for(;;i++){
            string name;
            string road;
            string city;
            string nation;
            string phone;
            rFile>>name>>road>>city>>nation>>phone;
            if(name==""){
                break;
            }
            Person p(name,road,city,nation,phone);
            d.add(p);
        }
        cout<<"已读取"<<i<<"条记录"<<endl;
        system("pause");
    }
}
void Clear(){
    cout<<"____________________________________________________________"<<endl;
    string confirm1;
    cout<<"您确定要清空所有信息吗? y(YES) 其他(NO)"<<endl;
    cin>>confirm1;
    if(confirm1!="y"){
        cout<<"用户取消操作"<<endl;
        return;
    }
    string confirm2;
    cout<<"\033[33;1m二次确认，您确定要清空所有信息吗? y(YES) 其他(NO)\033[0m"<<endl;
    cin>>confirm2;
    if(confirm1!="y"){
        cout<<"用户取消操作"<<endl;
        return;
    }
    string confirm3;
    cout<<"\033[31;1m最后次确认，您确定要清空所有信息吗? y(YES) 其他(NO)\033[0m"<<endl;
    cin>>confirm3;
    if(confirm1!="y"){
        cout<<"用户取消操作"<<endl;
        return;
    }
    int size=d.length;
    d.clear();
    cout<<"成功清除"<<size<<"条数据"<<endl;
    Sleep(3000);
}
int main(){
    while(true){
        system("cls");
        Menu();
        int choose;
        cin>>choose;
        switch (choose) {
            case 1:
                system("cls");
                Input();
                break;
            case 2:
                system("cls");
                PrintAll();
                break;
            case 3:
                system("cls");
                Search();
                break;
            case 4:
                system("cls");
                Delete();
                break;
            case 5:
                system("cls");
                Save();
                break;
            case 6:
                system("cls");
                InputFromFile();
                break;
            case 7:
                system("cls");
                cout<<"感谢您的使用"<<endl;
                system("pause");
                exit(0);
            case 8:
                system("cls");
                Clear();
                break;
            default:
                system("cls");
                cerr<<"您输入的指令有误，请重新输入"<<endl;
                system("pause");
                break;
        }
    }
}