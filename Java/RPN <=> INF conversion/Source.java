//Jan Skwarczek - grupa 8

import java.util.Scanner;

public class Source {
    public static Scanner sc = new Scanner(System.in);

    static class Stack{

        private int maxSize;
        private char[] elem;
        private int top;

        public Stack(int s){
            maxSize = s;
            elem = new char[maxSize];
            top = -1;
        }

        public void push(char ch) {
            top++;
            elem[top] = ch;
        }

        public char pop() {
            top--;
            return elem[top + 1];
        }

        public boolean isEmpty() {
            if (top == -1) return true;
            else return false;
        }

        public void display() {
            if (!isEmpty())
                for (int i = top; i >= 0; i--) System.out.println(elem[i] + " ");
            else System.out.println("empty");
        }
    }

    static class INFtoOnp {
        private Stack theStack;
        private String input;
        private String output = "";

        public INFtoOnp(String in) {
            input = in;
            int stackSize = input.length();
            theStack = new Stack(stackSize);
        }

        public String transToOnp() {
            for (int j = 0; j < input.length(); j++) {
                char ch = input.charAt(j);

                switch (ch) {
                    case'=':
                        gotOper(ch,0);
                        break;
                    case'>':
                    case'<':
                        gotOper(ch, 1);
                        break;
                    case '+':
                    case '-':
                        gotOper(ch, 2);
                        break;
                    case '*':
                    case '/':
                    case '%':
                        gotOper(ch, 3);
                        break;
                    case '^':
                        gotOper(ch, 4);
                        break;
                    case '~':
                        gotOper(ch, 5);
                        break;
                    case '(':
                        theStack.push(ch);
                        break;
                    case ')':
                        gotParen(ch);
                        break;
                    default:
                        output += ch;
                        break;
                }
            }

            while (!theStack.isEmpty()) {
                output += theStack.pop();
            }
            return output;
        }

        public void gotOper(char opThis, int prec1) {
            while (!theStack.isEmpty()) {
                char opTop = theStack.pop();
                if (opTop == '(') {
                    theStack.push(opTop);
                    break;
                } else {
                    int prec2;
                    if (prec1 > 0 && prec1 < 4) {
                        if (opTop == '+' || opTop == '-')
                            prec2 = 2;
                        else if (opTop == '>' || opTop == '<') prec2 = 1;
                        else if (opTop == '=') prec2 = 0;
                        else if (opTop == '%' || opTop == '*' || opTop == '/') prec2 = 3;
                        else if (opTop == '^') prec2 = 4;
                        else prec2 = 5;

                        if (prec2 < prec1) {
                            theStack.push(opTop);
                            break;
                        } else
                            output = output + opTop;
                    } else {
                        if (opTop == '+' || opTop == '-')
                            prec2 = 2;
                        else if (opTop == '>' || opTop == '<') prec2 = 1;
                        else if (opTop == '=') prec2 = 0;
                        else if (opTop == '%' || opTop == '*' || opTop == '/') prec2 = 3;
                        else if (opTop == '^') prec2 = 4;
                        else prec2 = 5;

                        if (prec2 <= prec1) {
                            theStack.push(opTop);
                            break;
                        } else
                            output = output + opTop;
                    }
                }
            }
            theStack.push(opThis);

        }
        public void gotParen(char ch) {

            while (!theStack.isEmpty()) {
                char chx = theStack.pop();
                if (chx == '(')
                    break;
                else
                    output = output + chx;
            }
        }
    }

    static class stackArray {
        private int maxSize;
        private String[] Elem;
        private int top;

        public stackArray(int size) {
            maxSize = size;

            Elem = new String[maxSize];
            top = maxSize;
        }

        public void push(String x) {
            if (!isFull())
                Elem[--top] = x;
        }

        public String pop() {
            if (isEmpty())
                return "";
            else
                return Elem[top++];
        }

        public boolean isEmpty() {
            return (top == maxSize);
        }

        public boolean isFull() {
            return (top == 0);
        }
    }

    static class stackArrayInt {
        private int maxSize;
        private int[] Elem;
        private int top;

        public stackArrayInt(int size) {
            maxSize = size;

            Elem = new int[maxSize];
            top = maxSize;
        }

        public void push(int x) {
            if (!isFull())
                Elem[--top] = x;
        }

        public int pop() {
            if (isEmpty())
                return 0;
            else
                return Elem[top++];
        }

