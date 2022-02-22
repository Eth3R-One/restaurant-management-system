#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>// for X-Y
#include <time.h>
#include <dos.h>
#include <conio.h>

char exit_txt[]={"Good Bye, Have a nice Day!"};
char intro_txt[]={"Welcome, What a Wonderful Day!"};

char line[1000],temp[1000];
int lineBreak[1000],line_count_orderFile;
int price_from_order;
int order_serial;

struct order_info{
    int serial_num;
    int number_of_items;
    int itm_no;
    char item_name[100];
    char siz[20];
    int price;
    int total_price;
    int quantity;
};
typedef struct order_info o_Info;

struct food_list{
    int code;
    char name[100];
    int m_size;
    int l_size;
    int serial_num;
};
typedef struct food_list food;

struct food_convert{
    char serial_num_string[10];
    char code_string[10];
    char m_size_string[10];
    char l_size_string[10];
};
typedef struct food_convert foo_Convrt;

struct chinese_food_struct{
    foo_Convrt foodConv_chFoodStruct[25];
    food food_chFoodStruct[25];
};
typedef struct chinese_food_struct chinese;

struct thai_food_struct{
    foo_Convrt foodConv_chFoodStruct[25];
    food food_chFoodStruct[25];
};
typedef struct thai_food_struct thai;

struct indian_food_struct{
    foo_Convrt foodConv_chFoodStruct[25];
    food food_chFoodStruct[25];
};
typedef struct thai_food_struct indian;

struct fast_food_struct{
    foo_Convrt foodConv_chFoodStruct[25];
    food food_chFoodStruct[25];
};
typedef struct thai_food_struct fast;

struct dessert_struct{
    foo_Convrt foodConv_chFoodStruct[25];
    food food_chFoodStruct[25];
};
typedef struct dessert_struct dessert;

struct beverage_struct{
    foo_Convrt foodConv_chFoodStruct[25];
    food food_chFoodStruct[25];
};
typedef struct dessert_struct beverage;

o_Info order_info_global[100];
food food_list_global[100];
foo_Convrt food_conv_global[100];

chinese chinese_food_list[100];
int line_of_chinese_food;

thai thai_food_list[100];
int line_of_thai_food;

indian indian_food_list[100];
int line_of_indian_food;

fast fast_food_list[100];
int line_of_fast_food;

dessert dessert_food_list[100];
int line_of_dessert_food;

beverage beverage_food_list[100];
int line_of_beverage_food;

void ext();
void welcome();
void orderList();
void Order(int last_item);
void gotoxy(int x, int y);
void show_time();
void menu();
void read_fast_food();
void print_fast_food();
void read_thai_food();
void print_thai_food();
void read_chinese_food();
void print_chinese_food();
void read_indian_food();
void print_indian_food();
void read_dessert_food();
void print_dessert_food();
void read_beverage_food();
void print_beverage_food();

void add();

void chk_str();
void str_conv(int f_num, int l_num);
int input_check(int a,int b);



