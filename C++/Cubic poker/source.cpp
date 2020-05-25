//Jan Skwarczek

#include <iostream>

char name1, name2;

float Z=0.0;

float a1=0.0, a2=0.0, a3=0.0, a4=0.0, b1=0.0, b2=0.0, b3=0.0, b4=0.0, c1=0.0, c2=0.0, c3=0.0, c4=0.0, d1=0.0, d2=0.0, d3=0.0, d4=0.0, e1=0.0, e2=0.0, e3=0.0, e4=0.0;

float arep=0.0, brep=0.0, crep=0.0, drep=0.0, erep=0.0;

float asum=0.0, bsum=0.0, csum=0.0, dsum=0.0, esum=0.0;

float awin=0.0, bwin=0.0, cwin=0.0, dwin=0.0, ewin=0.0;
float adraw=0.0, bdraw=0.0, cdraw=0.0, ddraw=0.0, edraw=0.0;

float awonout, bwonout, cwonout, dwonout, ewonout;
float alostout, blostout, clostout, dlostout, elostout;
float adrawout, bdrawout, cdrawout, ddrawout, edrawout;

float acounter, bcounter, ccounter, dcounter, ecounter;

int main(){
	
	std::cin >> Z;
	float all=Z;
	
	while(Z--){
		
		std::cin >> name1;
		if(name1=='a') std::cin >> a1 >> a2 >> a3 >> a4 >> name2;
		else if(name1=='b') std::cin >> b1 >> b2 >> b3 >> b4 >> name2;
		else if(name1=='c') std::cin >> c1 >> c2 >> c3 >> c4 >> name2;
		else if(name1=='d') std::cin >> d1 >> d2 >> d3 >> d4 >> name2;
		else if(name1=='e') std::cin >> e1 >> e2 >> e3 >> e4 >> name2;
		
		if(name2=='a') std::cin >> a1 >> a2 >> a3 >> a4;
		else if(name2=='b') std::cin >> b1 >> b2 >> b3 >> b4;
		else if(name2=='c') std::cin >> c1 >> c2 >> c3 >> c4;
		else if(name2=='d') std::cin >> d1 >> d2 >> d3 >> d4;
		else if(name2=='e') std::cin >> e1 >> e2 >> e3 >> e4;
		
		if(name1=='a') acounter++;
		else if(name1=='b') bcounter++;
		else if(name1=='c') ccounter++;
		else if(name1=='d') dcounter++;
		else if(name1=='e') ecounter++;
		
		if(name2=='a') acounter++;
		else if(name2=='b') bcounter++;
		else if(name2=='c') ccounter++;
		else if(name2=='d') dcounter++;
		else if(name2=='e') ecounter++;
		
		
		if(name1==name2||a1<0||a1>4||a2<0||a2>4||a3<0||a3>4||a4<0||a4>4||b1<0||b1>4||b2<0||b2>4||b3<0||b3>4||b4<0||b4>4||c1<0||c1>4||c2<0||c2>4||c3<0||c3>4||c4<0||c4>4||d1<0||d1>4||d2<0||d2>4||d3<0||d3>4||d4<0||d4>4||e1<0||e1>4||e2<0||e2>4||e3<0||e3>4||e4<0||e4>4) return 0;
		
		else{
			
		arep=0.0; brep=0.0; crep=0.0; drep=0.0; erep=0.0;
		asum=0.0; bsum=0.0; csum=0.0; dsum=0.0; esum=0.0;
		
		if((name1=='a')&&(a1==a2)){ arep++; asum=asum+a1+a2; }
		if((name1=='a')&&(a1==a3)){ arep++; asum=asum+a1+a3; }
		if((name1=='a')&&(a1==a4)){ arep++; asum=asum+a1+a4; }
		if((name1=='a')&&(a2==a3)){ arep++; asum=asum+a2+a3; } 
		if((name1=='a')&&(a2==a4)){ arep++; asum=asum+a2+a4; }
		if((name1=='a')&&(a3==a4)){ arep++; asum=asum+a3+a4; }
		if((name1=='a')&&(a1!=a2&&a1!=a3&&a1!=a4&&a2!=a3&&a2!=a4&&a3!=a4)) arep=4;
		
		
		if((name1=='b')&&(b1==b2)){ brep++; bsum=bsum+b1+b2; }
		if((name1=='b')&&(b1==b3)){ brep++; bsum=bsum+b1+b3; }
		if((name1=='b')&&(b1==b4)){ brep++; bsum=bsum+b1+b4; }
		if((name1=='b')&&(b2==b3)){ brep++; bsum=bsum+b2+b3; }
		if((name1=='b')&&(b2==b4)){ brep++; bsum=bsum+b2+b4; }
		if((name1=='b')&&(b3==b4)){ brep++; bsum=bsum+b3+b4; }
		if((name1=='b')&&(b1!=b2&&b1!=b3&&b1!=b4&&b2!=b3&&b2!=b4&&b3!=b4)) brep=4;
		
		
		if((name1=='c')&&(c1==c2)){ crep++; csum=csum+c1+c2; }
		if((name1=='c')&&(c1==c3)){ crep++; csum=csum+c1+c3; }
		if((name1=='c')&&(c1==c4)){ crep++; csum=csum+c1+c4; }
		if((name1=='c')&&(c2==c3)){ crep++; csum=csum+c1+c3; }
		if((name1=='c')&&(c2==c4)){ crep++; csum=csum+c2+c4; }
		if((name1=='c')&&(c3==c4)){ crep++; csum=csum+c3+c4; }
		if((name1=='c')&&(c1!=c2&&c1!=c3&&c1!=c4&&c2!=c3&&c2!=c4&&c3!=c4)) crep=4;
				
		
		if((name1=='d')&&(d1==d2)){ drep++; dsum=dsum+d1+d2; }
		if((name1=='d')&&(d1==d3)){ drep++; dsum=dsum+d1+d3; }
		if((name1=='d')&&(d1==d4)){ drep++; dsum=dsum+d1+d4; }
		if((name1=='d')&&(d2==d3)){ drep++; dsum=dsum+d2+d3; }
		if((name1=='d')&&(d2==d4)){ drep++; dsum=dsum+d2+d4; }
		if((name1=='d')&&(d3==d4)){ drep++; dsum=dsum+d3+d4; }
		if((name1=='d')&&(d1!=d2&&d1!=d3&&d1!=d4&&d2!=d3&&d2!=d4&&d3!=d4)) drep=4;
		
		
		if((name1=='e')&&(e1==e2)){ erep++; esum=esum+e1+e2; }
		if((name1=='e')&&(e1==e3)){ erep++; esum=esum+e1+e3; }
		if((name1=='e')&&(e1==e4)){ erep++; esum=esum+e1+e4; }
		if((name1=='e')&&(e2==e3)){ erep++; esum=esum+e2+e3; }
		if((name1=='e')&&(e2==e4)){ erep++; esum=esum+e2+e4; }
		if((name1=='e')&&(e3==e4)){ erep++; esum=esum+e3+e4; }
		if((name1=='e')&&(e1!=e2&&e1!=e3&&e1!=e4&&e2!=e3&&e2!=e4&&e3!=e4)) erep=4;
		
		
		if((name2=='a')&&(a1==a2)){ arep++; asum=asum+a1+a2; }
		if((name2=='a')&&(a1==a3)){ arep++; asum=asum+a1+a3; }
		if((name2=='a')&&(a1==a4)){ arep++; asum=asum+a1+a4; }
		if((name2=='a')&&(a2==a3)){ arep++; asum=asum+a2+a3; } 
		if((name2=='a')&&(a2==a4)){ arep++; asum=asum+a2+a4; }
		if((name2=='a')&&(a3==a4)){ arep++; asum=asum+a3+a4; }
		if((name2=='a')&&(a1!=a2&&a1!=a3&&a1!=a4&&a2!=a3&&a2!=a4&&a3!=a4)) arep=4;
		
		
		if((name2=='b')&&(b1==b2)){ brep++; bsum=bsum+b1+b2; }
		if((name2=='b')&&(b1==b3)){ brep++; bsum=bsum+b1+b3; }
		if((name2=='b')&&(b1==b4)){ brep++; bsum=bsum+b1+b4; }
		if((name2=='b')&&(b2==b3)){ brep++; bsum=bsum+b2+b3; }
		if((name2=='b')&&(b2==b4)){ brep++; bsum=bsum+b2+b4; }
		if((name2=='b')&&(b3==b4)){ brep++; bsum=bsum+b3+b4; }
		if((name2=='b')&&(b1!=b2&&b1!=b3&&b1!=b4&&b2!=b3&&b2!=b4&&b3!=b4)) brep=4;
			
		
		if((name2=='c')&&(c1==c2)){ crep++; csum=csum+c1+c2; }
		if((name2=='c')&&(c1==c3)){ crep++; csum=csum+c1+c3; }
		if((name2=='c')&&(c1==c4)){ crep++; csum=csum+c1+c4; }
		if((name2=='c')&&(c2==c3)){ crep++; csum=csum+c2+c3; }
		if((name2=='c')&&(c2==c4)){ crep++; csum=csum+c2+c4; }
		if((name2=='c')&&(c3==c4)){ crep++; csum=csum+c3+c4; }
		if((name2=='c')&&(c1!=c2&&c1!=c3&&c1!=c4&&c2!=c3&&c2!=c4&&c3!=c4)) crep=4;

		
		if((name2=='d')&&(d1==d2)){ drep++; dsum=dsum+d1+d2; }
		if((name2=='d')&&(d1==d3)){ drep++; dsum=dsum+d1+d3; }
		if((name2=='d')&&(d1==d4)){ drep++; dsum=dsum+d1+d4; }
		if((name2=='d')&&(d2==d3)){ drep++; dsum=dsum+d2+d3; }
		if((name2=='d')&&(d2==d4)){ drep++; dsum=dsum+d2+d4; }
		if((name2=='d')&&(d3==d4)){ drep++; dsum=dsum+d3+d4; }
		if((name2=='d')&&(d1!=d2&&d1!=d3&&d1!=d4&&d2!=d3&&d2!=d4&&d3!=d4)) drep=4;
		
		
		if((name2=='e')&&(e1==e2)){ erep++; esum=esum+e1+e2; }
		if((name2=='e')&&(e1==e3)){ erep++; esum=esum+e1+e3; }
		if((name2=='e')&&(e1==e4)){ erep++; esum=esum+e1+e4; }
		if((name2=='e')&&(e2==e3)){ erep++; esum=esum+e2+e3; }
		if((name2=='e')&&(e2==e4)){ erep++; esum=esum+e2+e4; }
		if((name2=='e')&&(e3==e4)){ erep++; esum=esum+e3+e4; }
		if((name2=='e')&&(e1!=e2&&e1!=e3&&e1!=e4&&e2!=e3&&e2!=e4&&e3!=e4)) erep=4;

		
		if(arep==3) arep=2;
		else if(arep==2) arep=3;
		else if(arep==6) arep=5;
		
		if(brep==3) brep=2;
		else if(brep==2) brep=3;
		else if(brep==6) brep=5;
		
		if(crep==3) crep=2;
		else if(crep==2) crep=3;
		else if(crep==6) crep=5;
		
		if(drep==3) drep=2;
		else if(drep==2) drep=3;
		else if(drep==6) drep=5;
		
		if(erep==3) erep=2;
		else if(erep==2) erep=3;
		else if(erep==6) erep=5;
		
		
		if(name1=='a'&&name2=='b'&&arep>brep) awin=awin+1.0;
		else if(name1=='a'&&name2=='c'&&arep>crep) awin=awin+1.0;
		else if(name1=='a'&&name2=='d'&&arep>drep) awin=awin+1.0;
		else if(name1=='a'&&name2=='e'&&arep>erep) awin=awin+1.0;
		
		if(name1=='a'&&name2=='b'&&arep<brep) bwin=bwin+1.0;
		else if(name1=='a'&&name2=='c'&&arep<crep) cwin=cwin+1.0;
		else if(name1=='a'&&name2=='d'&&arep<drep) dwin=dwin+1.0;
		else if(name1=='a'&&name2=='e'&&arep<erep) ewin=ewin+1.0;
		
		
		
		if(name1=='b'&&name2=='a'&&brep>arep) bwin=bwin+1.0;
		else if(name1=='b'&&name2=='c'&&brep>crep) bwin=bwin+1.0;
		else if(name1=='b'&&name2=='d'&&brep>drep) bwin=bwin+1.0;
		else if(name1=='b'&&name2=='e'&&brep>erep) bwin=bwin+1.0;
		
		if(name1=='b'&&name2=='a'&&brep<arep) awin=awin+1.0;
		else if(name1=='b'&&name2=='c'&&brep<crep) cwin=cwin+1.0;
		else if(name1=='b'&&name2=='d'&&brep<drep) dwin=dwin+1.0;
		else if(name1=='b'&&name2=='e'&&brep<erep) ewin=ewin+1.0;
		
		
		
		if(name1=='c'&&name2=='a'&&crep>arep) cwin=cwin+1.0;
		else if(name1=='c'&&name2=='b'&&crep>crep) cwin=cwin+1.0;
		else if(name1=='c'&&name2=='d'&&crep>drep) cwin=cwin+1.0;
		else if(name1=='c'&&name2=='e'&&crep>erep) cwin=cwin+1.0;
		
		if(name1=='c'&&name2=='a'&&crep<arep) awin=awin+1.0;
		else if(name1=='c'&&name2=='b'&&crep<brep) bwin=bwin+1.0;
		else if(name1=='c'&&name2=='d'&&crep<drep) dwin=dwin+1.0;
		else if(name1=='c'&&name2=='e'&&crep<erep) ewin=ewin+1.0;
		
		
		
		if(name1=='d'&&name2=='a'&&drep>arep) dwin=dwin+1.0;
		else if(name1=='d'&&name2=='b'&&drep>brep) dwin=dwin+1.0;
		else if(name1=='d'&&name2=='c'&&drep>drep) dwin=dwin+1.0;
		else if(name1=='d'&&name2=='e'&&drep>erep) dwin=dwin+1.0;
		
		if(name1=='d'&&name2=='a'&&drep<arep) awin=awin+1.0;
		else if(name1=='d'&&name2=='b'&&drep<brep) bwin=bwin+1.0;
		else if(name1=='d'&&name2=='c'&&drep<crep) cwin=cwin+1.0;
		else if(name1=='d'&&name2=='e'&&drep<erep) ewin=ewin+1.0;
		
		
		
		if(name1=='e'&&name2=='a'&&erep>arep) ewin=ewin+1.0;
		else if(name1=='e'&&name2=='b'&&erep>brep) ewin=ewin+1.0;
		else if(name1=='e'&&name2=='c'&&erep>crep) ewin=ewin+1.0;
		else if(name1=='e'&&name2=='d'&&erep>drep) ewin=ewin+1.0;
		
		if(name1=='e'&&name2=='a'&&erep<arep) awin=awin+1.0;
		else if(name1=='e'&&name2=='b'&&erep<brep) bwin=bwin+1.0;
		else if(name1=='e'&&name2=='c'&&erep<crep) cwin=cwin+1.0;
		else if(name1=='e'&&name2=='d'&&erep<drep) dwin=dwin+1.0;
		
		
		if(((name1=='a'&&name2=='b')||(name1=='b'&&name2=='a'))&&(arep==4&&brep==4))
			if(a1+a2+a3+a4>b1+b2+b3+b4) awin=awin+1.0;
			else if(a1+a2+a3+a4<b1+b2+b3+b4) bwin=bwin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4>b1+b2+b3+b4) awin=awin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4<b1+b2+b3+b4) bwin=bwin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4==b1+b2+b3+b4) { adraw=adraw+1.0; bdraw=bdraw+1.0;}
		
		if(((name1=='a'&&name2=='c')||(name1=='c'&&name2=='a'))&&(arep==4&&crep==4))
			if(a1+a2+a3+a4>c1+c2+c3+c4) awin=awin+1.0;
			else if(a1+a2+a3+a4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(asum==csum&&a1+a2+a3+a4>c1+c2+c3+c4) awin=awin+1.0;
			else if(asum==csum&&a1+a2+a3+a4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(asum==csum&&a1+a2+a3+a4==c1+c2+c3+c4) { adraw=adraw+1.0; cdraw=cdraw+1.0;}
			
		if(((name1=='a'&&name2=='d')||(name1=='d'&&name2=='a'))&&(arep==4&&drep==4))
			if(a1+a2+a3+a4>d1+d2+d3+d4) awin=awin+1.0;
			else if(a1+a2+a3+a4<d1+d2+d3+d4) dwin=dwin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4>d1+d2+d3+d4) awin=awin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4<d1+d2+d3+d4) dwin=dwin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4==d1+d2+d3+d4) { adraw=adraw+1.0; ddraw=ddraw+1.0;}
			
		if(((name1=='a'&&name2=='e')||(name1=='e'&&name2=='a'))&&(arep==4&&erep==4))
			if(a1+a2+a3+a4>e1+e2+e3+e4) awin=awin+1.0;
			else if(a1+a2+a3+a4<e1+e2+e3+e4) ewin=ewin+1.0;
				else if(asum==esum&&a1+a2+a3+a4>e1+e2+e3+e4) awin=awin+1.0;
			else if(asum==esum&&a1+a2+a3+a4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(asum==esum&&a1+a2+a3+a4==e1+e2+e3+e4) { adraw=adraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='b'&&name2=='c')||(name1=='c'&&name2=='b'))&&(brep==4&&crep==4))
			if(b1+b2+b3+b4>c1+c2+c3+c4) bwin=bwin+1.0;
			else if(b1+b2+b3+b4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4>c1+c2+c3+c4) bwin=bwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4==c1+c2+c3+c4) { bdraw=bdraw+1.0; cdraw=cdraw+1.0;}
		
		if(((name1=='b'&&name2=='d')||(name1=='d'&&name2=='b'))&&(brep==4&&drep==4))
			if(b1+b2+b3+b4>d1+d2+d3+d4) bwin=bwin+1.0;
			else if(b1+b2+b3+b4<d1+d2+d3+d4) dwin=dwin+1.0;
				else if(bsum==dsum&&b1+b2+b3+b4>d1+d2+d3+d4) bwin=bwin+1.0;
			else if(bsum==dsum&&b1+b2+b3+b4<d1+d2+d3+d4) dwin=dwin+1.0;
			else if(bsum==dsum&&b1+b2+b3+b4==d1+d2+d3+d4) { bdraw=bdraw+1.0; ddraw=ddraw+1.0;}
		
		if(((name1=='b'&&name2=='e')||(name1=='e'&&name2=='b'))&&(brep==4&&erep==4))
			if(b1+b2+b3+b4>e1+e2+e3+e4) bwin=bwin+1.0;
			else if(b1+b2+b3+b4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4>e1+e2+e3+e4) bwin=bwin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4==e1+e2+e3+e4) { bdraw=bdraw+1.0; edraw=edraw+1.0;}
			
		else if(((name1=='c'&&name2=='e')||(name1=='e'&&name2=='c'))&&(erep==4&&crep==4))
			if(e1+e2+e3+e4>c1+c2+c3+c4) ewin=ewin+1.0;
			else if(e1+e2+e3+e4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(csum==esum&&c1+c2+c3+c4>e1+e2+e3+e4) cwin=cwin+1.0;
			else if(csum==esum&&c1+c2+c3+c4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(csum==esum&&c1+c2+c3+c4==e1+e2+e3+e4) { cdraw=cdraw+1.0; edraw=edraw+1.0;}	
			
		if(((name1=='d'&&name2=='c')||(name1=='c'&&name2=='d'))&&(drep==4&&crep==4))
			if(d1+d2+d3+d4>c1+c2+c3+c4) dwin=dwin+1.0;
			else if(d1+d2+d3+d4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4>c1+c2+c3+c4) dwin=dwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4==c1+c2+c3+c4) { ddraw=ddraw+1.0; cdraw=cdraw+1.0;}	
			
		if(((name1=='d'&&name2=='e')||(name1=='e'&&name2=='d'))&&(drep==4&&erep==4))
			if(d1+d2+d3+d4>e1+e2+e3+e4) dwin=dwin+1.0;
			else if(d1+d2+d3+d4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4>e1+e2+e3+e4) dwin=dwin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4==e1+e2+e3+e4) { ddraw=ddraw+1.0; edraw=edraw+1.0;}
		
		
		
		
		if(((name1=='a'&&name2=='b')||(name1=='b'&&name2=='a'))&&(arep==5&&brep==5))
			if(asum>bsum) awin=awin+1.0;
			else if(asum<bsum) bwin=bwin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4>b1+b2+b3+b4) awin=awin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4<b1+b2+b3+b4) bwin=bwin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4==b1+b2+b3+b4) { adraw=adraw+1.0; bdraw=bdraw+1.0;}
		
		if(((name1=='a'&&name2=='c')||(name1=='c'&&name2=='a'))&&(arep==5&&crep==5))
			if(asum>csum) awin=awin+1.0;
			else if(asum<csum) cwin=cwin+1.0;
			else if(asum==csum&&a1+a2+a3+a4>c1+c2+c3+c4) awin=awin+1.0;
			else if(asum==csum&&a1+a2+a3+a4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(asum==csum&&a1+a2+a3+a4==c1+c2+c3+c4) { adraw=adraw+1.0; cdraw=cdraw+1.0;}
			
		if(((name1=='a'&&name2=='d')||(name1=='d'&&name2=='a'))&&(arep==5&&drep==5))
			if(asum>dsum) awin=awin+1.0;
			else if(asum<dsum) dwin=dwin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4>d1+d2+d3+d4) awin=awin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4<d1+d2+d3+d4) dwin=dwin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4==d1+d2+d3+d4) { adraw=adraw+1.0; ddraw=ddraw+1.0;}
			
		if(((name1=='a'&&name2=='e')||(name1=='e'&&name2=='a'))&&(arep==5&&erep==5))
			if(asum>esum) awin=awin+1.0;
			else if(asum<esum) ewin=ewin+1.0;
			else if(asum==esum&&a1+a2+a3+a4>e1+e2+e3+e4) awin=awin+1.0;
			else if(asum==esum&&a1+a2+a3+a4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(asum==esum&&a1+a2+a3+a4==e1+e2+e3+e4) { adraw=adraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='b'&&name2=='c')||(name1=='c'&&name2=='b'))&&(brep==5&&crep==5))
			if(bsum>csum) bwin=bwin+1.0;
			else if(bsum<csum) cwin=cwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4>c1+c2+c3+c4) bwin=bwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4==c1+c2+c3+c4) { bdraw=bdraw+1.0; cdraw=cdraw+1.0;}
		
		if(((name1=='b'&&name2=='d')||(name1=='d'&&name2=='b'))&&(brep==5&&drep==5))
			if(bsum>dsum) bwin=bwin+1.0;
			else if(bsum<dsum) dwin=dwin+1.0;
			else if(bsum==dsum&&b1+b2+b3+b4>d1+d2+d3+d4) bwin=bwin+1.0;
			else if(bsum==dsum&&b1+b2+b3+b4<d1+d2+d3+d4) dwin=dwin+1.0;
			else if(bsum==dsum&&b1+b2+b3+b4==d1+d2+d3+d4) { bdraw=bdraw+1.0; ddraw=ddraw+1.0;}
		
		if(((name1=='b'&&name2=='e')||(name1=='e'&&name2=='b'))&&(brep==5&&erep==5))
			if(bsum>esum) bwin=bwin+1.0;
			else if(bsum<esum) ewin=ewin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4>e1+e2+e3+e4) bwin=bwin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4==e1+e2+e3+e4) { bdraw=bdraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='c'&&name2=='e')||(name1=='e'&&name2=='c'))&&(erep==5&&crep==5))
			if(esum>csum) ewin=ewin+1.0;
			else if(esum<csum) cwin=cwin+1.0;
			else if(csum==esum&&c1+c2+c3+c4>e1+e2+e3+e4) cwin=cwin+1.0;
			else if(csum==esum&&c1+c2+c3+c4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(csum==esum&&c1+c2+c3+c4==e1+e2+e3+e4) { cdraw=cdraw+1.0; edraw=edraw+1.0;}	
			
		if(((name1=='d'&&name2=='c')||(name1=='c'&&name2=='d'))&&(drep==5&&crep==5))
			if(dsum>csum) dwin=dwin+1.0;
			else if(dsum<csum) cwin=cwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4>c1+c2+c3+c4) dwin=dwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4==c1+c2+c3+c4) { ddraw=ddraw+1.0; cdraw=cdraw+1.0;}	
			
		if(((name1=='d'&&name2=='e')||(name1=='e'&&name2=='d'))&&(drep==5&&erep==5))
			if(dsum>esum) dwin=dwin+1.0;
			else if(dsum<esum) ewin=ewin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4>e1+e2+e3+e4) dwin=dwin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4==e1+e2+e3+e4) { ddraw=ddraw+1.0; edraw=edraw+1.0;}
		
		
		
		
		if(((name1=='a'&&name2=='b')||(name1=='b'&&name2=='a'))&&(arep==1&&brep==1))
			if(asum>bsum) awin=awin+1.0;
			else if(asum<bsum) bwin=bwin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4>b1+b2+b3+b4) awin=awin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4<b1+b2+b3+b4) bwin=bwin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4==b1+b2+b3+b4) { adraw=adraw+1.0; bdraw=bdraw+1.0;}
		
		if(((name1=='a'&&name2=='c')||(name1=='c'&&name2=='a'))&&(arep==1&&crep==1))
			if(asum>csum) awin=awin+1.0;
			else if(asum<csum) cwin=cwin+1.0;
			else if(asum==csum&&a1+a2+a3+a4>c1+c2+c3+c4) awin=awin+1.0;
			else if(asum==csum&&a1+a2+a3+a4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(asum==csum&&a1+a2+a3+a4==c1+c2+c3+c4) { adraw=adraw+1.0; cdraw=cdraw+1.0;}
			
		if(((name1=='a'&&name2=='d')||(name1=='d'&&name2=='a'))&&(arep==1&&drep==1))
			if(asum>dsum) awin=awin+1.0;
			else if(asum<dsum) dwin=dwin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4>d1+d2+d3+d4) awin=awin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4<d1+d2+d3+d4) dwin=dwin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4==d1+d2+d3+d4) { adraw=adraw+1.0; ddraw=ddraw+1.0;}
			
		if(((name1=='a'&&name2=='e')||(name1=='e'&&name2=='a'))&&(arep==1&&erep==1))
			if(asum>esum) awin=awin+1.0;
			else if(asum<esum) ewin=ewin+1.0;
			else if(asum==esum&&a1+a2+a3+a4>e1+e2+e3+e4) awin=awin+1.0;
			else if(asum==esum&&a1+a2+a3+a4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(asum==esum&&a1+a2+a3+a4==e1+e2+e3+e4) { adraw=adraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='b'&&name2=='c')||(name1=='c'&&name2=='b'))&&(brep==1&&crep==1))
			if(bsum>csum) bwin=bwin+1.0;
			else if(bsum<csum) cwin=cwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4>c1+c2+c3+c4) bwin=bwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4==c1+c2+c3+c4) { bdraw=bdraw+1.0; cdraw=cdraw+1.0;}
		
		if(((name1=='b'&&name2=='d')||(name1=='d'&&name2=='b'))&&(brep==1&&drep==1))
			if(bsum>dsum) bwin=bwin+1.0;
			else if(bsum<dsum) dwin=dwin+1.0;
			else if(bsum==dsum&&b1+b2+b3+b4>d1+d2+d3+d4) bwin=bwin+1.0;
			else if(bsum==dsum&&b1+b2+b3+b4<d1+d2+d3+d4) dwin=dwin+1.0;
			else if(bsum==dsum&&b1+b2+b3+b4==d1+d2+d3+d4) { bdraw=bdraw+1.0; ddraw=ddraw+1.0;}
		
		if(((name1=='b'&&name2=='e')||(name1=='e'&&name2=='b'))&&(brep==1&&erep==1))
			if(bsum>esum) bwin=bwin+1.0;
			else if(bsum<bsum) ewin=ewin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4>e1+e2+e3+e4) bwin=bwin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4==e1+e2+e3+e4) { bdraw=bdraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='c'&&name2=='e')||(name1=='e'&&name2=='c'))&&(erep==1&&crep==1))
			if(csum>esum) cwin=cwin+1.0;
			else if(csum<esum) ewin=ewin+1.0;
			else if(csum==esum&&c1+c2+c3+c4>e1+e2+e3+e4) cwin=cwin+1.0;
			else if(csum==esum&&c1+c2+c3+c4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(csum==esum&&c1+c2+c3+c4==e1+e2+e3+e4) { cdraw=cdraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='d'&&name2=='c')||(name1=='c'&&name2=='d'))&&(drep==1&&crep==1))
			if(dsum>csum) dwin=dwin+1.0;
			else if(dsum<csum) cwin=cwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4>c1+c2+c3+c4) dwin=dwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4==c1+c2+c3+c4) { ddraw=ddraw+1.0; cdraw=cdraw+1.0;}	
			
		if(((name1=='d'&&name2=='e')||(name1=='e'&&name2=='d'))&&(drep==1&&erep==1))
			if(dsum>bsum) dwin=dwin+1.0;
			else if(dsum<esum) ewin=ewin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4>e1+e2+e3+e4) dwin=dwin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4==e1+e2+e3+e4) { ddraw=ddraw+1.0; edraw=edraw+1.0;}
			
		
		
			
		if(((name1=='a'&&name2=='b')||(name1=='b'&&name2=='a'))&&(arep==2&&brep==2))
			if(asum>bsum) awin=awin+1.0;
			else if(asum<bsum) bwin=bwin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4>b1+b2+b3+b4) awin=awin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4<b1+b2+b3+b4) bwin=bwin+1.0;
			else if(asum==bsum&&a1+a2+a3+a4==b1+b2+b3+b4) { adraw=adraw+1.0; bdraw=bdraw+1.0;}
		
		if(((name1=='a'&&name2=='c')||(name1=='c'&&name2=='a'))&&(arep==2&&crep==2))
			if(asum>csum) awin=awin+1.0;
			else if(asum<csum) cwin=cwin+1.0;
			else if(asum==csum&&a1+a2+a3+a4>c1+c2+c3+c4) awin=awin+1.0;
			else if(asum==csum&&a1+a2+a3+a4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(asum==csum&&a1+a2+a3+a4==c1+c2+c3+c4) { adraw=adraw+1.0; cdraw=cdraw+1.0;}
			
		if(((name1=='a'&&name2=='d')||(name1=='d'&&name2=='a'))&&(arep==2&&drep==2))
			if(asum>dsum) awin=awin+1.0;
			else if(asum<dsum) dwin=dwin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4>d1+d2+d3+d4) awin=awin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4<d1+d2+d3+d4) dwin=dwin+1.0;
			else if(asum==dsum&&a1+a2+a3+a4==d1+d2+d3+d4) { adraw=adraw+1.0; ddraw=ddraw+1.0;}
			
		if(((name1=='a'&&name2=='e')||(name1=='e'&&name2=='a'))&&(arep==2&&erep==2))
			if(asum>esum) awin=awin+1.0;
			else if(asum<esum) ewin=ewin+1.0;
			else if(asum==esum&&a1+a2+a3+a4>e1+e2+e3+e4) awin=awin+1.0;
			else if(asum==esum&&a1+a2+a3+a4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(asum==esum&&a1+a2+a3+a4==e1+e2+e3+e4) { adraw=adraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='b'&&name2=='c')||(name1=='c'&&name2=='b'))&&(brep==2&&crep==2))
			if(bsum>csum) bwin=bwin+1.0;
			else if(bsum<csum) cwin=cwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4>c1+c2+c3+c4) bwin=bwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(bsum==csum&&b1+b2+b3+b4==c1+c2+c3+c4) { bdraw=bdraw+1.0; cdraw=cdraw+1.0;}
		
		if(((name1=='b'&&name2=='d')||(name1=='d'&&name2=='b'))&&(brep==2&&drep==2))
			if(bsum>dsum) bwin=bwin+1.0;
			else if(bsum<dsum) dwin=dwin+1.0;
			else if(bsum==dsum&&b1+b2+b3+b4>d1+d2+d3+d4) bwin=bwin+1.0;
			else if(bsum==dsum&&b1+b2+b3+b4<d1+d2+d3+d4) dwin=dwin+1.0;
			else if(bsum==dsum&&b1+b2+b3+b4==d1+d2+d3+d4) { bdraw=bdraw+1.0; ddraw=ddraw+1.0;}
		
		if(((name1=='b'&&name2=='e')||(name1=='e'&&name2=='b'))&&(brep==2&&erep==2))
			if(bsum>esum) bwin=bwin+1.0;
			else if(bsum<esum) ewin=ewin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4>e1+e2+e3+e4) bwin=bwin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(bsum==esum&&b1+b2+b3+b4==e1+e2+e3+e4) { bdraw=bdraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='c'&&name2=='e')||(name1=='e'&&name2=='c'))&&(erep==2&&crep==2))
			if(csum>esum) cwin=cwin+1.0;
			else if(csum<esum) ewin=ewin+1.0;
			else if(csum==esum&&c1+c2+c3+c4>e1+e2+e3+e4) cwin=cwin+1.0;
			else if(csum==esum&&c1+c2+c3+c4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(csum==esum&&c1+c2+c3+c4==e1+e2+e3+e4) { cdraw=cdraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='d'&&name2=='c')||(name1=='c'&&name2=='d'))&&(drep==2&&crep==2))
			if(dsum>csum) dwin=dwin+1.0;
			else if(dsum<csum) cwin=cwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4>c1+c2+c3+c4) dwin=dwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4<c1+c2+c3+c4) cwin=cwin+1.0;
			else if(dsum==csum&&d1+d2+d3+d4==c1+c2+c3+c4) { ddraw=ddraw+1.0; cdraw=cdraw+1.0;}	
			
		if(((name1=='d'&&name2=='e')||(name1=='e'&&name2=='d'))&&(drep==2&&erep==2))
			if(dsum>bsum) dwin=dwin+1.0;
			else if(dsum<esum) ewin=ewin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4>e1+e2+e3+e4) dwin=dwin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4<e1+e2+e3+e4) ewin=ewin+1.0;
			else if(dsum==esum&&d1+d2+d3+d4==e1+e2+e3+e4) { ddraw=ddraw+1.0; edraw=edraw+1.0;}
		
		
		
		
		if(((name1=='a'&&name2=='b')||(name1=='b'&&name2=='a'))&&(arep==3&&brep==3))
			if(asum>bsum) awin=awin+1.0;
			else if(asum<bsum) bwin=bwin+1.0;
			else if(asum==bsum&&a1*a1+a2*a2+a3*a3+a4*a4>b1*b1+b2*b2+b3*b3+b4*b4) awin=awin+1.0;
			else if(asum==bsum&&a1*a1+a2*a2+a3*a3+a4*a4<b1*b1+b2*b2+b3*b3+b4*b4) bwin=bwin+1.0;
			else if(asum==bsum&&a1*a1+a2*a2+a3*a3+a4*a4==b1*b1+b2*b2+b3*b3+b4*b4) { adraw=adraw+1.0; bdraw=bdraw+1.0;}
		
		if(((name1=='a'&&name2=='c')||(name1=='c'&&name2=='a'))&&(arep==3&&crep==3))
			if(asum>csum) awin=awin+1.0;
			else if(asum<csum) cwin=cwin+1.0;
			else if(asum==csum&&a1*a1+a2*a2+a3*a3+a4*a4>c1*c1+c2*c2+c3*c3+c4*c4) awin=awin+1.0;
			else if(asum==csum&&a1*a1+a2*a2+a3*a3+a4*a4<c1*c1+c2*c2+c3*c3+c4*c4) cwin=cwin+1.0;
			else if(asum==csum&&a1*a1+a2*a2+a3*a3+a4*a4==c1*c1+c2*c2+c3*c3+c4*c4) { adraw=adraw+1.0; cdraw=cdraw+1.0;}
			
		if(((name1=='a'&&name2=='d')||(name1=='d'&&name2=='a'))&&(arep==3&&drep==3))
			if(asum>dsum) awin=awin+1.0;
			else if(asum<dsum) dwin=dwin+1.0;
			else if(asum==dsum&&a1*a1+a2*a2+a3*a3+a4*a4>d1*d1+d2*d2+d3*d3+d4*d4) awin=awin+1.0;
			else if(asum==dsum&&a1*a1+a2*a2+a3*a3+a4*a4<d1*d1+d2*d2+d3*d3+d4*d4) dwin=dwin+1.0;
			else if(asum==dsum&&a1*a1+a2*a2+a3*a3+a4*a4==d1*d1+d2*d2+d3*d3+d4*d4) { adraw=adraw+1.0; ddraw=ddraw+1.0;}
			
		if(((name1=='a'&&name2=='e')||(name1=='e'&&name2=='a'))&&(arep==3&&erep==3))
			if(asum>esum) awin=awin+1.0;
			else if(asum<esum) ewin=ewin+1.0;
			else if(asum==esum&&a1*a1+a2*a2+a3*a3+a4*a4>e1*e1+e2*e2+e3*e3+e4*e4) awin=awin+1.0;
			else if(asum==esum&&a1*a1+a2*a2+a3*a3+a4*a4<e1*e1+e2*e2+e3*e3+e4*e4) ewin=ewin+1.0;
			else if(asum==esum&&a1*a1+a2*a2+a3*a3+a4*a4==e1*e1+e2*e2+e3*e3+e4*e4) { adraw=adraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='b'&&name2=='c')||(name1=='c'&&name2=='b'))&&(brep==3&&crep==3))
			if(bsum>csum) bwin=bwin+1.0;
			else if(bsum<csum) cwin=cwin+1.0;
			else if(bsum==csum&&b1*b1+b2*b2+b3*b3+b4*b4>c1*c1+c2*c2+c3*c3+c4*c4) bwin=bwin+1.0;
			else if(bsum==csum&&b1*b1+b2*b2+b3*b3+b4*b4<c1*c1+c2*c2+c3*c3+c4*c4) cwin=cwin+1.0;
			else if(bsum==csum&&b1*b1+b2*b2+b3*b3+b4*b4==c1*c1+c2*c2+c3*c3+c4*c4) { bdraw=bdraw+1.0; cdraw=cdraw+1.0;}
		
		if(((name1=='b'&&name2=='d')||(name1=='d'&&name2=='b'))&&(brep==3&&drep==3))
			if(bsum>dsum) bwin=bwin+1.0;
			else if(bsum<dsum) dwin=dwin+1.0;
			else if(bsum==dsum&&b1*b1+b2*b2+b3*b3+b4*b4>d1*d1+d2*d2+d3*d3+d4*d4) bwin=bwin+1.0;
			else if(bsum==dsum&&b1*b1+b2*b2+b3*b3+b4*b4<d1*d1+d2*d2+d3*d3+d4*d4) dwin=dwin+1.0;
			else if(bsum==dsum&&b1*b1+b2*b2+b3*b3+b4*b4==d1*d1+d2*d2+d3*d3+d4*d4) { bdraw=bdraw+1.0; ddraw=ddraw+1.0;}
		
		if(((name1=='b'&&name2=='e')||(name1=='e'&&name2=='b'))&&(brep==3&&erep==3))
			if(bsum>esum) bwin=bwin+1.0;
			else if(bsum<esum) ewin=ewin+1.0;
			else if(bsum==esum&&b1*b1+b2*b2+b3*b3+b4*b4>e1*e1+e2*e2+e3*e3+e4*e4) bwin=bwin+1.0;
			else if(bsum==esum&&b1*b1+b2*b2+b3*b3+b4*b4<e1*e1+e2*e2+e3*e3+e4*e4) ewin=ewin+1.0;
			else if(bsum==esum&&b1*b1+b2*b2+b3*b3+b4*b4==e1*e1+e2*e2+e3*e3+e4*e4) { bdraw=bdraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='c'&&name2=='e')||(name1=='e'&&name2=='c'))&&(erep==3&&crep==3))
			if(csum>esum) cwin=cwin+1.0;
			else if(csum<esum) ewin=ewin+1.0;
			else if(csum==esum&&c1*c1+c2*c2+c3*c3+c4*c4>e1*e1+e2*e2+e3*e3+e4*e4) cwin=cwin+1.0;
			else if(csum==esum&&c1*c1+c2*c2+c3*c3+c4*c4<e1*e1+e2*e2+e3*e3+e4*e4) ewin=ewin+1.0;
			else if(csum==esum&&c1*c1+c2*c2+c3*c3+c4*c4==e1*e1+e2*e2+e3*e3+e4*e4) { cdraw=cdraw+1.0; edraw=edraw+1.0;}
			
		if(((name1=='d'&&name2=='c')||(name1=='c'&&name2=='d'))&&(drep==3&&crep==3))
			if(dsum>csum) dwin=dwin+1.0;
			else if(dsum<csum) cwin=cwin+1.0;
			else if(dsum==csum&&d1*d1+d2*d2+d3*d3+d4*d4>c1*c1+c2*c2+c3*c3+c4*c4) dwin=dwin+1.0;
			else if(dsum==csum&&d1*d1+d2*d2+d3*d3+d4*d4<c1*c1+c2*c2+c3*c3+c4*c4) cwin=cwin+1.0;
			else if(dsum==csum&&d1*d1+d2*d2+d3*d3+d4*d4==c1*c1+c2*c2+c3*c3+c4*c4) { ddraw=ddraw+1.0; cdraw=cdraw+1.0;}	
			
		if(((name1=='d'&&name2=='e')||(name1=='e'&&name2=='d'))&&(drep==3&&erep==3))
			if(dsum>bsum) dwin=dwin+1.0;
			else if(dsum<esum) ewin=ewin+1.0;
			else if(dsum==esum&&d1*d1+d2*d2+d3*d3+d4*d4>e1*e1+e2*e2+e3*e3+e4*e4) dwin=dwin+1.0;
			else if(dsum==esum&&d1*d1+d2*d2+d3*d3+d4*d4<e1*e1+e2*e2+e3*e3+e4*e4) ewin=ewin+1.0;
			else if(dsum==esum&&d1*d1+d2*d2+d3*d3+d4*d4==e1*e1+e2*e2+e3*e3+e4*e4) { ddraw=ddraw+1.0; edraw=edraw+1.0;}
			
	}
}
	awonout = (awin/acounter)*100.0; bwonout = (bwin/bcounter)*100.0; cwonout = (cwin/ccounter)*100.0; dwonout = (dwin/dcounter)*100.0; ewonout = (ewin/ecounter)*100.0;
	
	adrawout = (adraw/acounter)*100.0; bdrawout = (bdraw/bcounter)*100.0; cdrawout = (cdraw/ccounter)*100.0; ddrawout = (ddraw/dcounter)*100.0; edrawout = (edraw/ecounter)*100.0;
	
	alostout = 100.0-(awonout+adrawout); blostout = 100.0-(bwonout+bdrawout); clostout = 100.0-(cwonout+cdrawout); dlostout = 100.0-(dwonout+ddrawout); elostout = 100.0-(ewonout+edrawout);
	
	if(awonout>0&&adrawout>0&&alostout>0) std::cout << "gracz a" << std::endl << "    wygrane: " << awonout << "%" << std::endl << "    remisy: " << adrawout << "%" << std::endl << "    przegrane: " << alostout << "%" <<  std::endl << std::endl;
	else if(awonout>0&&adrawout>0&&alostout==0) std::cout << "gracz a" << std::endl << "    wygrane: " << awonout << "%" << std::endl << "    remisy: " << adrawout << "%" <<  std::endl << std::endl;
	else if(awonout>0&&adrawout==0&&alostout==0) std::cout << "gracz a" << std::endl << "    wygrane: " << awonout << "%" <<  std::endl << std::endl;
	else if(awonout==0&&adrawout>0&&alostout>0) std::cout << "gracz a" << std::endl << "    remisy: " << adrawout << "%" << std::endl << "    przegrane: " << alostout << "%" <<  std::endl << std::endl;
	else if(awonout==0&&adrawout==0&&alostout>0) std::cout << "gracz a" << std::endl << "    przegrane: " << alostout << "%" <<  std::endl << std::endl;
	else if(awonout==0&&adrawout>0&&alostout==0) std::cout << "gracz a" << std::endl << "    remisy: " << adrawout << "%" << std::endl << std::endl;
	else if(awonout>0&&adrawout==0&&alostout>0)  std::cout << "gracz a" << std::endl << "    wygrane: " << awonout << "%" << std::endl << "    przegrane: " << alostout << "%" <<  std::endl << std::endl;
	
	if(bwonout>0&&bdrawout>0&&blostout>0) std::cout << "gracz b" << std::endl << "    wygrane: " << bwonout << "%" << std::endl << "    remisy: " << bdrawout << "%" << std::endl << "    przegrane: " << blostout << "%" <<  std::endl << std::endl;
	else if(bwonout>0&&bdrawout>0&&blostout==0) std::cout << "gracz b" << std::endl << "    wygrane: " << bwonout << "%" << std::endl << "    remisy: " << bdrawout << "%" <<  std::endl << std::endl;
	else if(bwonout>0&&bdrawout==0&&blostout==0) std::cout << "gracz b" << std::endl << "    wygrane: " << bwonout << "%" <<  std::endl << std::endl;
	else if(bwonout==0&&bdrawout>0&&blostout>0) std::cout << "gracz b" << std::endl << "    remisy: " << bdrawout << "%" << std::endl << "    przegrane: " << blostout << "%" <<  std::endl << std::endl;
	else if(bwonout==0&&bdrawout==0&&blostout>0) std::cout << "gracz b" << std::endl << "    przegrane: " << blostout << "%" <<  std::endl << std::endl;
	else if(bwonout==0&&bdrawout>0&&blostout==0) std::cout << "gracz b" << std::endl << "    remisy: " << bdrawout << "%" << std::endl << std::endl;
	else if(bwonout>0&&bdrawout==0&&blostout>0)  std::cout << "gracz b" << std::endl << "    wygrane: " << bwonout << "%" << std::endl << "    przegrane: " << blostout << "%" <<  std::endl << std::endl;
	
	if(cwonout>0&&cdrawout>0&&clostout>0) std::cout << "gracz c" << std::endl << "    wygrane: " << cwonout << "%" << std::endl << "    remisy: " << cdrawout << "%" << std::endl << "    przegrane: " << clostout << "%" <<  std::endl << std::endl;
	else if(cwonout>0&&cdrawout>0&&clostout==0) std::cout << "gracz c" << std::endl << "    wygrane: " << cwonout << "%" << std::endl << "    remisy: " << cdrawout << "%" <<  std::endl << std::endl;
	else if(cwonout>0&&cdrawout==0&&clostout==0) std::cout << "gracz c" << std::endl << "    wygrane: " << cwonout << "%" <<  std::endl << std::endl;
	else if(cwonout==0&&cdrawout>0&&clostout>0) std::cout << "gracz c" << std::endl << "    remisy: " << cdrawout << "%" << std::endl << "    przegrane: " << clostout << "%" <<  std::endl << std::endl;
	else if(cwonout==0&&cdrawout==0&&clostout>0) std::cout << "gracz c" << std::endl << "    przegrane: " << clostout << "%" <<  std::endl << std::endl;
	else if(cwonout==0&&cdrawout>0&&clostout==0) std::cout << "gracz c" << std::endl << "    remisy: " << cdrawout << "%" << std::endl << std::endl;
	else if(cwonout>0&&cdrawout==0&&clostout>0)  std::cout << "gracz c" << std::endl << "    wygrane: " << cwonout << "%" << std::endl << "    przegrane: " << clostout << "%" <<  std::endl << std::endl;
	
	if(dwonout>0&&ddrawout>0&&dlostout>0) std::cout << "gracz d" << std::endl << "    wygrane: " << dwonout << "%" << std::endl << "    remisy: " << ddrawout << "%" << std::endl << "    przegrane: " << dlostout << "%" <<  std::endl << std::endl;
	else if(dwonout>0&&ddrawout>0&&dlostout==0) std::cout << "gracz d" << std::endl << "    wygrane: " << dwonout << "%" << std::endl << "    remisy: " << ddrawout << "%" <<  std::endl << std::endl;
	else if(dwonout>0&&ddrawout==0&&dlostout==0) std::cout << "gracz d" << std::endl << "    wygrane: " << dwonout << "%" <<  std::endl << std::endl;
	else if(dwonout==0&&ddrawout>0&&dlostout>0) std::cout << "gracz d" << std::endl << "    remisy: " << ddrawout << "%" << std::endl << "    przegrane: " << dlostout << "%" <<  std::endl << std::endl;
	else if(dwonout==0&&ddrawout==0&&dlostout>0) std::cout << "gracz d" << std::endl << "    przegrane: " << dlostout << "%" <<  std::endl << std::endl;
	else if(dwonout==0&&ddrawout>0&&dlostout==0) std::cout << "gracz d" << std::endl << "    remisy: " << ddrawout << "%" << std::endl << std::endl;
	else if(dwonout>0&&ddrawout==0&&dlostout>0)  std::cout << "gracz d" << std::endl << "    wygrane: " << dwonout << "%" << std::endl << "    przegrane: " << dlostout << "%" <<  std::endl << std::endl;
	
	if(ewonout>0&&edrawout>0&&elostout>0) std::cout << "gracz e" << std::endl << "    wygrane: " << ewonout << "%" << std::endl << "    remisy: " << edrawout << "%" << std::endl << "    przegrane: " << elostout << "%" <<  std::endl << std::endl;
	else if(ewonout>0&&edrawout>0&&elostout==0) std::cout << "gracz e" << std::endl << "    wygrane: " << ewonout << "%" << std::endl << "    remisy: " << edrawout << "%" <<  std::endl << std::endl;
	else if(ewonout>0&&edrawout==0&&elostout==0) std::cout << "gracz e" << std::endl << "    wygrane: " << ewonout << "%" <<  std::endl << std::endl;
	else if(ewonout==0&&edrawout>0&&elostout>0) std::cout << "gracz e" << std::endl << "    remisy: " << edrawout << "%" << std::endl << "    przegrane: " << elostout << "%" <<  std::endl << std::endl;
	else if(ewonout==0&&edrawout==0&&elostout>0) std::cout << "gracz e" << std::endl << "    przegrane: " << elostout << "%" <<  std::endl << std::endl;
	else if(ewonout==0&&edrawout>0&&elostout==0) std::cout << "gracz e" << std::endl << "    remisy: " << edrawout << "%" << std::endl << std::endl;
	else if(ewonout>0&&edrawout==0&&elostout>0)  std::cout << "gracz e" << std::endl << "    wygrane: " << ewonout << "%" << std::endl << "    przegrane: " << elostout << "%" <<  std::endl << std::endl;

	
	return 0;
}
