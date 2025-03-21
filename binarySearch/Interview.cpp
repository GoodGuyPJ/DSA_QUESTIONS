// Find First & Last Position Of Element In Sorted Array
class Solution
{
public:
  int findleftMost(vector<int> &nums, int target, int n)
  {
    int l = 0, r = n - 1;
    int leftMost = -1;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target)
      {
        leftMost = mid;
        r = mid - 1;
      }
      else if (nums[mid] < target)
      {
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }
    return leftMost;
  }
  int findrightMost(vector<int> &nums, int target, int n)
  {
    int l = 0, r = n - 1;
    int rightMost = -1;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target)
      {
        rightMost = mid;
        l = mid + 1;
      }
      else if (nums[mid] < target)
      {
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }
    return rightMost;
  }
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int n = nums.size();
    int left_most = findleftMost(nums, target, n);
    int right_most = findrightMost(nums, target, n);

    return {left_most, right_most};
  }
};

// Find Minimum in Rotated Sorted Array
class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
      int mid = l + (r - l) / 2;
      if (nums[mid] > nums[r])
      {
        l = mid + 1;
      }
      else
      {
        r = mid;
      }
    }
    return nums[r]; // or nums[l]
  }
};
