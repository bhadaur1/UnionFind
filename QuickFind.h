#ifndef _QUICK_FIND_UF_
#define _QUICK_FIND_UF_

class QuickFindUF {
    private:
    int m_N;
    int *m_id;
    
    public:
    QuickFindUF(int const &N);
    ~QuickFindUF();
    bool IsConnected(int const &p, int const &q);
    void Union (int const &p, int const &q);
    void PrintID ();
};

#endif