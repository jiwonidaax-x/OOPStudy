# Workshop #3: Member Functions and Privacy
* Version 0.7   Part 1 only

In this workshop, you will use member functions, privacy, safe empty state and formatting the output to complete your work.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities:

- to define a class type
- to privatize data within the class type
- to instantiate objects of class type
- to access data within an object of class type through public member functions
- to use standard library facilities to format data inserted into the output stream
- to describe to your instructor what you have learned in completing this workshop

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1: A step-by-step guided workshop, worth 50% of the workshop's total mark that is due on **Thursday at 23:59:59** of the week of your scheduled lab.
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your OOP244 class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark. This part is due on **Sunday at 23:59:59** of the week of your scheduled lab.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.


If at the deadline the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

If the file contains only your work or work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace.

# LAB (50%) Library Book Loan Report Module

Seneca library system creates a daily report of the books on loan in a file in the following format:

```text
Book Title
comma
Stock Keeping Unit Number
comma
Number Of Days on Loan
newline
```

Example:

```text
Alice's Adventures In Wonderland,122,15 
Don Quixote,100,4 
Pilgrim's Progress,101,18 
Robinson Crusoe,102,20
Gulliver's Travels,103,4
Tom Jones,104,6
Clarissa,105,11
Tristram Shandy,106,13
Dangerous Liaisons,107,11
Emma,108,12
Frankenstein,109,14
Nightmare Abbey,110,11
The Black Sheep,111,10
Jude the Obscure,134,12
The Charterhouse of Parma,112,2
Sybil,113,12
David Copperfield,114,16
Wuthering Heights,115,17
```

Your task for this lab is to create the modules required to provide functionalities to other programmers to create on-screen reports of:

- All the books that are on loan

```text
------------------------------------------------------------------------------
*****  Seneca Library  *****
Books on Loan
------------------------------------------------------------------------------
Row Book title                                       SKU     loan days penalty
--- ------------------------------------------------ ------- --------- -------
1   Alice's Adventures In Wonderland                 122     15
2   Don Quixote                                      100     4
3   Pilgrim's Progress                               101     18           4.50
4   Robinson Crusoe                                  102     20           7.50
5   Gulliver's Travels                               103     4
6   Tom Jones                                        104     6
7   Clarissa                                         105     11
8   Tristram Shandy                                  106     13
9   Dangerous Liaisons                               107     11
10  Emma                                             108     12
11  Frankenstein                                     109     14
------------------------------------------------------------------------------
```

- All the books that are on loan and overdue to be returned

```text
Overdue Books
------------------------------------------------------------------------------
Row Book title                                       SKU     loan days penalty
--- ------------------------------------------------ ------- --------- -------
1   Pilgrim's Progress                               101     18           4.50
2   Robinson Crusoe                                  102     20           7.50
3   David Copperfield                                114     16           1.50
4   Wuthering Heights                                115     17           3.00
5   The Woman in White                               121     18           4.50
6   Dangerous Liaisons                               107     18           4.50
7   Nostromo                                         137     23          12.00
8   The Brothers Karamazov                           127     19           6.00
------------------------------------------------------------------------------
```

- All the books with their title containing a substring.

```text
>>> Searching for: "The" <<<
------------------------------------------------------------------------------
*****  Seneca Library  *****
Substring search
------------------------------------------------------------------------------
Row Book title                                       SKU     loan days penalty
--- ------------------------------------------------ ------- --------- -------
1   The Black Sheep                                  111     10
2   The Charterhouse of Parma                        112     2
3   The Scarlet Letter                               118     9
4   The Woman in White                               121     18           4.50
5   The Way We Live Now                              124     7
6   The Brothers Karamazov                           127     19           6.00
7   The Portrait of a Lady                           128     20           7.50
8   The Strange Case of Dr Jekyll and Mr Hyde        130     
------------------------------------------------------------------------------
```

## Implementation
To accomplish this, create two modules; the Book and the Library. 

The Book should hold a single record of the book on loan in the report file.
The Library should hold a dynamically allocated array of books and provide the required reports.

> Note: Reading and accessing the data file and populating the Modules are done by the tester program. You are not implementing any file-related code

## The Book module. (The Book class)
### Constant Values
Define two constant values in the Book module:

```C++
	const double PENALTY = 1.5; // Penalty in dollars for each day a book's return is overdue
	const int MAXLOAN = 15; // Maximum number of days to loan a book witout penalty.
```

### Member variables (properties)

All the member variables are private.

#### m_title

Title of the book; an array of 51 characters to hold a Cstring of a maximum of 50 characters.

#### m_SKU

Stock Keeping Unit number, an integer

#### m_daysOnLoan;
The number of days on loan.

### Member Functions (Methods)
#### Public Methods:
##### set

Accepts three arguments and returns void:
- Book title: a constant Cstring for the title of the book
- SKU Number: (integer)
- Number of days on loan: (integer)

