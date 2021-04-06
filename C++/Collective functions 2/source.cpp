//Jan Skwarczek

int ToInt(int &i, int &ascii, string &c){

    if(i<c.length()){
        ascii += c[i] - '0';
        i++;
        ToInt(i, ascii, c);
    }
    return ascii;
}

int ToInt(string c){
    int i = 0;
    int ascii = 0;
    return ToInt(i, ascii, c);
}

string ToString(int c){

    string result = "";

    if(c/10 != 0){
        result += (c/10 + '0');
        result += (c%10 + '0');
    }
    else{
        result += (c + '0');
    }

    return result;
}

bool CompareString(int &i, string &first_number, string &second_number){

    if(i<first_number.length()){
        if(first_number[i]>second_number[i])
            return true;

        else if(first_number[i]<second_number[i])
            return false;

        i++;
        return CompareString(i, first_number, second_number);
    }
    return false;
}

bool CompareString(string &first_number, string &second_number){

    int i = 0;
    return CompareString(i, first_number, second_number);
}

void AddZeros(int &i, string &number, int &amount){
    if(i<amount){
        number += "0";
        i++;
        AddZeros(i, number, amount);
    }
}

void AddZeros(string &number, int &amount){
    int i = 0;
    AddZeros(i, number, amount);
}

void RemoveZeros(int &i, string &number){

    if(i<number.length() && number[i] == '0'){
        if(number[i]=='0' && number[i+1]=='0'){
            number = number.substr(i+2);
            i = -1;
        }
        if(number[i]=='0' && number[i+1]!='0') {
            number = number.substr(i + 1);
            i = -1;
        }

        i++;
        RemoveZeros(i, number);
    }
}

void RemoveZeros(string &number){
    int i = 0;
    RemoveZeros(i, number);
}

string ReverseString(int &i, string &result, string &number){

    if(i >= 0){
        result += number[i];
        i--;
        ReverseString(i, result, number);
    }

    return result;
}

void ReverseString(string &number){

    int i = number.length()-1;
    string result = "";

    number = ReverseString(i, result, number);
}

string Sub(int &i, int &sum, int &carry, string &result, string &first_number, string &second_number){

    if (i < second_number.length()){
        sum = (first_number[i] - '0') - (second_number[i] - '0') - carry;
        if(sum < 0){
            sum += 10;
            carry = 1;

        } else {
            carry = 0;
        }
        result += (sum + '0');
        i++;
        Sub(i, sum, carry, result, first_number, second_number);
    }
    else if(i >= second_number.length() && i<first_number.length()){
        sum = (first_number[i] - '0') - carry;
        if(sum < 0){
            sum += 10;
            carry = 1;

        } else {

            carry = 0;
        }
        result += (sum + '0');
        i++;
        Sub(i, sum, carry, result, first_number, second_number);
    }

    return result;
}

string Sub(string first_number, string second_number){

    string result = "";
    int i = 0;
    int sum = 0;
    int carry = 0;

    ReverseString(first_number);
    ReverseString(second_number);

    result = Sub(i, sum, carry, result, first_number, second_number);

    if(carry){
        result += carry + '0';
    }

    ReverseString(result);

    return result;
}

string Add(int &i, int &sum, int &carry, string &result, string &first_number, string &second_number){

    if (i < first_number.length()) {
        sum = (first_number[i] - '0') + (second_number[i] - '0') + carry;
        result += (sum % 10 + '0');
        carry = sum / 10;
        i++;
        Add(i, sum, carry, result, first_number, second_number);
    }
    else if (i >= first_number.length() && i<second_number.length()) {
        sum = (second_number[i] - '0') + carry;
        result += (sum % 10 + '0');
        carry = sum / 10;
        i++;
        Add(i, sum, carry, result, first_number, second_number);
    }

    return result;

}

string Add(string first_number, string second_number){

    string result = "";
    int i = 0;
    int sum = 0;
    int carry = 0;

    if(first_number.length() > second_number.length()){
        first_number.swap(second_number);
    }

    ReverseString(first_number);
    ReverseString(second_number);

    result = Add(i, sum, carry, result, first_number, second_number);

    if(carry){
        result += carry + '0';
    }

    ReverseString(result);

    return result;
}

