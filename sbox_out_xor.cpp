#include<bits/stdc++.h>
using namespace std;
#define number_of_text 100

string permute(string k, int* arr, int n){ 
    string per=""; 
    for(int i=0; i<n ; i++){ 
        per+= k[arr[i]-1]; 
    } 
    return per; 
}



int main(){
    ifstream in("output_xor_before_perm.txt");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect cin to in.txt!

    ofstream out("sbox_out_xor.txt");
    streambuf *coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf()); //redirect cout to out.txt!
    string t1, r, s_i_dash;
    int inv_p[32] = {
    9, 17, 23, 31,
    13, 28, 2, 18,
    24, 16, 30, 6,
    26, 20, 10, 1,
    8, 14, 25, 3,
    4, 29, 11, 19,
    32, 12, 22, 7,
    5, 27, 15, 21 };
    for(int i=0; 2*i<number_of_text; i++){
        cin >> t1;
        r = t1.substr(32, 64);
        s_i_dash = permute(r, inv_p, 32);
        cout << s_i_dash << "\n"; 
    }
    return 0;
    // F' = a' ^ D' ^ l'
}