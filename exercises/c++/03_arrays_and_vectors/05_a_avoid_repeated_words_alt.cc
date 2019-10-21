#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <chrono>
using namespace std::chrono;

int main()
{
	auto t0 = high_resolution_clock::now();

	std::unordered_set<char> specials;
	// special characters collected in an unordered_set
	specials.insert({' ','\t','\n','"','\'','/','\\','.',','});  
	specials.insert({';',':','!','?','(',')','[',']','{','}'});
	specials.insert({'&','%','<','>','*','#','+','$','^','='});
	
	std::string input;
	std::string space{' '};
	std::vector<std::string> list;
	std::vector<std::string> uniq;
	std::vector<int> count;
	// this implementation uses vectors
	
	while(getline(std::cin, input)){
	
		while(specials.find(input[0])!=specials.end())
			input.erase(input.begin());
			// removes initial special characters
			
		int j{0};
		for (int i = 0; i < (int)input.size(); i++){	
			int k{1};
			if(specials.find(input[i])!=specials.end()){	
				while(specials.find(input[i+k])!=specials.end())
					k++; // if there are adjacent special characters
				list.push_back(input.substr(j,i-j));
				j = i+k;
				i += (k-1);}}}
 				// populates a vector with all the words
 			
		for (int i = 0; i < (int)list.size(); i++){
   			std::transform(list[i].begin(), list[i].end(), list[i].begin(), ::tolower);
   			// upper cases converted to lower cases
   			if(!(std::count(uniq.begin(), uniq.end(), list[i]))){
   				uniq.push_back(list[i]); // populates a vector with singular words
   				count.push_back(1);
   				
   			}else{ 
   			int h{0};
   			while(!(uniq[h].compare(list[i])==0))
   				h += 1;
   			count[h] += 1;}} // updates frequency vector
   	
   	std::cout << "Freq:\t" << "Word:" << std::endl;
    for (int i = 0; i < (int)uniq.size(); i++)
		std::cout << "[" << count[i] << "]\t" << uniq[i] << std::endl;
		// words are printed in the order they are read
		
   	std::cout << "Singular words: " << uniq.size() << std::endl;
   	std::cout << "Total words   : " << list.size() << std::endl;
	
	auto t1 = high_resolution_clock::now();
	auto elapsed = duration_cast<milliseconds>(t1-t0);
	std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;
	
	return 0;
}
