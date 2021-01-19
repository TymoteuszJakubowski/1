#include <iostream>
#include <math.h>
#include <sstream>
#include <fstream>
 
using namespace std;
 
bool sprawdz(int liczba)
{
    int ilosc=0;
    int dod =0;
    if(liczba%2==0)
    {
        return false;
    }
 
    for(int i=3;i<=liczba;i+=2)
    {
        while(liczba%i==0)
        {
            liczba/=i;
            dod++;
        }
        if(dod>0)
            ilosc++;
        dod=0;
 
        if(liczba==1)
            break;
 
    }
if(ilosc==3)
    return true;
else
    return false;
}

int main()
{
    fstream plik;
    plik.open("liczby.txt", ios::out|ios::in);
 
    int liczba;
    int z = 0;
 
    while(!plik.eof())
    {
        plik>>liczba;
        z+=sprawdz(liczba);
    }
    cout<<"W "<<z<<"wysępują różne czynniki pierwsze."<<endl;
 
    return 0;
}
