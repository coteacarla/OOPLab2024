#include <iostream>
#include <cstring>

template<typename K, typename V, size_t SIZE = 100>
class Map {
private:
    K keys[SIZE];
    V values[SIZE];
    size_t count;

public:
    Map() : count(0) {}

    void Set(const K& key, const V& value) {
        for (size_t i = 0; i < count; ++i) {
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
        for (size_t i = 0; i < count; ++i) {
            if (keys[i] == key) {
                value = values[i];
                return true;
            }
        }
        return false;
    }

    size_t Count() const {
        return count;
    }

    void Clear() {
        count = 0;
    }

    bool Delete(const K& key) {
        for (size_t i = 0; i < count; ++i) {
            if (keys[i] == key) {
                for (size_t j = i; j < count - 1; ++j) {
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
        for (size_t i = 0; i < otherMap.count; ++i) {
            bool found = false;
            for (size_t j = 0; j < count; ++j) {
                if (keys[j] == otherMap.keys[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    class Iterator {
    private:
        const Map<K, V>& map;
        size_t index;

    public:
        Iterator(const Map<K, V>& m, size_t i) : map(m), index(i) {}

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        void operator++() {
            ++index;
        }

        struct Entry {
            K key;
            V value;
            size_t index;
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

    V& operator[](const K& key) {
        for (size_t i = 0; i < count; ++i) {
            if (keys[i] == key) {
                return values[i];
            }
        }
        keys[count] = key;
        values[count] = V();
        return values[count++];
    }
};

int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto i = m.begin(); i != m.end(); ++i) {
        auto entry = *i;
        std::cout << "Index:" << entry.index << ", Key=" << entry.key << ", Value=" << entry.value << '\n';
    }

    m[20] = "result";

    for (auto i = m.begin(); i != m.end(); ++i) {
        auto entry = *i;
        std::cout << "Index:" << entry.index << ", Key=" << entry.key << ", Value=" << entry.value << '\n';
    }

    return 0;
}
