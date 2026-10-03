#include <vector>

struct StaticHashMap
{
    static const int CAP = 16;
    int keys[CAP];
    int values[CAP];
    bool occupied[CAP];

    StaticHashMap()
    {
        for (int i = 0; i < CAP; ++i)
            occupied[i] = false;
    }

    int hash(int k) const { return ((k % CAP) + CAP) % CAP; }

    void insert(int key, int value)
    {
        int index = hash(key);
        int ctr = CAP;
        while (occupied[index] != false && ctr--)
        {
            if (keys[index] == key)
            {
                values[index] = value;
                return;
            }
            index = (index + 1) % CAP;
        }

        if (ctr == 0)
            return;

        keys[index] = key;
        values[index] = value;
        occupied[index] = true;
    }

    int lookup(int key) const
    {
        int index = hash(key);
        int ctr = CAP;

        while (occupied[index] && ctr--)
        {
            if (keys[index] == key)
            {
                return values[index];
            }

            index = (index + 1) % CAP;
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
