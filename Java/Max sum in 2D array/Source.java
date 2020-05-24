//Jan Skwarczek - grupa 8

import java.util.Scanner;

public class Source{

    public static Scanner s = new Scanner(System.in);

    public static void main(String[] args){

        int Z = s.nextInt();

        while (0 < Z--){
            int rows = s.nextInt();
            int columns = s.nextInt();
            int maxsum = -1;
            int frow = 0;
            int lrow = 0;
            int fcolumn = 0;
            int lcolumn = 0;
            int maxsize = rows*columns;
            int help = 0;
            int tab[][] = new int[rows][columns];

            for (int i = 0; i < rows; i++){
                for (int j = 0; j < columns; j++){
                    tab[i][j] = s.nextInt();

                    if (tab[i][j] >= 0){
                        help = 1;
                    }
                }
            }

            if (help == 0){
                System.out.println("empty");
            }

            else{

                int optab[][] = new int[rows + 1][columns];

                for (int i = 0; i < rows; i++){
                    for (int j = 0; j < columns; j++){
                        optab[i + 1][j] = optab[i][j] + tab[i][j];
                    }
                }

                for (int frow1 = 0; frow1 < rows; frow1++){
                    for (int row = frow1; row < rows; row++){
                        int sum = 0;
                        int fcolumns1 = 0;
                        for (int column = 0; column < columns; column++){
                            sum += optab[row + 1][column] - optab[frow1][column];


                            if(sum == 0 && maxsum == -1){

                                int rozmiar = ((row - frow1) + 1)*((column - fcolumns1) + 1);

                                maxsize = rozmiar;
                                maxsum = sum;
                                frow = frow1;
                                lrow = row;
                                fcolumn = fcolumns1;
                                lcolumn = column;
                            }

                            else if(sum<=0){
                                sum = 0;
                                fcolumns1 = column+1;
                            }
                            else if(sum>0){

                                int size = ((row - frow1) + 1)*((column - fcolumns1) + 1);

                                if (maxsum < sum){
                                    maxsize = size;
                                    maxsum = sum;
                                    frow = frow1;
                                    lrow = row;
                                    fcolumn = fcolumns1;
                                    lcolumn = column;
                                }

                                else if (maxsum == sum){
                                    if (maxsize > size){
                                        maxsize = size;
                                        maxsum = sum;
                                        frow = frow1;
                                        lrow = row;
                                        fcolumn = fcolumns1;
                                        lcolumn = column;
                                    }

                                    else if (maxsize == size){
                                        if (frow > frow1){
                                            maxsize = size;
                                            maxsum = sum;
                                            frow = frow1;
                                            lrow = row;
                                            fcolumn = fcolumns1;
                                            lcolumn = column;
                                        }

                                        else if (frow == frow1){
                                            if (lrow > row){
                                                maxsize = size;
                                                maxsum = sum;
                                                frow = frow1;
                                                lrow = row;
                                                fcolumn = fcolumns1;
                                                lcolumn = column;
                                            }

                                            else if (lrow == row){
                                                if (fcolumn > fcolumns1){
                                                    maxsize = size;
                                                    maxsum = sum;
                                                    frow = frow1;
                                                    lrow = row;
                                                    fcolumn = fcolumns1;
                                                    lcolumn = column;
                                                }

                                                else if (fcolumn == fcolumns1){
                                                    if (lcolumn > column){
                                                        maxsize = size;
                                                        maxsum = sum;
                                                        frow = frow1;
                                                        lrow = row;
                                                        fcolumn = fcolumns1;
                                                        lcolumn = column;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                System.out.println("max_sum = " + maxsum + ", a[" + frow + ".." + lrow + "][" + fcolumn + ".." + lcolumn + "]");
            }
        }
    }
}