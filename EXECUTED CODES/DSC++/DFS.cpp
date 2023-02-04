#include <iostream>
using namespace std;
int a[20][20], st[20], visited[20], n, i, j, top = -1;
void dfs(int v)
{
    cout << v << "\t";
    visited[v] = 1;
    while (1)
    {
        for (i = 1; i <= n; i++) // for all the vertices
        {
            if (a[v][i] != 0 && visited[i] == 0) // adjacent to v and not visited
            {
                st[++top] = i;
            }
        }
        // if stack is empty, stop while loop
        if (top == -1)
            break;
        v = st[top--]; // pop top vertex from stack
        if (visited[v] != 1)
        {
            cout << v << "\t"; // print it
            visited[v] = 1;    // mark it as visited
        }
    }
}
int main()
{
    int v;
    cout << "\n Enter the number of vertices:";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0; // initially all vertices are not visited
    }
    cout << "\n Enter graph data in matrix form:\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    cout << "\n Enter the starting vertex:";
    cin >> v;
    cout << "DEPTH FIRST TRAVERSAL:\n";
    dfs(v);
}

/*Output:
Enter the number of vertices:5
Enter graph data in matrix form:
0 1 0 1 1
1 0 0 0 1
1 1 0 0 0
1 1 1 0 0
1 0 1 0 1
Enter the starting vertex:3
DEPTH FIRST TRAVERSAL:
3 2 5 1 4*/