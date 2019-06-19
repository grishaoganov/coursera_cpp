#include <vector>
using namespace std;

class FunctionPart{
public:
    FunctionPart(const char& new_oper, const double& new_value){
        operation = new_oper;
        value = new_value;
    }
    void Invert(){
        if (operation == '-'){
            operation = '+';
        } else if (operation == '+'){
            operation = '-';
        } else if (operation == '*'){
            operation = '/';
        } else if (operation == '/'){
            operation = '*';
        }
    }
    double Apply(double& d) const{
        if (operation == '-'){
            return d - value;
        } else if (operation == '+'){
            return d + value;
        } else if (operation == '*'){
            return d * value;
        } else if (operation == '/'){
            return d / value;
        }
    }
private:
    char operation;
    double value;
};

class Function{
public:
    double Apply(double value) const{
        for (const FunctionPart& item : parts){
            value = item.Apply(value);
        }
        return value;
    }
    void AddPart(const char& new_oper, const double& new_value){
        parts.push_back({new_oper, new_value});
    }
    void Invert(){
        for (FunctionPart& item : parts){
            item.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};