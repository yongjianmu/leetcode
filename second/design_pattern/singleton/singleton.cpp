#include "../../include/header.h"
#include "singleton.h"

Singleton* Singleton::mInstance = NULL;

Singleton::Singleton()
{
    cout << "Init Singleton" << endl;
}

Singleton* Singleton::getInstance()
{
    if(NULL == mInstance)
    {
        mInstance = new Singleton();
    }

    return mInstance;
}
