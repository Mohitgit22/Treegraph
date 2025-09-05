class Solution {
public:
    int cnt= 0;
    void merge(vector<int>& nums, int l, int mid, int r) {
        int l1 = (mid-l) + 1;
        int l2 = r - (mid+1) + 1;

        vector<int> first, second;

        int k = l;
        for(int i = 0; i < l1; i++){
            first.push_back(nums[k++]);
        }
        k = mid + 1;
        for(int j = 0; j < l2; j++){
            second.push_back(nums[k++]);
        }
       
        int i = 0;
        int j = 0;
        for(; i < l1; i++) {
            while(j < l2 && (long long)first[i] > 2LL * second[j]) {
                j++;
            }
            cnt += j;
        }
        
        i = 0, j = 0;
        k = l;
        while(i < l1 and j < l2 ){
            if(first[i] < second[j]){
                nums[k] = first[i];
                i++;
                k++;
            }
            else {
                nums[k] = second[j];
                j++;
                k++;
            }
        }

        while(i < l1){
            nums[k++] = first[i++];
        }
        while(j < l2){
            nums[k++] = second[j++];
        }

    }
    void mergesort(vector<int>& nums, int l, int r) {
        if(l >= r)
        return ;
      
        int mid = l + (r-l)/2;
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, 0, n-1);
        cout<<cnt<<endl;
        return cnt;
    }
};