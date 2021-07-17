#include <bits/stdc++.h>
using namespace std;

void print_mobile(string a) {
    vector<string> mapping = {"2",    "22", "222", "3",   "33", "333", "4",   "44",  "444",
                  "5",    "55", "555", "6",   "66", "666", "7",   "77",  "777",
                  "7777", "8",  "88",  "888", "9",  "99",  "999", "9999"};
    
    string output;
    for(char ch : a){
      if(ch == ' '){
        output += "0";
      }else{
        output += mapping[ch-'A'];
      }
    }

    cout<<output;
}

int main() {
    string s = "HELLO VROMIS";

    print_mobile(s);
}
