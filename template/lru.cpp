#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
	typedef pair<int, int> PII;
	typedef list<PII>::iterator IT;

    LRUCache(int capacity): capacity(capacity) {

    }
    
    int get(int key) {
		if(cache.find(key) == cache.end()) return -1;
		IT it = cache[key];
		lru.splice(lru.begin(), lru, it);
		return it->second;
    }
    
    void put(int key, int value) {
		if(cache.find(key) != cache.end()) {
			IT it = cache[key];
			it->second = value;
			lru.splice(lru.begin(), lru, it);
			return;
		}
		if(cache.size() == capacity) {
			IT it = lru.end();
			it--;
			cache.erase(it->first);
			lru.erase(it);
		}
		lru.push_front(PII(key, value));
		cache[key] = lru.begin();
    }
private:
	int capacity;
	unordered_map<int, IT> cache;
	list<PII> lru;
};