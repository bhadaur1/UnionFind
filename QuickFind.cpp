#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "QuickFind.h"

QuickFindUF::QuickFindUF(int const &N) {
    m_N = N;
    m_id = new int [N];
    for (int i=0; i<N; i++) {
        m_id[i] = i;
    }
}

QuickFindUF::~QuickFindUF() {
    delete m_id;
}

void QuickFindUF::PrintID() {
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

void QuickFindUF::Union(int const &p, int const &q) {
    if (m_N <= p || m_N <= q) {
        throw std::invalid_argument("Index out of bounds in Union.");
    }
    int const pid = m_id[p];
    int const qid = m_id[q];
    for (int i = 0; i < m_N; i++) {
        if (m_id[i] == pid)
            m_id[i] = qid;
    }
}

bool QuickFindUF::IsConnected(int const &p, int const&q) {
    if (m_N <= p || m_N <= q) {
        throw std::invalid_argument("Index out of bounds in Connected query.");
    }    
    return (m_id[p] == m_id[q]);
}