//Jan Skwarczek

#include <iostream>

unsigned long long allgoods = 0;

struct Place{
	
	unsigned short int amount;
	char label[2];
	
	void clean(){
		
		label[0] = 0;
		label[1] = 0;
		
		allgoods = allgoods - amount;
		amount = 0;
		
	}
	
};

struct Shelf{
	
	Place places[128];
	unsigned short int placenumber;
	
	void clean(unsigned short int a, unsigned short int b){
		
		for(int i=a; i<b; i++){
			
			places[i].clean();

		}
		
	}
	
};

struct Rack{
	
	Shelf shelves[128];
	unsigned short int shelfnumber;
	
	void clean(unsigned short int a, unsigned short int b){
		
		for(int i=a; i<b; i++){
			
			shelves[i].clean(0, 128);
			
		}
		
	}
	
};

struct Warehouse{
	
	Rack racks[128];
	unsigned short int racknumber;
	Shelf warehandyshelf;
	
	void clean(unsigned short int a, unsigned short int b){
		
		for(int i=a; i<b; i++){
			
			racks[i].clean(0, 128);		
			
		}
		
	}
	
};

struct Storehouse{
	
	Warehouse warehouses[128];
	unsigned short int warenumber;
	Rack storehandyrack;
	Shelf storehandyshelf;
	
	void clean(unsigned short a, unsigned short b){
		
		for(int i=a; i<b; i++){
			
			warehouses[i].clean(0, 128);		
			
		}
		
	}

	void SET_AP(unsigned short int wb, unsigned short int rb, unsigned short int sb, unsigned short int Pe){
		
		if(wb>=warenumber || rb>=warehouses[wb].racknumber || sb>=warehouses[wb].racks[rb].shelfnumber) std::cout << "error" << std::endl;
		
		else{
			
			unsigned short int oldnumber = warehouses[wb].racks[rb].shelves[sb].placenumber;
			warehouses[wb].racks[rb].shelves[sb].clean(Pe, oldnumber);
			warehouses[wb].racks[rb].shelves[sb].placenumber = Pe;
			
		}
		
	}
	
	void SET_AS(unsigned short int wb, unsigned short int rb, unsigned short Se, unsigned short int Pe){
		
		if(wb>=warenumber || rb>=warehouses[wb].racknumber) std::cout << "error" << std::endl;
		
		else{
			
			unsigned short int oldnumber = warehouses[wb].racks[rb].shelfnumber;
			warehouses[wb].racks[rb].clean(Se, oldnumber);
			warehouses[wb].racks[rb].shelfnumber = Se;
			
			for(int i=0; i<Se; i++){
				
				SET_AP(wb,rb,i,Pe);
				
			}
			
		}
		
	}

	void SET_AR(unsigned short int wb, unsigned short int Re, unsigned short Se, unsigned short int Pe){

		if(wb>=warenumber) std::cout << "error" << std::endl;

		else{

			unsigned short int oldnumber = warehouses[wb].racknumber;
			warehouses[wb].clean(Re, oldnumber);
			warehouses[wb].racknumber = Re;
			
			for(int i=0; i<Re; i++){
				
				SET_AS(wb, i, Se, Pe);
				
			}

		}
		
	}
	
	void SET_AW(unsigned short int We, unsigned short int Re, unsigned short Se, unsigned short int Pe){
		
		unsigned short int oldnumber = warenumber;
		clean(We, oldnumber);
		warenumber = We;
			
		for(int i=0; i<We; i++){
				
			SET_AR(i, Re, Se, Pe);
				
		}
		
	}
	
	void SET_HW(unsigned short int w, unsigned short int P){
		
		if(w>=warenumber) std::cout << "error" << std::endl;
		
		else{
			
			unsigned short int oldnumber = warehouses[w].warehandyshelf.placenumber;
			warehouses[w].warehandyshelf.clean(P, oldnumber);
			warehouses[w].warehandyshelf.placenumber = P;
			
		}
	}
	
	void SET_HR(unsigned short S, unsigned short P){
		
		int oldnumber = storehandyrack.shelfnumber;
		storehandyrack.clean(S, oldnumber);
		storehandyrack.shelfnumber = S;
		
		for(int i = 0; i<S; i++){
			oldnumber = storehandyrack.shelves[i].placenumber;
			storehandyrack.shelves[i].clean(P, oldnumber);
			storehandyrack.shelves[i].placenumber = P;
		}
	}
	
