#ifndef PRECOND_VIOLATED_EXCEP_H
#define PRECOND_VIOLATED_EXCEP_H

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep: public logic_error
{
public:
  PrecondViolatedExcep(const string& message = "");
};

#endif

PrecondViolatedExcep::PrecondViolatedExcep(const string& message):
  logic_error("Precondition Violated Exception: " + message){}
