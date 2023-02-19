// Delete file from a directory

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char path[] = "E:\\3Y2S\\Operating System and System Programming Lab\\Practice\\TestDelete.txt";

    if (remove(path) == 0)
        cout << "File deleted successfully.";
    else
        cout << "Error deleting file.";

    return 0;
}