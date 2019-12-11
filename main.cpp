#include <iostream>
#include <fstream>
//#include <fcntl.h>
//#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
// check
typedef char* TE;

struct mine
{
    TE str = new char[255]; //data field
    mine* next;             //address field
};

mine* declare(int& i)
{
/*
    mine* head = new mine;


    cout << "Please, fill your " << i << " list: \n";
    cin >> head->str;
    mine* temp = head;


    while (true)
    {
        char var;
        cout << "Do you want to add some new elements? Please, type ""y"":" << endl;
        cin >> var;
        if (var == 'y' || var == 'Y')
        {
            i++;
            temp->next = new mine;
            temp = temp->next;
            cout << "Enter your elements: ";
            cin >> temp->str;
        }
        else
        {
            break;
        }
    }*/

            mine *head = new mine;
            mine *temp = head;

            mine *temp2 = head;

            temp->next = new mine;
            temp = temp->next;
            temp->str  = "elem1";

            temp->next = new mine;
            temp = temp->next;
            temp->str  = "elem2";

            temp->next = new mine;
            temp = temp->next;
            temp->str  = "elem3";

            temp->next = new mine;
            temp = temp->next;
            temp->str  = "elem4";

            temp->next = new mine;
            temp = temp->next;
            temp->str = "elem5";

            temp->next = new mine;
            temp = temp->next;
            temp->str = "elem6";

            temp->next = new mine;
            temp = temp->next;
            temp->str = "elem7";

            temp->next = new mine;
            temp = temp->next;
            temp->str = "elem8";

            temp->next = new mine;
            temp = temp->next;
            temp->str = "elem9";

    cout << "End of " << i << " list" << endl;
    cout << endl;

    head = head->next;
    return head;
}

int showLists(mine* head)
{
    int i = 0;
    cout << endl << "   ";
    for (mine* temp = head; temp != NULL; temp = temp->next)
    {
        i++;
        cout << temp->str;
        cout << setw(8);
        if(i%3 == 0)
        {
            cout << endl << endl;
        }
    }
    cout << endl << endl;
    return 0;
}

 mine *changeL(int m, mine *head)
 {
    mine *far = head;
    for(int i=0; i<m-2; i++)
    {
        far = far->next; //last
    }
    TE a = far->str;
    mine *close = head;
    for(int i=0; i<m-3; i++)
    {
        close = close->next; //last - 1
    }
    TE b = close->str;
    far->str = b;
    close->str = a;
    if (m > 0)
    {
        head = changeL(m-1, head);
    }
    else
        return head;
 }

mine *del_element_end(mine* head)
{
    mine *temp = head;
    mine *tempL = head; //last elem p

    int i = 1;
    while (tempL->next)
    {
        tempL = tempL->next; //last elem
        i++;
    }
    tempL->str = temp->str;
    head = head->next;
    delete temp;
    mine *tempx = head;
    head = changeL(i, head);
    return head;
}

mine* del_first(mine *head)
{
    mine *temp = head;
    head = head->next;
    delete temp;
    return head;
}

mine *del_second(mine* head)
{
    mine* temp = head;
    mine* temp2 = head->next;
    temp2->str = temp->str;

    head = head->next;
    delete temp;
    return head;
}

int ListQ(mine *head)
{
    int m = 0;
    mine *temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        m++;
    }
    return m;
}

mine *addF(mine *head, int m)
{
    int i = 1;
    mine *common = head;
    for (mine* temp = head; temp->next != NULL; temp = temp->next)
    {
        common = common->next;
        i++;
    }
    common->next = new mine;
    cout << endl << "Please, enter 1 element *front add*" << endl << endl;
    cin >> common->next->str;
    common->next->next = new mine;
    common->next->next = NULL;
    head = changeL(m+2, head);
    return head;
}

mine *addB(mine *head, int m)
{
    int i = 1;
    mine *common = head;
    for (mine* temp = head; temp->next != NULL; temp = temp->next)
    {
        common = common->next;
        i++;
    }
    common->next = new mine;
    cout << endl << "Please, enter 1 element *back add*" << endl << endl;
    cin >> common->next->str;
    common->next->next = new mine;
    common->next->next = NULL;
    return head;
}

mine *DelC(mine *head)
{
       int m = ListQ(head);
       //cout << m << endl << endl;
       //showLists(head);
       head = addF(head, m);
       showLists(head);
        //cout << m << endl;  m == 9;
       mine *common = head;
       cout << "a is: ";
       //cout << endl <<common->next->next->str << endl;
       TE a = head->str;
       //cout << "a is: "; //<< a;
       while(common->next->str != NULL)
       {
               //common = common->next;
               if(common->next->str == a)
               {
                       cout << "Found similar element" << endl;

                       return del_first(head);
               }
               common = common->next;
        }
                      cout << "No similar elem found; list updated" << endl;
                      head = del_element_end(head);
                      return head;




    //   common->next = new mine
   //    common = common->next
  //     common->str = "elem2"
}


void write(mine* head)
{
    ofstream output ("list.txt");
    for (mine* temp = head; temp != NULL; temp = temp->next)
    {
        output << temp->str << setw(10);
    }
    output.close();
}

int main()
{
    int i = 1;
    char var = '1';
    mine* head;
    head = declare(i);
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
        << "-0 EXIT"                       << endl;
        cin >> var;
        switch (var)
        {
            case '1':
                showLists(head);
                break;
            case '2':
                head = del_first(head);
                break;
            case '3':
                head = del_second(head);
                break;
            case '4':
                head = del_element_end(head);
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
            case '0':
                var = 0;
               break;
            default:
                cout << "Wrong value!" << endl;
                break;
        }
    }
    cout << "END";
    return 0;
    //system("pause");
}

