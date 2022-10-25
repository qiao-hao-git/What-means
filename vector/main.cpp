#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v1(3);
    vector<int> v2(3,2);
    vector<int> v3(3,1,v2.get_allocator());
    vector<int> v4(v2);
    vector<int> v5(v4.begin()+1,v4.begin()+3);
    vector<int> v6(std::move(v2));
    cout<<"v1=";
    cout<<v1.cbegin();
    cout<<endl;
    return 0;
}
