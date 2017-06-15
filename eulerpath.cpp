//Fleury’s Algorithm for printing Eulerian Path or Circuit





#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countt=0,n,nv;
 vector<int>::iterator q1;
  vector<int>::iterator q2;
  vector<int>xxx[100];
void work(vector<int >h[],int x,int y)
{
h[x].push_back(y);
h[y].push_back(x);
 
}



void dfs(vector<int> h[],int v[],int l)
{ 
   int jj=0;
   v[l]=1;
	while(1!=0)
	{ //cout<<h[l][jj]<<" "; 
        if(h[l][jj]  )
        {   if( h[l][jj]!=-7)
        	{if(v[h[l][jj]]==0  )
        	{   //cout<<h[l][jj]<<" ";  
        	++countt;
        		dfs(h,v,h[l][jj]);
        	}}
        	 

        }  
                else
        	       break;
        ++jj;
    }
}

void rmedge(vector<int >adj[],int x,int y)  //removing edges
{

vector<int>::iterator iv=find(adj[x].begin(),adj[x].end(),y);
vector<int>::iterator iu=find(adj[y].begin(),adj[y].end(),x);
 *iv=-7;
 *iu=-7;
q1=iv;
q2=iu;


}
int checkBridge(vector<int >adj[],int a,int b) // check if it is bridge
{ countt =0 ;
	int v[100]={0};
rmedge(adj,a,b);
//cout<<adj[7][0];
*q1=b;
*q2=a;
dfs(adj,v,a);

 
if(countt+1!=nv)
	return(-1);
else
	return(0);
}


void fire(vector<int>adj[],int a)
{ int jj=0;
	int qq1,qq2,vv=0,zt=0;
	while(1!=0)
	{
     if(adj[a][jj])
     {         
 //cout<<adj[a][jj];
      if(adj[a][jj]!=-7)
     	{ ++zt;   
       if(checkBridge(adj,a,adj[a][jj])==-1)
       	{  //bridge
            vv=4;
         qq1=a;
       	qq2=adj[a][jj];
        
       	//rmedge(adj,a,adj[a][jj]);
                   }       
       else 
       {  qq1=a;
       	qq2=adj[a][jj];
       		rmedge(adj,a,adj[a][jj]);
       	break;}
    }



       } else break;
       ++jj;
    }
    if(zt>0)
    	{ if(vv==4)
    		{     
    			rmedge(adj,qq1,qq2);}
    			 	cout<<qq1<<" "<<qq2 << endl;
    		 fire(adj,qq2);

}





         }
   








 










int main()
{ countt=0;
vector<int >adj[100],cpy[100]; 
int z[999]={0}; 
int prev[999]={0}; 
int  g,h,i=0;
 
cin>>n;
cin>>nv;// no. of vvertexxx

for(int e=0;e<n;e++)
{ 
cin>>g>>h;
work(adj,g,h);
 
}
 
 
cout<<"3"<<endl;
fire(adj,3);//starts from 1

 

 
}