// There are times when your answer is a floating point that contains the undesired amount of digits after the decimal. Here, we'll learn how to get a precise answer out of a floating number. You are given two floating numbers a and b. You need to output a/b and decimal precision of a/b up to 3 places after the decimal point.
// Note: You may use System.out.format()

// Example 1:

// Input:
// a = 5.43, b = 2.653
// Output:
// 2.0467393 2.047
// Explanation:
// a/b and decimal precision of a/b up to 3 places after the decimal point are given.

// Example 2:

// Input: 
// a = 3.25, b = 2.5
// Output: 
// 1.3 1.300
// Explanation:
// a/b and decimal precision of a/b up to 3 places after the decimal point are given.

// User Task:

// Your task is to complete the provided function printInFormat().
// Note: You don't need to give a new line character after using System.out.format().

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= a, b <= 109


class Geeks{
    static void printInFormat(float a, float b){
        float result = a/b;
        System.out.print(result+" ");
        System.out.printf("%.3f",result);
        // Your code here to print upto 3 decimal places
    }    
}