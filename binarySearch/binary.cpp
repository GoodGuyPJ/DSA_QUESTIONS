binarySearch(vector<int> arr)
{
  int n = arr.size();
  in l = 0, h = n - 1;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] < target)
    {
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }
}

recursivebinarySearch(vector<int> arr, int l, int h)
{
  int n = arr.size();
  in l = 0, h = n - 1;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] < target)
    {
      recursivebinarySearch(arr, mid + 1, h);
    }
    else
    {
      recursivebinarySearch(arr, l, mid - 1);
    }
  }
}

// lowerbound
int lowerBound(vector<int> arr, int n, int x)
{
  int l = 0, h = n - 1;
  int ans = n;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    if (arr[mid] >= x)
    {
      h = mid - 1;
      ans = mid;
    }
    else
    {
      l = mid + 1;
    }
  }
  return ans;
}

// upperbound
int upperBound(vector<int> arr, int n, int x)
{
  int l = 0, h = n - 1;
  int ans = n;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    if (arr[mid] > x)
    {
      h = mid - 1;
      ans = mid;
    }
    else
    {
      l = mid + 1;
    }
  }
  return ans;
}

// search insert position
int searchInsert(vector<int> arr, int n, int x)
{
  int l = 0, h = n - 1;
  int ans = n;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    if (arr[mid] == x)
    {
      return mid;
    }
    else if (arr[mid] > x)
    {
      ans = mid;
      h = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return ans;
}

// floor and ceil in sorted array
int floor(vector<int> arr, int n, int x)
{
  int l = 0, h = n - 1;
  int ans = -1;
  while (l <= h)
  {
    int mid = l + h / 2;
    if (arr[mid] <= x)
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }
  return ans;
}

// Search Element in Rotated Sorted Array - I
int serach(vector<int> arr, int target)
{
  int low = 0, h = arr.size() - 1;
  while (low <= h)
  {
    int mid = l + (h - l) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    if (arr[low] <= arr[mid])
    {
      if (arr[low] <= target && target <= arr[mid])
      {
        h = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    else
    {
      if (arr[mid] <= target && target <= arr[h])
      {
        l = mid + 1;
      }
      else
      {
        h = mid - 1;
      }
    }
  }
}

// Search Element in Rotated Sorted Array - II
int serach(vector<int> arr, int target)
{
  int low = 0, h = arr.size() - 1;
  while (low <= h)
  {
    int mid = l + (h - l) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    if (ar[low] == arr[mid] && arr[mid] == arr[h])
    {
      low++;
      h--;
      continue;
    }
    if (arr[low] <= arr[mid])
    {
      if (arr[low] <= target && target <= arr[mid])
      {
        h = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    else
    {
      if (arr[mid] <= target && target <= arr[h])
      {
        l = mid + 1;
      }
      else
      {
        h = mid - 1;
      }
    }
  }
}

// BS-6. Minimum in Rotated Sorted Array
int minimum(vector<int> arr)
{
  int l = 0;
  int h = arr.size() - 1;
  int ans = INT_MAX;
  while (l <= h)
  {
    if (arr[l] <= arr[mid])
    {
      ans = min(ans, arr[l]);
      l = mid + 1;
    }
    else
    {
      ans = min(ans, arr[mid]);
      h = mid - 1;
    }
  }
  return ans;
}

// BS-7. Find out how many times array has been rotated
int findkrotation(vector<int> arr)
{
  int l = 0, h = arr.size() - 1;
  int ans = INT_MAX;
  int index = -1;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    if (arr[l] <= arr[h])
    {
      if (arr[low] < ans)
      {
        ans = arr[low];
        index = low;
      }
      break;
    }
    if (arr[low] <= arr[mid])
    {
      if (arr[low] < ans)
      {
        ans = arr[low];
        index = low;
      }
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
      if (arr[mid] < ans)
      {
        ans = arr[mid];
        index = mid;
      }
    }
  }
  return ans;
}

// BS-8. Single Element in Sorted Array
int single(vector<int> arr)
{
  int n = arr.size();
  if (n == 1)
    return arr[0];
  if (arr[0] != arr[1])
    return arr[0];
  if (arr[n - 1] != arr[n - 2])
    return arr[n - 1];

  int l = 1, h = n - 2;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
    {
      return arr[mid];
    }
    if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
    {
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }
  return -1;
}

// BS-9. Find Peak Element
int peak(vector<int> arr)
{
  int n = arr.size();
  int l = 0, h = n - 1;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
    {
      return mid;
    }
    if (mid > 0 && arr[mid - 1] > arr[mid])
    {
      h = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return -1;
}

// BS-10. Finding Sqrt of a number using Binary Search
int nthroot(int n)
{
  int l = 0, h = n, ans = 1;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    if (mid * mid <= n)
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }
  return ans;
}

// BS-11. Find the Nth root of an Integer
int func(int mid, int n)
{
  long long ans = 1;
  while (n > 0)
  {
    if (n % 2 == 1)
    {
      ans = ans * mid;
      n = n - 1;
    }
    else
    {
      mid = mid * mid;
      n = n / 2;
    }
  }
  return ans;
}

int nthroot(int n, int m)
{
  int l = 1, h = m;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    int midN = func(mid, n);
    if (midN == m)
    {
      return mid;
    }
    else if (midN < m)
    {
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }
  return -1;
}

int func(int mid, int n, int m)
{
  long long ans = 1;
  for (int i = 1; i <= n; i++)
  {
    ans = ans * mid;
    if (ans > m)
      return 2;
  }
  if (ans == m)
    return 1;
  return 0;
}

// BS-12. Koko Eating Bananas
int totalHOUR(vector<int> arr, int hourly)
{
  int total = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    total += ceil(arr[i] / hourly);
  }
  return total;
}
int koko(int arr, int h)
{
  int l = 1, h = *max_element(arr.begin(), arr.end());
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    int total = totalHOUR(arr, mid);
    if (total <= h)
    {
      h = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return l;
}

// BS-13. Minimum days to make M bouquets | Binary Search
int possible(vector<int> arr, int day, int m, int k)
{
  int n = arr.size();
  int no_of_bouquets = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] <= day)
    {
      cnt++;
    }
    else
    {
      no_of_bouquets += cnt / k;
      cnt = 0;
    }
  }
  no_of_bouquets += cnt / k;
  return no_of_bouquets >= m;
}

int minDays(vector<int> arr, int m, int k)
{
  int val = m * 1ll * k * 1ll;
  int n = arr.size();
  if (val > n)
    return -1;
  for (int i = 0; i < n; i++)
  {
    mini = min(mini, arr[i]);
    maxi = max(maxi, arr[i]);
  }
  int l = mini, h = maxi;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    if (possible(arr, mid, m, k))
    {
      h = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return l;
}

// BS-14. Find the Smallest Divisor Given a Threshold | Binary Search
int sumByD(vector<int> arr, int div)
{
  int sum = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    sum += ceil((double)arr[i] / (double)(div));
  }
  return sum;
}
int smallestDivisor(vector<int> arr, int threshold)
{
  int low = 1, h = *max_element(arr.begin(), end(arr));
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    if (sumByD(arr, mid) <= threshold)
    {
      h = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return l;
}

// BS-15. Capacity to Ship Packages within D Days
int finddays(vector<int> w, int cap)
{
  int days = 1;
  int load = 0;
  for (int i = 0; i < n; i++)
  {
    if (load + w[i] > cap)
    {
      day++;
      load = w[i];
    }
    else
    {
      load += w[i];
    }
  }
  return days;
}

int shipWithinDays(vector<int> w, int d)
{
  int n = w.size();
  int l = *max_element(w.begin(), end(w));
  int h = accumulate(w.begin(), end(w), 0);
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    int days = finddays(w, mid);
    if (days <= d)
    {
      h = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return l;
}

// BS-16. Kth Missing Positive Number | Maths + Binary Search
int missingK(vector<int> arr, int k)
{
  int l = 0, h = arr.size() - 1;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    int missing = arr[mid] - (mid + 1);
    if (missing < k)
    {
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }
  return k + h + 1; // low+k
}

// BS-17. Aggressive Cows | Binary Search Hard
bool canWePlace(vector<int> stalls, int dist, int cows)
{
  int cntCows = 1, last = stalls[0];
  for (int i = 1; i < stalls.size(); i++)
  {
    if (stalls[i] - last >= dist)
    {
      cntCows++;
      last = stalls[i];
    }
    if (cntCows >= cows)
      return true;
  }
  return false;
}

int aggressiveCows(vector<int> stalls, int k)
{
  sort(stalls.begin(), stalls.end());
  int n = stalls.size();
  int l = 1, h = stalls[n - 1] - stalls[0];
  while (l <= h)
  {
    int mid = (l + h) / 2;
    if (canWePlace(stalls, mid, k) == true)
    {
      low = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }
  return h;
}

// BS-18. Allocate Books or Book Allocation | Hard Binary Search
int countStudents(vector<int> &arr, int pages)
{
  int student = 1;
  long long pagesStudent = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (pagesStudent + arr[i] <= pages)
    {
      pagesStudent += arr[i];
    }
    esle
    {
      student++;
      pagesStudent = arr[i];
    }
  }
  return student;
}
int findPages(vector<int> arr, int n, int m)
{
  if (m > n)
    return -1;
  int l = *max_element(arr.begin(), arr.end());
  int h = accumulate(arr.begin(), arr.end(), 0);
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    int students = countStudents(arr, mid);
    if (studnets > m)
    {
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }
  return l;
}

// BS 19. Painter's Partition and Split Array - Largest Sum
int countPainters(vector<int> &arr, int sum)
{
  int painters = 1;
  long long sumPainter = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (sumPainter + arr[i] <= sum)
    {
      sumPainter += arr[i];
    }
    else
    {
      painters++;
      sumPainter = arr[i];
    }
  }
  return painters;
}
int findSum(vector<int> arr, int n, int m)
{
  int l = *max_element(arr.begin(), arr.end());
  int h = accumulate(arr.begin(), arr.end(), 0);
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    int painters = countPainters(arr, mid);
    if (painters > m)
    {
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }
  return l;
}

// BS 21: Median of two Sorted Arrays of Different Sizes | Brute and Better Approach
double median(vector<int> a, vector<int> b)
{
  int n1 = a.size(), n2 = b.size();
  vector<int> arr3;
  int i = 0, j = 0;
  while (i < n1 && j < n2)
  {
    if (a[i] < b[j])
      arr3.push_back(a[i++]);
    else
      arr3.push_back(b[j++]);
  }

  while (i < n1)
    arr3.push_back(a[i++]);
  while (j < n2)
    arr3.push_back(b[j++]);

  int n = n1 + n2;
  if (n % 2 == 1)
  {
    return (double)arr3[n / 2];
  }
  double median = (arr3[n / 2] + arr3[n / 2 - 1]) / 2.0;
  return median;
}

// 2 better approach
double median(vector<int> a, vector<int> b)
{
  int n1 = a.size(), n2 = b.size();
  int n = n1 + n2;
  int ind2 = n / 2;
  int ind1 = ind2 - 1;
  int cnt = 0;
  int ind1el = -1, ind2el = -1;
  int i = 0, j = 0;
  while (i < n1 && j < n2)
  {
    if (a[i] < b[j])
    {
      if (cnt == ind1)
        ind1el = a[i];
      if (cnt == ind2)
        ind2el = a[i];
      cnt++;
      i++;
    }
    else
    {
      if (cnt == ind1)
        ind1el = b[j];
      if (cnt == ind2)
        ind2el = b[j];
      cnt++;
      j++;
    }
  }
  while (i < n1)
  {
    if (cnt == ind1)
      ind1el = a[i];
    if (cnt == ind2)
      ind2el = a[i];
    cnt++;
    i++;
  }
  while (j < n2)
  {
    if (cnt == ind1)
      ind1el = b[j];
    if (cnt == ind2)
      ind2el = b[j];
    cnt++;
    j++;
  }

  if (n % 2 == 1)
    return (double)ind2el;

  return (double)((double)(ind1el + ind2el)) / 2.0;
}

// optimal
double median(vector<int> &a, vector<int> &b)
{
  int n1 = a.size(), n2 = b.size();
  if (n1 > n2)
    return median(b, a);

  int n = n1 + n2;
  int left = (n1 + n2 + 1) / 2;
  int l = 0, h = n1;
  while (l <= h)
  {
    int mid1 = (l + h) >> 1;
    int mid2 = left - mid1;

    int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

    if (mid1 < n1)
      r1 = a[mid1];
    if (mid2 < n2)
      r2 = b[mid2];
    if (mid1 - 1 >= 0)
      l1 = a[mid1 - 1];
    if (mid2 - 1 >= 0)
      l2 = b[mid2 - 1];

    if (l1 <= r2 && l2 <= r1)
    {
      if (n % 2 == 1)
        return (double)max(l1, l2);
      return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
    }

    else if (l1 > r2)
      h = mid1 - 1;
    else
      l = mid1 + 1;
  }
  return 0;
}

// Bs-22. K-th element of two sorted arrays | Binary Search Approach
int kthElement(vector<int> &a, vector<int> &b, int m, int n, int k)
{
  if (m > n)
    return kthElement(b, a, n, m, k);

  int left = k; // length of left half

  // apply binary search:
  int low = max(0, k - n), high = min(k, m);
  while (low <= high)
  {
    int mid1 = (low + high) >> 1;
    int mid2 = left - mid1;
    // calculate l1, l2, r1 and r2;
    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;
    if (mid1 < m)
      r1 = a[mid1];
    if (mid2 < n)
      r2 = b[mid2];
    if (mid1 - 1 >= 0)
      l1 = a[mid1 - 1];
    if (mid2 - 1 >= 0)
      l2 = b[mid2 - 1];

    if (l1 <= r2 && l2 <= r1)
    {
      return max(l1, l2);
    }

    // eliminate the halves:
    else if (l1 > r2)
      high = mid1 - 1;
    else
      low = mid1 + 1;
  }
  return 0; // dummy statement
}

// BS 23. Row with maximum number of 1s | Binary Search on 2D Arrays
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
  int cnt_max = 0;
  int index = -1;

  for (int i = 0; i < n; i++)
  {
    int cnt = m - lower_bound(matrix[i].begin(), matrix[i].end(), 1);
    if (cnt > cnt_max)
    {
      cnt_max = cnt;
      index = i;
    }
  }
  return index;
}

// BS-24. Search in a 2D Matrix - I | Binary Search of 2D
bool searchMatrix(vector<vector<int>> mat, int target)
{
  int n = mat.size();
  int m = mat[0].size();
  int low = 0, high = m * n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int row = mid / m;
    int col = mid % m;
    if (mat[row][col] == target)
      return true;
    else if (mat[row][col] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return false;
}

// BS-25. Search in a 2D Matrix - II | Binary Search on 2D
bool searchElement(vector<vector<int>> arr, int target)
{
  int n = mat.size();
  int m = mat[0].size();
  int row = 0, col = m - 1;
  while (row < n && col >= 0)
  {
    if (mat[row][col] == target)
      return true;
    else if (mat[row][col] < target)
      row++;
    else
      col--;
  }
  return false;
}

// BS-26. Find Peak Element-II | Binary Search
// 2 adjacent elements are not same TC- o(logm*n)
int findMaxIndex(vector<int> mat, int n, int m, int col)
{
  int maxValue = -1;
  int index = -1;
  for (int i = 0; i < n; i++)
  {
    if (mat[i][col] > maxValue)
    {
      maxValue = mat[i][col];
      index = i;
    }
  }
  return index;
}
vector<int> findPeakGrid(vector<vector<int>> mat)
{
  int n = mat.size();
  int m = mat[0].size();
  int low = 0, high = m - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int maxRowIndex = findMaxIndex(mat, n, m, mid);
    int left = mid - 1 >= 0 ? mat[maRowIndex][mid - 1] : INT_MIN;
    int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : INT_MIN;

    if (mat[matRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
    {
      return {maxRowIndex, mid};
    }
    else if (mat[matRowIndex][mid] < left)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return {-1, -1};
}

// BS-27. Median in a Row Wise Sorted Matrix
int countSmallEqual(vector<vector<int>> matrix, int n, int m, int x)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    cnt += upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
  }
  return cnt;
}

int median(vector<vector<int>> matrix, int m, int n)
{
  int low = INT_MAX, high = INT_MIN;
  int n = matrix.size();
  int m = matrix[0].size();
  for (int i = 0; i < n; i++)
  {
    low = min(low, matrix[i][0]);
    high = max(high, matrix[i][m - 1]);
  }

  int req = (n * m) / 2;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int smallEqual = countSmallEqual(matrix, n, m, mid);
    if (smallEqual <= req)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return low;
}

// BS-20. Minimise Maximum Distance between Gas Stations | 3 Approaches | Heap | Binary Search
