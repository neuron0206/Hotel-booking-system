#include <string>
#include <vector>

using namespace std;

class BookingSystem {
public:
    void processCommands();

private:
    void newHotel(const string& name, int capacity, int maxGuests, int costPerPerson);
};