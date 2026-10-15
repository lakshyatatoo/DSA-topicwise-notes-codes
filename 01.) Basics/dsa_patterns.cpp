/*
============================================================
                PATTERN PRINTING NOTES
============================================================

CORE APPROACH
--------------
1. Outer loop  -> controls NUMBER OF ROWS
2. Inner loop  -> controls what appears in each ROW
3. Connect columns/values to the row number
4. Observe SYMMETRY
5. Find a FORMULA for:
      - stars
      - spaces
      - numbers
      - characters

IMPORTANT PATTERNS TO REMEMBER
------------------------------
Increasing  : i
Decreasing  : n-i
Pyramid     : spaces = n-i-1, stars = 2*i+1
Inverted    : spaces = i, stars = 2*n-(2*i+1)
Symmetric   : increasing + decreasing
Boundary    : top/bottom/left/right condition
*/

#include <bits/stdc++.h>
using namespace std;

/*
============================================================
P1 - SQUARE
============================================================

***
***
***

IDEA:
Rows = n
Columns = n
*/

void p1()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

/*
============================================================
P2 - INCREASING STAR TRIANGLE
============================================================

*
**
***
****

IDEA:
Stars = row number

row 1 -> 1 star
row 2 -> 2 stars
row 3 -> 3 stars
*/

void p2()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
============================================================
P3 - INCREASING NUMBER TRIANGLE
============================================================

1
12
123
1234

IDEA:
Print column number j
*/

void p3()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
============================================================
P4 - SAME NUMBER IN EACH ROW
============================================================

1
22
333
4444

IDEA:
Print row number i
*/

void p4()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

/*
============================================================
P5 - DECREASING STAR TRIANGLE
============================================================

***
**
*

IDEA:
Stars = n-i
*/

void p5()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
============================================================
P6 - DECREASING NUMBER TRIANGLE
============================================================

123
12
1

IDEA:
Start from i
Go up to n

row 1 -> 1 2 3
row 2 -> 2 3
row 3 -> 3
*/

void p6()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
============================================================
P7 - PYRAMID
============================================================

   *
  ***
 *****
*******

FORMULA:
spaces = n-i-1
stars  = 2*i+1
*/

void p7()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

/*
============================================================
P8 - INVERTED PYRAMID
============================================================

*******
 *****
  ***
   *

FORMULA:
spaces = i
stars  = 2*n-(2*i+1)
*/

void p8()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

/*
============================================================
P9 - DIAMOND
============================================================

   *
  ***
 *****
*******
 *****
  ***
   *

IDEA:
Pyramid + inverted pyramid
*/

void p9()
{
    int n;
    cin >> n;

    // Upper half
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Lower half
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * n - (2 * i + 3); j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

/*
============================================================
P10 - INCREASING + DECREASING
============================================================

*
**
***
****
***
**
*

ROWS = 2*n-1

STARS:
i <= n  -> i
i > n   -> 2*n-i
*/

void p10()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;

        if (i > n)
            stars = 2 * n - i;

        for (int j = 1; j <= stars; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

/*
============================================================
P11 - 0/1 TRIANGLE
============================================================

1
01
101
0101

IDEA:
Even row starts with 1
Odd row starts with 0

Toggle:
start = 1-start
*/

void p11()
{
    int n;
    cin >> n;

    int start;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;

        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }

        cout << endl;
    }
}

/*
============================================================
P12 - NUMBER PALINDROME
============================================================

1      1
12    21
123  321
12344321

THREE PARTS:
1. Left numbers
2. Spaces
3. Right numbers

spaces = 2*(n-i)
*/

void p12()
{
    int n;
    cin >> n;

    int spaces = 2 * (n - 1);

    for (int i = 1; i <= n; i++)
    {
        // left
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // middle spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // right
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }

        cout << endl;

        spaces -= 2;
    }
}

/*
============================================================
P13 - CONTINUOUS NUMBERS
============================================================

1
2 3
4 5 6
7 8 9 10

IDEA:
Use one variable that continues across rows.
*/

void p13()
{
    int n;
    cin >> n;

    int num = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }

        cout << endl;
    }
}

/*
============================================================
P14 - INCREASING ALPHABET
============================================================

A
AB
ABC
ABCD

IDEA:
Character goes from A to A+i
*/

void p14()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }

        cout << endl;
    }
}

/*
============================================================
P15 - DECREASING ALPHABET
============================================================

ABCDE
ABCD
ABC
AB
A

IDEA:
End character decreases every row.
*/

void p15()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
        {
            cout << ch << " ";
        }

        cout << endl;
    }
}

/*
============================================================
P16 - SAME CHARACTER IN EACH ROW
============================================================

A
BB
CCC
DDDD

IDEA:
Character stays same within a row.
Character changes after row.
*/

void p16()
{
    int n;
    cin >> n;

    char ch = 'A';

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << ch;
        }

        ch++;
        cout << endl;
    }
}

/*
============================================================
P17 - PALINDROMIC ALPHABET PYRAMID
============================================================

   A
  ABA
 ABCBA
ABCDCBA

IDEA:
1. spaces decrease
2. characters increase
3. then characters decrease

Example:
A B C D C B A
*/

