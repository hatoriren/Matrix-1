#include <iostream>
#include <ctime> // Для використання функції time()
#include <cstdlib>

using namespace std;

#include <iostream>
#include <ctime> // Для використання функції time()
#include <cstdlib>

using namespace std;

void nadglowek() {

    char name[] = "Autor programu: Anastasiia Nerestenko";

    for (int i = 0; i < 120; i++) {
        printf("*");
    }

    printf("\n");

    for (int i = 0; i < 120; i++)
    {
        printf(" ");
    }


    printf(name);

    for (int i = 0; i < 120; i++) {
        printf(" ");
    }

    printf("\n");

    for (int i = 0; i < 120; i++) {
        printf("*");
    }
    printf("\n\n");
}

void wyswietlanie(int liczby[][10], int rozmiar) { 
    for (int i = 0; i < rozmiar; i++) { 
        for (int j = 0; j < rozmiar; j++) { 
            cout << liczby[i][j] << " ";
        }
        cout << endl;
    }
}

void diagonal(int liczby[][10], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            if (i == j) {
                if (liczby[i][j] == 0) {
                    cout << "X ";
                }
                else {
                    cout << "! ";
                }
            }
            else {
                cout << liczby[i][j] << " ";
            }
        }
        cout << endl;
    }
}

 int dolny_trojkat(int liczby[][10], int rozmiar) {
    int wyznacznik = 1; 
     for (int i = 0; i < rozmiar; i++) {
         for (int j = 0; j < rozmiar; j++) {
             if (j <= i) {
                 cout << liczby[i][j] << " ";
                 if (i == j) {
                     wyznacznik = wyznacznik * liczby[i][j];

                 }
             }
             else {
                 cout << "0 ";
             }
         }
         cout << endl;
     }

     return wyznacznik;
}

int main()
{
    nadglowek();

    int rozmiar;
    int liczba1, liczba2;
    int liczby[10][10];
   

    cout << "Podaj rozmiar kwadratowej macierzy: ";
    cin >> rozmiar; 

    // Перевірка, щоб розмір не перевищував максимально допустимий 
    if (rozmiar > 10) {
        cout << "Rozmiar jest za duzy!";
        return 1; 
    }

     // Максимальний розмір матриці 

    cout << "\nZadaj przedzial losowania liczb" << endl;
    cout << "\nPoczatek: ";
    cin >> liczba1;
    cout << "\nKoniec: ";
    cin >> liczba2;
    cout << endl;

    srand(time(NULL));

    for (int i = 0; i < rozmiar; i++) { // Зміна тут
        for (int j = 0; j < rozmiar; j++) { // Зміна тут
            liczby[i][j] = rand() % (liczba2 - liczba1 + 1) + liczba1;
        }
    }

    wyswietlanie(liczby, rozmiar); 

    cout << endl;

    diagonal(liczby, rozmiar);

    cout << endl;


    cout << "\nWyznacznik maczirzy: " << dolny_trojkat(liczby, rozmiar);

   
}



