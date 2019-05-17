//Calcula el GCD por el algoritmo de euclides (gcd(a, b)) y euclides extendido (ax + by = gcd(a, b))
#include <bits/stdc++.h>

long long gcd(long long a, long long b) {
   return (a == 0 ? b : gcd(b % a, a));
}

long long gcd_ext(long long a, long long b, long long& x, long long& y) {
   if (a == 0) {
      x = 0, y = 1;
      return b;
   }

   long long x1, y1;
   long long gcd = gcd_ext(b % a, a, x1, y1);
   x = y1 - (b / a) * x1;
   y = x1;

   return gcd;
}

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   std::cout << gcd(10, 15) << "\n";

   long long x, y;
   long long g = gcd_ext(35, 15, &x, &y);
   std::cout << g << " " << x << " " << y << "\n";
}
