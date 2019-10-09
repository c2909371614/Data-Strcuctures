#include"head.h"
Record* head_re = new Record();// new a record point by constructor

int main() {
	head_re->Next = NULL;
	int choice = 0;
	print_main_menu();
	while (true) {
		cout << "Please enter your operation:";
		//---aviod enter endless loop when cin fail---
		
		try{
			while(!(cin >> choice) || choice > 7 && choice <= 0) {
				while(getchar() != '\n');//solve the '\n'
				cin.clear();
				choice = 0;
				throw "choice";
			}
			switch(choice){
				case 1:
					read_data();
					break;
				case 2:
					insert_record(new_re());
					break;
				case 3:
					print_record();
					break;
				case 4:
					search_name();
					break;
				case 5:
					save_to_file();
					break;
				case 6:
					del_all();
					break;
				case 7:
					print_main_menu();
					break;
			} 
		}
		catch(string &ex){
			cout << ex << " not a operation, Please enter valid number:" << endl;
		}
	}
	return 0;
}
