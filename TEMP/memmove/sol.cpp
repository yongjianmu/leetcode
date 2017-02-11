void* memmove(void* dest, void* source, size_t count)
{
    void* ret = dest;
    if (dest <= source || dest >= (source + count))
    {
        //Non-Overlapping Buffers
        //copy from lower addresses to higher addresses
        while (count --)
          *dest++ = *source++;
    }
    else
    {
        //Overlapping Buffers
        //copy from higher addresses to lower addresses 内存重叠的情况
        dest += count - 1;
        source += count - 1;
        while (count--)
          *dest-- = *source--;
    }
    return ret;
}
