#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 2;
  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      cnt++;
    }
  }
  if (cnt == 2)
  {
    cout << "Prime Number";
  }
  else
  {
    cout << "Not a Prime Number";
  }

  return 0;
}