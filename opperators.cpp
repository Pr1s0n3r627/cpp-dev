#include <iostream>

using namespace std;

class Time {
public:
int hr, min, sec;

public:
Time(int h, int m, int s) : hr(h), min(m), sec(s) {}

friend Time operator--(Time& t) {
if (t.sec > 0) {
t.sec--;
} else {
if (t.min > 0) {
t.min--;
t.sec = 59;
} else {
if (t.hr > 0) {
t.hr--;
t.min = 59;
t.sec = 59;
}
}
}
return t;
}

friend Time operator--(Time& t, int) {
Time temp = t;
--t;
return temp;
}

friend ostream& operator<<(ostream& os, const Time& t) {
os << t.hr << ":" << t.min << ":" << t.sec;
return os;
}
};

int main() {
int h, m, s;
cin >> h >> m >> s;

Time t(h, m, s);

cout << "Output of Pre-decrement Operator" << endl;
--t;
cout << t << endl;
cout << t << endl;

cout << "Output of Post-decrement Operator" << endl;
t--;
cout << t << endl;
t.sec += 1;
cout << t << endl;

return 0;
}