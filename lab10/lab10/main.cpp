#include <iostream>
#include <cstring>

template<typename K, typename V, int SIZE = 100>
class Map {
private:
    K keys[SIZE];
    V values[SIZE];
    int count;

public:
    Map() : count(0) {}

    void Set(const K& key, const V& value) {
        for (int i = 0; i < count; ++i) {
            if (keys[i] == key) {
                values[i] = value;
                return;
            }
        }
        keys[count] = key;
        values[count] = value;
        ++count;
    }

    bool Get(const K& key, V& value) const {
        for (int i = 0; i < count; ++i) {
            if (keys[i] == key) {
                value = values[i];
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return count;
    }

    void Clear() {
        count = 0;
    }

    bool Delete(const K& key) {
        for (int i = 0; i < count; ++i) {
            if (keys[i] == key) {
                for (int j = i; j < count - 1; ++j) {
                    keys[j] = keys[j + 1];
                    values[j] = values[j + 1];
                }
                --count;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& otherMap) const {
        for (int i = 0; i < otherMap.count; ++i) {
            bool ok = false;
            for (int j = 0; j < count; ++j) {
                if (keys[j] == otherMap.keys[i]) {
                    ok= true;
                    break;
                }
            }
            if (!ok) {
                return false;
            }
        }
        return true;
    }
    V& operator[](const K& key) {
        for (int i = 0; i < count; ++i) {
            if (keys[i] == key) {
                return values[i];
            }
        }
        keys[count] = key;
        values[count] = V();
        return values[count++];
    }

    class Iterator {
    private:
        const Map<K, V>& map;
        int index;

    public:
        Iterator(const Map<K, V>& m, int i) : map(m), index(i) {}

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        void operator++() {
            ++index;
        }

        struct Entry {
            K key;
            V value;
            int index;
        };

        Entry operator*() const {
            return { map.keys[index], map.values[index], index };
        }
    };

    Iterator begin() const {
        return Iterator(*this, 0);
    }

    Iterator end() const {
        return Iterator(*this, count);
    }


};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
