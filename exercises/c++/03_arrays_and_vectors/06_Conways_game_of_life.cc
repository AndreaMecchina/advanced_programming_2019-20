#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <thread>

int main(int argc, char* argv[]){

	int a{17},b{17};
	char m[a][b];
	char t[a][b];
	char live{'#'};
	char dead{'.'};
	
	// matrix initialization
	for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
    	m[i][j]=dead;}}
    
    // glider 17x17
    
    m[4][6]=live;		
    m[4][7]=live;
    m[4][8]=live;
    m[2][7]=live;
    m[3][8]=live;
    
    /*
    // pulsar 17x17
   	m[2][4]=live;	m[2][5]=live;
   	m[2][6]=live;	m[2][10]=live;
   	m[2][11]=live;	m[2][12]=live;
   
   	m[7][4]=live;	m[7][5]=live;
   	m[7][6]=live;	m[7][10]=live;
   	m[7][11]=live;	m[7][12]=live;
   
   	m[9][4]=live;	m[9][5]=live;
   	m[9][6]=live;	m[9][10]=live;
   	m[9][11]=live;	m[9][12]=live;
   
   	m[14][4]=live;	m[14][5]=live;
   	m[14][6]=live;	m[14][10]=live;
   	m[14][11]=live;	m[14][12]=live;
   
   	m[4][2]=live;	m[5][2]=live;
   	m[6][2]=live;	m[10][2]=live;
   	m[11][2]=live;	m[12][2]=live;
   
   	m[4][7]=live;	m[10][7]=live;
   	m[5][7]=live;	m[11][7]=live;
   	m[6][7]=live;	m[12][7]=live;
   		
   	m[4][9]=live;	m[10][9]=live;
   	m[5][9]=live;	m[11][9]=live;
   	m[6][9]=live;	m[12][9]=live;
   	
   	m[4][14]=live;	m[10][14]=live;
   	m[5][14]=live;	m[11][14]=live;
   	m[6][14]=live;	m[12][14]=live;
   	*/
   	
	for (int i = 0; i < a; i++){
   	for (int j = 0; j < b; j++)
    	std::cout << std::setw(3) << m[i][j];
   		std::cout << std::endl;}

	// iterations number read from command line
 	std::istringstream s{argv[1]};
  	int it; s >> it;
	
	for(int k = 0; k < it; k++){

		for (int i = 0; i < a; i++){
   		for (int j = 0; j < b; j++){
   	
   			std::vector<char> adj{};
			for(int ystep = -1; ystep < 2; ystep++){
   				int y{i};
				y += ystep;
				// periodic boundary conditions
   				while(y < 0) y += a;
    			while(y >= a) y -= a;
    			
   			for(int xstep = -1; xstep < 2; xstep++){
				int x{j};
   				x += xstep;	
   				// periodic boundary conditions
    			while(x < 0) x += b;
    			while(x >= b) x -= b;
    			
        		adj.push_back(m[y][x]);}}
				// gets the neighbours
   		adj.erase (adj.begin()+4);
   				
   		// t[i][j] stores the number of 
   	   	// life cells adjacent m[i][j]
   		int count{0};
        for (auto i =0ul; i < adj.size(); i++){
   	    	if(adj[i]==live)
   	     	count += 1;}
   	   	t[i][j]=count;}}
 
 	// updating rules
   	for(int i = 0; i < a; i++){
   	for(int j = 0; j < b; j++){
   		if(m[i][j]==live && (t[i][j]==2 || t[i][j]==3)){m[i][j]=live;}
   		else if(m[i][j]==dead && t[i][j]==3){m[i][j]=live;}
   		else{m[i][j]=dead;}}}
   			
   	std::cout << "\n\n\n\n\n\n\n\n\n"
   				 "\n\n\n\n\n\n\n\n\n"
   				 "\n\n\n\n\n\n\n\n\n"
   				 "\n\n\n\n\n\n\n\n\n" << std::endl; 
   					
   	// prints updated matrix
   	for (int i = 0; i < a; i++){
   	for (int j = 0; j < b; j++)
     	std::cout << std::setw(3) << m[i][j];
   		std::cout << std::endl;}
   		
   	std::this_thread::sleep_for (std::chrono::milliseconds(50));}
   	
    return 0;
}