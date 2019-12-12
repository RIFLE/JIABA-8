#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

typedef char* TE;

struct mine
{
    TE str = new char[255]; //data field
    mine* next;             //address field
};

int showLists(mine *head);
mine *del_first(mine *head, int m);
mine *del_second(mine *head, int m);
mine *del_element_end(mine *head, int m);
mine *DelC(mine *head);
void write(mine *head);
int ListQ(mine *head);
mine *addF(mine *head, int m);
mine *addB(mine *head, int m);
int CheckL(mine *head);
mine* declare();
