//FINDING ARTICULATION POINT

  #include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fire(vector<int>arr[1111],int a,int b)
{
   arr[a].push_back(b);
   arr[b].push_back(a);
   //cout<<a<<" "<<b<<endl;
 
}
int df=0;
int gg=0;
int mg=0;
set<int>zzz;
void DFS(vector<int>arr[],int cont[],int st,int prt[],int num[],int low[],int prev)
{




	if(cont[st]==0)
		{  cont[st]=1;
           low[st]=df;
           num[st]=df;
           prev=st;
           ++df;
            //cout<<st<<endl;
			for(int e=0;e<arr[st].size();e++)
			{
              if(cont[arr[st][e]]==0 && arr[st][e]!=mg)
              	{prt[arr[st][e]]=st;
               
                     if(st==mg) ++gg;
               }


              DFS(arr,cont,arr[st][e],prt,num,low,prev);

            }
              
           //cout<<arr[3].size()<<"<";
           if(  !(prt[st]==-1 || arr[prt[st]].size()<=1))
            	{
                     //if(st==5)
                     	//cout<<prt[5]<<" "<<num[prt[5]]<<" "<<low[5]<<endl;
            		if(low[st]>=num[prt[st]] && prt[st]!=mg )
               { zzz.insert(prt[st]);
                  //cout<<prt[st]<<endl;

               }
                   else
                   	if(	low[prt[st]]>=low[st])
                   	low[prt[st]]=low[st];

                   }


        }
        else if(cont[st]==1 && prt[prev]!=st)
        {

         

              low[prev]=min(low[prev],num[st]);
     //cout<<prev<<" "<<low[prev]<<endl;



        }
}










int main()
{

while(1!=0)
{
vector<int >arr[1111];
int cont[1111]={0}, st=0,prt[1111]={0},num[1111]={0}, low[1111]={0},  prev=0;
int a,b,ar;
char d;
int n;
cin>>n;
if(n==0)
break;
int h=0;
while(1!=0)
{ if(h==0)
	{cin>>a;
		if(a==0)
			break;
		else
		ar=a;
      h=1;
	}
	else
		{cin>>b;
			fire(arr,a,b);
        
   }
          

d=getchar();
if(d==' ')
h=1;
else if(d=='\n')
h=0;
 
}
prt[ar]=-1;
mg=ar;
              DFS(arr,cont,ar,prt,num,low,prev);
             
              if(gg<=1)
cout<<zzz.size()<<endl;
else
cout<<zzz.size()+1<<endl;
zzz.clear() ;
df=0;
gg=0;

}

}
















 
