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
char intro_txt[]={"Welcome to --- BaBu kheyecho ? ---"};
char date[]={"Today is "};
char cheking;
char name[]={"B a B u  Kheyecho?\n"};

char line[1000000],temp[1000];
int lineBreak[1000],line_count_orderFile;
int price_from_order;
int order_serial;
int serial_no;
int item;
char ti_me;
int flag;
int total_quantity;
unsigned long long state;

struct order_info{
    int serial_num;
    int number_of_items;
    int itm_no;
    char item_name[100];
    char siz[20];
    int price;
    int t_price;
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
typedef struct indian_food_struct indian;

struct fast_food_struct{
    foo_Convrt foodConv_chFoodStruct[25];
    food food_chFoodStruct[25];
};
typedef struct fast_food_struct fast;

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
void order(int last_item);
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
void serial_no_fromFile();

void order_to_serve();

void OrderState();
void add();

void re_move();

void modify_item();
void modify_fun(char file_name[]);

void chk_str();
void str_conv(int f_num, int l_num);
int input_check(int a,int b);



int main (){
    //gotoxy(40,6);
    system("cls");

    show_time();
    welcome();
mainx:
    flag = 0;
    total_quantity = 0;


    line_count_orderFile=0;
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
    int add_remove_modify=0;
    int i=0;
    int total_bill=0,total_item=0;
    int surf;
    char ch;

    system("cls"); //gotoxy(40,6);
    //gotoxy(40,6);
    printf("\n\n\n");


    printf("\n\t\t\t\t\t-Main Menu-\n\n\n");


    printf("\t\t\t\t\t1.Menu List\n");
    printf("\t\t\t\t\t2.Order List\n");
    printf("\t\t\t\t\t3.Add | Remove | modify item.\n");
    printf("\t\t\t\t\t4.Order State\n");



    printf("\n\n\nEnter 0 to Close the Programme\n");
    scanf("%d",&surf);
    order_serial=0;
    price_from_order=0;

    switch(surf){
        case 0:
            fflush(stdin);
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\n\n\t\t\t\t\tDo you really want to close the progrrmme? (y/n)\n");
            //printf("\n\t\t\t\t\tEnter Y to exit\nEnter any Other key to goto main menu\n");
            printf("\t\t\t\t\t");
            ch=getchar();
            if(ch == 'Y' || ch == 'y'){
                ext();
                slp();
                return 0;
            }
            else
                goto mainx;
            break;
        case 1:
me_nu:
            flag = 0;
            printf("\t\t\t\t\tMain menu selected\n");
            fflush(stdin);
            menu();
            printf("\n\n\n\nTo go back menu enter 0\n");
            scanf("%d",&surf);
            switch (surf){
                case 0:
                    goto mainx;
                    break;

                case 1:

                    system("cls"); //gotoxy(40,6);
                    fflush(stdin);
                    printf("Enter 0 to go back\n\n\n");
                    //gotoxy(40,6);
                    printf("\t\t\t\t\tFast Food selected\n");
                    //printf("\t\t\t\t\tNot Created\n");
                    //slp(1000);
                    order(1);
                    //goto me_nu;
                    if(flag == 1)
                        goto me_nu;
                    else
                        goto confirm_order;

                    break;
                case 2:

                    system("cls"); //gotoxy(40,6);
                    fflush(stdin);
                    printf("Enter 0 to go back\n\n\n");
                    //gotoxy(40,6);
                    printf("\t\t\t\t\tThai Food selected\n");
                    fflush(stdin);
                    order(2);
                    if(flag == 1)
                        goto me_nu;
                    else
                        goto confirm_order;
                    break;
                case 3:

                    system("cls"); //gotoxy(40,6);
                    printf("Enter 0 to go back\n\n\n");
                    //gotoxy(40,6);
                    printf("\t\t\t\t\tIndian Food selected\n");
                    fflush(stdin);
                    // printf("\t\t\t\t\tNot Created\n");
                    order(3);
                    if(flag == 1)
                        goto me_nu;
                    else
                        goto confirm_order;
                    break;
                case 4:

                    system("cls"); //gotoxy(40,6);
                    fflush(stdin);
                    printf("Enter 0 to go back\n\n\n");
                    //gotoxy(40,6);
                    printf("\t\t\t\t\tChinese food selected\n");
                    order(4);
                    if(flag == 1)
                        goto me_nu;
                    else
                        goto confirm_order;
                    break;
                case 5:
                    system("cls"); //gotoxy(40,6);
                    fflush(stdin);
                    printf("Enter 0 to go back\n\n\n");
                    //gotoxy(40,6);
                    printf("\t\t\t\t\tdessert Selected\n");
                    order(5);
                    if(flag == 1)
                        goto me_nu;
                    else
                        goto confirm_order;
                    break;

                case 6:
                    system("cls"); //gotoxy(40,6);
                    fflush(stdin);
                    printf("Enter 0 to go back\n\n\n");
                    //gotoxy(40,6);
                    printf("\t\t\t\t\tBeverage Selected\n");
                    order(6);
                    if(flag == 1)
                        goto me_nu;
                    else
                        goto confirm_order;
                    break;
                default:
                    system("cls"); //gotoxy(40,6);
                    //gotoxy(40,6);
                    printf("\t\t\t\t\tWrong Input\n");
                    slp();
                    goto me_nu;
            }
confirm_order :
    fflush(stdin);
    system("cls"); //gotoxy(40,6);
    //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tDo you need anything  ( Y / N )?\n\n");
        printf("\t\t\t\t\t");
        // printf("\t\t\t\t\tTo order anything else enter y\n");
        // printf("\t\t\t\t\tTo place order enter any key\n");
        fflush(stdin);
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
                slp();
                //getchar();
                goto mainx;
        }
        break;
    case 2:
        system("cls");

        printf("Enter 0 to go back!\n\n");
        printf("\n\n\t\t\t\t\tPending Orders to serve\n\n\n");
        order_to_serve();
        //Sleep(1);
        fflush(stdin);

        //getchar();
        break;
    case 3:
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        fflush(stdin);
        printf("\n\n\n\t\t\t\t\tChoose an option\n\n\n\n");
        printf("\t\t\t\t\t1.ADD an Item\n");
        printf("\t\t\t\t\t2.Remove an Item\n");
        printf("\t\t\t\t\t3.Modify an Item\n");
        printf("\n\n\nEnter 0 to go to main menu\n");
        scanf("%d",&add_remove_modify);
            if(add_remove_modify==0){
                goto mainx;
            }
            else if(add_remove_modify==1){
                add();
                break;
            }
            else if(add_remove_modify==2){
                re_move();
                break;
            }
            else if(add_remove_modify==3){
                modify_item();
                break;
            }
            else{
                //printf("\n\t\t\t\t\tWrong Input\n");
                //slp();
                goto mainx;
                break;
            }
            break;
    case 4:
        system("cls");
        show_time();
        OrderState();
        printf("\t\t\t\t\tTotal Income = %llu\n",state);
        //sleep(1);
        slp();
        break;
    default :
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\t\t\t\t\tWrong Input\n");
        slp();
        goto mainx;
    }
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

    goto mainx;


    return 0;
}

void OrderState(){
    FILE *ordr_state;
    ordr_state=fopen("OrderState.txt","r");
    fscanf(ordr_state,"%llu",&state);
    fclose(ordr_state);
}

void order_to_serve(){
    int item_to_remove;
    FILE *orderFile;
    //FILE *tem_file;
    orderFile=fopen("Order_List.txt","r");
    //tem_file= fopen("temp.txt","w");
    char file_line[100][1000];
    char boom;
    //strcpy(file_name,"Order_List.txt");

    int i=0;
    printf("\t\t\t_____________________________________________________________________\n");

    while(fgets(line,sizeof(line),orderFile)!=NULL){
        strcpy(file_line[i],line);

        printf("\t\t\tSerial No - %d\n\n\t\t\t\t\t",i+1);
        for(int j=0;line[j]!= '\0';j++){
            if(line[j]== '*')
                printf("\n\t\t\t\t\t");
            else if(line[j] == '_'){
                printf("\n");
                printf("\t\t\t_____________________________________________________________________\n");
                printf("\n");

            }
            else
                printf("%c",line[j]);
        }
        i++;
        line_count_orderFile++;
    }

    if(line_count_orderFile !=0){
        //fclose(orderFile);
        printf("\n\n\n\n\t\t\t\tEnter Serial No. to serve : ");
        scanf("%d", &item_to_remove);
        printf("\n\n\n\t\t\t\t\t");
        system("cls");
        if(item_to_remove==0){
            return;
        }

        printf("\t\t\tSerial No - %d\n\n\t\t\t\t\t",item_to_remove);
        strcpy(line,file_line[item_to_remove-1]);

        for(int j=0;line[j] != '\0';j++){
            if(line[j]== '*')
                printf("\n\t\t\t\t\t");
            else if(line[j] == '_'){
                printf("\n");
                printf("\t\t\t_____________________________________________________________________\n");
                printf("\n");
            }
            else
                printf("%c",line[j]);
            }

        fclose(orderFile);
        i=0;
        printf("\n\t\t\t\t\tIs this Order Ready to serve? (y /n ) : ");

        scanf(" %c", &boom);

        if(boom == 'Y' || boom == 'y'){
            orderFile=fopen("Order_List.txt","w");
            for(i=0;i<line_count_orderFile; i++){
                if(i+1 != item_to_remove){
                    fprintf(orderFile,"%s",file_line[i]);
                }
                else
                    continue;
            }
            system("cls");
            printf("\n\n\t\t\t\t\tOrder Served!\n\n\n");
            fflush(stdin);
            fclose(orderFile);
        }
        else{
            system("cls");
            printf("\n\n\n\t\t\t\t\tBe QUICK ! The customer is waiting\n");
        }
        //remove_item_fun(item_to_remove, file_name);
        slp();
    }
    else{
        system("cls");
        printf("\n\n\n\t\t\t\t\tNo Order is pending to serve!\n");
        slp();
    }

//two_2:

}


