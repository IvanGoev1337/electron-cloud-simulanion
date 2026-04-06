// electron dynamics.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
#include "electron.h"
#include "proton.h"
#include <fstream>

using namespace std;
const unsigned int N_e = 64;
const unsigned int N_p = 1;
static vector enviromentField(vector x, proton* p) {
    vector field;
    field.zero();
    for (int i = 0;i < N_p;i++) {
        field = field + p[i].getElectricField(x);
    }
    return field;
}
static void electricFieldCalculate(electron* A, proton* p, vector* res) {
    vector field[N_e][N_e];
    for (int i = 0;i < N_e;i++) {  
        for (int j = 0;j < N_e;j++) {
            if (i == j) {
                field[i][j].zero();
                continue;
            }
            field[i][j] = A[i].getElectricField(A[j].position);
        }
    }
    vector resTemp[N_e];
    for (int i = 0;i < N_e;i++) {
        resTemp[i].zero();
    }
    for (int i = 0;i < N_e;i++) {
        resTemp[i] = enviromentField(A[i].position, p) * q_e;
        for (int j = 0;j < N_e;j++) {
            resTemp[i] = resTemp[i] + field[i][j];
        }
    }
    for (int i = 0;i < N_e;i++) res[i] = resTemp[i];
}

int main()
{
    unsigned int t_limit = 100;
    double dt = 1.0 / 10;
    electron ans[N_e];
    proton env[N_p];
    vector force[N_e];
    vector startPos[N_e];
    vector startV[N_e];
    ofstream dataFile("data.txt");
    dataFile << to_string(t_limit) << '\n';
    dataFile << to_string(N_e) << '\n';
    double dx = 1;
    env[0].set(0, 0, 0);
    for (int i = 0;i < N_e;i++) {
        startPos[i].set(int(i / 8) * dx + 3, i % 8 * dx, 0);
    }
    for (unsigned int i = 0;i < N_e;i++) {
        startV[i].set(0, 1, 0);
    }
    for (int i = 0;i < N_e;i++) {
        ans[i].set(startPos[i], startV[i]);
    }
    for (unsigned int i = 0;i < t_limit;i++) {
        electricFieldCalculate(ans, env, force);
        //force[0].print();
        for (int j = 0;j < N_e;j++) {
            dataFile << ans[j].to_string() << endl;
            ans[j].newStep(dt, force[j]);
        }
        dataFile << "new step" << endl;
    }
    dataFile.close();
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
