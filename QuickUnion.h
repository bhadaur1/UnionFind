#ifndef _QUICK_UNION_UF_
#define _QUICK_UNION_UF_

class QuickUnionUF {
 private:
    int m_N;
    int *m_id;
    int *m_sz;
    int Root(int p);
    
 public:
    QuickUnionUF(int const &N);
    ~QuickUnionUF();
    bool IsConnected(int const &p, int const &q);
    void Union (int const &p, int const &q);
    void PrintID ();
};

#endif