void slp(){
    // for(int i=0; i< a*500000000 ;i++){
    // }
    printf("\n\n\nPress Enter\n");
    fflush(stdin);
    getchar();
}

void welcome(){
    system("cls"); //gotoxy(40,6);
    //gotoxy(40,6);
    printf("\t\t\t\t\t\t\t\t\tDeveloped by Eth3r and friends\n");
    
    show_time();
    printf("\n\t\t\t\t\t");
    for(int i=0;intro_txt[i]!='\0';i++){
        printf("%c",intro_txt[i]);
        for(int j=0; j<31250000/2;j++){
            /* Does Nothing */
        }
    }
    printf("\n\t\t\t\t\t\n");
    slp();

}


void serial_no_fromFile(){
    FILE *order_serial_no;
    system("cls");
    order_serial_no=fopen("serial.txt","r");

    while(fgets(line,sizeof(line), order_serial_no) != NULL){
        serial_no = atoi(line);
    }
    //fprintf(order_serial_no,"%d\n",serial_no+1);
    fclose(order_serial_no);
}

void ext(){
    system("cls"); //gotoxy(40,6);
    //gotoxy(40,6);
    printf("\n\t\t\t\t\t");
    for(int i=0; exit_txt[i]!='\0';i++){
        printf("%c",exit_txt[i]);
        for(int j=0; j<31250000;j++){
            /* Does Nothing */
        }
    }
    printf("\n\t\t\t\t\t\n");
}
void modify_fun(char file_name[]){
    FILE *tmp;
    FILE *read;
    char new_line[100],temp[100];
    char name[100];
    int  mprice,lprice;
    char temp_file[]={"temp.txt"};
    tmp=fopen(temp_file,"w");
    int i=1;
    read=fopen(file_name,"r");

        fflush(stdin);
        //printf("\n\t\t\t\t\t\nPrevious name - %s\n",fast_food_list[line_no-1].food_chFoodStruct->name);
        printf("\t\t\t\t\tEnter Modified name : ");
        fflush(stdin);
        gets(name);
        printf("\n\t\t\t\t\t\n");
        //printf("\n\t\t\t\t\t\nPrevious Medium size price - %d\n",fast_food_list[line_no-1].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tEnter Medium size price : ");
        scanf("%d",&mprice);
        printf("\n\t\t\t\t\t\n");
        //printf("\n\t\t\t\t\t\nPrevious Large Size price - %d\n",fast_food_list[line_no-1].food_chFoodStruct->l_size);
        printf("\t\t\t\t\tEnter Large size price : ");
        scanf("%d",&lprice);
        printf("\n\t\t\t\t\t\n");
        for(int i=0;name[i]!='\0';i++){
            if(name[i] == ' ') name[i] = '_';
        }
        new_line[0]='\0';

        strcat(new_line,name);
        strcat(new_line,"*");

        itoa(mprice, temp, 10);
        strcat(new_line,temp);
        strcat(new_line,"*");

        itoa(lprice, temp, 10);
        strcat(new_line,temp);
        strcat(new_line,"*");

        // printf("\n\t\t\t\t\t\n%s\n",new_line);
        // printf("\n\t\t\t\t\t%d\n",item);
        while(fgets(line,sizeof(line),read)!=NULL){
            if(i==item){
                fprintf(tmp,"%s\n",new_line);
                //printf("\t\t\t\t\ti = %d....%s\n", i, new_line);
            }
            else{
                fprintf(tmp,"%s",line);
                //printf("\t\t\t\t\ti = %d...%s\n", i, line);
            }
            i++;
        }

    fclose(read);
    fclose(tmp);


    remove(file_name);
    rename(temp_file, file_name);
    system("cls"); //gotoxy(40,6);
    //gotoxy(40,6);
    flag = 0;
    total_quantity = 0;
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

    printf("\n\t\t\t\t\tModification Successful\n");
    slp();
}

void modify_item(){
    int cat;

    char con[3];
    char file_name[30];
    menu();
    printf("\n\n\n\t\t\t\t\tSelect a catagory : \n");
    scanf("%d", &cat);
    switch (cat){
    case 0:
        break;
    case 1:
        strcpy(file_name,"fastfood.txt");
        print_fast_food();
        printf("\n\t\t\t\t\tEnter Item No. to modify : ");
        scanf("%d",&item);
        if(item == 0){
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
            break;
        }
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tItem name :\t\t%s\n",fast_food_list[item-1].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size Price :\t%d\n", fast_food_list[item-1].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size Price :\t%d\n", fast_food_list[item-1].food_chFoodStruct->l_size);
        printf("\n\n\n\t\t\t\t\tBe careful and sure before modifying an item!!\n");
        printf("\t\t\t\t\ttype YES to modify this item\n");
        printf("\t\t\t\t\t");

        scanf("%s",con);
        if( strcmp(con,"YES") == 0  || strcmp(con,"yes") == 0 )
            modify_fun( file_name);
        else{
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
        }
        break;
    case 2:
        strcpy(file_name,"thaifood.txt");
        print_thai_food();
        printf("\n\t\t\t\t\tEnter Item No. to modify : ");
        scanf("%d",&item);
        if(item == 0){
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
            break;
        }
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tItem name :\t\t%s\n",thai_food_list[item-1].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size Price :\t%d\n", thai_food_list[item-1].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size Price :\t%d\n", thai_food_list[item-1].food_chFoodStruct->l_size);
        printf("\n\n\n\t\t\t\t\tBe careful and sure before modifying an item!!\n");
        printf("\t\t\t\t\ttype YES to modify this item\n");
            printf("\t\t\t\t\t");

        scanf("%s",con);
        if( strcmp(con,"YES") == 0  || strcmp(con,"yes") == 0 )
            modify_fun( file_name);
        else{
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
        }
        break;
    case 3:
        strcpy(file_name,"indianfood.txt");
        print_indian_food();
        printf("\n\t\t\t\t\tEnter Item No. to modify : ");
        scanf("%d",&item);
        if(item == 0){
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
            break;
        }
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tItem name :\t\t%s\n",indian_food_list[item-1].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size Price :\t%d\n", indian_food_list[item-1].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size Price :\t%d\n", indian_food_list[item-1].food_chFoodStruct->l_size);
        printf("\n\n\n\t\t\t\t\tBe careful and sure before modifying an item!!\n");
        printf("\t\t\t\t\ttype YES to modify this item\n");
            printf("\t\t\t\t\t");

        scanf("%s",con);
        if( strcmp(con,"YES") == 0  || strcmp(con,"yes") == 0 )
            modify_fun( file_name);
        else{
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
        }
        break;
    case 4:
        strcpy(file_name,"chinesefood.txt");
        print_chinese_food();
        printf("\n\t\t\t\t\tEnter Item No. to modify : ");
        scanf("%d",&item);
        if(item == 0){
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
            break;
        }
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tItem name :\t\t%s\n",chinese_food_list[item-1].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size Price :\t%d\n", chinese_food_list[item-1].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size Price :\t%d\n", chinese_food_list[item-1].food_chFoodStruct->l_size);
        printf("\n\n\n\t\t\t\t\tBe careful and sure before modifying an item!!\n");
        printf("\t\t\t\t\ttype YES to modify this item\n");
            printf("\t\t\t\t\t");

        scanf("%s",con);
        if( strcmp(con,"YES") == 0  || strcmp(con,"yes") == 0 )
            modify_fun( file_name);
        else{
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
        }
        break;
    case 5:
        strcpy(file_name,"dessertfood.txt");
        print_dessert_food();
        printf("\n\t\t\t\t\tEnter Item No. to modify : ");
        scanf("%d",&item);
        if(item == 0){
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
            break;
        }
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tItem name :\t\t%s\n",dessert_food_list[item-1].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size Price :\t%d\n", dessert_food_list[item-1].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size Price :\t%d\n", dessert_food_list[item-1].food_chFoodStruct->l_size);
        printf("\n\n\n\t\t\t\t\tBe careful and sure before modifying an item!!\n");
        printf("\t\t\t\t\ttype YES to modify this item\n");
            printf("\t\t\t\t\t");

        scanf("%s",con);
        if( strcmp(con,"YES") == 0  || strcmp(con,"yes") == 0 )
            modify_fun( file_name);
        else{
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
        }
        break;
    case 6:
        strcpy(file_name,"beveragefood.txt");
        print_beverage_food();
        printf("\n\t\t\t\t\tEnter Item No. to modify : ");
        scanf("%d",&item);
        if(item == 0){
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
            break;
        }
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tItem name :\t\t%s\n",beverage_food_list[item-1].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size Price :\t%d\n", beverage_food_list[item-1].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size Price :\t%d\n", beverage_food_list[item-1].food_chFoodStruct->l_size);
        printf("\n\n\n\t\t\t\t\tBe careful and sure before modifying an item!!\n");
        printf("\t\t\t\t\ttype YES to modify this item\n");
            printf("\t\t\t\t\t");

        scanf("%s",con);
        if( strcmp(con,"YES") == 0  || strcmp(con,"yes") == 0 )
            modify_fun( file_name);
        else{
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\t\t\t\t\tModification Process canceled\n");
            slp();
        }
        break;
    default:
        //printf("\t\t\t\t\tNot Created yet\n");
        //slp();
        break;
    }
}

