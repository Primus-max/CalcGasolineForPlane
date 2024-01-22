//Грузовой самолет должен пролететь с грузом из пункта А
//в пункт С через пункт В. Емкость бака для топлива у самолета - 300 литров. Потребление топлива на 1 км в зависимости от веса груза у самолёта следующее:
//■ до 500 кг — 1 литров / км;
//■ до 1000 кг — 4 литров / км;
//■ до 1500 кг — 7 литров / км;
//■ до 2000 кг — 9 литров / км;
//■ более 2000 кг — самолет не поднимает.
//Пользователь вводит расстояние между пунктами А и В,
//и расстояние между пунктами В и С, а также вес груза.Программа должна рассчитать какое минимальное количество
//топлива необходимо для дозаправки самолету в пункте В,
//чтобы долететь из пункта А в пункт С.В случае невозможности преодолеть любое из расстояний — программа должна
//вывести сообщение о невозможности полета по введенному
//маршруту


#include <iostream>
using namespace std;

const double FUEL_TANK = 300.0; // Объём бака самолёта

/// <summary>
/// Метод расчёта топлива на 1 км при указанном весе груза
/// </summary>
/// <param name="cargoWeight">Вес груза</param>
/// <returns>double расход топлива на 1 км</returns>
double CalOfFuelConsumption(double cargoWeight)
{
    if (cargoWeight <= 500) {
        return 1.0; // 1 литр / км
    }
    else if (cargoWeight <= 1000) {
        return 4.0; // 4 литра / км
    }
    else if (cargoWeight <= 1500) {
        return 7.0; // 7 литров / км
    }
    else if (cargoWeight <= 2000) {
        return 9.0; // 9 литров / км
    }
    else {
        return -1.0; // Возвращаем значение -1 в случае ошибки
    }
}

/// <summary>
/// Метод расчёта пути и топлива
/// </summary>
/// <param name="ABPoint">Расстояние от A до В</param>
/// <param name="BCPoint">Расстояние от B до C</param>
/// <param name="cargoWeight">Вес груза</param>
/// <returns></returns>
bool CalculatingThePath(double ABPoint, double BCPoint, double cargoWeight)
{
    double fuelConsumption = CalOfFuelConsumption(cargoWeight);

    // Расчет необходимого топлива для полета из A в C с учетом расхода топлива
    double requiredFuel = (ABPoint + BCPoint) * fuelConsumption;

    // Проверка на возможность полета
    if (requiredFuel <= FUEL_TANK)
        return true;
    else
        return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double ABPoint = 0;
    double BCPoint = 0;
    double cargoWeight = 0;

    cout << "Я помогу тебе рассчитать расход топлива от пункта A до пункта С с пересадкой в пункте B " << endl;
    cout << "Введи расстояние от пункта A до пунтка В : ";
    cin >> ABPoint;
    cout << "Отлично, теперь расстояние от пункта В до пунтка С : ";
    cin >> BCPoint;

    cout << "Теперь укажи какой будет вес груза (максимально допустимый вес до 2000 кг.) : ";

    bool isInpuCargoWeightInValid = true;

    while (isInpuCargoWeightInValid)
    {
        cin >> cargoWeight;

        double fuelConsumption = CalOfFuelConsumption(cargoWeight);

        if (fuelConsumption == -1.0) {
            cout << "Ты ввёл недопустимый вес груза, максимальный вес до 2000 кг. Попробуй ещё раз, введи вес груза : ";
        }
        else {
            isInpuCargoWeightInValid = false;
        }
    }

    bool isPathImpossible = CalculatingThePath(ABPoint, BCPoint, cargoWeight);

    if (isPathImpossible)
        cout << "Для долета из пункта A в пункт C необходимо дозаправиться в пункте B." << std::endl;
    else
        cerr << "Ошибка: Невозможно преодолеть маршрут из-за нехватки топлива." << std::endl;

    return 0;

}
