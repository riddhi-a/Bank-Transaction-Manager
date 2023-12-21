#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node1{
    public:
    unsigned int accno;
    int balance;
    Node1* next;
    Node1()
    {
        balance=1000;
        accno=0;
        next=nullptr;
    }
    Node1(unsigned int acc)
    {
        balance=1000;
        accno=acc;
        next=nullptr;
    }
};
class SLL{
    private:
    Node1* first;
    Node1* last;
    int len;
    public:
    SLL()
    {
        first=nullptr;
        last=nullptr;
        len=0;
    }
    void insertNode1(unsigned int);
    bool isThere(unsigned int);
    Node1* getloc1(unsigned int);
    void ftransac(unsigned int,char,int);
    void rtransac(unsigned int,char,int);
    int processG(int);
    void processM();
    void processV(unsigned int);
    //void printList1();
};
/*void SLL::printList1()
{
    Node1* temp =first;
    while(temp!=nullptr)
    {
        cout<<temp->accno<<" "<<temp->balance<<"\n";
        temp=temp->next;
    }
}*/
void SLL::insertNode1(unsigned int acc)
{
    Node1* toAdd=new Node1(acc);
    if(first==nullptr)
    {
        first=toAdd;
    }
    else
    {
        Node1* temp=first;
        while(temp->next!=nullptr)
            temp=temp->next;
        temp->next=toAdd;
    }
    len++;
}
void SLL::ftransac(unsigned int acc,char T,int X)
{
    Node1* temp=first;
    if(T=='W')
    {
        X=-X;
    }
    while(temp!=nullptr)
    {
        if(temp->accno == acc)
        {temp->balance+=X;return;}
        temp=temp->next;
    }
}
void SLL::rtransac(unsigned int acc,char T,int X)
{
    Node1* temp=first;
    if(T=='D')
    {
        X=-X;
    }
    while(temp!=nullptr)
    {
        if(temp->accno == acc)
        {temp->balance+=X;return;}
        temp=temp->next;
    }
}
bool SLL::isThere(unsigned int acc)
{
    Node1* temp=first;
    while(temp!=nullptr)
    {
        if(temp->accno == acc)
            return true;
        temp=temp->next;
    }
    return false;
}
int SLL::processG(int X)
{
    Node1* temp=first;
    int c=0;
    while(temp!=nullptr)
    {
        if((temp->balance)>=X)
        {c++;}
        temp=temp->next;
    }
    return c;
}
void SLL::processM()
{
    Node1* temp=first;
    int arr[len]={0};
    int c=0;
    int max=first->balance;
    while(temp!=nullptr)
    {
        if(temp->balance>max)
        {max=temp->balance;}
        temp=temp->next;
    }
    temp=first;
    while(temp!=nullptr)
    {
        if(temp->balance==max)
        {arr[c++]=temp->accno;}
        temp=temp->next;
    }
    for(int i=0;i<c;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void SLL::processV(unsigned int X)
{
    Node1* temp=first;
    while(temp!=nullptr)
    {
        if(temp->accno==X)
        {cout<<temp->balance<<"\n";
        return;}
        temp=temp->next;
    }
    
}
/*Node1* SLL::getloc1(unsigned int acc)
{
    Node1* temp=first;
    while(temp!=nullptr)
    {
        if(temp->accno == acc)
            return temp;
        temp=temp->next;
    }
    
}*/
class Node2{
    private:
    unsigned int accno;
    char Type;
    int amount;
    Node2* next;
    Node2* prev;
    //Node1* detail;
    Node2()
    {
        accno=0;
        amount=0;
        Type='\0';
        next=nullptr;
        prev=nullptr;
        //detail=nullptr;
    }
    public:
    Node2(unsigned int acc,char T,int amt)
    {
        accno=acc;
        amount=amt;
        Type=T;
        next=nullptr;
        prev=nullptr;
        //detail= getloc1(acc);
    }
    friend class DLL;
};
class DLL{
    private:
    Node2* head;
    Node2* tail;
    int len;
    Node2* cursor;
    int cursint;
    public:
    DLL()
    {
        head=new Node2();
        tail=new Node2();
        head->next=tail;
        tail->prev=head;
        cursor=head;
        cursint=0;
        len=0;
    }
    void insertNode2(unsigned int,char,int);
    void processF(int,SLL&);
    void processR(int,SLL&);
    void processI(int,Node2*,SLL&);
    void processS(unsigned int);
    void processD(unsigned int,int,SLL&);
    int getLen();
    //void printList2();
};
/*void DLL::printList2()
{
    Node2* temp =head->next;
    while(temp!=tail)
    {
        cout<<temp->accno<<" "<<temp->Type<<" "<<temp->amount<<"\n";
        temp=temp->next;
    }
}*/
void DLL::processF(int n,SLL& accountDet)
{
    Node2* temp=cursor->next;
    while(temp!=tail && n>0)
    { 
        accountDet.ftransac(temp->accno,temp->Type,temp->amount);
        temp=temp->next;
        n--;
        cursor=cursor->next;
        cursint++;
    }
}
void DLL::processR(int n,SLL& accountDet)
{
    Node2* temp=cursor;
    while(temp!=head && n>0)
    {   
        accountDet.rtransac(temp->accno,temp->Type,temp->amount);
        temp=temp->prev;
        n--;
        cursor=cursor->prev;
        cursint--;
    }
}
void DLL::processI(int k,Node2* toAdd,SLL& accountDet)
{
    if(k<1 || k>len)
        return;
    //Node2* temp=head->next;
    Node2* temp=head;
    int f=0;
    for(int i=0;i<k;i++)
    {
        temp=temp->next;
        if(temp==cursor)
            f=5;
    }
    
    len++;
    toAdd->next=temp->next;
    toAdd->prev=temp;
    temp->next=toAdd;
    (toAdd->next)->prev=toAdd;
    if(f==0)
        accountDet.ftransac(toAdd->accno,toAdd->Type,toAdd->amount);
   /* while(k>1)
    {
        temp=temp->next;
        k--;
    }
    len++;
    toAdd->next=temp->next;
    toAdd->prev=temp;
    temp->next=toAdd;
    (toAdd->next)->prev=toAdd;
    if(cursint>k)
    {
        accountDet.ftransac(toAdd->accno,toAdd->Type,toAdd->amount);
        k=k+1;
    }*/
    
}
void DLL::processS(unsigned int Y)
{
    Node2* temp=head->next;
    while(temp!=cursor->next)
    { 
        if(temp->accno==Y)
        {
            cout<<temp->accno<<" "<<temp->Type<<" "<<temp->amount<<"\n";
        }
        temp=temp->next;
    }
}
void DLL::processD(unsigned int A,int M,SLL& accountDet)
{
    if(M>0)
    {
        Node2* temp1=cursor->next;
        Node2* temp=cursor->next;
        while(M>0 && temp!=tail)
        {
            if(temp->accno==A)
            {
                (temp->next)->prev=temp->prev;
                (temp->prev)->next=temp->next;
                temp1=temp;
                delete temp1;
                M--;
            }
            temp=temp->next;
            
        }
    }
    else
    {
        M=-M;
        Node2* temp1=cursor->prev;
        Node2* temp=cursor->prev;
        while(M>0 && temp!=head)
        {
            if(temp->accno==A)
            {
                (temp->next)->prev=temp->prev;
                (temp->prev)->next=temp->next;
                temp1=temp;
                accountDet.rtransac(temp->accno,temp->Type,temp->amount);
                delete temp1;
                M--;
            }
            temp=temp->prev;
            
        }
    }
}
void DLL::insertNode2(unsigned int acc,char T,int amt)
{
    Node2* toAdd=new Node2(acc,T,amt);
    Node2* temp=tail->prev;
    temp->next=toAdd;
    toAdd->prev=temp;
    toAdd->next=tail;
    tail->prev=toAdd;
    len++;
}
int DLL::getLen()
{
    return len;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int C;
    cin>>C;
    unsigned int acc;
    SLL accountDet;
    DLL transaction;
    for(int i=0;i<C;i++)
    {
        cin>>acc;
        accountDet.insertNode1(acc);
    }
    int N;
    char T;
    int amt;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>acc;
        if(accountDet.isThere(acc))
        {
            cin>>T>>amt;
            transaction.insertNode2(acc,T,amt);
        }
    }
    //accountDet.printList1();
    //transaction.printList2();
    string s;
    cin>>s;
    while(s!="END")
    {
        //cout<<s<<"."<<"\n";
        if(s=="F")
        {
            int x;
            cin>>x;
            transaction.processF(x,accountDet);
        }
        else if(s=="R")
        {
            int y;
            cin>>y;
            transaction.processR(y,accountDet);
        }
        else if(s=="I")
        {
             unsigned int accno;
             char Type;
             int amount;
            int k;
            cin>>accno>>Type>>amount;
            Node2* toAdd=new Node2(accno,Type,amount);
            cin>>k;
            transaction.processI(k,toAdd,accountDet);
        }
        else if(s=="D")
        {
            unsigned int A;int M;
            cin>>A>>M;
            transaction.processD(A,M,accountDet);
        }
        else if(s=="C")
        {
            transaction.processF(transaction.getLen(),accountDet);
        }
        else if(s=="S")
        {
            unsigned int Y;
            cin>>Y;
            transaction.processS(Y);
        }
        else if(s=="G")
        {
            int x;
            cin>>x;
            cout<<accountDet.processG(x)<<"\n";
        }
        else if(s=="M")
        {
            accountDet.processM();
        }
        else if(s=="V")
        {
            unsigned int X;
            cin>>X;
            accountDet.processV(X);
        }
        cin>>s;
    }
    return 0;
}
