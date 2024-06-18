#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

int main() {
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<pair<int, int>>> adj(v);
    int from, to;

    // Read edges assuming directed graph and we'll add a reverse edge with weight = 1
    cout << "Enter all edges in the format 'from to':\n";
    for (int i = 0; i < e; i++) {
        cin >> from >> to;
        adj[from].push_back(make_pair(to, 0));  // original edge with weight 0
        adj[to].push_back(make_pair(from, 1));  // reverse edge with weight 1
    }

    int source, destination;
    cout << "Enter source and destination: ";
    cin >> source >> destination;

    vector<int> distance(v, INT_MAX);
    set<pair<int, int>> setds;

    // Start Dijkstra's from source
    distance[source] = 0;
    setds.insert({0, source});

    while (!setds.empty()) {
        int dist = setds.begin()->first;
        int u = setds.begin()->second;
        setds.erase(setds.begin());

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Check if a shorter path to v is found
            if (distance[u] + weight < distance[v]) {
                // If distance[v] is not INF, it must be in the set, so remove it
                if (distance[v] != INT_MAX) {
                    setds.erase({distance[v], v});
                }
                distance[v] = distance[u] + weight;
                setds.insert({distance[v], v});
            }
        }
    }

    // Check if the destination is reachable
    if (distance[destination] == INT_MAX) {
        cout << "Not possible to reach destination." << endl;
    } else {
        cout << "Minimum edge reversals required: " << distance[destination] << endl;
    }

    return 0;
}
