// You are given a string str containing two fractions a/b and c/d, compare them and return the greater. If they are equal, then return "equal".

// Note: The string str contains "a/b, c/d"(fractions are separated by comma(,) & space( )). 

// Examples

// Input: str = "5/6, 11/45"
// Output: 5/6
// Explanation: 5/6=0.8333 and 11/45=0.2444, So 5/6 is greater fraction.

// Input: str = "8/1, 8/1"
// Output: equal
// Explanation: We can see that both the fractions are same, so we'll return a string "equal".

// Input: str = "10/17, 9/10"
// Output: 9/10
// Explanation: 10/17 = 0.588 & 9/10 = 0.9, so the greater fraction is "9/10".

// Expected Time Complexity: O(len|str|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 0<=a,c<=103
// 1<=b,d<=103

class Solution {
    string f, l;
    float getNum(string str, int &i, char c, int n, string &s){
        float num=0;
        while(str[i] != c){
            if(i == n)break;
            s+=str[i];
            num=num*10 + (str[i]-48);
            i++;
        }
        i++;
        return num;
    }
  public:
    string compareFrac(string str) {
        float a, b, c, d;
        int i=0, n=str.size();
        f=""; l="";
        a=getNum(str, i, '/', n, f);
        f+='/';
        b=getNum(str, i, ',', n, f);
        i++;
        c=getNum(str, i, '/', n, l);
        l+='/';
        d=getNum(str, i, 'e', n, l);
        if(a/b > c/d)return f;
        else if(c/d > a/b)return l;
        return "equal";
    }
};