#include <iostream>
#include <fstream>
 
using namespace std;
 
#define LOG_WARNING 4
void syslog (int facility_priority, const char *format, ...);
 
void path_manipulation() {
    char path[100];
    ifstream f;
    string buff;
    cout << "Starting path manipulation test." << endl;
    cout << "Enter a path.\n";
    cin >> path; // Is path now tainted?  Not sure.  Below test indicates that it probably isn't
 
               /* Start added as an unkown source / known sink test */
    char error_msg[256];
    sprintf(error_msg, "Illegal request: %s", path);
    syslog(LOG_WARNING, error_msg);
               /* End added as an unkown source / known sink test */
 
    f.open(path);  // Here is where the customer wants us to find a defect.  Tried modeling this.
    f >> buff;
    cout << buff << endl;
    f.close();
    cout << "Leaving path manipulation test." << endl << endl;
}
 
