#include <iostream> 
#include <vector>


void triangle(std::vector<std::vector<int>> &tableau, int i, int j, int m, int n){
//std::cout << i << " et " << j << " et " << m << " et " << n << std::endl;
if (((m-i) ==1) && ((n-j)==1)){
  //std::cout << i << " " << j << "\n" << std::endl;
   tableau[i][j] = 1;
   tableau[i+1][j] = 1;
   tableau[i][j+1] = 1;
   return;

}
int moitligne = i+(((m-i)/2)+1);
int moitcolonne = j+(((n-j)/2)+1);
triangle(tableau,i,j,moitligne-1,moitcolonne-1);
triangle(tableau,i,moitcolonne,moitligne-1,n);
triangle(tableau,moitligne,j,m,moitcolonne-1);

}


int main(){

int nbElement;
std::cin >> nbElement; 
if (nbElement ==1){
  std::cout << "#";
  
}else{
std::vector<int> ligne = std::vector<int>(nbElement);

std::vector<std::vector<int>> tableau;

for(int i = 0; i< nbElement; i++){
   tableau.push_back(ligne);
   
}

int i,j,m,n;
i = 0;
j = 0;
m = nbElement-1;
n = nbElement-1;
triangle(tableau, i,j,m,n);

for(std::vector<int> l : tableau){
   for (int p : l){
      if (p == 1){
        std::cout << "#";
      }
      else{
        std::cout << " ";
      }
      //std::cout << p;
   }
   std::cout << "\n";
}
}
}