	void SET_HS(unsigned short int P){
		
		unsigned short int oldnumber = storehandyshelf.placenumber;
		storehandyshelf.clean(P, oldnumber);
		storehandyshelf.placenumber = P;	
	}
	
	void PUT_W(unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p, long long A){
		
		if(w>=warenumber || r>=warehouses[w].racknumber || s>=warehouses[w].racks[r].shelfnumber || p>=warehouses[w].racks[r].shelves[s].placenumber) std::cout << "error" << std::endl;
		
		else{
			
			long long n = warehouses[w].racks[r].shelves[s].places[p].amount + A;
			
			if(n>65535){
				
				n = 65535;
				allgoods += 65535 - warehouses[w].racks[r].shelves[s].places[p].amount;
			}
			
			else{
			
				allgoods += A;
			}
			warehouses[w].racks[r].shelves[s].places[p].amount = n;
		}	
		
		
	}
	
	void PUT_H(unsigned short int w, unsigned short int p, long long A){
		
		if(w>=warenumber || p>=warehouses[w].warehandyshelf.placenumber) std::cout << "error" << std::endl;
		
		else{
			
			long long n = warehouses[w].warehandyshelf.places[p].amount + A;
			
			if(n>65535){
				
				n = 65535;
				allgoods += 65535 - warehouses[w].warehandyshelf.places[p].amount;
			}
			
			else{
				
				allgoods += A;
				
			}
			warehouses[w].warehandyshelf.places[p].amount = n;
		}
		
		
	}
	
	void PUT_R(unsigned short s, unsigned short p, long long A){
		
		if(s>=storehandyrack.shelfnumber || p>=storehandyrack.shelves[s].placenumber) std::cout << "error" << std::endl;
		
		else{
			
			long long n = storehandyrack.shelves[s].places[p].amount + A;
			
			if(n>65535){
				
				n = 65535;
				allgoods += 65535 - storehandyrack.shelves[s].places[p].amount;
			}
			
			else{
				
				allgoods += A;
				
			}
			storehandyrack.shelves[s].places[p].amount = n;
		}
	};
	
	void PUT_S(unsigned short int p, long long A){
		
		if(p>=storehandyshelf.placenumber) std::cout << "error" << std::endl;
		
		else{
			
			long long n = storehandyshelf.places[p].amount + A;
			
			if(n>65535){
				
				n = 65535;
				allgoods += 65535 - storehandyshelf.places[p].amount;
			}
			
			else{
				
				allgoods += A;
				
			}
			storehandyshelf.places[p].amount = n;
		}
		
	}
	
	void FILL(unsigned short int W, unsigned short int R, unsigned short int S, unsigned short int P, long long A){
		
		clean(0, warenumber);
		storehandyshelf.clean(0,128);
		storehandyrack.clean(0,128);
		
		SET_AW(W, R, S, P);
		SET_HR(S, P);
		SET_HS(P);
		
		for(int i=0; i<W; i++){
			for(int j=0; j<R; j++){
				for(int k=0; k<S; k++){
					for(int l=0; l<P; l++){
						
						PUT_W(i,j,k,l,A);
						
					}			
				}
			}
		}
		
		for(int i=0; i<W; i++){
		
			warehouses[i].warehandyshelf.clean(0, 128);	
			SET_HW(i, P);
				
			for( int j=0; j<P; j++){
				PUT_H(i,j,A);
			}
		}
					
		for(int i=0; i<S; i++){
			for(int j=0; j<P; j++){	
				PUT_R(i,j,A);
			}
		}
			
		for( int i=0; i<P; i++){
			PUT_S(i, A);
		}
	
	}
	
	void POP_W(unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p, long long A){
		
		if(w>=warenumber || r>=warehouses[w].racknumber || s>=warehouses[w].racks[r].shelfnumber || p>=warehouses[w].racks[r].shelves[s].placenumber) std::cout << "error" << std::endl;
		
		else{
			
			long long n = warehouses[w].racks[r].shelves[s].places[p].amount - A;
			
			if(n<=0){
				
				n = 0;
				allgoods -= warehouses[w].racks[r].shelves[s].places[p].amount;
			}
			
			else allgoods -= A;
			
			warehouses[w].racks[r].shelves[s].places[p].amount = n;	
		}
		
	}
	
