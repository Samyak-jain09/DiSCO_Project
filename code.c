// INPUT FROM CSV
// OUTPUT IN CSV
// VISUALIZE
// WHILE(1) KE SARE SWITCH
// DISPLAY
// KHUD KE FUNCTION


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stddef.h>
#include<stdbool.h>


int size;


int matrix[600][600];
int trans[600][600];
char name[600][100];

/*void plot(char * fname){
    int pid;
    if((pid = fork())==0){
        if(execlp("python", "python","visualise.py",fname,(char*)NULL)==-1){
        	execlp("python3", "python3","visualise.py",fname,(char*)NULL);
        };
    }
    exit(0);
}
*/
int fileOut(int reqMatrix[][size]){
FILE *fp;

int i,j;



fp=fopen("newCSV.csv","w+");



for(i=0;i<size;i++){
if(i==0){
    for(int k=0;k<size;++k){
            fprintf(fp,",");
            for(int j=0;j<100;j++){
            if(name[k][j]=='\0'){
             break;
             }
            fprintf(fp,"%c",name[k][j]);

    }

    }
}

fprintf(fp,"\n");
    for(int j=0;j<100;j++){
            if(name[i][j]=='\0'){
             break;
             }
            fprintf(fp,"%c",name[i][j]);

    }
    for(j=0;j<size;j++)

        fprintf(fp,",%d ",reqMatrix[i][j]);

    }

fclose(fp);


}

void warshall() {
	int i,j,k;
	for (k=1;k<=size;k++)
	  for (i=1;i<=size;i++)
	   for (j=1;j<=size;j++)
	    trans[i][j]=max(trans[i][j],trans[i][k]&& trans[k][j]);
}
int max(int a,int b) {
	;
	if(a>b)
	 return(a); else
	 return(b);
}

void y(){
    printf("\nYES\n");
}

void n(){
    printf("\nNO\n");
}

int disp_main(){
printf("\n--------MAIN--------\n");
printf("1. Does every website has a link to itself\n2. Is it possible to always return back to the previous website from the current website in one step.\n3. Does every website has all the links to the websites which are reachable from it?\n4. Does there exist any website that contains a link to itself?\n5. Is it impossible to return to the previous website from the current website in one step?\n6. Is it impossible to return to the previous website from the current website in one step(excluding the cases where the current and the previous website is same)?\n7. Is it possible to divide the network  into multiple pieces such that website in a piece is reachable from every other website in that piece?\n8. Is this relation an example of a poset?\n9. Exit\n");
int input;
printf("Please select from the choices given above\n");
scanf("%d", &input);
return input;
}

int disp_menu2(){
printf("\n--------MENU2--------\n");
printf("\nDo you want to visualize how the network will look if we add minimum links to satisfy the property?(If yes, display the graph, else return to Main Menu)\n");
int input;
printf("Please select from the choices given above(0 for no and 1 for yes)\n");
scanf("%d", &input);
return input;

}
int disp_menu3(){
printf("\n--------MENU3--------\n");
printf("\nDo you want to know the nodes in each piece?(List all the pieces and their corresponding websites else return to Main Menu)\n");
int input;
printf("Please select from the choices given above(0 for no and 1 for yes)\n");
scanf("%d", &input);
return input;

}

int disp_menu4(){
printf("\n--------MENU4--------\n");
printf("\n1. Display the hasse diagram.\n2. Display the website whose link is available in every website.\n3. Display the website which has links of every website.\n4. Display the website that do not have links to any other website except itself.\n5. Display the website that can not be reached from any other website except itself.\n6. Given some website display the websites which are reachable from all of them.(Take some input from the user and display the result)\n7. Given some websites, display the websites from which you can reach all those websites.(Process similar to 5)\n8. Is this relation an example of  lattice?\n9. Return to Main Menu\n");
int input;
printf("Please select from the choices given above\n");
scanf("%d", &input);
return input;

}
int disp_menu5(){
printf("\n--------MENU5--------\n");
printf("\n1. Given 2 websites A and B, display the website which is reachable by both A and B and can also reach to all such websites that A and B can reach.\n2. Given 2 websites A and B, display the website which can reach to both A and B and is also reachable from all such websites which can reach to both A and B.\n3. Is the lattice distributive?\n4. Return to Menu4\n");

int input;
printf("Please select from the choices given above\n");
scanf("%d", &input);
return input;


}
int main_1(){
    bool ans = true;
    for(int i=0 ; i<size ; i++){
        if(matrix[i][i]==0){
            ans = false;
            break;
        }
    }
    if(ans){
        y();
        return 1;
    }else{
        n();
        return 0;
    }
}





