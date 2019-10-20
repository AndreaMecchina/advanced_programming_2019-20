#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main()
{	
	std::unordered_set<char> specials;
	// special characters collected in an unordered_set
	specials.insert({' ','\t','\n','"','\'','/','\\','.',','});  
	specials.insert({';',':','!','?','(',')','[',']','{','}'});
	specials.insert({'&','%','<','>','*','#','+','$','^','='});
	
	std::string input;
	std::string space{' '};
	std::vector<std::string> list;
	std::vector<std::string> uniq;
	
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
			i += (k-1);
			}
		}
	} // populates a vector with all the words
	std::cout << "Total words: " << list.size() << std::endl;
	
	for (int i = 0; i < (int)list.size(); i++){
   		std::transform(list[i].begin(), list[i].end(), list[i].begin(), ::tolower);
   		// upper cases converted to lower cases
   		if(!(std::count(uniq.begin(), uniq.end(), list[i])))
   			uniq.push_back(list[i]);
   	} // if a word is non-repeated is pushed into uniq
   	
   	std::cout << "Words without repetitions: " << std::endl;
    for (int i = 0; i < (int)uniq.size(); i++)
		std::cout << "[" << i+1 << "] " << uniq[i] << std::endl;
		// words are printed in the order they are read
	
	return 0;
}