//Jan Skwarczek

#include <iostream>

int n, k;
int ods, ip, ik;
char type;
int tempswipe;

int licznik=0;
double srednia;
double wagasrednia;

int main(){
	
	std::cin >> n;
	
	if(n>10000) return 0;
	
	double tab[n];
	
	for(int i=0; i<n; i++){
		
		std::cin >> tab[i];
	}
	
	
	std::cin >>k;
	
	if(k>21||k%2==0||k>n) return 0;
		
	double mask[k];
	
	for(int i=0; i<k; i++){
		
		std::cin >> mask[i];
	}
	
	std::cin >> ods >> ip >> ik >> type;
	
	int helplen;
	
	if(ik-ip>0) helplen = ik-ip;
	else helplen = n-(ip-ik);
	
	double helper[helplen+1];
	int masklen = k+(ods*(k-1));
	
	
	for( int i = 0; i<=helplen; i++ )
		helper[i] = tab[(ip+i)%n];
		
	
	if(type=='r'){	
		
		for(int i=0; i<=helplen; i++){
			
			srednia = 0;
			licznik = 0;
			
			for( int j=0; j<masklen; j=j+ods+1){
				
				if(((i+j-(masklen/2))%(helplen+1))>=0) tempswipe = (i+j-(masklen/2))%(helplen+1);
				
				else tempswipe = (helplen+1)+((i+j-(masklen/2))%(helplen+1));
				
				srednia = srednia+helper[tempswipe];
				licznik++;
			}
			
			srednia = srednia/licznik;
			tab[(ip+i)%n] = ((int)(srednia*100.0)/100.0);
		}
		
		for(int i=0; i<n; i++){
		
		std::cout << tab[i] << " ";
		
		}
	}
		
	
	else if(type=='m'){
		
		for(int i=0; i<=helplen; i++){
			
			srednia = 0;
			licznik = 0;
			
			for( int j=0; j<masklen; j=j+ods+1){
				
				if(((i+j-(masklen/2))%(helplen+1))>=0) tempswipe = (i+j-(masklen/2))%(helplen+1);
				
				else tempswipe = (helplen+1)+((i+j-(masklen/2))%(helplen+1));
				
				
				mask[licznik] = helper[tempswipe];
				
				licznik++;
			}
			
			for(int x=0; x<k-1; x++){
				
				int t;
				
				if(mask[x]>mask[x+1]){
					
					t = mask[x+1];
					mask[x+1] = mask[x];
					mask[x] = t;
					x=-1;
				}
				
			}
			
			tab[(ip+i)%n] = (int)(mask[k/2]*100.0)/100.0;
		}
		
		for(int i=0; i<n; i++){
		
		std::cout << tab[i] << " ";
		
		}
		
	}
	
	else if(type=='w'){	
		
		for(int i=0; i<=helplen; i++){
			
			wagasrednia = 0;
			licznik = 0;
			
			for( int j=0; j<masklen; j=j+ods+1){
				
				if(((i+j-(masklen/2))%(helplen+1))>=0) tempswipe = (i+j-(masklen/2))%(helplen+1);
				
				else tempswipe = (helplen+1)+((i+j-(masklen/2))%(helplen+1));
				
				wagasrednia = wagasrednia + helper[tempswipe] * mask[licznik];
				licznik++;
			}
			
			tab[(ip+i)%n] = ((int)(wagasrednia*100.0)/100.0);
		}
		
		
		for(int i=0; i<n; i++){
		
		std::cout << tab[i] << " ";
		
		}
	}
	
	
	return 0;
}
