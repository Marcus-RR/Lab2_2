#include <iostream>
#include <cctype>
#include "Cipher.h"
#include <locale>
using namespace std;
void check(const wstring& Text, const int & key)
{
    wstring s=Text;
    try {
        Cipher kluch(key);
        wcout<<kluch.zakodirovat(key, s)<<endl;
        wstring g=kluch.zakodirovat(key, s);
        wcout<<kluch.raskodirovar(key, g)<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main()
{
    wcout<<L'-'<<endl;
    check(L"",10);
    wcout<<L'-'<<endl;
    check(L"TEXTTOCHECK",10);
    wcout<<L'-'<<endl;
    check(L"TEXTTOCHECK",1);
    wcout<<L'-'<<endl;
    check(L"TEXTTOCHECK",0);
    wcout<<L'-'<<endl;
    check(L"TEXTTOCHECK",3);
    wcout<<L'-'<<endl;
    return 0;
}
