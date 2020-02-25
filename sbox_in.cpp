#include<bits/stdc++.h>
using namespace std;
#define number_of_text 100

string xor_(string a, string b){ 
    string ans= ""; 
    for(int i=0; i<a.size(); i++){ 
        if(a[i]==b[i]){ 
            ans+= "0"; 
        }else{ 
            ans+= "1"; 
        } 
    } 
    return ans; 
} 

int main(){
    ifstream in("sbox_in_before_key.txt");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect cin to in.txt!
    ofstream out("sbox_in_xor.txt");
    streambuf *coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf()); //redirect cout to out.txt!
    string se, se_star;
    for(int i=0; 2*i<number_of_text; i++){
        cin >> se >> se_star;
        cout << xor_(se, se_star) << "\n";
    }
}