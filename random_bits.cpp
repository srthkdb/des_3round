#include <bits/stdc++.h>
using namespace std;
#define number_of_text 100

string permute(string k, int* arr, int n){ 
    string per=""; 
    for(int i=0; i<n ; i++){ 
        per+= k[arr[i]-1]; 
    } 
    return per; 
} 

void xor_(string a, string b, char* ans){ 
    for(int i=0; i<a.size(); i++){ 
        if(a[i]==b[i]){ 
            ans[i]= '0'; 
        }else{ 
            ans[i]= '1'; 
        } 
    } 
} 

int main(){
  int final_perm[64] = { 40, 8, 48, 16, 56, 24, 64, 32, 
                           39, 7, 47, 15, 55, 23, 63, 31, 
                           38, 6, 46, 14, 54, 22, 62, 30, 
                           37, 5, 45, 13, 53, 21, 61, 29, 
                           36, 4, 44, 12, 52, 20, 60, 28, 
                           35, 3, 43, 11, 51, 19, 59, 27, 
                           34, 2, 42, 10, 50, 18, 58, 26, 
                           33, 1, 41, 9, 49, 17, 57, 25 };
  long long int r;
   std::ofstream out("random_input.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf());
    FILE *f_xor;
    f_xor = fopen("input_xor.txt","w+");
  for(int i=0; 2*i<number_of_text; i++){
    string sl1, sl2, sr, a, b;
    for(int j=0; j<32; j++){
      r = rand()%2; 
      sl1+= r + 48;
    }
    for(int j=0; j<32; j++){
      r = rand()%2; 
      sl2+= r + 48;
    }
    for(int j=0; j<32; j++){
      r = rand()%2; 
      sr+= r + 48;
    }
    string S1=sl1+sr;
    string S2=sl2+sr;
    string perm1 = permute(S1, final_perm, 64);
    string perm2 = permute(S2, final_perm, 64);   
    for(int l = 0 ; l < 16 ; l++)
     {
       int h1,h2;
       h1 = (perm1[l*4]-48)*8+(perm1[l*4+1]-48)*4+(perm1[l*4+2]-48)*2+(perm1[l*4+3]-48);
       h2 = (perm2[l*4]-48)*8+(perm2[l*4+1]-48)*4+(perm2[l*4+2]-48)*2+(perm2[l*4+3]-48);
       h1 += 102;
       h2 += 102;
       a += (char)h1;
       b += (char)h2;
     }
    cout << a << "\n" << b << "\n";
    char x[65];
    xor_(S1, S2, x);
    x[64] = '\0';
    fprintf(f_xor, "%s\n", x);
  }
  return 0;
}
