class Logger {
public:
    
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
                hash[message] = timestamp + 10;
                return true;
            }
        }

        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */