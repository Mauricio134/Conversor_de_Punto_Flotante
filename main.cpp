#include <iostream>
#include <bitset>
#include <math.h>
#include <cstring>

using namespace std;

string quitar_uno_float(string number)
{
    int tam = number.length();
    char de[tam];
    strcpy(de,number.c_str());
    string new_de = number;
    for (int i = 0; i<tam;i++)
    {
        if(de[i] == '0')
        {
            new_de = new_de.erase(0,1);
        }
        else if(de[i] == '1')
        {
            new_de = new_de.erase(0,1);
            break;
        }
    }
    return new_de;
}

string quitar_uno_double(string number)
{
    int tam = number.length();
    char de[tam];
    strcpy(de,number.c_str());
    string new_de = number;
    for (int i = 0; i<tam;i++)
    {
        if(de[i] == '0')
        {
            new_de = new_de.erase(0,1);
        }
        else if(de[i] == '1')
        {
            new_de = new_de.erase(0,1);
            break;
        }
    }
    return new_de;
}

string integer_float(int number)
{
    string bi("");
    string nuevo("");
    if(number >0){
        while(number != 0)
        {
            int mod = number%2;
            if(mod == 1){
                bi = "1" + bi;
            }
            else{
                bi = "0" + bi;
            }
             number /= 2;
        }
        return bi;
    }
    else if(number < 0){
        number = number*(-1);
        while(number != 0)
        {
            int mod = number%2;
            if(mod == 1){
                bi = "0" + bi;
            }
            else{
                bi = "1" + bi;
            }
            number /= 2;
        }
        int tam = bi.length();
        char p[tam];
        strcpy(p, bi.c_str());
        char uno[tam];
        string uno_s = "1";
        string aca = "0";
        for(int i = 1; i< tam; i++){
            uno_s = "0" + uno_s;
        }
        strcpy(uno, uno_s.c_str());
        for(int i = tam-1; i>=0; i--){
            if(p[i] == '1' && uno[i] == '1'){
                if(aca == "1"){
                    nuevo = "1" + nuevo;
                    aca = "1";
                }
                else if(aca == "0"){
                    nuevo = "0" + nuevo;
                    aca = "1";
                }
            }
            else if((p[i] == '1' && uno[i] == '0')||(p[i] == '0' && uno[i] == '1')){
                if(aca == "1"){
                    nuevo = "0" + nuevo;
                    aca = "1";
                }
                else if(aca == "0"){
                    nuevo = "1" + nuevo;
                    aca = "0";
                }
            }
            else if(p[i] == '0' && uno[i] == '0'){
                if(aca == "1"){
                    nuevo = "1" + nuevo;
                    aca = "0";
                }
                else if(aca == "0"){
                    nuevo = "0" + nuevo;
                    aca = "0";
                }
            }
        }
        if(aca == "1"){
            nuevo = "1"+nuevo;
        }
        return nuevo;
    }
}

string integer_double(int number)
{
    string bi("");
    string nuevo("");
    if(number >0){
        while(number != 0)
        {
            int mod = number%2;
            if(mod == 1){
                bi = "1" + bi;
            }
            else{
                bi = "0" + bi;
            }
             number /= 2;
        }
        return bi;
    }
    else if(number < 0){
        number = number*(-1);
        while(number != 0)
        {
            int mod = number%2;
            if(mod == 1){
                bi = "0" + bi;
            }
            else{
                bi = "1" + bi;
            }
            number /= 2;
        }
        int tam = bi.length();
        char p[tam];
        strcpy(p, bi.c_str());
        char uno[tam];
        string uno_s = "1";
        string aca = "0";
        for(int i = 1; i< tam; i++){
            uno_s = "0" + uno_s;
        }
        strcpy(uno, uno_s.c_str());
        for(int i = tam-1; i>=0; i--){
            if(p[i] == '1' && uno[i] == '1'){
                if(aca == "1"){
                    nuevo = "1" + nuevo;
                    aca = "1";
                }
                else if(aca == "0"){
                    nuevo = "0" + nuevo;
                    aca = "1";
                }
            }
            else if((p[i] == '1' && uno[i] == '0')||(p[i] == '0' && uno[i] == '1')){
                if(aca == "1"){
                    nuevo = "0" + nuevo;
                    aca = "1";
                }
                else if(aca == "0"){
                    nuevo = "1" + nuevo;
                    aca = "0";
                }
            }
            else if(p[i] == '0' && uno[i] == '0'){
                if(aca == "1"){
                    nuevo = "1" + nuevo;
                    aca = "0";
                }
                else if(aca == "0"){
                    nuevo = "0" + nuevo;
                    aca = "0";
                }
            }
        }
        if(aca == "1"){
            nuevo = "1"+nuevo;
        }
        return nuevo;
    }
}