	void POP_H(unsigned short int w, unsigned short int p, long long A){
		
		if(w>=warenumber || p>=warehouses[w].warehandyshelf.placenumber) std::cout << "error" << std::endl;
		
		else{
			
			long long n = warehouses[w].warehandyshelf.places[p].amount - A;
			
			if(n<=0){
				n = 0;
				allgoods -= warehouses[w].warehandyshelf.places[p].amount;
			}
			
			else allgoods -= A;
			
			warehouses[w].warehandyshelf.places[p].amount = n;
		}					
		
	}
	
	void POP_R(unsigned short int s, unsigned short int p, long long A){
		
		if(s>=storehandyrack.shelfnumber || p>=storehandyrack.shelves[s].placenumber) std::cout << "error" << std::endl;
		
		else{
			
			long long n = storehandyrack.shelves[s].places[p].amount - A;
			
			if(n<=0){
				n = 0;
				allgoods -= storehandyrack.shelves[s].places[p].amount;
			}
			
			else allgoods -= A;
				
			storehandyrack.shelves[s].places[p].amount = n;
		}
		
	}
	
	void POP_S(unsigned short int p, long long A){
		
		if(p>=storehandyshelf.placenumber) std::cout << "error" << std::endl;
		
		else{
			
			long long n = storehandyshelf.places[p].amount - A;
			
			if(n<=0){
				n = 0;
				allgoods -= storehandyshelf.places[p].amount;
			}
			
			else allgoods -= A;
			
			storehandyshelf.places[p].amount = n;
		}
		
	}
	
	void MOV_W(unsigned short int wb, unsigned short int rb, unsigned short int sb, unsigned short int we, unsigned short int re, unsigned short int se, unsigned short int p, long long A){
		
		long long temp;
		
		if(wb>=warenumber || rb>=warehouses[wb].racknumber || sb>=warehouses[wb].racks[rb].shelfnumber || we>=warenumber || re>=warehouses[we].racknumber || se>=warehouses[we].racks[re].shelfnumber || p>=warehouses[we].racks[re].shelves[se].placenumber || p>=warehouses[wb].racks[rb].shelves[sb].placenumber) std::cout << "error" << std::endl;
		
		else{
			
			if(wb!=we || rb!=re || sb!=se){
				
				long long tempWb = warehouses[wb].racks[rb].shelves[sb].places[p].amount;
				long long tempWe = warehouses[we].racks[re].shelves[se].places[p].amount;
				long long tempA = A;
				
				if(tempWb - A<0) tempA = warehouses[wb].racks[rb].shelves[sb].places[p].amount;
				
				else tempA = A;
						
				if(tempWe + tempA>65535) tempA = 65535 - warehouses[we].racks[re].shelves[se].places[p].amount;
		
				warehouses[wb].racks[rb].shelves[sb].places[p].amount = tempWb - tempA;
				warehouses[we].racks[re].shelves[se].places[p].amount = tempWe + tempA;
			}
		}
		
	}
	
	void MOV_H(unsigned short int w, unsigned short int r, unsigned short int s, unsigned short int p, long long A){
		
		long long temp;
		
		if(w>=warenumber || r>=warehouses[w].racknumber || s>=warehouses[w].racks[r].shelfnumber || p>=warehouses[w].racks[r].shelves[s].placenumber) std::cout << "error" << std::endl;
		
		else{
			
			long long tempWb = warehouses[w].racks[r].shelves[s].places[p].amount;
			long long tempH = warehouses[w].warehandyshelf.places[p].amount;
			long long tempA = A;
		
			if(tempWb - A<0) tempA = warehouses[w].racks[r].shelves[s].places[p].amount;
			
			else tempA = A;
					
			if(tempH + tempA>65535) tempA = 65535 - warehouses[w].warehandyshelf.places[p].amount;
				
			warehouses[w].racks[r].shelves[s].places[p].amount = tempWb - tempA;
			warehouses[w].warehandyshelf.places[p].amount = tempH + tempA;
		}
	}
	
