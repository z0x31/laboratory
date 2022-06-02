#include "Stroka.h"
#include "DecStr.h"
using namespace std;

DecStr::DecStr(char val) : Stroka(val)
{
    if (!((pCh[0] >= '1' && pCh[0] <= '9'))) {
        cout << "Bad symbol pCh[0] = " << pCh[0] << endl;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
    }
    cout << "DecStr::DecStr(char val) : Stroka(val)" << endl;
}
DecStr::DecStr(int val) : Stroka(val) {
    cout << "decimal_string::decimal_string(int val) : String(val)" << endl;
}
DecStr::DecStr(const char* str) : Stroka(str) {
    if (!((pCh[0] >= '1' && pCh[0] <= '9') || pCh[0] == '-' || pCh[0] == '+')) { 
        cout << "Bad symbol pCh[0] = " << pCh[0] << endl;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    else {
        for (int i = 1; i < len; i++) {
            if (!(pCh[i] >= '0' && pCh[i] <= '9')) {
                cout << "Bad string, pCh[" << i << "] = " << pCh[i] << endl;
                if (pCh) delete[] pCh;
                len = 0;
                pCh = new char[len + 1];
                pCh[0] = '\0';
                return;
            }
        }
    }
    cout << "DecStr::DecStr(const char* str) : Stroka(str)" << endl;
}
DecStr::DecStr(const DecStr& from) :Stroka(from)
{
    cout << "DecStr::DecStr(const DecStr&from)" << endl;
}
DecStr::~DecStr()
{
    cout << "DecStr::~DecStr()" << endl;
};
DecStr& DecStr::operator=(const DecStr& Ds)
{
    if (&Ds != this)
    {
        delete[]pCh;
        len = strlen(Ds.pCh);
        pCh = new char[len + 1];
        strcpy_s(pCh, len + 1, Ds.pCh);
    }
    cout << "DecStr& DecStr::operator=(const DecStr&Ds)" << endl;
    return *this;
}
DecStr operator+(const DecStr& pobj1, const DecStr& pobj2)
{
    int num1, num2;
    DecStr tmp(pobj1);
    num1 = atoi(tmp.Getstr());
    num2 = atoi(pobj2.Getstr());
    char* pTmpCh;
    int A = num1 + num2;
    if (tmp.len >= pobj2.len)
    {
        pTmpCh = new char[tmp.len + 2];
        _itoa_s(A, pTmpCh, tmp.len + 2, 10);
    }
    else
    {
        pTmpCh = new char[pobj2.len + 2];
        _itoa_s(A, pTmpCh, pobj2.len + 2, 10);
    }
    if (tmp.pCh)
        delete[] tmp.pCh;
    tmp.pCh = pTmpCh;
    tmp.len = strlen(tmp.pCh);
    return tmp;
}
DecStr operator+(const DecStr& pobj1, const int pobj2) {
    int num1, num2, len2 = 0, temp2;
    DecStr temp(pobj1);
    num1 = atoi(pobj1.Getstr());
    num2 = pobj2;
    char* PtmpChar;
    int A = num1 + num2;
    temp2 = A;
    while (temp2) {
        len2++;
        temp2 /= 10;
    }
    if (temp.len >= len2) {
        PtmpChar = new char[temp.len + 2];
        _itoa_s(A, PtmpChar, temp.len + 2, 10);
    }
    else {
        PtmpChar = new char[len2 + 2];
        _itoa_s(A, PtmpChar, len2 + 2, 10);
    }
    if (temp.pCh) delete[] temp.pCh;
    temp.pCh = PtmpChar;
    temp.len = strlen(temp.pCh);
    cout << "DecStr operator+(const DecStr& pobj1, const int pobj2)" << endl;
    return temp;
}
DecStr operator+(const int pobj2, const DecStr& pobj1) {
    int num1, num2, len2 = 0, temp2;
    DecStr temp(pobj1);
    num1 = atoi(pobj1.Getstr());
    num2 = pobj2;
    char* PtmpChar;
    int A = num1 + num2;
    temp2 = A;
    while (temp2) {
        len2++;
        temp2 /= 10;
    }
    if (temp.len >= len2) {
        PtmpChar = new char[temp.len + 2];
        _itoa_s(A, PtmpChar, temp.len + 2, 10);
    }
    else {
        PtmpChar = new char[len2 + 2];
        _itoa_s(A, PtmpChar, len2 + 2, 10);
    }
    if (temp.pCh) delete[] temp.pCh;
    temp.pCh = PtmpChar;
    temp.len = strlen(temp.pCh);
    cout << "DecStr operator+(const int pobj2, const DecStr& pobj1)" << endl;
    return temp;
}