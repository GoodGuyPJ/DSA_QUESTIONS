// 1 - Two Sum
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            int rem = target - nums[i];
            if (mpp.find(rem) != mpp.end())
            {
                return {mpp[rem], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};

// 2 - Two sum II - Input array is sorted
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum > target)
            {
                j--;
            }
            else if (sum < target)
                i++;
            else
            {
                return {i + 1, j + 1};
            }
        }
        return {};
    }
};

// 3 - Three Sum
class Solution
{
public:
    vector<vector<int>> res;
    void twoSum(vector<int> &nums, int target, int i, int j)
    {
        int n = nums.size();
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum > target)
                j--;
            else if (sum < target)
                i++;
            else
            {
                while (i < j && nums[i] == nums[i + 1])
                    continue;
                while (i < j && nums[j] == nums[j - 1])
                    continue;
                res.push_back({-target, nums[i], nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return {};

        sort(begin(nums), end(nums));
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int n1 = nums[i];

            int target = -n1;
            twoSum(nums, target, i + 1, n - 1);
        }
        return res;
    }
};

// 4 - Trapping Rain Water | without stack
class Solution
{
public:
    vector<int> getleftmax(vector<int> &height, int &n)
    {
        vector<int> leftmax(n);
        leftmax[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }
        return leftmax;
    }
    vector<int> getrightmax(vector<int> &height, int &n)
    {
        vector<int> rmax(n);
        rmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rmax[i] = max(rmax[i + 1], height[i]);
        }
        return rmax;
    }

    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> leftMax = getleftmax(height, n);
        vector<int> rightMax = getrightmax(height, n);

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int h = min(leftMax[i], rightMax[i]) - height[i];
            sum += h;
        }
        return sum;
    }
};

// 5 - 3Sum Closest
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        int closestSum = 100000;
        sort(begin(nums), end(nums));
        for (int k = 0; k < n; k++)
        {
            int i = k + 1;
            int j = n - 1;
            while (i < j)
            {
                int sum = nums[k] + nums[i] + nums[j];
                if (abs(target - sum) < abs(target - closestSum))
                {
                    closestSum = sum;
                }
                if (sum > target)
                    j--;
                else
                {
                    i++;
                }
            }
        }
        return closestSum;
    }
};

// 6 - Factorial Of Large Numbers
class Solution
{
public:
    void multiply(vector<int> &arr, int &size, int multiplier)
    {
        int carry = 0;
        for (int i = 0; i < size; i++)
        {
            int res = multiplier * arr[i];
            res = res + carry;
            arr[i] = res % 10;
            carry = res / 10;
        }

        // carry 12
        while (carry > 0)
        {
            arr[size] = carry % 10;
            size++;

            carry = carry / 10;
        }
    }

    vector<int> factorial(int N)
    {
        vector<int> arr(10000, 0);
        arr[0] = 1; // 1 put for multiplication
        int size = 1;

        for (int multiplier = 2; multiplier <= N; multiplier++)
        {
            multiply(arr, size, multiplier);
        }

        vector<int> result;
        for (int i = size - 1; i >= 0; i--)
        {
            result.push_back(arr[i]);
        }
        return result;
    }
};

// 7 -  Next Permutation
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int gola_index = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                gola_index = i;
                break;
            }
        }

        if (gola_index != -1)
        {
            for (int i = n - 1; i > gola_index; i--)
            {
                if (nums[i] > nums[gola_index])
                {
                    swap(nums[i], nums[gola_index]);
                    break;
                }
            }
        }
        reverse(nums.begin() + gola_index + 1, end(nums));
    }
};

// 8 - Rotate Image
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < m; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// 9 - Container With Most Water
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();

        int maxWater = 0;
        int i = 0, j = n - 1;
        while (i < j)
        {
            int w = j - i;
            int h = min(height[i], height[j]);

            int area = w * h;
            maxWater = max(maxWater, area);

            if (height[i] > height[j])
                j--;
            else
                i++;
        }
        return maxWater;
    }
};

