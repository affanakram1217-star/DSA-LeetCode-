class Solution {
public:
    int dayOfYear(const string& dates){
        vector<int> DaysInEveryMonth={31,28,31,30,31,30,31,31,30,31,30,31};
        int month=stoi(dates.substr(0,2));
        int date=stoi(dates.substr(3,2));

        int totalDays = date;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += DaysInEveryMonth[i];
        }
        return totalDays;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int Alice_Arrive=dayOfYear(arriveAlice);
        int Alice_leave=dayOfYear(leaveAlice);
        int Bob_Arrive=dayOfYear(arriveBob);
        int Bob_leave=dayOfYear(leaveBob);

        int OverlapArrive=max(Alice_Arrive,Bob_Arrive);
        int OverlapLeave=min(Alice_leave,Bob_leave);

        return max(0,OverlapLeave-OverlapArrive+1);
    }
};