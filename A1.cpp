#include<iostream>
using namespace std;
class SetOp
{
int a[10]={0},n;
public:
SetOp()
{
n=5;
}
void add();
void display();
int contains(int);
void size();
void union_set(SetOp);
void intersection_set(SetOp);
void difference_set(SetOp);
void subset(SetOp);
void remove(int);
};
void SetOp::add() //defination
{
int value,i;
cout<<"\n Enter no of elements: ";
cin>>n;
for(i=0;i<n;)
{
cout<<"\n Enter elements: ";
cin>>value;
if(contains(value)==-1) //10 10 10 20 i=20
{
a[i]=value;
i++;
}
else
cout<<"\n Elements is already exist";
}
}
void SetOp::display()
{
for(int i=0;i<n;i++)
{
cout<<"\n"<<a[i];
}
}
int SetOp::contains(int val)
{
for(int i=0;i<n;i++)
{
if(a[i]==val)
return i;
}
return -1;
}
void SetOp::remove(int val) //this->1 2 3 4 val=5/ val=2
{
if(this->contains(val)==-1) //return index
cout<<"\n"<<val<<"does not exist";
else //this->1 3 4
{
int index=contains(val);
while(index<n)
{
a[index]=a[index+1]; //a[1]=a[2]
index++;
}
n--;
}
}
void SetOp::union_set(SetOp S2) //this={1 2 3 4} S2={1 3 5 7} i->result={1,2,3,4,5,7}
{
cout<<"\n Enter second set:";
S2.add();
SetOp result;
int i,j;
for(i=0;i<n;i++)
result.a[i]=this->a[i];
for(j=0;j<S2.n;j++)
{
if (this->contains(S2.a[j])==-1) //-1->not exists, index i->exits
{
result.a[i]=S2.a[j];
i++;
}
}
cout<<"\n union set operations: ";
result.n=i;
result.display();
}
void SetOp::intersection_set(SetOp S2)
{
cout<<"\n Enter second set: ";
S2.add();
SetOp result; //this->1,2,3,4 i->S2=1,3,5,7 j->result=1,3
int j=0;
for(int i=0;i<S2.n;i++)
{
if(this->contains(S2.a[i])!=-1)
{
result.a[j]=S2.a[i];
j++;
}
}
cout<<"\n Intersection of elements: ";
result.n=j;
result.display();
}
void SetOp::difference_set(SetOp S2)
{
cout<<"\n difference set operation";
cout<<"\n Enter 2nd set:";
S2.add();
SetOp result; //this->1,2,3,4 i->s2=1,3,5,7 j->result=2,4
int j;
for(int i=0;i<this->n;i++)
{
if(S2.contains(this->a[i])==-1)
{
result.a[j]=this->a[i];
j++;
}
}
cout<<"\n Difference between";
result.n=j;
result.display();
}
void SetOp::subset(SetOp S2)
{
int flag=0;
cout<<"\n subset operation"; //this->1,2,3,4 S2=1,3,4
cout<<"\n enter second set:";
S2.add();
for(int i=0;i<S2.n;i++)
{
if(this->contains(S2.a[i])==-1) //-1->does not exist return index
{
cout<<"\n set2 is not a subset of set1";
flag=1;
break;
}
}
if(flag==0)
{
cout<<"\n set2 is a setof set1";
}
}
int main()
{
int val;
SetOp obj1;
SetOp obj2;
int ch;
obj1,obj2;
do
{
cout<<"\n set operation";
cout<<"\n 1.accept \n 2.display \n 3.remove \n 4.union of 2set \n 5.intersection_set \n 6.difference_set \n 7.subset \n 8.exit";
cout<<"\n enter your choice:";
cin>>ch;
switch(ch)
{
case 1:
obj1.add();
break;
case 2:
obj1.display();
break;
case 3:
int val;
cout<<"\nEnter value to be deleted:";
cin>>val;
obj1.remove(val);
break;
case 4:
obj1.union_set(obj2);
break;
case 5:
obj1.intersection_set(obj2);
break;
case 6:
obj1.difference_set(obj2);
break;
case 7:
obj1.subset(obj2);
break;
case 8:
exit(0);
break;
default:
cout<<"\nInvalid";
}
}
while(ch!=8);
return 0;
}