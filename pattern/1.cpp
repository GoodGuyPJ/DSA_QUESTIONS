#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}

//****************2********************* */
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}

//****************3********************* */
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << j;
    }
    cout << endl;
  }
  return 0;
}

//****************4********************* */
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << i;
    }
    cout << endl;
  }
  return 0;
}

//****************5********************* */
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  for (int i = 0; i < n; i++)
  {
    for (int j = n - i; j >= 1; --j)
    {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}

//****************6********************* */
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= n - i; j++)
    {
      cout << j;
    }
    cout << endl;
  }
  return 0;
}
//****************7********************* */
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  for (int i = 0; i < n; i++)
  {
    // spaces
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    // stars
    for (int j = 1; j <= (2 * i + 1); j++)
    {
      cout << "*";
    }
    // spaces
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    cout << endl;
  }
  return 0;
}

//****************8********************* */
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  for (int i = 0; i < n; i++)
  {
    // spaces
    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }
    // stars
    for (int j = 1; j <= (2 * n - (2 * i + 1)); j++)
    {
      cout << "*";
    }
    // spaces
    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }

    cout << endl;
  }
  return 0;
}

//****************9********************* */
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  for (int i = 0; i < n; i++)
  {
    // spaces
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    // stars
    for (int j = 1; j <= (2 * i + 1); j++)
    {
      cout << "*";
    }
    // spaces
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    cout << endl;
  }
  for (int i = 0; i < n; i++)
  {
    // spaces
    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }
    // stars
    for (int j = 1; j <= (2 * n - (2 * i + 1)); j++)
    {
      cout << "*";
    }
    // spaces
    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }

    cout << endl;
  }
  return 0;
}

//****************10********************* */
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  for (int i = 1; i <= 2 * n - 1; i++)
  {
    int stars = i;
    if (i > n)
      stars = 2 * n - i;
    for (int j = 1; j <= stars; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}

//****************11********************* */
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  int start = 0;
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
      start = 1;
    else
      start = 0;
    for (int j = 0; j <= i; j++)
    {
      cout << start;
      start = 1 - start;
    }

    cout << endl;
  }

  return 0;
}
