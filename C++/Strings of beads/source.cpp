//Jan Skwarczek

#include <iostream>

using namespace std;

struct Wiazanie {

    Wiazanie *next;

    int Id;
    char A, B, C;

    Wiazanie() {

        next = 0;

    }

};

struct Koralik {

    Koralik *next;
    Wiazanie *first;

    int Id;

    Koralik() {

        next = 0;
        first = 0;

    }

};

struct Sznurek {

    Sznurek *next;
    Koralik *first;

    char A, B, C;

    Sznurek() {

        next = 0;
        first = 0;
    }

};

struct Baza {

    Sznurek *first;

    Baza() {

        first = 0;
    }

    void print() {

        Sznurek *sznur_itr = first;

        while (sznur_itr) {

            cout << sznur_itr->A << sznur_itr->B << sznur_itr->C << endl;

            Koralik *koral_itr = sznur_itr->first;

            while (koral_itr) {

                cout << koral_itr->Id;

                Wiazanie *wiazanie_itr = koral_itr->first;

                while (wiazanie_itr) {

                    cout << " " << wiazanie_itr->A << wiazanie_itr->B << wiazanie_itr->C << " " << wiazanie_itr->Id;
                    wiazanie_itr = wiazanie_itr->next;

                }

                cout << endl;
                koral_itr = koral_itr->next;
            }

            sznur_itr = sznur_itr->next;
        }
    }

    void przeniesKoralik(int ID, char A1, char B1, char C1, char A2, char B2, char C2) {

        Sznurek *sznur_itr = first;

        while (sznur_itr && !porownajSznurek(sznur_itr->A, sznur_itr->B, sznur_itr->C, A1, B1,
                                             C1)) { //szukanie odpowiedniego sznurka

            sznur_itr = sznur_itr->next;
        }

        if (sznur_itr) { //jesli nie doszlismy na koniec sznurkow

            Koralik *koral_itr = sznur_itr->first;

            while (koral_itr && !porownajKoralik(koral_itr->Id, ID)) { //szukanie odpowiedniego koralika

                koral_itr = koral_itr->next;
            }

            if (koral_itr) {

                dodajKoralik(koral_itr->Id, A2, B2, C2);

                Wiazanie *wiazanie_itr = koral_itr->first;

                while (wiazanie_itr) {

                    dodajWiazanie(koral_itr->Id, A2, B2, C2, wiazanie_itr->Id, wiazanie_itr->A, wiazanie_itr->B,
                                  wiazanie_itr->C);

                    wiazanie_itr = wiazanie_itr->next;

                }

                usunKoralik(koral_itr->Id, A1, B1, C1);
            }
        }
    }

    void usunWszystkieWiazania(int ID, char A, char B, char C) {

        Sznurek *sznur_itr = first;

        while (sznur_itr && !porownajSznurek(sznur_itr->A, sznur_itr->B, sznur_itr->C, A, B, C)) { //szukanie odpowiedniego sznurka

            sznur_itr = sznur_itr->next;
        }

        if (sznur_itr) { //jesli nie doszlismy na koniec sznurkow

            Koralik *koral_itr = sznur_itr->first;

            while (koral_itr && !porownajKoralik(koral_itr->Id, ID)) { //szukanie odpowiedniego koralika

                koral_itr = koral_itr->next;
            }

            if (koral_itr) { //jesli nie doszlismy na koniec koralikow

                if (koral_itr->first != 0) { //jesli wgl istnieje jakies wiazanie

                    Wiazanie *wiazanie_itr = koral_itr->first;

                    while (wiazanie_itr->next) {

                        if (wiazanie_itr->next->next == 0) {

                            usunWiazanie(ID, A, B, C, wiazanie_itr->next->Id, wiazanie_itr->next->A, wiazanie_itr->next->B, wiazanie_itr->next->C);
                            wiazanie_itr = koral_itr->first;
                        } else {
                            wiazanie_itr = wiazanie_itr->next;
                        }
                    }

                    delete wiazanie_itr;
                }
            }
        }
    }

