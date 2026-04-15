class Solution {
public:
    void merge(int low,int mid,int high,vector<int>& nums){
        vector<int> temp;
        int i=low;
        int j=mid+1;

        while(i<=mid && j<=high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }

        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=high){
            temp.push_back(nums[j++]);
        }

        for(int i = low;i<=high ; i++){
            nums[i] = temp[i-low];
        }
    }

    void mergesort(int low,int high,vector<int>& nums){
        if(low==high) return;

        int mid = low + (high-low)/2;

        mergesort(low,mid,nums);
        mergesort(mid+1,high,nums);

        merge(low,mid,high,nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(0,nums.size()-1,nums);
        return nums;
    }
};