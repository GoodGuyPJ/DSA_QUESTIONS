#include <bits/stdc++.h>
using namespace std;

void func(int i, int n)
{
  if (i > n)
    return;
  cout << "raj" << " ";
  func(i + 1, n);
}

int main()
{
  int n = 5;
  int i;
  func(i, n);

  return 0;
}