#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#define Error puts("\n=================\n|     Error!    |\n=================")

//Functions made by Zulnoor Siddiqui(20k-0183)
//Headers of various functions
void Title_heading();
void company_heading();
void customer_panel_heading();
void Admin_panel_heading();
void Customer_Analytics_panel_heading();
void print_current_bill(int);
//Function for the purchase of items
void Item_Purchase();
//Sturcture of items listed in database
struct item_info
{
	int id;
	char item_name[100];
	char company_name[100];
	int price;
} item;
int addition = 1;

//Functions made by Mohammad Wamiq Akram (20k-1090)
FILE *fp_cus;
struct Customer_info
{
	char customer_name[150];
	int customer_id;
	int cusotmer_age;
	char customer_gender;
	char customer_area[50];
} customer;
void customers_panel();
void Add_new_cusotmer();
void Delete_cusotmer();
void View_existing_customers();
void Customer_Data_breakdown_age();
void Customer_data_breakdown_gender();

//Functions made by Bilal Ahmed Khan (20k-0183)
//Function for admin previliges
void Admin_option_panel();
FILE *fp;
//Password verifier
int Password_Verification();

//Admin_option_panel functions
void Add_new_item();
void Modify_item();
void Delete_item();
void Search_for_item();
void View_stock();

main()
{
	int choice;
	int acc;
	Title_heading();
	company_heading();
	fflush(stdin);
	puts("\tChoose any of the given option");
	fflush(stdin);
	puts("	1. Buy Products");
	fflush(stdin);
	puts("	2. Login as Administrator");
	fflush(stdin);
	puts("\t3. Customer Analytics");
	fflush(stdin);
	puts("	4. Exit");
	fflush(stdin);
	puts("Choose an option");
	fflush(stdin);
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
	case 1:
	{
		Item_Purchase();
		break;
	}
	case 2:
	{
		acc = Password_Verification();
		if (acc == 1)
			Admin_option_panel();
		else
		{
			getch();
			main();
		}
	}

	case 3:
	{
		customers_panel();
	}
	case 4:
	{
		company_heading();
		fflush(stdin);
		puts("\n\n\n\n\n\n\t\t\t\tTHANK YOU");
		fflush(stdin);
		puts("\n\t\t\tHope you like our project :)\n");
		fflush(stdin);
		fclose(fp);
		getch();
		exit(0);
	}
	}
}
void Admin_option_panel()
{
	int choice1;
	fp = fopen("itemsdatabase.txt", "ab+");
	fseek(fp, 0, 0);
	company_heading();
	Admin_panel_heading();
	printf("\n\n\t1. Add new items\n");
	printf("\t2. View available items\n");
	printf("\t3. Modify existing items\n");
	printf("\t4. Search for an exsiting item\n");
	printf("\t5. Delete put of stock items\n");
	printf("\t6. Return to main menu\n");
	printf("\tEnter a choice: \n");
	scanf("%d", &choice1);
	switch (choice1)
	{
	case 1:
		Add_new_item();
	case 2:
		View_stock();
	case 3:
		Modify_item();
	case 4:
		Search_for_item();
	case 5:
		Delete_item();
	case 6:
		main();
	}
}

void Add_new_item()
{
	company_heading();
	int id;
	Admin_panel_heading();
	printf("\n\t\t     ***** Current Selection: Addition of new stock *****");
	fflush(stdin);
	printf("\nEnter the ID of the product\n");
	scanf("%d", &id);
	while (fread(&item, sizeof(item), 1, fp) == 1)
	{
		if (item.id == id)
		{
			Error;
			printf("\nSorry. This item already exists.\n");
			printf("\nPress any key to start adding another item...\n");
			getch();
			Add_new_item();
		}
	}
	item.id = id;
	printf("Enter the name of the product:\n");
	fflush(stdin);
	gets(item.item_name);
	printf("Enter the manufacturer of the product:\n");
	fflush(stdin);
	gets(item.company_name);
	printf("Enter the price of the product:\n");
	scanf("%d", &item.price);
	fwrite(&item, sizeof(item), 1, fp);
	printf("\nPress any key to return to previous menu...\n");
	getch();
	fclose(fp);
	Admin_option_panel();
}

