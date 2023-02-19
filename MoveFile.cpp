//Move a file from one directory to another

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char oldPath[]="E:\\3Y2S\\Operating System and System Programming Lab\\Practice\\MoveFileTesting\\oldFile.txt.txt";
    char newPath[]="E:\\3Y2S\\Operating System and System Programming Lab\\Practice\\newFile.txt";

    if(rename(oldPath,newPath)==0)
        cout<<"File moved succesfully.";
    else
        cout<<"Error moving file.";

    return 0;
}