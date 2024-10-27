#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class DisjointSet {
private:
    unordered_map< int, unordered_set< double > > Sets;

public:
    void make_set(double x) {
        for (const auto& Set : Sets) {
            if (Set.second.count(x) > 0) {
                cout << "Operação Inválida!\n " << x << " pertence ao conjunto " << Set.first << "\n\n";
                return;
            }
        }

        int new_i = find_next();

        unordered_set< double > new_set = {x};

        Sets[new_i] = new_set;
    }

    void show_set(double x) {
        for (const auto& Set : Sets) {
            if (Set.second.count(x) > 0) {
                cout << "Conjunto com " << x << ": S" << Set.first << " = ";
                print_set(Set.second);
                return;
            }
        }
        cout << x << " nao pertence a nenhum conjunto\n\n";
    }

    void show_set(int i) {
        auto it = Sets.find(i);

        if (it != Sets.end()) {
            print_set(it->second);
        } else {
            cout << "Conjunto de ordem " << i << " nao existe\n\n";
        }
    }

    void destroy_set(double x) {
        for (auto it = Sets.begin(); it != Sets.end(); ++it) {
            if (it->second.count(x) > 0) {
                Sets.erase(it);

                cout << "Conjunto com " << x << " destruido\n\n";
                return;
            }
        }
    }

    void destroy_set(int i) {
        auto it = Sets.find(i);

        if (it != Sets.end()) {
            Sets.erase(it);
            cout << "Conjunto de ordem " << i << " destruido.\n\n";
        } else {
            cout << "Conjunto de ordem " << i << " nao existe.\n\n";
        }
    }

    void union_sets(double x, double y) {
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

    int find_set(double x) {
        for (const auto& Set : Sets) {
            if (Set.second.count(x) > 0) {
                cout << "Representante do conjunto " << x << "\n\n";
                return Set.first;
            }
        }
        cout << x << " nao pertence a nenhum conjunto\n\n";
        return -1; 
    }

    int size_set(double x) {
        for (const auto& Set : Sets) {
            if (Set.second.count(x) > 0) {
                cout << "Cardinalidade de " << x << ": " << Set.second.size() << "\n\n";
                return Set.second.size();
            }
        }
        cout << x << " nao pertence a nenhum conjunto\n\n";
        return -1; 
    }

    int size_set(int i) {
        auto it = Sets.find(i);

        if (it != Sets.end()) {
            cout << "Cardinalidade de " << i << ": " << it->second.size() << "\n\n";
            return it->second.size();
        } else {
            cout << "Conjunto de ordem " << i << " nao existe\n\n";
            return -1; 
        }
    }

private:
    int find_next() {
        int i = 1;
        while (Sets.count(i) > 0) {
            i++;
        }
        return i;
    }

    void print_set(const unordered_set<double>& Set) {
        cout << "{";
        for (auto it = Set.begin(); it != Set.end(); ++it) {
            cout << *it;
            if (next(it) != Set.end()) {
                cout << ", ";
            }
        }
        cout << "}\n\n";
    }

    int order(double x) {
        for (const auto& Set : Sets) {
            if (Set.second.count(x) > 0) {
                return Set.first;
            }
        }
        return -1; 
    }
};

int main() {
    DisjointSet data;
    int op;
    bool flag = false;

    while(1){
        cout << "Escolha a operacao:\n1-Make-Set(x)\n2-Show-Set(x)\n3-Show-Set(i)\n4-Destroy-Set(x)\n5-Destroy-Set(i)\n6-Union(x, y)\n7-Find-Set(x)\n8-Size-Set(x)\n9-Size-Set(i)\n10-Sair\n";
        cin >> op;

        double x, y;
        int i;
        switch(op){
            case 1:
                cout << "Digite o valor x\n";
                cin >> x;
                data.make_set(x);
                break;
            case 2:
                cout << "Digite o valor x\n";
                cin >> x;
                data.show_set(x);
                break;
            case 3:
                cout << "Digite a ordem do conjunto\n";
                cin >> i;
                data.show_set(i);
                break;
            case 4:
                cout << "Digite o valor x\n";
                cin >> x;
                data.destroy_set(x);
                break;
            case 5:
                cout << "Digite a ordem i\n";
                cin >> i;
                data.destroy_set(i);
                break;
            case 6:
                cout << "Digite os elemento x e y\n";
                cin >> x >> y;
                data.union_sets(x, y);
                break;
            case 7:
                cout << "Digite o valor x\n";
                cin >> x;
                data.find_set(x);
                break;
            case 8:
                cout << "Digite o valor x\n";
                cin >> x;
                data.size_set(x);
                break;
            case 9:
                cout << "Digite o valor i\n";
                cin >> i;
                data.size_set(i);
                break;
            case 10:
                flag = true;
                break;
            default:
                cout << "Operacao invalida\n";
        }

        if(flag)
            break;
    }

    return 0;
}