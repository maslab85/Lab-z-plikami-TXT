#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    cout << "Programoperacja na Plikach TXT!\n";

    fstream plik;
    fstream plik2;
    string napis;
    string linia;

    plik.open("miasta.txt", ios::in );
    plik2.open("miasta2.txt", ios::in | ios::out | ios::app);

    if (plik.good() == true)
    {
        cout << "Uzyskano dostep do pliku!" << endl;   
    }
    else cout << "Dostep do pliku zostal zabroniony!" << endl;

    if (plik2.good() == true)
    {
        cout << "Uzyskano dostep do pliku!" << endl; 
    }
    else cout << "Dostep do pliku zostal zabroniony!" << endl;
    
    while (getline(plik, napis))
        cout << napis;

    int dlugosc = napis.length();
    int c = 0;
    for (int a = 0; a < dlugosc; a++)
    {
       
        if (napis[a] == ' ') 
        {
            for (int b = c; b < a; b++) 
            {
            
                linia=napis[b];
                plik2<< linia;
                if (b == a - 1) 
                {
                    plik2 <<" \n\n";
                    c = a+1;
                }
            }
        }
    }
    plik.close();
    plik2.close();
}
