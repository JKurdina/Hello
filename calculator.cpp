#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPNCalculator {
private:
    std::stack<double> stack;

public:
    double evaluate(const std::string& expression) {
        std::istringstream tokens(expression);
        std::string token;

        while (tokens >> token) {
            if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1]))) {
                stack.push(std::stod(token));  // Число
            } else if (token == "+" || token == "-" || token == "*" || token == "/") {
                if (stack.size() < 2) throw std::runtime_error("Ошибка: Недостаточно операндов");

                double b = stack.top(); stack.pop();
                double a = stack.top(); stack.pop();

                stack.push(calculate(a, b, token));
            } else {
                throw std::runtime_error("Ошибка: Некорректный токен '" + token + "'");
            }
        }

        if (stack.size() != 1) throw std::runtime_error("Ошибка: Некорректное выражение");

        return stack.top();
    }

private:
    // Выполняем операцию
    double calculate(double a, double b, const std::string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") {
            if (b == 0) throw std::runtime_error("Ошибка: Деление на ноль");
            return a / b;
        }
        throw std::runtime_error("Ошибка: Неизвестная операция '" + op + "'");
    }
};

int main() {
    RPNCalculator calculator;
    std::string input;

    std::cout << "Введите выражение в RPN (пример: '3 4 +'):\n> ";
    std::getline(std::cin, input);

    try {
        double result = calculator.evaluate(input);
        std::cout << "Результат: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
