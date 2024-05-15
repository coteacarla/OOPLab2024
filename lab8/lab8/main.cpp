#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    string MyString;
    ifstream file("input.txt");
    if (!file) {
        cerr << "Error opening file.\n";
        return 1;
    }

    if (!getline(file, MyString)) {
        cerr << "Error reading from file.\n";
        return 1;
    }

    cout << "The string read is: " << MyString << endl;


    for (char& c : MyString) {
        c = tolower(c);
    }

    char c[100];
    strcpy(c, MyString.c_str());
    char* p;
    vector<string> words;


    p = strtok(c, " ;,.");
    while (p) {
        words.push_back(p);
        p = strtok(NULL, " ;,.");
    }


    map<string, int> MyMap;
    for (const string& word : words) {
        MyMap[word]++;
    }

    for (const auto& pair : MyMap) {
        cout << pair.first << " => " << pair.second << endl;
    }

    auto comparator = [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
        };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comparator)> sortedWords(comparator);

    for (const auto& pair : MyMap) {
        sortedWords.push(pair);
    }

    while (!sortedWords.empty()) {
        cout << sortedWords.top().first << " => " << sortedWords.top().second << endl;
        sortedWords.pop();
    }

    return 0;
}
