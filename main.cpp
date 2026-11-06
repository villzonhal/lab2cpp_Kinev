#include "functions.h"

#include <algorithm>
#include <clocale>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

int main() {
    std::setlocale(LC_ALL, ".UTF-8");

    std::string line;
    std::vector<int> numbers;

    while (true) {
        std::cout << "\nЛАБОРАТОРНАЯ РАБОТА №2. STL. ВАРИАНТ 8\n"
            << "1 - задача 1.6: удвоение первого, среднего и "
            "последнего элементов\n"
            << "2 - задача 2.3: первая треть списка - в конец, "
            "наоборот\n"
            << "3 - задача 3.9: удаление чётных номеров "
            "в половине дека\n"
            << "4 - задача 4.4: запись чисел в файл "
            "с заменой 0 на 10\n"
            << "5 - задача 5.8: удаление последнего набора "
            "из K нулей\n"
            << "6 - задача 6.8: инвертирование половин списков\n"
            << "7 - задача 7.5: количество чётных "
            "и нечётных чисел\n"
            << "8 - задача 8.1: средние арифметические "
            "соседних чисел\n"
            << "9 - задача 9.2: векторы, содержащие "
            "все элементы V0\n"
            << "10 - задача 10.4: группировка слов "
            "по последней букве\n"
            << "0 - выход\n"
            << "--------------------------------------------------"
            "-------------\n";

        int choice = 0;
        while (true) {
            std::cout << "Выберите пункт меню (0-10): ";
            if (!std::getline(std::cin, line)) {
                return 0;
            }
            std::istringstream stream(line);
            char extra = ' ';
            if ((stream >> choice) && !(stream >> extra) && choice >= 0 &&
                choice <= 10) {
                break;
            }
            std::cout << "Ошибка: нужно ввести одно целое число "
                "от 0 до 10.\n";
        }

        if (choice == 0) {
            std::cout << "Работа завершена. До свидания!\n";
            return 0;
        }

        if (choice == 1) {
            std::cout << "\n--- Задача 1.6: удвоение первого, среднего "
                "и последнего элементов ---\n"
                << "Даны вектор V, дек D и список L. В каждом "
                "из них нечётное количество чисел\n(не меньше "
                "3). Первый, средний и последний элементы "
                "каждого контейнера удвоятся.\n"
                << "Числа вводите через пробел, например: "
                "1 2 3 4 5\n";

            while (true) {
                std::cout << "Вектор V: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                numbers.assign(std::istream_iterator<int>(stream),
                    std::istream_iterator<int>());
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только целые числа "
                        "(не больше 2 млрд по модулю) "
                        "через пробел.\n";
                }
                else if (numbers.size() < 3 || numbers.size() % 2 == 0) {
                    std::cout << "Ошибка: количество чисел должно быть "
                        "нечётным и не меньше 3 (введено "
                        << numbers.size() << ").\n";
                }
                else {
                    break;
                }
            }
            std::vector<int> v(numbers.begin(), numbers.end());

            while (true) {
                std::cout << "Дек D: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                numbers.assign(std::istream_iterator<int>(stream),
                    std::istream_iterator<int>());
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только целые числа "
                        "(не больше 2 млрд по модулю) "
                        "через пробел.\n";
                }
                else if (numbers.size() < 3 || numbers.size() % 2 == 0) {
                    std::cout << "Ошибка: количество чисел должно быть "
                        "нечётным и не меньше 3 (введено "
                        << numbers.size() << ").\n";
                }
                else {
                    break;
                }
            }
            std::deque<int> d(numbers.begin(), numbers.end());

            while (true) {
                std::cout << "Список L: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                numbers.assign(std::istream_iterator<int>(stream),
                    std::istream_iterator<int>());
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только целые числа "
                        "(не больше 2 млрд по модулю) "
                        "через пробел.\n";
                }
                else if (numbers.size() < 3 || numbers.size() % 2 == 0) {
                    std::cout << "Ошибка: количество чисел должно быть "
                        "нечётным и не меньше 3 (введено "
                        << numbers.size() << ").\n";
                }
                else {
                    break;
                }
            }
            std::list<int> l(numbers.begin(), numbers.end());

            DoubleFirstMiddleLast(v);
            DoubleFirstMiddleLast(d);
            DoubleFirstMiddleLast(l);

            std::cout << "Результат:\n V: ";
            std::copy(v.begin(), v.end(),
                std::ostream_iterator<int>(std::cout, " "));
            std::cout << "\n D: ";
            std::copy(d.begin(), d.end(),
                std::ostream_iterator<int>(std::cout, " "));
            std::cout << "\n L: ";
            std::copy(l.begin(), l.end(),
                std::ostream_iterator<int>(std::cout, " "));
            std::cout << '\n';
        }
        else if (choice == 2) {
            std::cout << "\n--- Задача 2.3: первая треть списка "
                "в конец в обратном порядке ---\n"
                << "Дан список L, количество элементов "
                "которого делится на 3.\n"
                << "Числа вводите через пробел, например: "
                "1 2 3 4 5 6\n";

            while (true) {
                std::cout << "Список L: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                numbers.assign(std::istream_iterator<int>(stream),
                    std::istream_iterator<int>());
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только целые числа "
                        "(не больше 2 млрд по модулю) "
                        "через пробел.\n";
                }
                else if (numbers.empty() || numbers.size() % 3 != 0) {
                    std::cout << "Ошибка: количество чисел должно "
                        "делиться на 3 и быть не меньше 3 "
                        "(введено "
                        << numbers.size() << ").\n";
                }
                else {
                    break;
                }
            }
            std::list<int> l(numbers.begin(), numbers.end());

            AppendReversedFirstThird(l);

            std::cout << "Результат L: ";
            std::copy(l.begin(), l.end(),
                std::ostream_iterator<int>(std::cout, " "));
            std::cout << '\n';
        }
        else if (choice == 3) {
            std::cout << "\n--- Задача 3.9: удаление элементов "
                "с чётными номерами в первой половине "
                "дека ---\n"
                << "Дан дек D, количество элементов которого "
                "кратно 4. Номера считаются с 1.\n"
                << "Числа вводите через пробел, например: "
                "1 2 3 4 5 6 7 8\n";

            while (true) {
                std::cout << "Дек D: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                numbers.assign(std::istream_iterator<int>(stream),
                    std::istream_iterator<int>());
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только целые числа "
                        "(не больше 2 млрд по модулю) "
                        "через пробел.\n";
                }
                else if (numbers.empty() || numbers.size() % 4 != 0) {
                    std::cout << "Ошибка: количество чисел должно быть "
                        "кратно 4 и не меньше 4 (введено "
                        << numbers.size() << ").\n";
                }
                else {
                    break;
                }
            }
            std::deque<int> d(numbers.begin(), numbers.end());

            EraseEvenPositionsInFirstHalf(d);

            std::cout << "Результат D: ";
            std::copy(d.begin(), d.end(),
                std::ostream_iterator<int>(std::cout, " "));
            std::cout << '\n';
        }
        else if (choice == 4) {
            std::cout << "\n--- Задача 4.4: запись чисел в файл "
                "с заменой 0 на 10 ---\n"
                << "Числа запишутся в файл в том же порядке, "
                "каждый 0 заменится на 10,\nпосле каждого "
                "числа будет два пробела.\n"
                << "Числа вводите через пробел, например: "
                "5 0 7 0 -3\n";

            while (true) {
                std::cout << "Набор чисел: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                int count = 0;
                int value = 0;
                while (stream >> value) {
                    ++count;
                }
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только целые числа "
                        "(не больше 2 млрд по модулю) "
                        "через пробел.\n";
                }
                else if (count == 0) {
                    std::cout << "Ошибка: нужно ввести хотя бы одно "
                        "число.\n";
                }
                else {
                    break;
                }
            }

            std::string file_name;
            std::ofstream output;
            while (true) {
                std::cout << "Имя файла (существующий файл будет "
                    "перезаписан): ";
                if (!std::getline(std::cin, file_name)) {
                    return 0;
                }
                if (file_name.find_first_not_of(" \t") ==
                    std::string::npos) {
                    std::cout << "Ошибка: имя файла не может быть "
                        "пустым.\n";
                    continue;
                }
                output.open(file_name);
                if (output.is_open()) {
                    break;
                }
                std::cout << "Ошибка: не удалось открыть файл \""
                    << file_name
                    << "\" для записи. Введите другое имя.\n";
            }

            std::istringstream input(line);
            WriteReplacedNumbers(input, output);
            output.close();

            if (output.fail()) {
                std::cout << "Ошибка: не удалось записать данные "
                    "в файл.\n";
            }
            else {
                std::ifstream result(file_name);
                std::string text;
                std::getline(result, text);
                std::cout << "Готово! В файле \"" << file_name
                    << "\" записано (в кавычках):\n\""
                    << text << "\"\n";
            }
        }
        else if (choice == 5) {
            std::cout << "\n--- Задача 5.8: удаление последнего "
                "набора из K подряд идущих нулей ---\n"
                << "Дан вектор V из нулей и единиц. Если "
                "в наборе больше K нулей,\nудаляются "
                "только последние K.\n";

            int k = 0;
            while (true) {
                std::cout << "Введите K (целое число больше 0): ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line);
                char extra = ' ';
                if ((stream >> k) && !(stream >> extra) && k > 0) {
                    break;
                }
                std::cout << "Ошибка: нужно ввести одно целое число "
                    "больше 0.\n";
            }

            std::cout << "Элементы вектора вводите через пробел, "
                "например: 1 0 0 1 0 0 0\n";
            while (true) {
                std::cout << "Вектор V (только 0 и 1): ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                numbers.assign(std::istream_iterator<int>(stream),
                    std::istream_iterator<int>());
                bool only_zeros_and_ones = true;
                for (int x : numbers) {
                    if (x != 0 && x != 1) {
                        only_zeros_and_ones = false;
                    }
                }
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только числа 0 и 1, "
                        "разделённые пробелами.\n";
                }
                else if (numbers.empty()) {
                    std::cout << "Ошибка: нужно ввести хотя бы один "
                        "элемент.\n";
                }
                else if (!only_zeros_and_ones) {
                    std::cout << "Ошибка: в векторе должны быть "
                        "только нули и единицы.\n";
                }
                else {
                    break;
                }
            }

            if (EraseLastZeroRun(numbers, k)) {
                std::cout << "Набор из " << k << " нулей удалён.\n";
            }
            else {
                std::cout << "Набора из " << k
                    << " нулей подряд нет, вектор не изменён.\n";
            }
            std::cout << "Результат V: ";
            std::copy(numbers.begin(), numbers.end(),
                std::ostream_iterator<int>(std::cout, " "));
            std::cout << '\n';
        }
        else if (choice == 6) {
            std::cout << "\n--- Задача 6.8: инвертирование половин "
                "списков ---\n"
                << "В списке L1 инвертируется первая половина, "
                "в списке L2 - вторая.\nКоличество "
                "элементов в каждом списке кратно 4.\n"
                << "Числа вводите через пробел, например: "
                "1 2 3 4 5 6 7 8\n";

            while (true) {
                std::cout << "Список L1: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                numbers.assign(std::istream_iterator<int>(stream),
                    std::istream_iterator<int>());
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только целые числа "
                        "(не больше 2 млрд по модулю) "
                        "через пробел.\n";
                }
                else if (numbers.empty() || numbers.size() % 4 != 0) {
                    std::cout << "Ошибка: количество чисел должно быть "
                        "кратно 4 и не меньше 4 (введено "
                        << numbers.size() << ").\n";
                }
                else {
                    break;
                }
            }
            std::list<int> l1(numbers.begin(), numbers.end());

            while (true) {
                std::cout << "Список L2: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                numbers.assign(std::istream_iterator<int>(stream),
                    std::istream_iterator<int>());
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только целые числа "
                        "(не больше 2 млрд по модулю) "
                        "через пробел.\n";
                }
                else if (numbers.empty() || numbers.size() % 4 != 0) {
                    std::cout << "Ошибка: количество чисел должно быть "
                        "кратно 4 и не меньше 4 (введено "
                        << numbers.size() << ").\n";
                }
                else {
                    break;
                }
            }
            std::list<int> l2(numbers.begin(), numbers.end());

            ReverseFirstHalf(l1);
            ReverseSecondHalf(l2);

            std::cout << "Результат:\n L1: ";
            std::copy(l1.begin(), l1.end(),
                std::ostream_iterator<int>(std::cout, " "));
            std::cout << "\n L2: ";
            std::copy(l2.begin(), l2.end(),
                std::ostream_iterator<int>(std::cout, " "));
            std::cout << '\n';
        }
        else if (choice == 7) {
            std::cout << "\n--- Задача 7.5: количество чётных "
                "и нечётных чисел ---\n"
                << "Числа вводите через пробел, например: "
                "4 7 -2 9 10\n";

            while (true) {
                std::cout << "Список L: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                numbers.assign(std::istream_iterator<int>(stream),
                    std::istream_iterator<int>());
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только целые числа "
                        "(не больше 2 млрд по модулю) "
                        "через пробел.\n";
                }
                else if (numbers.empty()) {
                    std::cout << "Ошибка: нужно ввести хотя бы одно "
                        "число.\n";
                }
                else {
                    break;
                }
            }
            std::list<int> l(numbers.begin(), numbers.end());

            int even = 0;
            int odd = 0;
            CountEvenAndOdd(l, even, odd);

            std::cout << "Чётных чисел:   " << even << "\n"
                << "Нечётных чисел: " << odd << '\n';
        }
        else if (choice == 8) {
            std::cout << "\n--- Задача 8.1: средние арифметические "
                "пар соседних элементов ---\n"
                << "Из списка L получится вектор V из средних "
                "значений соседних пар.\n"
                << "Числа вводите через пробел (не меньше 2), "
                "например: 1 3 4 6\n";

            while (true) {
                std::cout << "Список L: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                numbers.assign(std::istream_iterator<int>(stream),
                    std::istream_iterator<int>());
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только целые числа "
                        "(не больше 2 млрд по модулю) "
                        "через пробел.\n";
                }
                else if (numbers.size() < 2) {
                    std::cout << "Ошибка: нужно ввести не меньше 2 "
                        "чисел (введено "
                        << numbers.size() << ").\n";
                }
                else {
                    break;
                }
            }
            std::list<int> l(numbers.begin(), numbers.end());

            std::vector<double> v = AdjacentMeans(l);

            std::cout << std::fixed;
            std::cout.precision(1);
            std::cout << "Результат V: ";
            std::copy(v.begin(), v.end(),
                std::ostream_iterator<double>(std::cout, " "));
            std::cout << '\n';
            std::cout.unsetf(std::ios::fixed);
            std::cout.precision(6);
        }
        else if (choice == 9) {
            std::cout << "\n--- Задача 9.2: векторы, содержащие "
                "все элементы V0 ---\n"
                << "Элементы считаются с учётом повторений: "
                "если в V0 двойка встречается\nдважды, то "
                "и в векторе должно быть не меньше двух "
                "двоек.\n"
                << "Числа вводите через пробел, например: "
                "1 2 2 3\n";

            while (true) {
                std::cout << "Вектор V0: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line + '\n');
                numbers.assign(std::istream_iterator<int>(stream),
                    std::istream_iterator<int>());
                if (!stream.eof()) {
                    std::cout << "Ошибка: допустимы только целые числа "
                        "(не больше 2 млрд по модулю) "
                        "через пробел.\n";
                }
                else if (numbers.empty()) {
                    std::cout << "Ошибка: нужно ввести хотя бы одно "
                        "число.\n";
                }
                else {
                    break;
                }
            }
            std::vector<int> v0 = numbers;

            int n = 0;
            while (true) {
                std::cout << "Сколько векторов V1..VN (N > 0)? N = ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line);
                char extra = ' ';
                if ((stream >> n) && !(stream >> extra) && n > 0) {
                    break;
                }
                std::cout << "Ошибка: нужно ввести одно целое число "
                    "больше 0.\n";
            }

            std::vector<std::vector<int>> vectors;
            for (int i = 1; i <= n; ++i) {
                while (true) {
                    std::cout << "Вектор V" << i << ": ";
                    if (!std::getline(std::cin, line)) {
                        return 0;
                    }
                    std::istringstream stream(line + '\n');
                    numbers.assign(std::istream_iterator<int>(stream),
                        std::istream_iterator<int>());
                    if (!stream.eof()) {
                        std::cout << "Ошибка: допустимы только целые "
                            "числа (не больше 2 млрд "
                            "по модулю) через пробел.\n";
                    }
                    else if (numbers.size() < v0.size()) {
                        std::cout << "Ошибка: в векторе не может быть "
                            "меньше элементов, чем в V0 "
                            "(нужно не меньше "
                            << v0.size() << ", введено "
                            << numbers.size() << ").\n";
                    }
                    else {
                        break;
                    }
                }
                vectors.push_back(numbers);
            }

            std::cout << "Векторов, содержащих все элементы V0: "
                << CountVectorsContaining(v0, vectors) << " из "
                << n << '\n';
        }
        else {
            std::cout << "\n--- Задача 10.4: группировка слов "
                "по последней букве ---\n"
                << "Слова вводятся заглавными латинскими "
                "буквами через пробел.\nВнутри группы "
                "слова идут в порядке, обратном исходному.\n"
                << "Пример: CAT DOG BEAT FROG ZEBRA\n";

            std::vector<std::string> words;
            while (true) {
                std::cout << "Слова: ";
                if (!std::getline(std::cin, line)) {
                    return 0;
                }
                std::istringstream stream(line);
                words.assign(std::istream_iterator<std::string>(stream),
                    std::istream_iterator<std::string>());
                bool only_capitals = true;
                for (const std::string& word : words) {
                    for (char c : word) {
                        if (c < 'A' || c > 'Z') {
                            only_capitals = false;
                        }
                    }
                }
                if (words.empty()) {
                    std::cout << "Ошибка: нужно ввести хотя бы одно "
                        "слово.\n";
                }
                else if (!only_capitals) {
                    std::cout << "Ошибка: слова должны состоять только "
                        "из заглавных латинских букв "
                        "(A-Z).\n";
                }
                else {
                    break;
                }
            }

            std::multimap<char, std::string> groups =
                GroupByLastLetter(words);

            std::cout << "Результат (ключ - последняя буква):\n"
                << "Ключ  Слово\n";
            for (const auto& entry : groups) {
                std::cout << entry.first << "    " << entry.second
                    << '\n';
            }
        }
    }
}
