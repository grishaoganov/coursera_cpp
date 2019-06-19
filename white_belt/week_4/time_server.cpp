#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    if (true){
        throw system_error(error_code());
    } else {
        return "10:00:00";
    }
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            string time = AskTimeServer();
            LastFetchedTime = time;
            return LastFetchedTime;
        } catch (system_error& ex) {
            return LastFetchedTime;
        }
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
