#include "Day1.hpp"
int GetCalibrationValue(const string& line)
{
    map<char, vector<string>> front_alpha_to_digit;
    map<char, vector<string>> reverse_alpha_to_digit;
    map<string, int> front_map;
    map<string, int> reverse_map;

    front_map.insert(make_pair("zero", 0));
    front_map.insert(make_pair("one", 1));
    front_map.insert(make_pair("two", 2));
    front_map.insert(make_pair("three", 3));
    front_map.insert(make_pair("four", 4));
    front_map.insert(make_pair("five", 5));
    front_map.insert(make_pair("six", 6));
    front_map.insert(make_pair("seven", 7));
    front_map.insert(make_pair("eight", 8));
    front_map.insert(make_pair("nine", 9));

    reverse_map.insert(make_pair("orez", 0));
    reverse_map.insert(make_pair("eno", 1));
    reverse_map.insert(make_pair("owt", 2));
    reverse_map.insert(make_pair("eerht", 3));
    reverse_map.insert(make_pair("ruof", 4));
    reverse_map.insert(make_pair("evif", 5));
    reverse_map.insert(make_pair("xis", 6));
    reverse_map.insert(make_pair("neves", 7));
    reverse_map.insert(make_pair("thgie", 8));
    reverse_map.insert(make_pair("enin", 9));
    
    for (auto& digit : front_map)
    {
        front_alpha_to_digit[digit.first[0]].push_back(digit.first);
    }

    for (auto& digit : reverse_map)
    {
        reverse_alpha_to_digit[digit.first[0]].push_back(digit.first);
    }

    int unit_cal_value = 0;
    
    int len_line = line.size();
    string digit_to_check;

    for (int i = 0; i < len_line; i++)
    {
        bool digit_found = false;
        if (!isdigit(line[i]))
        {        
            auto it = front_alpha_to_digit.find(line[i]);
            if (it == front_alpha_to_digit.end()) 
            {
                continue;
            }
            
            for (auto it_digit : it->second)
            {
                digit_to_check = line.substr(i, it_digit.size());
                if (it_digit == digit_to_check)
                {
                    digit_found = true;
                    auto it_digit_found = front_map.find(it_digit);
                    unit_cal_value = 10* it_digit_found->second;
                    break;
                }
            }
        }
        else
        {
            int digit = line[i] - '0';
            unit_cal_value = 10* digit;
            digit_found = true;
            break;
        }
        
        if (digit_found)
        {
            break;
        }
    }

    string reverse_line(line);
    reverse(reverse_line.begin(), reverse_line.end());

    for (int i = 0; i < len_line; i++)
    {
        bool digit_found = false;
        if (!isdigit(reverse_line[i]))
        {        
            auto it = reverse_alpha_to_digit.find(reverse_line[i]);
            if (it == reverse_alpha_to_digit.end()) 
            {
                continue;
            }
            
            for (auto it_digit : it->second)
            {
                digit_to_check = reverse_line.substr(i, it_digit.size());
                if (it_digit == digit_to_check)
                {
                    digit_found = true;
                    auto it_digit_found = reverse_map.find(it_digit);
                    unit_cal_value = unit_cal_value + it_digit_found->second;
                    break;
                }
            }
        }
        else
        {
            int digit = reverse_line[i] - '0';
            unit_cal_value = unit_cal_value + digit;
            digit_found = true;
            break;
        }
        if (digit_found)
        {
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
            cout<<line<<endl;
            cout<<GetCalibrationValue(line)<<endl;
            cal_value = cal_value + GetCalibrationValue(line);
        }
        file.close();
    }

    cout<<cal_value<<endl;

}