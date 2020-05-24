//Jan Skwarczek - gr. 8

import java.util.Scanner;

public class Source{

    public static Scanner scan = new Scanner(System.in);

    static void IterPier(int[][] tab, int m, int n, int k){

        int i = 0;
        int j = n-1;

        while(i < m && j >= 0){

            if(tab[i][j] == k){

                if(j-1 >= 0 && tab[i][j-1] == k){
                    j--;
                }
                else{
                    System.out.print("IterPier: " + k + " w (" + i + "," + j + ")");
                    System.out.println();
                    return;
                }
            }
            else if(tab[i][j] < k){
                i++;
            }
            else{
                j--;
            }
        }
        System.out.println("IterPier: nie ma " + k);
    }


    public static void IterOst(int tab[][], int m, int n, int k)
    {

        int i = m-1;
        int j = 0;

        while(i >= 0 && j < n){

            if(tab[i][j] == k){

                if(j+1 < n && tab[i][j+1] == k){
                    j++;
                }
                else{
                    System.out.print("IterOst: " + k + " w (" + i + "," + j + ")");
                    System.out.println();
                    return;
                }
            }
            else if(tab[i][j] < k){
                j++;
            }
            else{
                i--;
            }
        }
        System.out.println("IterOst: nie ma " + k);
    }


    public static void RekPier(int tab[][], int i, int j, int m, int n, int k){

        if(i < m && j >= 0){

            if(tab[i][j] == k){

                if(j-1 >= 0 && tab[i][j-1] == k){
                    RekPier(tab, i, j-1, m, n, k);
                }
                else{
                    System.out.println("RekPier: " + k + " w (" + i + "," + j + ")");
                }
            }

            else if(tab[i][j] < k){
                RekPier(tab, i+1, j, m, n, k);;
            }

            else{
                RekPier(tab, i, j-1, m, n, k);;
            }
        }
        else
            System.out.println("RekPier: nie ma " + k);
    }

    public static void RekOst(int tab[][], int i, int j, int m, int n, int k){

        if(i >= 0 && j < n){

            if(tab[i][j] == k){

                if(j+1 < n && tab[i][j+1] == k){
                    RekOst(tab, i, j+1, m, n, k);
                }
                else{
                    System.out.println("RekOst: " + k + " w (" + i + "," + j + ")");
                }
            }

            else if(tab[i][j] < k){
                RekOst(tab, i, j+1, m, n, k);;
            }

            else{
                RekOst(tab, i-1, j, m, n, k);;
            }
        }
        else
            System.out.println("RekOst: nie ma " + k);
    }

    public static void main(String args[])
    {

        int Z = scan.nextInt();

        while(Z-- > 0){

            int m = scan.nextInt();
            int n = scan.nextInt();

            int [][]tab = new int[m][n];

            for(int i=0; i<m; i++){
                for (int j = 0; j<n; j++){

                    tab[i][j] = scan.nextInt();
                }
            }

            int k = scan.nextInt();

            RekPier(tab, 0, n-1, m, n, k);
            RekOst(tab, m-1, 0, m, n, k);
            IterPier(tab, m, n, k);
            IterOst(tab, m, n, k);

            System.out.println("---");
        }
    }
}

//12
//1 1
//0
//1
//2 2
//5 6
//6 7
//5
//5 5
//1 2 3 4 5
//2 3 4 5 6
//3 4 5 6 7
//4 5 6 7 8
//5 6 7 8 9
//5
//3 4
//10 10 10 10
//10 20 20 30
//20 20 20 40
//20
//3 4
//10 10 10 10
//10 20 20 30
//20 20 20 40
//50
//3 3
//10 10 10
//10 20 20
//20 20 20
//10
//1 10
//0 0 0 0 0 0 0 0 0 1
//1
//10 1
//0
//0
//0
//0
//0
//0
//0
//0
//0
//1
//1
//3 4
//10 10 10 10
//10 20 20 30
//20 20 20 40
//20
//3 4
//10 10 10 10
//10 20 20 30
//20 20 20 40
//50
//3 3
//10 10 10
//10 20 20
//20 20 20
//10
//4 4
//1 2 3 20
//1 2 3 20
//1 2 3 20
//1 4 4 20
//4