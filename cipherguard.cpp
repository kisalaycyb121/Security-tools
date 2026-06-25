#include<bits/stdc++.h>
using namespace std;

void line()
{
    cout<<"--------------------------------------------------\n";
}

void pauseScreen()
{
    cout<<"\nPress ENTER to continue...";
    cin.ignore();
    cin.get();
}

string caesarEncrypt(string message,int shift)
{
    string output="";

    shift%=26;

    for(char c:message)
    {
        if(isupper(c))
            output+=char((c-'A'+shift)%26+'A');
        else if(islower(c))
            output+=char((c-'a'+shift)%26+'a');
        else
            output+=c;
    }

    return output;
}