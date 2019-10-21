#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <chrono>
#include <map>
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
	std::map<std::string,int> mp;
	std::map<std::string, int>::iterator ptr;
	// this implementation uses maps
	
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
			i += (k-1);}}} // populates a vector with all the words
	
	for (int i = 0; i < (int)list.size(); i++){
   		std::transform(list[i].begin(), list[i].end(), list[i].begin(), ::tolower);
   		// upper cases converted to lower cases  
   		ptr = mp.find(list[i]); 
   		if(!(ptr != mp.end()))
   			mp.insert(std::pair<std::string,int>(list[i],1)); // populates map
		else
   			mp[list[i]] += 1;} // updates map

   	std::cout << "Freq:\t" << "Word:" << std::endl;
   	for(auto itr = mp.begin(); itr!=mp.end(); itr++)
        std::cout << '[' << itr->second << "]\t" << itr->first << std::endl;
        // words are printed in alphabetical the order
    
    std::cout << "Singular words: " << mp.size() << std::endl;
    std::cout << "Total words   : " << list.size() << std::endl;
   			
	auto t1 = high_resolution_clock::now();
	auto elapsed = duration_cast<milliseconds>(t1-t0);
	std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;
	
	return 0;
}