void View_stock()
{
	company_heading();
	Admin_panel_heading();
	printf("\n\t\t     ***** Current Selection: Viewing available stock *****\n");
	rewind(fp);
	while (fread(&item, sizeof(item), 1, fp) == 1)
	{
		printf("\n=================================================================================================================\n");
		printf("\nItem Id: ");
		printf("%d", item.id);
		printf("\nItem Name: ");
		fflush(stdin);
		puts(item.item_name);
		printf("Item manufacturer: ");
		fflush(stdin);
		puts(item.company_name);
		printf("Item Price: ");
		printf("%d\n", item.price);
	}
	printf("\nPress any key to continue to previous menu...");
	getch();
	system("cls");
	fclose(fp);
	Admin_option_panel();
}

void Modify_item()
{
	fflush(stdin);
	company_heading();
	Admin_panel_heading();
	FILE *temp_ptr;
	printf("\n\t\t     ***** Current selection: Modification of In-stock items *****");
	int id;
	int a = 0;
	char state = 'y';
	while (state == 'y' || state == 'Y')
	{
		fflush(stdin);
		printf("\nEnter the ID of the item you want to modify");
		scanf("%d", &id);
		temp_ptr = fopen("temporary.txt", "wb");
		rewind(fp);
		int flag = 0;
		while (fread(&item, sizeof(item), 1, fp) == 1)
		{
			if (item.id == id)
			{
				fflush(stdin);
				printf("Item: %s exists in database!\n", item.item_name);
				flag = 10;
				printf("New item name: ");
				fflush(stdin);
				gets(item.item_name);
				printf("New manufacturer name: ");
				fflush(stdin);
				gets(item.company_name);
				printf("New Price: ");
				scanf("%d", &item.price);
				fwrite(&item, sizeof(item), 1, temp_ptr);
			}
			else
			{
				fwrite(&item, sizeof(item), 1, temp_ptr);
			}
		}
		if (flag != 10)
		{
			Error;
			fflush(stdin);
			puts("No such record exists!");
		}
		fclose(fp);
		fclose(temp_ptr);
		remove("itemsdatabase.txt");
		rename("temporary.txt", "itemsdatabase.txt");
		fp = fopen("itemsdatabase.txt", "ab+");
		printf("\nModify another Item? (Y/N)? ");
		fflush(stdin);
		state = getche();
	}
	fclose(fp);
	Admin_option_panel();
}

void Search_for_item()
{
	int a = 0;
	int id;
	company_heading();
	Admin_panel_heading();
	fp = fopen("itemsdatabase.txt", "ab+");
	fflush(stdin);
	printf("\n\t\t     ***** Current Selection: Search in available stock *****");
	fflush(stdin);
	puts("\nEnter the ID of the product you want to search");
	scanf("%d", &id);
	while (fread(&item, sizeof(item), 1, fp) == 1)
	{
	
		if (item.id == id)
		{
			fflush(stdin);
			puts("\n-------------------------------------------------\n\t\t    PRODUCT FOUND!:   \n-------------------------------------------------\n");
			printf("\nItem ID: ");
			printf("%d", item.id);
			printf("\nItem Name: ");
			fflush(stdin);
			puts(item.item_name);
			printf("Item Manufacturer: ");
			fflush(stdin);
			puts(item.company_name);
			printf("Item Price: ");
			printf("%d", item.price);
			a = 1;
		}
	}

	if (a != 1)
	{
		printf("\nItem not found!\nPlease Enter a valid product ID", id);
	}
	printf("\nPress any key to continue to previous menu...");
	getch();
	system("cls");
	fclose(fp);
	Admin_option_panel();
}

