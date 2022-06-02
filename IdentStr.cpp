#include "Stroka.h"
#include "IdentStr.h"
using namespace std;

IdentStr::IdentStr(int val) :Stroka(val)
{
    cout << "IdentStr::IdentStr(int val):Stroka(val)" << endl;
}
IdentStr::IdentStr(char ch) : Stroka(ch) {
    if ((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z')) 
        cout << "string_id::string_id(char ch) : String(ch)" << endl;
    else {                                                                   
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        cout << "Bad symbol" << endl;
    }
}
IdentStr::IdentStr(const char* Str) :Stroka(Str)
{
    const char* keyword[] = {
    "while",
    "continue",
    "switch",
    "extern",
    "/0"
    };
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(pCh, keyword[i]) == 0)
        {
            if (pCh[0] >= '0' && pCh[0] <= '9') {
                cout << "Bad symbol pCh[0] = " << pCh[0] << endl;
                if (pCh) delete[] pCh;
                len = 0;
                pCh = new char[len + 1];
                pCh[0] = '\0';
            }
            else {
                for (int i = 1; i < len; i++) { 
                    if (!((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') || (pCh[i] >= '0' && pCh[i] <= '9')) && (pCh[i] != '_') && (pCh[i] != ' ')) {
                        if (pCh) delete[] pCh;
                        len = 0;
                        pCh = new char[len + 1];
                        pCh[0] = '\0';
                    }
                }
            }
        }
    }
    cout << "IdentStr::IdentStr(const char* Str) :Stroka(Str)" << endl;
}
IdentStr& IdentStr::operator=(const IdentStr& S)
{
    if (&S != this)
    {
        delete[] pCh;
        len = strlen(S.pCh);
        pCh = new char[len + 1];
        strcpy_s(pCh, len + 1, S.pCh);
    }
    cout << "IdentStr& IdentStr::operator=(const IsentStr& S)" << endl;
    return *this;
}
char& IdentStr::operator[](int index)
{
    if (index >= 0 && index < len) {
        cout << "char& string_id::operator[](int index)" << endl;
        return pCh[index];
    }
    return pCh[0];
}
IdentStr::IdentStr(const IdentStr& from) : Stroka(from)
{
    cout << "IdentStr::IdentStr(const IdentStr& from) : Stroka(from)" << endl;
}
IdentStr::~IdentStr()
{
    cout << "IdentStr::~IdentStr()" << endl;
}
IdentStr IdentStr::operator~()
{
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = pCh[i];
        pCh[i] = pCh[len - 1 - i];
        pCh[len - 1 - i] = temp;
    }
    cout << "string_id string_id::operator~()" << endl;
    if (pCh[0] >= '0' && pCh[0] <= '9') {
        cout << "Impossible reverse. Bad symbol pCh[0] = " << pCh[0] << endl;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
    }
    return *this;
}
IdentStr operator+ (const IdentStr& pobj1, const IdentStr& pobj2)
{
    IdentStr tmp(pobj1.GetLen() + pobj2.GetLen());
    int i = 0, j = 0;
    while (tmp.pCh[i++] = pobj1.pCh[j++]);
    strcpy_s(tmp.pCh, tmp.len + 1, pobj1.Getstr());
    strcat_s(tmp.pCh, tmp.len + 1, pobj2.Getstr());
    cout << "IdentStr operator+(...)" << endl;
    return tmp;
}
IdentStr operator+ (const IdentStr& pobj1, const char* pobj2)
{
    IdentStr tmp(pobj1.GetLen() + (int)strlen(pobj2));
    strcpy_s(tmp.pCh, tmp.len + 1, pobj1.Getstr());
    strcat_s(tmp.pCh, tmp.len + 1, pobj2);
    cout << "..." << endl;
    return tmp;
}
IdentStr operator+ (const char* pobj1, const IdentStr& pobj2)
{
    IdentStr tmp((int)strlen(pobj1) + pobj2.GetLen());
    strcpy_s(tmp.pCh, tmp.len + 1, pobj1);
    strcat_s(tmp.pCh, tmp.len + 1, pobj2.Getstr());
    cout << "..." << endl;
    return tmp;
}