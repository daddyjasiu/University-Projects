//Jan Skwarczek

void ReverseString1(std::string &set1, string &result, int &i){
	
    if (i >= 0) {
        result += set1[i];
        i--;
        ReverseString1(set1, result, i);
    }
}

void ReverseString(std::string &set1){
	
    std::string result;
    int i = set1.size() - 1;
    ReverseString1(set1, result, i);
    set1 = result;
}

void Push1(std::string &set1, int &i, int &n){
	
    if (i < n) {
        set1 += "0";
        i++;
        Push1(set1, i, n);
    }
}

void Push(std::string &set1, int n){
	
    int i = 0;
    Push1(set1, i, n);
}

int isGreater1(std::string &set1, std::string &set2, int &i){
	
    if (i <= set1.size()) {
        if (set1[i] > set2[i])
        {
            return 1;
        }
        else if (set1[i] < set2[i])
        {
            return 0;
        }
        i++;
        return isGreater1(set1, set2, i);
    }
    return 3;
}

bool isGreater(std::string& set1,std::string& set2){
	
    if( set1.size() > set2.size() )
        return true;
        
    if( set1.size() < set2.size() )
        return false;

    int i = 0;
    int tmp = isGreater1(set1,set2,i);
    if (tmp == 1){
        return true;
    }
    else if (tmp == 0){
        return false;
    }
    return false;
}

void Add1(std::string &set1, std::string &set2, std::string &result, int &carryValue, int &sum, int &i, int &set1Size) {
    if (i < set1Size) {
        sum = (set1[i] - '0') + (set2[i] - '0') + carryValue;
        result += (sum % 10 + '0');
        carryValue = sum / 10;
        i++;
        Add1(set1, set2, result, carryValue, sum, i, set1Size);
    }
}

void Add2(std::string &set1, std::string &set2, std::string &result, int &carryValue, int &sum, int &i, int &set2Size) {
    if (i < set2Size) {
        sum = (set2[i] - '0') + carryValue;
        result += (sum % 10 + '0');
        carryValue = sum / 10;
        i++;
        Add2(set1, set2, result, carryValue, sum, i, set2Size);
    }
}

std::string Add(std::string set1, std::string set2) {
    std::string result = "";
    int sum = 0;
    int carryValue = 0;
    if (set1.size() > set2.size())
        set1.swap(set2);

    ReverseString(set1);
    ReverseString(set2);
    int set1Size = set1.size();
    int set2Size = set2.size();

    int i = 0;
    Add1(set1, set2, result, carryValue, sum, i, set1Size);

    i = set1Size;
    Add2(set1, set2, result, carryValue, sum, i, set2Size);

    if (carryValue)
        result += (carryValue + '0');
    ReverseString(result);
    return result;
}


void Sub2 (std::string &set1 , std::string &set2 , int &k , int &sum , int &carryValue , int &set1Size, int &set2Size , std::string &result) {

    if (k < set1Size) {
        sum = (set1[k] - '0') - carryValue;
        if (sum < 0) {
            sum += 10;
            carryValue = 1;
        } else {
            carryValue = 0;
        }
        result += (sum + '0');
        k ++;
        Sub2(set1, set2, k, sum, carryValue, set1Size, set2Size, result);
    }
}


void Sub1 (std::string &set1 , std::string &set2 , int &i , int &sum , int &carryValue , int &set2Size , std::string &result){

    if (i < set2Size){
        sum = (set1[i] - '0') - (set2[i] - '0') - carryValue;
        if(sum < 0){
            sum += 10;
            carryValue = 1;

        } else {

            carryValue = 0;
        }
        result += (sum + '0');
        i ++;
        Sub1(set1, set2, i, sum, carryValue, set2Size, result);
    }
}