void Delete_item()
{
	fflush(stdin);
	company_heading();
	Admin_panel_heading();
	FILE *temp_ptr;
	printf("\n\t\t     ***** Current selection: Deletion of OUT OF STOCK items *****");
	int id;
	int a = 0;
	char state = 'y';
	while (state == 'y' || state == 'Y')
	{
		fflush(stdin);
		printf("\nEnter the ID of the product you want to delete");
		scanf("%d", &id);
		temp_ptr = fopen("tempdel.txt", "wb");
		rewind(fp);
		int flag = 0;
		while (fread(&item, sizeof(item), 1, fp) == 1)
		{

			if (item.id != id)
			{
				fwrite(&item, sizeof(item), 1, temp_ptr);
			}
			else if (item.id == id)
			{
				flag = 10;
				printf("\nItem Deleted successfully!!!\n");
			}
		}
		if (flag != 10)
		{
			Error;
			fflush(stdin);
			puts("Product does not exist!");
		}
		fclose(fp);
		fclose(temp_ptr);
		remove("itemsdatabase.txt");
		rename("tempdel.txt", "itemsdatabase.txt");
		fp = fopen("itemsdatabase.txt", "ab+");
		printf("\nDelete more items?(Y/N)? ");
		fflush(stdin);
		state = getch();
	}
	fclose(fp);
	Admin_option_panel();
}

int Password_Verification()
{
	fflush(stdin);
	char admin[30];
	static char password[5];
	int a;
	printf("\n\t\t\t\t\t\tEnter Admin username (Username is admin): ");
	fflush(stdin);
	gets(admin);
	if (strcmp(admin, "admin") == 0)
	{
		fflush(stdin);
		puts("\n\t\t\t\t\t\tAdmin identity verified!");
		printf("\n\t\t\t\t\t\tEnter 5-digit database password(Password is 12345):");
		fflush(stdin);
		fflush(stdin);
		gets(password);
		if (strcmp(password, "12345") == 0)
		{
			fflush(stdin);
			puts("\n\t\t\t\t\t\tACCESS GRANTED");
			printf("\n\t\t\t\t\t\tPress any key to continue");
			getch();
			a = 1;
		}
		else
		{
			fflush(stdin);
			puts("\n\t\t\t\t\t\tACCESS DENIED!");
			a = 0;
		}
	}
	else
	{
		company_heading();
		fflush(stdin);
		puts("\n\t\t\t\t\t\tUNKNOWN IDENTITY");
		a = 0;
	}
	return a;
}

