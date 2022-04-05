#include <iostream>
#include "time.h"

using namespace std;

int main()
{
    Time t1(58, 7, 4, 2), t2(1, 19, 8, 5), t3, t4(28, 7, 4, 2), t5(2, 19, 8, 5), t6(5, 5, 5, 5);
    Time t7(57, 15, 12, 5), t8(5, 51, 16, 2);

    Time t9(214748364, 214748364, 214748364, 214748364);

    cout << "T1 Time: " << t1 << endl;
    cout << "T2 Time: " << t2 << endl;
    cout << "T3 Time: " << t3 << endl;
    cout << "T4 Time: " << t4 << endl;
    cout << "T5 Time: " << t5 << endl;
    cout << "T6 Time: " << t6 << "\n\n";

    //testing comparision operators <, >, and ==.

    cout << t1 << " < " << t2 << " = " << (t1 < t2) << "        Should be False" << endl;
    cout << t5 << " < " << t4 << " = " << (t5 < t4) << "        Should be False" << endl;
    cout << t7 << " < " << t8 << " = " << (t7 < t8) << "        Should be False" << endl;
    cout << t4 << " < " << t5 << " = " << (t4 < t5) << "        Should be True" << endl;
    cout << t8 << " < " << t7 << " = " << (t8 < t7) << "        Should be True" << endl;
    cout << t5 << " < " << t7 << " = " << (t5 < t7) << "        Should be True" << endl;
    cout << t6 << " < " << t5 << " = " << (t6 < t5) << "        Should be True" << endl;

    cout << t1 << " > " << t2 << " = " << (t1 > t2) << "        Should be True" << endl;
    cout << t5 << " > " << t4 << " = " << (t5 > t4) << "        Should be True" << endl;
    cout << t2 << " > " << t1 << " = " << (t2 > t1) << "        Should be False" << endl;

    cout << t1 << " <= " << t2 << " = " << (t1 <= t2) << "        Should be False" << endl;
    cout << t2 << " <= " << t3 << " = " << (t2 <= t3) << "        Should be true" << endl;

    cout << t1 << " >= " << t2 << " = " << (t1 >= t2) << "        Should be true" << endl;
    cout << t2 << " >= " << t3 << " = " << (t2 >= t3) << "        Should be true" << endl;

    cout << t5 << " == " << t4 << " = " << (t5 == t4) << "       Should be false" << endl;
    cout << t2 << " == " << t3 << " = " << (t2 == t3) << "       Should be True" << endl;

    cout << t2 << " != " << t3 << " = " << (t2 != t3) << "       Should be false" << endl;
    cout << t1 << " != " << t3 << " = " << (t1 != t3) << "       Should be true" << endl;

    //tests multiplication of Time and int;
    cout << t1 << " * 2 = " << (t1 * 2) << endl;

    //tests addition and subtractions of Time and int
    cout << t4 << " + " << t5 << " = " << (t4 + t5) << "  This value should be 7~12:26:30" << endl;
    cout << t4 << " - " << t5 << " = " << (t4 - t5) << "  This value should be 0~00:00:00" << endl;
    cout << t8 << " - " << t7 << " = " << (t8 - t7) << "  This value should be 0~00:00:00" << endl;
    cout << t7 << " - " << t8 << " = " << (t7 - t8) << "  This value should be 2~19:24:52" << endl;
    cout << t7 << " + " << t8 << " = " << (t7 + t8) << "  This value should be 8~05:07:02" << endl;

    // Test of ++ and -- overloads
    cout << "T6 Time: " << t6 << endl;
    cout << "T6++: " << t6++ << endl;
    cout << "T6--: " << t6-- << endl;
    cout << "++T6: " << ++t6 << endl;
    cout << "--T6: " << --t6 << endl;
    cout << "T6++ is now: " << t6 << endl;

    //Test of conversion constructor
    t6 = 1234;
    cout << "T6 should now be 0~00:20:34: " << t6 << endl;

    //tests input and data checking functionality of non member function
    // cout << "enter 3~15:61:06: ";
    // cin >> t3;
    // cout << "you entered: " << t3 << endl;

    cout << "\n bounds test on t9: " << t9 << endl;

    t9 = -1;
    cout << "\n t9 should now be default due to negative: " << t9 << endl;

    t9 = t6;
    cout << "\n t9 should now be equal to t6: " << t9 << endl;

    t9 = 4321;
    cout << "\n t9 = 0~1:12:01   " << t9 << endl;

    cout << "t1: " << t1 << endl;
    cout << "t2: " << t2 << endl;

    cout << "t1: " << t1 << "   t1++: " << t1++ << endl;
    cout << "t1: " << t1 << "   ++t1: " << ++t1 << endl;

    cout << "t2: " << t2 << "   t2--: " << t2-- << endl;
    cout << "t2: " << t2 << "   --t2: " << --t2 << endl;

    return 0;
}
