/* Given a non-negative integer c, decide whether
 there're two integers a and b such that a2 + b2 = c.  */

 #include<bits/stdc++.h>
 using namespace std;
 bool isSumSquare(int c){
    long int s = sqrt(c);
    if(c ==0 || c==2 || c==4){
        return true;
    }
    long l = 0, r = s;
    while(l<=s){
        if((l*l + r*r) == c){
            return true;
        }
        else if((l*l + r*r)<c){
            l++;
        }
        else if((l*l + r*r)>c){
            r--;
        }
    }
    return false;
    /* using map 
    unordered_map<long, bool> mp;
    long val = 0;
    while(val*val<=c){
        mp[val*val] = true;
        val++;
    }
    val = 0;
    while(val*val<=c){
        if(mp[c-val*val]){
            return true;
        }
        val++;
    }
    return false; */
 }

 // driver code
 int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int c;
     cin>>c;
     cout<<isSumSquare(c);
 }