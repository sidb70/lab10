#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::find_if;
#include<numeric>
using std::accumulate;


int CloseEnough(const vector<string> &vec, const int &diff){
    int i=1;
    auto itr = find_if(vec.begin(),vec.end()-2,[&i,&vec,&diff](string str){
        int index=0;
        string next = vec.at(i);
        int difference= accumulate(str.begin(),str.end(),0,[&next,&index](int &sum,char &curr){
                                    ++index;
                                    if(curr!=next.at(index-1))
                                        return (sum+1);
                                    return sum;      });
        ++i;
        next=vec.at(i);
        if(difference<=diff)
            return true;
        return false;
        });
    if(itr-vec.begin()!=vec.size()-2)
        return itr-vec.begin();
    return -1;
}