std::string Sub( std::string set1, std::string set2 ) {
    std::string result = "";
    int sum = 0;
    int carryValue = 0;

    ReverseString(set1);
    ReverseString(set2);
    int set1Size = set1.size();
    int set2Size = set2.size();

    int i = 0;

    Sub1(set1, set2, i, sum, carryValue, set2Size, result);

    int k = set2Size;

    Sub2(set1, set2, k, sum, carryValue, set1Size, set2Size, result);

    ReverseString( result );

    int pom= result.find_first_not_of('0');
    if( pom>= result.size())
        result = "0";
    else
        result.erase(0, pom);

    return result;
}
std::string PartSum(std::string set1, std::string set2) {
    bool notA = false;
    bool notB = false;
    std::string result = "";

    if (set1.size() > 0 && set1[0] == '+')
        set1 = set1.substr(1);
    if (set2.size() > 0 && set2[0] == '+')
        set2 = set2.substr(1);


    if (set1.size() > 0 && set1[0] == '-') {
        notA = true;
        set1 = set1.substr(1);
    }
    if (set2.size() > 0 && set2[0] == '-') {
        notB = true;
        set2 = set2.substr(1);
    }

    if (!notA && !notB)
        result = Add(set1, set2);
    else if (notA && notB) {
        result = Add(set1, set2);
        result = "-" + result;
    } else {
        if (notA) {
            if (isGreater(set1, set2)) {
                result = Sub(set1, set2);
                if (result != "0")
                    result = "-" + result;
            } else
                result = Sub(set2, set1);
        } else { // set1 - set2
            if (isGreater(set2, set1)) {
                result = Sub(set2, set1);
                if (result != "0")
                    result = "-" + result;
            } else
                result = Sub(set1, set2);
        }
    }
    return result;
}

void Sum1 (std::string &result, int &i, int &set, const std::string *data){
    
	if( i < set){
        result = PartSum(result, data[i]);
        i++;
        Sum1(result, i, set, data);
    }
	
}

std::string Sum(int set, const std::string *data) {
    
	std::string result = "0";
    int i = 0;
    Sum1(result, i, set, data);
    return result;
}

void Sum2 (int &set, std::string &result, std::string &tmp, va_list &args){
    
	if (set > 0){
        tmp = va_arg(args, char*);
        result = PartSum(result, tmp);
        set--;
        Sum2(set,result,tmp,args);
    }
}

std::string Sum(int set, ...) {
	
    std::string result = "0";
    std::string tmp;
    va_list args;
    va_start(args, set);
    Sum2(set,result,tmp,args);
    va_end(args);
    return result;
    
}

void Sum(std::string *result, int set, const std::string *data) {
    *result = Sum(set, data);
}

void Sum3 (std::string *result, int &set, std::string &tmp, va_list &args){
    if(set > 0){
        tmp = va_arg(args, char*);
        *result = PartSum(*result, tmp);
        set--;
        Sum3(result, set, tmp, args);
    }
}

void Sum(std::string *result, int set, ...) {
    *result = "0";
    std::string tmp;
    va_list args;
    va_start(args, set);
    Sum3(result, set, tmp, args);
    va_end(args);
}

void Sum(std::string &result, int set, const std::string *data) {
    Sum(&result, set, data);
}

void Sum(std::string &result, int set, ...) {
    result = "0";
    std::string tmp;
    va_list args;
    va_start(args, set);
    Sum2(set,result,tmp,args);
    va_end(args);
}

void PartMult2(std::string &set1, std::string &set2, std::string &tmp, std::string &result, int &j) {
    if (j > 0) {
        tmp = Add(tmp, set1);
        j--;
        PartMult2(set1, set2, tmp, result, j);
    }
}


void PartMult1(std::string &set1, std::string &set2, std::string &tmp, std::string &result, int &i) {
    if (i >= 0) {
        tmp = "0";
        int j = set2[i] - '0';
        PartMult2(set1, set2, tmp, result, j);
        Push(tmp, set2.size() - 1 - i);
        result = Add(result, tmp);
        i--;
        PartMult1(set1, set2, tmp, result, i);
    }
}


