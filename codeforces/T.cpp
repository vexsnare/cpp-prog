#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

/*

// quota = 10
// timeInterval = 60 seconds

boolean rateLimit(int organizationId) {
    if ratelimit
        true
    else
        false
}

// timeInterval = 60 seconds
// creditsPerInterval = 10
// maxCredits = 100
boolean rateLimit(int organizationId) {
    if haveEnoughCredits
        true
    else
        false
}

10 [ interval ] 20 [ interval ] 30 [ interval ] 40 ... [ interval ] 100 [ interval ] 100
10 [ interval ] 20 [ interval, 5 requests, 5 allowed ] 25
10 [ interval, 90 requests, 10 allowed ] 10 [ interval, 5 requests, 5 allowed ] 15
10 [2 req, 8] 10 + 8[] 28

*/

// Request :{
//     timestamp,
//     typeOfRequest
// }

int quota = 3;
int timeinterval = 60;
map<string, queue<int> > allowedRequestsTimestampOrgMap;
bool isAllowed(string organizationId, int timestamp) {
    if(allowedRequestsTimestampOrgMap.find(organizationId) == allowedRequestsTimestampOrgMap.end()) {
        queue<int> dq;
        dq.push(timestamp);
        allowedRequestsTimestampOrgMap[organizationId] =  dq;
        return true;
    } else {
        queue<int> &allowedRequestsTimestamp = allowedRequestsTimestampOrgMap[organizationId];
        int sz = allowedRequestsTimestamp.size();
        if(allowedRequestsTimestamp.size() < quota) {
            allowedRequestsTimestamp.push(timestamp);
            return true;
        } else {
            int currentTimeStamp = timestamp;
            while(allowedRequestsTimestamp.size() > 0 && currentTimeStamp - allowedRequestsTimestamp.front() > timeinterval) {
                allowedRequestsTimestamp.pop();
            }
            if(allowedRequestsTimestamp.size() < quota) {
                allowedRequestsTimestamp.push(timestamp);
                return true;
            }
            return false;
        }
    }
}

int main() {
    // cin >> quota;
//    cin >> timeinterval;
    cout << isAllowed("1", 10) << "\n";
    cout << isAllowed("1", 20) << "\n";
    cout << isAllowed("1", 30) << "\n";
    cout << isAllowed("1", 30) << "\n";
    cout << isAllowed("1", 30) << "\n";
    cout << isAllowed("1", 30) << "\n";
    cout << isAllowed("1", 100) << "\n";
    cout << isAllowed("1", 130) << "\n";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
