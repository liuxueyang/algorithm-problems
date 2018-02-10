/*
  Author: Xueyang Liu
  Date: 2018/01/25
*/

// ==================================================

//                                        /*
//                                       +
//                                      +
//                                     +
//                                     +
//                                     [         >i>n[t
//                                      */   #include<stdio.h>
//                         /*2w0,1m2,]_<n+a m+o>r>i>=>(['0n1'0)1;
//                      */int/**/main(int/**/n,char**m){FILE*p,*q;int        A,k,a,r,i/*
//                    #uinndcelfu_dset<rsitcdti_oa.nhs>i/_*/;char*d="P%"   "d\n%d\40%d"/**/
//                  "\n%d\n\00wb+",b[1024],y[]="yuriyurarararayuruyuri*daijiken**akkari~n**"
//           "/y*u*k/riin<ty(uyr)g,aur,arr[a1r2a82*y2*/u*r{uyu}riOcyurhiyua**rrar+*arayra*="
//        "yuruyurwiyuriyurara'rariayuruyuriyuriyu>rarararayuruy9uriyu3riyurar_aBrMaPrOaWy^?"
//       "*]/f]`;hvroai<dp/f*i*s/<ii(f)a{tpguat<cahfaurh(+uf)a;f}vivn+tf/g*`*w/jmaa+i`ni("/**
//      */"i+k[>+b+i>++b++>l[rb";int/**/u;for(i=0;i<101;i++)y[i*2]^="~hktrvg~dmG*eoa+%squ#l2"
//      ":(wn\"1l))v?wM353{/Y;lgcGp`vedllwudvOK`cct~[|ju {stkjalor(stwvne\"gt\"yogYURUYURI"[
//      i]^y[i*2+1]^4;/*!*/p=(n>1&&(m[1][0]-'-'||m[1][1]  !='\0'))?fopen(m[1],y+298):stdin;
//       /*y/riynrt~(^w^)],]c+h+a+r+*+*[n>)+{>f+o<r<(-m]    =<2<5<64;}-]-(m+;yry[rm*])/[*
//        */q=(n<3||!(m[2][0]-'-'||m[2][1]))?stdout /*]{     }[*/:fopen(m[2],d+14);if(!p||/*
//        "]<<*-]>y++>u>>+r >+u+++y>--u---r>++i+++"  <)<      ;[>-m-.>a-.-i.++n.>[(w)*/!q/**/)
//     return+printf("Can "  "not\x20open\40%s\40"    ""       "for\40%sing\n",m[!p?1:2],!p?/*
//   o=82]5<<+(+3+1+&.(+  m  +-+1.)<)<|<|.6>4>-+(>    m-        &-1.9-2-)-|-|.28>-w-?-m.:>([28+
//  */"read":"writ");for  (   a=k=u= 0;y[u];  u=2    +u){y[k++   ]=y[u];}if((a=fread(b,1,1024/*
// ,mY/R*Y"R*/,p/*U*/)/*          R*/ )>/*U{  */   2&& b/*Y*/[0]/*U*/=='P' &&4==/*"y*r/y)r\}
// */sscanf(b,d,&k,& A,&           i,  &r)&&        !   (k-6&&k -5)&&r==255){u=A;if(n>3){/*
// ]&<1<6<?<m.-+1>3> +:+ .1>3+++     .   -m-)      -;.u+=++.1<0< <; f<o<r<(.;<([m(=)/8*/
// u++;i++;}fprintf   (q,    d,k,           u      >>1,i>>1,r);u  = k-5?8:4;k=3;}else
//   /*]>*/{(u)=/*{   p> >u  >t>-]s                >++(.yryr*/+(    n+14>17)?8/4:8*5/
//      4;}for(r=i=0  ;  ;){u*=6;u+=                (n>3?1:0);if    (y[u]&01)fputc(/*
//       <g-e<t.c>h.a r  -(-).)8+<1.                 >;+i.(<)<     <)+{+i.f>([180*/1*
//       (r),q);if(y[u   ]&16)k=A;if                               (y[u]&2)k--;if(i/*
//       ("^w^NAMORI; {   I*/==a/*"                               )*/){/**/i=a=(u)*11
//        &255;if(1&&0>=     (a=                                 fread(b,1,1024,p))&&
//         ")]i>(w)-;} {                                         /i-f-(-m--M1-0.)<{"
//          [ 8]==59/* */                                       )break;i=0;}r=b[i++]
//             ;u+=(/**>>                                     *..</<<<)<[[;]**/+8&*
//             (y+u))?(10-              r?4:2):(y[u]         &4)?(k?2:4):2;u=y[u/*
//              49;7i\(w)/;}             y}ru\=*ri[        ,mc]o;n}trientuu ren (
//              */]-(int)'`';}             fclose(          p);k= +fclose( q);
//               /*] <*.na/m*o{ri{                       d;^w^;}  }^_^}}
//                "   */   return  k-                -1+   /*\'   '-`*/
//                      (   -/*}/   */0x01        );       {;{    }}
//                             ;           /*^w^*/        ;}

// ==================================================

// C library
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Containers
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// Input/Output
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <ios>
#include <iomanip>

// Other
#include <tuple>
#include <string>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <iterator>
#include <limits>

// ==================================================

using namespace std;

using PII = pair<int, int>;

// ==================================================

static auto __________2333__________ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ==================================================

template<typename T>
void PRINT_CONTAINER(const T& c) {
  for (auto x : c) cout << x << " ";
  cout << "\n";
}

template<typename T>
void PRINTV(const vector<T>& c) {
  PRINT_CONTAINER<vector<T>>(c);
}

template<typename T1, typename T2>
void PRINTP(const pair<T1, T2>& p) {
  PRINTC(p.first);
  PRINTLN(p.second);
}

template<typename T>
void PRINTC(const T& a) {
  cout << a << " ";
}

template<typename T>
void PRINTLN(const T& a) {
  cout << a << "\n";
}

template<typename T1, typename T2>
auto max_(const T1& a, const T2& b) {
  using return_type = decltype(a + b);
  return a > b ? static_cast<return_type>(a) : static_cast<return_type>(b);
}

template<typename T1, typename T2>
auto min_(const T1& a, const T2& b) {
  using return_type = decltype(a + b);
  return b > a ? static_cast<return_type>(a) : static_cast<return_type>(b);
}

// ==================================================

int main(void) {

#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif

  int x, y;
  
  while (cin >> x >> y) {
    bool mark = true;

    if (y < 1) mark = false;
    if (y == 1 && x > 0) mark = false;
    if (x < y - 1) mark = false;
    if ((x - y + 1) & 1) mark = false;

    PRINTLN(mark ? "Yes" : "No");
  }

  return 0;
}
