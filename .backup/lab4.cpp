#include "LinkedScroll.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

static void scrollCopyTest()
{
  LinkedScroll<int> scroll;
  scroll.enqueue(1);
  assert(scroll.peekFront() == 1);
  scroll.enqueue(3);
  assert(scroll.peekFront() == 1);
  LinkedScroll<int> s2 = scroll;
  assert(s2.peekFront() == 1);
  s2.dequeue();
  assert(s2.peekFront() == 3);

}



void showChoices();

int main()
{
  scrollCopyTest();
  cout << "Instruction maintenance program\n\n";
  LinkedScroll<string> scroll;
  unsigned short int choice;
  do
  {
    showChoices();
    cin >> choice;
    string instruction;
    string last;
    switch (choice)
    {
    case 1:
      cout << "Enter instruction: ";
      cin >> instruction;
      scroll.enqueue(instruction);
      break;
    case 2:
      scroll.removeLast(last);
      break;
    case 3:
      break;
    default:
      cout << "Invalid input\n";
    }
    LinkedScroll<string> temp = scroll;
    do
    {
      temp.removeLast(last);
      cout << last << endl;
    } while (!temp.isEmpty() && (choice == 1 || choice == 2));
  } while (choice != 3);
}

void showChoices(){
    cout << "1) Enter instruction\n2) Undo last instruction\n3) Quit\n";
    cout << "Enter choice: ";
}
