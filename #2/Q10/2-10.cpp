#include <bits/stdc++.h>

using namespace std;

struct graph{
    int row;
    int column;
    int item;
};

int n,e;

graph g[1000];

void b_f_s(int s) {
    bool *vis = new bool[n];
    for(int i = 0; i < n; i++)
        vis[i] = false;

    list<int> queue;

    vis[s] = true;
    queue.push_back(s);

    list<pair<int,int > >::iterator i;

    while(!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for(int i=0;i<e;i++) {
            if(g[i].row==s) {
                if(!vis[g[i].column]) {
                    vis[g[i].column] = true;
                    queue.push_back(g[i].column);
                }
            }
        }
    }
}

/*
4
4
0 1 100
1 3 200
1 2 100
2 0 200
*/

int main(){

    cout<<"Enter no. nodes"<<endl;
    cin>>n;

    cout<<"Enter no. edges"<<endl;
    cin>>e;

    cout<<"Enter row column item"<<endl;
    for(int i=0;i<e;i++) {
        cin>>g[i].row>>g[i].column>>g[i].item;
    }

    cout << "Following is Breadth First search Traversal "
         << "\n";
    b_f_s(1);

    return 0;
}