std::string PartMult(std::string set1, std::string set2) {

    bool aNeg = false;
    bool bNeg = false;
    std::string result;
    std::string tmp;

    if (set1.size() > 0 && set1[0] == '+')
        set1 = set1.substr(1);
    if (set2.size() > 0 && set2[0] == '+')
        set2 = set2.substr(1);

    if (set1.size() > 0 && set1[0] == '-') {
        aNeg = true;
        set1 = set1.substr(1);
    }
    if (set2.size() > 0 && set2[0] == '-') {
        bNeg = true;
        set2 = set2.substr(1);
    }

    if (set1 == "0" || set2 == "0")
        return "0";

    int i = set2.size() - 1;
    PartMult1(set1, set2, tmp, result, i);

    if (aNeg ^ bNeg)
        result = "-" + result;

    return result;
}

void Mult1(int &set, const std::string *data, std::string &result, int &i) {
	
    if (i < set) {
        result = PartMult(result, data[i]);
        i++;
        Mult1(set, data, result, i);
    }
}

std::string Mult(int set, const std::string *data) {
	
    std::string result = "1";
    int i = 0;
    Mult1(set, data, result, i);
    return result;
}

void Mult2(int &set, std::string &tmp, std::string &result, va_list &args) {
	
    if (set-- > 0) {
        tmp = va_arg(args, char*);
        result = PartMult(result, tmp);
        Mult2(set, tmp, result, args);
    }

}

std::string Mult(int set, ...) {
	
    std::string result = "1";
    std::string tmp;
    va_list args;
    va_start(args, set);
    Mult2(set, tmp, result, args);
    va_end(args);
    return result;
}

void Mult(std::string *result, int set, const std::string *data) {
    *result = Mult(set, data);
}


void Mult3(int &set, std::string &tmp, std::string *result, va_list& args) {
    if (set-- > 0) {
        tmp = va_arg( args, char*);
        *result = PartMult(*result, tmp );
        Mult3(set, tmp, result, args);
    }
}

void Mult(std::string* result, int set, ... ){
    *result = "1";
    std::string tmp;
    va_list args;
    va_start(args, set );
    Mult3(set, tmp, result, args);
    va_end(args );
}


void Mult(std::string &result, int set, const std::string *data) {
    Mult(&result, set, data);
}


void Mult(std::string &result, int set, ...) {
    result = "1";
    std::string tmp;
    va_list args;
    va_start(args, set);
    Mult2(set, tmp, result, args);
    va_end(args);
}

std::string Operation(std::string (*funct)(int, const std::string *), int set, const std::string *data) {
    return funct(set, data);
}

void Operation1(int &set, std::string *data, int &i, va_list& args) {
    if (i < set) {
        data[i] = va_arg(args, char*);
        i++;
        Operation1(set, data, i, args);
    }

}

std::string Operation(std::string (*funct)(int, const std::string *), int set, ...) {
	
    std::string *data = new std::string[set];
    va_list args;
    va_start(args, set);
    int i = 0;
    Operation1(set, data, i, args);
    va_end(args);

    std::string result = Operation(funct, set, data);
    delete[] data;
    return result;
}

void Operation(std::string *result, std::string (*funct)(int, const std::string *), int set, ...) {

    std::string *data = new std::string[set];
    va_list args;
    va_start(args, set);
    int i = 0;
    Operation1(set, data, i, args);
    va_end(args);

    *result = Operation(funct, set, data);
    delete[] data;
}

void Operation(std::string *result, std::string (*funct)(int, const std::string *), int set, const std::string *data) {
    *result = funct(set, data);
}

void Operation(std::string &result, std::string (*funct)(int, const std::string *), int set, ...) {

    std::string *data = new std::string[set];
    va_list args;
    va_start(args, set);
    int i = 0;
    Operation1(set, data, i, args);
    va_end(args);

    result = Operation(funct, set, data);
    delete[] data;
}

void Operation(std::string &result, std::string (*funct)(int, const std::string *), int set, const std::string *data) {
    result = funct(set, data);
}

