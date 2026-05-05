#include <iostream>
#include <string>
using namespace std;

/*
---------------------------------------
1. CHARACTER → ASCII
---------------------------------------
- Every character has a numeric ASCII value
Example:
'A' → 65
'a' → 97
*/
void charToASCII()
{
  char ch;
  cout << "Enter a character: ";
  cin >> ch;

  cout << "ASCII value = " << int(ch) << endl;
}

/*
---------------------------------------
2. ASCII → CHARACTER
---------------------------------------
- Convert number back to character
Example:
65 → 'A'
*/
void ASCIIToCharacter()
{
  int num;
  cout << "Enter ASCII value: ";
  cin >> num;

  cout << "Character = " << char(num) << endl;
}

/*
---------------------------------------
3. CHARACTER TYPE CHECK
---------------------------------------
We check ranges:
A–Z → Uppercase
a–z → Lowercase
0–9 → Digit
Else → Special character
*/
void checkCharacterType()
{
  char ch;
  cout << "Enter a character: ";
  cin >> ch;

  if (ch >= 'A' && ch <= 'Z')
  {
    cout << "Uppercase\n";
  }
  else if (ch >= 'a' && ch <= 'z')
  {
    cout << "Lowercase\n";
  }
  else if (ch >= '0' && ch <= '9')
  {
    cout << "Digit\n";
  }
  else
  {
    cout << "Special Character\n";
  }
}

/*
---------------------------------------
4. CONVERT TO LOWERCASE
---------------------------------------
Logic:
'A' → 'a' difference = 32
*/
void convertToLowercase()
{
  char ch;
  cout << "Enter a character: ";
  cin >> ch;

  if (ch >= 'A' && ch <= 'Z')
  {
    ch = ch + 32;
  }

  cout << "Lowercase: " << ch << endl;
}

/*
---------------------------------------
5. BROTHERS PROBLEM
---------------------------------------
- If last names are same → YES
*/
void brothers()
{
  string first1, last1;
  string first2, last2;

  cout << "Enter first person name: ";
  cin >> first1 >> last1;

  cout << "Enter second person name: ";
  cin >> first2 >> last2;

  if (last1 == last2)
  {
    cout << "YES (They are brothers)\n";
  }
  else
  {
    cout << "NO\n";
  }
}

/*
---------------------------------------
6. LEXICOGRAPHICAL COMPARISON
---------------------------------------
- Compare like dictionary order
*/
void lexicographicalOrder()
{
  string A, B;
  cout << "Enter two strings:\n";
  cin >> A >> B;

  int n = min(A.size(), B.size());

  for (int i = 0; i < n; i++)
  {
    if (A[i] < B[i])
    {
      cout << "A comes first\n";
      return;
    }
    else if (A[i] > B[i])
    {
      cout << "B comes first\n";
      return;
    }
  }

  // If all characters same till min length
  if (A.size() < B.size())
  {
    cout << "A comes first\n";
  }
  else if (A.size() > B.size())
  {
    cout << "B comes first\n";
  }
  else
  {
    cout << "Both are equal\n";
  }
}

/*
---------------------------------------
7. REPLACE CHARACTER
---------------------------------------
Replace all occurrences of c1 with c2
*/
void replaceCharacter()
{
  string s;
  char c1, c2;

  cout << "Enter string: ";
  cin >> s;

  cout << "Enter character to replace and new character: ";
  cin >> c1 >> c2;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == c1)
    {
      s[i] = c2;
    }
  }

  cout << "Result: " << s << endl;
}

/*
---------------------------------------
8. REMOVE CHARACTER
---------------------------------------
Remove all occurrences of a character
*/
void removeCharacter()
{
  string s;
  char x;

  cout << "Enter string: ";
  cin >> s;

  cout << "Enter character to remove: ";
  cin >> x;

  string result = "";

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != x)
    {
      result += s[i];
    }
  }

  cout << "Result: " << result << endl;
}

/*
---------------------------------------
9. REMOVE SPACES FROM STRING
---------------------------------------
*/
void removeSpaces()
{
  cin.ignore(); // important when using getline after cin

  string s;
  cout << "Enter a sentence: ";
  getline(cin, s);

  string result = "";

  for (char ch : s)
  {
    if (ch != ' ')
    {
      result += ch;
    }
  }

  cout << "Without spaces: " << result << endl;
}

/*
---------------------------------------
10. TOGGLE CASE
---------------------------------------
Upper → Lower
Lower → Upper
*/
void toggleCase()
{
  string s;
  cout << "Enter string: ";
  cin >> s;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z')
    {
      s[i] += 32;
    }
    else if (s[i] >= 'a' && s[i] <= 'z')
    {
      s[i] -= 32;
    }
  }

  cout << "Toggled: " << s << endl;
}

/*
---------------------------------------
11. STRONG PASSWORD CHECK
---------------------------------------
Conditions:
- Length = 10
- Has lowercase, uppercase, digit, special char
*/
void strongPassword()
{
  string s;
  cout << "Enter password: ";
  cin >> s;

  if (s.length() != 10)
  {
    cout << "Weak\n";
    return;
  }

  bool hasLower = false, hasUpper = false;
  bool hasDigit = false, hasSpecial = false;

  for (char ch : s)
  {
    if (islower(ch))
      hasLower = true;
    else if (isupper(ch))
      hasUpper = true;
    else if (isdigit(ch))
      hasDigit = true;
    else
      hasSpecial = true;
  }

  if (hasLower && hasUpper && hasDigit && hasSpecial)
  {
    cout << "Strong\n";
  }
  else
  {
    cout << "Weak\n";
  }
}

/*
---------------------------------------
12. REVERSE STRING
---------------------------------------
*/
void reverseString()
{
  string s;
  cout << "Enter string: ";
  cin >> s;

  string result = "";

  for (int i = s.size() - 1; i >= 0; i--)
  {
    result += s[i];
  }

  cout << "Reversed: " << result << endl;
}

/*
---------------------------------------
13. PALINDROME CHECK
---------------------------------------
Same forward and backward
*/
void palindrome()
{
  string s;
  cout << "Enter string: ";
  cin >> s;

  string reversed = "";

  for (int i = s.size() - 1; i >= 0; i--)
  {
    reversed += s[i];
  }

  if (s == reversed)
  {
    cout << "YES (Palindrome)\n";
  }
  else
  {
    cout << "NO\n";
  }
}

/*
---------------------------------------
14. COUNT WORDS
---------------------------------------
- Count transitions from space → character
*/
void countWords()
{
  cin.ignore();

  string s;
  cout << "Enter sentence: ";
  getline(cin, s);

  int count = 0;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
    {
      count++;
    }
  }

  cout << "Word count = " << count << endl;
}

/*
---------------------------------------
MAIN FUNCTION
---------------------------------------
*/
int main()
{

  // charToASCII();

  // ASCIIToCharacter();

  // checkCharacterType();

  // convertToLowercase();

  // brothers();

  // lexicographicalOrder();

  // replaceCharacter();

  // removeCharacter();

  // removeSpaces();

  // toggleCase();

  // strongPassword();

  // reverseString();

  // palindrome();

  countWords();

  return 0;
}