int main (){
    show_time();
    welcome();
mainx:
    line_of_beverage_food=0;
    line_of_chinese_food=0;
    line_of_dessert_food=0;
    line_of_fast_food=0;
    line_of_indian_food=0;
    line_of_thai_food=0;

    read_chinese_food();
    read_fast_food();
    read_thai_food();
    read_indian_food();
    read_dessert_food();
    read_beverage_food();
    show_time();
    //welcome();
    int add_remove_modify;
    int i=0;
    int total_bill=0,total_item=0;
    int surf;
    char ch;

    system("cls");
    printf("\t\t-Main Menu-\n");
    printf("\t1.Menu List\n");
    printf("\t2.Order List\n");
    printf("\t3.Add | Remove | modify item.\n");
    printf("\t4.Order State\n");
    printf("\n\n\n\n\nEnter 0 to Close the Programme\n");
    scanf("%d",&surf);
    order_serial=0;
    price_from_order=0;

    switch(surf){
        case 0:
            fflush(stdin);
            system("cls");
            printf("Do yu really want to close the progrrmme?\n");
            printf("\n\n\nEnter Y to exit\nEnter any Other key to goto main menu\n");
            ch=getchar();
            if(ch== 'y' || ch == 'Y'){
                ext();
                sleep(1);
                return 0;
            }
            else
                goto mainx;
            break;
        case 1:
me_nu:
            printf("Main menu selected\n");
            fflush(stdin);
            menu();
            printf("\n\n\nTo goto back menu enter 0\n");
            scanf("%d",&surf);
            switch (surf){
                case 0:
                    goto mainx;
                    break;
                case 1:

                    system("cls");
                    fflush(stdin);
                    printf("Fast Food selected\n");
                    //printf("Not Created\n");
                    //sleep(1000);
                    order(1);
                    //goto me_nu;
                    goto confirm_order;
                    break;
                case 2:

                    system("cls");
                    fflush(stdin);
                    printf("Thai Food selected\n");
                    fflush(stdin);
                    order(2);
                    goto confirm_order;
                    break;
                case 3:

                    system("cls");
                    printf("Indian Food selected\n");
                    fflush(stdin);
                    // printf("Not Created\n");
                    order(3);
                    goto confirm_order;
                    break;
                case 4:

                    system("cls");
                    fflush(stdin);
                    printf("Chinese food selected\n");
                    order(4);
                    goto confirm_order;
                    break;
                case 5:
                    system("cls");
                    fflush(stdin);
                    printf("dessert Selected\n");
                    order(5);
                    goto confirm_order;
                    break;

                case 6:
                    system("cls");
                    fflush(stdin);
                    printf("Beverage Selected\n");
                    order(6);
                    goto confirm_order;
                    break;
                default:
                    system("cls");
                    printf("Wrong Input\n");
                    sleep(1);
                    goto me_nu;
            }
confirm_order :
    fflush(stdin);
    system("cls");
        printf("Do you need anything ?\n");
        printf("To order anything else enter y\n");
        printf("To place order enter any key\n");
        ch=getchar();
        //scanf("%c",&ch);
        switch(ch){
            case 'y' :
                goto me_nu;
                break;
            case 'Y' :
                goto me_nu;
                break;
            default :
                orderList();
                getchar();
                goto mainx;
        }
        break;
    case 3:
        system("cls");
        fflush(stdin);
        printf("Choose an option\n");
        printf("1.ADD an Item\n");
        printf("2.Remove an Item\n");
        printf("3.Modify an Item\n");
        scanf("%d",&add_remove_modify);
        if(add_remove_modify==1){
            add();
            break;
        }
    default :
        system("cls");
        printf("Wrong Input\n");
        sleep(1);
        goto mainx;
    }
    goto mainx;
    return 0;
}

void welcome(){
    system("cls");
    show_time();
    for(int i=0;intro_txt[i]!='\0';i++){
        printf("%c",intro_txt[i]);
        for(int j=0; j<125000000/2;j++){
            /* Do Nothing */
        }
    }
    printf("\n");
    sleep(1);
}

void ext(){
    system("cls");
    for(int i=0; exit_txt[i]!='\0';i++){
        printf("%c",exit_txt[i]);
        for(int j=0; j<125000000/2;j++){
            /* Do Nothing */
        }
    }
    printf("\n");
}

void add_fun(FILE *read){
    char name[25];
    int mprice,lprice;
    printf("Serial No. of the product is - %d\n",line_of_fast_food);
    printf("Enter Item name\n");
    gets(name);
    printf("Enter %s Item's medium size price : ",name);
    scanf("%d",&mprice);
    printf("\n");
    printf("Enter %s Item's Large size price : ",name);
    scanf("%d",&lprice);
    printf("\n");
    system("cls");
    printf("Item name : %s\n",name);
    printf("Medium Size Price : %d\n",mprice);
    printf("Large Size Price : %d\n",lprice);
    for(int i=0;name[i]!='\0';i++){
        if(name[i]==' ') name[i]='_';
    }
    //line[0]='0';
    line[0]='\0';

    itoa(line_of_fast_food, temp, 10);
    strcat(line,temp); 
    strcat(line,"*");
    
    strcat(line,name);
    strcat(line,"*");
            
    itoa(mprice, temp, 10);
            
    strcat(line,temp);
    strcat(line,"*");

    itoa(lprice, temp, 10);
    strcat(line,temp);
    strcat(line,"*");

    fprintf(read,"%s\n",line);
    printf("Adding Item successful\n");
    fflush(stdin);
    getchar();
    fclose(read);
    //strcat();

}

