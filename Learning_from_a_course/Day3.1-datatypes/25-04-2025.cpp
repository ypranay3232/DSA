#include <iostream>
using namespace std;

int main()
{
    // lets learn datatypes;
    // we have 3 types of data types. 1)built-in which are in built in c++. 2)Derived: these are derived from built-in data types. 3) User defined these are created and used by users(also known as custom datatypes)

    // 1) we have Integer,character,short,long,long long, float,doubt.
    // int stores 4 bytes --> 8 bits = 1 byte. (each bit can store either a 0 or 1) so 8(bits)*4 = Integer.

    int Password = 1234567890;

    cout << "The entered Password is : " << Password << endl;

    // character datatype
    char First_Letter = 'a';
    cout << "your first name is : " << First_Letter << endl;

    // A quick Question how do these get stored in the memory. as we know in binary (0's and 1's) not Quite these all characters are converted into ASCII values. 'A' = 65 and 'a' = 97. and these values are then converted back to binary and then we store them into memory.

    // Boolean Data type. It contains just two values either true or false. And it takes 1 Byte of memory (8 bits) but as we understood 1 bit is enough to represent (0/1) true of false. so why are we using 8 bits(1byte) because in computer the minimum addressable memory is 1 byte so you can't use a memory smaller than 1 Byte.
    bool Access = true;
    cout << "The value of Access is : " << Access << endl;
    // it displays 1 because the true indicates 1 and false indicates 0. And we can also represent 1 with True and 0 with false.

    // bool at = 1;
    // bool at = 0;
    // cout<<at<<endl;

    // Lets see Float and double both stores floating number values (i.e the values which comes after a decimal point)
    float f = 1.23435253453464564564;
    cout << f << endl;

    double d = 1.4343745928347584756486574836582749031745893;
    cout << d << endl;

    // if both works the same what's the difference Float ---> 4 bytes and Double ---> 8 bytes.

    // understand this the maximum number we can create in an datatype is : ex: int = 4 bytes so 2^32 -1. for short = 2^16-1

    // long long : it takes 8 bytes for storage (double of int) works the same. The main motive for these is if we have more space/storage capcity in an datatype we can store a large number. thats it

    // Now i want to scheck the size of an variable so we can use sizeof();

    cout << sizeof(d) << endl;

    // ex: let's say if we store a big number in a character then what will happen
    char ch1 = 9742364723 ;//Here the compiler is warning us that char can store only 1 byte but we gave it more than one byte to store so the data will be overflowed. And that stored data which character stored before overflowing that if it has any equivalent to ASCII it will display its respective value ex: if i store something like this (9743249823) then char which is of 256 bits will be divided by give number :         9742364723  % 256 =  3. so we get 3. and 
    cout << ch1 << endl;


    char ch2 = 9723223;
    cout<<ch2<<endl;//the same for this too 9723223 % 256 = 119 ----> 119 == 'w' in ASCII so it prints 'w'

    // what if we use an large number which exceeds the ASCII limit or a number which dont contain ASCII values
    char ch3 = 4703422;
    cout<<ch3<<endl;//prints an non-printable or blank space because we are trying to print when it dont exist

    return 0;
}