// Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating (in any direction) string 'a' by exactly 2 places.

// Example 1:

// Input:
// a = amazon
// b = azonam
// Output: 
// 1
// Explanation: 
// amazon can be rotated anti-clockwise by two places, which will make it as azonam.
// Example 2:

// Input:
// a = geeksforgeeks
// b = geeksgeeksfor
// Output: 
// 0
// Explanation: 
// If we rotate geeksforgeeks by two place in any direction, we won't get geeksgeeksfor.
// Your Task:
// The task is to complete the function isRotated() which takes two strings as input parameters and checks if given strings can be formed by rotations. The function returns true if string 1 can be obtained by rotating string 2 by two places, else it returns false.

// Expected Time Complexity: O(N).
// Expected Auxilary Complexity: O(N).
// Challenge: Try doing it in O(1) space complexity.

// Constraints:
// 1 ≤ length of a, b ≤ 105

// class Solution{
//     public:
//     //Function to check if a string can be obtained by rotating
//     //another string by exactly 2 places.
//     bool isRotated(string str1, string str2){
//         int size=str1.size();
//         if(size!=str2.size())return false;
//         int t=0;
//         for(int i=0;i<size;i++){
//             int index=(i+2)%size;
//             if(str1[i]!=str2[index]){
//                 t=1;
//                 break;
//             }
//         }
//         if(t==0)return true;
//         for(int i=0;i<size;i++){
//             int index=(size+i-2)%size;
//             if(str1[i]!=str2[index]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2){
        int size=str1.size();
        if(size!=str2.size())return false;
        if(size<2){
            if(size==1){
             if(str1[0]!=str2[0])return false;
            }
            return true;
        }
        string a="",b="";
        a=str1.substr(2,size-2)+str1.substr(0,2);
        b=str1.substr(size-2,2)+str1.substr(0,size-2);
        return a==str2 || b==str2;
    }
};