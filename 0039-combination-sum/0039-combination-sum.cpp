class Solution {
public:
    void fn(int ind, int s, vector<int>&t, int target, vector<vector<int>>&v, vector<int>&candidates)
    {
        if(ind>=candidates.size() || s>target) return;
        if(s==target) {v.push_back(t); return;}

        t.push_back(candidates[ind]);
        s+=candidates[ind];
        fn(ind, s,t, target, v, candidates);

        s-=candidates[ind];
        t.pop_back();
        fn(ind+1, s,t, target, v, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>t;
        fn(0,0,t,target,v,candidates);
        return v;
    }
};