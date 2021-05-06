//IMPLEMENT HASHTABLE

#include<stdio.h>
#include<stdlib.h>
struct HASH{
	int* table;
	int m;
	int c1;
	int c2;
	int R;
};
int* HASHTABLE(int m){
	int* T = (int*)malloc(sizeof(int)*m);
	for(int i = 0;i<m;i++){
		T[i] = -1;
	}
	return T;
}

int GETPRIME(int n){
	if (n <= 1) 
		return 0; 
	if (n <= 3) 
		return 1; 
  
	if (n % 2 == 0 || n % 3 == 0) 
		return 0; 
  
	for (int i = 5; i * i <= n; i = i + 2) 
		if (n % i == 0) 
			return 0; 

	return 1; 
}
struct HASH* INSERT(struct HASH* T,int k){
	int val = k%T->m;

	if(T->table[val] == -1){
		T->table[val] = k;
		return T;
	}
	else if(T->c1 >=0){
		for(int i = 1;i<T->m;++i){
			int value = (val + T->c1 * i + T->c2 * i * i)%T->m;
			if(T->table[value] == -1){
				T->table[value] = k;
				break;
			}
		}
		return T;	
	}
	else{
		
		if(T->table[val] == -1){
			T->table[val] = k;
			return T;
		}
		int R = T->R;
		for(int j = 0 ; j<T->m ; j++){
			int h2 = R - (k%R);
			int value = (val + j*h2)%T->m;
			if(T->table[value] == -1){
				T->table[value] = k;
				break;
			} 
		}
		return T;
	}
	

}

int SEARCH(struct HASH* T,int k){
	int val = k%T->m;
	if(T->table[val] == k)return 1;
	else if(T->c1 >=0){
		for(int i = 1;i<T->m;++i){
			int value = (val + T->c1 * i + T->c2 * i * i)%T->m;
			if(T->table[value] == -1)break;
			else if(T->table[value] == k)return 1;
			
		}
	}
	else{
		int R = T->R;
		for(int j = 1; j<T->m ; j++){
			int h2 = R - (k%R);
			int value = (val + j*h2)%T->m;
			if(T->table[value] == -1)break;
			else if(T->table[value] == k)return 1;
		
		}
	}
	return -1;

}

struct HASH* DELETE(struct HASH* T,int k){
	int val = k%T->m;
	if(T->table[val] == k){
		T->table[val] = -1;
		return T;
	}
	else if(T->c1 >=0){
		for(int i = 1;i<T->m;++i){
			int value = (val + T->c1 * i + T->c2 * i * i)%T->m;
			if(T->table[value] == k){
				T->table[value] = -1;
				return T;
			}
			
		}
	}
	
	else{
		int R = T->R;
		for(int j = 1; j<T->m ; j++){
			int h2 = R - (k%R);
			int value = (val + j*h2)%T->m;
			if(T->table[value] == k){
				T->table[value] = -1;
				return T;
			}
		
		}
		
	}
	return T;

}
void PRINT(struct HASH* T){
	for(int i = 0 ;i<T->m;++i){
		if(T->table[i] == -1){
			printf("%d()\n",i);
		}
		else printf("%d(%d)\n",i,T->table[i]);
	}
}

void main(){
	char x;
	int m;
	int c1,c2;
	char y;
	int k;
	scanf("%c",&x);
	scanf("%d",&m);
	
	struct HASH* T = (struct HASH*)malloc(sizeof(struct HASH));
	T->table = HASHTABLE(m);
	T->m = m;
	T->c1 = -1;
	T->c2 = -1;
	T->R =-1;
	if(x=='a'){
		scanf("%d %d",&c1,&c2);
		T->c1 = c1;
		T->c2 = c2;
	}
	else {
		for(int i = T->m-10 ; i<T->m ; ++i){
			if(GETPRIME(i))T->R=i;
		}
	}
	while(1){
		scanf("%c",&y);
		
		if(y == 'i'){
			scanf("%d",&k);
			T = INSERT(T,k);
			
		}
		if(y == 's'){
			scanf("%d",&k);
			printf("%d",SEARCH(T,k));
			printf("\n");
		}
		if(y == 'd'){
			scanf("%d",&k);
			T = DELETE(T,k);
		}
		if(y == 'p'){PRINT(T);}
		if(y == 't'){break;}
	
	}

}
