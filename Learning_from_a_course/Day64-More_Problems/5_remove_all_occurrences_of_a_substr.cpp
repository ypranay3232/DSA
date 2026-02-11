// given a substring : daabcbaabcbc and substring : abc. remove all the substr from the str.
// so output : dab

// find the left most occurrence and remove it, 

#include<iostream>
#include<string>
using namespace std;

void removesubstr(string &s, string &part){
    // check if the substr exist in the string 
    int found = s.find(part); //find() returns the position of substr (ex: index 2 because the substr/part 'abc' start from there)

    // if substr not found return no position 
    if(found != string::npos){
        // if substring found. now remove the left most string. to do so we concatenate left and right parts (index 0-1 : da) and right string after (abc from index 2,3,4) "baabcbc"
        string left_part = s.substr(0,found); //0 - 2
        string right_part = s.substr(found+part.size(),s.length()); 
        //start from substr (2,3,4) to str length
        
        // we removed left and right string so we can say we got the final string by removing part
        // overwriting the existing string 
        s = left_part + right_part;

        // recursive call : by calling it again 
        removesubstr(s,part);
    }else{
        // Base case : if all the occurrences of the substring has been removed from str. 
        return;
    }
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";

    // function call : 
    removesubstr(s,part);
    cout<<"The final string after removing substring is : "<<s<<endl;
    return 0;
}