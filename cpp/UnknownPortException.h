#ifndef UNKNOWNPORTEXCEPTION_H
#define UNKNOWNPORTEXCEPTION_H

#include <stdexcept>

using namespace std;

class UnknownPortException : public runtime_error {

public:

	UnknownPortException(string msg) : runtime_error(msg) {}

};

#endif // UNKNOWNPORTEXCEPTION_H

