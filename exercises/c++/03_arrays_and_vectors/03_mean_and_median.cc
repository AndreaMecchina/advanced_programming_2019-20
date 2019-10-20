#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	std::vector<double> temp;
	
	double i;
	while(std::cin >> i){
	
		temp.push_back(i);
		
	} // populates the vector with values read from file
	
	double sum{0};
	for(auto j = 0u; j < temp.size(); ++j){
	
		sum += temp[j]; 
		
	} // accumulates values
	std::cout << "Mean temperature: " << sum/temp.size() << std::endl;
	
	std::sort(temp.begin(),temp.end());
	if(temp.size()%2==0){ // median is computed differently if the size is even or odd
	
		double median{0.5*(temp[temp.size()/2]+temp[temp.size()/2-1])};
		std::cout << "Median temperature: " << median << std::endl;
		
	} else {
	
		double median{temp[(temp.size()-1)/2]};
		std::cout << "Median temperature: " << median << std::endl;
		
	}
	
	return 0;
}
