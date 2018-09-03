vector<vector<int>> find_triples(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
    vector<vector<int>>ret;

    int n = nums.size();
    for (int i = 0; i < n-2; ++i)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int lo = i + 1, hi = n - 1;
            int sum = 0 - nums[i];
            while (lo < hi)
            {
                if (nums[lo] + nums[hi] == sum)
                {
                    ret.push_back({ nums[i], nums[lo], nums[hi] });
                    while (lo < hi && nums[lo] == nums[lo + 1])++lo;//跳过重复值
                    while (lo < hi && nums[hi] == nums[hi - 1])--hi;

                    ++lo;
                    --hi;
                }
                else if (nums[lo] + nums[hi] < sum)
                    ++lo;
                else
                    --hi;
            }
        }
    }
    return ret;
}
