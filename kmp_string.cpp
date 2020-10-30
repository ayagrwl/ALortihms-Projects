/*
Usage:
compile: g++ kmp_string -o kmp_string
run on terminal:  kmp_string <key> <pattern>
where <key>  is the string to be search
and <pattern> is the string in which to search.

example: 
~ kmp_string ayag someayaggood
output: The given key exists, starting at index 4
*/

#include<iostream>
using namespace std;

int find_string(string &key, string &pat){
    int nk = key.length();
    int nt = nk + 1 + pat.length();
    
    string comb = key + "#" + pat;
    int* LPS = new int[nt];
    LPS[0] = 0;
    for(int i=1, len = 0;i<nt;){
        if(comb[i] == comb[len]){
            LPS[i++] = ++len;
        } else {
            if(len == 0){
                LPS[i++] = 0;
            } else {
                len = LPS[len-1];
            }
        }
    }   

    for(int i=nk+1;i<nt;i++){
        if(LPS[i] == nk) return i - 2*nk;
    }
    return -1;
}


int main(int argc, char** argv){
    if(argc < 3){
        cout<<"A program to find a string <key> in another string <pattern> in linear time\n Usage: \n\
        compile the file using: g++ kmp_string.cpp -o kmp_string \n run: kmp_string <key> <pattern>\n";
        return -1;
    }
    string key = argv[1];
    string pat = argv[2];
    int ans = find_string(key, pat);

    if(ans < 0){
        cout<<"The given key does not exist in the pattern\n";
    } else {
        cout<<"The given key exists, starting at index "<<ans<<"\n";
    }
    return 0;
}