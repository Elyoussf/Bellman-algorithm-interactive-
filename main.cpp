#include <vector>
#include <iostream>
#include <queue>
#include <limits>

using namespace std;


struct customComparator{
    bool operator()(const vector<int> &a,const vector<int> &b){
        return a[1]<b[1];
    }
};

int main(){
    // represent a graph with adjency list
    int inf = numeric_limits<int>::max();
    int V;
    cout << "please enter the number of vertices in your graph: "<< endl;
    cin >> V;
    vector<vector<vector<int>>> graph(V);
    for (int i = 0;i<V;i++){
        cout << "please enter the number of neighbors of "<< i <<endl;
        int n ; 
        cin >> n;
        while (n--){
            cout << "enter the "<<(n+1)<<"th neighbor then space then the weight "<< endl;
            int neighbor;
            int w;
            cin >> neighbor>>w;

            graph[i].push_back({neighbor,w});
        }
    }
    int start;
    cout<<"the start : ";
    cin >> start;
    int rounds = V-1;
    vector<int> distances(V,inf);
    distances[start] = 0;
    while (rounds--){
        for (int i = 0;i<V;i++){
            for (auto &edge : graph[i]){
                distances[edge[0]] = min(distances[edge[0]],distances[i]+edge[1]);
            }
        }
    }
    int i =0;
    for (auto &d : distances){
        cout << "the distance from "<<start<<" to "<<i<<" is "<<d<<endl;
        i++;
    }







    return 0;
}