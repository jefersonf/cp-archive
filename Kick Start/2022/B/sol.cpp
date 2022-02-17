//Centauri Prime
//Solution: Implementation
#include <iostream>
#include <map>
using namespace std;
int main() {
    
    string vowels = "AEIOUaeiou";
    map<char, bool> v;
    for (int i=0; i<vowels.size(); i++) v[vowels[i]] = true;
    
    int t; cin >> t;
    cin.ignore();
    for (int i=1; i<=t; i++) {
        string s;
        getline(cin, s);
        cout << "Case #" << i << ": " << s;
        int n = s.size();
        if (s[n-1] == 'y' || s[n-1] == 'Y') {
            cout << " is ruled by nobody.\n";
        } else if (v.count(s[n-1])) {
            cout << " is ruled by Alice.\n";
        } else {
            cout << " is ruled by Bob.\n";
        }
    }
    return 0;
}
