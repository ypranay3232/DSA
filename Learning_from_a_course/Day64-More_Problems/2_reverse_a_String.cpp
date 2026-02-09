// given a string s = "abcd" we initialize start and end, start = 0, end = size()-1 and we swap start with end

#include<iostream>
#include<string>
using namespace std;

void reverse(string &s,int start, int end){

    // base condition : 
    if(start>=end){
        return ;
    }

    // condition : 
    swap(s[start], s[end]);

    // recursion : 
    reverse(s,start+1,end-1);//move both start and end.
}
int main(){
    cout<<"Enter a string : "<<endl;
    string s;
    cin>>s;

    reverse(s,0,s.size()-1);
    cout<<"Reversed string is : "<<endl;
    cout<<s<<endl;
    return 0;
}