        public int top() {
            if (isEmpty())
                return 0;
            else
                return Elem[top];
        }

        public boolean isEmpty() {
            return (top == maxSize);
        }

        public boolean isFull() {
            return (top == 0);
        }
    }

    static int pobierzPriorytet(String znak) {
        if(znak.equals("="))
            return 1;
        else if(znak.equals("<") || znak.equals(">"))
            return 2;
        else if (znak.equals("+") || znak.equals("-"))
            return 3;
        else if (znak.equals("*") || znak.equals("/") || znak.equals("%"))
            return 4;
        else if (znak.equals("^"))
            return 5;
        else if (znak.equals("~"))
            return 6;
        else if (znak.charAt(0) >= 'a' && znak.charAt(0) <= 'z')
            return 7;

        return 0;
    }

    static void ONPtoINF(String[] wejscie)
    {
        stackArray stos = new stackArray(wejscie.length);
        stackArrayInt stosPriorytetow = new stackArrayInt(wejscie.length);

        String tmp = "";
        int liczbaOperandow = 0, liczbaOperatorow = 0;

        for(int j = 0;j<wejscie.length;j++)
        {
            if(!wejscie[j].equals("(") && !wejscie[j].equals(")"))
                if(wejscie[j].charAt(0) >= 'a' && wejscie[j].charAt(0) <= 'z')
                {
                    stos.push(wejscie[j]);
                    stosPriorytetow.push(pobierzPriorytet(wejscie[j]));
                    liczbaOperandow++;
                }
                else
                {
                    tmp = "";

                    if((!wejscie[j].equals("~"))&& (!wejscie[j].equals("="))&&(!wejscie[j].equals("^")))
                    {
                        liczbaOperatorow++;

                        if(stosPriorytetow.top() <= pobierzPriorytet(wejscie[j]))
                            tmp = "(" + stos.pop() + ")";
                        else
                            tmp = stos.pop();

                        stosPriorytetow.pop();

                        if(stosPriorytetow.top() < pobierzPriorytet(wejscie[j]))
                            tmp = "(" + stos.pop() + ")" + wejscie[j] + tmp;
                        else
                            tmp = stos.pop() + wejscie[j] + tmp;

                        stosPriorytetow.pop();
                    }
                    else if(wejscie[j].equals("=")||wejscie[j].equals("^"))
                    {
                        liczbaOperatorow++;

                        if(stosPriorytetow.top() < pobierzPriorytet(wejscie[j]))
                            tmp = "(" + stos.pop() + ")";
                        else
                            tmp = stos.pop();

                        stosPriorytetow.pop();

                        if(stosPriorytetow.top() < pobierzPriorytet(wejscie[j]))
                            tmp = "(" + stos.pop() + ")" + wejscie[j] + tmp;
                        else
                            tmp = stos.pop() + wejscie[j] + tmp;

                        stosPriorytetow.pop();
                    }
                    else{
                        if(stosPriorytetow.top() < pobierzPriorytet(wejscie[j]))
                            tmp = wejscie[j] + "(" + stos.pop() + ")";
                        else
                            tmp = wejscie[j] + stos.pop();

                        stosPriorytetow.pop();
                    }

                    stos.push(tmp);
                    stosPriorytetow.push(pobierzPriorytet(wejscie[j]));
                }
        }

        System.out.println(stos.pop());
    }

