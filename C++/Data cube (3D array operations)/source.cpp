//Jan Skwarczek

#include <iostream>


void determinant(long long cube[][32][32], int n, char k, int l){
	
	long long tab[32][32];
	long long det = 0;
	long long temp = 0;
	long long znak = 1;

	if(k=='l'){
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				
				tab[i][j] = cube[l][i][j];
			}
		}
		

		if(n==1){
			
			det = tab[0][0];
		}
		
		else{
			
			for (int i=0; i<n-1; i++){
	
				
				for (int a=0; a<n; a++){
					for (int c=a+1; c<n; c++){
	                	
	                	if(tab[a][a]<0&&tab[c][a]<0){
	                		if(tab[a][a]<tab[c][a]){
		                    	for (int b=0; b<=n; b++){
		                            temp = tab[a][b];
		                            tab[a][b] = tab[c][b];
		                            tab[c][b] = temp;
		                            znak = znak*(-1);
		                        }
		                    }
						}
						else if(tab[a][a]>=0&&tab[c][a]>=0){
							if(tab[a][a]<tab[c][a]){
		                    	for (int b=0; b<=n; b++){
		                            temp = tab[a][b];
		                            tab[a][b] = tab[c][b];
		                            tab[c][b] = temp;
		                            znak = znak*(-1);
		                        }
		                    }
						}
						
					}
				}
	
	            for (int j=i+1; j<n; j++){
	                for (int k=i+1; k<n; k++){
	                    tab[j][k] = ((tab[i][i]*tab[j][k]) - (tab[j][i]*tab[i][k]));
	                }
	                tab[j][i] = 0;
	            }
	
	            if (i>=1){
	                for (int a=0; a<n; a++){
	                	for (int c=a+1; c<n; c++){
	                		
	                	    if(tab[a][a]<0&&tab[c][a]<0){
		                		if(tab[a][a]<tab[c][a]){
			                    	for (int b=0; b<=n; b++){
			                            temp = tab[a][b];
			                            tab[a][b] = tab[c][b];
			                            tab[c][b] = temp;
			                            znak = znak*(-1);
			                        }
			                    }
							}
							else if(tab[a][a]>=0&&tab[c][a]>=0){
								if(tab[a][a]<tab[c][a]){
			                    	for (int b=0; b<=n; b++){
			                            temp = tab[a][b];
			                            tab[a][b] = tab[c][b];
			                            tab[c][b] = temp;
			                            znak = znak*(-1);
			                        }
			                    }
							}
						}   
					}
			
	                
	                for (int j=i+1; j<n; j++){
	                    for (int k=i+1; k<n; k++){
	                        tab[j][k] = tab[j][k] / tab[i-1][i-1];
	                    }
	                }
	            }
	
	        det = znak*tab[n-1][n-1];
			}
		}
		
	}
	
	else if(k=='v'){
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
					
				tab[i][j] = cube[i][l][j];
			}
		}
		
		if(n==1){
			
			det = tab[0][0];
		}
		
		else{
			
			for (int i=0; i<n-1; i++){
	
				
				for (int a=0; a<n; a++){
					for (int c=a+1; c<n; c++){
	                	
	                	if(tab[a][a]<0&&tab[c][a]<0){
	                		if(tab[a][a]<tab[c][a]){
		                    	for (int b=0; b<=n; b++){
		                            temp = tab[a][b];
		                            tab[a][b] = tab[c][b];
		                            tab[c][b] = temp;
		                            znak = znak*(-1);
		                        }
		                    }
						}
						else if(tab[a][a]>=0&&tab[c][a]>=0){
							if(tab[a][a]<tab[c][a]){
		                    	for (int b=0; b<=n; b++){
		                            temp = tab[a][b];
		                            tab[a][b] = tab[c][b];
		                            tab[c][b] = temp;
		                            znak = znak*(-1);
		                        }
		                    }
						}
						
					}
				}
	
	            for (int j=i+1; j<n; j++){
	                for (int k=i+1; k<n; k++){
	                    tab[j][k] = ((tab[i][i]*tab[j][k]) - (tab[j][i]*tab[i][k]));
	                }
	                tab[j][i] = 0;
	            }
	
	            if (i>=1){
	                for (int a=0; a<n; a++){
	                	for (int c=a+1; c<n; c++){
	                		
	                	    if(tab[a][a]<0&&tab[c][a]<0){
		                		if(tab[a][a]<tab[c][a]){
			                    	for (int b=0; b<=n; b++){
			                            temp = tab[a][b];
			                            tab[a][b] = tab[c][b];
			                            tab[c][b] = temp;
			                            znak = znak*(-1);
			                        }
			                    }
							}
							else if(tab[a][a]>=0&&tab[c][a]>=0){
								if(tab[a][a]<tab[c][a]){
			                    	for (int b=0; b<=n; b++){
			                            temp = tab[a][b];
			                            tab[a][b] = tab[c][b];
			                            tab[c][b] = temp;
			                            znak = znak*(-1);
			                        }
			                    }
							}
						}   
					}
	                
	                for (int j=i+1; j<n; j++){
	                    for (int k=i+1; k<n; k++){
	                        tab[j][k] = tab[j][k] / tab[i-1][i-1];
	                    }
	                }
	            }
	
	        det = znak*tab[n-1][n-1];
			}
		}
		
	}

	
	else if(k=='p'){

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
					
				tab[i][j] = cube[i][j][l];
			}
		}
		
		
		if(n==1){
			
			det = tab[0][0];
		}
		
		else{
			
			for (int i=0; i<n-1; i++){
	
				
				for (int a=0; a<n; a++){
					for (int c=a+1; c<n; c++){
	                	
	                	if(tab[a][a]<0&&tab[c][a]<0){
	                		if(tab[a][a]<tab[c][a]){
		                    	for (int b=0; b<=n; b++){
		                            temp = tab[a][b];
		                            tab[a][b] = tab[c][b];
		                            tab[c][b] = temp;
		                            znak = znak*(-1);
		                        }
		                    }
						}
						else if(tab[a][a]>=0&&tab[c][a]>=0){
							if(tab[a][a]<tab[c][a]){
		                    	for (int b=0; b<=n; b++){
		                            temp = tab[a][b];
		                            tab[a][b] = tab[c][b];
		                            tab[c][b] = temp;
		                            znak = znak*(-1);
		                        }
		                    }
						}
						
					}
				}
	
	            for (int j=i+1; j<n; j++){
	                for (int k=i+1; k<n; k++){
	                    tab[j][k] = ((tab[i][i]*tab[j][k]) - (tab[j][i]*tab[i][k]));
	                }
	                tab[j][i] = 0;
	            }
	
	            if (i>=1){
	                for (int a=0; a<n; a++){
	                	for (int c=a+1; c<n; c++){
	                		
	                	    if(tab[a][a]<0&&tab[c][a]<0){
		                		if(tab[a][a]<tab[c][a]){
			                    	for (int b=0; b<=n; b++){
			                            temp = tab[a][b];
			                            tab[a][b] = tab[c][b];
			                            tab[c][b] = temp;
			                            znak = znak*(-1);
			                        }
			                    }
							}
							else if(tab[a][a]>=0&&tab[c][a]>=0){
								if(tab[a][a]<tab[c][a]){
			                    	for (int b=0; b<=n; b++){
			                            temp = tab[a][b];
			                            tab[a][b] = tab[c][b];
			                            tab[c][b] = temp;
			                            znak = znak*(-1);
			                        }
			                    }
							}
						}   
					}
	                
	                for (int j=i+1; j<n; j++){
	                    for (int k=i+1; k<n; k++){
	                        tab[j][k] = tab[j][k] / tab[i-1][i-1];
	                    }
	                }
	            }
	
	        det = znak*tab[n-1][n-1];
			}
		}
		
	}
	
	std::cout << det << std::endl;
}

