#include "LinkedScroll.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  LinkedScroll<string>* test = new LinkedScroll<string>();
  cout << "Enqueue \"WHAT\"\n";
  test->enqueue("WHAT");
  cout << "Front: " << test->peekFront() << endl;
  cout << "Enqueue \"DeleteThis\"\n";
  test->enqueue("DeleteThis");
  cout << "Front: " << test->peekFront() << endl;

  string last;
  test->removeLast(last);
  cout << "remove: " << last << endl;
  cout << "Front: " << test->peekFront() << endl;
  test->removeLast(last);
  cout << "remove " << last << endl;
  test->removeLast(last);
  delete test;
}  
