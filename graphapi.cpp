//A simple representation of graph using STL,


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void work(vector<int >h[],int x,int y)
{
h[x].push_back(y);
h[y].push_back(x);
}





int main()
{
vector<int >adj[100];   
int  g,h,i=0;
for(int e=0;e<=7;e++)
{ 
cin>>g>>h;
work(adj,g,h);

}
while(1!=0)  // prints the vertex adjacent to one
{   if(adj[1][i])
{	cout<<adj[1][i]<<" ";
++i;}
else break;
 }
}




 