	void MOV_R(unsigned short int w, unsigned short int r, unsigned short int sb, unsigned short int se, unsigned short int p, long long A){
		
		long long temp;
		
		if(w>=warenumber || r>=warehouses[w].racknumber || sb>=warehouses[w].racks[r].shelfnumber || se>=storehandyrack.shelfnumber || p>=warehouses[w].racks[r].shelves[sb].placenumber || p>=storehandyrack.shelves[se].placenumber) std::cout << "error" << std::endl;
		
		else{
			
			long long tempWb = warehouses[w].racks[r].shelves[sb].places[p].amount;
			long long tempR = storehandyrack.shelves[se].places[p].amount ;
			long long tempA = A;
		
			if(tempWb - A<0) tempA = warehouses[w].racks[r].shelves[sb].places[p].amount;
			else tempA = A;
					
			if(tempR + tempA>65535) tempA = 65535 - storehandyrack.shelves[se].places[p].amount;
				
			warehouses[w].racks[r].shelves[sb].places[p].amount = tempWb - tempA;
			storehandyrack.shelves[se].places[p].amount = tempR + tempA;
			
		}
		
	}
	
	void MOV_S(unsigned short int s, unsigned short int p, long long A){
		
		long long temp;
		
		if(s>=storehandyrack.shelfnumber || p>=storehandyrack.shelves[s].placenumber) std::cout << "error" << std::endl;
		
		else{
			
			long long tempR = storehandyrack.shelves[s].places[p].amount;
			long long tempS = storehandyshelf.places[p].amount;
			long long tempA = A;
		
			if(tempR - A<0) tempA = storehandyrack.shelves[ s ].places[ p ].amount ;
			
			else tempA = A;
					
			if(tempS + tempA>65535) tempA = 65535 - storehandyshelf.places[p].amount;
				
			storehandyrack.shelves[s].places[p].amount = tempR - tempA;
			storehandyshelf.places[p].amount = tempS + tempA;
		}
	}
	
	void GET_E(){
		
		std::cout << allgoods << std::endl;
	}
	
	void GET_W(unsigned short int w){
		
		unsigned long long goods = 0;
		
		if(w>=warenumber) std::cout << "error" << std::endl;
		
		else{
			
			for(int i = 0; i<warehouses[w].racknumber; i++){
				for(int j=0; j<warehouses[w].racks[i].shelfnumber; j++){
					for(int k=0; k<warehouses[w].racks[i].shelves[j].placenumber; k++){
						
						goods = goods + warehouses[w].racks[i].shelves[j].places[k].amount;
						
					}
				}
			}
			
			for(int i=0; i<warehouses[w].warehandyshelf.placenumber; i++){
				
				goods = goods + warehouses[w].warehandyshelf.places[i].amount;
				
			}
			
			std::cout << goods << std::endl;
			
		}
		
	}
	
	void GET_RW(unsigned short int w, unsigned short int r){
		
		unsigned long long goods = 0;
		
		if(w>=warenumber || r>=warehouses[w].racknumber) std::cout << "error" << std::endl;
		
		else{
			
			for(int i=0; i<warehouses[w].racks[r].shelfnumber; i++){
				for(int j=0; j<warehouses[w].racks[r].shelves[i].placenumber; j++){
					
					goods = goods + warehouses[w].racks[r].shelves[i].places[j].amount;
					
				}
			}
			
			std::cout << goods << std::endl;
			
		}
		
	}
	
	void GET_RH(){
		
		unsigned long long goods = 0;
		
		for(int i=0; i<storehandyrack.shelfnumber; i++){
			for(int j=0; j<storehandyrack.shelves[i].placenumber; j++){
				
				goods += storehandyrack.shelves[i].places[j].amount;
				
			}
		}
		
		std::cout << goods << std::endl;
		
	}
	
	void GET_SW(unsigned short w, unsigned short r, unsigned short s){
		
		unsigned long long goods = 0;
		
		if(w>=warenumber || r>=warehouses[w].racknumber || s>=warehouses[w].racks[r].shelfnumber) std::cout << "error" << std::endl;
		
		else{
		
			for(int i=0; i<warehouses[w].racks[r].shelves[s].placenumber; i++)
				goods += warehouses[w].racks[r].shelves[s].places[i].amount;
			
			std::cout << goods << std::endl;
		}
		
	}
	
	void GET_SH(unsigned short w){
		
		unsigned long long goods = 0;
		
		if(w>=warenumber) std::cout << "error" << std::endl;
		
		else{
			
			for(int i=0; i<warehouses[w].warehandyshelf.placenumber; i++)
				goods += warehouses[w].warehandyshelf.places[i].amount;
				
			std::cout << goods << std::endl;
			
		}
		
	}
	
