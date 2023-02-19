//Rename file name

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char oldName[]="oldFile.txt";
    char newName[]="newFile.txt";

    if(rename(oldName,newName)==0)
        cout<<"File renamed successfully.";
    else
        cout<<"Error renaming file.";

    return 0;
}