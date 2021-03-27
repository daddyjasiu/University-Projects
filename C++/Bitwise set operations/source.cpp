//Jan Skwarczek

using namespace std;

bool Emptiness(int a){
    return a == 0;
}

bool Nonempty(int a){
    return a!=0;
}

bool Disjoint(int a, int b){
    return (a & b) == 0;
}

bool Conjunctive(int a, int b){
    return (a & b) != 0;
}

bool Equality(int a, int b){
    return a == b;
}

bool Inclusion(int a, int b){
    return (a | b) == b;
}

void Union(int a, int b, int *out){
    *out = a | b;
}

void Intersection(int a, int b, int *out){
    *out = a & b;
}

void Symmetric(int a, int b, int *out){
    *out = a ^ b;
}

void Difference(int a, int b, int *out){
    *out = (a & (~b));
}

void Complement(int a, int *out){
    *out = ~a;
}

int Cardinality(int out, int i, int count){

    if(i==0){
        return count;
    }
    else{
        if((out&1) == 1) {
            count = count + 1;
            i--;
            Cardinality(out>>1, i, count);
        }
        else{
            i--;
            Cardinality(out>>1, i, count);
        }
    }

}

int Cardinality(int out){

    if(out == 0)
        return 0;

    else{
        int i = 32;
        int count = 0;
        return Cardinality(out, i, count);
    }

}

bool LessThen(int a, int b){
    if(Cardinality(a)==Cardinality(b)){
        return a<b;
    }
    else
        return Cardinality(a)<Cardinality(b);
}

bool LessEqual(int a, int b){
    if(Cardinality(a)==Cardinality(b)){
        return a<=b;
    }
    else{
        return Cardinality(a)<=Cardinality(b);
    }
}

bool GreatEqual(int a, int b){
    if(Cardinality(a)==Cardinality(b)){
        return a>=b;
    }
    else
        return Cardinality(a)>=Cardinality(b);
}

bool GreatThen(int a, int b){
    if(Cardinality(a)==Cardinality(b)){
        return a>b;
    }
    else
        return Cardinality(a)>Cardinality(b);
}

void Print(int in, char* out, int i, int char_itr){

    int temp_int = 2147483648;
    //std::cout << std::bitset<32> (in) << "\n";
    if(i>=0){
        if((in & temp_int) != 0){

            *(out+char_itr) = (i/16) + '0';
            char_itr++;

            *(out+char_itr) = (i/8) % 2 + '0';
            char_itr++;

            *(out+char_itr) = (i/4) % 4 % 2 + '0';
            char_itr++;

            *(out+char_itr) = (i/2) % 8 % 2 + '0';
            char_itr++;

            *(out+char_itr) = (i%2) + '0';
            char_itr++;

            *(out+char_itr) = ' ';
            char_itr++;
        }
        i--;
        in <<=1;
        Print(in, out, i, char_itr);
    }
    if(i<0)
        *(out+char_itr-1) = '\0';
};

void Print(int in, char* out){
    if(in==0) {
        *out = 'e';
        *(out + 1) = 'm';
        *(out + 2) = 'p';
        *(out + 3) = 't';
        *(out + 4) = 'y';
        *(out + 5) = '\0';
    }
    else{
        int i=31;
        int char_itr = 0;

        Print(in, out, i, char_itr);

    }
};

bool Member(char *in, int out, int i){

    if(*(in+i) != '\0'){

        if(*(in + i) != ' '){

            int temp_int = 1;

            if(*(in + i) == '1')
                temp_int <<= 16;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 8;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 4;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 2;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 1;

            return temp_int & out;

        }
        i++;
        Member(in, out, i);
    }
}

bool Member(char *in, int out){
    int i = 0;
    return Member(in, out, i);
}

void Emplace(char *in, int *out, int i){

    if(*(in+i) != '\0'){

        if(*(in + i) != ' '){

            int temp_int = 1;

            if(*(in + i) == '1')
                temp_int <<= 16;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 8;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 4;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 2;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 1;

            Union(temp_int, *out, out);

        }
        i++;
        Emplace(in, out, i);
    }
}

void Emplace(char *in, int *out){
    *out = 0;
    Emplace(in, out, 0);
}

void Insert(char *in, int *out){
    int i = 0;
    Emplace(in, out, i);
}

void Erase(char *in, int *out, int i){

    if(*(in+i) != '\0'){

        if(*(in + i) != ' '){

            int temp_int = 1;

            if(*(in + i) == '1')
                temp_int <<= 16;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 8;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 4;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 2;
            i++;

            if(*(in + i) == '1')
                temp_int <<= 1;

            if((temp_int & *out) != 0)
                *out = *out-temp_int;

        }
        i++;
        Erase(in, out, i);
    }

}

void Erase(char *in, int *out){

    int i = 0;
    Erase(in, out, i);

}

