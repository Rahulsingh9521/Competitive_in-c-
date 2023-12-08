#include<iostream>
#include<fstream>

using namespace std;
int edge, vertex;
vector<bool> visted;
vector<vector<int> > graph;


void dfs(int curr_index){

    if(visted[curr_index]){
        return;
    }
    visted[curr_index] = true;
    
    for(auto node: graph[curr_index]){

        if(!visted[node]){
            dfs(node);
        }
    }
    
    return;
}

int main() {

    cout << "enter E, V = ";
    cin >> edge >> vertex;
    // cout << edge << vertex;

    graph = vector<vector<int> >(vertex);
    visted = vector<bool>(vertex, false);

    for(int count = 0; count < edge; count++){
        int v, u; cin >> v >> u;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    // for(auto x: visted)
    // {
    //     cout << x << " firbf ";
    // }

    // cout << "\n-----\n";

    // for(int i = 0; i < vertex; i++){
    //     cout << i << " : ";
    //     for(auto x: graph[i]){
    //         cout << x << " ";
    //     }

    //     cout << "\n";
    // }
    

    dfs(0);

    return 0;
}