void Item_Purchase()
{
	int number_of_items = 0, total_sum = 0, k = 0,choice=0;
	company_heading();
	int Item_wanted = 0, i = 0, j = 0;
	customer_panel_heading();
	fp = fopen("itemsdatabase.txt", "ab+");
	fflush(stdin);
	puts("\nFollowing is the list of available items in stock");
	rewind(fp);
	while (fread(&item, sizeof(item), 1, fp) == 1)
	{
		i++;
		printf("\n=================================================================================================================\n");
		printf("\nItem ID: ");
		printf("%d\n", item.id);
		printf("Item Name: ");
		fflush(stdin);
		puts(item.item_name);
		printf("Manufacturer name: ");
		fflush(stdin);
		puts(item.company_name);
		printf("Price: ");
		printf("%d", item.price);
		printf("\n");
	}
	fflush(stdin);
	puts("\nPress a key to move on to the next window and select products");
	getch();
	system("cls");
	printf("Enter the number of products you want to buy\n");
	scanf("%d", &number_of_items);
	struct item_info purchased_items[number_of_items];
	fflush(stdin);
	for (k = 0; k < number_of_items; k++)
	{
		puts("\nEnter the ID of the item you want to buy");
		fflush(stdin);
		scanf("%d", &Item_wanted);
		rewind(fp);
		while (fread(&item, sizeof(item), 1, fp) == 1)
		{ 
			j++;
			if (Item_wanted == item.id)
			{
				fflush(stdin);
				printf("\n=================================================================================================================\n");
				printf("\n\t\t\t\t\t\tYOUR SELECTED ITEMS\n");
				printf("\n=================================================================================================================\n");
				printf("\nItem ID: ");
				printf("%d\n", item.id);
				purchased_items[k].id=item.id;
				printf("Item Name: ");
				fflush(stdin);
				puts(item.item_name);
				strcpy(purchased_items[k].item_name,item.item_name);
				printf("Item Manufactuer: ");
				fflush(stdin);
				puts(item.company_name);
				strcpy(purchased_items[k].company_name,item.company_name);
				printf("Item Price: ");
				printf("%d", item.price);
				purchased_items[k].price=item.price;
				printf("\n");
				total_sum+=item.price;
			}
		}
	}
	system("cls");
	company_heading();
	customer_panel_heading();
	printf("\n=================================================================================================================\n");
	printf("\n\t\t\t\t\t\tYOUR SELECTED ITEMS\n");
	printf("\n=================================================================================================================\n");
	printf("Your total bill is:");
	for(k=0;k<number_of_items;k++)
	{
		printf("\nItem ID: ");
		printf("%d\n", purchased_items[k].id);
		printf("Item Name: ");
		fflush(stdin);
		puts(purchased_items[k].item_name);
		printf("Item Manufactuer: ");
		fflush(stdin);
		puts(purchased_items[k].company_name);
		printf("Item Price: ");
		printf("%d", purchased_items[k].price);
		printf("\n");
	}
	printf("\n\t\t\t\t\t\tYOUR TOTAL BILL: %d\n", total_sum);
	printf("Enter 1 to continue making bills or 0 to exit\n");
	scanf("%d", &choice);
	if(choice==1) Item_Purchase();
	else main();
}

void customers_panel()
{
	company_heading();
	int choice;
	Customer_Analytics_panel_heading();
	printf("\n\n\t\tChoose an option from the list.\n\n\t\t01)Add new customer Data.\n\n\t\t02)View existing Customers\n\n\t\t03)Get customer data breakdown based on age.\n\n\t\t04)Customer data based on gender demographics.\n\n\t\t05)Delete a customer record\n\n\t\t06)Return to main menu \n\n\t\tPress any other key if you want to exit the program now\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		Add_new_cusotmer();

	case 2:
		View_existing_customers();

	case 3:
		Customer_Data_breakdown_age();

	case 4:
		Customer_data_breakdown_gender();
	case 5:
		Delete_cusotmer();

	case 6:
		main();
	}
}

void Add_new_cusotmer()
{
	company_heading();
	int id;
	Customer_Analytics_panel_heading();
	printf("\n\t\t     ***** Current Selection: Adding new customer data *****");
	fp_cus = fopen("customer_database.txt", "ab+");
	fflush(stdin);
	printf("\n\n\nEnter customer ID: \n");
	scanf("%d", &id);
	while (fread(&customer, sizeof(customer), 1, fp_cus) == 1)
	{
		if (customer.customer_id == id)
		{
			printf("This ID is alrady occupied by an existing customer please select a valid ID\n");
			printf("Press any key to continue...\n");
			getch();
			Add_new_cusotmer();
		}
	}
	customer.customer_id = id;
	printf("Enter the name of the customer: \n");
	fflush(stdin);
	gets(customer.customer_name);
	printf("Enter the age of the customer: \n");
	fflush(stdin);
	scanf("%d", &customer.cusotmer_age);
	printf("Enter the gender of the customer (M for male and F for female): \n");
	fflush(stdin);
	scanf("%c", &customer.customer_gender);
	printf("Enter the area name of the customer: \n");
	fflush(stdin);
	gets(customer.customer_area);
	fwrite(&customer, sizeof(customer), 1, fp_cus);
	printf("Press any key to return to the previous menu\n");
	getch();
	fclose(fp_cus);
	customers_panel();
}

