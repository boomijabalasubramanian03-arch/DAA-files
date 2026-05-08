#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cout << "Enter number of symbols: ";
    cin >> n;
    char data[100];
    double freq[200];
    int parent[200], left[200], right[200];
    string codes[100];
    for (int i = 0; i < 200; i++) {
        parent[i] = left[i] = right[i] = -1;
    }
    cout << "Enter symbols:\n";
    for (int i = 0; i < n; i++) cin >> data[i];
    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++) cin >> freq[i];
    int size = n;
    while (true) {
        int min1 = -1, min2 = -1;
        for (int i = 0; i < size; i++) {
            if (parent[i] == -1) {
                if (min1 == -1 || freq[i] < freq[min1]) {
                    min2 = min1;
                    min1 = i;
                } else if (min2 == -1 || freq[i] < freq[min2]) {
                    min2 = i;
                }
            }
        }
        if (min2 == -1) break;
        freq[size] = freq[min1] + freq[min2];
        left[size] = min1;
        right[size] = min2;
        parent[min1] = size;
        parent[min2] = size;
        size++;
    }
    cout << "\nHuffman Codes:\n";
    for (int i = 0; i < n; i++) {
        string c = "";
        int curr = i;
        while (parent[curr] != -1) {
            int p = parent[curr];
            if (left[p] == curr) c += "0";
            else c += "1";
            curr = p;
        }
        reverse(c.begin(), c.end());
        codes[i] = c;
        cout << data[i] << " : " << codes[i] << endl;
    }
    string inputStr;
    cout << "\nEnter string to encode: ";
    cin >> inputStr;
    cout << "Encoded string: ";
    for (int i = 0; i < inputStr.length(); i++) {
        for (int j = 0; j < n; j++) {
            if (inputStr[i] == data[j]) {
                cout << codes[j];
                break;
            }
        }
    }
    cout << endl;
    return 0;
}
