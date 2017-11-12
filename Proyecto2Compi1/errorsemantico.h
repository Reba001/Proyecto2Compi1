#ifndef ERRORSEMANTICO_H
#define ERRORSEMANTICO_H
#include "qstring.h"
#include "variables.h"

class ErrorSemantico
{
public:
    ErrorSemantico();
    ErrorSemantico(Variables var);
private:
    Variables var;
};

#endif // ERRORSEMANTICO_H