void Delete_cusotmer()
{
	fflush(stdin);
	company_heading();
	int id;
	Customer_Analytics_panel_heading();
	fp = fopen("customer_database.txt", "ab+");
	FILE *temp_cus_ptr;
	printf("\n\t\t     ***** Current selection: Deletion of Customer records *****");
	int a = 0;
	char state = 'y';
	while (state == 'y' || state == 'Y')
	{
		fflush(stdin);
		printf("\nEnter the Customer ID you want to delete: ");
		scanf("%d", &id);
		temp_cus_ptr = fopen("temp_customerdel.txt", "wb+");
		rewind(fp);
		int flag = 0;
		while (fread(&customer, sizeof(customer), 1, fp) == 1)
		{

			if (customer.customer_id != id)
			{
				fwrite(&customer, sizeof(customer), 1, temp_cus_ptr);
			}
			else if (customer.customer_id == id)
			{
				flag = 10;
				printf("\nRecord Deleted successfully!!!\n");
			}
		}
		if (flag != 10)
		{
			Error;
			fflush(stdin);
			puts("Customer does not exist!");
		}
		fclose(fp);
		fclose(temp_cus_ptr);
		remove("customer_database.txt");
		rename("temp_customerdel.txt", "customer_database.txt");
		fp = fopen("customer_database.txt", "ab+");
		printf("\nDelete more items?(Y/N)? ");
		fflush(stdin);
		state = getch();
	}
	fclose(fp);
	customers_panel();
}

void View_existing_customers()
{
	company_heading();
	Customer_Analytics_panel_heading();
	printf("\n\t\t     ***** Current Selection: Viewing Existing customer data *****");
	printf("\nFollowing is the list of existing customers:\n");
	fp_cus = fopen("customer_database.txt", "r");
	while (fread(&customer, sizeof(customer), 1, fp_cus) == 1)
	{
		printf("\n=================================================================================================================\n");
		printf("\nCustomer ID: ");
		printf("%d", customer.customer_id);
		printf("\nCustomer Name: ");
		fflush(stdin);
		puts(customer.customer_name);
		printf("Customer Gender: ");
		fflush(stdin);
		printf("%c", customer.customer_gender);
		printf("\nCustomer age: ");
		fflush(stdin);
		printf("%d", customer.cusotmer_age);
		printf("\nCustomer area name: ");
		fflush(stdin);
		puts(customer.customer_area);
	}
	printf("\nPress any key to return to the customers_panel menu\n");
	getch();
	fclose(fp_cus);
	customers_panel();
}

