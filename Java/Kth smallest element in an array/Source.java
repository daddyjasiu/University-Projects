//Jan Skwarczek - gr. 8

import java.util.Scanner;

class Node{

    int data;
    Node left, right;

    Node(int x)
    {
        data = x;
        left = right = null;
    }
}

class Source {

    public static Scanner scan = new Scanner(System.in);

    static int count = 0;

    public static Node insert(Node root, int x)
    {
        if (root == null)
            return new Node(x);

        if (x <= root.data)
            root.left = insert(root.left, x);

        else if (x >= root.data)
            root.right = insert(root.right, x);

        return root;
    }

    public static Node inorderKthSmallest(Node root, int k)
    {

        if (root == null)
            return null;

        Node left = inorderKthSmallest(root.left, k);

        if (left != null)
            return left;

        count++;
        if (count == k)
            return root;

        return inorderKthSmallest(root.right, k);
    }

    public static int printKth(Node root, int k)
    {
        count = 0;

        Node res = inorderKthSmallest(root, k);

        return res.data;
    }

    public static void main (String[] args) {

        int Z = scan.nextInt();

        for(int i=0; i<Z; i++){

            Node root = null;

            int n = scan.nextInt();
            int tab[] = new int[n];

            for(int j=0; j<n; j++)
                tab[j] = scan.nextInt();

            for(int k=0; k<tab.length; k++){

                root = insert(root,tab[k]);
            }

            int m = scan.nextInt();

            for(int l=0; l<m; l++){

                int k = scan.nextInt();

                if (k >= 1 && k <= tab.length) {

                    System.out.println(k + " " + printKth(root, k));
                }

                else
                    System.out.println(k + " brak");

            }
        }
    }
} 

/*
3
5
1 2 3 4 5
3
1 2 3
5
5 3 4 4 3
5
2 5 1 3 4
10
1 1 1 1 1 1 1 1 1 1
5
1 10 0 -1 11
 */