//https://leetcode.com/problems/integer-to-roman/submissions/
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> roman;
        roman[1000] = "M";
        roman[500] = "D";
        roman[100] = "C";
        roman[50] = "L";
        roman[10] = "X";
        roman[5] = "V";
        roman[1] = "I";

        vector<int> keys = {5000,1000,500,100,50,10,5,1};
        string ans = "";

        int start = 1000;
        int i=0;
        while(num/start==0){
            start/=10;
            i+=2;
        }

        while(num!=0){
            if(num/start==9){
                ans += roman[keys[i+1]] + roman[keys[i-1]];
                num -= start * (num/start);
                start /= 10;
                i+=2;
            }
            else if(num/start==4){
                i++;
                ans += roman[keys[i]] + roman[keys[i-1]];
                num -= start * (num/start);
                start /= 10;
                i++;
            }
            //8 7 6 5 3 2 1
            else if(num/start>=keys[i]/start){
                ans += roman[keys[i]];
                num -= keys[i];
                if(num/start==0){
                    start /= 10;
                    i+=2;
                }
            }
            else{
                i++;
                while(num/start!=0){
                    ans+=roman[keys[i]];
                    num -= keys[i];
                }
                start /= 10;
                i++;
            }
        }
        return ans;
    }
};
