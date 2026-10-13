#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, edges;

    cout << "Enter number of routers: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter number of connections: ";
    cin >> edges;

    cout << "Enter connections (router1 router2 cost):\n";

    for (int i = 0; i < edges; i++) {
        char a, b;
        int cost;

        cin >> a >> b >> cost;

        int u = a - 'A';
        int v = b - 'A';

        if (u < 0 || u >= n || v < 0 || v >= n || cost <= 0) {
            cout << "Invalid connection. Enter again.\n";
            i--;
            continue;
        }

        graph[u][v] = cost;
        graph[v][u] = cost;
    }

    char s, d;

    cout << "Enter source router (A, B, C...): ";
    cin >> s;

    cout << "Enter destination router (A, B, C...): ";
    cin >> d;

    int source = s - 'A';
    int destination = d - 'A';

    if (source < 0 || source >= n ||
        destination < 0 || destination >= n) {
        cout << "Invalid source or destination router.";
        return 0;
    }

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    dist[source] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] &&
                (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1 || dist[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && !visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[destination] == INT_MAX) {
        cout << "No path exists between the routers.";
        return 0;
    }

    vector<int> path;

    for (int v = destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    cout << "\nShortest path: ";

    for (int i = static_cast<int>(path.size()) - 1;
         i >= 0; i--) {
        cout << char('A' + path[i]);

        if (i > 0)
            cout << " -> ";
    }

    cout << "\nMinimum cost: " << dist[destination];

    return 0;
}