bool zwrot(int x, int n){
	
	if(x>=n/2) return true;
	else return false;
}

void tetrahedron(long long cube[][32][32], int n, long long l, long long v, long long p, long long e){
	
	long long sum = 0;
	
	bool h1 = zwrot(l, n);
    bool w1 = zwrot(v, n);
    bool d1 = zwrot(p, n);
    
    long long a = l;
    long long b = v;
    long long c = p;

    if(h1==false&&w1==false&&d1==false){
    	
       for(int i=0; i<=e; i++){
            for(int j=0; j<=e; j++){
                for(int k=0; k<=e; k++){

                    if(i+j+k<=e && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }

                    c++;
                }
				b++;
                c=p;
            }
			a++;
            b=v;
        }

        std::cout << sum << std::endl;
    }

	else if(h1==false && w1==false && d1==true){
       
       for(int i=0; i<=e; i++){
            for(int j=0; j<=e; j++){
                for(int k=0; k<=e; k++){
                	
                    if(i+j+k<=e && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }

                    c--;
                }
				b++;
                c=p;
            }
 			a++;
            b=v;
        }

        std::cout << sum << std::endl;

    }
	
	else if(h1==false&&w1==true&&d1==false){
        
		for(int i=0; i<=e; i++){
            for(int j=0; j<=e; j++){
                for(int k=0; k<=e; k++){
                	
                    if(i+j+k<=e && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c++;
                }
                b--;
                c=p;
            }
            a++;
            b=v;
        }
        
        std::cout << sum << std::endl;
    }
			
	else if(h1==false&&w1==true&&d1==true){
        
		for(int i=0; i<=e; i++){
            for(int j=0; j<=e; j++){
                for(int k=0; k<=e; k++){
                	
                    if(i+j+k<=e && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c--;
                }
                b--;
                c=p;
            }
            a++;
            b=v;
        }
        
        std::cout << sum << std::endl;
    }
            
	else if(h1==true&&w1==false&&d1==false){
            
       for(int i=0; i<=e; i++){
            for(int j=0; j<=e; j++){
                for(int k=0; k<=e; k++){
                	
                    if(i+j+k<=e && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c++;
                }
                b++;
                c=p;
            }
            a--;
            b=v;
        }
        
        std::cout << sum << std::endl;
    }
            
	else if(h1==true&&w1==false&&d1==true){
         
       for(int i=0; i<=e; i++){
            for(int j=0; j<=e; j++){
                for(int k=0; k<=e; k++){
                	
                    if(i+j+k<=e && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c--;
                }
                b++;
                c=p;
            }
            a--;
            b=v;
        }
        
        std::cout << sum << std::endl;	    
    }
            
	else if(h1==true&&w1==true&&d1==false){
         
       for(int i=0; i<=e; i++){
            for(int j=0; j<=e; j++){
                for(int k=0; k<=e; k++){
                	
                    if(i+j+k<=e && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c++;
                }
                b--;
                c=p;
               
            }
            a--;
            b=v;
            
        }
        
        std::cout << sum << std::endl;   
    }
            
	else if(h1==true&&w1==true&&d1==true){
            
       for(int i=0; i<=e; i++){
            for(int j=0; j<=e; j++){
                for(int k=0; k<=e; k++){
                	
                    if(i+j+k<=e && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c--;
                }
                b--;
                c=p;
            }
            a--;
            b=v;
        }
        
        std::cout << sum << std::endl;
	
	}
	
}

void octal(long long cube[][32][32], int n, long long l, long long v, long long p, long long r){
	
	long long sum = 0;
	
	bool h1 = zwrot(l, n);
    bool w1 = zwrot(v, n);
    bool d1 = zwrot(p, n);
    
    long long a = l;
    long long b = v;
    long long c = p;
	
    if(h1==false&&w1==false&&d1==false){
    	
       for(int i=0; i<=r; i++){
            for(int j=0; j<=r; j++){
                for(int k=0; k<=r; k++){

                    if((i*i)+(j*j)+(k*k)<=(r*r) && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n && r>=0){
                        sum = sum + cube[a][b][c];
                    }

                    c++;
                }
				b++;
                c=p;
            }
			a++;
            b=v;
        }

        std::cout << sum << std::endl;
    }

	else if(h1==false && w1==false && d1==true){
       
       for(int i=0; i<=r; i++){
            for(int j=0; j<=r; j++){
                for(int k=0; k<=r; k++){
                    if((i*i)+(j*j)+(k*k)<=(r*r) && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n && r>=0){
                        sum = sum + cube[a][b][c];
                    }

                    c--;
                }
				b++;
                c=p;
            }
			a++;
            b=v;
        }

        std::cout << sum << std::endl;

    }
	
	else if(h1==false&&w1==true&&d1==false){
        
		for(int i=0; i<=r; i++){
            for(int j=0; j<=r; j++){
                for(int k=0; k<=r; k++){
                	
                    if((i*i)+(j*j)+(k*k)<=(r*r) && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n && r>=0){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c++;
                }
                b--;
                c=p;
            }
            a++;
            b=v;
        }
        
        std::cout << sum << std::endl;
    }
			
	else if(h1==false&&w1==true&&d1==true){
        
		for(int i=0; i<=r; i++){
            for(int j=0; j<=r; j++){
                for(int k=0; k<=r; k++){
                	
                    if((i*i)+(j*j)+(k*k)<=(r*r) && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n && r>=0){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c--;
                }
                b--;
                c=p;
            }
            a++;
            b=v;
        }
        
        std::cout << sum << std::endl;
    }
            
	else if(h1==true&&w1==false&&d1==false){
            
       for(int i=0; i<=r; i++){
            for(int j=0; j<=r; j++){
                for(int k=0; k<=r; k++){
                	
                    if((i*i)+(j*j)+(k*k)<=(r*r) && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n && r>=0){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c++;
                }
                b++;
                c=p;
            }
            a--;
            b=v;
        }
        
        std::cout << sum << std::endl;
    }
            
	else if(h1==true&&w1==false&&d1==true){
         
       for(int i=0; i<=r; i++){
            for(int j=0; j<=r; j++){
                for(int k=0; k<=r; k++){
                	
                    if((i*i)+(j*j)+(k*k)<=(r*r) && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n && r>=0){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c--;
                }
                b++;
                c=p;
            }
            a--;
            b=v;
        }
        
        std::cout << sum << std::endl;	    
    }
            
	else if(h1==true&&w1==true&&d1==false){
         
       for(int i=0; i<=r; i++){
            for(int j=0; j<=r; j++){
                for(int k=0; k<=r; k++){
                	
                    if((i*i)+(j*j)+(k*k)<=(r*r) && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n && r>=0){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c++;
                }
                b--;
                c=p;
            }
            a--;
            b=v;
        }
        
        std::cout << sum << std::endl;   
    }
            
	else if(h1==true&&w1==true&&d1==true){
            
       for(int i=0; i<=r; i++){
            for(int j=0; j<=r; j++){
                for(int k=0; k<=r; k++){
                	
                    if((i*i)+(j*j)+(k*k)<=(r*r) && a>=0&&a<n && b>=0&&b<n && c>=0&&c<n && r>=0){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c--;
                }
                b--;
                c=p;
            }
            a--;
            b=v;
        }
        
        std::cout << sum << std::endl;
	
	}
	
}


void cuboid(long long cube[][32][32], int n, long long l, long long v, long long p, long long h, long long w, long long d){
	
	long long sum = 0;
	
	bool h1 = zwrot(l, n);
    bool w1 = zwrot(v, n);
    bool d1 = zwrot(p, n);
    
    long long a = l;
    long long b = v;
    long long c = p;
    
	
    if(h1==false&&w1==false&&d1==false){
    	
       for(int i=0; i<=h; i++){
            for(int j=0; j<=w; j++){
                for(int k=0; k<=d; k++){

                    if(a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }

                    c++;
                }
				b++;
                c=p;
            }
			a++;
            b=v;
        }
        
        std::cout << sum << std::endl;
        
    }

	else if(h1==false && w1==false && d1==true){
       
       for(int i=0; i<=h; i++){
            for(int j=0; j<=w; j++){
                for(int k=0; k<=d; k++){
                    if(a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }

                    c--;
                }
				b++;
                c=p;
            }
			a++;
            b=v;
        }

        std::cout << sum << std::endl;

    }
	
	else if(h1==false&&w1==true&&d1==false){
        
		       for(int i=0; i<=h; i++){
            for(int j=0; j<=w; j++){
                for(int k=0; k<=d; k++){
                	
                    if(a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c++;
                }
                b--;
                c=p;
            }
            a++;
            b=v;
        }
        
        std::cout << sum << std::endl;
    }
			
	else if(h1==false&&w1==true&&d1==true){
        
		       for(int i=0; i<=h; i++){
            for(int j=0; j<=w; j++){
                for(int k=0; k<=d; k++){
                	
                    if(a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c--;
                }
                b--;
                c=p;
            }
            a++;
            b=v;
        }
        
        std::cout << sum << std::endl;
    }
            
	else if(h1==true&&w1==false&&d1==false){
            
       for(int i=0; i<=h; i++){
            for(int j=0; j<=w; j++){
                for(int k=0; k<=d; k++){
                	
                    if(a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c++;
                }
                b++;
                c=p;
            }
            a--;
            b=v;
        }
        
        std::cout << sum << std::endl;
    }
            
	else if(h1==true&&w1==false&&d1==true){
         
       for(int i=0; i<=h; i++){
            for(int j=0; j<=w; j++){
                for(int k=0; k<=d; k++){
                	
                    if(a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c--;
                }
                b++;
                c=p;
            }
            a--;
            b=v;
        }
        
        std::cout << sum << std::endl;
    }
            
	else if(h1==true&&w1==true&&d1==false){
         
       for(int i=0; i<=h; i++){
            for(int j=0; j<=w; j++){
                for(int k=0; k<=d; k++){
                	
                    if(a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c++;
                }
                b--;
                c=p;
            }
            a--;
            b=v;
        }
        
        std::cout << sum << std::endl;   
    }
            
	else if(h1==true&&w1==true&&d1==true){
            
       for(int i=0; i<=h; i++){
            for(int j=0; j<=w; j++){
                for(int k=0; k<=d; k++){
                	
                    if(a>=0&&a<n && b>=0&&b<n && c>=0&&c<n){
                        sum = sum + cube[a][b][c];
                    }
                    
                    c--;
                }
                b--;
                c=p;
            }
            a--;
            b=v;
        }
        
        std::cout << sum << std::endl;
	}
	
}


int main(){
	
	int n;
	char operation;
	
	std::cin >> n;
	
	if(n>32||n<0||n%2!=0) return 0;
	
	long long cube[32][32][32];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				
				std::cin >> cube[j][k][i];
				
			}
		}
	}
	
	do{
		
		std::cin >> operation;
		
		if(operation == 'C'){
		
			long long l, v, p, h, w, d;
			std::cin >> l >> v >> p >> h >> w >> d;
			cuboid(cube, n, l, v, p, h, w, d);
		}
	
		else if(operation == 'T'){
			
			long long l, v, p, e;
			std::cin >> l >> v >> p >> e;
			tetrahedron(cube, n, l, v, p, e);
		}
		
		else if(operation == 'O'){
		
			long long l, v, p, r;	
			std::cin >> l >> v >> p >> r;
			octal(cube, n, l, v, p, r);
			
		}
		
		else if(operation == 'D'){
		
			long long i;
			char k;
			std::cin >> k >> i;
			determinant(cube, n, k, i);
		}
		
	}while(operation!='E');
	
	
	return 0;
}


















