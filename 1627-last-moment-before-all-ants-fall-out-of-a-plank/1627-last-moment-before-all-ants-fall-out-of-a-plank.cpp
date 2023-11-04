class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int res=0;
        for(int &x:left){
            res=max(res,x);
        }

        for(int &t:right){
            res=max(res,n-t);
        }

        return res;
    }
};