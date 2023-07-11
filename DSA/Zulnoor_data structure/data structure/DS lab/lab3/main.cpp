#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
#include "UDSA.h"
#include "ODSA.h"
using namespace std;

int main(){
ODSA d(3);
d.insert(2,1);
d.insert(1,2);
d.insert(0,3);
d.search(3);

cout<<endl;
UDSA d1(3);
d1.insert(6,1);
d1.insert(3,2);
d1.insert(5,3);
d1.search(8);

return 0;
}










