/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (49.86%)
 * Likes:    1878
 * Dislikes: 398
 * Total Accepted:    474.9K
 * Total Submissions: 952.4K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number n is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Return True if n is a happy number, and False if not.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 */

// @lc code=start

/*
class Solution {
public:
    int getNext(int n)
    {
        int res = 0;
        while (n != 0) {
            int t = n % 10;
            n /= 10;
            res += t * t;
        }
        
        return res;
    }
    
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        
        while (true) {
            n = getNext(n);
            if (n == 1) return true;
            if (s.count(n) > 0) break;
            s.insert(n);   
        }
        
        return false;
    }
};
*/

class Solution {
public:
    int getNext(int n)
    {
        int res = 0;
        while (n != 0) {
            int t = n % 10;
            n /= 10;
            res += t * t;
        }
        
        return res;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = getNext(slow);
            fast = getNext(fast);
            fast = getNext(fast);
        } while (slow != fast);
        
        return slow == 1; 
    }
};
// @lc code=end

