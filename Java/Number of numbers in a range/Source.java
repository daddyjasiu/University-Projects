//Jan Skwarczek - grupa 8

import java.util.Scanner;

//a - tablica danych
//n - dlugosc tablicy
//Z - ilosc zestawow danych
//p - ilosc par
//p1, p2 - liczby w parze
//P - startowy indeks w tablicy
//K - koncowy indeks w tablicy
//l - low, lewa czesc tablicy
//h - high, prawa czesc tablicy
//m - srodek tablicy
//s - ilosc indeksow
public class Source {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int Z = sc.nextInt();
        while (Z-- != 0) {
            int n = sc.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            int p = sc.nextInt();
            for (int i = 0; i < p; i++) {
                int p1 = sc.nextInt();
                int p2 = sc.nextInt();
                int l = 0;
                int h = n - 1;
                int i1 = -1;
                while (l <= h) {
                    int m = (h - l) / 2 + l;
                    if (a[m] > p1) {
                        h = m - 1;
                    } else if (a[m] == p1) {
                        i1 = m;
                        h = m - 1;
                    } else l = m + 1;
                }
                if (i1 == -1) {
                    l = 0;
                    h = n - 1;
                    while (l <= h) {
                        int m = (l + h) / 2;
                        if (a[m] <= p1) {
                            l = m + 1;
                        } else {
                            i1 = m;
                            h = m - 1;
                        }
                    }
                }
                int i2 = -1;
                l = 0;
                h = n - 1;
                while (l <= h) {
                    int m = (h - l) / 2 + l;
                    if (a[m] > p2) {
                        h = m - 1;
                    } else if (a[m] <= p2) {
                        i2 = m;
                        l = m + 1;
                    } else l = m + 1;
                }
                if (i2 == -1) {
                    l = 0;
                    h = n - 1;
                    while (l <= h) {
                        int m = (l + h) / 2;
                        if (a[m] >= p2) {
                            h = m - 1;
                        } else {
                            i2 = m;
                            l = m + 1;
                        }
                    }
                }
                int s = i2 - i1;
                if (p2 - p1 >= 0 && s >= 0 && i2 != -1 && i1 != -1) {
                    s++;
                    System.out.println(s);
                } else System.out.println("0");
            }
            Source.met(a, n);
        }
    }

    public static void met(int a[], int n) {
//c - zeznanie
//am - liczba zeznan
        int c = a[0];
        int am = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != c) {
                c = a[i];
                am++;
            }
        }
        System.out.println(am);
    }
}