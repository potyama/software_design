#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int length, height,area, question,cnt;
	int upper_len, lower_len;
	
	//case 1 is square, 2 is triangle, 3 is trapezium
	
	while(cnt!=3){
		switch(rand()%3){
		case 0:
			length = rand()%15+10;
			if(length%2==0){
				height = rand()%15+10;
				area = length * height;
				printf("Square Length = %d, Height = %d, Area = %d\n", length,height,area);
				cnt++;
				break;
			}
			else{
				length += 1;
				height = rand()%15+10;
				area = length * height;
				printf("Square Length = %d, Height = %d, Area = %d\n", length,height,area);
				cnt++;
				break;
			}
		
		case 1:
			length = rand()%15+10;
			if(length%2==0){
				height = rand()%15+10;
				area = 0.5 * length * height;
				printf("Triangle Length = %d, Height = %d, Area = %d\n", length,height,area);
				cnt++;
				break;
			}
			else{
				length += 1;
				height = rand()%15+10;
				area = 0.5 * length * height;
				printf("Triangle Length = %d, Height = %d, Area = %d\n", length,height,area);
				cnt++;
				break;
			}
		case 2:
			height = rand()%15+10;
			if(height%2==0){
				upper_len = rand()%15+10;
				lower_len = rand()%10+5;
				area = (0.5 * lower_len * height) + (upper_len * height);
				printf("Trapezium Upper Length = %d, Lower Length = %d, Height = %d, Area = %d\n", upper_len, (lower_len + upper_len), height, area);
				cnt++;
				break;
			}
			else{
				height += 1;
				upper_len = rand()%15+10;
				lower_len = rand()%10+5;
				area = (0.5 * lower_len * height) + (upper_len * height);
				printf("Trapezium Upper Length = %d, Lower Length = %d, Height = %d, Area = %d\n", upper_len, (lower_len + upper_len), height, area);
				cnt++;
				break;
			}	
	}
	}
	
	return 0;
	
}