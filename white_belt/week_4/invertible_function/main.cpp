#include <iostream>
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

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
    Function function;
    function.AddPart('*', params.a);
    function.AddPart('-', image.freshness * params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

int main() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 52) << endl;
    return 0;
}