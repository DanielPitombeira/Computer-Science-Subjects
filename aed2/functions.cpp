#include "lib.h"
#include <iostream>

using namespace std;

void DisjointSet::make_set(double x) {

    for (const auto& Set : Sets) {
        if (Set.second.count(x) > 0) {
            cout << "Operação Inválida!\n " << x << " pertence ao conjunto " << Set.first << "\n\n";
            return;
        }
    }

    int new_i = find_next();

    unordered_set<double> new_set = {x};

    Sets[new_i] = new_set;
}

void DisjointSet::show_set(double x) {
    for (const auto& Set : Sets) {
        if (Set.second.count(x) > 0) {
            cout << "Conjunto com " << x << ": S" << Set.first << " = ";
            print_set(Set.second);
            return;
        }
    }
    cout << x << " nao pertence a nenhum conjunto\n\n";
}

void DisjointSet::show_set(int i) {
    auto it = Sets.find(i);

    if (it != Sets.end()) {
        print_set(it->second);
    } else {
        cout << "Conjunto de ordem " << i << " nao existe\n\n";
    }
}

void DisjointSet::destroy_set(double x) {
    for (auto it = Sets.begin(); it != Sets.end(); ++it) {
        if (it->second.count(x) > 0) {
            Sets.erase(it);

            cout << "Conjunto com " << x << " destruido\n\n";
            return;
        }
    }
}

void DisjointSet::destroy_set(int i) {
    auto it = Sets.find(i);

    if (it != Sets.end()) {
        Sets.erase(it);
        cout << "Conjunto de ordem " << i << " destruido.\n\n";
    } else {
        cout << "Conjunto de ordem " << i << " nao existe.\n\n";
    }
}

void DisjointSet::union_sets(double x, double y) {
    int i = order(x);
    int j = order(y);

    if (i == j) {
        cout << x << " e " << y << " pertencem ao mesmo conjunto.\n\n";
        return;
    }

    auto it_i = Sets.find(i);
    auto it_j = Sets.find(j);

    it_i->second.insert(it_j->second.begin(), it_j->second.end());
    Sets.erase(it_j);

    cout << "S" << i << " = ";
    print_set(it_i->second);
}

int DisjointSet::find_set(double x) {
    for (const auto& Set : Sets) {
        if (Set.second.count(x) > 0) {
            cout << "Representante do conjunto " << x << "\n\n";
            return Set.first;
        }
    }
    cout << x << " nao pertence a nenhum conjunto\n\n";
    return -1; 
}

int DisjointSet::size_set(double x) {
    for (const auto& Set : Sets) {
        if (Set.second.count(x) > 0) {
            cout << "Cardinalidade de " << x << ": " << Set.second.size() << "\n\n";
            return Set.second.size();
        }
    }
    cout << x << " nao pertence a nenhum conjunto\n\n";
    return -1; 
}

int DisjointSet::size_set(int i) {
    auto it = Sets.find(i);

    if (it != Sets.end()) {
        cout << "Cardinalidade de " << i << ": " << it->second.size() << "\n\n";
        return it->second.size();
    } else {
        cout << "Conjunto de ordem " << i << " nao existe\n\n";
        return -1; 
    }
}

int DisjointSet::find_next() {
    int i = 1;
    while (Sets.count(i) > 0) {
        i++;
    }
    return i;
}

void DisjointSet::print_set(const unordered_set<double>& Set) {
    cout << "{";
    for (auto it = Set.begin(); it != Set.end(); ++it) {
        cout << *it;
        if (next(it) != Set.end()) {
            cout << ", ";
        }
    }
    cout << "}\n\n";
}

int DisjointSet::order(double x) {
    for (const auto& Set : Sets) {
        if (Set.second.count(x) > 0) {
            return Set.first;
        }
    }
    return -1; 
}