#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//
//3 0 3
//5 2
//6 1
//7 0
//вывод 3

struct Orc {
    int a, b, diff; // способности в бою и метании копья, разность способностей
};

bool cmp(const Orc& o1, const Orc& o2) {
    return o1.diff > o2.diff; // сортировка по убыванию разности способностей
}

int main() {
    int n, g, h;
    cin >> n >> g >> h;

    vector<Orc> orcs(n);
    for (int i = 0; i < n; ++i) {
        cin >> orcs[i].a >> orcs[i].b;
        orcs[i].diff = orcs[i].b - orcs[i].a;
    }

    sort(orcs.begin(), orcs.end(), cmp);

    vector<Orc> grunts(orcs.begin(), orcs.begin() + g); // первые g орков
    sort(orcs.begin() + g, orcs.end(), [](const Orc& o1, const Orc& o2) {
        return o1.b > o2.b; // сортировка по убыванию способности в метании копья
        });
    vector<Orc> headhunters(orcs.begin() + g, orcs.begin() + g + h); // первые h орков с наибольшей способностью в метании копья

    if (grunts.size() + headhunters.size() > n) { // проверка на неполноценную армию
        cout << -1 << endl;
    }
    else {
        int grunt_power = 0, headhunter_power = 0;
        for (auto orc : grunts) {
            grunt_power += orc.a;
        }
        for (auto orc : headhunters) {
            headhunter_power += orc.b;
        }
        int army_power = grunt_power + headhunter_power; // общая сила отряда
        cout << army_power << endl;
    }

    return 0;
}