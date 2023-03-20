#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool Include(const char* s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] == 'A' &&
            s[i + 1] == 'G' &&
            s[i + 2] == 'A') ||
            (s[i] == 'O' &&
                s[i + 1] == 'G' &&
                s[i + 2] == 'O'))
            return true;
    }
    return false;
}
char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 3)
        return str;
    char* tmp = new char[len * 2 / 3 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;
    while (i < len && str[i + 2] != 0)
    {
        if ((str[i] == 'A' &&
            str[i + 1] == 'G' &&
            str[i + 2] == 'A') ||
            (str[i] == 'O' &&
                str[i + 1] == 'G' &&
                str[i + 2] == 'O'))
        {
            strcat(t, "**");
            t += 2;
            i += 3;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';
    strcpy(str, tmp);
    return tmp;
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    if (Include(str))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    char* dest = new char[151]; dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
