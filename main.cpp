#include <iostream>
#include <pair.h>
#include <less.h>
#include <greater.h>
#include <mapToFirst.h>
#include <assert.h>

using namespace std;
using namespace map;


int rumpel()
{
  cout << "Hello World!" << endl;

  Pair<float,int> p(2.3,3);
  Pair<float,int> p2;
  Pair<string,int> p3;
  Pair<int,string> p4(4,"Hello");
  p2 = p;
  //cout << p2.first()<< endl;
  //cout << p2.second()<< endl;
  cout << Pair<float,int>(4.2,5) << endl;
  cout << p4 << endl;

  Greater<int> greaterInt;
  Greater<string> greaterString;
  Less<int> lessInt;
  Less<string> lessString;

  assert(lessInt(2,3));
  assert(greaterInt(3,2));
  assert(greaterString("ac","ab"));
  assert(lessString("ab","ac"));

  MapToFirst<int,string,Less> lessPair;
  Pair<int,string> p5(3,"low");
  Pair<int,string> p6(4,"high");

  assert(lessPair(p5,p6));




  return 0;
}

