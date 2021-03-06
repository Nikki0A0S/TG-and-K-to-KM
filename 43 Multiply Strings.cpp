//https://leetcode.com/problems/multiply-strings/
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        int i, j, k;
        int lisik=0;
        int temp;
        if(num1=="0" || num2=="0") return "0";
        string result(l1+l2, '0');
        
        for(j=l2-1; j>=0;--j)
        {   
            if(num2[j]=='0') continue;
            for(lisik=0, i=l1-1; i>=0; --i)
            {
                temp = lisik + (num2[j]-'0') * (num1[i]-'0') + result[i+j+1]-'0';
                result[i+j+1] = '0' + temp % 10;
                lisik = temp/10;
            }
            result[j] = lisik+'0';
        }
        if(lisik){
           return result; 
        } 
        else return result.substr(1);
        
    }
};
