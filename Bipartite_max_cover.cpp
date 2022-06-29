#include <iostream>
using namespace std;
#define M 5
#define N 5
bool graph[M][N];

bool BpM(int u, bool visited[], int assign[]) {
   for (int v = 0; v < N; v++) { 
      if (graph[u][v] && !visited[v]) { 
         visited[v] = true;  
         if (assign[v] < 0 || BpM(assign[v], visited, assign)) {
            assign[v] = u; 
            return true;
         }
      }
   }
   return false;
}

int MaxMatch() {
   int assign[N];    
   for(int i = 0; i<N; i++)
      assign[i] = -1;   
   int result = 0;

   for (int u = 0; u < M; u++) {   
      bool visited[N];
      for(int i = 0; i<N; i++)
         visited[i] = false;    
      if (BpM(u, visited, assign))   
         result++;
   }
   return result;
}

int main() {
    cout<<"Enter the adjacency matrix\n";
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>graph[i][j];
        }
    }
    cout << "Maximum number of Participants who can get prize is: "<< MaxMatch();
    
}