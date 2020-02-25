#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
#define number_of_text 100

void xor_(string a, string b, char* ans){ 
    for(int i=0; i<64; i++){ 
        if(a[i]==b[i]){ 
            ans[i]= '0'; 
        }else{ 
            ans[i]= '1'; 
        } 
    } 
}

string hex2bin(string s){ 
    unordered_map<char, string> mp; 
    mp['0']= "0000"; 
    mp['1']= "0001"; 
    mp['2']= "0010"; 
    mp['3']= "0011"; 
    mp['4']= "0100"; 
    mp['5']= "0101"; 
    mp['6']= "0110"; 
    mp['7']= "0111"; 
    mp['8']= "1000"; 
    mp['9']= "1001"; 
    mp['a']= "1010"; 
    mp['b']= "1011"; 
    mp['c']= "1100"; 
    mp['d']= "1101"; 
    mp['e']= "1110"; 
    mp['f']= "1111"; 
    string bin=""; 
    for(int i=0; i<s.size(); i++){ 
        bin+= mp[s[i]]; 
    } 
    return bin; 
} 

string permute(string k, int* arr, int n){ 
    string per=""; 
    for(int i=0; i<n ; i++){ 
        per+= k[arr[i]-1]; 
    } 
    return per; 
} 

int main()
{
    ifstream in("out.txt");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect cin to in.txt!

    ofstream out("out_before_perm.txt");
    streambuf *coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf()); //redirect cout to out.txt!
    FILE *f_xor;
    f_xor = fopen("output_xor_before_perm.txt","w+");
    int initial_perm[64]=  
    {    58,50,42,34,26,18,10,2, 
        60,52,44,36,28,20,12,4, 
        62,54,46,38,30,22,14,6, 
        64,56,48,40,32,24,16,8, 
        57,49,41,33,25,17,9,1, 
        59,51,43,35,27,19,11,3, 
        61,53,45,37,29,21,13,5, 
        63,55,47,39,31,23,15,7 
    };
    int inv_p[32] = {
    9, 17, 23, 31,
    13, 28, 2, 18,
    24, 16, 30, 6,
    26, 20, 10, 1,
    8, 14, 25, 3,
    4, 29, 11, 19,
    32, 12, 22, 7,
    5, 27, 15, 21 };
    string word, w1;
    for(int i=0; 2*i<number_of_text; i++){
        cin >> word >> w1;
        string result, r1;
        for(int i=0; i<word.length(); i++){
            stringstream stream;
            stream << hex << (word[i] - 'f');
            result.append( stream.str());   
        }
        for(int i=0; i<w1.length(); i++){
            stringstream stream;
            stream << hex << (w1[i] - 'f');
            r1.append( stream.str());   
        }
        string a1, a2;
        a1 = permute(hex2bin(result), initial_perm, 64);
        a2 = permute(hex2bin(r1), initial_perm, 64);
        cout << a1 << "\n";
        cout << a2 << "\n";
        char a[65];
        a[64]='\0';
        xor_(a1, a2, a);
        fprintf(f_xor, "%s\n", a);
    }
    return 0;
}