void Customer_Data_breakdown_age()
{
	int choice;
	company_heading();
	Customer_Analytics_panel_heading();
	printf("\t\tChoose an option from the list.\n\n\t\t01)Customers whose age is less than 18\n\n\t\t02)Customers whose age is between 18 and 25.\n\n\t\t03)Customers whose age is between 25 and 35.\n\n\t\t04)Customers whose age is between 35 and 45\n\n\t\t05)Customers whose age is greater than 45\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	{
		printf("\n\t\t     ***** Current Selection:  Customers with age less than 18 *****");
		printf("\nFollowing  is the list of customers whose age is less than 18\n");
		fp_cus = fopen("customer_database.txt", "r");
		while (fread(&customer, sizeof(customer), 1, fp_cus) == 1)
		{
			if (customer.cusotmer_age < 18)
			{
				printf("\n=================================================================================================================\n");
				printf("\nCustomer ID: ");
				printf("%d", customer.customer_id);
				printf("\nCustomer Name: ");
				fflush(stdin);
				puts(customer.customer_name);
				printf("Customer Gender: ");
				fflush(stdin);
				printf("%c", customer.customer_gender);
				printf("\nCustomer age: ");
				fflush(stdin);
				printf("%d", customer.cusotmer_age);
				printf("\nCustomer area name: ");
				fflush(stdin);
				puts(customer.customer_area);
			}
		}
		fclose(fp_cus);
		printf("\nPress any key to continue...\n");
		getch();
		customers_panel();
	}

	case 2:
	{
		printf("\n\t\t     ***** Current Selection:  Customers with ages between 18 and 25 *****");
		printf("\nFollowing  is the list of customers with ages between 18 and 25\n");
		fp_cus = fopen("customer_database.txt", "r");
		while (fread(&customer, sizeof(customer), 1, fp_cus) == 1)
		{
			if (customer.cusotmer_age >= 18 && customer.cusotmer_age <= 25)
			{
				printf("\n=================================================================================================================\n");
				printf("\nCustomer ID: ");
				printf("%d", customer.customer_id);
				printf("\nCustomer Name: ");
				fflush(stdin);
				puts(customer.customer_name);
				printf("Customer Gender: ");
				fflush(stdin);
				printf("%c", customer.customer_gender);
				printf("\nCustomer age: ");
				fflush(stdin);
				printf("%d", customer.cusotmer_age);
				printf("\nCustomer area name: ");
				fflush(stdin);
				puts(customer.customer_area);
			}
		}
		fclose(fp_cus);
		printf("\nPress any key to continue...\n");
		getch();
		customers_panel();
	}

	case 3:
	{
		printf("\n\t\t     ***** Current Selection:  Customers with ages between 25 and 35 *****");
		printf("\nFollowing  is the list of customers with ages between 25 and 35\n");
		fp_cus = fopen("customer_database.txt", "r");
		while (fread(&customer, sizeof(customer), 1, fp_cus) == 1)
		{
			if (customer.cusotmer_age >= 25 && customer.cusotmer_age <= 35)
			{
				printf("\n=================================================================================================================\n");
				printf("\nCustomer ID: ");
				printf("%d", customer.customer_id);
				printf("\nCustomer Name: ");
				fflush(stdin);
				puts(customer.customer_name);
				printf("Customer Gender: ");
				fflush(stdin);
				printf("%c", customer.customer_gender);
				printf("\nCustomer age: ");
				fflush(stdin);
				printf("%d", customer.cusotmer_age);
				printf("\nCustomer area name: ");
				fflush(stdin);
				puts(customer.customer_area);
			}
		}
		fclose(fp_cus);
		printf("\nPress any key to continue...\n");
		getch();
		customers_panel();
	}

	case 4:
	{
		printf("\n\t\t     ***** Current Selection:  Customers with ages between 35 and 45 *****");
		printf("\nFollowing  is the list of customers with ages between 35 and 45\n");
		fp_cus = fopen("customer_database.txt", "r");
		while (fread(&customer, sizeof(customer), 1, fp_cus) == 1)
		{
			if (customer.cusotmer_age >= 35 && customer.cusotmer_age <= 45)
			{
				printf("\n=================================================================================================================\n");
				printf("\nCustomer ID: ");
				printf("%d", customer.customer_id);
				printf("\nCustomer Name: ");
				fflush(stdin);
				puts(customer.customer_name);
				printf("Customer Gender: ");
				fflush(stdin);
				printf("%c", customer.customer_gender);
				printf("\nCustomer age: ");
				fflush(stdin);
				printf("%d", customer.cusotmer_age);
				printf("\nCustomer area name: ");
				fflush(stdin);
				puts(customer.customer_area);
			}
		}
		fclose(fp_cus);
		printf("\nPress any key to continue...\n");
		getch();
		customers_panel();
	}

	case 5:
	{
		printf("\n\t\t     ***** Current Selection:  Customers with ages greater than 45*****");
		printf("\nFollowing  is the list of customers with ages greater than 45\n");
		fp_cus = fopen("customer_database.txt", "r");
		while (fread(&customer, sizeof(customer), 1, fp_cus) == 1)
		{
			if (customer.cusotmer_age > 45)
			{
				printf("\n=================================================================================================================\n");
				printf("\nCustomer ID: ");
				printf("%d", customer.customer_id);
				printf("\nCustomer Name: ");
				fflush(stdin);
				puts(customer.customer_name);
				printf("Customer Gender: ");
				fflush(stdin);
				printf("%c", customer.customer_gender);
				printf("\nCustomer age: ");
				fflush(stdin);
				printf("%d", customer.cusotmer_age);
				printf("\nCustomer area name: ");
				fflush(stdin);
				puts(customer.customer_area);
			}
		}
		fclose(fp_cus);
		printf("\nPress any key to continue...\n");
		getch();
		customers_panel();
	}
	}
}

