class Solution {
public:

    bool isvow(char c){
        vector<char>v={'a','e','i','o','u','A','E','I','O','U'};
        for(auto ch:v){
            if(ch==c)return true;
        }
        return false;
    }
    string sortVowels(string s) {
        vector<char>v;
        for(auto c:s){
            if(isvow(c))v.push_back(c);

        }
        //sorting done for the vowels
        sort(v.begin(),v.end());

        //puytting the vowel and const in correct place 
        int j=0;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(isvow(s[i])){
                ans+=v[j];
                j++;
            }else {
                ans+=s[i];
            }
        }

        return ans;
       
    }
};