#include<stdio.h>
#include<string.h>
#define MAX_GOODS 100
struct detail{
    char name[20];
    char pass[20];
};
struct goods{
    char gname[20];
    int price;
    int quantity;
};
struct goods g[MAX_GOODS];
int goodcount=0;
void addgoods(){
    if(goodcount >= MAX_GOODS){ 
        printf("Insufficient space\n");
        return;
    }
    printf("Enter the goods name: \n");
    scanf("%s",g[goodcount].gname);
    printf("Enter the price of the goods: \n");
    scanf("%d", &g[goodcount].price);
    g[goodcount].quantity = 1;
    goodcount++;
    printf("goods added\n");
}
void viewgoods(){
    if(goodcount==0){
        printf("No goods available to view\n");
        return;
    }
    printf("Available goods are\n");
    for(int i=0;i<goodcount;i++){
        if(g[i].quantity==1){
            printf("goods : %s\nprice %d\n",g[i].gname,g[i].price);
        }
    }
    
}
int pr;
void buygoods(){
    char gd[20];
    int f=0;
    if(goodcount==0){
        printf("No goods available to buy\n");
        return;
    }
    printf("Enter the goods name\n");
    scanf("%s",gd);
    printf("Enter the price\n");
    scanf("%d",&pr);
    for(int i=0;i<goodcount;i++){
    if(pr !=g[i].price){
        printf("Price mismatch\n");
        return;
    }
}
    for(int i=0;i<goodcount;i++){
        if(strcmp(g[i].gname,gd)==0){
            printf("Thanks for buying %s\n",gd);
            g[i].quantity=0;
            f=1;
            break;
        }
        pr = g[i].price;
    }
    if (!f) {
        printf("Book not available.\n");
    }
}
void balance(){
    int tot = 0;
    for(int i=0;i<goodcount;i++){
        tot += pr;
    }
    printf("Total balance is %d\n", tot);
}
    
int main(){
    struct detail d;
    printf("Enter your Email: ");
    scanf("%s", d.name);
    printf("Enter your password: ");
    scanf("%s", d.pass);
    char na[]="melbin@gmail.com";
    char pa[]="melbin123";
    if(strcmp(d.name, na) == 0 && strcmp(d.pass, pa) == 0){
        printf("Login successful!\n");
        int choice;
        do{
            printf("1. Add goods\n");
            printf("2. viewgoods\n");
            printf("3. Buygoods\n");
            printf("4. Balance\n");
            printf("5. Exit\n");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    addgoods();
                    break;
                case 2:
                    viewgoods();
                    break;
                case 3:
                    buygoods();
                    break;
                case 4:
                    balance();
                    break;
                case 5:
                    printf("Exiting...\n");
                    return 0;
                default:
                    printf("Invalid choice, please try again.\n");
            }
        }while(choice != 5);
        return 0;
    } 
    else{
        printf("Login failed");
    }
   /* int ch;
    if(strcmp(d.name, na) == 0 && strcmp(d.pass, pa) == 0){
        printf("Welcome to the shop\n");
        do{
            printf("1. viewgoods\n");
            printf("2. buygoods\n");
            scanf("%d",&ch);
            switch(ch){
                case 1:
                    viewgoods();
                    break;
                case 2:
                    buygoods();
                    return 0;
                default:
                    printf("Invalid choice.\n");
            }
        }while(ch != 2);
    } else{
        printf("Access denied.\n");
    }*/
    return 0;
}