	void GET_SR(unsigned short s){
		
		unsigned long long goods = 0;
		
		if(s>=storehandyrack.shelfnumber) std::cout << "error" << std::endl;
		
		else{
			
			for(int i=0; i<storehandyrack.shelves[s].placenumber; i++)
				goods += storehandyrack.shelves[s].places[i].amount;
				
			std::cout << goods << std::endl;
		}
		
	}
	
	void GET_S(){
		
		unsigned long long goods = 0;
		
		for(int i=0; i<storehandyshelf.placenumber; i++)
			goods += storehandyshelf.places[i].amount;
		
		std::cout << goods << std::endl;
	}
	
	void SET_LW(unsigned short w, unsigned short r, unsigned short s, unsigned short p, char dd[]){
		
		if(w>=warenumber || r>=warehouses[w].racknumber || s>=warehouses[w].racks[r].shelfnumber || p>=warehouses[w].racks[r].shelves[s].placenumber) std::cout << "error" <<std::endl;
		
		else{
			
			warehouses[w].racks[r].shelves[s].places[p].label[0] = dd[0];
			warehouses[w].racks[r].shelves[s].places[p].label[1] = dd[1];
		}
	}
	
	void SET_LH(unsigned short w, unsigned short p, char dd[]){
		
		if(w>=warenumber || p>=warehouses[w].warehandyshelf.placenumber) std::cout << "error" << std::endl;
		
		else{
			
			warehouses[w].warehandyshelf.places[p].label[0] = dd[0];
			warehouses[w].warehandyshelf.places[p].label[1] = dd[1];
		}
	}
	
	void SET_LR(unsigned short s, unsigned short p, char dd[]){
		
		if(s>=storehandyrack.shelfnumber || p>=storehandyrack.shelves[s].placenumber) std::cout << "error" << std::endl;
		
		else{
			
			storehandyrack.shelves[s].places[p].label[0] = dd[0];
			storehandyrack.shelves[s].places[p].label[1] = dd[1];	
		}
	}
	
	void SET_LS(unsigned short p, char dd[]){
		
		if(p>=storehandyshelf.placenumber) std::cout << "error" << std::endl;
		
		else{
			
			storehandyshelf.places[p].label[0] = dd[0];
			storehandyshelf.places[p].label[1] = dd[1];
		}
	}
	
	void GET_LW(unsigned short w, unsigned short r, unsigned short s, unsigned short p){
		
		if(w>=warenumber || r>=warehouses[w].racknumber || s>=warehouses[w].racks[r].shelfnumber || p>=warehouses[w].racks[r].shelves[s].placenumber) std::cout << "error" <<std::endl;
		
		else{

			if(warehouses[w].racks[r].shelves[s].places[p].label[0] == 0 && warehouses[w].racks[r].shelves[s].places[p].label[1] == 0)
				std::cout << "--" << std::endl;
				
			else{
				
				std::cout << warehouses[w].racks[r].shelves[s].places[p].label[0] << warehouses[w].racks[r].shelves[s].places[p].label[1] << std::endl;
			}		
		}
	}
	
	void GET_LH(unsigned short w, unsigned short p){
		
		if(w>=warenumber || p>=warehouses[w].warehandyshelf.placenumber) std::cout << "error" << std::endl;
		
		else{
			
			if(warehouses[w].warehandyshelf.places[p].label[0] == 0 && warehouses[w].warehandyshelf.places[p].label[1] == 0)
				std::cout << "--" << std::endl;
				
			else{
				
				std::cout << warehouses[w].warehandyshelf.places[p].label[0] << warehouses[w].warehandyshelf.places[p].label[1] << std::endl;
			}
		}
	}
	
	void GET_LR(unsigned short s, unsigned short p){
		
		if(s>=storehandyrack.shelfnumber || p>=storehandyrack.shelves[s].placenumber) std::cout << "error" << std::endl;
		
		else{
			
			if(storehandyrack.shelves[s].places[p].label[0] == 0 && storehandyrack.shelves[s].places[p].label[1] == 0)
				std::cout << "--" << std::endl;
				
			else{
				
				std::cout << storehandyrack.shelves[s].places[p].label[0] << storehandyrack.shelves[s].places[p].label[1] << std::endl;
			}
		}
	}
	