If the book title is not null, and not an empty string and if the SKU and number of days are greater than zero, this function will set the corresponding member variables to the values of the arguments, otherwise, it will set the Book to a safe invalid empty state. (see setEmpty() method)

##### isEmpty

This constant member function will accept nothing and return true (a boolean) if the Book is in a safe empty state and false if it is not. (See setEmpty() to see what is the condition of an empty state here)

##### hasPenalty

This constant member function will accept nothing and returns true (a boolean) if the **number of days on loan** member variable is greater than the **MAXLOAN** constant integer value;

##### subTitle

The subTitle function receives a constant Cstring (a substring) and returns true if the Cstring exists within the title of the book and otherwise returns false.

For example, if the title of the book is **Alice's Adventures In Wonderland** and the Cstring argument passed to the function is **Wond**, the function returns true. However, if the Cstring is **abc** it should return false:

```C++
subTitle("Wond"); // returns true
subTitle("abc"); // returns false.
```

> Hint: Use the strstr function in &lt;cstring&gt; to accomplish this.

##### display

This constant function returns void and does not accept anything.
Display prints the book's properties in the following format if the book is not in a safe empty state:
- in 49 spaces, left-justified, prints the title
- in 8 spaces, left-justified, prints the SKU
- in 10 spaces, left-justified, prints the number of days on loan
- if the book is overdue (hasPenalty) in 7 spaces, right-justified and with two digits after the decimal point, it will print the penalty. (see penalty function)
- goes to newline.

If the book is in a safe empty state, it will print `"Invalid library book"` and goes to a new line

#### Private Methods
##### setEmpty

Returns void and receives nothing.
Set the book's title to an empty Cstring and other properties to zero.

##### penalty

This constant method returns a double and receives nothing.
The double value returned, is the product of the overdue days and the **PENALTY** constant value. (overdue days = days on loan - MAXLOAN)

## The Library Module
### Private Member Variables (properties)
#### m_name

This module will hold the name of the library up to 30 characters in a Cstring of 31 characters.

#### m_books

A Book pointer to hold a dynamic array of Book objects.

#### m_sizeOfBooksArray

An integer to hold the size of the dynamic array of books

#### m_addedBooks

An integer to keep track of the number of books that are set to valid values in the books array. 

### One Private Member function
#### setEmpty

Returns void and receives nothing.

setEmpty sets the name to an empty Cstring and all the other properties to zero and nullptr.

### Public Member functions

```C++
void initialize(const char* name, int noOfBooks);
```

If the name is not null and not an empty Cstring and noOfBooks is greater than zero, it will:
   - copy the name into the library name
   - set the size of **books** array to the noOfBooks
   - allocate a dynamic array of Books to the **noOfBooks**.  (if the allocation fails it will set the Library into a safe empty state)

Otherwise, it will set the Library into a safe empty state. 

```C++
bool addBook(const char* book_title, int sku, int loanDays);
```

If the number of added books is less than the size of the books array, it will use the set method of the book to set the values of the next book in the array to the incoming arguments. If after setting the book, the newly added book is valid (not in a safe empty state) it will add one to the number of books and return true. 

In all the other cases it will return false.

```C++
void clear();
```

Releases the allocated memory and sets the books pointer to nullptr.

```C++
bool isEmpty()const;
```

Returns true if the Library is in a safe invalid empty state

```C++
void header(const char* title)const;
```

Prints the header of the loaned books report as follows:
- prints dashes ('-') 78 times and goes to a new line
- prints ```"*****  "```, library name and  ```"  *****"``` then goes to a new line
- prints the title argument and goes to a new line
- prints dashes ('-') 78 times and goes to a new line
- prints 

```
"Row Book title                                       SKU     loan days penalty"
``` 

and goes to a new line
- prints 

```
"--- ------------------------------------------------ ------- --------- -------"
``` 

   and goes to a new line

```C++
void footer()const;
```

- prints dashes ('-') 78 times and goes to a new line

```C++
void display(const char* substr);
```

This function performs the following only if the Library is not in a safe empty state, otherwise, it will print `"Invalid Library"`, goes to a new line and exits the function.
defines an integer for row number and sets it to one.
defines a search flag and sets it to false;
- prints `">>> Searching for: \""`
- prints the **substr**
- prints `"\" <<<"` and goes to a new line
- calls header function with `"Substring search"` as an argument
- In a loop to the number of added books it will print the elements of the books array as follows (with a condition):
   - if the subTitle function of the book element returns true having the **substr** as an argument the function will print:
   - in 4 spaces, left-justified it will print the row number and add one to it.
   - calls the display of the book element.
   - sets the search flag to true
- If the search flag is false it will print:
   - `"No book title contains \""`
   - **substr** value
   - `"\""` and goes to a new line
- prints the footer

```C++
void display(bool overdueOnly=false)const;
```

