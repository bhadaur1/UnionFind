#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "QuickUnion.h"

QuickUnionUF::QuickUnionUF(int const &N) {
    m_N = N;
    m_id = new int [N];
    m_sz = new int [N];
    for (int i=0; i<N; i++) {
        m_id[i] = i;
        m_sz[i] = 1;
    }
}

QuickUnionUF::~QuickUnionUF() {
    delete m_id;
    delete m_sz;
}

void QuickUnionUF::PrintID() {
    for (int i = 0; i < m_N; i++) {
        std::cout << std::setw(4);
        std::cout << i << " | ";
    }
    std::cout << std::endl;
    for (int i = 0; i < m_N; i++) {
        std::cout << std::setw(4);
        std::cout << m_id[i] << " | ";
    }
    std::cout << std::endl;
}

int QuickUnionUF::Root(int p)
{
    while (p != m_id[p]) {
        m_id[p] = m_id[m_id[p]];
        p = m_id[p];
    }
    return p;
}

void QuickUnionUF::Union(int const &p, int const &q) {
    if (m_N <= p || m_N <= q) {
        throw std::invalid_argument("Index out of bounds in Union.");
    }
    if (Root(p) == Root (q)) return;
    else if (m_sz[p] < m_sz[q]) {
        m_id[Root(p)] = Root(q);
        m_sz[q] += m_sz[p];
    }
    else {
        m_id[Root(q)] = Root(p);
        m_sz[p] += m_sz[q];
    }
}

bool QuickUnionUF::IsConnected(int const &p, int const&q) {
    if (m_N <= p || m_N <= q) {
        throw std::invalid_argument("Index out of bounds in Connected query.");
    }    
    return (Root(p) == Root(q));
}