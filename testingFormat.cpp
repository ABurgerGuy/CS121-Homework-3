//File found online : http://www.cplusplus.com/forum/beginner/49529/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string paddingZerosStr(int number, int padding);
bool hasWordInIt(string strArr[200],string checkStr);

int main (){
string names[200] = {"GREENSBORO 2 WNW AL US","GREENSBORO 2 WNW AL US","MUSCLE SHOALS 2 N AL US","MUSCLE SHOALS 2 N AL US","raul","hilda","ron","ron","ron","jake"};
string temp[200];
int place = 0;
        // cout << "Run 1" << endl;
        
        // for (int i = 0; i < sizeof(names)/sizeof(names[0]); i++)
        // {
        //   cout << names[i] << endl;
        // }

        // cout << "Run 2" << endl;

        // for (int i = 0; i < sizeof(names)/sizeof(names[0]); i++)
        // {
        //   for (int j = i+1; j < sizeof(names)/sizeof(names[0]); j++)
        //   {
        //     if (names[i] != names[j])
        //     {
        //       cout << names[i] << endl;
        //     }
            
        //   }
          
        // }


        cout << "Run 3" << endl;

        for (int i = 0; i < sizeof(names)/sizeof(names[0]); i++)
        {

            if (!hasWordInIt(temp,names[i]))
            {
             cout << names[i] << " " << i << " " << !hasWordInIt(temp,names[i]) << endl;
             
            }
            //cout << setw(8) << left << names[i] << names[j] << endl;
            
          
          
        }

    


// int size = sizeof(names)/sizeof(names[0]);

//     for(int i=0;i<size;++i)
// 		  for(int j=i+1;j<size;)
// 		  {
// 			  if(names[i]==names[j])
// 			  {
// 				  for(int k=j;k<(size)-1;++k)
// 					  names[k]=names[k+1];
					
// 				  --size;
// 			  }
// 			  else
// 				  ++j;
// 		  }
//       cout << "Run 2" << endl;
//       for (int i = 0; i < size; i++)
//       {
//         cout << names[i] << endl;
//       }



      

        // if (/* condition */)
        //{
          /* code */
        //}
        

        return 0;
}
//           BANKHEAD LOCK AND DAM AL US************
//           BANKHEAD LOCK AND DAM AL US************

bool hasWordInIt(string strArr[200],string checkStr)
{
  for (int i = 0; i < 200; i++)
  {
    if (strArr[i] == checkStr)
    {
      return true;
    }
    
  }
  return false;
}