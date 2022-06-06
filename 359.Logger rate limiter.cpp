#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Logger {
public:
    map<string, int> Table;
    map<string, int>::iterator it ;
    int time_to_hold = 0;
    Logger() {

    }
    bool shouldPrintMessage(int timestamp, string message) {   
        // Define iterator
        it = Table.find(message);
        if(it == Table.end())
        {
            time_to_hold = timestamp + 10;
            Table.insert(pair<string, int>(message, time_to_hold));
            return true;
        }
        else
        {
            if (timestamp >= it->second)
            {
                it->second = timestamp + 10;
                return true;
            }
            else 
                return false;
        }
    }
};
// Way to call this function -> CLear with Ankit
// int main(int argc, char const *argv[])
// {
//     Logger* obj = new Logger();
//     auto input = {(1, "foo"), (2, "bar"),(3, "foo"), (8, "bar"), (10, "foo"), (11, "foo")};
//     bool param_1 = obj->shouldPrintMessage(input,input);
//     #cout << "Minimum Rooms required = " << result<<" ";
//     return 0;
// }