    void usunWiazanie(int ID1, char A1, char B1, char C1, int ID2, char A2, char B2, char C2) {

        Sznurek *sznur_itr = first;

        while (sznur_itr && !porownajSznurek(sznur_itr->A, sznur_itr->B, sznur_itr->C, A1, B1,
                                             C1)) { //szukanie odpowiedniego sznurka

            sznur_itr = sznur_itr->next;
        }

        if (sznur_itr) { //jesli nie doszlismy na koniec sznurkow

            Koralik *koral_itr = sznur_itr->first;

            while (koral_itr && koral_itr->Id != ID1) { //szukanie odpowiedniego koralika

                koral_itr = koral_itr->next;
            }

            if (koral_itr) { //jesli nie doszlismy na koniec koralikow

                if (koral_itr->first != 0) { //jesli wgl istnieje jakies wiazanie

                    Wiazanie *wiazanie_itr = koral_itr->first;

                    if (wiazanie_itr->Id == ID2 && wiazanie_itr->A == A2 && wiazanie_itr->B == B2 &&
                        wiazanie_itr->C == C2) { //usuwanie pierwszego wiazania

                        koral_itr->first = wiazanie_itr->next;
                        delete wiazanie_itr;

                    } else {

                        while (wiazanie_itr->next &&
                               !porownajWiazanie(wiazanie_itr->next->Id, ID2, wiazanie_itr->next->A,
                                                 wiazanie_itr->next->B, wiazanie_itr->next->C, A2, B2, C2)) {
                            wiazanie_itr = wiazanie_itr->next;
                        }

                        //jesli usuwamy cos co rzeczywiscie jest zlinkowane
                        if (wiazanie_itr->next != 0 && wiazanie_itr->next->Id == ID2 && wiazanie_itr->next->A == A2 &&
                            wiazanie_itr->next->B == B2 && wiazanie_itr->next->C == C2) {

                            if (wiazanie_itr->next->next == 0) { //usuwanie ostatniego wiazania

                                delete wiazanie_itr->next;
                                wiazanie_itr->next = NULL;
                            } else { //usuwanie dowolnych wiazan w srodku

                                Wiazanie *temp = wiazanie_itr->next;
                                wiazanie_itr->next = wiazanie_itr->next->next;
                                delete temp;
                            }
                        }
                    }
                }
            }
        }
    }

    void dodajWiazanie(int ID1, char A1, char B1, char C1, int ID2, char A2, char B2, char C2) {

        Sznurek *sznur_itr = first;
        Wiazanie *nowy = new Wiazanie();

        nowy->Id = ID2;
        nowy->A = A2;
        nowy->B = B2;
        nowy->C = C2;

        while (sznur_itr && !porownajSznurek(sznur_itr->A, sznur_itr->B, sznur_itr->C, A1, B1,
                                             C1)) { //szukanie odpowiedniego sznurka

            sznur_itr = sznur_itr->next;
        }

        if (sznur_itr) { //jesli nie doszlismy na koniec sznurkow

            Koralik *koral_itr = sznur_itr->first;

            while (koral_itr && koral_itr->Id != ID1) { //szukanie odpowiedniego koralika

                koral_itr = koral_itr->next;
            }

            if (koral_itr) { //jesli nie doszlismy na koniec koralikow

                if (koral_itr->first == 0) {

                    koral_itr->first = nowy;

                } else {

                    Wiazanie *wiazanie_itr = koral_itr->first;

                    if (porownajWiazanie(wiazanie_itr->Id, ID2, wiazanie_itr->A, wiazanie_itr->B, wiazanie_itr->C, A2,
                                         B2, C2)) {

                        nowy->next = koral_itr->first;
                        koral_itr->first = nowy;

                    } else {

                        while (wiazanie_itr->next &&
                               !porownajWiazanie(wiazanie_itr->next->Id, ID2, wiazanie_itr->next->A,
                                                 wiazanie_itr->next->B, wiazanie_itr->next->C, A2, B2, C2)) {

                            wiazanie_itr = wiazanie_itr->next;
                        }

                        if (wiazanie_itr->next == 0) {

                            wiazanie_itr->next = nowy;

                        } else {

                            nowy->next = wiazanie_itr->next;
                            wiazanie_itr->next = nowy;

                        }
                    }
                }
            }
        }
    }

