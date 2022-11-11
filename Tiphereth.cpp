#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    // 检测Ego.exe是否运行
    string cmd = "tasklist | findstr Ego.exe";
    FILE *fp = popen(cmd.c_str(), "r");
    char buf[1024] = {0};
    fread(buf, 1, sizeof(buf), fp);
    pclose(fp);
    if (strlen(buf) == 0)
    {
        // 运行Ego.exe
        system("Ego.exe");
    }
    // 如果自己被杀死，就重新运行自己
    cmd = "tasklist | findstr Tiphereth.exe";
    fp = popen(cmd.c_str(), "r");
    memset(buf, 0, sizeof(buf));
    fread(buf, 1, sizeof(buf), fp);
    pclose(fp);
    if (strlen(buf) == 0)
    {
        // 运行自己
        system("Tiphereth.exe");
    }
    return 0;
}

// Path: Tiphereth.cpp
// Compare this snippet from Ego.cpp:
// g++ -o Tiphereth.exe Tiphereth.cpp -std=c++11 -static-libgcc -static-libstdc++