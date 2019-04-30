//Calcula  (a^n % m)
#include <bits/stdc++.h>

long long power(long long a, long long n, long long m) {
   long long res = 1;
   for ( ; n; n >>= 1) {
      if (n & 1) {
         res = (res * a) % m;
      }
      a = (a * a) % m;
   }
   return res;
}

int main( ) {
   std::cout << power(2, 10, 123) << "\n";
}
