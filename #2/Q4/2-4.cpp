#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<pair<int,int> > *adjacent;
public:
    Graph(int V);
    void addEdge(int v, int w, int c);
    void b_f_s(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adjacent = new list<pair<int,int> >[V];
}

void Graph::addEdge(int v, int w,int c)
{
    adjacent[v].push_back(make_pair(w,c));
}

void Graph::b_f_s(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<pair<int,int > >::iterator i;

    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for(i = adjacent[s].begin(); i != adjacent[s].end(); ++i)
        {
            if(!visited[(*i).first])
            {
                visited[(*i).first] = true;
                queue.push_back((*i).first);
            }
        }
    }
}

/*
4
1 2 3 0
4
0 1 3 4
4
100 200 300 211
*/

int main() {
    int length1, length2, length3;
    cin>>length1;
    int array1[length1];
    Graph g(1<<21);
    for(int i=0;i<length1;i++) {
        cin>>array1[i];
    }
    cin>>length2;
    int array2[length2];
    for(int i=0;i<length2;i++) {
        cin>>array2[i];
    }
    cin>>length3;
    int array3[length3];
    for(int i=0;i<length3;i++) {
        cin>>array3[i];
    }

    for(int i=1;i<length2;i++) {
        for(int j = array2[i-1];j < array2[i];j++) {
            g.addEdge(i-1,array1[j],array3[j]);
        }
    }

    cout << "Breadth First Traversal starting from vertex 1: ";
    g.b_f_s(1);
    return 0;
}
