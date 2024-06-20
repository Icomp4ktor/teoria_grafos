#include <bits/stdc++.h>

using namespace std;

void leituraGrafo(vector<vector<double>> &, int);
void escritaGrafo(vector<vector<double>> &);
void floydWarshall(vector<vector<double>> &);

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<double>> Grafo;
    Grafo.assign(n, vector<double>(n, INFINITY));
    
    // Inicializa a diagonal principal como 0, pois a distância de um nó para ele mesmo é 0
    for (int i = 0; i < n; i++) {
        Grafo[i][i] = 0;
    }
    
    leituraGrafo(Grafo, m);
    cout << "Grafo inicial:" << endl;
    escritaGrafo(Grafo);
    
    floydWarshall(Grafo);
    
    cout << "Grafo após Floyd-Warshall:" << endl;
    escritaGrafo(Grafo);
    
    cout << "Total Vértices: " << n << endl;
    cout << "Total Arestas: " << m << endl;
    
    return 0;
}

void leituraGrafo(vector<vector<double>> &G, int m)
{
    int a, b;
    double c;
    while (m--)
    {
        cin >> a >> b >> c;
        G[a][b] = c;
        //G[b][a] = c; // Descomente esta linha se o grafo for não-direcionado
    }
}

void escritaGrafo(vector<vector<double>> &G)
{
    int n = G.size();
    cout << "Matriz de Adjacência:" << endl;
    cout << "   ";
    for (int u = 0; u < n; u++)
    {
        cout << u << " ";
    }
    cout << endl;
    for (int u = 0; u < n; u++)
    {
        cout << u << ": ";
        for (int v = 0; v < n; v++)
        {
            if (G[u][v] == INFINITY)
                cout << "INF ";
            else
                cout << G[u][v] << " ";
        }
        cout << endl;
    }
}

void floydWarshall(vector<vector<double>> &G)
{
    int n = G.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (G[i][k] < INFINITY && G[k][j] < INFINITY)
                {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
    }
}
