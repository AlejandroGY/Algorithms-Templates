//Calcula los divisores de un número en O(n^1/3)
#include <bits/stdc++.h>

int main( ) {
   int n;
   std::cin >> n;

   std::vector<int> divisores;
   auto raiz = std::sqrt(n);
   for (int i = 1; i <= raiz; ++i) {
      if (n % i == 0) {
         if (n / i == i) {
            divisores.push_back(i);
         } else {
            divisores.push_back(i);
            divisores.push_back(n / i);
         }
      }
   }
   std::sort(divisores.begin( ), divisores.end( ));

   std::cout << divisores.size( ) << "\n";
   for (auto d : divisores) {
      std::cout << d << " ";
   }
   std::cout << "\n";
}
