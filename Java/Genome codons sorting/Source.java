//Jan Skwarczek - grupa 8.

import java.util.Scanner;

public class Source {

    static Scanner scan = new Scanner(System.in);

    public static boolean isACGT(String genome){

        for (int i = 0; i < genome.length() ; i++) {

            if(genome.charAt(i) != 'A' && genome.charAt(i) != 'C' && genome.charAt(i) != 'T' && genome.charAt(i) != 'G')
                return false;
        }

        return true;
    }

    public static void errors(String genome){

        int indexOfStop = -1;
        int indexOfStart = genome.indexOf("ATG");
        int startCounter = 0;
        int stopCounter = 0;
        int ACTGcounter = 0;

        for (int i = genome.indexOf("ATG") + 3; i < genome.length(); i = i + 3){

            if(i < genome.length()-2 && (genome.charAt(i) == 'T' && genome.charAt(i+1) == 'A' && genome.charAt(i+2) == 'A')){

                indexOfStop = i + 2;

            }

            else if (i < genome.length()-2 && (genome.charAt(i) == 'T' && genome.charAt(i+1) == 'G' && genome.charAt(i+2) == 'A')){

                indexOfStop = i + 2;

            }

            else if (i < genome.length()-2 && (genome.charAt(i) == 'T' && genome.charAt(i+1) == 'A' && genome.charAt(i+2) == 'G')){

                indexOfStop = i + 2;

            }
        }

        for (int i = genome.indexOf("ATG") + 3; i < genome.length(); i = i + 3){

            if(i < genome.length()-2 && (genome.charAt(i) == 'A' && genome.charAt(i+1) == 'T' && genome.charAt(i+2) == 'G')){

                startCounter++;

            }
        }

        for (int i = indexOfStop - 3; i > indexOfStart + 5; i = i - 3) {

            if(i > 2 && (genome.charAt(i-2) == 'T' && genome.charAt(i-1) == 'A' && genome.charAt(i) == 'A')){

                stopCounter++;

            }

            else if (i > 2 && (genome.charAt(i-2) == 'T' && genome.charAt(i-1) == 'G' && genome.charAt(i) == 'A')){

                stopCounter++;

            }

            else if (i > 2 && (genome.charAt(i-2) == 'T' && genome.charAt(i-1) == 'A' && genome.charAt(i) == 'G')){

                stopCounter++;

            }
        }

        for(int i = genome.indexOf("ATG") + 3; i < indexOfStop - 3; i++){

            if(genome.charAt(i) == 'A' && genome.charAt(i) == 'C' && genome.charAt(i) == 'T' && genome.charAt(i) == 'G'){
                ACTGcounter++;
            }
        }

        if(indexOfStop == -1 || indexOfStop == indexOfStart + 5 || ACTGcounter%3 != 0){
            System.out.println("Wrong DNA sequence.");
            return;
        }

        if(startCounter != 0 || stopCounter != 0){
            System.out.println("More than one START/STOP codon.");
            return;
        }

        StringBuilder genomeCopy = new StringBuilder(genome);
        String genomeMiddleValues;

        genomeMiddleValues = genomeCopy.substring(indexOfStart+3, indexOfStop-2);

        String []genomeTab = new String[10000];

        int j = 0;
        int k = 3;

        for (int i = 0; i < genomeMiddleValues.length()/3; i++) {

            genomeTab[i] =  genomeMiddleValues.substring(j, k);

            j = j+3;
            k = k+3;

        }

        quickSort(genomeTab, genomeMiddleValues.length());

    }

    public static void quickSort(String[] genomeTab, int elements) {

        String piv;
        int []start = new int[100];
        int []end = new int [100];
        int i=0;
        int L;
        int R;
        int swap;

        start[0] = 0;
        end[0] = elements/3;

        while (i>=0){

            L=start[i];
            R=end[i]-1;

            if (L<R){

                piv = genomeTab[L];

                while (L<R) {

                    while (genomeTab[R].compareTo(piv)>=0 && L<R)
                        R--;

                    if (L<R)

                        genomeTab[L++] = genomeTab[R];

                    while (genomeTab[L].compareTo(piv)<=0 && L<R)
                        L++;

                    if (L<R)
                        genomeTab[R--] = genomeTab[L];

                }

                genomeTab[L] = piv;
                start[i+1] = L+1;
                end[i+1] = end[i];
                end[i++] = L;

                if (end[i]-start[i] > end[i-1]-start[i-1]) {

                    swap = start[i];
                    start[i] = start[i-1];
                    start[i-1] = swap;
                    swap = end[i];
                    end[i] = end[i-1];
                    end[i-1] = swap;
                }
            }

            else {
                i--;
            }
        }

        for(int z=0; z<elements/3; z++){
            System.out.print(genomeTab[z]);
        }
        System.out.println();
    }

    public static void main(String args[]){

        int Z;
        String genome;
        String genomeUp;

        Z = scan.nextInt();

        for(int i=0; i<Z; i++){

            genome = scan.next();

            genomeUp = genome.toUpperCase();

            if(!isACGT(genomeUp))
                System.out.println("Wrong character in DNA sequence.");

            else{

                if(genomeUp.indexOf("ATG") == -1){

                    System.out.println("Wrong DNA sequence.");
                }

                else{

                    errors(genomeUp);

                }
            }
        }
    }
}
