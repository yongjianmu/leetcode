#include "../../include/header.h"

/*
const char* get()
LazyString(const char*)//allocate new storage.
LazyString(LazyString& str)// does not allocate new storage
void copy_from(const char*str)// allocate new storage
*/

class LazyString
{
    const char* mStr;
public:
    LazyString(const char* str)
    {
        char* var = new char[strlen(str)];
        strncpy(var, str, strlen(str));
        mStr = var;
    }

    LazyString(LazyString& str)
    {
        const char* var = str.get();
        mStr = var;
    }

    const char* get()
    {
        return mStr;
    }

    void copy_from(const char* str)
    {
        char* var = new char(strlen(str));
        strncpy(var, str, strlen(str));
        mStr = var;
    }
};

int main()
{
    LazyString a("asdf"); //allocate new storage
    LazyString b(a);// shares storage with a
    assert(a.get()==b.get()); //they have smae sotrage
    b.copy_from("asdf"); //modifei b, allocate new storage
    assert(a.get()!=b.get());// they have different sotrage
    return 0;
}
