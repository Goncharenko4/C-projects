#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int base = 10; // number system

/*
    The function divides the number 'a' by a short number 'b'
    and returns the remainder of division:
*/
int Remainder_of_the_division(vector<int> a, int b) {
    /*
        r - indicates the current balance to which the next digit will be assigned
        Initially the remainder is 0
    */
    int r = 0;
    unsigned long n1 = a.size(); // length of a large number
    
    /*
        Cycle from the highest digits to the lowest, assigning the next digit
        Writing a quotient of division to the result
    */
    for (int i = 0; i < n1; i++) {
        r = r * base + a[i];
        a[i] = r / b;
        r %= b;
    }
    return r;
}

/*
    The function adds the number 'b' to the number 'a':
*/
vector<int> addition(vector<int> a, vector<int> b) {
    if (a[0] < b[0]) {
        a[0] = b[0];
    }
    
    /*
         You need to add up to the size of a larger number
         r - indicates how much we have "keep in mind"
         When adding the lower digits in the mind, we have 0
    */
    int r = 0;
    for (int i = 1; i <= a[0]; i++) {
        a[i] += b[i] + r;
        
        // If there is a transfer to the next category:
        if (a[i] >= 10) {
            r = 1;
            a[i] -= 10;
        } else {
             r = 0;
        }
    }

    // If there is still a transfer left after adding, then add another digit:
    if (r > 0) {
        a[0]++;
        a[a[0]] = r;
    }
    return a;
}


/*
    The function subtracts the number 'b' from the number 'a':
*/
vector<int> subtraction(vector<int> a, vector<int> b) {
    /*
         r - indicates whether the unit was borrowed from the current digit of the number
        There isn't loan from the lowest digit of the number
    */
    int r = 0;
    for (int i = 1; i <= a[0]; i++) {
        a[i] -= b[i] + r; // the difference in the next digits, including the loan
        
        // When is a loan made from the next digit of the number:
        if (a[i] < 0) {
            r = 1;
            a[i] += base;
        } else {
            r = 0;
        }
    }
    /*
        The difference may contain fewer digits,
        therefore, you need to reduce the number of digits if necessary
    */
    while ((a[0] > 1) && (a[a[0]] == 0)) {
        --a[0];
    }
    return a;
}


/*
    The function multiplies the number 'a' by the short number 'b':
*/
vector<int> multiplication (vector<int> a, int b) {
    /*
        r - indicates transfer to the current category
        There isn't transfer to the lowest digit of the number
    */
    int r = 0;
    for (int i = 1; i <= a[0]; i++) {
        /*
            The product of the next digit and a short number, taking into account
            the transfer to the current digit, calculating the transfer to the next digit
            (we leave only the part of multiplication smaller than base)
        */
        a[i] = a[i] * b + r;
        r = a[i] / base;
        a[i] -= r *base;
    }

    /*
        If there is still a carry after multiplication, then you need to add another digit.
        You may need to add multiple digits if the number 'b' is greater than base
    */
    while (r > 0) {
        a[0]++;
        a[a[0]] = r % base;
        r = r / base;
    }
    return a;
}

/*
    The function multiplies the number 'a' by the number 'b':
*/
vector<int> multiplication_huge (vector<int> a, vector<int> b) {
    /*
        'c' - the result of the multiplication,
        in this case you can't write the result in the same array
    */
    vector<int> c(max(a.size(), b.size()), 0);

    for (int i = 1; i <= a[0]; i++) {
        int r = 0, j;
        for (j = 1; j <= b[0] || r > 0; j++) {
            // As long as there is a digit transfer or there are more digits in 'b':
            c[i + j - 1] += a[i] * b[j] + r;
            /*
                When multiplying by the previous digits, some value is already written
                in 'c', so you need to add, not assign:
            */
            r = c[i + j - 1] / base;
            c[i + j - 1] -= r * base;
        }
    }
    c[0] = a[0] + b[0];

    // Move the answer to the 'a' array:
    a = c;

    // There may be fewer numbers:
    while ((a[0] > 1) && (a[a[0]] == 0)) {
        --a[0];
    }
    return a;
}

int main() {
    string str1;
    string str2;
    
    cin >> str1;
    cin >> str2;
    
    return 0;
}
