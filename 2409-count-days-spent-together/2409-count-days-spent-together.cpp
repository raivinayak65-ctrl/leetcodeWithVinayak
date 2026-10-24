class Solution {
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int getDayOfYear(const string& date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = 0;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonth[i];
        }
        return totalDays + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Find the overlapping interval [startDate, endDate]
        string startDate = max(arriveAlice, arriveBob);
        string endDate = min(leaveAlice, leaveBob);
        
        // If the start of the overlap is after the end, they don't overlap
        if (startDate > endDate) {
            return 0;
        }
        
        return getDayOfYear(endDate) - getDayOfYear(startDate) + 1;
    }
};