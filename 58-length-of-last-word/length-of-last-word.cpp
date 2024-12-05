class Solution {
public:
    int lengthOfLastWord(string s) {
       int t= s.length();
       int count=0;

       while(t>0 && s[t-1]== ' '  ){
        t--;
       } 
       while(t>0 && s[t-1]!= ' '){
        count++;
        t--;
       }
       return count;
    }
};