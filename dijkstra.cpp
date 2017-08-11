//DIJKSTRA ALGORITHM




#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class kys
{


public:
	bool operator ()(pair<int,int >q1,pair<int,int > q2)
	{

return(q1.second>=q2.second);



	}



};
void work(vector<pair<int ,int > >arr[1111],int a,int b,int c)
{

arr[a].push_back(make_pair(b,c));
arr[b].push_back(make_pair(a,c));


}









int main()
{

    vector<pair<int ,int > >arr[1111];
	priority_queue<pair<int,int>, vector< pair<int,int> >,kys >mint;
	int visited[1111]={0};
	int popped[1111]={0};
	int store[1111]={0};
	int f=0;
	int background[1111]={0};
	int xx[1111];
	int vertices;
	cin>>vertices;
	int sides;
	cin>>sides;
	for(int j=0;j<sides;j++)
	{
		xx[j]=9999;
  int a1,a2,a3;
  cin>>a1>>a2>>a3;
work(arr,a1,a2,a3);

	}

    xx[0]=0;
    xx[1]=0;
	mint.push(make_pair(1,0));



	while(!mint.empty())
	{

int q1=mint.top().first;
int q2=mint.top().second;

mint.pop();
int z=popped[q1];
popped[q1]=1;
if(z==0)
{
	++f;
	 
for(int h=0;h<arr[q1].size();h++)
{


	int b1=arr[q1][h].first;
	int b2=arr[q1][h].second;
 

	if(xx[b1]>xx[q1]+b2 && popped[b1]==0)
	{
        xx[b1]=xx[q1]+b2;
        store[b1]=q1;
      mint.push(make_pair(b1,xx[q1]+b2));






	}



}


	}
if(f==vertices+1)
		break;

}
cout<<xx[5]<<endl;
}