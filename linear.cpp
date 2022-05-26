#include <iostream>
#define SIZE 20
using namespace std;
class LinearProbing
{
//array based implementation
string name[SIZE],tel[SIZE];
char status[SIZE]; //O,D,E
int n;
public:
LinearProbing()
{
cout<<"\nEnter table size:";
cin>>n;
for(int i=0;i<n;i++)
{
name[i]="";
tel[i]="";
status[i]='E';
}
}
void display();
void insert(string nm,string telno); //declaration
int hashf(string key);
void probeSeq(string,string); //declaration
void search(string);
void probeSearch(string);
};
void LinearProbing::display()
{
cout<<"\nIndex\tClint's Name\tTelephone no\tStatus";
for(int i=0;i<n;i++)
{
cout<<"\n"<<i<<"\t\t"<<name[i]<<"\t\t"<<tel[i]<<"\t"<<
status[i];
}
}
int LinearProbing::hashf(string key)
{
//abc=a+b+c=sum mod tablesize
int asciiSum=0;
for (int i=0;i<key.length();i++)
{
asciiSum+=key[i];
}
return asciiSum % n;
}
void LinearProbing::insert(string nm,string telno)
{
int index=hashf(nm);
cout<<"\nIndex:"<<index;
if(status[index]=='E')
{
name[index]=nm;
tel[index]=telno;
status[index]='O';
}
else
probeSeq(nm,telno); //call
}
void LinearProbing::probeSeq(string nm,string telno )
{
int h0=hashf(nm);
int seq;
for (int i=1;i<n;i++)
{
//hi(x)=(h0+f(i))% tablesize f(i)=i
seq=(h0+i)%n;
if(status[seq]=='E')
{
name[seq]=nm;
tel[seq]=telno;
status[seq]='O';
return;
}
}
}
void LinearProbing::search(string nm)
{
int index=hashf(nm);
cout<<"\nIndex:"<<index;
if(name[index]==nm && status[index]=='O')
{
cout<<"\nRecord found at location :"<<index;
cout<<"\n"<<name[index]<<"->"<<tel[index];
}
else
probeSearch(nm);
}
void LinearProbing::probeSearch(string nm)
{
int h0=hashf(nm);
int seq;
for (int i=1;i<n;i++)
{
//hi(x)=(h0+f(i))% tablesize f(i)=i
seq=(h0+i)%n;
if(name[seq]==nm && status[seq]=='O')
{
cout<<"\nRecord found at location :"<<seq;
cout<<"\n"<<name[seq]<<"->"<<tel[seq];
return;
}
if (status[seq]=='E')
{
cout<<"\nRecord not found";
return ;
}
}
}
int main()
{
LinearProbing obj;
string name,tel;
int ch;
do
{
cout<<"\nMenu\n1. Insert\n2. Display\n3.Search\n4. Exit";
cout<<"\nEnter Your Choice:";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\nEnter Client's Name:";
cin>>name;
cout<<"\nEnter Telephone no.:";
cin>>tel;
obj.insert(name,tel);
break;
case 2:
obj.display();
break;
case 3:
cout<<"\n Enter Client's Name to be searched:";
cin>>name;
obj.search(name);
break;
case 4:
exit(0);
default:
cout<<"\nInvalid choice";
}
}while(ch!=4);
return 0;
}