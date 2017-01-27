
/*
    以下为内存分配与回收类## 标题 ##的实现
*/

template <class T>
class MemoryPool
{
public:
    MemoryPool(size_t size = EXPANSION_SIZE);
    ~MemoryPool();


    inline void* alloc();

    inline void free(void* someElement);
private:
    //空闲列表的下一个元素
    MemoryPool<T>* next;

    //如果空闲列表为空，就按该大小扩展它
    enum{ EXPANSION_SIZE = 32};

    //添加空闲元素至空闲列表
    void expandTheFreeList(inthowMany = EXPANSION_SIZE);
};


template <class T>
MemoryPool<T>::MemoryPool(size_t size)
{
    expandTheFreeList(size);
}


//析构函数  遍历空间列表，并删除所有元素
template <class T>
MemoryPool<T>::~MemoryPool()
{
    MemoryPool* nextPtr = next;
    for (nextPtr = next; nextPtr != NULL; nextPtr = next){
        next = next->next;
        delete[] nextPtr;
    }
}

//分配内存
template <class T>
inline
void* MemoryPool<T>::alloc()
{
    if (!next){//内存用尽则调用expandTheFreeList扩充
        expandTheFreeList();
    }

    MemoryPool<T>* head = next;
    next = head->next;

    return head;
}

//将内存回收到空闲列表
template <class T>
inline
void MemoryPool<T>::free(void* doomed)
{
    MemoryPool<T>* head = static_cast<MemoryPool<T>*>(doomed);
    head->next = next;
    next = head;
}


//expandTheFreeList向堆中分配新元素，然后将它们连接到空闲列表中
//当空闲列表被用尽时调用
template <class T>
void MemoryPool<T>::expandTheFreeList(int howMany)
{
    //分配足够大的对象已包含下一个指针
    size_t size = (sizeof(T) > sizeof(MemoryPool<T>*)) ?
        sizeof(T) : sizeof(MemoryPool<T>*);

    MemoryPool<T>* runner = static_cast<MemoryPool<T>*>(new char[size]);
    next = runner;
    for (int i = 0; i < howMany; i++){
        runner->next = static_cast<MemoryPool<T>*>new char[size];
        runner = runner->next;
    }
    runner->next = 0;
}


class Rational
{
public:
    Rational(int a = 0, int b = 1)
        :n(a), d(b)
    {}

    void* operator new(size_t size){
        return memPool->alloc(size);
    }

    void operator delete(void* doomed, size_t size){
        memPool->free(doomed);
    }

private:
    int n;
    int d;
    static MemoryPool<Rational>* memPool;
};