void remove_item_fun(int line_no, char file_name[]){

    FILE *tmp;
    FILE *read;
    char temp_file[]={"temp.txt"};
    tmp=fopen(temp_file,"w");
    int i=1;
    read=fopen(file_name,"r");
    while(fgets(line,sizeof(line),read)!=NULL){
        //printf("Line = %s",line);
        if(i==line_no){
            i++;
            continue;
        }
        else{
            fprintf(tmp,"%s",line);
            //printf("%s",line);
        }
        i++;
    }
    fclose(read);
    fclose(tmp);
    printf("\n\n\n\n\n");
    read=fopen(file_name,"w");
    tmp=fopen(temp_file,"r");

    while(fgets(line,sizeof(line),tmp)!=NULL){
        fprintf(read,"%s",line);
        //printf("%s\n",line);
    }
    fflush(stdin);
    //getchar();
    fclose(read);
    fclose(tmp);

    // remove(file_name);
    // rename(temp_file, file_name);
    system("cls"); //gotoxy(40,6);
    //gotoxy(40,6);

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
    printf("\n\n\n\n\t\t\t\t\tRemoving Successful\n");
    slp();
}

void re_move(){
    char file_name[25];
    char ck[5];
    //int item;
    menu();
    printf("\n\t\t\t\t\tSelect a catagory\n");
    scanf("%d",&item);
    switch(item){
        case 1:
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            fflush(stdin);
            strcpy(file_name,"fastfood.txt");
            print_fast_food();
            printf("\n\t\t\t\t\tEnter code which item to remove - ");
            scanf("%d",&item);
            if(item == 0){
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");
                sleep(1);
                break;
            }
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\n\n\t\t\t\t\tName - %s\n",fast_food_list[item-1].food_chFoodStruct->name);
            printf("\t\t\t\t\tMedium Size price - %d\n",fast_food_list[item-1].food_chFoodStruct->m_size);
            printf("\t\t\t\t\tLarge size price - %d\n",fast_food_list[item-1].food_chFoodStruct->l_size);
            printf("\n\n\t\t\t\t\tDo you really want to remove this item?\n");
            printf("\t\t\t\t\tThis cannot be undone. Proceed carefully\n");
            printf("\t\t\t\t\tType yes to remove this item\n");
            printf("\t\t\t\t\t");
            scanf("%s",ck);
            if(strcmp(ck,"yes")==0)
                remove_item_fun(item,file_name);
            else{
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");

                printf("\n\n\n\t\t\t\t\tGoing to main menu\n");
                sleep(1);
                break;
            }
            break;
        case 2:
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            fflush(stdin);
            strcpy(file_name,"thaifood.txt");
            print_thai_food();
            printf("\n\t\t\t\t\tEnter code which item to remove - ");
            scanf("%d",&item);
            if(item == 0){
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");
                sleep(1);
                break;
            }
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\n\n\t\t\t\t\tName - %s\n",thai_food_list[item-1].food_chFoodStruct->name);
            printf("\t\t\t\t\tMedium Size price - %d\n",thai_food_list[item-1].food_chFoodStruct->m_size);
            printf("\t\t\t\t\tLarge size price - %d\n",thai_food_list[item-1].food_chFoodStruct->l_size);
            printf("\n\n\t\t\t\t\tDo you really want to remove this item?\n");
            printf("\t\t\t\t\tThis cannot be undone. Proceed carefully\n");
            printf("\t\t\t\t\tType yes to remove this item\n");
            printf("\t\t\t\t\t");
            scanf("%s",ck);
            if(strcmp(ck,"yes")==0)
                remove_item_fun(item,file_name);
            else{
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");
                printf("\n\n\n\t\t\t\t\tGoing to main menu\n");
                sleep(1);
                break;
            }
            break;

        case 3:
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            fflush(stdin);
            strcpy(file_name,"indianfood.txt");
            print_indian_food();
            printf("\n\t\t\t\t\tEnter code which item to remove - ");
            scanf("%d",&item);
            if(item == 0){
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");
                sleep(1);
                break;
            }
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\n\n\t\t\t\t\tName - %s\n",indian_food_list[item-1].food_chFoodStruct->name);
            printf("\t\t\t\t\tMedium Size price - %d\n",indian_food_list[item-1].food_chFoodStruct->m_size);
            printf("\t\t\t\t\tLarge size price - %d\n",indian_food_list[item-1].food_chFoodStruct->l_size);
            printf("\n\n\t\t\t\t\tDo you really want to remove this item?\n");
            printf("\t\t\t\t\tThis cannot be undone. Proceed carefully\n");
            printf("\t\t\t\t\tType yes to remove this item\n");
            printf("\t\t\t\t\t");

            scanf("%s",ck);
            if(strcmp(ck,"yes")==0)
                remove_item_fun(item,file_name);
            else{
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");

                printf("\n\n\n\t\t\t\t\tGoing to main menu\n");
                sleep(1);
                break;
            }
            break;
        case 4:
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            fflush(stdin);
            strcpy(file_name,"chinesefood.txt");
            print_chinese_food();
            printf("\n\t\t\t\t\tEnter code which item to remove - ");
            scanf("%d",&item);
            if(item == 0){
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");
                sleep(1);
                break;
            }
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\n\n\t\t\t\t\tName - %s\n",chinese_food_list[item-1].food_chFoodStruct->name);
            printf("\t\t\t\t\tMedium Size price - %d\n",chinese_food_list[item-1].food_chFoodStruct->m_size);
            printf("\t\t\t\t\tLarge size price - %d\n",chinese_food_list[item-1].food_chFoodStruct->l_size);
            printf("\n\n\t\t\t\t\tDo you really want to remove this item?\n");
            printf("\t\t\t\t\tThis cannot be undone. Proceed carefully\n");
            printf("\t\t\t\t\tType yes to remove this item\n");
            printf("\t\t\t\t\t");

            scanf("%s",ck);
            if(strcmp(ck,"yes")==0)
                remove_item_fun(item,file_name);
            else{
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");

                printf("\n\n\n\t\t\t\t\tGoing to main menu\n");
                sleep(1);
                break;
            }
            break;
        case 5:
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            fflush(stdin);
            strcpy(file_name,"dessertfood.txt");
            print_dessert_food();
            printf("\n\t\t\t\t\tEnter code which item to remove - ");
            scanf("%d",&item);
            if(item == 0){
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");
                sleep(1);
                break;
            }
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\n\n\t\t\t\t\tName - %s\n",dessert_food_list[item-1].food_chFoodStruct->name);
            printf("\t\t\t\t\tMedium Size price - %d\n",dessert_food_list[item-1].food_chFoodStruct->m_size);
            printf("\t\t\t\t\tLarge size price - %d\n",dessert_food_list[item-1].food_chFoodStruct->l_size);
            printf("\n\n\t\t\t\t\tDo you really want to remove this item?\n");
            printf("\t\t\t\t\tThis cannot be undone. Proceed carefully\n");
            printf("\t\t\t\t\tType yes to remove this item\n");
            printf("\t\t\t\t\t");

            scanf("%s",ck);
            if(strcmp(ck,"yes")==0)
                remove_item_fun(item,file_name);
            else{
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");

                printf("\n\n\n\t\t\t\t\tGoing to main menu\n");
                sleep(1);
                break;
            }
            break;
        case 6:
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            fflush(stdin);
            strcpy(file_name,"beveragefood.txt");
            print_beverage_food();
            printf("\n\t\t\t\t\tEnter code which item to remove - ");
            scanf("%d",&item);
            if(item == 0){
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");
                sleep(1);
                break;
            }
            system("cls"); //gotoxy(40,6);
            //gotoxy(40,6);
            printf("\n\n\n\t\t\t\t\tName - %s\n",beverage_food_list[item-1].food_chFoodStruct->name);
            printf("\t\t\t\t\tMedium Size price - %d\n",beverage_food_list[item-1].food_chFoodStruct->m_size);
            printf("\t\t\t\t\tLarge size price - %d\n",beverage_food_list[item-1].food_chFoodStruct->l_size);
            printf("\n\n\t\t\t\t\tDo you really want to remove this item?\n");
            printf("\t\t\t\t\tThis cannot be undone. Proceed carefully\n");
            printf("\t\t\t\t\tType yes to remove this item\n");
            printf("\t\t\t\t\t");

            scanf("%s",ck);
            if(strcmp(ck,"yes")==0)
                remove_item_fun(item,file_name);
            else{
                printf("\n\n\t\t\t\t\tRemoving Process canceled\n");

                printf("\n\n\n\t\t\t\t\tGoing to main menu\n");
                sleep(1);
                break;
            }
            break;
        default :
            break;

    }
}

