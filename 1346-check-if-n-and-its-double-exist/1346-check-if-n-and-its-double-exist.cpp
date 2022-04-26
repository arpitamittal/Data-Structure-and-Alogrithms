class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
       sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++)
        {
            for(int j=i+1; j<arr.size(); j++)
            {
                if(2*arr[i] == arr[j] || arr[i] == 2*arr[j])
                    return true;
            }
        }
        return false;
    }
};