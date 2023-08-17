
#include <iostream>
#include <fstream>
using namespace std;

// This class will take the string and count words.
class Wordcount
{
protected:
  static int words;
  int ch = 0;

public:
  void wordCount(string st)
  {
    for (int i = 0; st[i] != '\0'; i++)
    {
      if (st[i] != ' ')
      {
        ch++;
      }
      else
      {
        if (ch > 0)
        {
          words++;
          ch = 0;
        }
      }
    }
    if (ch != 0)
    {
      words++;
    }
  }

  void display()
  {
    cout << "Total number of words in this file is: " << words << endl;
  }
};

int Wordcount::words = 0;

// This class will input the file from user
class inputFile : public Wordcount
{
protected:
  string st;
  string fName;

public:
  inputFile()
  {
    cout << "Enter Your File Name: ";
    cin >> fName;
    ifstream myFile(fName);
    while (myFile.eof() == 0)
    {
      getline(myFile, st);
      wordCount(st);
    }
    display();
  }
};

int main()
{

  string fName, st;
  Wordcount w1;
  cout << "\n**WORDS COUNTING PROGRAM**\n"<< endl;
  inputFile f1;
}