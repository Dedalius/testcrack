#include <bits/stdc++.h>
#include <cstring>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    int o1K = 0, o2K = 0, iK = 0;
    string o1 = "output1", o2 = "output2";
    string inp = "input";
    string pr[3];
    bool used[argc];
    for(int i = 0; i < argc; i++)
    {
        used[i] = 0;
    }
    int pr_num = 0;
    for(int i = 1; i < argc; i++)
    {
        if(used[i])continue;
        if(strcmp(argv[i],"-o1") == 0)
        {
            if(o1K)
            {
                cout << "error: double use of the -o1 flag";
                exit(0);
            }
            if(i + 1 >= argc)
            {
                cout << "error: the -o1 flag element is missing";
                exit(0);
            }
            o1K = 1;
            o1 = argv[i + 1];
            used[i] = 1;
            used[i + 1] = 1;
            continue;
        }
        if(strcmp(argv[i],"-o2") == 0)
        {
            if(o2K)
            {
                cout << "error: double use of the -o2 flag";
                exit(0);
            }
            if(i + 1 >= argc)
            {
                cout << "error: the -o2 flag element is missing";
                exit(0);
            }
            o2K = 1;
            o2 = argv[i + 1];
            used[i] = 1;
            used[i + 1] = 1;
            continue;
        }
        if(strcmp(argv[i],"-i") == 0)
        {
            if(iK)
            {
                cout << "error: double use of the -i flag";
                exit(0);
            }
            if(i + 1 >= argc)
            {
                cout << "error: the -i flag element is missing";
                exit(0);
            }
            iK = 1;
            inp = argv[i + 1];
            used[i] = 1;
            used[i + 1] = 1;
            continue;
        }
        if(pr_num > 2)
        {
            break;
            cout << "error: it was expected a smaller number of identification";
            exit(0);
        }
        pr[pr_num] = argv[i];
        pr_num++;
    }
begin:
    for(int i = 0; i < 3; i++)
    {
        string com = "start /b " + pr[i];
        //cout << com << endl;
        system(com.c_str());
    }
    string com = "fc ";
    com += o1;
    com += ' ';
    com += o2;
    com += "> nul";
    if(system(com.c_str()))
    {

        cout << "bad test found\n    successful\n\n";
        cout << "***** " << o1 << endl;
        com = "type " + o1;

        system(com.c_str());
        cout << endl;
        cout << "***** " << o2 << endl;
        com = "type " + o2;

        system(com.c_str());
        cout << endl;
        cout << "*****" << endl;
        exit(0);
    }
    goto begin;
}
