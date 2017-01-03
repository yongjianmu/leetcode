#ifndef __SINGLETON_H__
#define __SINGLETON_H__

class Singleton
{
private:
    static Singleton* mInstance;
    class Garbo
    {
    public:
        static Garbo garbo;
        ~Garbo()
        {
            if(Singleton::mInstance)
            {
                delete Singleton::mInstance;
            }
        }
    };
protected:
    Singleton();
public:
    static Singleton* getInstance();
};

#endif