void add_item_fun(FILE *read){

    char y;
    char name[25];
    int mprice,lprice;

    switch (item){
    case 1:
        printf("\n\n\n\t\t\t\t\tSerial No. of the product is - %d\n",line_of_fast_food);
again_1:
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tEnter Item name\n");
        printf("\t\t\t\t\t");
        fflush(stdin);
        gets(name);
        printf("\t\t\t\t\tEnter - %s - Item's medium size price : ",name);
        scanf("%d",&mprice);
        printf("\n\t\t\t\t\t\n");
        printf("\t\t\t\t\tEnter - %s - Item's Large size price : ",name);
        scanf("%d",&lprice);
        printf("\n\t\t\t\t\t\n");
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tItem name : %s\n",name);
        printf("\t\t\t\t\tMedium Size Price : %d\n",mprice);
        printf("\t\t\t\t\tLarge Size Price : %d\n",lprice);
        printf("\n\t\t\t\t\t");
        printf("\n\t\t\t\t\tDo you want to make any change(s) (y/n)?\n");
        printf("\t\t\t\t\t");
        //printf("\t\t\t\t\tEnter any Other alphabet to save as it is.\nEnter 'Y' if you want to make any change(s) - ");
        scanf(" %c", &y);
        if(y== 'Y' || y== 'y'){
            system("cls"); //gotoxy(40,6);
            goto again_1;
        }
        for(int i=0;name[i]!='\0';i++){
            if(name[i]==' ') name[i]='_';
        }
        line[0]='\0';

        strcat(line,name);
        strcat(line,"*");

        itoa(mprice, temp, 10);

        strcat(line,temp);
        strcat(line,"*");

        itoa(lprice, temp, 10);
        strcat(line,temp);
        strcat(line,"*");

        fprintf(read,"%s\n",line);
        system("cls");
        printf("\n\n\n\t\t\t\t\tAdding Item successful\n");
        slp();

        fflush(stdin);
        //getchar();
        fclose(read);
        //strcat();
        break;
    case 2:
        printf("\n\n\n\t\t\t\t\tSerial No. of the product is - %d\n",line_of_thai_food);
again_2:
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tEnter Item name\n");
        printf("\t\t\t\t\t");
        fflush(stdin);
        gets(name);
        printf("\t\t\t\t\tEnter - %s - Item's medium size price : ",name);
        scanf("%d",&mprice);
        printf("\n\t\t\t\t\t\n");
        printf("\t\t\t\t\tEnter - %s - Item's Large size price : ",name);
        scanf("%d",&lprice);
        printf("\n\t\t\t\t\t\n");
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\n\t\t\t\t\t\tItem name : %s\n",name);
        printf("\t\t\t\t\tMedium Size Price : %d\n",mprice);
        printf("\t\t\t\t\tLarge Size Price : %d\n",lprice);
        printf("\n\t\t\t\t\t");
        printf("\n\t\t\t\t\tDo you want to make any change(s) (y/n)?\n");
        printf("\t\t\t\t\t");
        //printf("\t\t\t\t\tEnter any Other alphabet to save as it is.\nEnter 'Y' if you want to make any change(s) - ");
        scanf(" %c",&y);
        if(y== 'Y' || y== 'y'){
            system("cls"); //gotoxy(40,6);
            goto again_2;
        }
        for(int i=0;name[i]!='\0';i++){
            if(name[i]==' ') name[i]='_';
        }
        line[0]='\0';

        strcat(line,name);
        strcat(line,"*");

        itoa(mprice, temp, 10);

        strcat(line,temp);
        strcat(line,"*");

        itoa(lprice, temp, 10);
        strcat(line,temp);
        strcat(line,"*");

        fprintf(read,"%s\n",line);
        system("cls");
        printf("\n\n\n\t\t\t\t\tAdding Item successful\n");
        slp();

        fflush(stdin);
        //getchar();
        fclose(read);
        //strcat();
        break;
    case 3:
        printf("\n\n\n\t\t\t\t\tSerial No. of the product is - %d\n",line_of_indian_food);
again_3:
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tEnter Item name\n");
        printf("\t\t\t\t\t");
        fflush(stdin);
        gets(name);
        printf("\t\t\t\t\tEnter - %s - Item's medium size price : ",name);
        scanf("%d",&mprice);
        printf("\n\t\t\t\t\t\n");
        printf("\t\t\t\t\tEnter - %s - Item's Large size price : ",name);
        scanf("%d",&lprice);
        printf("\n\t\t\t\t\t\n");
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\n\t\t\t\t\t\tItem name : %s\n",name);
        printf("\t\t\t\t\tMedium Size Price : %d\n",mprice);
        printf("\t\t\t\t\tLarge Size Price : %d\n",lprice);
        printf("\n\t\t\t\t\t");
        printf("\n\t\t\t\t\tDo you want to make any change(s) (y/n)?\n");
        printf("\t\t\t\t\t");
        //printf("\t\t\t\t\tEnter any Other alphabet to save as it is.\nEnter 'Y' if you want to make any change(s) - ");
        scanf(" %c",&y);
        if(y== 'Y' || y== 'y'){
            system("cls"); //gotoxy(40,6);
            goto again_3;
        }
        for(int i=0;name[i]!='\0';i++){
            if(name[i]==' ') name[i]='_';
        }
        line[0]='\0';

        strcat(line,name);
        strcat(line,"*");

        itoa(mprice, temp, 10);

        strcat(line,temp);
        strcat(line,"*");

        itoa(lprice, temp, 10);
        strcat(line,temp);
        strcat(line,"*");

        fprintf(read,"%s\n",line);
        system("cls");
        printf("\n\n\n\t\t\t\t\tAdding Item successful\n");
        slp();

        fflush(stdin);
        //getchar();
        fclose(read);
        //strcat();
        break;
    case 4:
        printf("\n\n\n\t\t\t\t\tSerial No. of the product is - %d\n",line_of_chinese_food);
again_4:
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tEnter Item name\n");
        printf("\t\t\t\t\t");
        fflush(stdin);
        gets(name);
        printf("\t\t\t\t\tEnter - %s - Item's medium size price : ",name);
        scanf("%d",&mprice);
        printf("\n\t\t\t\t\t\n");
        printf("\t\t\t\t\tEnter - %s - Item's Large size price : ",name);
        scanf("%d",&lprice);
        printf("\n\t\t\t\t\t\n");
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\n\t\t\t\t\t\tItem name : %s\n",name);
        printf("\t\t\t\t\tMedium Size Price : %d\n",mprice);
        printf("\t\t\t\t\tLarge Size Price : %d\n",lprice);
        printf("\n\t\t\t\t\t");
        printf("\n\t\t\t\t\tDo you want to make any change(s) (y/n)?\n");
        printf("\t\t\t\t\t");

        //printf("\t\t\t\t\tEnter any Other alphabet to save as it is.\nEnter 'Y' if you want to make any change(s) - ");
        scanf(" %c",&y);
        if(y== 'Y' || y== 'y'){
            system("cls"); //gotoxy(40,6);
            goto again_4;
        }
        for(int i=0;name[i]!='\0';i++){
            if(name[i]==' ') name[i]='_';
        }
        line[0]='\0';

        strcat(line,name);
        strcat(line,"*");

        itoa(mprice, temp, 10);

        strcat(line,temp);
        strcat(line,"*");

        itoa(lprice, temp, 10);
        strcat(line,temp);
        strcat(line,"*");

        fprintf(read,"%s\n",line);
        system("cls");
        printf("\n\n\n\t\t\t\t\tAdding Item successful\n");
        slp();

        fflush(stdin);
        //getchar();
        fclose(read);
        //strcat();
        break;
    case 5:
        printf("\n\n\n\t\t\t\t\tSerial No. of the product is - %d\n",line_of_dessert_food);
again_5:
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\tEnter Item name\n");
        printf("\t\t\t\t\t");
        fflush(stdin);
        gets(name);
        printf("\t\t\t\t\tEnter - %s - Item's medium size price : ",name);
        scanf("%d",&mprice);
        printf("\n\t\t\t\t\t\n");
        printf("\t\t\t\t\tEnter - %s - Item's Large size price : ",name);
        scanf("%d",&lprice);
        printf("\n\t\t\t\t\t\n");
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\n\t\t\t\t\t\tItem name : %s\n",name);
        printf("\t\t\t\t\tMedium Size Price : %d\n",mprice);
        printf("\t\t\t\t\tLarge Size Price : %d\n",lprice);
        printf("\n\t\t\t\t\t");
        printf("\n\t\t\t\t\tDo you want to make any change(s) (y/n)?\n");
        printf("\t\t\t\t\t");

        //printf("\t\t\t\t\tEnter any Other alphabet to save as it is.\nEnter 'Y' if you want to make any change(s) - ");
        scanf(" %c",&y);
        if(y== 'Y' || y== 'y'){
            system("cls"); //gotoxy(40,6);
            goto again_5;
        }
        for(int i=0;name[i]!='\0';i++){
            if(name[i]==' ') name[i]='_';
        }
        line[0]='\0';

        strcat(line,name);
        strcat(line,"*");

        itoa(mprice, temp, 10);

        strcat(line,temp);
        strcat(line,"*");

        itoa(lprice, temp, 10);
        strcat(line,temp);
        strcat(line,"*");

        fprintf(read,"%s\n",line);
        system("cls");
        printf("\n\n\n\t\t\t\t\tAdding Item successful\n");
        slp();

        fflush(stdin);
        //getchar();
        fclose(read);
        //strcat();
        break;
    case 6:
        printf("\n\n\n\t\t\t\t\tSerial No. of the product is - %d\n",line_of_beverage_food);
again_6:
        //gotoxy(40,6);
        printf("\n\n\n\t\t\t\t\t\tEnter Item name\n");
        printf("\t\t\t\t\t");
        fflush(stdin);
        gets(name);
        printf("\t\t\t\t\tEnter - %s - Item's medium size price : ",name);
        scanf("%d",&mprice);
        printf("\n\t\t\t\t\t\n");
        printf("\t\t\t\t\tEnter - %s - Item's Large size price : ",name);
        scanf("%d",&lprice);
        printf("\n\t\t\t\t\t\n");
        system("cls"); //gotoxy(40,6);
        //gotoxy(40,6);
        printf("\t\t\t\t\tItem name : %s\n",name);
        printf("\t\t\t\t\tMedium Size Price : %d\n",mprice);
        printf("\t\t\t\t\tLarge Size Price : %d\n",lprice);
        printf("\n\t\t\t\t\t");
        printf("\n\t\t\t\t\tDo you want to make any change(s) (y/n)?\n");
        printf("\t\t\t\t\t");

        //printf("\t\t\t\t\tEnter any Other alphabet to save as it is.\nEnter 'Y' if you want to make any change(s) - ");
        scanf(" %c",&y);
        if(y== 'Y' || y== 'y'){
            system("cls"); //gotoxy(40,6);
            goto again_6;
        }
        for(int i=0;name[i]!='\0';i++){
            if(name[i]==' ') name[i]='_';
        }
        line[0]='\0';

        strcat(line,name);
        strcat(line,"*");

        itoa(mprice, temp, 10);

        strcat(line,temp);
        strcat(line,"*");

        itoa(lprice, temp, 10);
        strcat(line,temp);
        strcat(line,"*");

        fprintf(read,"%s\n",line);
        system("cls");
        printf("\n\n\n\t\t\t\t\tAdding Item successful\n");
        slp();

        fflush(stdin);
        //getchar();
        fclose(read);
        //strcat();
        break;
    default:
        break;
    }

}