// 10 -Spiral Matrix
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int row = matrix.size();
        int col = matrix[0].size();

        /*
        dir 0 left to right
        dir 1 top to down
        dir  2 right to left
        dir 3 down to top
        */
        int dir = 0;
        int left = 0, right = col - 1, top = 0, down = row - 1;
        while (top <= down && left <= right)
        {
            if (dir == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            if (dir == 1)
            {
                for (int i = top; i <= down; i++)
                {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    res.push_back(matrix[down][i]);
                }
                down--;
            }
            if (dir == 3)
            {
                for (int i = down; i >= top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if (dir == 4)
            {
                dir = 0;
            }
        }
        return res;
    }
};

// 11 - Group Anagrams | using sorting (n*klog(k))
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        vector<vector<string>> res;
        map<string, vector<string>> mpp;
        for (int i = 0; i < n; i++)
        {
            string str = strs[i];
            sort(begin(str), end(str));
            mpp[str].push_back(strs[i]);
        }
        for (auto it : mpp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};

// 12 - Group Anagrams | without sorting

class Solution
{
public:
    string generate(stirng &word)
    {
        int arr[26] = {0};

        for (char &ch : word)
        {
            arr[ch - 'a']++;
        }
        stirng new_word = "";
        for (int i = 0; i < 26; i++)
        {
            int freq = arr[i];
            if (freq > 0)
            {
                new_word += string(freq, i + 'a');
            }
        }
        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mpp;
        for (int i = 0; i < n; i++)
        {
            string word = strs[i];
            string new_word = generate(word);
            mpp[new_word].push_back(strs[i]);
        }
        for (auto it : mpp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};

// 13 - Sort the Matrix Diagonally
//  a. [i -j] - lower diagonal
//  b. [i+j] - upper diagonal
class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {

        int n = mat.size();
        int m = mat[0].size();

        // store diganal matrix
        map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mpp[i - j].push_back(mat[i][j]);
            }
        }
        // sort them
        for (auto &it : mpp)
        {
            sort(it.second.begin(), it.second.end());
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                mat[i][j] = mpp[i - j].back();
                mpp[i - j].pop_back();
            }
        }
        return mat;
    }
};

// 14 - Diagonal Traverse
//  [i+j] - upper diagonal
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> mp;
        vector<int> res;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for (auto &it : mp)
        {
            if (flip)
            {
                reverse(it.second.begin(), it.second.end());
            }
            for (int &num : it.second)
            {
                res.push_back(num);
            }
            flip = !flip;
        }
        return res;
    }
};

// 15 - Sort Colors

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0, k = n - 1;
        while (j <= k)
        {
            if (nums[j] == 0)
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else if (nums[j] == 1)
            {
                j++;
            }
            else
            {
                swap(nums[j], nums[k]);
                k--;
            }
        }
    }
};

// 16 - Find Original Array From Doubled Array

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int n = changed.size();
        if (n % 2 != 0)
        {
            return {};
        }
        sort(changed.begin(), end(changed));

        map<int, int> mpp;

        vector<int> res;

        for (auto &num : changed)
        {
            mpp[num]++;
        }

        for (auto &num : changed)
        {
            int twice = 2 * num;

            if (mpp[num] == 0)
                continue;

            if (mpp.find(twice) == mpp.end() || mpp[twice] == 0)
            {
                return {};
            }
            res.push_back(num);

            mpp[num]--;
            mpp[twice]--;
        }

        return res;
    }
};

// 17 - Sum of Even Numbers After Queries
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int q = queries.size();

        int sumEven = 0;
        vector<int> res;

        // find sumEven
        for (int &x : nums)
        {
            if (x % 2 == 0)
            {
                sumEven += x;
            }
        }

        for (int i = 0; i < q; i++)
        {
            int val = queries[i][0];
            int idx = queries[i][1];

            if (nums[idx] % 2 == 0)
            {
                sumEven -= nums[idx];
            }

            nums[idx] += val;

            if (nums[idx] % 2 == 0)
            {
                sumEven += nums[idx];
            }

            res.push_back(sumEven);
        }

        return res;
    }
};

// 18 - Find Pivot Index | Equilibrium Index/Point
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        for (int &x : nums)
        {
            sum += x;
        }
        int cs = 0;

        for (int i = 0; i < n; i++)
        {
            int ls = cs;
            int rs = sum - cs - nums[i];

            if (ls == rs)
            {
                return i;
            }
            cs += nums[i];
        }
        return -1;
    }
};

// 19 - Increasing Triplet Subsequence
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();

        int num1 = INT_MAX;
        int num2 = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int num3 = nums[i];

            if (num3 <= num1)
            {
                num1 = num3;
            }
            else if (num3 < num2)
            {
                num2 = num3;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

// 20 - Largest Perimeter Triangle
class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));

        for (int i = n - 3; i >= 0; i--)
        {
            if (nums[i] + nums[i + 1] > nums[i + 2])
            {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};

// 21 - Contains Duplicate II
