#include <iostream>
#include <list>
#include <queue> // Libreria para colas
#define INFINITO 10000000  

using namespace std;

class Grafo
{
private: 
	int V; // Número de vértices

	// Puntero para lista de adyacencia
	list<pair<int, int> > * adj;

public:

	// Construtor
	Grafo(int V)
	{
		this->V = V; // Numero de vertices 

	
		adj = new list<pair<int, int> >[V];
	}

	// Funcionar para adicionar aristas 
	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	// Algoritmos principal basado en el Dijkstra 
	int intexsiteCaminoDist(Grafo G, int s, int t, int d)
	{
		// Vector de distancias 
		int dist[V];

		// Vector para vertices visitados 
		int visitados[V];

		// Fila de prioridades (Distancia, Vertice)
		priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// Iniciacializamos el vector de distancia e infinito
		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// Distancia de origen
		dist[s] = 0;

		// Insertar en la fila
		pq.push(make_pair(dist[s], s));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // Extraemos el par ultimo puesto
			int u = p.second; // Obtenemos vertice del par
			pq.pop(); // Removemos de la fila

			// Verificamos si ya fue visitado el vertice
			if(visitados[u] == false)
			{
				// Marcamos visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// Recorrido de los vertices adyacentes
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// Obtenemos el vertice adyacente de la arista 
					int v = it->first;
					int custo_aresta = it->second;

					// Reemplazamieno si es que la distancia actual es mayor 
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// Actualizamos el tamaÃ±o final
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// Retorna 1 si es menor que d y 0 si es que no es menor que d
		
		if (dist[t]>=d){
			return 1;
		}
		else{
			return 0; 
		}
	}
};

int main(int argc, char *argv[])
{
	
	int vertices;
	
	cout<<"\nCuantos vertices tiene el grafo: "; cin>>vertices;
	
	cout << "\nADVERTENCIA: Tenga en cuenta que si tiene 7 vertices por ejemplo, estos seran numeros del 0 al 6, asÃ­ para diferentes valores de vertices\n";
	
	Grafo g(vertices);
	
	int i;
	int uniones;
	int nodo1;
	int nodo2; 
	int aresta;
	int d;

	cout<<"\nCuantas aristas tiene el grafo: "; cin>>uniones;
	
	for (i=0; i<uniones; i++){
	
		cout<<"\nEscribe el primer nodo: "; cin>>nodo1;
		cout<<"Escribe el segundo nodo: "; cin>>nodo2;
		cout<<"Escribe el peso de la arista que los une: "; cin>>aresta;
	
		g.addAresta(nodo1, nodo2, aresta);
		
	}
	
	cout << "\n\nNos devolvera 1 si la distancia entre el nodo de partida y nodo de llegada  es por lo menos d, caso contrario nos devuelve 0";
	
	cout<<"\n\nEscribe el nodo de partida: "; cin>>nodo1;
	cout<<"Escribe el nodo de llegada: "; cin>>nodo2;
	cout<<"Escribe el valor de d: "; cin>>d;

	cout << g.intexsiteCaminoDist(g, nodo1, nodo2, d) << endl;

	return 0;
}
	