    void usunWszystkieKoraliki(char A, char B, char C) {

        Sznurek *sznur_itr = first;

        while (sznur_itr &&
               !porownajSznurek(sznur_itr->A, sznur_itr->B, sznur_itr->C, A, B, C)) { //szukanie odpowiedniego sznurka

            sznur_itr = sznur_itr->next;
        }

        if (sznur_itr) { //jesli nie doszlismy na koniec sznurkow

            if (sznur_itr->first != 0) { //jesli istnieje jakikolwiek koral

                Koralik *koral_itr = sznur_itr->first;

                while (koral_itr->next) {

                    if (koral_itr->next->next == 0) {

                        usunWszystkieWiazania(koral_itr->next->Id, A, B, C);

                        delete koral_itr->next;
                        koral_itr->next = NULL;
                        koral_itr = sznur_itr->first;
                    } else {
                        koral_itr = koral_itr->next;
                    }
                }

                usunWszystkieWiazania(koral_itr->Id, A, B, C);
                delete koral_itr;

            }
        }
    }

    void usunKoralik(int ID, char A, char B, char C) {

        Sznurek *sznur_itr = first;

        while (sznur_itr &&
               !porownajSznurek(sznur_itr->A, sznur_itr->B, sznur_itr->C, A, B, C)) { //szukanie odpowiedniego sznurka

            sznur_itr = sznur_itr->next;
        }

        if (sznur_itr) { //jesli nie doszlismy na koniec sznurkow

            if (sznur_itr->first != 0) { //jesli istnieje jakikolwiek koral

                Koralik *koral_itr = sznur_itr->first;

                if (koral_itr->Id == ID) { //usuwanie pierwszego koralika

                    usunWszystkieWiazania(ID, A, B, C);

                    sznur_itr->first = koral_itr->next;
                    delete koral_itr;
                } else {

                    while (koral_itr->next && !porownajKoralik(koral_itr->next->Id, ID)) {

                        koral_itr = koral_itr->next;
                    }

                    if (koral_itr) {
//						cout << "ID: " << koral_itr->Id <<  " ";

                        if (koral_itr->next != 0 && koral_itr->next->Id == ID) {

                            if (koral_itr->next->next == 0) { //usuwanie ostatniego korala
                                usunWszystkieWiazania(ID, A, B, C);
                                delete koral_itr->next;
                                koral_itr->next = NULL;
                            } else { //usuwanie dowolnych korali w srodku

                                usunWszystkieWiazania(ID, A, B, C);

                                Koralik *temp = koral_itr->next;
                                koral_itr->next = koral_itr->next->next;
                                delete temp;

                            }
                        }
                    }
                }
            }
        }
    }

    void dodajKoralik(int ID, char A, char B, char C) {

        Koralik *nowy = new Koralik();
        Sznurek *sznur_itr = first;

        nowy->Id = ID;

        while (sznur_itr &&
               !porownajSznurek(sznur_itr->A, sznur_itr->B, sznur_itr->C, A, B, C)) { //szukanie odpowiedniego sznurka

            sznur_itr = sznur_itr->next;
        }

        if (sznur_itr) { //jesli nie doszlismy na koniec sznurkow

            if (sznur_itr->first == 0) {

                sznur_itr->first = nowy;

            } else {

                Koralik *koral_itr = sznur_itr->first;

                if (!porownajKoralik(ID, koral_itr->Id)) {

                    nowy->next = sznur_itr->first;
                    sznur_itr->first = nowy;
                } else {

                    while (koral_itr->next && porownajKoralik(ID, koral_itr->next->Id)) {

                        koral_itr = koral_itr->next;
                    }

                    if (koral_itr->next == 0) {

                        koral_itr->next = nowy;
                    } else {

                        nowy->next = koral_itr->next;
                        koral_itr->next = nowy;

                    }
                }
            }
        }

    }

    void usunWszystkieSznurki() {

        Sznurek *sznur_itr = first;

        while (sznur_itr) {

            if (sznur_itr->next == 0) {

                usunSznurek(sznur_itr->A, sznur_itr->B, sznur_itr->C);

                sznur_itr = first;
            } else {
                sznur_itr = sznur_itr->next;
            }
        }

    }

