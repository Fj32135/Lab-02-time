#include <iostream>


class Time {
public:
    Time(int hours,int minutes, int seconds) {
        seconds_ = seconds;
        minutes_ = minutes;
        hours_ = hours;
    }
    Time(int seconds) {
        seconds_ = seconds;
    }
    Time();
friend  std::ostream &operator<<(std::ostream &str, Time &a){
    int indicatorh, indicatorm, seconds;
    indicatorh = a.seconds_/3600;
    indicatorm = a.seconds_/60;
    seconds = a.seconds_ - indicatorh*3600 - indicatorm*60;

    if(a.minutes_ != 0 & a.seconds_ != 0)
    std::cout << a.hours_ << "h:" << a.minutes_ << "m:" << a.seconds_ << "s" << std::endl;
    else
        std::cout << indicatorh << "h:" << indicatorm << "m:" << seconds << std::endl;
    return str;
    }
friend  std::ostream &operator>>(std::ostream &str, Time &a){
    std::cout << "Please enter the number of hours" << std::endl;
    std::cin >> a.hours_;
    std::cout << "Please enter the number of minutes" << std::endl;
    std::cin >> a.minutes_;
    std::cout << "Please enter the number of seconds" << std::endl;
    std::cin >> a.seconds_;
    return str;
 }
    Time operator+(Time a){
    int leftseconds, rightseconds, seconds;
    leftseconds = hours_*3600 + minutes_*60 + seconds_;
    rightseconds = a.hours_*3600 + a.minutes_*60 + a.seconds_;
    seconds = leftseconds + rightseconds;
    int indicatorh, indicatorm, seconds1;
    indicatorh = seconds/3600;
    indicatorm = seconds/60;
    seconds1 = seconds - indicatorh*3600 - indicatorm*60;
    return Time(indicatorh,indicatorm,seconds1);
}

private:
    int seconds_;
    int minutes_;
    int hours_;
};
int main()
{
    Time s(2,3,5);
    Time b(1,2,30);
    Time a;
    std::cout << s << std::endl;
    std::cout << b << std::endl;
    //std::cin >> a; // For some reason this implementation doesn't work
    //Time t3 = s + b; // I don't understand why wouldn't this work either
    //std::cout << t3 << std::endl;
    return 0;
}
