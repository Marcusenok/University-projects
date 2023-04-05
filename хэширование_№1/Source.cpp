#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>
using namespace std;

int _key(int key)
{
    key *= key;
    key >>= 11;
    return key % 1024;
}

int main()
{
    vector<int> keys;
    vector<string> words = { "Никель 3445" , "Алюминий 4535" , "Марганец 6534", "Медь 7453" };
    int key;
    setlocale(LC_ALL, "rus");
    bool in_keys;
    for (int i = 0; i < 4; i++) 
    { 
        in_keys = false;
        key = _key(4568 + i);
        for (auto it = keys.begin(); it != keys.end(); it++)
        {
            if (key == *it) in_keys = true;
        }
        if(!in_keys) keys.push_back(key);
    }

    for (int i = 0; i < 4; i++)
    {
        cout << words[i] << " код: " << keys[i] << endl;
    }

    return 0;
}