void add(){
    fflush(stdin);
    system("cls"); //gotoxy(40,6);
    //gotoxy(40,6);
    //int item;
    FILE *read;
    menu();
    //gotoxy(40,6);
    printf("\n\t\t\t\t\tSelect a catagory\n");
    scanf("%d",&item);
    switch(item){
        case 1 :
            system("cls"); //gotoxy(40,6);
            fflush(stdin);
            read=fopen("fastfood.txt","a");
            line_of_fast_food=line_of_fast_food+1;
            add_item_fun(read);
            break;
        case 2:
            system("cls"); //gotoxy(40,6);
            fflush(stdin);
            read=fopen("thaifood.txt","a");
            line_of_thai_food=line_of_thai_food+1;
            add_item_fun(read);
            break;
        case 3:
            system("cls"); //gotoxy(40,6);
            fflush(stdin);
            read=fopen("indianfood.txt","a");
            line_of_indian_food=line_of_indian_food+1;
            add_item_fun(read);
            break;
        case 4:
            system("cls"); //gotoxy(40,6);
            fflush(stdin);
            read=fopen("chinesefood.txt","a");
            line_of_chinese_food=line_of_chinese_food+1;
            add_item_fun(read);
            break;
        case 5:
            system("cls"); //gotoxy(40,6);
            fflush(stdin);
            read=fopen("dessertfood.txt","a");
            line_of_dessert_food=line_of_dessert_food+1;
            add_item_fun(read);
            break;
        case 6:
            system("cls"); //gotoxy(40,6);
            fflush(stdin);
            read=fopen("beveragefood.txt","a");
            line_of_beverage_food=line_of_beverage_food+1;
            add_item_fun(read);
            break;
        default :
            printf("\t\t\t\t\tWrong Input\n");
            slp();
    }
}

