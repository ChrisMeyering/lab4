#include "LinkedScroll.h"
#include <iostream>
#include <string>

using namespace std;

void output(string last, bool wasEmpty, LinkedScroll<string> scroll, unsigned short int choice);
void showChoices();

int main()
{
  
  cout << "Instruction maintenance program\n\n";
  LinkedScroll<string> scroll;
  unsigned short int choice;
  do
  {
    showChoices();
    cin >> choice;
    string instruction;
    string last;
    bool wasEmpty = true;

    switch (choice)
    {
    case 1:
      cin.ignore(256,'\n');
      cout << "Enter instruction: ";
      getline (cin >> ws, instruction);
      scroll.enqueue(instruction);
      break;
    case 2:
      if(scroll.removeLast(last))
        wasEmpty = false;
      break;
    case 3:
      return 0;
    default:
      cout << "Invalid input\n";
      return 0;
    }
    output(last, wasEmpty, scroll, choice);
    cout << endl;
  } while (choice != 3);
}

void showChoices(){
    cout << "1) Enter instruction\n2) Undo last instruction\n3) Quit\n";
    cout << "Enter choice: ";
}


void output(string last, bool wasEmpty, LinkedScroll<string> scroll, unsigned short int choice)
{
  if (choice == 2 && wasEmpty)
    cout << "There are no instructions to undo\n";
  else
  {
    cout << "***Instructions***\n";
    if(scroll.isEmpty())
      cout << "***There are no instructions at this time***\n";
    else
    {
      LinkedScroll<string> temp = scroll;
      do
      {
        cout << temp.peekFront() << endl;
        temp.dequeue();
      } while (!temp.isEmpty() && (choice == 1 || choice == 2));
    }
    if (choice == 2)
      cout << "\n***Note***\n\"" << last << "\" has been removed from queue\n";
  }
}
