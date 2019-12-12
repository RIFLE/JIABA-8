#include "module.h"
int main()
{
    char var = '1';
    mine* head;
    head = declare();
    int m = NULL;
    while (var != 0)
    {
        cout << "Menu: "                   << endl
        << "-1 Show lists"                 << endl
        << "-2 Delete first element"       << endl
        << "-3 Delete second element"      << endl
        << "-4 Delete last element"        << endl
        << "-5 Delete the similar element" << endl
        << "-6 Write to file"              << endl
        << "-7 Add an element *front lst*" << endl
        << "-8 Add an element *back lst*"  << endl
        << "-0 EXIT"                       << endl << endl;
        cin >> var;
        switch (var)
        {
            case '1':
                showLists(head);
                break;
            case '2':
                m = ListQ(head);
                head = del_first(head, m);
                break;
            case '3':
                m = ListQ(head);
                head = del_second(head, m);
                break;
            case '4':
                m = ListQ(head);
                head = del_element_end(head, m);
                break;
            case '5':
                head = DelC(head);
                break;
            case '6':
                write(head);
                break;
            case '7':
                m = ListQ(head);
                head = addF(head, m);
                break;
            case '8':
                m = ListQ(head);
                head = addB(head, m);
                break;
            case '9':
                m = CheckL(head);
                cout << m << endl << endl;
                break;
            case '0':
                var = 0;
               break;
            default:
                cout << "Wrong value!" << endl << endl;
                break;
        }
    }
    cout << "END";
    return 0;
}