string decimal_float(float number)
{
    string bi = "";
    while(number){
        if(number > 0)
        {
            number = number*2;
            if(number >= 1){
                bi += "1";
                number--;
            }
            else{
                bi += "0";
            }
        }
    }
    return bi;
}

string decimal_double(double number)
{
    string bi = "";
    while(number){
        if(number > 0)
        {
            number = number*2;
            if(number >= 1){
                bi += "1";
                number--;
            }
            else{
                bi += "0";
            }
        }
    }
    return bi;
}

string biased_float(int exponente)
{
    int expo = exponente+(pow(2,7)-1);
    string expone = integer_float(expo);
    return expone;
}

string biased_double(int exponente)
{
    int expo = exponente+(pow(2,10)-1);
    string expone = integer_double(expo);
    return expone;
}

string float_to_binary(float a)
{
    string sign;
    if(a>0){
        sign = "0";
    }
    else if(a<0){
        sign = "1";
    }
    string in = integer_float((int)a);
    float deci = a-(int)a;
    if(deci < 0){
        deci = deci* -1;
    }
    string de = decimal_float(deci);
    string expo = biased_float(in.length()-1);
    string real_de = quitar_uno_float(in) + de;
    if(real_de.length() < 23){
        string con("");
        int initial = 1;
        while(initial <= 23-real_de.length()){
            con = "0" + con;
            initial++;
        }
        string result = "SIGNO: " + sign +"\n"+ "EXPONENTE: " + expo + "\n" + "SIGNIFICANDO: " + real_de + con;
        return result;
    }
    else if(real_de.length() == 23){
        string result = "SIGNO: " + sign +"\n"+ "EXPONENTE: " + expo + "\n" + "SIGNIFICANDO: " + real_de;
        return result;
    }
}

string double_to_binary(double b)
{
    string sign;
    if(b>0){
        sign = "0";
    }
    else if(b<0){
        sign = "1";
    }
    string in = integer_double((int)b);
    double deci = b-(int)b;
    if(deci < 0){
        deci = deci* -1;
    }
    string de = decimal_double(deci);
    string expo = biased_double(in.length()-1);
    string real_de = quitar_uno_double(in) + de;
    if(real_de.length() < 53){
        string con("");
        int initial = 1;
        while(initial <= 53-real_de.length()){
            con = "0" + con;
            initial++;
        }
        string result = "SIGNO: " + sign +"\n"+ "EXPONENTE: " + expo + "\n" + "SIGNIFICANDO: " + real_de + con;
        return result;
    }
    else if(real_de.length() == 53){
        string result = "SIGNO: " + sign +"\n"+ "EXPONENTE: " + expo + "\n" + "SIGNIFICANDO: " + real_de;
        return result;
    }
}

int main()
{
    float a;
    cout << "Introduce un numero float: ";
    cin >> a;

    double b;
    cout << "Introduce un numero double: ";
    cin >> b;

    float c;
    cout << "Ingresar float para cambiar a double: ";
    cin >> c;

    cout << "<---FLOAT A BINARIO DE " << a << " --->" << endl;
    cout <<float_to_binary(a) << endl;
    cout<< endl;
    cout << "<---DOUBLE A BINARIO DE " << b << " --->" << endl;
    cout << double_to_binary(b) << endl;
    cout<< endl;
    cout << "<---FLOAT A DOUBLE DE " << c << " --->" << endl;
    cout << "=== FLOAT BINARY === \n" << float_to_binary(c) << endl;
    cout << "=== DOUBLE BINARY === \n" << double_to_binary((double)c);
    return 0;
}
