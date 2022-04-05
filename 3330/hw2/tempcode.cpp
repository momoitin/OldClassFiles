int Date::Compare(const Date &d) const
{
    if (year == d.year)
    {
        if (month == d.month)
        {
            if (day == d.day)
            {
                return 0;
            }
            else if (day < d.day)
            {
                return -1;
            }
            else if (day > d.day)
            {
                return 1;
            }
        }
        else if (month < d.month)
        {
            return -1;
        }
        else if (month > d.month)
        {
            return 1;
        }
    }
    else if (year < d.year)
    {
        return -1;
    }
    else if (year > d.year)
    {
        return 1;
    }

    return 0;
}


void Date::Show() const
{
    if (format == 'D')
    {
        cout << month << "/" << day << "/" << year << endl;
    }

    if (format == 'T')
    {
        if (month < 10)
        {
            cout << '0' << month << "/";
        }
        else
        {
            cout << month << "/";
        }
        if (day < 10)
        {
            cout << '0' << day << "/";
        }
        else
        {
            cout << day << "/";
        }
        cout << year % 100 << endl;
    }

    if (format == 'L')
    {
        cout << monthName[month - 1] << " " << day << ", " << year << endl;
    }
}