    public static void main(String[] args){

        int Z = sc.nextInt();
        String linia = sc.nextLine();

        while(0 < Z--) {

            String operator;
            String wyrazenie;

            String slowo = sc.nextLine();

            if(5 >= slowo.length() || slowo.length() > 256)
                System.out.println("error");
            else{

                operator = slowo.substring(0, 5);
                wyrazenie = slowo.substring(5);

                wyrazenie = wyrazenie.replaceAll("\\s", "");
                wyrazenie = zleZnaki(wyrazenie, operator);
                String dane = wyrazenie;

                String tab[] = new String[256];

                for (int x = 0; x < dane.length(); x++)
                    tab[x] = Character.toString(dane.charAt(x));

                int counter = 0;

                for (int j = 0; j < tab.length; j++)
                    if (tab[j] != null)
                        counter++;

                String wejscie[] = new String[counter];
                for (int j = 0; j < counter; j++)
                    wejscie[j] = tab[j];

                if (operator.equals("INF: ")) {

                    int a = 0;
                    int b = 0;
                    int o = wyrazenie.charAt(0);
                    boolean czy_error = true;
                    boolean puste = true;

                    if (o == '(') {
                        a++;
                    }

                    if ((o != '~' && o != '=' && o != '>' && o != '<' && o != '-' && o != '+' && o != '*' && o != '/' && o != '%' && o != '(' && o != '^' && o != ')') && (wyrazenie.length() == 1)) {
                        puste = false;
                    }
                    if (puste == false && wyrazenie.length() == 1) {
                        czy_error = false;
                    }

                    for (int j = 1; j < wyrazenie.length(); j++) {
                        char c = wyrazenie.charAt(j);
                        char p = wyrazenie.charAt(j - 1);
                        char l = wyrazenie.charAt(wyrazenie.length() - 1);

                        czy_error = false;

                        if (c == '(') {
                            a++;
                        } else if (c == ')') {
                            b++;
                        }

                        if(b > a){
                            czy_error = true;
                            break;
                        }

                        if (l == '+' || l == '-' || l == '*' || l == '/' || l == '%' || l == '^' || l == '(' || l == '=' || l == '<' || l == '>' || l == '~') {
                            czy_error = true;
                            break;
                        }

                        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == ')' || c == '=' || c == '<' || c == '>') {
                            if (p == '+' || p == '-' || p == '*' || p == '/' || p == '%' || p == '^' || p == '(' || p == '=' || p == '>' || p == '<' || p == '~') {
                                czy_error = true;
                                break;
                            }
                        } else {
                            if (p != '~' && p != '=' && p != '>' && p != '<' && p != '-' && p != '+' && p != '*' && p != '/' && p != '%' && p != '(' && p != '^') {
                                czy_error = true;
                                break;
                            }
                        }
                    }
                    if (a != b) {
                        czy_error = true;
                    }

                    if (!czy_error) {
                        INFtoOnp i = new INFtoOnp(wyrazenie);
                        System.out.println("ONP: " + i.transToOnp());
                    } else {
                        System.out.println("ONP: error");
                    }
                } else if (operator.equals("ONP: ")) {
                    int ilosc_operatorow = 0;
                    int ilosc_operandow = 0;
                    boolean czy_falsz = false;
                    for (int j = 0; j < wyrazenie.length(); j++) {
                        czy_falsz = false;
                        char t = wyrazenie.charAt(j);

                        if (t == '+' || t == '-' || t == '*' || t == '/' || t == '%' || t == '^' || t == '=' || t == '<' || t == '>') {
                            ilosc_operatorow++;
                        } else if (t == '~') {
                        } else {
                            ilosc_operandow++;
                        }
                        if (ilosc_operatorow > ilosc_operandow) {
                            czy_falsz = true;
                            break;
                        }
                    }
                    if (ilosc_operandow - ilosc_operatorow != 1) {
                        czy_falsz = true;
                    }


                    if (czy_falsz) {
                        System.out.println("INF: error");
                    } else {
                        System.out.print("INF: ");
                        ONPtoINF(wejscie);
                    }
                } else {
                    System.out.println("error");
                }

            }
        }

    }
    public static String zleZnaki(String tab_p, String rodzaj){

        char [] prawidlowe = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','+','-','>','<','=','*','%','/','^','~'};
        boolean toAdd = false;
        String output = new String();

        for(int j = 0; j < tab_p.length(); j++) {

            char test = tab_p.charAt(j);

            toAdd = false;
            for (int i = 0; i < prawidlowe.length; i++) {

                if(test == prawidlowe[i] && rodzaj.equals("ONP: ")) {
                    toAdd = true;
                    break;
                }
                else if ((test == prawidlowe[i] || test == '(' || test == ')') && rodzaj.equals("INF: ")){
                    toAdd = true;
                    break;
                }
            }
            if(toAdd) {
                output+=test;
            }
        }
        return output;
    }
}

//10
//ONP: xabc**=
//ONP: ab+a~a-+
//INF: a+b+(~a-a)
//INF: x=~~a+b*c
//INF: t=~a<x<~b
//INF: ( a,+ b)/..[c3
//ONP: ( a,b,.).c;-,*
//ONP: abc++def++g+++
//INF: x=a=b=c
//ONP: xabc===
//
//INF: x=a*(b*c)
//INF: a+b+(~a-a)
//ONP: ab+a~a-+
//ONP: xa~~bc*+=
//ONP: ta~x<b~<=
//ONP: ab+c/
//INF: a*(b-c)
//INF: error
//ONP: xabc===
//INF: x=a=b=c