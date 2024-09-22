#include <iostream>
#include "BookingSystem.h"
#include <boost/program_options.hpp>

using namespace std;

int main() {
    BookingSystem bookingSystem;
    bookingSystem.processCommands();
    return 0;
}