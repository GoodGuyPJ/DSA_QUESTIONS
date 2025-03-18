#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 12345;
  int count = 0;
  while (n != 0)
  {
    n = n / 10;
    count++;
  }
  cout << count;

  return 0;
}