#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <unordered_map>
#include <unordered_set>
using namespace std;

class DisjointSet {
private:
    unordered_map<int, unordered_set<double>> Sets;

public:
    void make_set(double x);
    void show_set(double x);
    void show_set(int i);
    void destroy_set(double x);
    void destroy_set(int i);
    void union_sets(double x, double y);
    int find_set(double x);
    int size_set(double x);
    int size_set(int i);

private:
    int find_next();
    void print_set(const unordered_set<double>& Set);
    int order(double x);
};

#endif