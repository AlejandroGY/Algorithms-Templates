#include <bits/stdc++.h>

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   int n;
   std::cin >> n;

   std::vector<int> lista[n + 1];
   for (int i = 0; i < n; ++i) {
      int num_amigos;
      std::cin >> num_amigos;
      for (int j = 0; j < num_amigos; ++j) {
         int amigo;
         std::cin >> amigo;
         lista[i].push_back(amigo);
      }
   }

   int inicia;
   std::cin >> inicia;

   int dias[n + 1] = { };
   bool visitados[n + 1] = { };
   std::queue<std::pair<int, int>> cola;

   cola.push({ inicia, 0 });
   visitados[inicia] = true;
   
   do {
      std::pair<int, int> act = cola.front( ); cola.pop( );
      for (int v : lista[act.first]) {
         if (!visitados[v]) {
            visitados[v] = true;
            cola.push({ v, act.second + 1 });
            dias[act.second + 1] += 1;
         }
      }
   } while (!cola.empty( ));

   std::cout << *std::max_element(dias, dias + n + 1) << "\n";
}