string AddOrSub(string first_number, string second_number){

    bool first_minus = false;
    bool second_minus = false;

    string result = "";

    if(first_number[0] == '-'){
        first_minus = true;
        first_number = first_number.substr(1); //ucinanie minusa na poczatku
    }
    if(second_number[0] == '-'){
        second_minus = true;
        second_number = second_number.substr(1);
    }
    if(first_number[0] == '+'){
        first_number = first_number.substr(1); //ucinanie plusa na poczatku
    }
    if(second_number[0] == '+'){
        second_number = second_number.substr(1);
    }

    if(first_number == "0" && second_number == "0")
        return "0";

    if(first_number != "0" && ToInt(first_number) != 0)
        RemoveZeros(first_number);
    if(second_number != "0" && ToInt(second_number) != 0)
        RemoveZeros(second_number);

    if(ToInt(first_number) == 0 && first_number.length() > 1)
        first_number = first_number.substr(first_number.length()-1);
    if(ToInt(second_number) == 0 && second_number.length() > 1)
        second_number = second_number.substr(second_number.length()-1);

    if(first_number == "" && second_number == "")
        return "";
    else if(first_number == "" && second_number != ""){
        if(second_minus)
            return "-" + second_number;
        else
            return second_number;
    }
    else if(first_number != "" && second_number == ""){
        if(first_minus)
            return "-" + first_number;
        else
            return first_number;
    }

    if(!first_minus && !second_minus){
        result = Add(first_number, second_number);
    }
    else if(first_minus && second_minus){
        result = Add(first_number, second_number);

        if(result != "0")
            RemoveZeros(result);

        result = '-' + result;
    }
    else if(first_minus && !second_minus) {

        if(first_number == second_number)
            result = "0";

        else{
            if(first_number.length() > second_number.length()){

                result = Sub(first_number, second_number);
                if(result != "0") {
                    RemoveZeros(result);
                    result = '-' + result;
                }
            }
            else if(first_number.length() < second_number.length()){
                result = Sub(second_number, first_number);
                RemoveZeros(result);

            }
            else{
                if(CompareString(first_number, second_number)){

                    result = Sub(first_number, second_number);
                    if(result != "0") {
                        RemoveZeros(result);
                        result = '-' + result;
                    }
                }
                else{
                    result = Sub(second_number, first_number);
                    RemoveZeros(result);
                }
            }
        }

    }
    else if(!first_minus && second_minus){

        if(first_number == second_number)
            result = "0";

        else{
            if(first_number.length() > second_number.length()) {
                result = Sub(first_number, second_number);
                RemoveZeros(result);

            }
            else if(first_number.length() < second_number.length()) {
                result = Sub(second_number, first_number);

                if(result != "0") {
                    RemoveZeros(result);
                    result = '-' + result;
                }
            }
            else{
                if(CompareString(first_number, second_number)){
                    result = Sub(first_number, second_number);
                    RemoveZeros(result);
                }
                else{
                    result = Sub(second_number, first_number);

                    if(result != "0") {
                        RemoveZeros(result);
                        result = '-' + result;
                    }
                }
            }
        }
    }

    return result;
}

void SumFirst(int &i, int &str_length, string &result, const string *numbers){

    if(i < str_length){
        result = AddOrSub(result, numbers[i]); //dodawanie resulta i kolejnych wartosci stringa
        i++;
        SumFirst(i, str_length, result, numbers);
    }
}

void SumSecond(int &i, int &str_length, string &result, va_list numbers){

    if(i < str_length){
        result = AddOrSub(result, va_arg(numbers, char*)); //dodawanie resulta i kolejnych wartosci stringa
        i++;
        SumSecond(i, str_length, result, numbers);
    }
}

string Sum(int str_length, const string *numbers){

    string result = "";

    int i = 0;
    SumFirst(i, str_length, result, numbers);

    return result;
}

string Sum(int str_length, ...){

    string result = "";
    int i = 0;

    va_list numbers;
    va_start(numbers, str_length);
    SumSecond(i, str_length, result, numbers);
    va_end(numbers);

    return result;
}

void Sum(string *result, int str_length, const string *numbers) {
    *result = Sum(str_length, numbers);
}

void Sum(string *result, int str_length, ...){

    int i = 0;

    va_list numbers;
    va_start(numbers, str_length);
    SumSecond(i, str_length, *result, numbers);
    va_end(numbers);
}

void Sum(string &result, int str_length, const string *numbers) {
    Sum(&result, str_length, numbers);
}

void Sum(string &result, int str_length, ...){

    result = "";
    int i = 0;

    va_list numbers;
    va_start(numbers, str_length);
    SumSecond(i, str_length, result, numbers);
    va_end(numbers);
}

string Multiply2(int &i, int &j, int &amount, int &counter, string &numsToAdd, string &result, string &first_number, string &second_number){

    if(i>=0){
        numsToAdd = ToString((first_number[i]-'0') * (second_number[j]-'0'));
        AddZeros(numsToAdd, amount);
        result = Add(result, numsToAdd);
        i--;
        amount++;
        Multiply2(i, j, amount, counter, numsToAdd, result, first_number, second_number);
    }
    amount = counter;
    return result;
}

