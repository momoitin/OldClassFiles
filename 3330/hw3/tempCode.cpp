//Time calculator as non member that accepts time variable
Time timeCalculator(Time t)
{
    //find the total number of seconds in the hours, minutes, and seconds
    double totalSeconds = ((t.hours * 60 * 60) + (t.minutes * 60) + t.seconds);
    //set everything other than days to zero, as days are already the highest they can be
    //  since this is the value we are returning
    t.hours = 0;
    t.minutes = 0;
    t.seconds = 0;
    // cout << "Total Seconds: " << totalSeconds << endl;
    while (totalSeconds > 0)
    {
        //each loop adds 1 to the seconds counter
        t.seconds++;
        //if there are 60 seconds, then increase minutes by one and reset seconds
        if (t.seconds == 60)
        {
            t.minutes++;
            t.seconds = 0;
        }
        //if there are 60 minutes, then increase hours by one and reset minutes
        if (t.minutes == 60)
        {
            t.hours++;
            t.minutes = 0;
        }
        //if there are 60 minutes, then increase days by one and reset hours
        if (t.hours == 24)
        {
            t.days++;
            t.hours = 0;
        }
        //deincrement untill there are no more seconds to add
        totalSeconds--;
    }
    return t;
}


//Time calculator as non member that accepts time variable
Time timeCalculator(Time t)
{
    while (t.seconds >= 60)
    {
        t.minutes++;
        t.seconds -=60;
    }
    
    while (t.minutes >= 60)
    {
        t.hours++;
        t.minutes -= 60;
    }
    while (t.hours >= 24)
    {
        t.days++;
        t.hours -= 24;
    }

    return t;
}


//Time calculator as non member that accepts time variable
Time timeCalculator(Time t)
{
    //checks to make sure no value is above bounds
    while (t.seconds > 60)
    {
        t.minutes++;
        t.seconds -= 60;
    }
    while (t.minutes > 60)
    {
        t.hours++;
        t.minutes -= 60;
    }
    while (t.hours > 24)
    {
        t.days++;
        t.hours -= 24;
    }
    //checks if any values are negative
    while (t.hours < 0)
    {
        t.days--;
        t.hours += 24;
    }
    while (t.minutes < 0)
    {
        t.hours--;
        t.minutes += 60;
    }
    while (t.seconds < 0)
    {
        t.minutes--;
        t.seconds += 60;
    }
    //if any values are still negative, zero out the variable
    if (t.days < 0 || t.hours < 0 || t.minutes < 0 || t.seconds < 0)
    {
        return t = 0;
    }

    return t;
}

bool operator<(const Time &t1, const Time &t2)
{ //As long as each variable is not equal, compares which one if smaller.
    //returns 0 if t1 is larger, returns 1 if t2 is larger.
    if (t1.days != t2.days)
    {
        // cout << t1.days << " < " << t2.days << " = " << (t1.days < t2.days) << " ";
        return (t1.days < t2.days);
    }

    if (t1.hours != t2.hours)
    {
        // cout << t1.hours << " < " << t2.hours << " = " << (t1.hours < t2.hours) << " ";
        return (t1.hours < t2.hours);
    }

    if (t1.minutes != t2.minutes)
    {
        // cout << t1.minutes << " < " << t2.minutes << " = " << (t1.minutes < t2.minutes) << " ";
        return (t1.minutes < t2.minutes);
    }

    if (t1.seconds != t2.seconds)
    {
        // cout << t1.seconds << " < " << t2.seconds << " = " << (t1.seconds < t2.seconds) << " ";
        return (t1.seconds < t2.seconds);
    }

    return false;
}