int main_2(){
  int transpose[size][size];
  for(int i=0;i<size;++i){
    for(int j=0;j<size;++j){
       transpose[j][i]=matrix[i][j];
       }
     }
   int isSymmetric = 1;
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(matrix[row][col] != transpose[row][col]){
                isSymmetric = 0;
            }
        }

    }
    if(isSymmetric==1){
     // displayMain();
     y();
     return 1;
     }
     n();
    return 0;
}

int main_3(){
int out = 1;
for(int i=0; i<size; i++)
	for(int j=0; j<size;j++)
		if(!matrix[i][j]==trans[i][j]){
			out =0;
}
if(out==1)
y();
else
n();
}

void main_4(){

    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            if(i==j && matrix[i][j]==1){
             y();
             return;
            }
        }
    }
    n();
    return;

}

void main_5(){
    bool ans = false;
    for(int i=0 ; i<size ; i++){
        for(int j=0 ; j<size ; j++){
            if(matrix[i][j]==1 && matrix[j][i]==1){
                ans = true;
                break;
            }
        }
    }
    if(ans){
        n();
    }else{
        y();
    }
}


void main_6(){
  int transpose[size][size];
  for(int i=0;i<size;++i){
    for(int j=0;j<size;++j){
       transpose[j][i]=matrix[i][j];
       }
     }

    int isSymmetric = 1;
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(matrix[row][col] != transpose[row][col]&& row!=col){
                isSymmetric = 0;
            }
        }}
     if(isSymmetric==1){
     y();

     }
     else{
         n();
     }


}

int main_7(){

}



int main_8(){
  //reflexive
  int isReflexive=1;
  for(int i=0;i<size;++i){
      for(int j=0;j<size;++j){
          if(i==j && matrix[i][j]!=1)
           isReflexive=0;
           break;
      }
  }

  //transitive
  bool trans=true;
  for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++)
            {
                if ((i!=j && j!=k) && (matrix[i][j] == 1 && matrix[j][k] == 1)){
                    if(matrix[i][k]!=1)
                        trans = false;
                }

            }
        }
    }

 //antiSymmetric
 int symmetric=1;
  for(int i=0;i<size;++i){
      for(int j=0;j<size;++j){
          if(i!=j && matrix[i][j]!= matrix[j][i])
            symmetric=0;
      }
  }

if(symmetric==0 && trans && isReflexive==1){
  y();
 return 1;

}
n();
return 0;
}

//void main_9(){
//    break;
//}

void menu3(int arr[], int m, char* websites[]){
    for(int i=0 ; i<m ; i++){
        printf("Website no. %d - %s\n", arr[i]+1,websites[i]);
    }
}
void menu4_1(){
    int hasse[size][size];
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            hasse[i][j]=matrix[i][j];
        }
    }
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            for(int k=0;k<size;++k){
                if(hasse[i][j]==1 && i==j)
                 hasse[i][j]=0;
                if((i!=j && j!=k) && hasse[i][j] == 1 && hasse[j][k] == 1 && hasse[i][k] == 1)
                  hasse[i][k]=0;


            }
        }
    }
    //output the hasse matrix to a nes csv
    fileOut(hasse);
    //plot("file_name.csv");
}




void menu4_2(){
       for(int i=0 ; i<size ; i++){
         int counter=0;

         for(int j = 0; j<size;j++){
            if(matrix[j][i]==1){
            counter++;
            }
        if(counter ==size){
            for(int j=0; j<100;j++){
              if(name[i][j]=='\0'){
                printf("\n");
              break;
             }
                printf("%c",name[i][j]);
            }
            }

        }
    }
}

