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

bool MR(long long d, long long n) {
   long long a = 2 + std::rand( ) % (n - 4);
   long long x = power(a, d, n);

   if (x == 1 || x == n - 1) return true;

   while (d != n - 1) {
      x = (x * x) % n;
      d *= 2;
      
      if (x == 1) return false;
      if (x == n - 1) return true;
   }

   return false;
}

bool esPrimo(long long n, long long k) {
   if (n <= 1 || n == 4) return false;
   if (n <= 3) return true;

   long long d = n - 1;
   while (d % 2 == 0) {
      d /= 2;
   }

   for (int i = 0; i < k; ++i) {
      if (!MR(d, n)) {
         return false;
      }
   }
   return true;
}

int main( ) {
   int k = 4;
   for (int i = 1; i < 100; ++i) {
      if (esPrimo(i, k)) {
         std::cout << i << " ";
      }
   }
}
