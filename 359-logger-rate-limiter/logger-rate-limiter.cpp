class Logger {
public:
    
    /* My Approach.

    unordered_map<string, int> hash;

    Logger() {

    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (hash.find(message) == hash.end()) {
            hash.insert({message, timestamp + 10});
        } else {
            int cur = hash[message];

            if(timestamp < cur) {
                return false;
            } else {
                hash[message] = timestamp + 10;          // initially missed to add 10 here.
                return true;
            }
        }

        return true;
    }

    */

    /* From Solution */

    unordered_map<string, int> mp;
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(message) == mp.end() || timestamp - mp[message] >= 10){
            mp[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */