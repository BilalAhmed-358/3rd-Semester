#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <conio.h>
using namespace std;

bool done = false;
class Node
{
	friend class AVL;

	int height;
	Node *left;
	Node *right;

public:
	Node() : height(0), left(NULL), right(NULL)
	{
		// Member initialization list for improving performance
	}

private:
	string star_rating, helpful_votes, total_votes, review, product_title, category, vine, verified_purchase, review_headline, detailed_review, customerID, marketplace, review_id, product_ID, product_parent;

public:
	Node(string review, Node *ptr = NULL, Node *ptr2 = NULL) : review(review), height(0), left(ptr), right(ptr2)
	{
		// Member initialization list for improving performance
	}
	Node(string product_ID, string review_id, string customerID, string marketplace, string product_parent, string product_title, string product_category, string star_rating, string helpful_votes, string total_votes, string vine, string verified_purchase, string review_headline, string detailed_review, Node *ptr = NULL, Node *ptr2 = NULL)

		: product_ID(product_ID), review_id(review_id), customerID(customerID), marketplace(marketplace), product_parent(product_parent), product_title(product_title), category(product_category), star_rating(star_rating), helpful_votes(helpful_votes), total_votes(total_votes), vine(vine), verified_purchase(verified_purchase), review_headline(review_headline), detailed_review(detailed_review), height(0), left(ptr), right(ptr2)
	{
		// Member initialization list for improving performance
	}
};
class AVL
{
public:
	Node *root;
	Node *pos, *neg;

	string *words;

	int spaces;

	int positive;

	int negative;

	int notflag;

	int noneflag;

	int noflag;

	int dontflag;

	int didntflag;

	int wontflag;

	int stat;

	int len;

	int flag;

	double polarity;

	AVL() : root(NULL), pos(NULL), neg(NULL), spaces(0), positive(0), negative(0), noflag(0), noneflag(0), notflag(0), dontflag(0), didntflag(0), wontflag(0), stat(0), len(0), flag(0)
	{
		// Member initialization list for improving performance
	}

	void Menu()
	{

		cout << "\n===================================================== \n";
		cout << " \t\tMenu \t \n ";
		cout << "===================================================== \n";
		cout << " 1.Search a Product\n";
		cout << " 2.Find Regular Products\n";
		cout << " 3.Find Hot Selling Products\n";
		cout << " 4.Product Review Analysis\n";
		cout << " 5-Search a Product by Rating and Helpful votes" << endl;
		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int i;
			// cout << "Search a Product by : " << endl
			// 	 << "1-PRODUCT ID" << endl;
			// 	//  << "2-customer ID" << endl;
			// cin >> i;
			// if (i == 1)
			// {
			system("CLS");
			cout << "Enter the Product ID to be searched: ";
			cin.ignore();
			string id;
			getline(cin, id);
			// Searching Product by Product ID
			this->Search_by_ProductID(this->root, id);
			cout << endl
				 << "Press 0 to return to Menu or any key to exit : ";
			cin >> i;
			if (i == 0)
			{
				system("CLS");
				this->Menu();
			}
			else
			{
				exit(0);
			}
			// }
			// else if (i == 2)
			// {
			// 	system("CLS");
			// 	cout << "Enter the customer ID to be searched: ";
			// 	cin.ignore();
			// 	string id;
			// 	getline(cin, id);
			// 	// searching customer by customer ID
			// 	this->Search_by_customerID(this->root, id);
			// 	cout << endl
			// 		 << "Press 0 to return to Menu or any key to exit:";
			// 	cin >> i;
			// 	if (i == 0)
			// 	{
			// 		system("CLS");
			// 		this->Menu();
			// 	}
			// 	else
			// 	{
			// 		exit(0);
			// 	}
			// }
			// else
			// {
			// 	cout << "INVALID CHOICE " << endl;
			// 	cout << "Press any Key to return to Main Menu :";
			// 	getch();
			// 	system("cls");
			// 	Menu();
			// }
			break;
		}
		case 2:
		{
			system("CLS");
			// Function to find the regular selling Products
			this->Regular_Products_Tittle(root);
			int i;
			cout << "Enter 0 to return to Menu or any key to exit : ";
			cin >> i;
			if (i == 0)
			{
				system("CLS");
				this->Menu();
			}
			else
			{
				exit(0);
			}
			break;
		}
		case 3:
		{
			system("CLS");
			// Function to find the top selling products //
			this->Best_Product_Tittle(this->root);

			int i;
			cout << "Enter 1 to return to Menu or any key to Exit:";
			cin >> i;
			if (i == 1)
			{
				system("CLS");
				this->Menu();
			}
			else
			{
				exit(0);
			}
			break;
		}

		case 4:
		{
			system("CLS");
			// review analysis

			this->find_result();

			int i;
			cout << "Enter 0 to return to Menu: or any key to exit : ";
			cin >> i;
			if (i == 0)
			{
				system("CLS");
				this->Menu();
			}
			else
			{
				exit(0);
			}
			break;
		}
		case 5:
		{
			string rating, helpful_notes;
			system("CLS");
			cout << "Enter Rating : " << endl;
			cin >> rating;
			cout << "Enter Heplful Notes" << endl;
			cin >> helpful_notes;
			this->Customize(root, rating, helpful_notes);

			int i;
			cout << "Enter 0 to return to Menu:";
			cin >> i;
			if (i == 0)
			{
				system("CLS");
				this->Menu();
			}
			else
			{
				exit(0);
			}
		}

		default:
		{
			cout << "INVALID CHOICE " << endl;
			cout << "Press any Key to return to Main Menu :";
			getch();
			system("cls");
			Menu();
		}
		}
	}

	int Height(Node *temp)
	{
		int hl, hr;

		hl = temp && temp->left ? temp->left->height : 0;
		hr = temp && temp->right ? temp->right->height : 0;

		return hl > hr ? hl + 1 : hr + 1;
	}

	int Balancing_Factor(Node *temp)
	{
		int hl, hr;

		hl = temp && temp->left ? temp->left->height : 0;
		hr = temp && temp->right ? temp->right->height : 0;

		return hl - hr;
	}

	Node *LLRotation(Node *temp)
	{
		Node *pl = temp->left;
		Node *plr = pl->right;

		pl->right = temp;
		temp->left = plr;
		temp->height = Height(temp);
		pl->height = Height(pl);

		if (root == temp)
		{
			root = pl;
		}
		return pl;
	}

	Node *RRRotation(Node *temp)
	{
		Node *pr = temp->right;
		Node *prl = pr->left;

		pr->left = temp;
		temp->right = prl;
		temp->height = Height(temp);
		pr->height = Height(pr);

		if (root == temp)
		{
			root = pr;
		}
		return pr;
	}

	Node *LRRotation(Node *temp)
	{
		Node *pl = temp->left;
		Node *plr = pl->right;

		pl->right = plr->left;
		temp->left = plr->right;
		plr->left = pl;
		plr->right = temp;

		pl->height = Height(pl);
		temp->height = Height(temp);
		plr->height = Height(plr);

		if (root == temp)
		{
			root = plr;
		}
		return plr;
	}

	Node *RLRotation(Node *temp)
	{
		Node *pr = temp->right;
		Node *prl = pr->left;

		pr->left = prl->right;
		temp->right = prl->left;
		prl->right = pr;
		prl->left = temp;

		pr->height = Height(pr);
		temp->height = Height(temp);
		prl->height = Height(prl);

		if (root == temp)
		{
			root = prl;
		}
		return prl;
	}

	Node *Insert(Node *temp, string product_ID, string review_id, string customerID, string marketplace, string product_parent, string product_title, string product_category, string star_rating, string helpful_votes, string total_votes, string vine, string verified_purchase, string review_headline, string detailed_review)
	{
		Node *t = NULL;

		if (temp == NULL)
		{

			t = new Node(product_ID, review_id, customerID, marketplace, product_parent, product_title, product_category, star_rating, helpful_votes, total_votes, vine, verified_purchase, review_headline, detailed_review);

			t->height = 1;
			t->left = t->right = NULL;
			return t;
		}

		if (product_ID < temp->product_ID)
		{
			temp->left = Insert(temp->left, product_ID, review_id, customerID, marketplace, product_parent, product_title, product_category, star_rating, helpful_votes, total_votes, vine, verified_purchase, review_headline, detailed_review);
		}

		else if (product_ID > temp->product_ID)
		{
			temp->right = Insert(temp->right, product_ID, review_id, customerID, marketplace, product_parent, product_title, product_category, star_rating, helpful_votes, total_votes, vine, verified_purchase, review_headline, detailed_review);
		}

		temp->height = Height(temp);

		if (Balancing_Factor(temp) == 2 && Balancing_Factor(temp->left) == 1)
		{
			return LLRotation(temp);
		}

		else if (Balancing_Factor(temp) == 2 && Balancing_Factor(temp->left) == -1)
		{
			return LRRotation(temp);
		}

		else if (Balancing_Factor(temp) == -2 && Balancing_Factor(temp->right) == -1)
		{
			return RRRotation(temp);
		}

		else if (Balancing_Factor(temp) == -2 && Balancing_Factor(temp->right) == 1)
		{
			return RLRotation(temp);
		}

		return temp;
	}

	Node *Insert2(Node *temp, string review)
	{
		Node *t = NULL;

		if (temp == NULL)
		{

			t = new Node(review);
			t->height = 1;
			t->left = t->right = NULL;
			return t;
		}
		if (review < temp->review)
		{
			temp->left = Insert2(temp->left, review);
		}

		else if (review > temp->review)
		{
			temp->right = Insert2(temp->right, review);
		}

		temp->height = Height(temp);

		if (Balancing_Factor(temp) == 2 && Balancing_Factor(temp->left) == 1)
		{
			return LLRotation(temp);
		}

		else if (Balancing_Factor(temp) == 2 && Balancing_Factor(temp->left) == -1)
		{
			return LRRotation(temp);
		}

		else if (Balancing_Factor(temp) == -2 && Balancing_Factor(temp->right) == -1)
		{
			return RRRotation(temp);
		}

		else if (Balancing_Factor(temp) == -2 && Balancing_Factor(temp->right) == 1)
		{
			return RLRotation(temp);
		}

		return temp;
	}
	void Regular_Products(Node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{

			Regular_Products(temp->left);
			if (!done)
			{
				done = true;
			}
			else
			{
				//            	for average products rating

				int rating;
				int helpfulvotes;
				istringstream(temp->star_rating) >> rating;
				istringstream(temp->helpful_votes) >> helpfulvotes;

				if (rating >= 4 && (helpfulvotes >= 100 && helpfulvotes <= 200) && temp->verified_purchase == "Y")
				{
					cout << temp->product_ID << "\t:" << temp->product_title << endl;
				}
			}

			Regular_Products(temp->right);
		}
	}

	void Best_products(Node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{

			Best_products(temp->left);
			if (!done)
			{
				done = true;
			}
			else
			{
				//            	for average products rating

				int rating;
				int helpfulvotes;
				istringstream(temp->star_rating) >> rating;
				istringstream(temp->helpful_votes) >> helpfulvotes;

				if (rating == 5 && (helpfulvotes > 200) && temp->verified_purchase == "Y")
				{
					cout << temp->product_ID << "\t" << temp->product_title << endl;
				}
			}

			Best_products(temp->right);
		}
	}

	Node *Search_by_customerID(Node *temp, string ID)
	{
		if (temp == NULL)
		{
			return NULL;
		}
		// cout<<"The Program reached here\n";
		// cout<<"Reached the end of customer ID function\n";
		if (ID == temp->customerID)
		{
			Display_details(temp);
			return temp;
		}
		else if (ID < temp->customerID)
		{
			return Search_by_customerID(temp->left, ID);
		}
		else if (ID > temp->customerID)
		{
			return Search_by_customerID(temp->right, ID);
		}
	}
	Node *Search_by_ProductID(Node *temp, string ID)
	{
		// cout<<"Checking against "<<temp->product_ID<<endl;
		if (temp == NULL)
		{
			return NULL;
		}
		if (ID == temp->product_ID)
		{
			Display_details(temp);
			return temp;
		}
		else if (ID < temp->product_ID)
		{
			return Search_by_ProductID(temp->left, ID);
		}
		else if (ID > temp->product_ID)
		{
			return Search_by_ProductID(temp->right, ID);
		}
	}
	void Display_details(Node *temp)
	{
		cout << "Marketplace          : " << temp->marketplace << endl;
		cout << "Category             : " << temp->category << endl;
		cout << "Product ID           : " << temp->product_ID << endl;
		cout << "Product Name         : " << temp->product_title << endl;
		cout << "Product Rating       : " << temp->star_rating << endl;
		cout << "customer ID          : " << temp->customerID << endl;
		cout << "customer Review      : " << temp->detailed_review << endl;
		cout << "customer Review      : " << temp->detailed_review << endl;
	}

	void Regular_Products_Tittle(Node *temp)
	{
		cout << "*******************************Regular Products********************************* " << endl
			 << endl;
		cout << "Product ID\t: "
			 << "Product Title " << endl
			 << endl;
		Regular_Products(temp);
	}
	void Best_Product_Tittle(Node *temp)
	{
		cout << "*******************************Best Products********************************* " << endl
			 << endl;
		cout << "Product ID\t:"
			 << "Product Title " << endl
			 << endl;
		Best_products(temp);
	}

	Node *negtree() // Creates balanced AVL tree for negative words
	{

		fstream n("Negative.txt");

		string str;

		while (!n.eof())
		{

			getline(n, str);

			neg = Insert2(neg, str);
		}

		n.close();
	}

	Node *postree() // Creates balanced AVL tree for positive words
	{

		fstream p("Positive.txt");

		string str;

		if (!p.is_open())
		{

			cout << "File Not Opened" << endl;

			exit(0);
		}

		while (!p.eof())
		{

			getline(p, str);

			pos = Insert2(pos, str);
		}

		p.close();
	}

	void Inorder2(Node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{

			Inorder2(temp->left);
			if (!done)
			{
				done = true;
			}
			else
			{
				// cout<<"Program reached inorder\n";
				cout << temp->customerID << " " << temp->detailed_review << endl;
			}

			Inorder2(temp->right);
		}
	}

	void check_positive_negative(Node *t, string temp, int n) // Function used for searching the extracted words
	{

		if (t == NULL)
			return;

		check_positive_negative(t->left, temp, n);
		if (t->review == temp)
		{

			if (n == 1)
			{

				if (notflag == 1)
				{

					negative++;

					string t = "not ";

					notflag = 0;

					flag++;

					return;
				}

				else if (noflag == 1)
				{

					negative++;

					string t = "no ";

					noflag = 0;

					flag++;

					return;
				}

				else if (noneflag == 1)
				{

					negative++;

					string t = "none ";

					noneflag = 0;

					flag++;

					return;
				}

				else if (wontflag == 1)
				{

					negative++;

					string t = "won't ";

					wontflag = 0;

					flag++;

					return;
				}

				else if (dontflag == 1)
				{

					negative++;

					string t = "don't ";

					dontflag = 0;

					flag++;

					return;
				}

				else if (didntflag == 1)
				{

					negative++;

					string t = "didn't ";

					didntflag = 0;

					flag++;

					return;
				}

				else
				{

					positive++;

					flag++;

					return;
				}
			}

			if (n == 2)
			{

				if (notflag == 1)
				{

					positive++;

					string t = "not ";

					notflag = 0;

					flag++;

					return;
				}

				else if (noflag == 1)
				{

					positive++;

					string t = "no ";

					noflag = 0;

					flag++;

					return;
				}

				else if (noneflag == 1)
				{

					positive++;

					string t = "none ";

					noneflag = 0;

					flag++;

					return;
				}

				else if (wontflag == 1)
				{

					positive++;

					string t = "won't ";

					wontflag = 0;

					flag++;

					return;
				}

				else if (dontflag == 1)
				{

					positive++;

					string t = "don't ";

					dontflag = 0;

					flag++;

					return;
				}

				else if (didntflag == 1)
				{

					positive++;

					string t = "didn't ";

					didntflag = 0;

					flag++;

					return;
				}

				else
				{

					negative++;

					flag++;

					return;
				}
			}
		}

		check_positive_negative(t->right, temp, n);
	}

	void word_search() // Searching throught input words to increment values of various flags
	{

		for (int i = 0; i < spaces; i++)
		{

			if (words[i] == "not")
			{

				notflag++;

				continue;
			}

			if (words[i] == "no")
			{

				noflag++;

				continue;
			}

			else if (words[i] == "none")
			{

				noneflag++;

				continue;
			}

			else if (words[i] == "wont" || words[i] == "won't")
			{

				wontflag++;

				continue;
			}

			else if (words[i] == "dont" || words[i] == "don't")
			{

				dontflag++;

				continue;
			}

			else if (words[i] == "didnt" || words[i] == "didn't")
			{

				didntflag++;

				continue;
			}

			flag = 0;

			check_positive_negative(pos, words[i], 1);

			if (!flag)
				check_positive_negative(neg, words[i], 2);
			else
				continue;
		}
	}

	Node *wordbreak(Node *temp, string ID)
	{

		if (temp == NULL)
		{
			return NULL;
		}
		if (ID == temp->product_ID)
		{
			cout<<"The body of the review is: "<<temp->detailed_review <<"."<<endl;
			int j = 0;
			transform(temp->detailed_review.begin(), temp->detailed_review.end(), temp->detailed_review.begin(), ::tolower);
			while (temp->detailed_review[j] != '\0')
			{
				if (temp->detailed_review[j] == ' ')
				{
					spaces++;
				}
				j++;
			}

			string word = "";
			int i = 0;
			int k = 0;
			words = new string[spaces];
			while (temp->detailed_review[i] != '\0')
			{

				if (temp->detailed_review[i] == ' ')
				{
					words[k] = word;
					k++;
					word = "";
					i++;
				}
				else
				{
					word += temp->detailed_review[i];
					i++;
				}
			}

			words[spaces - 1] = word;

			return temp;
		}

		else if (ID < temp->product_ID)
		{
			return wordbreak(temp->left, ID);
		}
		else if (ID > temp->product_ID)
		{
			return wordbreak(temp->right, ID);
		}
	}

	void get_result()
	{
		cout << "\n*********************************Review Analysis Report******************************************\n\n\n";
		cout << "No of positive words: " << positive << endl
			 << endl;
		cout << "No of negative words: " << negative << endl
			 << endl;
		int total = positive + negative;
		cout << "Total Sentiments    : " << total << endl;
		polarity = positive / total;
		cout << "Polarity : " << polarity << endl;

		if (positive == negative)
		{
			cout << endl
				 << "Sentiment possessed is NEUTRAL " << endl
				 << endl;
		}

		else if (polarity > 0)
		{
			cout << endl
				 << "Sentiment possessed is POSITIVE " << endl
				 << endl;
		}

		else if (polarity <= 0)
		{
			cout << endl
				 << "Sentiment possessed is NEGATIVE " << endl
				 << endl;
		}
	}

	void find_result()
	{
		cout << "\nEnter the Product ID: ";
		string s;
		cin.ignore();
		getline(cin, s);
		wordbreak(root, s);
		negtree();
		postree();
		word_search();
		get_result();
	}
	void Customize(Node *temp, string rating, string helpful)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{

			Customize(temp->left, rating, helpful);
			if (!done)
			{
				done = true;
			}
			else
			{

				int rating1, rating2;
				int helpfulvotes1, helpfulvotes2;
				istringstream(temp->star_rating) >> rating1;
				istringstream(temp->helpful_votes) >> helpfulvotes1;
				istringstream(rating) >> rating2;
				istringstream(helpful) >> helpfulvotes2;

				if (rating1 == rating2 && helpfulvotes1 == helpfulvotes2)
				{
					cout << temp->product_ID << "\t:" << temp->detailed_review << endl;
				}
			}

			Customize(temp->right, rating, helpful);
		}
	}
};
void Main_Menu()
{
	cout << "**********************************************************************************************\t\t" << endl;
	string product_ID, review_id, customerID, marketplace, product_parent, product_title, product_category, vine, verified_purchase, review_headline, detailed_review, star_rating, helpful_votes, total_votes, review_date;
	AVL A1;
	int choice;
	cout << "Which Data set do you want to open : " << endl
		 << "1-Apparel" << endl
		 << "2-Toys" << endl
		 << "3-Shoes" << endl;
	cin >> choice;
	ifstream myfile;
	system("cls");
	switch (choice)
	{
	case 1:
	{
		int c = 0;
		ifstream myfile("Apparel.txt");
		if (myfile.is_open())
		{
			cout << "Reading........" << endl;
			while (!myfile.eof())
			{
				fflush(stdin);
				getline(myfile, marketplace, ',');
				getline(myfile, customerID, ',');
				getline(myfile, review_id, ',');
				getline(myfile, product_ID, ',');
				getline(myfile, product_parent, ',');
				getline(myfile, product_title, ',');
				getline(myfile, product_category, ',');
				getline(myfile, star_rating, ',');
				getline(myfile, helpful_votes, ',');
				getline(myfile, total_votes, ',');
				getline(myfile, vine, ',');
				getline(myfile, verified_purchase, ',');
				getline(myfile, review_headline, ',');
				getline(myfile, detailed_review, ',');
				getline(myfile, review_date, '\n');
				if (A1.root == NULL)
				{

					A1.root = A1.Insert(A1.root, product_ID, review_id, customerID, marketplace, product_parent, product_title, product_category, star_rating, helpful_votes, total_votes, vine, verified_purchase, review_headline, detailed_review);

					c++;
				}
				else
				{
					A1.Insert(A1.root, product_ID, review_id, customerID, marketplace, product_parent, product_title, product_category, star_rating, helpful_votes, total_votes, vine, verified_purchase, review_headline, detailed_review);
					c++;
				}
			}

			myfile.close();
		}
		else
		{
			cout << "Unable to open Dataset !! \n"
				 << endl;
			cout << "Press any key to exit" << endl;
			getch();
			exit(0);
		}

		break;
	}
	case 2:
	{
		int c = 0;
		ifstream myfile("toys.txt");
		if (myfile.is_open())
		{
			cout << "Reading........" << endl;
			while (!myfile.eof())
			{
				// cout << "Reading........" << endl;
				fflush(stdin);
				getline(myfile, marketplace, ',');
				getline(myfile, customerID, ',');
				getline(myfile, review_id, ',');
				getline(myfile, product_ID, ',');
				getline(myfile, product_parent, ',');
				getline(myfile, product_title, ',');
				getline(myfile, product_category, ',');
				getline(myfile, star_rating, ',');
				getline(myfile, helpful_votes, ',');
				getline(myfile, total_votes, ',');
				getline(myfile, vine, ',');
				getline(myfile, verified_purchase, ',');
				getline(myfile, review_headline, ',');
				getline(myfile, detailed_review, ',');
				getline(myfile, review_date, '\n');
				if (A1.root == NULL)
				{

					A1.root = A1.Insert(A1.root, product_ID, review_id, customerID, marketplace, product_parent, product_title, product_category, star_rating, helpful_votes, total_votes, vine, verified_purchase, review_headline, detailed_review);

					c++;
				}
				else
				{
					A1.Insert(A1.root, product_ID, review_id, customerID, marketplace, product_parent, product_title, product_category, star_rating, helpful_votes, total_votes, vine, verified_purchase, review_headline, detailed_review);
					c++;
				}
			}

			myfile.close();
		}
		else
		{
			cout << "Unable to open Dataset !! \n"
				 << endl;
			cout << "Press any key to exit" << endl;
			getch();
			exit(0);
		}

		break;
	}
	case 3:
	{
		int c = 0;
		ifstream myfile("shoes.txt");
		if (myfile.is_open())
		{
				cout << "Reading........" << endl;
			// cout << "Reading........" << endl;
			while (!myfile.eof())
			{
				fflush(stdin);
				getline(myfile, marketplace, ',');
				getline(myfile, customerID, ',');
				getline(myfile, review_id, ',');
				getline(myfile, product_ID, ',');
				getline(myfile, product_parent, ',');
				getline(myfile, product_title, ',');
				getline(myfile, product_category, ',');
				getline(myfile, star_rating, ',');
				getline(myfile, helpful_votes, ',');
				getline(myfile, total_votes, ',');
				getline(myfile, vine, ',');
				getline(myfile, verified_purchase, ',');
				getline(myfile, review_headline, ',');
				getline(myfile, detailed_review, ',');
				getline(myfile, review_date, '\n');
				if (A1.root == NULL)
				{

					A1.root = A1.Insert(A1.root, product_ID, review_id, customerID, marketplace, product_parent, product_title, product_category, star_rating, helpful_votes, total_votes, vine, verified_purchase, review_headline, detailed_review);

					c++;
				}
				else
				{
					A1.Insert(A1.root, product_ID, review_id, customerID, marketplace, product_parent, product_title, product_category, star_rating, helpful_votes, total_votes, vine, verified_purchase, review_headline, detailed_review);
					c++;
				}
			}

			myfile.close();
		}
		else
		{
			cout << "Unable to open Dataset !! \n"
				 << endl;
			cout << "Press any key to exit" << endl;
			getch();
			exit(0);
		}

		break;
	}
	default:
	{
		cout << "Invalid Choice" << endl;
		cout << "Press any key to return to Main Menu : " << endl;
		getch();
		Main_Menu();
	}
	}
	system("cls");
	A1.Menu();
}
int main()
{

	Main_Menu();
}