void menu4_3(){
    for(int i=0 ; i<size ; i++){
        bool ans = true;
        for(int j=0 ; j<size ; j++){
            if(matrix[i][j]==0){
                ans = false;
                break;
            }
        }
        if(!ans) continue;
        for(int j=0; j<100;j++){
            if(name[i][j]=='\0'){
                printf("\n");
                break;
            }
            printf("%c",name[i][j]);
        }
    }
}






void menu4_4(){
    for(int i=0;i<size;++i){
        int x=0;
        if(matrix[i][i]==1){
        for(int j=0;j<size;++j){
            if(matrix[i][j]==1 && i!=j)
             x++;
        }
        if(x==0){
             for(int j=0; j<100;j++){
            if(name[i][j]=='\0'){
                printf("\n");
                break;
            }
            printf("%c",name[i][j]);
        }
          }


        }

    }
}



void menu4_5(){
for(int i=0;i<size;i++){
	int ans =1;
	for(int j=0;j<size;j++){
		if(matrix[j][i]==1&&i!=j)
			ans = 0;
}
if(ans==1){
for(int j=0; j<100;j++){
            if(name[i][j]=='\0'){
                printf("\n");
                break;
            }
            printf("%c",name[i][j]);
        }
}
}
}



void menu4_6(){
    printf("Enter the number of websites\n");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter the indices of the websites(starting from 0)\n");
    for(int i=0 ; i<n ; i++){
        int x;
        scanf("%d",&x);
        a[i] = x;
    }
    //for(int i=0 ; i<n ; i++) printf("%d  \n",a[i]);

    int result[size];
    for(int i=0 ; i<size ; i++) result[i]=0;
    for(int i=0 ; i<n ; i++){
        int row = a[i];
        for(int j=0 ; j<size ; j++){
            if(trans[row][j]==0) result[j]=1;
        }
    }
    for(int i=0 ; i<size ; i++){
        if(result[i]==0)
            for(int j=0; j<100;j++){
            if(name[i][j]=='\0'){
                printf("\n");
                break;
            }
            printf("%c",name[i][j]);
        }
}
    }



void menu4_7(){
    printf("Enter the number of websites\n");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter the indices of the websites (starting from 0)\n");
    for(int i=0 ; i<n ; i++){
        int x;
        scanf("%d",&x);
        a[i] = x;
    }
    int result[size];
    for(int i=0;i<size;++i){
        result[i]=0;
    }
    for(int i=0;i<n;++i){
        int col=a[i];
        for(int j=0;j<size;++j){
            if(trans[j][col]==1)
              result[j]++;

        }
    }
    int counter=0;
    for(int i=0;i<size;++i){
        if(result[i]==n){
             for(int j=0; j<100;j++){
            if(name[i][j]=='\0'){
                printf("\n");
                break;
            }
            printf("%c",name[i][j]);
        }
        }
        else
         counter++;

    }
    if(counter==n)
     printf("No such website exist\n");
}


int menu4_8(){

}

void menu5_1(){
    int a,b;
    printf("Enter index of website A\n");
    scanf("%d",&a);
    printf("Enter index of website B\n");
    scanf("%d",&b);

    int result[size];
    for(int j=0 ; j<size ; j++){
        if(trans[a][j]==0) result[j]=1;
    }
    for(int j=0 ; j<size ; j++){
        if(trans[b][j]==0) result[j]=1;
    }

    for(int i=0 ; i<size ; i++){
        int ans = 1;
        if(result[i]==1) continue;
        for(int j=0 ; j<size ; j++){
            if(result[j]==1) continue;
            if(trans[i][j]==0){
                ans = 0;
                break;
            }
        }
        if(ans==1){
            printf("The required website index is %d.",i);
            return;
        }
    }
    printf("No such website found.");
}

