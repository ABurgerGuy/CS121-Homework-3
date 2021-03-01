//File found online : http://www.cplusplus.com/forum/beginner/49529/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string paddingZerosStr(int number, int padding);

int main (){
    // string anotherStr = "test";
    // cout << anotherStr.length()/sizeof(anotherStr[0]) << endl;

    // string testString = "STATION";
    // cout << testString << endl;
    // cout << testString.size()/sizeof(testString[0]) << endl;
    // int qtyOfLines = 50;      
    //     for(int j=0; j<(qtyOfLines-(testString.size()/sizeof(testString[0])))/2; j++){
    //       cout << " ";
    //     }
    //       cout << testString; 
    //     for (int j = 0; j < ((qtyOfLines-(testString.size()/sizeof(testString[0])))/2)+1; j++)
    //     {
    //       cout << "*";
    //     }
          
  cout << paddingZerosStr(5,1) << endl;

        return 0;
}
//           BANKHEAD LOCK AND DAM AL US************
//           BANKHEAD LOCK AND DAM AL US************

string paddingZerosStr(int number, int padding)
{ 
  string newStr = "";
  for (int i = 0; i < padding; i++)
  {
    newStr += '0';
  }
  newStr += to_string(number);
  

  return newStr;
}