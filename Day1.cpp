#include "Day1.hpp"
int GetCalibrationValue(const string& line)
{
    int unit_cal_value = 0;
    
    int len_line = line.size();

    for (int i = 0; i < len_line; i++)
    {
        if (isdigit(line[i]))
        {
            int digit = line[i] - '0';
            unit_cal_value = 10* digit;
            break;
        }
    }

    for (int i = len_line-1; i >= 0; i--)
    {
        if (isdigit(line[i]))
        {
            int digit = line[i] - '0';
            unit_cal_value = unit_cal_value + digit;
            break;
        }
    }

    return unit_cal_value;
}


int main()
{
    int cal_value = 0;

    string line;
    std::ifstream file("Day1_input.txt");

    if (file.is_open()) 
    {
        while (std::getline(file, line)) 
        {
            cal_value = cal_value + GetCalibrationValue(line);
        }
        file.close();
    }

    cout<<cal_value<<endl;

}