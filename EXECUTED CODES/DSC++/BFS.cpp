#include <iostream>
using namespace std;

class bfs(int S)
{
        visited[S]=1;   //source is visited

        cout<< S <<"\t";    //source is printed 

        while(true)
        {
                for(int i=1;i<=n;i++)   
                {
                        if(graph[S][i]!=0 && visited[i]==0) // if adjacent to S and not visited or not
                        {
                                visited[i]=1;
                                queue[++rear]
                        }
                }

                if(front > rear)        //if front is greater than rear queue is empty
                        break;
                S=queue[front++];   // pop front vertex from queue
                cout<< S << "\t';
        }
}

int main()
{
        int S;

        cout<<"\n enter number of vertices ";
        cin>>n;
    
        int front=-1;rear=-1;
        int queue[n] , graph[n][n] ,  visited[n];
       

        for(int i=1;i<=n;i++)
        {
                visited[i]=o;
        }

        cout<<"\n Enter graph data in matrix form";
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=n;j++;
                {
                        cin>>arr[i][j];
                }
        }

        cout<<"\n Enter source vertex: ";
        cin>>S;
        cout<<" Breadth First Traversal : \n";

        bfs(S);

        return 0;
}

/*
Output:
Enter the number of vertices:5
Enter graph data in matrix form:
0 1 0 1 1
1 0 0 0 1
1 1 0 0 0
1 1 1 0 0
1 0 1 0 1
Enter the starting vertex:3
BREADTH FIRST TRAVERSAL:
3 1 2 4 5*/

                                                                                                                               27,1           6%