string Multiply1(int &i, int &j, int &amount, int &counter, string &numsToAdd, string &result, string &first_number, string &second_number){

    if(j>=0){
        Multiply2(i, j, amount, counter, numsToAdd, result, first_number, second_number);
        i = first_number.length()-1;
        counter++;
        j--;
        Multiply1(i, j, amount, counter, numsToAdd, result, first_number, second_number);
    }
    return result;
}

string Multiply(string first_number, string second_number){

    int i = first_number.length()-1;
    int j = second_number.length()-1;

    int amount = 0;
    int counter = 1;

    string numsToAdd = "";

    string result = "";

    result = Multiply1(i, j, amount, counter, numsToAdd, result, first_number, second_number);

    return result;

}

string Multiplier(string first_number, string second_number){

    bool first_minus = false;
    bool second_minus = false;

    string result = "";

    if(first_number[0]=='-'){
        first_minus = true;
        first_number = first_number.substr(1);
    }
    if(second_number[0]=='-'){
        second_minus = true;
        second_number = second_number.substr(1);
    }
    if(first_number[0]=='+'){
        first_number = first_number.substr(1);
    }
    if(second_number[0]=='+'){
        second_number = second_number.substr(1);
    }

    if(first_number != "0")
        RemoveZeros(first_number);
    if(second_number != "0")
        RemoveZeros(second_number);

    if(first_number == "0" || second_number == "0" || first_number == "" || second_number == "")
        return "0";

    if(first_number.length() < second_number.length())
        first_number.swap(second_number);

    if((first_minus && second_minus) || (!first_minus && !second_minus)){
        result = Multiply(first_number, second_number);
    }
    else{
        result = Multiply(first_number, second_number);
        result = '-' + result;
    }

    return result;
}

void MultFirst(int &i, int &str_length, string &result, const string *numbers){
    if(i<str_length){
        result = Multiplier(result, numbers[i]);
        i++;
        MultFirst(i, str_length, result, numbers);
    }
}

void MultSecond(int &i, int &str_length, string &result, va_list numbers){
    if(i < str_length){
        result = Multiplier(result, va_arg(numbers, char*)); //dodawanie resulta i kolejnych wartosci stringa
        i++;
        MultSecond(i, str_length, result, numbers);
    }
}

string Mult(int str_length, const string *numbers){

    string result = "1";
    int i = 0;

    MultFirst(i, str_length, result, numbers);

    return result;
}

string Mult(int str_length, ...){
    string result = "1";
    int i = 0;

    va_list numbers;
    va_start(numbers, str_length);
    MultSecond(i, str_length, result, numbers);
    va_end(numbers);

    return result;
}

void Mult(string *result, int str_length, const string *numbers){
    *result = Mult(str_length, numbers);
}

void Mult(string *result, int str_length, ...){
    int i = 0;
    *result = "1";
    va_list numbers;
    va_start(numbers, str_length);
    MultSecond(i, str_length, *result, numbers);
    va_end(numbers);
}

void Mult(string &result, int str_length, const string *numbers){
    Mult(&result, str_length, numbers);
}

void Mult(string &result, int str_length, ...){
    result = "1";
    int i = 0;

    va_list numbers;
    va_start(numbers, str_length);
    MultSecond(i, str_length, result, numbers);
    va_end(numbers);
}

string Operation(string(*f)(int, const string *), int str_length, const string *numbers){
    return f(str_length, numbers);
}

void DataFiller(int &i, int &str_length, string *data, va_list &numbers){
    if(i<str_length){
        data[i] = va_arg(numbers, char*);
        i++;
        DataFiller(i, str_length, data, numbers);
    }
}

string Operation(string (*f)(int, const string *), int str_length, ...){

    string data[str_length];
    int i = 0;

    va_list numbers;
    va_start(numbers, str_length);
    DataFiller(i, str_length, data, numbers);
    va_end(numbers);

    return Operation(f, str_length, data);
}

void Operation(string *result, string(*f)(int, const string *), int str_length, ...){
    string data[str_length];
    int i = 0;

    va_list numbers;
    va_start(numbers, str_length);
    DataFiller(i, str_length, data, numbers);
    va_end(numbers);

    *result = Operation(f, str_length, data);
}

void Operation(string *result, string(*f)(int, const string *), int str_length, const string *numbers){
    *result = f(str_length, numbers);
}

void Operation(string &result, string(*f)(int, const string *), int str_length, ...){
    string data[str_length];
    int i = 0;

    va_list numbers;
    va_start(numbers, str_length);
    DataFiller(i, str_length, data, numbers);
    va_end(numbers);

    result = Operation(f, str_length, data);
}

void Operation(string &result, string(*f)(int, const string *), int str_length, const string *numbers){
    result = f(str_length, numbers);
}
