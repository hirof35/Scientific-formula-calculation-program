#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ===== プロトタイプ宣言 =====
double kineticEnergy(double mass, double velocity);
double potentialEnergy(double mass, double height, double g);
double heatQuantity(double mass, double specificHeat, double deltaTemp);
double ohmsLaw(double current, double resistance);
double boyleCharlesLaw(double pressure, double volume, double tempCelsius);
double gravitationalForce(double m1, double m2, double distance);
void showMenu();

// ===== 定数 =====
const double G = 6.67430e-11;   // 万有引力定数 [N・m²/kg²]
const double g = 9.80665;       // 重力加速度 [m/s²]
const double KELVIN_OFFSET = 273.15;   // 摂氏→ケルビン変換

// ===== メイン関数 =====
int main() {
    int choice;
    bool running = true;

    cout << "===== 重要科学式 計算プログラム =====" << endl << endl;

    while (running) {
        showMenu();
        cout << "計算したい式の番号を入力してください：";
        cin >> choice;
        cout << endl;

        double mass, velocity, height, specificHeat, deltaTemp;
        double current, resistance, pressure, volume, tempCelsius;
        double m1, m2, distance, result;

        switch (choice) {
        case 1:
            cout << "--- 運動エネルギー ---" << endl;
            cout << "質量[kg]："; cin >> mass;
            cout << "速度[m/s]："; cin >> velocity;
            result = kineticEnergy(mass, velocity);
            cout << "■ 運動エネルギー = " << fixed << setprecision(4) << result << " J" << endl;
            break;

        case 2:
            cout << "--- 位置エネルギー ---" << endl;
            cout << "質量[kg]："; cin >> mass;
            cout << "高さ[m]："; cin >> height;
            result = potentialEnergy(mass, height, g);
            cout << "■ 位置エネルギー = " << fixed << setprecision(4) << result << " J" << endl;
            break;

        case 3:
            cout << "--- 熱量 ---" << endl;
            cout << "質量[kg]："; cin >> mass;
            cout << "比熱[J/(kg・℃)]："; cin >> specificHeat;
            cout << "温度変化[℃]："; cin >> deltaTemp;
            result = heatQuantity(mass, specificHeat, deltaTemp);
            cout << "■ 発生熱量 = " << fixed << setprecision(4) << result << " J" << endl;
            break;

        case 4:
            cout << "--- オームの法則 ---" << endl;
            cout << "電流[A]："; cin >> current;
            cout << "抵抗[Ω]："; cin >> resistance;
            result = ohmsLaw(current, resistance);
            cout << "■ 電圧 = " << fixed << setprecision(4) << result << " V" << endl;
            break;

        case 5:
            cout << "--- ボイル=シャルルの法則 ---" << endl;
            cout << "圧力[Pa]："; cin >> pressure;
            cout << "体積[m³]："; cin >> volume;
            cout << "温度[℃]："; cin >> tempCelsius;
            result = boyleCharlesLaw(pressure, volume, tempCelsius);
            cout << "■ P×V/T = " << fixed << setprecision(6) << result << " （一定値）" << endl;
            break;

        case 6:
            cout << "--- 万有引力 ---" << endl;
            cout << "質量1[kg]："; cin >> m1;
            cout << "質量2[kg]："; cin >> m2;
            cout << "距離[m]："; cin >> distance;
            if (distance <= 0) {
                cout << "⚠ 距離は0より大きい値を入力してください" << endl;
                break;
            }
            result = gravitationalForce(m1, m2, distance);
            cout << "■ 万有引力 = " << scientific << setprecision(6) << result << " N" << endl;
            break;

        case 0:
            cout << "プログラムを終了します。お疲れ様でした！" << endl;
            running = false;
            break;

        default:
            cout << "⚠ 正しい番号を入力してください（0～6）" << endl;
            break;
        }
        cout << endl << "----------------------------------------" << endl << endl;
    }
    return 0;
}

// ===== メニュー表示 =====
void showMenu() {
    cout << "【計算できる科学式】" << endl;
    cout << " 1. 運動エネルギー       E = 1/2 × m × v²" << endl;
    cout << " 2. 位置エネルギー       U = m × g × h" << endl;
    cout << " 3. 熱量                 Q = m × c × ΔT" << endl;
    cout << " 4. オームの法則         V = I × R" << endl;
    cout << " 5. ボイル=シャルルの法則 P×V/T = 一定" << endl;
    cout << " 6. 万有引力             F = G×m₁×m₂/r²" << endl;
    cout << " 0. 終了" << endl;
}

// ===== 各種計算関数の定義 =====
double kineticEnergy(double mass, double velocity) {
    return 0.5 * mass * velocity * velocity;
}

double potentialEnergy(double mass, double height, double g) {
    return mass * g * height;
}

double heatQuantity(double mass, double specificHeat, double deltaTemp) {
    return mass * specificHeat * deltaTemp;
}

double ohmsLaw(double current, double resistance) {
    return current * resistance;
}

double boyleCharlesLaw(double pressure, double volume, double tempCelsius) {
    double tempKelvin = tempCelsius + KELVIN_OFFSET;
    return (pressure * volume) / tempKelvin;
}

double gravitationalForce(double m1, double m2, double distance) {
    return G * m1 * m2 / (distance * distance);
}