void Customer_data_breakdown_gender()
{
	company_heading();
	Customer_Analytics_panel_heading();
	char gender_choice;
	printf("Do you want to see Male customers or Female customers?(Enter M for male or F for female)\n");
	fflush(stdin);
	scanf("%c", &gender_choice);
	printf("\n\t\t     ***** Current Selection:  All %c Customers *****", gender_choice);
	fp_cus = fopen("customer_database.txt", "r");
	while (fread(&customer, sizeof(customer), 1, fp_cus) == 1)
	{
		if (customer.customer_gender == gender_choice)
		{
			printf("\n=================================================================================================================\n");
			printf("\nCustomer ID: ");
			printf("%d", customer.customer_id);
			printf("\nCustomer Name: ");
			fflush(stdin);
			puts(customer.customer_name);
			printf("Customer Gender: ");
			fflush(stdin);
			printf("%c", customer.customer_gender);
			printf("\nCustomer age: ");
			fflush(stdin);
			printf("%d", customer.cusotmer_age);
			printf("\nCustomer area name: ");
			fflush(stdin);
			puts(customer.customer_area);
		}
	}
	fclose(fp_cus);
	printf("\nPress any key to continue...\n");
	getch();
	customers_panel();
}

void Title_heading()
{
	system("cls");
	printf("=============================================================================================================\n\n\n");
	printf("\nPROUDLY PRESENTED BY:\n\n01)Bilal Ahmed Khan (20k-0183)\n02)Mohammad Wamiq Akram (20k-1857)\n03)Zulnoor Siddiqui (20k-1090)\n");
	printf("\n\n\n=============================================================================================================");
	fflush(stdin);
	puts("\nPress any key to continue");
	getch();
}

void company_heading()
{
	system("cls");
	printf("\n=================================================================================================================\n");
	printf("\n\t\t\t\t\t   Stationary Shop Managment Software\n");
	printf("\t\t\t\t Provider of best sationary items at most reasonable prices\n");
	printf("\n=================================================================================================================\n");
}

void print_current_bill(int bal)
{
	system("cls");
	printf("\n=================================================================================================================\n");
	printf("\n\t\t\t\t\t\tKhan Stationers\n");
	printf("\tProvider of best sationary items at most reasonable prices\n");
	printf("\n\t\t\t\t\t\tCurrent expense = %d", bal);
	printf("\n=================================================================================================================\n");
}

void Admin_panel_heading()
{
	printf("\t");
	printf("\n=================================================================================================================\n");
	printf("\n\t\t\t\t\t\tADMIN PANEL\n");
	printf("\t");
	printf("\n=================================================================================================================\n");
}

void Customer_Analytics_panel_heading()
{
	printf("\t");
	printf("\n=================================================================================================================\n");
	printf("\n\t\t\t\t\t\tCustomer Analytics\n");
	printf("\t");
	printf("\n=================================================================================================================\n");
}

void customer_panel_heading()
{
	printf("\n=================================================================================================================\n");
	printf("\n\t\t\t\t\t\tCUSTOMER PURCHASE\n");
	printf("\n=================================================================================================================\n");
}
