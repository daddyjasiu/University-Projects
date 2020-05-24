//Jan Skwarczek - gr. 8

import java.util.LinkedList;
import java.util.Scanner;

class Node{

    private int x, y;
    private int dir;

    public Node(int i, int j){
        this.x = i;
        this.y = j;
        this.dir = 0;
    }

    public int getX(){
        return x;
    }

    public int getY(){
        return y;
    }

    public int getDir(){
        return dir;
    }

    public void setDir(int dir){
        this.dir = dir;
    }

}

public class Source{

    private static int col;
    private static int row;

    private static boolean[][] pathMade = new boolean[col][row];

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int width = scan.nextInt();
        int height = scan.nextInt();

        col = height + 2;
        row = width + 2;

        pathMade = new boolean[col][row];

        int[][] maze = new int[height + 2][width + 2];

        for (int k = 1; k < height + 2; k++){
            maze[k][0] = 1;
            maze[k][width + 1] = 1;
        }

        for (int k = 0; k < width + 2; k++){
            maze[0][k] = 1;
            maze[height + 1][k] = 1;
        }

        for (int m = height; m != 0; m--){
            for (int n = 1; n < width + 1; n++){

                maze[m][n] = scan.nextInt();
            }
        }

        int Z = scan.nextInt();

        while(Z-- > 0){

            for (int i = 0; i < pathMade.length; i++) {
                for (int j = 0; j < pathMade[i].length; j++) {

                    pathMade[i][j] = true;
                }
            }

            char operation = scan.next().charAt(0);
            int x1 = scan.nextInt() + 1;
            int y1 = scan.nextInt() + 1;
            int x2 = scan.nextInt() + 1;
            int y2 = scan.nextInt() + 1;

            if (operation == 'i'){

                if (IterativePathfinder.findPath(maze, x1, y1, x2, y2)){

                    int tempx1 = 0;
                    int tempy1 = 0;

                    tempx1 = x1;
                    tempy1 = y1;

                    String output = new String();

                    output = "i";

                    do{

                        if (!pathMade[tempy1 + 1][tempx1]){

                            output = output + " N";
                            pathMade[tempy1][tempx1] = true;
                            tempy1 += 1;

                        } else if (!pathMade[tempy1][tempx1 + 1]){

                            output = output + " E";
                            pathMade[tempy1][tempx1] = true;
                            tempx1 += 1;

                        } else if (!pathMade[tempy1][tempx1 - 1]){

                            output = output + " W";
                            pathMade[tempy1][tempx1] = true;
                            tempx1 -= 1;

                        } else if (!pathMade[tempy1 - 1][tempx1]){

                            output = output + " S";
                            pathMade[tempy1][tempx1] = true;
                            tempy1 -= 1;

                        } else{
                            break;
                        }


                    }while (tempx1 != x2 || tempy1 != y2);

                    System.out.println(output);

                }

                else{
                    System.out.println("i X");
                }

            }

            if (operation == 'r'){

                RecursivePathfinder recpath = new RecursivePathfinder(y2, x2, col, row, maze);

                System.out.print("r");
                recpath.solveRec(y1, x1);
                System.out.println();

            }
        }
    }

    public static class RecursivePathfinder{

        LinkedList<Character> recList = new LinkedList<>();

        static int destX;
        static int destY;

        static int N;
        static int M;

        static int[][] maze;

        RecursivePathfinder(int dx, int dy, int n, int m, int[][] mz){

            maze = mz;
            destX = dx;
            destY = dy;
            N = n;
            M = m;
        }

        void printSolution() {
            while (!recList.isEmpty()) {
                System.out.print(" " + recList.pop());
            }
        }

        void solveRec(int activeX, int activeY) {
            int pathMake[][] = new int[N][M];

            if (!findPath(activeX, activeY, pathMake)){
                System.out.print(" X");
            }

            else{
                printSolution();
            }
        }

        boolean findPath(int x, int y, int[][] pathMake) {

            if (x == destX && y == destY) {
                return true;
            }

            if (x >= 0 && y >= 0 && x < N && y < M && pathMake[x][y] == 0 && maze[x][y] == 0) {
                pathMake[x][y] = 1;

                if (findPath(x + 1, y, pathMake)) {
                    recList.addFirst('N');
                    return true;
                }
                if (findPath(x, y + 1, pathMake)) {
                    recList.addFirst('E');
                    return true;
                }
                if (findPath(x - 1, y, pathMake)) {
                    recList.addFirst('S');
                    return true;
                }
                if (findPath(x, y - 1, pathMake)) {
                    recList.addFirst('W');
                    return true;
                }
            }
            return false;
        }
    }

    public static class IterativePathfinder{

        private static boolean findPath(int maze[][], int x1, int y1, int x2, int y2){

            LinkedList<Node> iterList = new LinkedList<Node>();

            Node temp = new Node(y1, x1);

            pathMade[y1][x1] = false;

            iterList.push(temp);

            while (!iterList.isEmpty()){

                temp = iterList.peek();
                int direction = temp.getDir();
                y1 = temp.getX();
                x1 = temp.getY();

                temp.setDir(temp.getDir() + 1);
                iterList.pop();
                iterList.push(temp);

                if(y1 == y2 && x1 == x2){
                    return true;
                }

                if(direction == 0){
                    if(y1 - 1 >= 0 && maze[y1 - 1][x1] == 0 && pathMade[y1 - 1][x1]){
                        Node temp1 = new Node(y1 - 1, x1);
                        pathMade[y1 - 1][x1] = false;
                        iterList.push(temp1);
                    }
                }

                else if (direction == 1){

                    if(x1 - 1 >= 0 && maze[y1][x1 - 1] == 0 && pathMade[y1][x1 - 1]) {
                        Node temp1 = new Node(y1, x1 - 1);
                        pathMade[y1][x1 - 1] = false;
                        iterList.push(temp1);
                    }
                }

                else if (direction == 2){

                    if(y1 + 1 < col && maze[y1 + 1][x1] == 0 && pathMade[y1 + 1][x1]){
                        Node temp1 = new Node(y1 + 1, x1);
                        pathMade[y1 + 1][x1] = false;
                        iterList.push(temp1);
                    }
                }

                else if (direction == 3){

                    if (x1 + 1 < row && maze[y1][x1 + 1] == 0 && pathMade[y1][x1 + 1]) {
                        Node temp1 = new Node(y1, x1 + 1);
                        pathMade[y1][x1 + 1] = false;
                        iterList.push(temp1);
                    }
                }

                else{
                    pathMade[temp.getX()][temp.getY()] = true;
                    iterList.pop();
                }
            }
            return false;
        }
    }
}