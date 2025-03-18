// #include<bits/stdc++.h>
// using namespace std;

//  void func(int i, int n){
//   if(i>n)
//     return;
//     cout<<i<<" ";
//     func(i+1,n);
//  }

// int main(){
//     int n=10;
//     int i=1;
//     func(i,n);

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void func2(int i, int n)
{

  if (i < 1)
    return;

  func2(i - 1, n);

  cout << i << " ";
}

int main()
{
  int n = 10, i = 1;
  func2(n, n);

  return 0;
}