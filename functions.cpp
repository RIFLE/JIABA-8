#include "module.h"

mine* declare()
{
    mine* head = new mine;
    cout << "Please, fill your list: \n";
    cin >> head->str;
    mine* temp = head;
    while (true)
    {
        char var;
        cout << "Do you want to add some new elements? Please, type ""y"":" << endl;
        cin >> var;
        if (var == 'y' || var == 'Y')
        {
            temp->next = new mine;
            temp = temp->next;
            cout << "Enter your elements: ";
            cin >> temp->str;
        }
        else
        {
            break;
        }
    }
        /*  mine *head = new mine;
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
            temp->str = "elem9";   */

    cout << "End of list." << endl;
    cout << endl;
    head = head->next;
    return head;
}

int showLists(mine* head)
{
    int i = 0;
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

int CheckL(mine *head)
{
    if(head != NULL)
    {
        if(head->next != NULL)
        {
            return 2;
        }
        return 1;
    }
    else
    {
        return 0;
    }
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

mine *del_element_end(mine* head, int m)
{
    if(m <= 1)
    {
        if(m == 0)
        {
            cout << "No elements left." << endl << endl;
            return head;
        }
        cout << "One element left." << endl << endl;
        return head;
    }
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

mine* del_first(mine *head, int m)
{
    if(m == 0)
    {
        cout << "No elements left." << endl << endl;
        return head;
    }
    mine *temp = head;
    head = head->next;
    delete temp;
    return head;
}

mine *del_second(mine* head, int m)
{
    if(m <= 1)
    {
        if(m == 0)
        {
            cout << "No elements left." << endl << endl;
            return head;
        }
        cout << "One element left." << endl << endl;
        return head;
    }
    mine* temp = head;
    mine* temp2 = head->next;
    temp2->str = temp->str;

    head = head->next;
    delete temp;
    return head;
}

int ListQ(mine *head)
{
    int m = CheckL(head), n=0;
    if(m<=1)
        return m;
    mine *temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        n++;
    }   //showLists(head);

    cout << m;
    return n;
}

mine *addF(mine *head, int m)
{
    int i = 1;
    if(m == 0)
    {
        head = new mine;
    }
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
    if(m == 0)
    {
        m = 1;
        return del_first(head, m);
    }
    return head;
}

mine *addB(mine *head, int m)
{
    int i = 1;
    if(m == 0)
    {
        head = new mine;
    }
    mine *common = head;
    if(common == NULL)
    {
        cout << "JIOX";
    }
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
    if(m == 0)
    {
        m = 1;
        return del_first(head, m);
    }
    return head;
}

mine *DelC(mine *head)
{
    int m = ListQ(head);
    if(m == 0)
    {
        cout << "No elements left." << endl << endl;
        return head;
    }
    mine *common, *other;
    head = addF(head, m);
    common = head;
    other = common;
    stringstream a,b[m];
    string aa,bb[m];
    a << common->str;
    a >> aa;
    int i = 0;
    for(mine *temp = head; temp->next!=NULL; temp = temp->next)
    {
        common = common->next;
        b[i] << common->str;
        b[i] >> bb[i];

        if(aa == bb[i])
        {
            cout << "Found similar element." << endl << endl;
            return del_first(head, m);
        }
        i++;
    }
   cout << "No similar element found. List updated." << endl << endl;
   return del_element_end(head, m);
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
