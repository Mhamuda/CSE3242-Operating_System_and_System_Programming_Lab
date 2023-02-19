//Copy file from one directory to another directory

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;

    ifstream source("originalFile.txt");
    ofstream destination("copyFile.txt");

    if(source.is_open())
    {
        while(getline(source,line))
            destination<<line<<"\n";
        cout<<"File copied successfully.";
        source.close();
    }
    else
        cout<<"Error copying file.";

    destination.close();
    return 0;
}