    void usunSznurek(char A, char B, char C) {

        Sznurek *sznur_itr = first;

        if (sznur_itr->A == A && sznur_itr->B == B && sznur_itr->C == C) { //usuwanie pierwszego sznura

            usunWszystkieKoraliki(A, B, C);

            first = sznur_itr->next;
            delete sznur_itr;

        } else {

            while (sznur_itr->next && !porownajSznurek(sznur_itr->next->A, sznur_itr->next->B, sznur_itr->next->C, A, B, C)) { //szukanie sznura do usuniecia

                sznur_itr = sznur_itr->next;
            }

            if (sznur_itr) {

                if (sznur_itr->next != 0 && sznur_itr->next->A == A && sznur_itr->next->B == B &&
                    sznur_itr->next->C == C) {

                    if (sznur_itr->next->next == 0) { //usuwanie ostatniego sznurka
                        usunWszystkieKoraliki(A, B, C);
                        delete sznur_itr->next;
                        sznur_itr->next = NULL;
                    } else { //usuwanie dowolnych sznurkow w srodku

                        usunWszystkieKoraliki(A, B, C);

                        Sznurek *temp = sznur_itr->next;
                        sznur_itr->next = sznur_itr->next->next;
                        delete temp;

                    }
                }
            }
        }
    }

    void dodajSznurek(char A, char B, char C) {

        Sznurek *nowy = new Sznurek();

        nowy->A = A;
        nowy->B = B;
        nowy->C = C;

        if (first == 0) {

            first = nowy;
        } else {

            Sznurek *sznur_itr = first;

            if (!porownajSznurek(A, B, C, sznur_itr->A, sznur_itr->B, sznur_itr->C)) {

                nowy->next = first;
                first = nowy;
            } else {

                while (sznur_itr->next &&
                       porownajSznurek(A, B, C, sznur_itr->next->A, sznur_itr->next->B, sznur_itr->next->C)) {

                    sznur_itr = sznur_itr->next;
                }

                if (sznur_itr->next == 0) {

                    sznur_itr->next = nowy;
                } else {

                    nowy->next = sznur_itr->next;
                    sznur_itr->next = nowy;

                }

            }

        }

    }

    bool porownajSznurek(char A1, char B1, char C1, char A2, char B2, char C2) {

        if (A1 > A2) {
            return true;
        } else if (A1 == A2) {
            if (B1 > B2) {
                return true;
            } else if (B1 == B2) {
                if (C1 >= C2) {
                    return true;
                } else if (C1 < C2) {
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    bool porownajKoralik(int ID1, int ID2) {

        if (ID1 >= ID2)
            return true;

        return false;
    }

    bool porownajWiazanie(int ID1, int ID2, char A1, char B1, char C1, char A2, char B2, char C2) {

        if (A1 == A2 && B1 == B2 && C1 == C2) {
            return porownajKoralik(ID1, ID2);
        } else
            return (porownajSznurek(A1, B1, C1, A2, B2, C2));

    }

};

int main() {

    char op;
    Baza *baza = new Baza();

    do {
        cin >> op;

        if (op == 'S') {

            char A, B, C;

            cin >> A >> B >> C;

            baza->dodajSznurek(A, B, C);

        } else if (op == 'B') {

            char A, B, C;
            int ID;

            cin >> ID >> A >> B >> C;

            baza->dodajKoralik(ID, A, B, C);
        } else if (op == 'L') {

            char A1, B1, C1, A2, B2, C2;
            int ID1, ID2;

            cin >> ID1 >> A1 >> B1 >> C1 >> ID2 >> A2 >> B2 >> C2;

            baza->dodajWiazanie(ID1, A1, B1, C1, ID2, A2, B2, C2);
        } else if (op == 'U') {

            char A1, B1, C1, A2, B2, C2;
            int ID1, ID2;

            cin >> ID1 >> A1 >> B1 >> C1 >> ID2 >> A2 >> B2 >> C2;
            baza->usunWiazanie(ID1, A1, B1, C1, ID2, A2, B2, C2);
        } else if (op == 'D') {

            char A, B, C;
            int ID;

            cin >> ID >> A >> B >> C;
            baza->usunKoralik(ID, A, B, C);

        } else if (op == 'M') {

            char A1, B1, C1, A2, B2, C2;
            int ID;

            cin >> ID >> A1 >> B1 >> C1 >> A2 >> B2 >> C2;

            baza->przeniesKoralik(ID, A1, B1, C1, A2, B2, C2);

        } else if (op == 'R') {

            char A, B, C;

            cin >> A >> B >> C;
            baza->usunSznurek(A, B, C);
        } else if (op == 'P') {

            baza->print();
        } else if (op == 'F') {

            baza->usunWszystkieSznurki();

            delete baza;
        }


    } while (op != 'F');

    return 0;
}
