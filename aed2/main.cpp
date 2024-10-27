#include "lib.h"
#include <iostream>
using namespace std;

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