class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double>results;
        results.push_back(celsius+273.15);
        results.push_back(celsius * 1.80 +32.00);
    return results;
}
};