	void GET_LS(unsigned short p){
		
		if(p>=storehandyshelf.placenumber) std::cout << "error" << std::endl;
		
		else{
			
			if(storehandyshelf.places[p].label[0] == 0 && storehandyshelf.places[p].label[1] == 0)
				std::cout << "--" << std::endl;
				
			else{
				
				std::cout << storehandyshelf.places[p].label[0] << storehandyshelf.places[p].label[1] << std::endl;
			}
		}
	}

};

Storehouse store;

int main(){
	
	std::string order;
	
	do{
		std::cin >> order;
		
		if(order == "SET-AP"){
			
			int wb, rb, sb, Pe;
			std::cin >> wb >> rb >> sb >> Pe;
			
			if(wb>=0 && rb>=0 && sb>=0 && Pe>=0 && wb<=127 && rb<=127 && sb<=127 && Pe<=128) store.SET_AP(wb,rb,sb,Pe);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "SET-AS"){
			
			
			int wb, rb, Se, Pe;
			std::cin >> wb >> rb >> Se >> Pe;
			
			if(wb>=0 && rb>=0 && Se>=0 && Pe>=0 && wb<=127 && rb<=127 && Se<=128 && Pe<=128) store.SET_AS(wb,rb,Se,Pe);		
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "SET-AR"){
			
			int wb, Re, Se, Pe;
			std::cin >> wb >> Re >> Se >> Pe;
			
			if(wb>=0 && Re>=0 && Se>=0 && Pe>=0 && wb<=127 && Re<=128 && Se<=128 && Pe<=128) store.SET_AR(wb,Re,Se,Pe);		
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "SET-AW"){
			
			int We, Re, Se, Pe;
			std::cin >> We >> Re >> Se >> Pe;
			
			if(We>=0 && We>=0 && Se>=0 && Pe>=0 && We<=128 && Re<=128 && Se<=128 && Pe<=128) store.SET_AW(We,Re,Se,Pe);		
		
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "SET-HW"){
			
			int w, P;
			std::cin >> w >> P;
			
			if(w>=0 && P>=0 && w<=127 && P<=128) store.SET_HW(w,P);		
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "SET-HR"){
			
			int S, P;
			std::cin >> S >> P;
			
			if(S>=0 && P>=0 && S<=128 && P<=128) store.SET_HR(S,P);		
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "SET-HS"){
			
			int P;
			std::cin >> P;
			
			if(P>=0 && P<=128) store.SET_HS(P);		
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "PUT-W"){
			
			int w, r, s, p;
			long long A;
			std::cin >> w >> r >> s >> p >> A;
			
			if(w>=0 && r>=0 && s>=0 && p>=0 && w<=127 && r<=127 && s<=127 && p<=127) store.PUT_W(w,r,s,p,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "PUT-H"){
			
			int w, p;
			long long A;
			std::cin >> w >> p >> A;
			
			if(w>=0 && p>=0 && w<=127 && p<=127) store.PUT_H(w,p,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "PUT-R"){
			
			int s, p;
			long long A;
			std::cin >> s >> p >> A;
			
			if(s>=0 && p>=0 && s<=127 && p<=127) store.PUT_R(s,p,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "PUT-S"){
			
			int p;
			long long A;
			std::cin >> p >> A;
			
			if(p>=0 && p<=127) store.PUT_S(p,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "FILL"){
			
			int W, R, S, P;
			long long A;
			std::cin >> W >> R >> S >> P >> A;
			
			if(W>=0 && R>=0 && S>=0 && P>=0 && W<=128 && R<=128 && S<=128 && P<=128) store.FILL(W,R,S,P,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "POP-W"){
			
			int w, r, s, p;
			long long A;
			std::cin >> w >> r >> s >> p >> A;
			
			if(w>=0 && r>=0 && s>=0 && p>=0 && w<=127 && r<=127 && s<=127 && p<=127) store.POP_W(w,r,s,p,A);
		
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "POP-H"){
			
			int w, p;
			long long A;
			std::cin >> w >> p >> A;
			
			if(w>=0 && p>=0 && w<=127 && p<=127) store.POP_H(w,p,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "POP-R"){
			
			int s, p;
			long long A;
			std::cin >> s >> p >> A;
			
			if(s>=0 && p>=0 && s<=127 && p<=127) store.POP_R(s,p,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "POP-S"){
			
			int p;
			long long A;
			std::cin >> p >> A;
			
			if(p>=0 && p<=127) store.POP_S(p,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "MOV-W"){
			
			int wb, rb, sb, we, re, se, p;
			long long A;
			std::cin >> wb >> rb >> sb >> we >> re >> se >> p >> A;
			
			if(wb>=0 && rb>=0 && sb>=0 && we>=0 && re>=0 && se>=0 && p>=0 && wb<=127 && rb<=127 && sb<=127 && we<=127 && re<=127 && se<=127 && p<=127) store.MOV_W(wb,rb,sb,we,re,se,p,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "MOV-H"){
			
			int w, r, s, p;
			long long A;
			std::cin >> w >> r >> s >> p >> A;
			
			if(w>=0 && r>=0 && s>=0 && p>=0 && w<=127 && r<=127 && s<=127 && p<=127) store.MOV_H(w,r,s,p,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "MOV-R"){
			
			int w, r, sb, se, p;
			long long A;
			std::cin >> w >> r >> sb >> se >> p >> A;
			
			if(w>=0 && r>=0 && sb>=0 && se>=0 && p>=0 && w<=127 && r<=127 && sb<=127 && se<=127 && p<=127) store.MOV_R(w,r,sb,se,p,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "MOV-S"){
			
			int s, p;
			long long A;
			std::cin >> s >> p >> A;
			
			if(s>=0 && p>=0 && s<=127 && p<=127) store.MOV_S(s,p,A);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "GET-E"){
			
			store.GET_E();
		}
		
		else if(order == "GET-W"){
			
			int w;
			std::cin >> w;
			
			if(w>=0 && w<=127) store.GET_W(w);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "GET-RW"){
			
			int w, r;
			std::cin >> w >> r;
			
			if(w>=0 && r>=0 && w<=127 && r<=127) store.GET_RW(w,r);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "GET-RH"){
			
			store.GET_RH();
		}
		
		else if(order == "GET-SW"){
			
			int w, r, s;
			std::cin >> w >> r >> s;
			
			if(w>=0 && r>=0 && s>=0 && w<=127 && r<=127 && s<=127) store.GET_SW(w,r,s);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "GET-SH"){
			
			int w;
			std::cin >> w;
			
			if(w>=0 && w<=127) store.GET_SH(w);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "GET-SR"){
			
			int s;
			std::cin >> s;
			
			if(s>=0 && s<=127) store.GET_SR(s);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "GET-S"){
			
			store.GET_S();
		}
		
		else if(order == "SET-LW"){
			
			int w, r, s, p;
			char dd[2];
			std::cin >> w >> r >> s >> p;
			std::cin >> dd[0] >> dd[1];
			
			if(w>=0 && r>=0 && s>=0 && p>=0 && w<=127 && r<=127 && s<=127 && p<=128) store.SET_LW(w,r,s,p,dd);
		
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "SET-LH"){
			
			int w, p;
			char dd[2];
			std::cin >> w >> p;
			std::cin >> dd[0] >> dd[1];
			
			if(w>=0 && p>=0 && w<=127 && p<=127) store.SET_LH(w,p,dd);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "SET-LR"){
			
			int s, p;
			char dd[2];
			std::cin >> s >> p;
			std::cin >> dd[0] >> dd[1];
			
			if(s>=0 && p>=0 && s<=127 && p<=127) store.SET_LR(s,p,dd);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "SET-LS"){
			
			int p;
			char dd[2];
			std::cin >> p;
			std::cin >> dd[0] >> dd[1];
			
			if(p>=0 && p<=127) store.SET_LS(p,dd);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "GET-LW"){
			
			int w, r, s, p;
			std::cin >> w >> r >> s >> p;
			
			if(w>=0 && r>=0 && s>=0 && p>=0 && w<=127 && r<=127 && s<=127 && p<=127) store.GET_LW(w,r,s,p);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "GET-LH"){
			
			int w, p;
			std::cin >> w >> p;
			
			if(w>=0 && p>=0 && w<=127 && p<=127) store.GET_LH(w,p);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "GET-LR"){
			
			int s, p;
			std::cin >> s >> p;
			
			if(s>=0 && p>=0 && s<=127 && p<=127) store.GET_LR(s,p);
			
			else std::cout << "error" << std::endl;
		}
		
		else if(order == "GET-LS"){
			
			int p;
			std::cin >> p;
			
			if(p>=0 && p<=127) store.GET_LS(p);
			
			else std::cout << "error" << std::endl;
		}
		
	}while(order!="END");
	

	return 0;
}