This function performs the following only if the Library is not in a safe empty state, otherwise, it will print `"Invalid Library"`, goes to a new line and exits the function.

defines an integer for row number and sets it to one.
- prints the header with one of the following titles:
   - overdueOnly is true: `"Overdue Books"`
   - overdueOnly is false: `"Books on Loan"`
- In a loop to the number of added books it will print the elements of the books array as follows (with the following condition):
   - if the **overdueOnly** is true, it will only print those books that are overdue (hasPenalty()) otherwise it will print them all.
   - in 4 spaces, left-justified it will print the row number and add one to it.
   - calls the display of the book element.
- prints the footer

## Tester program

```C++
// Workshop #3:
// Version: 0.9
// Date: 2021/09/26
// Author: Fardad Soleimanloo, Original Nargis Khan
// Description:
// This file tests the lab section of your workshop
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Library.h"
#include "Book.h"
using namespace std;
using namespace sdds;
int noOfRecs(FILE* fptr);
void readBooks(Library& L, FILE* fptr);
int main() {
   FILE* fptr = fopen("books.csv", "r");
   Library b[4];
   Library L;
   int i;
   b[0].initialize("", 10);
   b[1].initialize(nullptr, 20);
   b[2].initialize("something", 0);
   b[3].initialize("something", -1);
   for (i = 0; i < 4; i++) {
      b[i].display();
      b[i].clear();
   }
   L.initialize("Seneca Newnham Library", noOfRecs(fptr));
   readBooks(L, fptr);
   L.display();
   L.display(true);
   L.display("The");
   L.display("ter");
   L.clear();
   fclose(fptr);
}
int noOfRecs(FILE* fptr) {
   int no = 0;
   int newline = 0;
   while ((newline = fgetc(fptr)) != EOF) {
      no += (newline == '\n');
   }
   rewind(fptr);
   return no;
}
void readBooks(Library& L, FILE* fptr) {
   int noOfRecs = ::noOfRecs(fptr);
   char book_title[51];
   int sku;
   int days;
   for (int i = 0; i < noOfRecs; i++) {
      fscanf(fptr, "%[^,],%d,%d\n", book_title, &sku, &days);
      L.addBook(book_title, sku, days);
   }
}
```

## Execution sample

```text
Invalid Library
Invalid Library
Invalid Library
Invalid Library
------------------------------------------------------------------------------
*****  Seneca Newnham Library  *****
Books on Loan
------------------------------------------------------------------------------
Row Book title                                       SKU     loan days penalty
--- ------------------------------------------------ ------- --------- -------
1   Alice's Adventures In Wonderland                 122     15
2   Don Quixote                                      100     4
3   Pilgrim's Progress                               101     18           4.50
4   Robinson Crusoe                                  102     20           7.50
5   Gulliver's Travels                               103     4
6   Tom Jones                                        104     6
7   Clarissa                                         105     11
8   Tristram Shandy                                  106     13
9   Dangerous Liaisons                               107     11
10  Emma                                             108     12
11  Frankenstein                                     109     20           7.50
12  Nightmare Abbey                                  110     11
13  The Black Sheep                                  111     10
14  Jude the Obscure                                 134     22          10.50
15  The Charterhouse of Parma                        112     2
------------------------------------------------------------------------------
------------------------------------------------------------------------------
*****  Seneca Newnham Library  *****
Overdue Books
------------------------------------------------------------------------------
Row Book title                                       SKU     loan days penalty
--- ------------------------------------------------ ------- --------- -------
1   Pilgrim's Progress                               101     18           4.50
2   Robinson Crusoe                                  102     20           7.50
3   Frankenstein                                     109     20           7.50
4   Jude the Obscure                                 134     22          10.50
------------------------------------------------------------------------------
>>> Searching for: "The" <<<
------------------------------------------------------------------------------
*****  Seneca Newnham Library  *****
Substring search
------------------------------------------------------------------------------
Row Book title                                       SKU     loan days penalty
--- ------------------------------------------------ ------- --------- -------
1   The Black Sheep                                  111     10
2   The Charterhouse of Parma                        112     2
------------------------------------------------------------------------------
>>> Searching for: "ter" <<<
------------------------------------------------------------------------------
*****  Seneca Newnham Library  *****
Substring search
------------------------------------------------------------------------------
Row Book title                                       SKU     loan days penalty
--- ------------------------------------------------ ------- --------- -------
1   The Charterhouse of Parma                        112     2
------------------------------------------------------------------------------

```

## PART 1 Submission 

### Files to submit:  

```Text
Book.h
Book.cpp
Library.h
Library.cpp
WS3P1Tester.cpp
books.csv
```


Upload your source code and data file to your `matrix` account. Compile and run your code using the `g++` compiler as the execution sample above and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 

```text
~profname.proflastname/submit 2??/w#/pX
```

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


# DIY (50%) 

Under Construction.
