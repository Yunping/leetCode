/*
Problem: LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

===========================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/05/2014
Difficulty: **^
Review: ****
Solution:
    (My Own)
    - Use a list to store all items. The front item is the least recent item, and the last item is the oldest item
    - Use a hash map for quick access by key.
    
    *Note*
    - std::list::splice method: http://www.cplusplus.com/reference/list/list/splice/
    - the iterator in std::list won't be invalid even the node it points is moved.
*/
class LRUCache{
private:
    struct Item {
        int key;
        int value;
        Item(int k, int v) : key(k), value(v) {}
    };
    
    list<Item> cacheList;
    unordered_map<int, list<Item>::iterator> cacheMap;
    int capacity;
    
    void makeLeastRecent(list<Item>::iterator it) {
        cacheList.splice(cacheList.begin(), cacheList, it);
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            makeLeastRecent(cacheMap[key]);
            return cacheMap[key]->value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            if (cacheList.size() == this->capacity) {
                // reach the capacity. remove the oldest one.
                Item back = cacheList.back();
                cacheList.pop_back();
                cacheMap.erase(back.key);
            }
            
            // insert a new Item.
            Item newItem(key, value);
            cacheList.push_front(newItem);
            cacheMap[key] = cacheList.begin();
        } else {
            // update the value and move it to the front
            cacheMap[key]->value = value;
            makeLeastRecent((*it).second);
        }
    }
};