void add(){
    fflush(stdin);
    system("cls");
    int item;
    FILE *read;
    menu();
    printf("\n\n\nSelect a catagory\n");
    scanf("%d",&item);
    switch(item){
        case 1 :
            system("cls");
            fflush(stdin);
            read=fopen("fastfood.txt","a");
            line_of_fast_food=line_of_fast_food+1;
            add_fun(read);
            break;
        default :
            printf("NOT CREATED\n");
    }
    fflush(stdin);
    sleep(1);
}

void gotoxy(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void show_time(){
    fflush(stdin);
    system("cls");
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo=localtime(&rawtime);
    printf ("\t%s\n\n", asctime(timeinfo));
    printf("\n\n\n");
}

void menu(){
    //goto4(10,10);
    system("cls");
    fflush(stdin);
    printf("\t\tCATAGORIES\n");
    printf("\t1.Fast Food\n");
    printf("\t2.Thai Food\n");
    printf("\t3.Indian Food\n");
    printf("\t4.Chinese Food\n");
    printf("\t5.Dessert\n");
    printf("\t6.Beverage\n");
}

int input_check(int a,int b){
    if(a>0 && a<=b)return 0;
    else return 1;
}


void chk_str(){
    //printf("This 4 chk_str function = %s\n",line);
    int i,j=0;
    for(i=0;line[i]!='\0';i++){
        if(line[i]=='*'){
            lineBreak[j]=i;
            j++;
        }
    }
}


void str_conv(int f_num, int l_num){
    int i,k=0;
    //printf("This is from str_conv fun = %s\n",line);
    for(i=f_num;i<l_num;i++,k++){
        temp[k]=line[i];
        if(temp[k]=='*') break;
        if(temp[k]=='_')
            temp[k]=' ';
    }
    temp[k]='\0';
}
void read_beverage_food(){
    FILE *read;
    int i=0;
    read=fopen("beverage.txt","r");
    while(fgets(line,sizeof(line),read)!=NULL){
        chk_str();

        str_conv(0,lineBreak[0]);
        strcpy(beverage_food_list[i].foodConv_chFoodStruct->code_string, temp);
        beverage_food_list[i].food_chFoodStruct->code=atoi(beverage_food_list[i].foodConv_chFoodStruct->code_string);

        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(beverage_food_list[i].food_chFoodStruct->name,temp);

        str_conv(lineBreak[1]+1,lineBreak[2]);
        strcpy(beverage_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        beverage_food_list[i].food_chFoodStruct->m_size=atoi(beverage_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[2]+1,lineBreak[3]);
        strcpy(beverage_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        beverage_food_list[i].food_chFoodStruct->l_size=atoi(beverage_food_list[i].foodConv_chFoodStruct->l_size_string);

        line_of_beverage_food++;
        i++;
    }
    fclose(read);
}
void print_beverage_food(){
    system("cls");
    printf("--Beverage List--\n");
    for(int i=0;beverage_food_list[i].food_chFoodStruct->code!=0;i++){
        printf("Code = %d\n", beverage_food_list[i].food_chFoodStruct->code);
        printf("%s\n",beverage_food_list[i].food_chFoodStruct->name);
        printf("Medium Size = %d\n",beverage_food_list[i].food_chFoodStruct->m_size);
        printf("Large Size = %d\n",beverage_food_list[i].food_chFoodStruct->l_size);
        printf("---------------\n");
    }
}


void read_dessert_food(){
    FILE *read;
    int i=0;
    read=fopen("dessert.txt","r");
    while(fgets(line,sizeof(line),read)!=NULL){
        chk_str();

        str_conv(0,lineBreak[0]);
        strcpy(dessert_food_list[i].foodConv_chFoodStruct->code_string, temp);
        dessert_food_list[i].food_chFoodStruct->code=atoi(dessert_food_list[i].foodConv_chFoodStruct->code_string);

        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(dessert_food_list[i].food_chFoodStruct->name,temp);

        str_conv(lineBreak[1]+1,lineBreak[2]);
        strcpy(dessert_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        dessert_food_list[i].food_chFoodStruct->m_size=atoi(dessert_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[2]+1,lineBreak[3]);
        strcpy(dessert_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        dessert_food_list[i].food_chFoodStruct->l_size=atoi(dessert_food_list[i].foodConv_chFoodStruct->l_size_string);

        line_of_dessert_food++;
        i++;
    }
    fclose(read);
}
void print_dessert_food(){
    system("cls");
    printf("--DESSERT List--\n");
    for(int i=0;dessert_food_list[i].food_chFoodStruct->code!=0;i++){
        printf("Code = %d\n", dessert_food_list[i].food_chFoodStruct->code);
        printf("%s\n",dessert_food_list[i].food_chFoodStruct->name);
        printf("Medium Size = %d\n",dessert_food_list[i].food_chFoodStruct->m_size);
        printf("Large Size = %d\n",dessert_food_list[i].food_chFoodStruct->l_size);
        printf("---------------\n");
    }
}

void read_chinese_food(){
    FILE *read;
    int i=0;
    read=fopen("chinesefood.txt","r");
    while(fgets(line,sizeof(line),read)!=NULL){
        chk_str();

        str_conv(0,lineBreak[0]);
        strcpy(chinese_food_list[i].foodConv_chFoodStruct->code_string, temp);
        chinese_food_list[i].food_chFoodStruct->code=atoi(chinese_food_list[i].foodConv_chFoodStruct->code_string);

        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(chinese_food_list[i].food_chFoodStruct->name,temp);

        str_conv(lineBreak[1]+1,lineBreak[2]);
        strcpy(chinese_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        chinese_food_list[i].food_chFoodStruct->m_size=atoi(chinese_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[2]+1,lineBreak[3]);
        strcpy(chinese_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        chinese_food_list[i].food_chFoodStruct->l_size=atoi(chinese_food_list[i].foodConv_chFoodStruct->l_size_string);

        line_of_chinese_food++;
        i++;
    }
    fclose(read);
}
void print_chinese_food(){
    system("cls");
    printf("--CHINESE Food--\n");
    for(int i=0;chinese_food_list[i].food_chFoodStruct->code!=0;i++){
        printf("Code = %d\n", chinese_food_list[i].food_chFoodStruct->code);
        printf("%s\n",chinese_food_list[i].food_chFoodStruct->name);
        printf("Medium Size = %d\n",chinese_food_list[i].food_chFoodStruct->m_size);
        printf("Large Size = %d\n",chinese_food_list[i].food_chFoodStruct->l_size);
        printf("---------------\n");
    }
}

void read_indian_food(){
    FILE *read;
    int i=0;
    read=fopen("indianfood.txt","r");

    while(fgets(line,sizeof(line),read)!=NULL){
        chk_str();

        str_conv(0,lineBreak[0]);
        strcpy(indian_food_list[i].foodConv_chFoodStruct->code_string, temp);
        indian_food_list[i].food_chFoodStruct->code=atoi(indian_food_list[i].foodConv_chFoodStruct->code_string);


        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(indian_food_list[i].food_chFoodStruct->name,temp);

        str_conv(lineBreak[1]+1,lineBreak[2]);
        strcpy(indian_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        indian_food_list[i].food_chFoodStruct->m_size=atoi(indian_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[2]+1,lineBreak[3]);
        strcpy(indian_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        indian_food_list[i].food_chFoodStruct->l_size=atoi(indian_food_list[i].foodConv_chFoodStruct->l_size_string);

        line_of_indian_food++;
        i++;
    }
    fclose(read);
}
void print_indian_food(){
    system("cls");
    printf("--INDIAN Food--\n");
    for(int i=0;indian_food_list[i].food_chFoodStruct->code!=0;i++){
        printf("Code = %d\n", indian_food_list[i].food_chFoodStruct->code);
        printf("%s\n",indian_food_list[i].food_chFoodStruct->name);
        printf("Medium Size = %d\n",indian_food_list[i].food_chFoodStruct->m_size);
        printf("Large Size = %d\n",indian_food_list[i].food_chFoodStruct->l_size);
        printf("---------------\n");
    }
}

void read_fast_food(){
    FILE *read;
    int i=0;
    read=fopen("fastfood.txt","r");

    while(fgets(line,sizeof(line),read)!=NULL){
        chk_str();

        str_conv(0,lineBreak[0]);
        strcpy(fast_food_list[i].foodConv_chFoodStruct->code_string, temp);
        fast_food_list[i].food_chFoodStruct->code=atoi(fast_food_list[i].foodConv_chFoodStruct->code_string);

        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(fast_food_list[i].food_chFoodStruct->name,temp);

        str_conv(lineBreak[1]+1,lineBreak[2]);
        strcpy(fast_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        fast_food_list[i].food_chFoodStruct->m_size=atoi(fast_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[2]+1,lineBreak[3]);
        strcpy(fast_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        fast_food_list[i].food_chFoodStruct->l_size=atoi(fast_food_list[i].foodConv_chFoodStruct->l_size_string);

        line_of_fast_food++;
        i++;
    }
    fclose(read);
}
void print_fast_food(){
    system("cls");
    
    printf("--FAST Food--\n");
    for(int i=0;fast_food_list[i].food_chFoodStruct->code!=0;i++){
        printf("Code = %d\n", fast_food_list[i].food_chFoodStruct->code);
        printf("%s\n",fast_food_list[i].food_chFoodStruct->name);
        printf("Medium Size = %d\n",fast_food_list[i].food_chFoodStruct->m_size);
        printf("Large Size = %d\n",fast_food_list[i].food_chFoodStruct->l_size);
        printf("---------------\n");
    }
}

void read_thai_food(){
    FILE *read;
    int i=0;
    read=fopen("thaifood.txt","r");

    while(fgets(line,sizeof(line),read)!=NULL){
        chk_str();

        str_conv(0,lineBreak[0]);
        strcpy(thai_food_list[i].foodConv_chFoodStruct->code_string, temp);
        thai_food_list[i].food_chFoodStruct->code=atoi(thai_food_list[i].foodConv_chFoodStruct->code_string);

        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(thai_food_list[i].food_chFoodStruct->name,temp);


        str_conv(lineBreak[1]+1,lineBreak[2]);
        strcpy(thai_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        thai_food_list[i].food_chFoodStruct->m_size=atoi(thai_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[2]+1,lineBreak[3]);
        strcpy(thai_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        thai_food_list[i].food_chFoodStruct->l_size=atoi(thai_food_list[i].foodConv_chFoodStruct->l_size_string);

        i++;
        line_of_thai_food++;
    }
    fclose(read);
}

void print_thai_food(){
    system("cls");

    printf("--THAI Food--\n");
    for(int i=0; i<line_of_thai_food;i++){
        printf("Code = %d\n", thai_food_list[i].food_chFoodStruct->code);
        printf("%s\n",thai_food_list[i].food_chFoodStruct->name);
        printf("Medium Size = %d\n",thai_food_list[i].food_chFoodStruct->m_size);
        printf("Large Size = %d\n",thai_food_list[i].food_chFoodStruct->l_size);
        printf("---------------\n");
    }
}

void order(int item){
    int size_price,selected_item,quantity,brk;
    int total_price=0;
    char ch[5],che;
    int i=order_serial;
    switch (item){
        case 1:

            while(1){
        chking_1:
                system("cls");
                
                print_fast_food();
                printf("Enter item no.\n");
                scanf("%d",&selected_item);
                    if(input_check(selected_item,line_of_fast_food)){
                        printf("Wrong Input\n");
                        getchar();
                        //sleep("1000");
                        goto chking_1;
                    }

                order_info_global[i].itm_no=fast_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,fast_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls");
                printf("selected item -\t%s\n",fast_food_list[selected_item-1].food_chFoodStruct->name);
                printf("Select size\n");
                printf("\n");
                printf("1.Medium - %d\n", fast_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("2.Large - %d\n", fast_food_list[selected_item-1].food_chFoodStruct->l_size);
                scanf("%d",&size_price);

                if(size_price==1){
                    order_info_global[i].price=fast_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("Medium size selected\n");
                }
                else{
                    order_info_global[i].price=fast_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("Large size selected\n");
                }
                printf("Enter Quantity\n");
                scanf("%d",&quantity);
                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("%s --- %d x %d = %d\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
                printf("To order again press enter\n");
                printf("To place order press 0\n");
                che=getche();
                //scanf("%s",ch);
                if(che=='0')
                    break;
            }
            break;
        case 2:

            while(1){
        chking_2:
                system("cls");
                print_thai_food();
                printf("Enter item no.\n");
                scanf("%d",&selected_item);
                    if(input_check(selected_item,line_of_thai_food)){
                        printf("Wrong Input\n");
                        getchar();
                        //sleep("1000");
                        goto chking_2;
                    }

                order_info_global[i].itm_no=thai_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,thai_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls");
                printf("selected item -\t%s\n",thai_food_list[selected_item-1].food_chFoodStruct->name);
                printf("Select size\n");
                printf("\n");
                printf("1.Medium - %d\n", thai_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("2.Large - %d\n", thai_food_list[selected_item-1].food_chFoodStruct->l_size);
                scanf("%d",&size_price);

                if(size_price==1){
                    order_info_global[i].price=thai_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("Medium size selected\n");
                }
                else{
                    order_info_global[i].price=thai_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("Large size selected\n");
                }
                printf("Enter Quantity\n");
                scanf("%d",&quantity);
                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("%s --- %d x %d = %d\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
                printf("To order again press enter\n");
                printf("To place order press 0\n");
                che=getche();
                //scanf("%s",ch);
                if(che=='0')
                    break;
            }
            break;
        case 3:
            while(1){
        chking_3:
                system("cls");
                print_indian_food();
                printf("Enter item no.\n");
                scanf("%d",&selected_item);
                    if(input_check(selected_item,line_of_indian_food)){
                        printf("Wrong Input\n");
                        getchar();
                        //sleep("1000");
                        goto chking_3;
                    }

                order_info_global[i].itm_no=indian_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,indian_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls");
                printf("selected item -\t%s\n",indian_food_list[selected_item-1].food_chFoodStruct->name);
                printf("Select size\n");
                printf("\n");
                printf("1.Medium - %d\n", indian_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("2.Large - %d\n", indian_food_list[selected_item-1].food_chFoodStruct->l_size);
                scanf("%d",&size_price);

                if(size_price==1){
                    order_info_global[i].price=indian_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("Medium size selected\n");
                }
                else{
                    order_info_global[i].price=indian_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("Large size selected\n");
                }
                printf("Enter Quantity\n");
                scanf("%d",&quantity);
                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("%s --- %d x %d = %d\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
                printf("To order again press enter\n");
                printf("To place order press 0\n");
                che=getche();
                //scanf("%s",ch);
                if(che=='0')
                    break;
            }
            break;
        case 4:
            while(1){
        chking_4:
                system("cls");
                print_chinese_food();
                printf("Enter item no.\n");
                scanf("%d",&selected_item);
                    if(input_check(selected_item,line_of_chinese_food)){
                        printf("Wrong Input\n");
                        getchar();
                        //sleep("1000");
                        goto chking_4;
                    }

                order_info_global[i].itm_no=chinese_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,chinese_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls");
                printf("selected item -\t%s\n",chinese_food_list[selected_item-1].food_chFoodStruct->name);
                printf("Select size\n");
                printf("\n");
                printf("1.Medium - %d\n", chinese_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("2.Large - %d\n", chinese_food_list[selected_item-1].food_chFoodStruct->l_size);
                scanf("%d",&size_price);

                if(size_price==1){
                    order_info_global[i].price=chinese_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("Medium size selected\n");
                }
                else{
                    order_info_global[i].price=chinese_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("Large size selected\n");
                }
                printf("Enter Quantity\n");
                scanf("%d",&quantity);
                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("%s --- %d x %d = %d\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
                printf("To order again press enter\n");
                printf("To place order press 0\n");
                che=getche();
                //scanf("%s",ch);
                if(che=='0')
                    break;
            }
            break;
        case 5:
            while(1){
        chking_5:
                system("cls");
                print_dessert_food();
                printf("Enter item no.\n");
                scanf("%d",&selected_item);
                    if(input_check(selected_item,line_of_dessert_food)){
                        printf("Wrong Input\n");
                        getchar();
                        //sleep("1000");
                        goto chking_5;
                    }

                order_info_global[i].itm_no=dessert_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,dessert_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls");
                printf("selected item -\t%s\n",dessert_food_list[selected_item-1].food_chFoodStruct->name);
                printf("Select size\n");
                printf("\n");
                printf("1.Medium - %d\n", dessert_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("2.Large - %d\n", dessert_food_list[selected_item-1].food_chFoodStruct->l_size);
                scanf("%d",&size_price);

                if(size_price==1){
                    order_info_global[i].price=dessert_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("Medium size selected\n");
                }
                else{
                    order_info_global[i].price=dessert_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("Large size selected\n");
                }
                printf("Enter Quantity\n");
                scanf("%d",&quantity);
                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("%s --- %d x %d = %d\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
                printf("To order again press enter\n");
                printf("To place order press 0\n");
                che=getche();
                //scanf("%s",ch);
                if(che=='0')
                    break;
            }
            break;
        case 6 :
            while(1){
        chking_6:
                system("cls");
                print_beverage_food();
                printf("Enter item no.\n");
                scanf("%d",&selected_item);
                    if(input_check(selected_item,line_of_beverage_food)){
                        printf("Wrong Input\n");
                        getchar();
                        //sleep("1000");
                        goto chking_6;
                    }

                order_info_global[i].itm_no=beverage_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,beverage_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls");
                printf("selected item -\t%s\n",beverage_food_list[selected_item-1].food_chFoodStruct->name);
                printf("Select size\n");
                printf("\n");
                printf("1.Medium - %d\n", beverage_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("2.Large - %d\n", beverage_food_list[selected_item-1].food_chFoodStruct->l_size);
                scanf("%d",&size_price);

                if(size_price==1){
                    order_info_global[i].price=beverage_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("Medium size selected\n");
                }
                else{
                    order_info_global[i].price=beverage_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("Large size selected\n");
                }
                printf("Enter Quantity\n");
                scanf("%d",&quantity);
                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("%s --- %d x %d = %d\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
                printf("To order again press enter\n");
                printf("To place order press 0\n");
                che=getche();
                //scanf("%s",ch);
                if(che=='0')
                    break;
            }
            break;
        default:
            break;
    }
}


void orderList(){
    int total_price=0;

system("cls");
    printf("\tSelected Item(s)\n\n");

    for(int j=0;j<order_serial;j++){

        printf("Item No - %d\n",j+1);
        printf("%s (%s) = x%d\n",order_info_global[j].item_name, order_info_global[j].siz, order_info_global[j].quantity);
        printf("Price = %d\n",order_info_global[j].price);
        printf("\n");

        total_price+= (order_info_global[j].price*order_info_global[j].quantity);
    }
    printf("---------------------\n");
    printf("TOTAL = %d\n",total_price);
    price_from_order=total_price;
    getchar();
}