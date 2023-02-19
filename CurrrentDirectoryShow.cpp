// Showing working current directory

#include <bits/stdc++.h>
#include <unistd.h> //(for getcwd() function) "unistd. h" is the name of the header file that provides access to the POSIX operating system API
using namespace std;

int main()
{
    char dir[2048];           // 2048 is the maximum length of a path
    getcwd(dir, sizeof(dir)); // getcwd() function returns current working directory

    cout << "Current working directory: " << dir << "\n";

    return 0;
}
