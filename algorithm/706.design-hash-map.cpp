/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 *
 * https://leetcode.com/problems/design-hashmap/description/
 *
 * algorithms
 * Easy (58.62%)
 * Likes:    632
 * Dislikes: 85
 * Total Accepted:    69.7K
 * Total Submissions: 118.1K
 * Testcase Example:  '["MyHashMap","put","put","get","get","put","get", "remove", "get"]\n' +
  '[[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]'
 *
 * Design a HashMap without using any built-in hash table libraries.
 * 
 * To be specific, your design should include these functions:
 * 
 * 
 * put(key, value) : Insert a (key, value) pair into the HashMap. If the value
 * already exists in the HashMap, update the value.
 * get(key): Returns the value to which the specified key is mapped, or -1 if
 * this map contains no mapping for the key.
 * remove(key) : Remove the mapping for the value key if this map contains the
 * mapping for the key.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MyHashMap hashMap = new MyHashMap();
 * hashMap.put(1, 1);          
 * hashMap.put(2, 2);         
 * hashMap.get(1);            // returns 1
 * hashMap.get(3);            // returns -1 (not found)
 * hashMap.put(2, 1);          // update the existing value
 * hashMap.get(2);            // returns 1 
 * hashMap.remove(2);          // remove the mapping for 2
 * hashMap.get(2);            // returns -1 (not found) 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All keys and values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashMap library.
 * 
 * 
 */

// @lc code=start
class MyHashMap {
public:
    enum {
        kSize = 20011
    };

    struct Node {
        int key;
        int val;
    };

private:
    vector<list<Node>> vec;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        vec = vector<list<Node>>(kSize);    
    }

    list<Node>::iterator find(int key) {
        int index = key % kSize;
        auto& nodes = vec[index];

        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            if (it->key == key) return it;
        }

        return nodes.end();
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto it = find(key);
        
        int index = key % kSize;
        auto& nodes = vec[index];
        if (it != nodes.end()) {
            it->val = value;
        } else {
            Node n = {key, value};
            nodes.emplace_back(n);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto it = find(key);
        
        int index = key % kSize;
        auto& nodes = vec[index];
        if (it != nodes.end()) {
            return it->val;
        }

        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto it = find(key);
        
        int index = key % kSize;
        auto& nodes = vec[index];
        if (it != nodes.end()) {
            nodes.erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

