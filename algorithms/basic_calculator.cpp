#include<cstddef>
#include<string>
#include<stdexcept>
#include<iostream>

class BasicCalculator{
private:
  static double getOperand(std::string s, int &i){
    double operand = 0;
    int j = 0;
  	while((s[i]>=48 && s[i]<=57) || s[i]=='.')
  	{
  		if(s[i]=='.')
  		{
  			j=i;
  			i++;
  			continue;
  		}
  		operand = operand*10+s[i]-48;
  		i++;
  	}
  	if(j != 0)
  	{
  		for(int k=0; k<i-j-1; k++){
        operand /= 10;
      }
  	}
  	return operand;
  }

  static double calculate(std::string s, int &i, int state){
    while(s[i] == ' '){
      i++;
    }
    double result = 0;
    if(state == 0){
      result = calculate(s, i, 1);
    }
    else if(s[i] == '('){
      i++;
      result = calculate(s, i, 0);
    }
    else{
      result = getOperand(s, i);
    }
    while(i<s.size()){
      char c = s[i];
      switch(c){
        case '+':
          if(state != 0){
            return result;
          }
          i++;
          result += calculate(s, i, 1);
          break;
        case '-':
          if(state != 0){
            return result;
          }
          i++;
          result -= calculate(s, i, 1);
          break;
        case '*':
          i++;
          result *= getOperand(s, i);
          break;
        case '/':
          i++;
          result /= getOperand(s, i);
          break;
        case ')':
          i++;
          return result;
        default:
          throw std::invalid_argument(std::string("Unknown variable ")+c);
          return result;
      }
    }
    return result;
  }

public:
  static double calculate(std::string s){
    if(s.empty()){
      return 0;
    }
    int i = 0;
    return calculate(s, i, 0);
  }

};

int main(){
  try{
    std::cout<<BasicCalculator::calculate("(23+56)*32+12/3")<<std::endl;
    std::cout<<BasicCalculator::calculate("12+23-12+35*6/3")<<std::endl;
    std::cout<<BasicCalculator::calculate("12.5+34.7+13/6")<<std::endl;
    std::cout<<BasicCalculator::calculate("12+abc*12+12")<<std::endl;
    std::cout<<BasicCalculator::calculate("abc*12+12")<<std::endl;
  }
  catch(const std::invalid_argument& e){
    std::cout<<e.what()<<std::endl;
  }
  return 0;
}