void gotoxy(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void show_time(){
    fflush(stdin);
    //system("cls"); //gotoxy(40,6);
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo=localtime(&rawtime);
    //ti_me=asctime(timeinfo);
    //strcpy(ti_me,asctime(timeinfo));
    printf("\n%s\n\n", asctime(timeinfo));
    //printf("\n\t\t\t\t\t");
}

void menu(){
    //goto4(10,10);
    system("cls"); //gotoxy(40,6);
    fflush(stdin);
    printf("\n\n\n\t\t\t\t\tCATAGORIES\n");
    printf("\n\n\t\t\t\t\t1.Fast Food\n");
    printf("\t\t\t\t\t2.Thai Food\n");
    printf("\t\t\t\t\t3.Indian Food\n");
    printf("\t\t\t\t\t4.Chinese Food\n");
    printf("\t\t\t\t\t5.Dessert\n");
    printf("\t\t\t\t\t6.Beverage\n");
}

int input_check(int a,int b){
    if(a>0 && a<=b)return 0;
    else return 1;
}


void chk_str(){
    //printf("\t\t\t\t\tThis 4 chk_str function = %s\n",line);
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
    //printf("\t\t\t\t\tThis is from str_conv fun = %s\n",line);
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

        // str_conv(0,lineBreak[0]);
        // strcpy(beverage_food_list[i].foodConv_chFoodStruct->code_string, temp);
        // beverage_food_list[i].food_chFoodStruct->code=atoi(beverage_food_list[i].foodConv_chFoodStruct->code_string);
        beverage_food_list[i].food_chFoodStruct->code=line_of_beverage_food+1;

        str_conv(0,lineBreak[0]);
        strcpy(beverage_food_list[i].food_chFoodStruct->name,temp);

        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(beverage_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        beverage_food_list[i].food_chFoodStruct->m_size=atoi(beverage_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[1]+1,lineBreak[2]);
        // str_conv(lineBreak[2]+1,lineBreak[3]);
        strcpy(beverage_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        beverage_food_list[i].food_chFoodStruct->l_size=atoi(beverage_food_list[i].foodConv_chFoodStruct->l_size_string);

        line_of_beverage_food++;
        i++;
    }
    fclose(read);
}
void print_beverage_food(){
    system("cls");
    printf("Enter 0 to go back\n\n\n");
    printf("\n\t\t\t\t\t--Beverage List--\n\n\n\n\n");
    //gotoxy(40,6);
    for(int i=0;beverage_food_list[i].food_chFoodStruct->code!=0;i++){
        printf("\t\t\t\t\tCode = %d\n", beverage_food_list[i].food_chFoodStruct->code);
        printf("\n\t\t\t\t\t%s\n",beverage_food_list[i].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size = %d\n",beverage_food_list[i].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size = %d\n",beverage_food_list[i].food_chFoodStruct->l_size);
        printf("\n\t\t\t\t\t---------------\n\n");
    }
}


void read_dessert_food(){
    FILE *read;
    int i=0;
    read=fopen("dessert.txt","r");
    while(fgets(line,sizeof(line),read)!=NULL){
        chk_str();

        // str_conv(0,lineBreak[0]);
        // strcpy(dessert_food_list[i].foodConv_chFoodStruct->code_string, temp);
        dessert_food_list[i].food_chFoodStruct->code=line_of_dessert_food+1;

        str_conv(0,lineBreak[0]);
        strcpy(dessert_food_list[i].food_chFoodStruct->name,temp);

        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(dessert_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        dessert_food_list[i].food_chFoodStruct->m_size=atoi(dessert_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[1]+1,lineBreak[2]);
        strcpy(dessert_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        dessert_food_list[i].food_chFoodStruct->l_size=atoi(dessert_food_list[i].foodConv_chFoodStruct->l_size_string);

        line_of_dessert_food++;
        i++;
    }
    fclose(read);
}
void print_dessert_food(){
    system("cls"); //gotoxy(40,6);
    printf("Enter 0 to go back\n\n\n");

    printf("\n\t\t\t\t\t--DESSERT List--\n\n\n\n\n");
    for(int i=0;dessert_food_list[i].food_chFoodStruct->code!=0;i++){
        printf("\t\t\t\t\tCode = %d\n", dessert_food_list[i].food_chFoodStruct->code);
        printf("\n\t\t\t\t\t%s\n",dessert_food_list[i].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size = %d\n",dessert_food_list[i].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size = %d\n",dessert_food_list[i].food_chFoodStruct->l_size);
        printf("\n\t\t\t\t\t---------------\n\n");
    }
}

void read_chinese_food(){
    FILE *read;
    int i=0;
    read=fopen("chinesefood.txt","r");
    while(fgets(line,sizeof(line),read)!=NULL){
        chk_str();

        // str_conv(0,lineBreak[0]);
        // chinese
        chinese_food_list[i].food_chFoodStruct->code=line_of_chinese_food+1;

        str_conv(0,lineBreak[0]);
        strcpy(chinese_food_list[i].food_chFoodStruct->name,temp);

        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(chinese_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        chinese_food_list[i].food_chFoodStruct->m_size=atoi(chinese_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[1]+1,lineBreak[2]);
        strcpy(chinese_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        chinese_food_list[i].food_chFoodStruct->l_size=atoi(chinese_food_list[i].foodConv_chFoodStruct->l_size_string);

        line_of_chinese_food++;
        i++;
    }
    fclose(read);
}
void print_chinese_food(){
    system("cls"); //gotoxy(40,6);
    printf("Enter 0 to go back\n\n\n");

    printf("\n\t\t\t\t\t--CHINESE Food --\n\n\n\n\n");
    for(int i=0;chinese_food_list[i].food_chFoodStruct->code!=0;i++){
        printf("\t\t\t\t\tCode = %d\n", chinese_food_list[i].food_chFoodStruct->code);
        printf("\n\t\t\t\t\t%s\n",chinese_food_list[i].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size = %d\n",chinese_food_list[i].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size = %d\n",chinese_food_list[i].food_chFoodStruct->l_size);
        printf("\n\t\t\t\t\t---------------\n\n");
    }
}

void read_indian_food(){
    FILE *read;
    int i=0;
    read=fopen("indianfood.txt","r");

    while(fgets(line,sizeof(line),read)!=NULL){
        chk_str();

        // str_conv(0,lineBreak[0]);
        // strcpy(indian_food_list[i].foodConv_chFoodStruct->code_string, temp);

        indian_food_list[i].food_chFoodStruct->code=line_of_indian_food+1;

        str_conv(0,lineBreak[0]);
        strcpy(indian_food_list[i].food_chFoodStruct->name,temp);


        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(indian_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        indian_food_list[i].food_chFoodStruct->m_size=atoi(indian_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[1]+1,lineBreak[2]);
        strcpy(indian_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        indian_food_list[i].food_chFoodStruct->l_size=atoi(indian_food_list[i].foodConv_chFoodStruct->l_size_string);

        line_of_indian_food++;
        i++;
    }
    fclose(read);
}
void print_indian_food(){
    system("cls"); //gotoxy(40,6);
    printf("Enter 0 to go back\n\n\n");

    printf("\n\t\t\t\t\t--INDIAN Food --\n\n\n\n\n");
    for(int i=0;indian_food_list[i].food_chFoodStruct->code!=0;i++){
        printf("\t\t\t\t\tCode = %d\n", indian_food_list[i].food_chFoodStruct->code);
        printf("\n\t\t\t\t\t%s\n",indian_food_list[i].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size = %d\n",indian_food_list[i].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size = %d\n",indian_food_list[i].food_chFoodStruct->l_size);
        printf("\n\t\t\t\t\t---------------\n\n");
    }
}

void read_fast_food(){
    FILE *read;
    int i=0;
    read=fopen("fastfood.txt","r");

    while(fgets(line,sizeof(line),read)!=NULL){
        chk_str();

        // str_conv(0,lineBreak[0]);
        // fast
        fast_food_list[i].food_chFoodStruct->code=line_of_fast_food+1;

        str_conv(0,lineBreak[0]);
        strcpy(fast_food_list[i].food_chFoodStruct->name,temp);


        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(fast_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        fast_food_list[i].food_chFoodStruct->m_size=atoi(fast_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[1]+1,lineBreak[2]);
        strcpy(fast_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        fast_food_list[i].food_chFoodStruct->l_size=atoi(fast_food_list[i].foodConv_chFoodStruct->l_size_string);

        line_of_fast_food++;
        i++;
    }
    fclose(read);
}
void print_fast_food(){
    system("cls"); //gotoxy(40,6);
    printf("Enter 0 to go back\n\n\n");

    printf("\n\t\t\t\t\t--FAST Food --\n\n\n\n\n");
    for(int i=0;i<line_of_fast_food;i++){
        printf("\t\t\t\t\tCode = %d\n", fast_food_list[i].food_chFoodStruct->code);
        printf("\n\t\t\t\t\t%s\n",fast_food_list[i].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size = %d\n",fast_food_list[i].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size = %d\n",fast_food_list[i].food_chFoodStruct->l_size);
        printf("\n\t\t\t\t\t---------------\n\n");
    }
}

void read_thai_food(){
    FILE *read;
    int i=0;
    read=fopen("thaifood.txt","r");

    while(fgets(line,sizeof(line),read)!=NULL){
        chk_str();

        // str_conv(0,lineBreak[0]);
        // strcpy(thai_food_list[i].foodConv_chFoodStruct->code_string, temp);
        thai_food_list[i].food_chFoodStruct->code=line_of_thai_food+1;

        str_conv(0,lineBreak[0]);
        strcpy(thai_food_list[i].food_chFoodStruct->name,temp);


        str_conv(lineBreak[0]+1,lineBreak[1]);
        strcpy(thai_food_list[i].foodConv_chFoodStruct->m_size_string,temp);
        thai_food_list[i].food_chFoodStruct->m_size=atoi(thai_food_list[i].foodConv_chFoodStruct->m_size_string);

        str_conv(lineBreak[1]+1,lineBreak[2]);
        strcpy(thai_food_list[i].foodConv_chFoodStruct->l_size_string,temp);
        thai_food_list[i].food_chFoodStruct->l_size=atoi(thai_food_list[i].foodConv_chFoodStruct->l_size_string);

        i++;
        line_of_thai_food++;
    }
    fclose(read);
}

void print_thai_food(){
    system("cls"); //gotoxy(40,6);
    printf("Enter 0 to go back\n\n\n");

    printf("\n\t\t\t\t\t--THAI Food --\n\n\n\n\n");
    for(int i=0; i<line_of_thai_food;i++){
        printf("\t\t\t\t\tCode = %d\n", thai_food_list[i].food_chFoodStruct->code);
        printf("\n\t\t\t\t\t%s\n",thai_food_list[i].food_chFoodStruct->name);
        printf("\t\t\t\t\tMedium Size = %d\n",thai_food_list[i].food_chFoodStruct->m_size);
        printf("\t\t\t\t\tLarge Size = %d\n",thai_food_list[i].food_chFoodStruct->l_size);
        printf("\n\t\t\t\t\t---------------\n\n");
    }
}

void order(int order_item){
    int size_price,selected_item,quantity,brk;
    int total_price=0;
    int i=order_serial;
    switch (order_item){
        case 0:
            system("cls"); //gotoxy(40,6);
            printf("\t\t\t\t\tWrong Input!\n");
            printf("\t\t\t\t\tGoing back to menu!\n");
            flag = 1;
            slp();
            break;
        case 1:

            while(1){
        chking_1:
                print_fast_food();
                printf("\t\t\tEnter item no - ");
                scanf("%d",&selected_item);
                printf("\n");

                if(selected_item==0){
                        system("cls"); //gotoxy(40,6);
                        printf("\t\t\t\t\tGoing back to menu!\n");
                        flag = 1;
                        slp();
                        break;
                    }

                else if(input_check(selected_item,line_of_fast_food)){
                        system("cls"); //gotoxy(40,6);
                        printf("\n\n\n\t\t\t\t\tWrong Input\n");
                        //getchar();
                        slp();
                        system("cls");
                        goto chking_1;
                    }

                order_info_global[i].itm_no=fast_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,fast_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls"); //gotoxy(40,6);

            s_l1:
                //printf("\n\t\t\t\t\t\nEnter 0 to go back\n\n\n");
                printf("\n\n\t\t\t\t\tselected item -\t%s\n\n",fast_food_list[selected_item-1].food_chFoodStruct->name);
                printf("\n\t\t\t\t\tSelect size\n\n");
                //printf("\n");
                printf("\t\t\t\t\t1.Medium - %d\n", fast_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("\t\t\t\t\t2.Large - %d\n", fast_food_list[selected_item-1].food_chFoodStruct->l_size);
                printf("\n\t\t\t\t\t");

                scanf("%d",&size_price);
                printf("\n\t\t\t\t\t");


                if(size_price==1){
                    order_info_global[i].price=fast_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("\t\t\t\t\tMedium size selected\n");
                }
                else if(size_price == 2){
                    order_info_global[i].price=fast_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("\t\t\t\t\tLarge size selected\n");
                }
                else{
                    printf("Wrong Input\n");
                    printf("\n\t\t\t\t\t");
                    printf("Enter Again\n");
                    slp();
                    system("cls");
                    goto s_l1;
                }
            q_1:
                printf("\n\t\t\t\t\tEnter Quantity\n");
                printf("\n\t\t\t\t\t");

                scanf("%d",&quantity);
                if(quantity == 0){
                    printf("\n\t\t\t\t\tQuantity cannot be zero !!!\n");
                    printf("\t\t\t\t\tEnter again\n");
                    //slp();
                    goto q_1;
                }
                total_quantity+=quantity;
                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("\n\n\t\t\t\t\t%s --- %d x %d = %d\n\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
        ag_1:
                printf("\n\n\t\t\t\t\tNeed anythin else from fast food ? (Y / N)\n");
                //("\n\t\t\t\t\tTo confirm and go back to menu list press 0\n");
                fflush(stdin);

                //che=getchar();
                //scanf("%c",&che);
                printf("\t\t\t\t\t");
            //    scanf(" %c", &cheking);
                scanf(" %c", &cheking);

                //scanf("%s",ch);
                //printf("Checking %c\n", cheking);
                if(cheking == 'Y' || cheking == 'y')
                        goto chking_1;
                else if(cheking == 'N' || cheking == 'n')
                        break;
                else{
                    printf("\t\t\t\t\tEnter Carefully!!!\n");
                    fflush(stdin);
                    //getchar();
                    goto ag_1;
                }


            }
            break;
        case 2:

            while(1){
        chking_2:
                system("cls"); //gotoxy(40,6);
                printf("Enter 0 to go back\n\n\n");
                print_thai_food();

                printf("\t\t\tEnter item no- ");
                scanf("%d",&selected_item);
                printf("\n");

                if(selected_item==0){
                        system("cls"); //gotoxy(40,6);
                        printf("\t\t\t\t\tGoing back to menu!\n");
                        flag = 1;
                        slp();
                        break;
                    }
                else if(input_check(selected_item,line_of_thai_food)){
                        printf("\t\t\t\t\tWrong Input\n");
                        //getchar();
                        slp();
                        goto chking_2;
                    }

                order_info_global[i].itm_no=thai_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,thai_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls"); //gotoxy(40,6);
                printf("\n\n\t\t\t\t\tselected item -\t%s\n\n",thai_food_list[selected_item-1].food_chFoodStruct->name);
                printf("\n\t\t\t\t\tSelect size\n\n");
                //printf("\n");
                printf("\t\t\t\t\t1.Medium - %d\n", thai_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("\t\t\t\t\t2.Large - %d\n", thai_food_list[selected_item-1].food_chFoodStruct->l_size);
                printf("\n\t\t\t\t\t");

                scanf("%d",&size_price);
                printf("\n\t\t\t\t\t");

                if(size_price==1){
                    order_info_global[i].price=thai_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("\t\t\t\t\tMedium size selected\n");
                }
                else{
                    order_info_global[i].price=thai_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("\t\t\t\t\tLarge size selected\n");
                }

                printf("\n\t\t\t\t\tEnter Quantity\n");
                printf("\n\t\t\t\t\t");

                scanf("%d",&quantity);
                if(quantity == 0){
                    printf("\nQuantity cannot be zero !!!\n");
                    slp();
                    goto chking_2;
                }
                total_quantity+=quantity;
                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("\n\t\t\t\t\t%s --- %d x %d = %d\n\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
            ag_2:
                printf("\n\n\t\t\t\t\tNeed anythin else from thai food ? (Y / N)\n");
                //printf("\n\t\t\t\t\tTo confirm and go back to menu list press 0\n");
                //printf("\n\n\t\t\t\t\tTo place order press 0\n");
                fflush(stdin);
                //che=getchar();
                printf("\t\t\t\t\t");
                scanf(" %c",&cheking);
                //scanf("%s",ch);

                if(cheking == 'Y' || cheking == 'y')
                        goto chking_2;
                else if(cheking == 'N' || cheking == 'n')
                        break;
                else{
                    printf("\t\t\t\t\tEnter Carefully!!!\n");
                    fflush(stdin);
                    //getchar();
                    goto ag_2;
                }
            }
            break;
        case 3:
            while(1){
        chking_3:
                system("cls"); //gotoxy(40,6);
                printf("Enter 0 to go back\n\n\n");
                print_indian_food();

                printf("\t\t\tEnter item no- ");
                scanf("%d",&selected_item);
                printf("\n");

                if(selected_item==0){
                        system("cls"); //gotoxy(40,6);
                        printf("\t\t\t\t\tGoing back to menu!\n");
                        flag = 1;
                        slp();
                        break;
                    }
                    else if(input_check(selected_item,line_of_indian_food)){
                        printf("\t\t\t\t\tWrong Input\n");
                        //getchar();
                        slp();
                        goto chking_3;
                    }

                order_info_global[i].itm_no=indian_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,indian_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls"); //gotoxy(40,6);
                printf("\n\n\t\t\t\t\tselected item -\t%s\n\n",indian_food_list[selected_item-1].food_chFoodStruct->name);
                printf("\n\t\t\t\t\tSelect size\n\n");
                //printf("\n\t\t\t\t\t");
                printf("\t\t\t\t\t1.Medium - %d\n", indian_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("\t\t\t\t\t2.Large - %d\n", indian_food_list[selected_item-1].food_chFoodStruct->l_size);
                printf("\n\t\t\t\t\t");

                scanf("%d",&size_price);
                printf("\n\t\t\t\t\t");

                if(size_price==1){
                    order_info_global[i].price=indian_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("\t\t\t\t\tMedium size selected\n");
                }
                else{
                    order_info_global[i].price=indian_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("\t\t\t\t\tLarge size selected\n");
                }
                printf("\n\t\t\t\t\tEnter Quantity\n");
                printf("\n\t\t\t\t\t");

                scanf("%d",&quantity);
                if(quantity == 0){
                    printf("\nQuantity cannot be zero !!!\n");
                    slp();
                    goto chking_3;
                }
                total_quantity+=quantity;
                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("\n\t\t\t\t\t%s --- %d x %d = %d\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
            ag_3:
                printf("\n\n\t\t\t\t\tNeed anythin else from indian food ? (Y / N)\n");
                //printf("\t\t\t\t\tTo place order press 0\n");
                //printf("\n\t\t\t\t\tTo confirm and go back to menu list press 0\n");
                fflush(stdin);
                //che=getchar();
                printf("\t\t\t\t\t");
                scanf(" %c",&cheking);
                //scanf("%s",ch);
                if(cheking == 'Y' || cheking == 'y')
                        goto chking_3;
                else if(cheking == 'N' || cheking == 'n')
                        break;
                else{
                    printf("\t\t\t\t\tEnter Carefully!!!\n");
                    fflush(stdin);
                    //getchar();
                    goto ag_3;
                }
            }
            break;
        case 4:
            while(1){
        chking_4:
                system("cls"); //gotoxy(40,6);
                printf("Enter 0 to go back\n\n\n");
                print_chinese_food();

                printf("\t\t\tEnter item no- ");
                scanf("%d",&selected_item);
                printf("\n");

                if(selected_item==0){
                        system("cls"); //gotoxy(40,6);
                        printf("\t\t\t\t\tGoing back to menu!\n");
                        flag = 1;
                        slp();
                        break;
                    }
                else if(input_check(selected_item,line_of_chinese_food)){
                        printf("\t\t\t\t\tWrong Input\n");
                        //getchar();
                        slp();
                        goto chking_4;
                    }

                order_info_global[i].itm_no=chinese_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,chinese_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls"); //gotoxy(40,6);
                printf("\n\n\t\t\t\t\tselected item -\t%s\n\n",chinese_food_list[selected_item-1].food_chFoodStruct->name);
                printf("\n\t\t\t\t\tSelect size\n\n");
                //printf("\n\t\t\t\t\t");
                printf("\t\t\t\t\t1.Medium - %d\n", chinese_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("\t\t\t\t\t2.Large - %d\n", chinese_food_list[selected_item-1].food_chFoodStruct->l_size);
                printf("\n\t\t\t\t\t");

                scanf("%d",&size_price);
                printf("\n\t\t\t\t\t");

                if(size_price==1){
                    order_info_global[i].price=chinese_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("\t\t\t\t\tMedium size selected\n");
                }
                else{
                    order_info_global[i].price=chinese_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("\t\t\t\t\tLarge size selected\n");
                }
                printf("\n\t\t\t\t\tEnter Quantity\n");
                printf("\n\t\t\t\t\t");

                scanf("%d",&quantity);
                if(quantity == 0){
                    printf("\nQuantity cannot be zero !!!\n");
                    slp();
                    goto chking_4;
                }
                total_quantity+=quantity;

                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("\n\t\t\t\t\t%s --- %d x %d = %d\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
            ag_4:
                printf("\n\n\t\t\t\t\tNeed anythin else from chinese ? (Y / N)\n");
                //printf("\t\t\t\t\tTo place order press 0\n");
                //printf("\n\t\t\t\t\tTo confirm and go back to menu list press 0\n");
                fflush(stdin);
                //che=getchar();
                printf("\t\t\t\t\t");
                scanf(" %c",&cheking);
                //scanf("%s",ch);
                if(cheking == 'Y' || cheking == 'y')
                        goto chking_4;
                else if(cheking == 'N' || cheking == 'n')
                        break;
                else{
                    printf("\t\t\t\t\tEnter Carefully!!!\n");
                    fflush(stdin);
                    //getchar();
                    goto ag_4;
                }
            }
            break;
        case 5:
            while(1){
        chking_5:
                system("cls"); //gotoxy(40,6);
                printf("Enter 0 to go back\n\n\n");
                print_dessert_food();

                printf("\t\t\tEnter item no- ");
                scanf("%d",&selected_item);
                printf("\n");

                if(selected_item==0){
                        system("cls"); //gotoxy(40,6);
                        printf("\t\t\t\t\tGoing back to menu!\n");
                        flag = 1;
                        slp();
                        break;
                    }
                else if(input_check(selected_item,line_of_dessert_food)){
                        printf("\t\t\t\t\tWrong Input\n");
                        //getchar();
                        slp();
                        goto chking_5;
                    }

                order_info_global[i].itm_no=dessert_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,dessert_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls"); //gotoxy(40,6);
                printf("\n\n\t\t\t\t\tselected item -\t%s\n\n",dessert_food_list[selected_item-1].food_chFoodStruct->name);
                printf("\n\t\t\t\t\tSelect size\n\n");
                //printf("\n\t\t\t\t\t");
                printf("\t\t\t\t\t1.Medium - %d\n", dessert_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("\t\t\t\t\t2.Large - %d\n", dessert_food_list[selected_item-1].food_chFoodStruct->l_size);
                printf("\n\t\t\t\t\t");

                scanf("%d",&size_price);
                printf("\n\t\t\t\t\t");

                if(size_price==1){
                    order_info_global[i].price=dessert_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("\t\t\t\t\tMedium size selected\n");
                }
                else{
                    order_info_global[i].price=dessert_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("\t\t\t\t\tLarge size selected\n");
                }

                printf("\n\t\t\t\t\tEnter Quantity\n");
                printf("\n\t\t\t\t\t");
                scanf("%d",&quantity);


                if(quantity == 0){
                    printf("\nQuantity cannot be zero !!!\n");
                    slp();
                    goto chking_5;
                }
                total_quantity+=quantity;
                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("\n\t\t\t\t\t%s --- %d x %d = %d\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
            ag_5:
                printf("\n\n\t\t\t\t\tNeed anythin else from dessert ? (Y / N)\n");
                //printf("\t\t\t\t\tTo place order press 0\n");
                //printf("\n\t\t\t\t\tTo confirm and go back to menu list press 0\n");
                fflush(stdin);
                //che=getchar();
                printf("\t\t\t\t\t");
                scanf(" %c",&cheking);
                //scanf("%s",ch);
                if(cheking == 'Y' || cheking == 'y')
                        goto chking_5;
                else if(cheking == 'N' || cheking == 'n')
                        break;
                else{
                    printf("\t\t\t\t\tEnter Carefully!!!\n");
                    fflush(stdin);
                    //getchar();
                    goto ag_5;
                }
            }
            break;
        case 6 :
            while(1){
        chking_6:
                system("cls");
                printf("Enter 0 to go back\n\n\n");
                //gotoxy(40,6);
                print_beverage_food();

                printf("\t\t\tEnter item no- ");
                scanf("%d",&selected_item);
                printf("\n");

                if(selected_item==0){
                        system("cls"); //gotoxy(40,6);
                        printf("\t\t\t\t\tGoing back to menu!\n");
                        flag = 1;
                        slp();
                        break;
                    }
                else if(input_check(selected_item,line_of_beverage_food)){
                        printf("\t\t\t\t\tWrong Input\n");
                        //getchar();
                        slp();
                        goto chking_6;
                    }

                order_info_global[i].itm_no=beverage_food_list[selected_item-1].food_chFoodStruct->code;
                strcpy(order_info_global[i].item_name,beverage_food_list[selected_item-1].food_chFoodStruct->name);
                system("cls"); //gotoxy(40,6);
                printf("\n\n\t\t\t\t\tselected item -\t%s\n\n",beverage_food_list[selected_item-1].food_chFoodStruct->name);
                printf("\n\t\t\t\t\tSelect size\n\n");
                //printf("\n\t\t\t\t\t\n");
                printf("\t\t\t\t\t1.Medium - %d\n", beverage_food_list[selected_item-1].food_chFoodStruct->m_size);
                printf("\t\t\t\t\t2.Large - %d\n", beverage_food_list[selected_item-1].food_chFoodStruct->l_size);
                printf("\n\t\t\t\t\t");
                scanf("%d",&size_price);
                printf("\n\t\t\t\t\t");

                if(size_price==1){
                    order_info_global[i].price=beverage_food_list[selected_item-1].food_chFoodStruct->m_size;
                    strcpy(order_info_global[i].siz,"Medium");
                    //printf("\t\t\t\t\tMedium size selected\n");
                }
                else{
                    order_info_global[i].price=beverage_food_list[selected_item-1].food_chFoodStruct->l_size;
                    strcpy(order_info_global[i].siz,"Large");
                    //printf("\t\t\t\t\tLarge size selected\n");
                }
                printf("\n\t\t\t\t\tEnter Quantity\n");
                printf("\n\t\t\t\t\t");
                scanf("%d",&quantity);
                if(quantity == 0){
                    printf("\nQuantity cannot be zero !!!\n");
                    slp();
                    goto chking_6;
                }
                total_quantity+=quantity;
                order_info_global[i].quantity=quantity;
                total_price+=(order_info_global[i].price*quantity);
                printf("\n\t\t\t\t\t%s --- %d x %d = %d\n",order_info_global[i].item_name, order_info_global[i].price, order_info_global[i].quantity, order_info_global[i].quantity*order_info_global[i].price);
                i++;
                order_serial=i;
            ag_6:
                printf("\n\n\t\t\t\t\tNeed anythin else from beverage ? (Y / N)\n");
                //printf("\n\t\t\t\t\tTo confirm and go back to menu list press 0\n");
                //printf("\t\t\t\t\tTo place order press 0\n");
                fflush(stdin);
                //che=getchar();
                printf("\t\t\t\t\t");
                scanf(" %c",&cheking);
                //scanf("%s",ch);
                //if(cheking != 'Y' || cheking != 'y')
                if(cheking == 'Y' || cheking == 'y')
                        goto chking_6;
                else if(cheking == 'N' || cheking == 'n')
                        break;
                else{
                    printf("\t\t\t\t\tEnter Carefully!!!\n");
                    fflush(stdin);
                    //getchar();
                    goto ag_6;
                }
            }
            break;
        default:
            system("cls"); //gotoxy(40,6);
            printf("\t\t\t\t\tWrong Input\n");
            break;
    }
}


void orderList(){
    int total_price=0;
    int tem_serial;
    float vat=0;
    FILE *store_order;
    FILE *order_serial_no;
    FILE *ordr_state;
    order_serial_no=fopen("serial.txt","a");

    serial_no_fromFile();

    system("cls"); //gotoxy(40,6);
    show_time();

    printf("\n\n\t\t\t\t\t\t");
    for(int i=0; i<30; ++i){
        printf("\xdc");
    }
    printf("\n\n");
    printf("\t\t\t\t\t\t\xdc       BaBu kheyecho?       \xdc\n\n");
    printf("\t\t\t\t\t\t");
    for(int i=0; i<30; ++i){
        printf("\xdc");
    }
    printf("\n\t\t\t\t\t\t   RUPNOGOR, Mirpur2 Dhaka\n");
    printf("\n\t\t\t\t\t\t   ""WE BELIEVE IN QUALITY""\n");

    printf("\n\nToken %d",serial_no+1);
    //printf("\t\t\t\t%s\n",ti_me);
    printf("\n\n");
    printf("\t\t\t\t\tSelected Item(s)\n\n");

    line[0]='\0';
    strcat(line,"Token - ");
    tem_serial=serial_no+1;
    itoa(tem_serial,temp,10);
    strcat(line,temp);
    strcat(line,"*");

    strcat(line,"Total Quantity - ");
    itoa(total_quantity,temp,10);
    strcat(line,temp);
    strcat(line,"*");

    for(int j=0;j<order_serial;j++){

        printf("\t\t\t\t\tItem No - %d\n",j+1);
        printf("\n\t\t\t\t\t%s (%s) - %d x %d = %d\n",order_info_global[j].item_name, order_info_global[j].siz, order_info_global[j].quantity,order_info_global[j].price, order_info_global[j].price*order_info_global[j].quantity);
        //printf("\t\t\t\t\tPrice = %d\n",order_info_global[j].price);
        printf("\n\n");
        order_info_global[j].t_price=order_info_global[j].price*order_info_global[j].quantity;

        total_quantity+=order_info_global[j].quantity;
        total_price+= (order_info_global[j].price*order_info_global[j].quantity);
        strcat(line,order_info_global[j].item_name);
        strcat(line," ");

        strcat(line," ( ");
        strcat(line,order_info_global[j].siz);
        strcat(line," ) ");
        strcat(line," ");

        itoa(order_info_global[j].quantity,temp,10);
        strcat(line,temp);

        strcat(line," x ");

        itoa(order_info_global[j].price,temp,10);
        strcat(line,temp);

        strcat(line," = ");

        itoa(order_info_global[j].t_price,temp,10);
        strcat(line,temp);
        strcat(line,"*");

    }
    printf("\n\t\t\t\t\t___________________________________________\n");
    printf("\n\t\t\t\t\t\t\tSub Total = %d\n",total_price);
    vat=(total_price*(7.5/100));
    vat=ceil(vat);
    printf("\t\t\t\t\t\t\tVat = %.1f ( 7.5%% )\n",vat);
    total_price=total_price+vat;
    printf("\n\t\t\t\t\t\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc");
    printf("\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\n");
    printf("\n\t\t\t\t\t\t\tGross Total = %d\n",total_price);

    //printf("\n\n\n%s\n",line);
    OrderState();
    state+=total_price;
    ordr_state= fopen("OrderState.txt","w");
    fprintf(ordr_state,"%llu", state);
    fclose(ordr_state);

    strcat(line,"*Total = ");
    itoa(total_price,temp,10);
    strcat(line,temp);
    strcat(line," (with vat)_");
    store_order=fopen("Order_List.txt","a");

    fprintf(store_order,"%s\n",line);

    price_from_order=total_price;

    order_serial_no=fopen("serial.txt","a");
    fprintf(order_serial_no,"%d\n",serial_no+1);

    fclose(order_serial_no);
    fclose(store_order);

    //getchar();
}
