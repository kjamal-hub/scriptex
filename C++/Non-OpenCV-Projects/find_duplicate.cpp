#include <iostream>

using namespace std;

int find(int num[ ])
{
  int t = num[0];
  int h = num[0];

  while(true)
  {
    t = num[t];
    h = num[num[h]];
    if(t == h)
      break;
  };

 int p1 = num[0];
 int p2 = t;

  while(p1 != p2)
  {
    p1 = num[p1];
    p2 = num[p2];
  };

  return p1;

};

int main()
{
  int num[] = {1,2,3,4,3};
  cout << find(num) << endl;
}
