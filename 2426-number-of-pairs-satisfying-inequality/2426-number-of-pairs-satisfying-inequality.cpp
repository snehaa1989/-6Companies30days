class Solution {
public:
    long long d,cnt=0;
    void merge(int s,int m,int e,vector<int>& v) {
        vector<int> v1,v2;
        for (int i=s;i<=m;i++) v1.push_back(v[i]);
        for (int i=m+1;i<=e;i++) v2.push_back(v[i]);
        int i=0,j=0,k=s;
        while (j<v2.size()) {
            while (i<v1.size()&&v1[i]-d<=v2[j]) i++;
            j++;
            cnt+=i;
        }
        i=0,j=0;
        while (i<v1.size()&&j<v2.size()) {
            if (v1[i]<v2[j]) {
                v[k++]=v1[i++];
            }
            else {
                v[k++]=v2[j++];
            }
        }
        if (i==v1.size()) {
            while (j<v2.size()) v[k++]=v2[j++];
        }
        else {
            while (i<v1.size()) v[k++]=v1[i++];
        }
    }
    void mergeSort(int s,int e,vector<int> &nums1) {
        if (s>=e) return;
        int m=(s+e)>>1;
        mergeSort(s,m,nums1);
        mergeSort(m+1,e,nums1);
        merge(s,m,e,nums1);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        d=diff;
        for (int i=0;i<nums1.size();i++) {
            nums1[i]-=nums2[i];
        }
        mergeSort(0,nums1.size()-1,nums1);
        return cnt;
    }
};