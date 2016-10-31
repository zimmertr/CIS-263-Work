/*#include<map>
#include<string.h>
#include<stdio.h>
#include<string>
using namespace std;

char cz[40],str[40],use[1000];
char data[1000][40];
map<string,int> name;
string now,t;
int l,N,n,num[1000];

void PRINT()    {
    int i;

    for(i=l-1;i>=0;i--){

	if(use[i]){
	    printf("%s%4d\n",data[i],num[i]);
	}
    }

    printf("AVAILABLE SHELF SPACE:        %4d\n\n",N-n);
    gets(str);
}

void ADD(){

    int k,temp=1,L=0;
    char ch;

    for(k=0;k<6;k++){
	scanf("%c",&ch);
    }

    gets(data[l]);
    sscanf(data[l]+30,"%d",&L);
    data[l][30]=0;
    n+=L;num[l]=L;

    t=data[l];
    name[t]=l;
    use[l]=1;
    k=0;

    while(n>N){
	if(use[k]){

	    use[k]=0;
	    n-=num[k];
	}
	k++;
    }
    l++;
}

void CHECKOUT(){
    int k,i;char ch;
    scanf("%c",&ch);
    gets(str);

    for(i=strlen(str);i<30;i++){
	str[i]=' ';
    }

    str[30]=0;
    t=str;
    k=name[t];
    use[k]=0;
    n-=num[k];
}

void RETURN(){

    int k,i;
    char ch;

    for(i=0;i<3;i++){
	scanf("%c",&ch);
    }

    gets(str);

    for(i=strlen(str);i<30;i++){
	str[i]=' ';
    }

    str[30]=0;
    t=str;
    k=name[t];

    for(i=0;i<31;i++){
	data[l][i]=data[k][i];
    }

    use[l]=1;num[l]=num[k];
    n+=num[l];
    k=0;

    while(n>N){
	if(use[k]){
	    use[k]=0;
	    n-=num[k];
	}
	k++;
    }
    l++;
}

int main(){
    //freopen("bbbbbbbbbb.txt","w",stdout);

    scanf("%d",&N);n=0;l=0;
    name.clear();
    memset(use,0,sizeof(use));

    while(scanf("%s",cz)!=EOF){

	now=cz;

	if(now=="PRINT"){
	    PRINT();
	}
	else if(now=="ADD"){
	    ADD();
	}
	else if(now=="CHECKOUT"){
	    CHECKOUT();
	}
	else if(now=="RETURN"){
	    RETURN();
	}
    }

    return 0;
}*/