void menu5_2(){
// Take input of A and B and display output
     int a,b;
    printf("Enter index of website A\n");
    scanf("%d",&a);
    printf("Enter index of website B\n");
    scanf("%d",&b);

    int result[size];
    for(int i=0;i<size;++i){
        result[i]=0;

    }
    for(int i=0;i<size;++i){
        if(trans[a][i]==1 && trans[b][i]==1)
          result[i]=1;
    }
    int total=0;
    for(int i=0;i<size;++i){
        if(result[i]==1)
          total++;
    }
    for(int i=0;i<size;++i){
        if(result[i]==1){
            int x=0;
            for(int j=0;j<size;++j){
                if(result[j]==1 && i!=j){
                    if(trans[j][i]==1)
                     x++;
                }
            }
            if(x==total-1){
                for(int j=0;j<100;j++){
                printf("%c ",name[i][j]);
               }
               printf("\n");
            }

        }
    }

}


void menu5_3(){

}

void displaySequence(){
  /*  for(int i=0 ; i<size ; i++){
        for(int j=0 ; j<size ; j++){
            printf("%d ",trans[i][j]);
        }
        printf("\n");
    }*/
    while(true){
        int mainChoice = disp_main();

        if(mainChoice==1){
            int choice = main_1();
            if(choice==0){
                int choice2 = disp_menu2();
                if(choice2==1){
                    disp_menu2();
                }
            }
        }else if(mainChoice==2){
            int choice = main_2();
            if(choice==0){
                int choice2 = disp_menu2();
                if(choice2==1){
                    disp_menu2();
                }
            }
        }else if(mainChoice==3){
            int choice = main_3();
            if(choice==0){
                int choice2 = disp_menu2();
                if(choice2==1){
                    disp_menu2();
                }
            }
        }else if(mainChoice==4){
            main_4();
        }else if(mainChoice==5){
            main_5();
        }else if(mainChoice==6){
            main_6();
        }else if(mainChoice==7){
            int choice = main_7();
            if(choice==0){
                int choice2 = disp_menu2();
                if(choice2==1){
                    disp_menu2();
                }
            }else{
                int choice3 = disp_menu3();
                if(choice3==1){
                   // menu3();
                  printf("menu 3 abt to run");
                }
            }
        }else if(mainChoice==8){
            int result = main_8();
            if(result==1){
                while(true){
                    int secChoice = disp_menu4();
                    if(secChoice==1){
                        menu4_1();
                    }else if(secChoice==2){
                        menu4_2();
                    }else if(secChoice==3){
                        menu4_3();
                    }else if(secChoice==4){
                        menu4_4();
                    }else if(secChoice==5){
                        menu4_5();
                    }else if(secChoice==6){
                        menu4_6();
                    }else if(secChoice==7){
                        menu4_7();
                    }else if(secChoice==8){
                        int result2 = menu4_8();
                        if(result2==1){
                            while(true){
                                int terChoice = disp_menu5();
                                if(terChoice==1){
                                    menu5_1();
                                }else if(terChoice==2){
                                    menu5_2();
                                }else if(terChoice==2){
                                    menu5_3();
                                }else{
                                    break;
                                }
                            }
                        }
                    }else{
                        break;
                    }
                }

            }
        }else{
            break;
        }
    }

}










int main()

{
FILE *fp_in;
    int col,row=0;

    fp_in = fopen("SampleInput.csv", "r");
    if (!fp_in)
        return 1;

    char buffer[1000000];

while (fgets(buffer, 1000000, fp_in)!=NULL)
    {
        char *value = strtok(buffer, ",");
        col = 0;
        while (value != NULL)
        {
            if (col == 0)
            {
                if(row!=0){
                 for(int i=0;i<100;++i){
                    name[row-1][i]=value[i];
                    if(value[i]==NULL)
                        break;
                 }

                }
                value = strtok(NULL, ",");


                col++;

                continue;
            }
            int val = atoi(value);
            matrix[row - 1][col - 1] = val;
            value = strtok(NULL, ",");
            col++;
        }
        row++;
    }

    row--;
    col--;
    size=row;
    /*To access i th website name

        for(int j=0;j<100;j++){
            printf("%c ",name[i][j]);
        }*/
   /* matrix print
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            printf("%d", r[i][j]);
        }
        printf("\n");
    }*/

for(int i=0;i<size;++i){
 for(int j=0;j<size;++j){
    trans[i][j]=matrix[i][j];
    }
}
warshall();
displaySequence();




    return 0;
}















































