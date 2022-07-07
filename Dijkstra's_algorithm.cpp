/*
References:
1. https://www.tutorialspoint.com/cplusplus-program-for-dijkstra-s-shortest-path-algorithm
2. https://favtutor.com/blogs/dijkstras-algorithm-cpp
*/

#include<iostream>
#include<iomanip>
#include<stdio.h>
#define INFINITY 9999
#define max 6

using namespace std;

int convert(char input);
void dijkstra(int G[max][max],int n,char u,char d);
int main() {
    int G[max][max]={{0,4,2,0,0,0},
	                 {4,0,1,5,0,0},
					 {2,1,0,8,10,0},
					 {0,5,8,0,2,6},
					 {0,0,10,2,0,5},
					 {0,0,0,6,5,0}};
					 
    int n=6;
    char u;
    char destination;
    char choice='y';
   	while(choice!='n'){
		cout<<"Please enter the node for origin of the Location. (Example: a,b,c,d,e,z): ";
		cin>>u;
		cout<<"\nNow please enter the node for destination of the Location. (Example: a,b,c,d,e,z): ";
		cin>>destination;
    	dijkstra(G,n,u,destination);
    	cout<<"\nDo you want to Continue calculating?(y/n): ";
    	cin>>choice;
    	cout<<endl;
    }
    return 0;
}

void dijkstra(int G[max][max],int n,char u,char d) {
	int cost[max][max],distance[max],pred[max];
    int visited[max],count,mindistance,nextnode,i,j;
	int startnode;
	int destination;
    char arrChar[6]={'a','b','c','d','e','z'};
    int arrNum[6]={0,1,2,3,4,5};
    
	for(int i=0;i<6;i++){
    	if(arrChar[i]==u){
    		startnode=arrNum[i];
		}
		if(arrChar[i]==d){
			destination=arrNum[i];
		}
	}
    for(i=0;i<n;i++){
      	for(j=0;j<n;j++){
    		if(G[i][j]==0){
      			cost[i][j]=INFINITY;
      		}
    		else{
      			cost[i][j]=G[i][j];
      		}
        }	  
    }
    for(i=0;i<n;i++) {
      	distance[i]=cost[startnode][i];
      	pred[i]=startnode;
      	visited[i]=0;
    }
    
	distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    
	while(count<n-1) {
        mindistance=INFINITY;
        for(i=0;i<n;i++){
            if(distance[i]<mindistance&&!visited[i]) {
            	mindistance=distance[i];
            	nextnode=i;
        	}
        }
        visited[nextnode]=1;
        for(i=0;i<n;i++){		
            if(!visited[i]){			
        		if(mindistance+cost[nextnode][i]<distance[i]) {
           		    distance[i]=mindistance+cost[nextnode][i];
            		pred[i]=nextnode;
        		}
        	}
    	}
        count++;
    }
    
    int arr[]={0};
    int check=0;

	i=destination;
	if(i!=startnode) {
        cout<<"\n\nThe Distance of node "<<i<<" = "<<distance[i];
        cout<<"\n\nThe Path = ";
        j=i;
        do {
            j=pred[j];
          	arr[check]=j;
            check++;              
           	//cout<<"  "<<j<<endl;
        }while(j!=startnode);
        for(int i=check;i>0;i--){
        	//cout<<arr[i-1]<<" -> ";
        	cout<<arrChar[arr[i-1]]<<" -> ";
		}
		cout<<d<<endl;
        cout<<"\nBus Fare from both location inputted = RM"<<fixed<<setprecision(2)<<distance[i]*1.5<<endl;
    }
    else if(i==startnode){
    	cout<<"\nError occured, the origin should not be equal to the destination."<<endl;
	}
    
}
