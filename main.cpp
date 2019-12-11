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
    TE str = new char[255];//поле данных
    mine* next;// адресное поле
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



    temp->next = NULL;
   /* temp->next = new mine;
    temp = temp->next;
    temp->str = NULL;*/
    cout << "End of " << i << " list" << endl;
    cout << endl;

    head = head->next;
  //  delete temp2;
    return head;
}    //declare elem end

int showLists(mine* head)
{
    //cout << "here" << endl;
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
        //cout << "JIOX    ";
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
       int m = 1;
       mine *temp = head;
       cout <<endl<< endl<< temp->str << endl << endl;
       while(temp != NULL)
       {
              cout <<endl<< endl<< temp->str << endl << endl;
              temp = temp->next;
              m++;
       }
       return m;
}

mine *add(mine *head, int m)
{
       mine *common = head;
       while(common->str != NULL)
       {
               common = common->next;
       }
       common->next = new mine;
       common = common->next;
       cin >> common->str;
       head = changeL(m+1, head);
       common->next = NULL;
       return head;
}



mine *DelC(mine *head)
{
       int m = ListQ(head);
       head = add(head, m);
       mine *common = head;
       TE a = common->str;
       while(common->str != NULL)
       {
               common = common->next;
               if(common->str == a)
               {
                       cout << "Found similar element" << endl;

                       return del_first(head);
               }
               else
               {
                      cout << "No similar elem found; list updated" << endl;
                      head = del_element_end(head);
                      return head;
               }
       }
    //   common->next = new mine
   //    common = common->next
  //     common->str = "elem2"
}


void write(mine* head)
{
    ofstream output ("list.txt");
   // _setmode (_fileno (output), _O_U8TEXT);
    for (mine* temp = head; temp->next != NULL; temp = temp->next)
    {
  //      output.write(temp->str, sizeof(mine));
        output << temp->str << setw(10);
    }
    output.close();
}

int main()
{
   /* TE s;
    cin >> s;
    cout << s;
*/
    int i = 1;
    char var;
    mine* head;
    head = declare(i);
    while (1 == 1)
    {
        cout << "Menu: "                   << endl
        << "-1 Show lists"                 << endl
        << "-2 Delete first element"       << endl
        << "-3 Delete second element"      << endl
        << "-4 Delete last element"        << endl
        << "-5 Delete the similar element" << endl
        << "-6 Write to file"              << endl
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
            case '0':
                return 0;
               break;
            default:
                cout << "Wrong value!" << endl;
                break;
        }
    }
    cout << "11";
    return 0;
    //system("pause");
}

