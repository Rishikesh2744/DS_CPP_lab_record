#include <iostream>
using namespace std;
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;
void bfs(int v)
{
    visited[v] = 1;
    cout << v << "\t";
    while (1)
    {
        for (i = 1; i <= n; i++) // for all the vertices
        {
            if (a[v][i] != 0 && visited[i] == 0) // adjacent to v and not visited
            {
                visited[i] = 1;
                q[++r] = i;
            }
        }
        // if queue is empty, stop while loop
        if (f > r)
            break;
        v = q[f++]; // pop front vertex from queue
        cout << v << "\t";
    }
}
int main()
{
    int v;
    cout << "\n Enter the number of vertices:";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    cout << "\n Enter graph data in matrix form:\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    cout << "\n Enter the starting vertex:";
    cin >> v;
    cout << "BREADTH FIRST TRAVERSAL:\n";
    bfs(v);
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