void p17()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        char ch = 'A';

        // middle position
        int breakpoint = (2 * i + 1) / 2;

        // characters
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << ch;

            if (j < breakpoint)
                ch++;
            else
                ch--;
        }

        cout << endl;
    }
}

/*
============================================================
P18 - REVERSE STARTING ALPHABET
============================================================

E
DE
CDE
BCDE
ABCDE

IDEA:
Starting character decreases every row.
Ending character remains E.
*/

void p18()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch;
        }

        cout << endl;
    }
}

/*
============================================================
P19 - BUTTERFLY
============================================================

****    ****
***      ***
**        **
*          *
**        **
***      ***
****    ****

THREE PARTS:
left stars
middle spaces
right stars

Upper:
stars decrease
spaces increase

Lower:
stars increase
spaces decrease
*/

void p19()
{
    int n;
    cin >> n;

    int spaces = 0;

    // Upper half
    for (int i = 0; i < n; i++)
    {
        // left stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < spaces; j++)
        {
            cout << " ";
        }

        // right stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }

        spaces += 2;

        cout << endl;
    }

    // Lower half
    int innerSpaces = 2 * n - 2;

    for (int i = 1; i <= n; i++)
    {
        // left stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < innerSpaces; j++)
        {
            cout << " ";
        }

        // right stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        innerSpaces -= 2;

        cout << endl;
    }
}

/*
============================================================
P20 - SYMMETRIC BUTTERFLY
============================================================

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *

IDEA:
Rows = 2*n-1

stars:
increases till n
then decreases

spaces:
decreases till 0
then increases
*/

void p20()
{
    int n;
    cin >> n;

    int spaces = 2 * n - 2;

    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;

        if (i > n)
            stars = 2 * n - i;

        // left stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        // middle spaces
        for (int j = 0; j < spaces; j++)
        {
            cout << " ";
        }

        // right stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        // update spaces
        if (i < n)
            spaces -= 2;
        else
            spaces += 2;

        cout << endl;
    }
}

/*
============================================================
P21 - HOLLOW SQUARE
============================================================

******
*    *
*    *
*    *
*    *
******

IDEA:
Print * only on the boundary.

Top    -> i == 0
Bottom -> i == n-1
Left   -> j == 0
Right  -> j == n-1
*/

void p21()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 ||
                j == 0 || j == n - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}

/*
============================================================
P22 - CONCENTRIC NUMBER SQUARE
============================================================

For n = 5:

555555555
544444445
543333345
543222345
543212345
543222345
543333345
544444445
555555555

IDEA:
Find distance from each cell to all 4 boundaries.

left   = j
top    = i
right  = 2*n-2-j
bottom = 2*n-2-i

Take minimum distance.

value = n - minimumDistance
*/

void p22()
{
    int n;
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int left = j;
            int top = i;

            int right = (2 * n - 2) - j;
            int bottom = (2 * n - 2) - i;

            int minimumDistance =
                min(
                    min(top, bottom),
                    min(left, right));

            cout << n - minimumDistance;
        }

        cout << endl;
    }
}

/*
============================================================
                QUICK REVISION
============================================================

P1  -> Square
P2  -> Increasing stars
P3  -> Increasing numbers using j
P4  -> Same number using i
P5  -> Decreasing stars
P6  -> Decreasing numbers
P7  -> Pyramid
P8  -> Inverted pyramid
P9  -> Diamond
P10 -> Increasing + decreasing stars
P11 -> 0/1 pattern
P12 -> Number palindrome
P13 -> Continuous numbers
P14 -> Increasing alphabets
P15 -> Decreasing alphabets
P16 -> Same character per row
P17 -> Palindromic alphabet pyramid
P18 -> Reverse starting alphabet
P19 -> Butterfly
P20 -> Symmetric butterfly
P21 -> Hollow square
P22 -> Concentric number square


============================================================
MOST IMPORTANT FORMULAS
============================================================

Increasing triangle:
    stars = i

Decreasing triangle:
    stars = n-i

Pyramid:
    spaces = n-i-1
    stars  = 2*i+1

Inverted pyramid:
    spaces = i
    stars  = 2*n-(2*i+1)

Diamond:
    pyramid + inverted pyramid

Increasing/decreasing:
    rows = 2*n-1
    stars = i
    if (i > n)
        stars = 2*n-i

Hollow square:
    if (top || bottom || left || right)
        print '*'
    else
        print ' '

Concentric pattern:
    minimum distance from boundary
    answer = n - minimumDistance


============================================================
MASTER WAY TO THINK
============================================================

For EVERY pattern:

Step 1:
    How many rows?

Step 2:
    What does each row contain?

Step 3:
    How many spaces?

Step 4:
    How many stars/numbers/chars?

Step 5:
    What value am I printing?
        i?
        j?
        num?
        ch?

Step 6:
    Is there symmetry?

Step 7:
    Find the formula.

DON'T MEMORIZE THE CODE.
MEMORIZE THE RELATION BETWEEN ROW -> COLUMNS.
*/